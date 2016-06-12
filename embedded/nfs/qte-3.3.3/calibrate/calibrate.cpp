/**********************************************************************
** Copyright (C) 2000 Trolltech AS.  All rights reserved.
**
** This file is part of Qt Palmtop Environment.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#include <qapplication.h>

//#ifdef _WS_QWS_

#include <qpainter.h>
#include <qtimer.h>
#include <qwindowsystem_qws.h>
#include <qgfx_qws.h>
#include <qpixmap.h>
#include <stdlib.h>

#include "calibrate.h"


Calibrate::Calibrate(QWidget* parent, const char * name, WFlags wf) :
QWidget( parent, name, wf | WStyle_Tool | WStyle_Customize | WStyle_StaysOnTop | WDestructiveClose )
{
    const int offset = 30;
    QRect desk = qApp->desktop()->geometry();
    setGeometry( 0, 0, desk.width(), desk.height() );
	qDebug("%d %d", desk.width(), desk.height() );
	setBackgroundColor(Qt::white);
	
	
    cd.screenPoints[QWSPointerCalibrationData::TopLeft] = QPoint( offset, offset );
    cd.screenPoints[QWSPointerCalibrationData::BottomLeft] = QPoint( offset, qt_screen->deviceHeight() - offset );
    cd.screenPoints[QWSPointerCalibrationData::BottomRight] = QPoint( qt_screen->deviceWidth() - offset, qt_screen->deviceHeight() - offset );
    cd.screenPoints[QWSPointerCalibrationData::TopRight] = QPoint( qt_screen->deviceWidth() - offset, offset );
    cd.screenPoints[QWSPointerCalibrationData::Center] = QPoint( qt_screen->deviceWidth()/2, qt_screen->deviceHeight()/2 );

    crossPos = fromDevice( cd.screenPoints[QWSPointerCalibrationData::TopLeft] );
    location = QWSPointerCalibrationData::TopLeft;
	
    timer = new QTimer( this );
    connect( timer, SIGNAL(timeout()), this, SLOT(timeout()) );
	
    QWSServer::mouseHandler()->clearCalibration();
    grabMouse();
}

Calibrate::~Calibrate()
{
}

QPoint Calibrate::fromDevice( const QPoint &p )
{
    return qt_screen->mapFromDevice( p,
		QSize(qt_screen->deviceWidth(), qt_screen->deviceHeight()) );
}

bool Calibrate::sanityCheck()
{
    QPoint tl = cd.devPoints[QWSPointerCalibrationData::TopLeft];
    QPoint tr = cd.devPoints[QWSPointerCalibrationData::TopRight];
    QPoint bl = cd.devPoints[QWSPointerCalibrationData::BottomLeft];
    QPoint br = cd.devPoints[QWSPointerCalibrationData::BottomRight];
	
    qDebug("tl-x : %d, tl-y : %d, tr-x : %d, tr-y : %d", tl.x(), tl.y(),
		tr.x(), tr.y());
    qDebug("bl-x : %d, bl-y : %d, br-x : %d, br-y : %d", bl.x(), bl.y(),
		br.x(), br.y());
	
    int vl = QABS( tl.y() - bl.y() );
    int vr = QABS( tr.y() - br.y() );
    qDebug("vl(tl.y - bl.y): %d, vr(tr.y - br.y) : %d", vl, vr);
    int diff = QABS( vl - vr );
    int avg = ( vl + vr ) / 2;
    qDebug("diff(vl - vr) : %d, avg((vl+vr)/2) : %d", diff, avg);	
    if ( diff > avg / 20 ) { // 5% leeway
		qDebug(" diff > avg / 20 : False");
		return FALSE;
    }
    qDebug(" diff <= avg / 20 : OK");
	
    int ht = QABS( tl.x() - tr.x() );
    int hb = QABS( br.x() - bl.x() );
    qDebug("ht(tl.x - tr.x): %d, hb(br.y - bl.y) : %d", ht, hb);	
    diff = QABS( ht - hb );
    avg = ( ht + hb ) / 2;
    qDebug("diff(ht - hb) : %d, avg((ht+hb)/2) : %d", diff, avg);	
    if ( diff > avg / 20 ) { // 5% leeway
		qDebug(" diff > avg / 20 : False");
		return FALSE;
    }	
    qDebug(" diff <= avg / 20 : OK");
	
    return TRUE;
}

void Calibrate::moveCrosshair( QPoint pt )
{
    QPainter p( this );
    p.fillRect(rect(), QBrush(white));
    p.drawRect( pt.x()-1, pt.y()-8, 2, 7 );
    p.drawRect( pt.x()-1, pt.y()+1, 2, 7 );
    p.drawRect( pt.x()-8, pt.y()-1, 7, 2 );
    p.drawRect( pt.x()+1, pt.y()-1, 7, 2 );
    crossPos = pt;
}

void Calibrate::paintEvent( QPaintEvent * )
{
    QPainter p( this );
	
    p.fillRect(rect(), QBrush(white));
    moveCrosshair( crossPos );
}

void Calibrate::mousePressEvent( QMouseEvent *e )
{
    // map to device coordinates
    QPoint devPos = qt_screen->mapToDevice( e->pos(), QSize(qt_screen->width(), qt_screen->height()) );

    if ( penPos.isNull() )
		penPos = devPos;
    else
		penPos = QPoint( (penPos.x() + devPos.x())/2, (penPos.y() + devPos.y())/2 );
    
    qDebug("mousePressEvent(%d, %d)", penPos.x(), penPos.y());
}

void Calibrate::mouseReleaseEvent( QMouseEvent * )
{
    if ( timer->isActive() )
		return;
	
    bool doMove = TRUE;
	
	cd.devPoints[location] = penPos;
    if ( location < QWSPointerCalibrationData::LastLocation ) 
	{
		location = (QWSPointerCalibrationData::Location)((int)location + 1);
    } 
	else 
	{
		if ( sanityCheck() ) 
		{
			for(int i=0; i<5; i++)
			{
				qDebug("dev %4x:%4x, scr %4x:%4x \n", cd.devPoints[i].x(), cd.devPoints[i].y(), cd.screenPoints[i].x(), cd.screenPoints[i].y() ); 

			}
			QWSServer::mouseHandler()->calibrate( &cd );
			releaseMouse();
			hide();
			close();
			doMove = FALSE;
		} 
		else 
		{
			location = QWSPointerCalibrationData::TopLeft;
		}
    }
	
    if ( doMove ) 
	{
		QPoint target = fromDevice( cd.screenPoints[location] );
		dx = (target.x() - crossPos.x())/10;
		dy = (target.y() - crossPos.y())/10;
		timer->start( 30 );
    }
}

void Calibrate::timeout()
{
    QPoint target = fromDevice( cd.screenPoints[location] );
	
    bool doneX = FALSE;
    bool doneY = FALSE;
    QPoint newPos( crossPos.x() + dx, crossPos.y() + dy );
	
    if ( QABS(crossPos.x() - target.x()) <= QABS(dx) ) {
		newPos.setX( target.x() );
		doneX = TRUE;
    }
	
    if ( QABS(crossPos.y() - target.y()) <= QABS(dy) ) {
		newPos.setY(target.y());
		doneY = TRUE;
    }
	
    if ( doneX && doneY ) {
		penPos = QPoint();
		timer->stop();
    }
	
    moveCrosshair( newPos );
}

//#endif // _WS_QWS_
