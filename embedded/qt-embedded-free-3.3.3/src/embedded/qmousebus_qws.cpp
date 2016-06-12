/****************************************************************************
** $Id: qt/qmousebus_qws.cpp   3.3.3   edited May 27 2003 $
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

#include "qmousebus_qws.h"

#include "qwindowsystem_qws.h"
#include "qsocketnotifier.h"

#include "qapplication.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

/*
 * bus mouse driver (a.k.a. Logitech busmouse)
 */

class QWSBusMouseHandlerPrivate : public QObject
{
    Q_OBJECT
public:
    QWSBusMouseHandlerPrivate( QWSBusMouseHandler *h, const QString &driver, const QString &device );
    ~QWSBusMouseHandlerPrivate();

private slots:
    void readMouseData();

protected:
    enum { mouseBufSize = 128 };
    QWSBusMouseHandler *handler;
    int mouseFD;
    int mouseIdx;
    int obstate;
    uchar mouseBuf[mouseBufSize];
};

QWSBusMouseHandler::QWSBusMouseHandler( const QString &driver, const QString &device )
{
    d = new QWSBusMouseHandlerPrivate( this, driver, device );
}

QWSBusMouseHandler::~QWSBusMouseHandler()
{
    delete d;
}

QWSBusMouseHandlerPrivate::QWSBusMouseHandlerPrivate( QWSBusMouseHandler *h,
    const QString &, const QString &device )
    : handler( h )
					  
{
    QString mouseDev = device;
    if ( mouseDev.isEmpty() )
	mouseDev = "/dev/mouse";
    obstate = -1;
    mouseFD = -1;
    mouseFD = open( mouseDev.local8Bit(), O_RDWR | O_NDELAY);
    if ( mouseFD < 0 ) {
	mouseFD = open( mouseDev.local8Bit(), O_RDONLY | O_NDELAY);
	if ( mouseFD < 0 )
	    qDebug( "Cannot open %s (%s)", mouseDev.ascii(),
		    strerror(errno));
    }

    // Clear pending input
    tcflush(mouseFD,TCIFLUSH);
    usleep(50000);

    char buf[100];				// busmouse driver will not read if bufsize < 3,  YYD
    while (read(mouseFD, buf, 100) > 0) { }  // eat unwanted replies

    mouseIdx = 0;

    QSocketNotifier *mouseNotifier;
    mouseNotifier = new QSocketNotifier( mouseFD, QSocketNotifier::Read, this );
    connect(mouseNotifier, SIGNAL(activated(int)),this, SLOT(readMouseData()));
}

QWSBusMouseHandlerPrivate::~QWSBusMouseHandlerPrivate()
{
    if (mouseFD >= 0) {
	tcflush(mouseFD,TCIFLUSH);	    // yyd.
	close(mouseFD);
    }
}

void QWSBusMouseHandlerPrivate::readMouseData()
{
    int n;
    // It'll only read 3 bytes a time and return all other buffer zeroed, thus cause protocol errors
    for (;;) {
	if ( mouseBufSize - mouseIdx < 3 )
	    break;
	n = read( mouseFD, mouseBuf+mouseIdx, 3 );
	if ( n != 3 )
	    break;
	mouseIdx += 3;
    }

    static const int accel_limit = 5;
    static const int accel = 2;

    int idx = 0;
    int bstate = 0;
    int dx = 0, dy = 0;
    bool sendEvent = false;
    int tdx = 0, tdy = 0;

    while ( mouseIdx-idx >= 3 ) {
#if 0 // debug
	qDebug( "Got mouse data" );
#endif
	uchar *mb = mouseBuf+idx;
	bstate = 0;
	dx = 0;
	dy = 0;
	sendEvent = false;
	if ( ((mb[0] & 0x04)) )
	    bstate |= Qt::LeftButton;
	if ( ((mb[0] & 0x01)) )
	    bstate |= Qt::RightButton;

	dx=(signed char)mb[1];
	dy=(signed char)mb[2];
	sendEvent=true;

	if (sendEvent) {
	    if ( QABS(dx) > accel_limit || QABS(dy) > accel_limit ) {
		dx *= accel;
		dy *= accel;
	    }
	    tdx += dx;
	    tdy += dy;
	    if ( bstate != obstate ) {
		QPoint pos = handler->pos() + QPoint(tdx,-tdy);
		handler->limitToScreen( pos );
		handler->mouseChanged(pos,bstate);
		sendEvent = FALSE;
		tdx = 0;
		tdy = 0;
		obstate = bstate;
	    }
	}
	idx += 3;
    }
    if ( sendEvent ) {
	QPoint pos = handler->pos() + QPoint(tdx,-tdy);
	handler->limitToScreen( pos );
	handler->mouseChanged(pos,bstate);
    }

    int surplus = mouseIdx - idx;
    for ( int i = 0; i < surplus; i++ )
	mouseBuf[i] = mouseBuf[idx+i];
    mouseIdx = surplus;
}

#include "qmousebus_qws.moc"
