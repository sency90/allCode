/****************************************************************************
** $Id: qt/qmouselinuxtp_qws.cpp   3.3.3   edited Apr 7 10:45 $
**
** Implementation of Qt/Embedded mouse drivers
**
** Created : 20020220
**
** Copyright (C) 1992-2002 Trolltech AS.  All rights reserved.
**
** This file is part of the kernel module of the Qt GUI Toolkit.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses for Qt/Embedded may use this file in accordance with the
** Qt Embedded Commercial License Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#include "qmouselinuxtp_qws.h"

#ifndef QT_NO_QWS_MOUSE_LINUXTP
#include "qwindowsystem_qws.h"
#include "qsocketnotifier.h"
#include "qtimer.h"
#include "qapplication.h"
#include "qgfx_qws.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>


#if defined(QT_QWS_IPAQ)
#define QT_QWS_IPAQ_RAW
typedef struct {
	unsigned short pressure;
	unsigned short x;
	unsigned short y;
	unsigned short pad;
} TS_EVENT;
#elif defined(QT_QWS_EBX)
#define QT_QWS_EBX_RAW
#ifndef QT_QWS_SHARP
typedef struct {
        unsigned short pressure;
        unsigned short x;
        unsigned short y;
        unsigned short pad;
} TS_EVENT;
#else
typedef struct {
       long y;
       long x;
       long pressure;
       long long millisecs;
} TS_EVENT;
#define QT_QWS_TP_SAMPLE_SIZE 10
#define QT_QWS_TP_MINIMUM_SAMPLES 4
#define QT_QWS_TP_PRESSURE_THRESHOLD 500
#define QT_QWS_TP_MOVE_LIMIT 50
#define QT_QWS_TP_JITTER_LIMIT 2
#endif
#else
typedef struct {
	unsigned short pressure;
	unsigned short x;
	unsigned short y;
	unsigned short pad;
} TS_EVENT;
#endif

#ifndef QT_QWS_TP_SAMPLE_SIZE
#define QT_QWS_TP_SAMPLE_SIZE 5
#endif

#ifndef QT_QWS_TP_MINIMUM_SAMPLES
#define QT_QWS_TP_MINIMUM_SAMPLES 5
#endif

#ifndef QT_QWS_TP_PRESSURE_THRESHOLD
#define QT_QWS_TP_PRESSURE_THRESHOLD 1
#endif

#ifndef QT_QWS_TP_MOVE_LIMIT
#define QT_QWS_TP_MOVE_LIMIT 100
#endif

#ifndef QT_QWS_TP_JITTER_LIMIT
#define QT_QWS_TP_JITTER_LIMIT 2
#endif


class QWSLinuxTPMouseHandlerPrivate : public QObject
{
    Q_OBJECT
public:
    QWSLinuxTPMouseHandlerPrivate( QWSLinuxTPMouseHandler *h );
    ~QWSLinuxTPMouseHandlerPrivate();

private:
    static const int mouseBufSize = 2048;
    int mouseFD;
    QPoint oldmouse;
    QPoint oldTotalMousePos;
    bool waspressed;
    QPointArray samples;
    unsigned int currSample;
    unsigned int lastSample;
    unsigned int numSamples;
    int skipCount;
    int mouseIdx;
    uchar mouseBuf[mouseBufSize];
    QWSLinuxTPMouseHandler *handler;

private slots:
    void readMouseData();
};

QWSLinuxTPMouseHandler::QWSLinuxTPMouseHandler( const QString &, const QString & )
{
    d = new QWSLinuxTPMouseHandlerPrivate( this );
}

QWSLinuxTPMouseHandler::~QWSLinuxTPMouseHandler()
{
    delete d;
}

QWSLinuxTPMouseHandlerPrivate::QWSLinuxTPMouseHandlerPrivate( QWSLinuxTPMouseHandler *h )
    : samples(QT_QWS_TP_SAMPLE_SIZE), currSample(0), lastSample(0),
    numSamples(0), skipCount(0), handler(h)
{
#if defined(QT_QWS_IPAQ)
# ifdef QT_QWS_IPAQ_RAW
    if ((mouseFD = open( "/dev/h3600_tsraw", O_RDONLY | O_NDELAY)) < 0) {
# else
    if ((mouseFD = open( "/dev/h3600_ts", O_RDONLY | O_NDELAY)) < 0) {
# endif
	qWarning( "Cannot open /dev/h3600_ts (%s)", strerror(errno));
	return;
    }
#elif defined(QT_QWS_EBX)
//# ifdef QT_QWS_EBX_TSRAW
# if 0
    if ((mouseFD = open( "/dev/tsraw", O_RDONLY | O_NDELAY)) < 0) {
        qWarning( "Cannot open /dev/tsraw (%s)", strerror(errno));
       return;
    }
# else
    if ((mouseFD = open( "/dev/ts", O_RDONLY | O_NDELAY)) < 0) {
        qWarning( "Cannot open /dev/ts (%s)", strerror(errno));
        return;
     }
# endif
#endif

    QSocketNotifier *mouseNotifier;
    mouseNotifier = new QSocketNotifier( mouseFD, QSocketNotifier::Read,
					 this );
    connect(mouseNotifier, SIGNAL(activated(int)),this, SLOT(readMouseData()));
    waspressed=FALSE;
    mouseIdx = 0;
}

QWSLinuxTPMouseHandlerPrivate::~QWSLinuxTPMouseHandlerPrivate()
{
    if (mouseFD >= 0)
	close(mouseFD);
}


void QWSLinuxTPMouseHandlerPrivate::readMouseData()
{
    if(!qt_screen)
	return;

    int n;
    do {
	n = read(mouseFD, mouseBuf+mouseIdx, mouseBufSize-mouseIdx );
	if ( n > 0 )
	    mouseIdx += n;
    } while ( n > 0 && mouseIdx < mouseBufSize );

    TS_EVENT *data;
    int idx = 0;

    // perhaps we shouldn't be reading EVERY SAMPLE.
    while ( mouseIdx-idx >= (int)sizeof( TS_EVENT ) ) {
	uchar *mb = mouseBuf+idx;
	data = (TS_EVENT *) mb;
	if(data->pressure >= QT_QWS_TP_PRESSURE_THRESHOLD) {
#ifdef QT_QWS_SHARP
	    samples[currSample] = QPoint( 1000 - data->x, data->y );
#else
	    samples[currSample] = QPoint( data->x, data->y );
#endif

	    numSamples++;
	    if ( numSamples >= QT_QWS_TP_MINIMUM_SAMPLES ) {
		int sampleCount = QMIN(numSamples + 1,samples.count());

		// average the rest
		QPoint mousePos = QPoint( 0, 0 );
		QPoint totalMousePos = oldTotalMousePos;
		totalMousePos += samples[currSample];
		if(numSamples >= samples.count())
		    totalMousePos -= samples[lastSample];

		mousePos = totalMousePos / (sampleCount - 1);

# if defined(QT_QWS_IPAQ_RAW) || defined(QT_QWS_EBX_RAW)
		mousePos = handler->transform( mousePos );
# endif
		if(!waspressed)
		    oldmouse = mousePos;
		QPoint dp = mousePos - oldmouse;
		int dxSqr = dp.x() * dp.x();
		int dySqr = dp.y() * dp.y();
		if ( dxSqr + dySqr < (QT_QWS_TP_MOVE_LIMIT * QT_QWS_TP_MOVE_LIMIT) ) {
		    if ( waspressed ) {
			if ( (dxSqr + dySqr > (QT_QWS_TP_JITTER_LIMIT * QT_QWS_TP_JITTER_LIMIT) ) || skipCount > 2) {
			    handler->mouseChanged(mousePos,Qt::LeftButton);
			    oldmouse = mousePos;
			    skipCount = 0;
			} else {
			    skipCount++;
			}
		    } else {
			handler->mouseChanged(mousePos,Qt::LeftButton);
			oldmouse=mousePos;
			waspressed=true;
		    }

		    // save recuring information
		    currSample++;
		    if (numSamples >= samples.count())
			lastSample++;
		    oldTotalMousePos = totalMousePos;
		} else {
		    numSamples--; // don't use this sample, it was bad.
		}
	    } else {
		// build up the average
		oldTotalMousePos += samples[currSample];
		currSample++;
	    }
	    if ( currSample >= samples.count() )
		currSample = 0;
	    if ( lastSample >= samples.count() )
		lastSample = 0;
	} else {
	    currSample = 0;
	    lastSample = 0;
	    numSamples = 0;
	    skipCount = 0;
	    oldTotalMousePos = QPoint(0,0);
	    if ( waspressed ) {
		handler->mouseChanged(oldmouse,0);
		oldmouse = QPoint( -100, -100 );
		waspressed=false;
	    }
	}
	idx += sizeof( TS_EVENT );
    }

    int surplus = mouseIdx - idx;
    for ( int i = 0; i < surplus; i++ )
	mouseBuf[i] = mouseBuf[idx+i];
    mouseIdx = surplus;
}

#include "qmouselinuxtp_qws.moc"
#endif //QT_NO_QWS_MOUSE_LINUXTP
