/****************************************************************************
** $Id: qt/qdirectpainter_qws.h   3.3.3   edited Jun 23 2003 $
**
** Definition of QDirectPainter class
**
** Created : 010101
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

#ifndef QDIRECTPAINTER_QWS_H
#define QDIRECTPAINTER_QWS_H

#ifndef QT_H
#include "qpainter.h"
#endif // QT_H

#ifdef Q_WS_QWS
#ifndef QT_NO_DIRECTPAINTER
class Q_EXPORT QDirectPainter : public QPainter {
public:
    QDirectPainter( const QWidget* );
    ~QDirectPainter();

    uchar* frameBuffer();
    int lineStep();
    int transformOrientation();

    int numRects() const;
    const QRect& rect(int i) const;
    QRegion region() const;

    int depth() const;
    int width() const;
    int height() const;
    int xOffset() const;
    int yOffset() const;

    QPoint offset() const;
    QSize size() const;

    void setAreaChanged( const QRect& );

private:
    class Private;
    Private* d;
};

#endif
#endif

#endif // QDIRECTPAINTER_QWS_H
