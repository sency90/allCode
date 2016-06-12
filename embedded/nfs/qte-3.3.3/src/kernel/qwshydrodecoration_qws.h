/****************************************************************************
** $Id: qt/qwshydrodecoration_qws.h   3.3.3   edited May 27 2003 $
**
** Declaration of Qt/Embedded Hydro decorations
**
** Created : 000101
**
** Copyright (C) 2000-2002 Trolltech AS.  All rights reserved.
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

#ifndef QWSHYDRODECORATION_QWS_H
#define QWSHYDRODECORATION_QWS_H

#ifndef QT_H
#include "qwsdefaultdecoration_qws.h"
#endif // QT_H


#ifndef QT_NO_QWS_HYDRO_WM_STYLE


class QWSHydroDecoration : public QWSDefaultDecoration
{
public:
    QWSHydroDecoration();
    virtual ~QWSHydroDecoration();

    virtual QRegion region(const QWidget *, const QRect &rect, Region);
    virtual void paint(QPainter *, const QWidget *);
    virtual void paintButton(QPainter *, const QWidget *, Region, int state);
protected:
//    virtual int getTitleWidth(const QWidget *);
    virtual int getTitleHeight(const QWidget *);
    virtual const char **menuPixmap();
    virtual const char **closePixmap();
    virtual const char **minimizePixmap();
    virtual const char **maximizePixmap();
    virtual const char **normalizePixmap();
};

#endif // QT_NO_QWS_HYDRO_WM_STYLE

#endif // QWSHYDRODECORATION_QWS_H
