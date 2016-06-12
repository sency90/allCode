/****************************************************************************
** $Id: qt/qinputcontext_qws.cpp   3.3.3   edited May 27 2003 $
**
** Implementation of QInputContext class
**
** Copyright (C) 2000-2003 Trolltech AS.  All rights reserved.
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

#include "qinputcontext_p.h"
#include "qstring.h"
#include "qwindowsystem_qws.h"
#include "qpaintdevice.h"
#include "qwsdisplay_qws.h"


#ifndef QT_NO_QWS_IM
QWidget* QInputContext::focusWidget = 0;
QString* QInputContext::composition = 0;

void QInputContext::translateIMEvent( QWSIMEvent *e, QWidget *keywidget )
{
    //generate end event for previous widget if focus has changed
    if ( focusWidget && focusWidget != keywidget )
	reset();

    QString txt( e->text, e->simpleData.textLen );


    if ( e->simpleData.type == QWSServer::IMStart ) {
	//We may already have generated a start event for this widget
	//(could happen if the IM is buggy)
	if ( !focusWidget ) {
	    QIMEvent out( QEvent::IMStart, txt, e->simpleData.cpos );
	    QApplication::sendSpontaneousEvent( keywidget, &out );
	    focusWidget = keywidget;
	    if ( !composition )
		composition = new QString;
	}
    } else if ( e->simpleData.type == QWSServer::IMCompose ) {
	//generate start event if we haven't done so already
	//(focus change or careless IM)
	if ( !focusWidget ) {
	    QIMEvent out( QEvent::IMStart, "", -1 );
	    QApplication::sendSpontaneousEvent( keywidget, &out );
	    focusWidget = keywidget;
	    if ( !composition )
		composition = new QString;
	}

	QIMComposeEvent out( QEvent::IMCompose, txt, 
			     e->simpleData.cpos, 
			     e->simpleData.selLen );
	QApplication::sendSpontaneousEvent( keywidget, &out );

	*composition = txt;
    } else if ( e->simpleData.type == QWSServer::IMEnd ) {
	//Make sure we don't send multiple end events (guard against buggy IM)
	if ( focusWidget ) {
	    QIMEvent out( QEvent::IMEnd, txt, e->simpleData.cpos );
	    QApplication::sendSpontaneousEvent( keywidget, &out );
	    focusWidget = 0;
	    *composition = QString::null;
	}
    }
}

void QInputContext::reset()
{
    //send appropriate IMEnd event if necessary
    if ( focusWidget ) {
	QIMEvent out( QEvent::IMEnd, *composition, -1 );
	QApplication::sendSpontaneousEvent( focusWidget, &out );
	focusWidget = 0;
	*composition = QString::null;
    }
    
    QPaintDevice::qwsDisplay()->resetIM();
}
#endif //QT_NO_QWS_IM
