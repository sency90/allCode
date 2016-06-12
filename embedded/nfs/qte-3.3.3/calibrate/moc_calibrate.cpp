/****************************************************************************
** Calibrate meta object code from reading C++ file 'calibrate.h'
**
** Created: Thu Sep 1 12:37:40 2005
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "calibrate.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Calibrate::className() const
{
    return "Calibrate";
}

QMetaObject *Calibrate::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Calibrate( "Calibrate", &Calibrate::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Calibrate::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Calibrate", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Calibrate::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Calibrate", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Calibrate::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"timeout", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "timeout()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"Calibrate", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Calibrate.setMetaObject( metaObj );
    return metaObj;
}

void* Calibrate::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Calibrate" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool Calibrate::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: timeout(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool Calibrate::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Calibrate::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool Calibrate::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
