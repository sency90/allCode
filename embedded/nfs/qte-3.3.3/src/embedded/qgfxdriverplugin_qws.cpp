/****************************************************************************
** $Id: qt/qgfxdriverplugin_qws.cpp   3.3.3   edited May 27 2003 $
**
** Implementation of QGfxDriverPlugin
**
** Created : 20020212
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

#include "qgfxdriverplugin_qws.h"

#ifndef QT_NO_COMPONENT

#include "qgfxdriverinterface_p.h"
#include "qgfx_qws.h"

/*!
    \class QGfxDriverPlugin qgfxdriverplugin_qws.h
    \brief The QGfxDriverPlugin class provides an abstract base for
    Qt/Embedded graphics driver plugins.

    \ingroup plugins

    The graphics driver plugin is a simple plugin interface that makes
    it easy to create custom graphics drivers.

    Writing a graphics driver plugin is achieved by subclassing this
    base class, reimplementing the pure virtual functions keys() and
    create(), and exporting the class with the \c Q_EXPORT_PLUGIN
    macro. See the \link plugins-howto.html Plugins
    documentation\endlink for details.

    This class is only available in Qt/Embedded.
*/

/*!
    \fn QStringList QGfxDriverPlugin::keys() const

    Returns the list of graphics drivers this plugin supports.

    \sa create()
*/


class QGfxDriverPluginPrivate : public QGfxDriverInterface
{
public:
    QGfxDriverPluginPrivate( QGfxDriverPlugin *p )
	: plugin( p )
    {
    }
    virtual ~QGfxDriverPluginPrivate();

    QRESULT queryInterface( const QUuid &iid, QUnknownInterface **iface );
    Q_REFCOUNT;

#ifndef QT_NO_STRINGLIST
    QStringList featureList() const;
#endif

    QScreen* create( const QString& driver, int displayId );

private:
    QGfxDriverPlugin *plugin;
};

QGfxDriverPluginPrivate::~QGfxDriverPluginPrivate()
{
    delete plugin;
}

QRESULT QGfxDriverPluginPrivate::queryInterface( const QUuid &iid, QUnknownInterface **iface )
{
    *iface = 0;

    if ( iid == IID_QUnknown )
	*iface = this;
    else if ( iid == IID_QFeatureList )
	*iface = this;
    else if ( iid == IID_QGfxDriver )
	*iface = this;
    else
	return QE_NOINTERFACE;

    (*iface)->addRef();
    return QS_OK;
}

#ifndef QT_NO_STRINGLIST
QStringList QGfxDriverPluginPrivate::featureList() const
{
    return plugin->keys();
}
#endif

QScreen* QGfxDriverPluginPrivate::create( const QString& driver, int displayId )
{
    qDebug( "Loading plugin: %s", driver.latin1() );
    return plugin->create( driver, displayId );
}

/*!
    Constructs a graphics driver plugin. This is invoked automatically
    by the \c Q_EXPORT_PLUGIN macro.
*/
QGfxDriverPlugin::QGfxDriverPlugin()
    : QGPlugin( d = new QGfxDriverPluginPrivate( this ) )
{
}

/*!
    Destroys the graphics driver plugin.

    You never have to call this explicitly. Qt destroys a plugin
    automatically when it is no longer used.
*/
QGfxDriverPlugin::~QGfxDriverPlugin()
{
}


/*!
    \fn QScreen* QGfxDriverPlugin::create( const QString &driver, int displayId )

    Creates a driver matching the type specified by \a driver, that
    will use display \a displayId.

    \sa keys()
*/

QScreen* QGfxDriverPlugin::create( const QString& driver, int displayId )
{
    Q_UNUSED( driver )
    Q_UNUSED( displayId )
    return 0;
}

#endif // QT_NO_COMPONENT
