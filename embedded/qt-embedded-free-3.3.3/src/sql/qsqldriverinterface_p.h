/****************************************************************************
** $Id: qt/qsqldriverinterface_p.h   3.3.3   edited May 27 2003 $
**
** Definition of QSqlDriverInterface class
**
** Created : 2000-11-03
**
** Copyright (C) 2000-2002 Trolltech AS.  All rights reserved.
**
** This file is part of the sql module of the Qt GUI Toolkit.
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
** Licensees holding valid Qt Enterprise Edition licenses may use this
** file in accordance with the Qt Commercial License Agreement provided
** with the Software.
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

#ifndef QSQLDRIVERINTERFACE_H
#define QSQLDRIVERINTERFACE_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  This header file may
// change from version to version without notice, or even be
// removed.
//
// We mean it.
//
//

#ifndef QT_H
#include <private/qcom_p.h>
#endif // QT_H

#if !defined( QT_MODULE_SQL ) || defined( QT_LICENSE_PROFESSIONAL )
#define QM_EXPORT_SQL
#else
#define QM_EXPORT_SQL Q_EXPORT
#endif

#ifndef QT_NO_SQL

#ifndef QT_NO_COMPONENT

// {EDDD5AD5-DF3C-400c-A711-163B72FE5F61}
#ifndef IID_QSqlDriverFactory
#define IID_QSqlDriverFactory QUuid(0xeddd5ad5, 0xdf3c, 0x400c, 0xa7, 0x11, 0x16, 0x3b, 0x72, 0xfe, 0x5f, 0x61)
#endif

class QSqlDriver;

struct QM_EXPORT_SQL QSqlDriverFactoryInterface : public QFeatureListInterface
{
    virtual QSqlDriver* create( const QString& name ) = 0;
};

#endif //QT_NO_COMPONENT
#endif // QT_NO_SQL

#endif // QSQLDRIVERINTERFACE_P_H
