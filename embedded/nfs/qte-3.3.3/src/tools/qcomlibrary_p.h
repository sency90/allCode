/****************************************************************************
** $Id: qt/qcomlibrary_p.h   3.3.3   edited May 27 2003 $
**
** Definition of QComLibrary class
**
** Copyright (C) 2001-2002 Trolltech AS.  All rights reserved.
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

#ifndef QCOMLIBRARY_P_H
#define QCOMLIBRARY_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of a number of Qt sources files.  This header file may change from
// version to version without notice, or even be removed.
//
// We mean it.
//
//

#ifndef QT_H
#include "qcom_p.h"
#include "qlibrary.h"
#endif // QT_H

#ifndef QT_NO_COMPONENT

class Q_EXPORT QComLibrary : public QLibrary
{
public:
    QComLibrary( const QString &filename );
    ~QComLibrary();

    bool unload();
    QRESULT queryInterface( const QUuid &iid, QUnknownInterface **iface );
    uint qtVersion();

private:
    void createInstanceInternal();

    QUnknownInterface *entry;
    QLibraryInterface *libiface;
    uint qt_version;

};

#endif //QT_NO_COMPONENT

#endif
