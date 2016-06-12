/****************************************************************************
** $Id: qt/qmutex_p.h   3.3.3   edited May 27 2003 $
**
** QMutex private class declarations
**
** Created : 20012507
**
** Copyright (C) 1992-2002 Trolltech AS.  All rights reserved.
**
** This file is part of the tools module of the Qt GUI Toolkit.
**
** This file may be distributed under the terms of the Q Public License
** as defined by Trolltech AS of Norway and appearing in the file
** LICENSE.QPL included in the packaging of this file.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses may use this file in accordance with the Qt Commercial License
** Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/qpl/ for QPL licensing information.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef    QMUTEX_P_H
#define    QMUTEX_P_H

#ifndef QT_H
#endif // QT_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of qmutex_unix.cpp and qmutex_win.cpp.  This header file may change
// from version to version without notice, or even be removed.
//
// We mean it.
//

class QMutexPrivate {
public:
    // Q_MUTEX_T is defined in the various *.cpp files
    Q_MUTEX_T handle;

    virtual ~QMutexPrivate();

    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual bool locked() = 0;
    virtual bool trylock() = 0;
    virtual int type() const = 0;
};


#endif // QMUTEX_P_H
