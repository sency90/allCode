/**********************************************************************
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of Qt/Embedded virtual framebuffer.
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

#ifndef QANIMATIONWRITER_H
#define QANIMATIONWRITER_H

#include <qimage.h>

class QAnimationWriterData;

class QAnimationWriter
{
public:
    QAnimationWriter( const QString& filename, const char* format="MNG" );
    ~QAnimationWriter();

    bool okay() const;
    void setFrameRate(int);
    void appendBlankFrame();
    void appendFrame(const QImage&);
    void appendFrame(const QImage&, const QPoint& offset);

private:
    QImage prev;
    QIODevice* dev;
    QAnimationWriterData* d;
};

#endif
