/****************************************************************************
** QObject meta object code from reading C++ file 'allmoc.h'
**
** Created: Fri Jun 3 22:08:50 2016
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#define QT_H_CPP
#include "kernel/qt.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#include <qvariant.h>
const char *QObject::className() const
{
    return "QObject";
}

QMetaObject *QObject::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QObject( "QObject", &QObject::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QObject::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QObject", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QObject::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QObject", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QObject::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = staticQtMetaObject();
    static const QUMethod slot_0 = {"deleteLater", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_1 = {"cleanupEventFilter", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "deleteLater()", &slot_0, QMetaData::Public },
	{ "cleanupEventFilter(QObject*)", &slot_1, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"destroyed", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ "obj", &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod signal_1 = {"destroyed", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "destroyed()", &signal_0, QMetaData::Public },
	{ "destroyed(QObject*)", &signal_1, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[1] = {
 	{ "QCString","name", 0x14000103, &QObject::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QObject", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	props_tbl, 1,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QObject.setMetaObject( metaObj );
    return metaObj;
}

void* QObject::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QObject" ) )
	return this;
    return 0;
}

// SIGNAL destroyed
void QObject::destroyed()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL destroyed
void QObject::destroyed( QObject* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QObject::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: deleteLater(); break;
    case 1: cleanupEventFilter((QObject*)static_QUType_ptr.get(_o+1)); break;
    default:
	return FALSE;
    }
    return TRUE;
}

bool QObject::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: destroyed(); break;
    case 1: destroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    default:
	return FALSE;
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QObject::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setName(v->asCString()); break;
	case 1: *v = QVariant( this->name() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return FALSE;
    }
    return TRUE;
}

bool QObject::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWidget::className() const
{
    return "QWidget";
}

QMetaObject *QWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWidget( "QWidget", &QWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "NoFocus",  (int) QWidget::NoFocus },
	{ "TabFocus",  (int) QWidget::TabFocus },
	{ "ClickFocus",  (int) QWidget::ClickFocus },
	{ "StrongFocus",  (int) QWidget::StrongFocus },
	{ "WheelFocus",  (int) QWidget::WheelFocus }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "WidgetOrigin",  (int) QWidget::WidgetOrigin },
	{ "ParentOrigin",  (int) QWidget::ParentOrigin },
	{ "WindowOrigin",  (int) QWidget::WindowOrigin },
	{ "AncestorOrigin",  (int) QWidget::AncestorOrigin }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "FocusPolicy", 5, enum_0, FALSE },
	{ "BackgroundOrigin", 4, enum_1, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setEnabled", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setDisabled", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setCaption", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_varptr, "\x06", QUParameter::In }
    };
    static const QUMethod slot_3 = {"setIcon", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setIconText", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "enable", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setMouseTracking", 1, param_slot_5 };
    static const QUMethod slot_6 = {"setFocus", 0, 0 };
    static const QUMethod slot_7 = {"clearFocus", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ "enable", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"setUpdatesEnabled", 1, param_slot_8 };
    static const QUMethod slot_9 = {"update", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In },
	{ "w", &static_QUType_int, 0, QUParameter::In },
	{ "h", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"update", 4, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_varptr, "\x08", QUParameter::In }
    };
    static const QUMethod slot_11 = {"update", 1, param_slot_11 };
    static const QUMethod slot_12 = {"repaint", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ "erase", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"repaint", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In },
	{ "w", &static_QUType_int, 0, QUParameter::In },
	{ "h", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"repaint", 4, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In },
	{ "w", &static_QUType_int, 0, QUParameter::In },
	{ "h", &static_QUType_int, 0, QUParameter::In },
	{ "erase", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"repaint", 5, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_varptr, "\x08", QUParameter::In }
    };
    static const QUMethod slot_16 = {"repaint", 1, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ 0, &static_QUType_varptr, "\x08", QUParameter::In },
	{ "erase", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"repaint", 2, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_varptr, "\x16", QUParameter::In }
    };
    static const QUMethod slot_18 = {"repaint", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ 0, &static_QUType_varptr, "\x16", QUParameter::In },
	{ "erase", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"repaint", 2, param_slot_19 };
    static const QUMethod slot_20 = {"show", 0, 0 };
    static const QUMethod slot_21 = {"hide", 0, 0 };
    static const QUParameter param_slot_22[] = {
	{ "show", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_22 = {"setShown", 1, param_slot_22 };
    static const QUParameter param_slot_23[] = {
	{ "hide", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_23 = {"setHidden", 1, param_slot_23 };
    static const QUMethod slot_24 = {"iconify", 0, 0 };
    static const QUMethod slot_25 = {"showMinimized", 0, 0 };
    static const QUMethod slot_26 = {"showMaximized", 0, 0 };
    static const QUMethod slot_27 = {"showFullScreen", 0, 0 };
    static const QUMethod slot_28 = {"showNormal", 0, 0 };
    static const QUMethod slot_29 = {"polish", 0, 0 };
    static const QUMethod slot_30 = {"constPolish", 0, 0 };
    static const QUParameter param_slot_31[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out }
    };
    static const QUMethod slot_31 = {"close", 1, param_slot_31 };
    static const QUMethod slot_32 = {"raise", 0, 0 };
    static const QUMethod slot_33 = {"lower", 0, 0 };
    static const QUParameter param_slot_34[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_34 = {"stackUnder", 1, param_slot_34 };
    static const QUParameter param_slot_35[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_35 = {"move", 2, param_slot_35 };
    static const QUParameter param_slot_36[] = {
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_36 = {"move", 1, param_slot_36 };
    static const QUParameter param_slot_37[] = {
	{ "w", &static_QUType_int, 0, QUParameter::In },
	{ "h", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_37 = {"resize", 2, param_slot_37 };
    static const QUParameter param_slot_38[] = {
	{ 0, &static_QUType_varptr, "\x09", QUParameter::In }
    };
    static const QUMethod slot_38 = {"resize", 1, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In },
	{ "w", &static_QUType_int, 0, QUParameter::In },
	{ "h", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_39 = {"setGeometry", 4, param_slot_39 };
    static const QUParameter param_slot_40[] = {
	{ 0, &static_QUType_varptr, "\x08", QUParameter::In }
    };
    static const QUMethod slot_40 = {"setGeometry", 1, param_slot_40 };
    static const QUMethod slot_41 = {"adjustSize", 0, 0 };
    static const QUMethod slot_42 = {"focusProxyDestroyed", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setEnabled(bool)", &slot_0, QMetaData::Public },
	{ "setDisabled(bool)", &slot_1, QMetaData::Public },
	{ "setCaption(const QString&)", &slot_2, QMetaData::Public },
	{ "setIcon(const QPixmap&)", &slot_3, QMetaData::Public },
	{ "setIconText(const QString&)", &slot_4, QMetaData::Public },
	{ "setMouseTracking(bool)", &slot_5, QMetaData::Public },
	{ "setFocus()", &slot_6, QMetaData::Public },
	{ "clearFocus()", &slot_7, QMetaData::Public },
	{ "setUpdatesEnabled(bool)", &slot_8, QMetaData::Public },
	{ "update()", &slot_9, QMetaData::Public },
	{ "update(int,int,int,int)", &slot_10, QMetaData::Public },
	{ "update(const QRect&)", &slot_11, QMetaData::Public },
	{ "repaint()", &slot_12, QMetaData::Public },
	{ "repaint(bool)", &slot_13, QMetaData::Public },
	{ "repaint(int,int,int,int)", &slot_14, QMetaData::Public },
	{ "repaint(int,int,int,int,bool)", &slot_15, QMetaData::Public },
	{ "repaint(const QRect&)", &slot_16, QMetaData::Public },
	{ "repaint(const QRect&,bool)", &slot_17, QMetaData::Public },
	{ "repaint(const QRegion&)", &slot_18, QMetaData::Public },
	{ "repaint(const QRegion&,bool)", &slot_19, QMetaData::Public },
	{ "show()", &slot_20, QMetaData::Public },
	{ "hide()", &slot_21, QMetaData::Public },
	{ "setShown(bool)", &slot_22, QMetaData::Public },
	{ "setHidden(bool)", &slot_23, QMetaData::Public },
	{ "iconify()", &slot_24, QMetaData::Public },
	{ "showMinimized()", &slot_25, QMetaData::Public },
	{ "showMaximized()", &slot_26, QMetaData::Public },
	{ "showFullScreen()", &slot_27, QMetaData::Public },
	{ "showNormal()", &slot_28, QMetaData::Public },
	{ "polish()", &slot_29, QMetaData::Public },
	{ "constPolish()", &slot_30, QMetaData::Public },
	{ "close()", &slot_31, QMetaData::Public },
	{ "raise()", &slot_32, QMetaData::Public },
	{ "lower()", &slot_33, QMetaData::Public },
	{ "stackUnder(QWidget*)", &slot_34, QMetaData::Public },
	{ "move(int,int)", &slot_35, QMetaData::Public },
	{ "move(const QPoint&)", &slot_36, QMetaData::Public },
	{ "resize(int,int)", &slot_37, QMetaData::Public },
	{ "resize(const QSize&)", &slot_38, QMetaData::Public },
	{ "setGeometry(int,int,int,int)", &slot_39, QMetaData::Public },
	{ "setGeometry(const QRect&)", &slot_40, QMetaData::Public },
	{ "adjustSize()", &slot_41, QMetaData::Public },
	{ "focusProxyDestroyed()", &slot_42, QMetaData::Private }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[65] = {
 	{ "bool","isTopLevel", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "bool","isDialog", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "bool","isModal", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "bool","isPopup", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "bool","isDesktop", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "bool","enabled", 0x12000103, &QWidget::metaObj, 0, -1 },
	{ "QRect","geometry", 0x8000103, &QWidget::metaObj, 0, -1 },
	{ "QRect","frameGeometry", 0x8000001, &QWidget::metaObj, 0, -1 },
	{ "int","x", 0x10000001, &QWidget::metaObj, 0, -1 },
	{ "int","y", 0x10000001, &QWidget::metaObj, 0, -1 },
	{ "QPoint","pos", 0xe011003, &QWidget::metaObj, 0, -1 },
	{ "QSize","frameSize", 0x9000001, &QWidget::metaObj, 0, -1 },
	{ "QSize","size", 0x9011003, &QWidget::metaObj, 0, -1 },
	{ "int","width", 0x10000001, &QWidget::metaObj, 0, -1 },
	{ "int","height", 0x10000001, &QWidget::metaObj, 0, -1 },
	{ "QRect","rect", 0x8000001, &QWidget::metaObj, 0, -1 },
	{ "QRect","childrenRect", 0x8000001, &QWidget::metaObj, 0, -1 },
	{ "QRegion","childrenRegion", 0x16000001, &QWidget::metaObj, 0, -1 },
	{ "QSizePolicy","sizePolicy", 0x19000103, &QWidget::metaObj, 0, -1 },
	{ "QSize","minimumSize", 0x9000103, &QWidget::metaObj, 0, -1 },
	{ "QSize","maximumSize", 0x9000103, &QWidget::metaObj, 0, -1 },
	{ "int","minimumWidth", 0x10011103, &QWidget::metaObj, 0, -1 },
	{ "int","minimumHeight", 0x10011103, &QWidget::metaObj, 0, -1 },
	{ "int","maximumWidth", 0x10011103, &QWidget::metaObj, 0, -1 },
	{ "int","maximumHeight", 0x10011103, &QWidget::metaObj, 0, -1 },
	{ "QSize","sizeIncrement", 0x9000103, &QWidget::metaObj, 0, -1 },
	{ "QSize","baseSize", 0x9000103, &QWidget::metaObj, 0, -1 },
	{ "BackgroundMode","backgroundMode", 0x1107, &QWidget::metaObj, 0, -1 },
	{ "QColor","paletteForegroundColor", 0xa000103, &QWidget::metaObj, 0, -1 },
	{ "QColor","paletteBackgroundColor", 0xa000103, &QWidget::metaObj, 0, -1 },
	{ "QPixmap","paletteBackgroundPixmap", 0x6000103, &QWidget::metaObj, 0, -1 },
	{ "QBrush","backgroundBrush", 0x7000001, &QWidget::metaObj, 0, -1 },
	{ "QColorGroup","colorGroup", 0xc000001, &QWidget::metaObj, 0, -1 },
	{ "QPalette","palette", 0xb000103, &QWidget::metaObj, 0, -1 },
	{ "BackgroundOrigin","backgroundOrigin", 0x0107, &QWidget::metaObj, &enum_tbl[1], -1 },
	{ "bool","ownPalette", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "QFont","font", 0x5000103, &QWidget::metaObj, 0, -1 },
	{ "bool","ownFont", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "QCursor","cursor", 0x18000103, &QWidget::metaObj, 0, -1 },
	{ "bool","ownCursor", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "QString","caption", 0x3000103, &QWidget::metaObj, 0, -1 },
	{ "QPixmap","icon", 0x6000103, &QWidget::metaObj, 0, -1 },
	{ "QString","iconText", 0x3000103, &QWidget::metaObj, 0, -1 },
	{ "bool","mouseTracking", 0x12000103, &QWidget::metaObj, 0, -1 },
	{ "bool","underMouse", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "bool","isActiveWindow", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "bool","focusEnabled", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "FocusPolicy","focusPolicy", 0x0107, &QWidget::metaObj, &enum_tbl[0], -1 },
	{ "bool","focus", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "bool","updatesEnabled", 0x12001103, &QWidget::metaObj, 0, -1 },
	{ "bool","visible", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "QRect","visibleRect", 0x8000001, &QWidget::metaObj, 0, -1 },
	{ "bool","hidden", 0x12005103, &QWidget::metaObj, 0, -1 },
	{ "bool","shown", 0x12005103, &QWidget::metaObj, 0, -1 },
	{ "bool","minimized", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "bool","maximized", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "bool","fullScreen", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "QSize","sizeHint", 0x9000001, &QWidget::metaObj, 0, -1 },
	{ "QSize","minimumSizeHint", 0x9000001, &QWidget::metaObj, 0, -1 },
	{ "QRect","microFocusHint", 0x8000001, &QWidget::metaObj, 0, -1 },
	{ "bool","acceptDrops", 0x12000103, &QWidget::metaObj, 0, -1 },
	{ "bool","autoMask", 0x12005103, &QWidget::metaObj, 0, -1 },
	{ "bool","customWhatsThis", 0x12000001, &QWidget::metaObj, 0, -1 },
	{ "bool","inputMethodEnabled", 0x12005103, &QWidget::metaObj, 0, -1 },
	{ "double","windowOpacity", 0x13001103, &QWidget::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QWidget", parentObject,
	slot_tbl, 43,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 65,
	enum_tbl, 2,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWidget.setMetaObject( metaObj );
    return metaObj;
}

void* QWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWidget" ) )
	return this;
    if ( !qstrcmp( clname, "QPaintDevice" ) )
	return (QPaintDevice*)this;
    return QObject::qt_cast( clname );
}

bool QWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 1: setDisabled((bool)static_QUType_bool.get(_o+1)); break;
    case 2: setCaption((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: setIcon((const QPixmap&)*((const QPixmap*)static_QUType_ptr.get(_o+1))); break;
    case 4: setIconText((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: setMouseTracking((bool)static_QUType_bool.get(_o+1)); break;
    case 6: setFocus(); break;
    case 7: clearFocus(); break;
    case 8: setUpdatesEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 9: update(); break;
    case 10: update((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4)); break;
    case 11: update((const QRect&)*((const QRect*)static_QUType_ptr.get(_o+1))); break;
    case 12: repaint(); break;
    case 13: repaint((bool)static_QUType_bool.get(_o+1)); break;
    case 14: repaint((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4)); break;
    case 15: repaint((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4),(bool)static_QUType_bool.get(_o+5)); break;
    case 16: repaint((const QRect&)*((const QRect*)static_QUType_ptr.get(_o+1))); break;
    case 17: repaint((const QRect&)*((const QRect*)static_QUType_ptr.get(_o+1)),(bool)static_QUType_bool.get(_o+2)); break;
    case 18: repaint((const QRegion&)*((const QRegion*)static_QUType_ptr.get(_o+1))); break;
    case 19: repaint((const QRegion&)*((const QRegion*)static_QUType_ptr.get(_o+1)),(bool)static_QUType_bool.get(_o+2)); break;
    case 20: show(); break;
    case 21: hide(); break;
    case 22: setShown((bool)static_QUType_bool.get(_o+1)); break;
    case 23: setHidden((bool)static_QUType_bool.get(_o+1)); break;
    case 24: iconify(); break;
    case 25: showMinimized(); break;
    case 26: showMaximized(); break;
    case 27: showFullScreen(); break;
    case 28: showNormal(); break;
    case 29: polish(); break;
    case 30: constPolish(); break;
    case 31: static_QUType_bool.set(_o,close()); break;
    case 32: raise(); break;
    case 33: lower(); break;
    case 34: stackUnder((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 35: move((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 36: move((const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+1))); break;
    case 37: resize((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 38: resize((const QSize&)*((const QSize*)static_QUType_ptr.get(_o+1))); break;
    case 39: setGeometry((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4)); break;
    case 40: setGeometry((const QRect&)*((const QRect*)static_QUType_ptr.get(_o+1))); break;
    case 41: adjustSize(); break;
    case 42: focusProxyDestroyed(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QWidget::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QWidget::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 1: *v = QVariant( this->isTopLevel(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 1: *v = QVariant( this->isDialog(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 1: *v = QVariant( this->isModal(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 1: *v = QVariant( this->isPopup(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 1: *v = QVariant( this->isDesktop(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setGeometry(v->asRect()); break;
	case 1: *v = QVariant( this->geometry() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 1: *v = QVariant( this->frameGeometry() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 1: *v = QVariant( this->x() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 1: *v = QVariant( this->y() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 0: move(v->asPoint()); break;
	case 1: *v = QVariant( this->pos() ); break;
	case 4: break;
	default: return FALSE;
    } break;
    case 11: switch( f ) {
	case 1: *v = QVariant( this->frameSize() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 12: switch( f ) {
	case 0: resize(v->asSize()); break;
	case 1: *v = QVariant( this->size() ); break;
	case 4: break;
	default: return FALSE;
    } break;
    case 13: switch( f ) {
	case 1: *v = QVariant( this->width() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 14: switch( f ) {
	case 1: *v = QVariant( this->height() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 15: switch( f ) {
	case 1: *v = QVariant( this->rect() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 16: switch( f ) {
	case 1: *v = QVariant( this->childrenRect() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 17: switch( f ) {
	case 1: *v = QVariant( this->childrenRegion() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 18: switch( f ) {
	case 0: setSizePolicy(v->asSizePolicy()); break;
	case 1: *v = QVariant( this->sizePolicy() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 19: switch( f ) {
	case 0: setMinimumSize(v->asSize()); break;
	case 1: *v = QVariant( this->minimumSize() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 20: switch( f ) {
	case 0: setMaximumSize(v->asSize()); break;
	case 1: *v = QVariant( this->maximumSize() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 21: switch( f ) {
	case 0: setMinimumWidth(v->asInt()); break;
	case 1: *v = QVariant( this->minimumWidth() ); break;
	case 4: break;
	default: return FALSE;
    } break;
    case 22: switch( f ) {
	case 0: setMinimumHeight(v->asInt()); break;
	case 1: *v = QVariant( this->minimumHeight() ); break;
	case 4: break;
	default: return FALSE;
    } break;
    case 23: switch( f ) {
	case 0: setMaximumWidth(v->asInt()); break;
	case 1: *v = QVariant( this->maximumWidth() ); break;
	case 4: break;
	default: return FALSE;
    } break;
    case 24: switch( f ) {
	case 0: setMaximumHeight(v->asInt()); break;
	case 1: *v = QVariant( this->maximumHeight() ); break;
	case 4: break;
	default: return FALSE;
    } break;
    case 25: switch( f ) {
	case 0: setSizeIncrement(v->asSize()); break;
	case 1: *v = QVariant( this->sizeIncrement() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 26: switch( f ) {
	case 0: setBaseSize(v->asSize()); break;
	case 1: *v = QVariant( this->baseSize() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 27: switch( f ) {
	case 0: setBackgroundMode((BackgroundMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->backgroundMode() ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 28: switch( f ) {
	case 0: setPaletteForegroundColor(v->asColor()); break;
	case 1: *v = QVariant( this->paletteForegroundColor() ); break;
	case 2: this->unsetPalette(); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 29: switch( f ) {
	case 0: setPaletteBackgroundColor(v->asColor()); break;
	case 1: *v = QVariant( this->paletteBackgroundColor() ); break;
	case 2: this->unsetPalette(); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 30: switch( f ) {
	case 0: setPaletteBackgroundPixmap(v->asPixmap()); break;
	case 1: if ( this->paletteBackgroundPixmap() ) *v = QVariant( *paletteBackgroundPixmap() ); break;
	case 2: this->unsetPalette(); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 31: switch( f ) {
	case 1: *v = QVariant( this->backgroundBrush() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 32: switch( f ) {
	case 1: *v = QVariant( this->colorGroup() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 33: switch( f ) {
	case 0: setPalette(v->asPalette()); break;
	case 1: *v = QVariant( this->palette() ); break;
	case 2: this->unsetPalette(); break;
	case 5: return this->ownPalette();
	case 3: case 4: break;
	default: return FALSE;
    } break;
    case 34: switch( f ) {
	case 0: setBackgroundOrigin((BackgroundOrigin&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->backgroundOrigin() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 35: switch( f ) {
	case 1: *v = QVariant( this->ownPalette(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 36: switch( f ) {
	case 0: setFont(v->asFont()); break;
	case 1: *v = QVariant( this->font() ); break;
	case 2: this->unsetFont(); break;
	case 5: return this->ownFont();
	case 3: case 4: break;
	default: return FALSE;
    } break;
    case 37: switch( f ) {
	case 1: *v = QVariant( this->ownFont(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 38: switch( f ) {
	case 0: setCursor(v->asCursor()); break;
	case 1: *v = QVariant( this->cursor() ); break;
	case 2: this->unsetCursor(); break;
	case 5: return this->ownCursor();
	case 3: case 4: break;
	default: return FALSE;
    } break;
    case 39: switch( f ) {
	case 1: *v = QVariant( this->ownCursor(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 40: switch( f ) {
	case 0: setCaption(v->asString()); break;
	case 1: *v = QVariant( this->caption() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 41: switch( f ) {
	case 0: setIcon(v->asPixmap()); break;
	case 1: if ( this->icon() ) *v = QVariant( *icon() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 42: switch( f ) {
	case 0: setIconText(v->asString()); break;
	case 1: *v = QVariant( this->iconText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 43: switch( f ) {
	case 0: setMouseTracking(v->asBool()); break;
	case 1: *v = QVariant( this->hasMouseTracking(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 44: switch( f ) {
	case 1: *v = QVariant( this->hasMouse(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 45: switch( f ) {
	case 1: *v = QVariant( this->isActiveWindow(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 46: switch( f ) {
	case 1: *v = QVariant( this->isFocusEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 47: switch( f ) {
	case 0: setFocusPolicy((FocusPolicy&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->focusPolicy() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 48: switch( f ) {
	case 1: *v = QVariant( this->hasFocus(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 49: switch( f ) {
	case 0: setUpdatesEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isUpdatesEnabled(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 50: switch( f ) {
	case 1: *v = QVariant( this->isVisible(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 51: switch( f ) {
	case 1: *v = QVariant( this->visibleRect() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 52: switch( f ) {
	case 0: setHidden(v->asBool()); break;
	case 1: *v = QVariant( this->isHidden(), 0 ); break;
	case 5: break;
	default: return FALSE;
    } break;
    case 53: switch( f ) {
	case 0: setShown(v->asBool()); break;
	case 1: *v = QVariant( this->isShown(), 0 ); break;
	case 5: break;
	default: return FALSE;
    } break;
    case 54: switch( f ) {
	case 1: *v = QVariant( this->isMinimized(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 55: switch( f ) {
	case 1: *v = QVariant( this->isMaximized(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 56: switch( f ) {
	case 1: *v = QVariant( this->isFullScreen(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 57: switch( f ) {
	case 1: *v = QVariant( this->sizeHint() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 58: switch( f ) {
	case 1: *v = QVariant( this->minimumSizeHint() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 59: switch( f ) {
	case 1: *v = QVariant( this->microFocusHint() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 60: switch( f ) {
	case 0: setAcceptDrops(v->asBool()); break;
	case 1: *v = QVariant( this->acceptDrops(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 61: switch( f ) {
	case 0: setAutoMask(v->asBool()); break;
	case 1: *v = QVariant( this->autoMask(), 0 ); break;
	case 5: break;
	default: return FALSE;
    } break;
    case 62: switch( f ) {
	case 1: *v = QVariant( this->customWhatsThis(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 63: switch( f ) {
	case 0: setInputMethodEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isInputMethodEnabled(), 0 ); break;
	case 5: break;
	default: return FALSE;
    } break;
    case 64: switch( f ) {
	case 0: setWindowOpacity(v->asDouble()); break;
	case 1: *v = QVariant( this->windowOpacity() ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QObject::qt_property( id, f, v );
    }
    return TRUE;
}

bool QWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QStyle::className() const
{
    return "QStyle";
}

QMetaObject *QStyle::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QStyle( "QStyle", &QStyle::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QStyle::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QStyle", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QStyle::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QStyle", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QStyle::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QStyle", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QStyle.setMetaObject( metaObj );
    return metaObj;
}

void* QStyle::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QStyle" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QStyle::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QStyle::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QStyle::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QStyle::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QFrame::className() const
{
    return "QFrame";
}

QMetaObject *QFrame::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFrame( "QFrame", &QFrame::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFrame::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFrame", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFrame::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFrame", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFrame::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "NoFrame",  (int) QFrame::NoFrame },
	{ "Box",  (int) QFrame::Box },
	{ "Panel",  (int) QFrame::Panel },
	{ "WinPanel",  (int) QFrame::WinPanel },
	{ "HLine",  (int) QFrame::HLine },
	{ "VLine",  (int) QFrame::VLine },
	{ "StyledPanel",  (int) QFrame::StyledPanel },
	{ "PopupPanel",  (int) QFrame::PopupPanel },
	{ "MenuBarPanel",  (int) QFrame::MenuBarPanel },
	{ "ToolBarPanel",  (int) QFrame::ToolBarPanel },
	{ "LineEditPanel",  (int) QFrame::LineEditPanel },
	{ "TabWidgetPanel",  (int) QFrame::TabWidgetPanel },
	{ "GroupBoxPanel",  (int) QFrame::GroupBoxPanel },
	{ "MShape",  (int) QFrame::MShape }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "Plain",  (int) QFrame::Plain },
	{ "Raised",  (int) QFrame::Raised },
	{ "Sunken",  (int) QFrame::Sunken },
	{ "MShadow",  (int) QFrame::MShadow }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "Shape", 14, enum_0, FALSE },
	{ "Shadow", 4, enum_1, FALSE }
    };
#endif // QT_NO_PROPERTIES
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[8] = {
 	{ "int","frameWidth", 0x10000001, &QFrame::metaObj, 0, -1 },
	{ "QRect","contentsRect", 0x8000001, &QFrame::metaObj, 0, -1 },
	{ "Shape","frameShape", 0x0107, &QFrame::metaObj, &enum_tbl[0], -1 },
	{ "Shadow","frameShadow", 0x0107, &QFrame::metaObj, &enum_tbl[1], -1 },
	{ "int","lineWidth", 0x10000103, &QFrame::metaObj, 0, -1 },
	{ "int","margin", 0x10000103, &QFrame::metaObj, 0, -1 },
	{ "int","midLineWidth", 0x10000103, &QFrame::metaObj, 0, -1 },
	{ "QRect","frameRect", 0x8001103, &QFrame::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QFrame", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 8,
	enum_tbl, 2,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFrame.setMetaObject( metaObj );
    return metaObj;
}

void* QFrame::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFrame" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QFrame::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool QFrame::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QFrame::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 1: *v = QVariant( this->frameWidth() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 1: *v = QVariant( this->contentsRect() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setFrameShape((Shape&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->frameShape() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setFrameShadow((Shadow&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->frameShadow() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setLineWidth(v->asInt()); break;
	case 1: *v = QVariant( this->lineWidth() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setMargin(v->asInt()); break;
	case 1: *v = QVariant( this->margin() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setMidLineWidth(v->asInt()); break;
	case 1: *v = QVariant( this->midLineWidth() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setFrameRect(v->asRect()); break;
	case 1: *v = QVariant( this->frameRect() ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QFrame::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QComboBox::className() const
{
    return "QComboBox";
}

QMetaObject *QComboBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QComboBox( "QComboBox", &QComboBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QComboBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QComboBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QComboBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QComboBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QComboBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "NoInsertion",  (int) QComboBox::NoInsertion },
	{ "AtTop",  (int) QComboBox::AtTop },
	{ "AtCurrent",  (int) QComboBox::AtCurrent },
	{ "AtBottom",  (int) QComboBox::AtBottom },
	{ "AfterCurrent",  (int) QComboBox::AfterCurrent },
	{ "BeforeCurrent",  (int) QComboBox::BeforeCurrent }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "Policy", 6, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUMethod slot_0 = {"clear", 0, 0 };
    static const QUMethod slot_1 = {"clearValidator", 0, 0 };
    static const QUMethod slot_2 = {"clearEdit", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"setEditText", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"internalActivate", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"internalHighlight", 1, param_slot_5 };
    static const QUMethod slot_6 = {"internalClickTimeout", 0, 0 };
    static const QUMethod slot_7 = {"returnPressed", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "clear()", &slot_0, QMetaData::Public },
	{ "clearValidator()", &slot_1, QMetaData::Public },
	{ "clearEdit()", &slot_2, QMetaData::Public },
	{ "setEditText(const QString&)", &slot_3, QMetaData::Public },
	{ "internalActivate(int)", &slot_4, QMetaData::Private },
	{ "internalHighlight(int)", &slot_5, QMetaData::Private },
	{ "internalClickTimeout()", &slot_6, QMetaData::Private },
	{ "returnPressed()", &slot_7, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"activated", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"highlighted", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"activated", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"highlighted", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"textChanged", 1, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "activated(int)", &signal_0, QMetaData::Public },
	{ "highlighted(int)", &signal_1, QMetaData::Public },
	{ "activated(const QString&)", &signal_2, QMetaData::Public },
	{ "highlighted(const QString&)", &signal_3, QMetaData::Public },
	{ "textChanged(const QString&)", &signal_4, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[11] = {
 	{ "bool","editable", 0x12000103, &QComboBox::metaObj, 0, -1 },
	{ "int","count", 0x10000001, &QComboBox::metaObj, 0, -1 },
	{ "QString","currentText", 0x3001103, &QComboBox::metaObj, 0, -1 },
	{ "int","currentItem", 0x10000103, &QComboBox::metaObj, 0, -1 },
	{ "bool","autoResize", 0x12001103, &QComboBox::metaObj, 0, -1 },
	{ "int","sizeLimit", 0x10000103, &QComboBox::metaObj, 0, -1 },
	{ "int","maxCount", 0x10000103, &QComboBox::metaObj, 0, -1 },
	{ "Policy","insertionPolicy", 0x0107, &QComboBox::metaObj, &enum_tbl[0], -1 },
	{ "bool","autoCompletion", 0x12000103, &QComboBox::metaObj, 0, -1 },
	{ "bool","duplicatesEnabled", 0x12000103, &QComboBox::metaObj, 0, -1 },
	{ "bool","autoMask", 0x12020200, &QComboBox::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QComboBox", parentObject,
	slot_tbl, 8,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	props_tbl, 11,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QComboBox.setMetaObject( metaObj );
    return metaObj;
}

void* QComboBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QComboBox" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL activated
void QComboBox::activated( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL highlighted
void QComboBox::highlighted( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL activated
void QComboBox::activated( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL highlighted
void QComboBox::highlighted( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 3, t0 );
}

// SIGNAL textChanged
void QComboBox::textChanged( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 4, t0 );
}

bool QComboBox::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: clear(); break;
    case 1: clearValidator(); break;
    case 2: clearEdit(); break;
    case 3: setEditText((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: internalActivate((int)static_QUType_int.get(_o+1)); break;
    case 5: internalHighlight((int)static_QUType_int.get(_o+1)); break;
    case 6: internalClickTimeout(); break;
    case 7: returnPressed(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QComboBox::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: activated((int)static_QUType_int.get(_o+1)); break;
    case 1: highlighted((int)static_QUType_int.get(_o+1)); break;
    case 2: activated((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: highlighted((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QComboBox::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setEditable(v->asBool()); break;
	case 1: *v = QVariant( this->editable(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 1: *v = QVariant( this->count() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setCurrentText(v->asString()); break;
	case 1: *v = QVariant( this->currentText() ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setCurrentItem(v->asInt()); break;
	case 1: *v = QVariant( this->currentItem() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setAutoResize(v->asBool()); break;
	case 1: *v = QVariant( this->autoResize(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setSizeLimit(v->asInt()); break;
	case 1: *v = QVariant( this->sizeLimit() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setMaxCount(v->asInt()); break;
	case 1: *v = QVariant( this->maxCount() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setInsertionPolicy((Policy&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->insertionPolicy() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setAutoCompletion(v->asBool()); break;
	case 1: *v = QVariant( this->autoCompletion(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setDuplicatesEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->duplicatesEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	case 3: case 4: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
resolve:
    return QWidget::qt_property( staticMetaObject()->resolveProperty(id), f, v );
}

bool QComboBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QGroupBox::className() const
{
    return "QGroupBox";
}

QMetaObject *QGroupBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QGroupBox( "QGroupBox", &QGroupBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QGroupBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGroupBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QGroupBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGroupBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QGroupBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setChecked", 1, param_slot_0 };
    static const QUMethod slot_1 = {"fixFocus", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setChildrenEnabled", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "setChecked(bool)", &slot_0, QMetaData::Public },
	{ "fixFocus()", &slot_1, QMetaData::Private },
	{ "setChildrenEnabled(bool)", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"toggled", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "toggled(bool)", &signal_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[7] = {
 	{ "QString","title", 0x3000103, &QGroupBox::metaObj, 0, -1 },
	{ "Alignment","alignment", 0x010f, &QGroupBox::metaObj, 0, -1 },
	{ "Orientation","orientation", 0x110f, &QGroupBox::metaObj, 0, -1 },
	{ "int","columns", 0x10001103, &QGroupBox::metaObj, 0, -1 },
	{ "bool","flat", 0x12000103, &QGroupBox::metaObj, 0, -1 },
	{ "bool","checkable", 0x12000103, &QGroupBox::metaObj, 0, -1 },
	{ "bool","checked", 0x12000103, &QGroupBox::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QGroupBox", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	props_tbl, 7,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QGroupBox.setMetaObject( metaObj );
    return metaObj;
}

void* QGroupBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QGroupBox" ) )
	return this;
    return QFrame::qt_cast( clname );
}

// SIGNAL toggled
void QGroupBox::toggled( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 0, t0 );
}

bool QGroupBox::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setChecked((bool)static_QUType_bool.get(_o+1)); break;
    case 1: fixFocus(); break;
    case 2: setChildrenEnabled((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QGroupBox::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: toggled((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QGroupBox::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setTitle(v->asString()); break;
	case 1: *v = QVariant( this->title() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setAlignment(v->asInt()); break;
	case 1: *v = QVariant( (int)this->alignment() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setOrientation((Orientation&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->orientation() ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setColumns(v->asInt()); break;
	case 1: *v = QVariant( this->columns() ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setFlat(v->asBool()); break;
	case 1: *v = QVariant( this->isFlat(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setCheckable(v->asBool()); break;
	case 1: *v = QVariant( this->isCheckable(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setChecked(v->asBool()); break;
	case 1: *v = QVariant( this->isChecked(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QFrame::qt_property( id, f, v );
    }
    return TRUE;
}

bool QGroupBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDialog::className() const
{
    return "QDialog";
}

QMetaObject *QDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDialog( "QDialog", &QDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_0 = {"exec", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"done", 1, param_slot_1 };
    static const QUMethod slot_2 = {"accept", 0, 0 };
    static const QUMethod slot_3 = {"reject", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"showExtension", 1, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "exec()", &slot_0, QMetaData::Public },
	{ "done(int)", &slot_1, QMetaData::Protected },
	{ "accept()", &slot_2, QMetaData::Protected },
	{ "reject()", &slot_3, QMetaData::Protected },
	{ "showExtension(bool)", &slot_4, QMetaData::Protected }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[2] = {
 	{ "bool","sizeGripEnabled", 0x12000103, &QDialog::metaObj, 0, -1 },
	{ "bool","modal", 0x12000103, &QDialog::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QDialog", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 2,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDialog.setMetaObject( metaObj );
    return metaObj;
}

void* QDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDialog" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: static_QUType_int.set(_o,exec()); break;
    case 1: done((int)static_QUType_int.get(_o+1)); break;
    case 2: accept(); break;
    case 3: reject(); break;
    case 4: showExtension((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDialog::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDialog::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setSizeGripEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isSizeGripEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setModal(v->asBool()); break;
	case 1: *v = QVariant( this->isModal(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDataView::className() const
{
    return "QDataView";
}

QMetaObject *QDataView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDataView( "QDataView", &QDataView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDataView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDataView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDataView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDataView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDataView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod slot_0 = {"refresh", 1, param_slot_0 };
    static const QUMethod slot_1 = {"readFields", 0, 0 };
    static const QUMethod slot_2 = {"writeFields", 0, 0 };
    static const QUMethod slot_3 = {"clearValues", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "refresh(QSqlRecord*)", &slot_0, QMetaData::Public },
	{ "readFields()", &slot_1, QMetaData::Public },
	{ "writeFields()", &slot_2, QMetaData::Public },
	{ "clearValues()", &slot_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDataView", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDataView.setMetaObject( metaObj );
    return metaObj;
}

void* QDataView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDataView" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QDataView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: refresh((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 1: readFields(); break;
    case 2: writeFields(); break;
    case 3: clearValues(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDataView::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDataView::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QDataView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDockWindow::className() const
{
    return "QDockWindow";
}

QMetaObject *QDockWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDockWindow( "QDockWindow", &QDockWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDockWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDockWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDockWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDockWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDockWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "InDock",  (int) QDockWindow::InDock },
	{ "OutsideDock",  (int) QDockWindow::OutsideDock }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "Never",  (int) QDockWindow::Never },
	{ "Docked",  (int) QDockWindow::Docked },
	{ "Undocked",  (int) QDockWindow::Undocked },
	{ "Always",  (int) QDockWindow::Always }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "Place", 2, enum_0, FALSE },
	{ "CloseMode", 4, enum_1, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "w", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_0 = {"undock", 1, param_slot_0 };
    static const QUMethod slot_1 = {"undock", 0, 0 };
    static const QUMethod slot_2 = {"dock", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "o", &static_QUType_ptr, "Orientation", QUParameter::In }
    };
    static const QUMethod slot_3 = {"setOrientation", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "s", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setCaption", 1, param_slot_4 };
    static const QUMethod slot_5 = {"toggleVisible", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "undock(QWidget*)", &slot_0, QMetaData::Public },
	{ "undock()", &slot_1, QMetaData::Public },
	{ "dock()", &slot_2, QMetaData::Public },
	{ "setOrientation(Orientation)", &slot_3, QMetaData::Public },
	{ "setCaption(const QString&)", &slot_4, QMetaData::Public },
	{ "toggleVisible()", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "o", &static_QUType_ptr, "Orientation", QUParameter::In }
    };
    static const QUMethod signal_0 = {"orientationChanged", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "p", &static_QUType_ptr, "QDockWindow::Place", QUParameter::In }
    };
    static const QUMethod signal_1 = {"placeChanged", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"visibilityChanged", 1, param_signal_2 };
    static const QMetaData signal_tbl[] = {
	{ "orientationChanged(Orientation)", &signal_0, QMetaData::Public },
	{ "placeChanged(QDockWindow::Place)", &signal_1, QMetaData::Public },
	{ "visibilityChanged(bool)", &signal_2, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[10] = {
 	{ "int","closeMode", 0x10000103, &QDockWindow::metaObj, 0, -1 },
	{ "bool","resizeEnabled", 0x12000103, &QDockWindow::metaObj, 0, -1 },
	{ "bool","movingEnabled", 0x12000103, &QDockWindow::metaObj, 0, -1 },
	{ "bool","horizontallyStretchable", 0x12000103, &QDockWindow::metaObj, 0, -1 },
	{ "bool","verticallyStretchable", 0x12000103, &QDockWindow::metaObj, 0, -1 },
	{ "bool","stretchable", 0x12000001, &QDockWindow::metaObj, 0, -1 },
	{ "bool","newLine", 0x12000103, &QDockWindow::metaObj, 0, -1 },
	{ "bool","opaqueMoving", 0x12000103, &QDockWindow::metaObj, 0, -1 },
	{ "int","offset", 0x10000103, &QDockWindow::metaObj, 0, -1 },
	{ "Place","place", 0x0005, &QDockWindow::metaObj, &enum_tbl[0], -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QDockWindow", parentObject,
	slot_tbl, 6,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	props_tbl, 10,
	enum_tbl, 2,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDockWindow.setMetaObject( metaObj );
    return metaObj;
}

void* QDockWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDockWindow" ) )
	return this;
    return QFrame::qt_cast( clname );
}

// SIGNAL orientationChanged
void QDockWindow::orientationChanged( Orientation t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL placeChanged
void QDockWindow::placeChanged( QDockWindow::Place t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL visibilityChanged
void QDockWindow::visibilityChanged( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 2, t0 );
}

bool QDockWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: undock((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 1: undock(); break;
    case 2: dock(); break;
    case 3: setOrientation((Orientation)(*((Orientation*)static_QUType_ptr.get(_o+1)))); break;
    case 4: setCaption((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: toggleVisible(); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDockWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: orientationChanged((Orientation)(*((Orientation*)static_QUType_ptr.get(_o+1)))); break;
    case 1: placeChanged((QDockWindow::Place)(*((QDockWindow::Place*)static_QUType_ptr.get(_o+1)))); break;
    case 2: visibilityChanged((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QDockWindow::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setCloseMode(v->asInt()); break;
	case 1: *v = QVariant( this->closeMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setResizeEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isResizeEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setMovingEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isMovingEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setHorizontallyStretchable(v->asBool()); break;
	case 1: *v = QVariant( this->isHorizontallyStretchable(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setVerticallyStretchable(v->asBool()); break;
	case 1: *v = QVariant( this->isVerticallyStretchable(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 1: *v = QVariant( this->isStretchable(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setNewLine(v->asBool()); break;
	case 1: *v = QVariant( this->newLine(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setOpaqueMoving(v->asBool()); break;
	case 1: *v = QVariant( this->opaqueMoving(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setOffset(v->asInt()); break;
	case 1: *v = QVariant( this->offset() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 1: *v = QVariant( (int)this->place() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QFrame::qt_property( id, f, v );
    }
    return TRUE;
}

bool QDockWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QCommonStyle::className() const
{
    return "QCommonStyle";
}

QMetaObject *QCommonStyle::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCommonStyle( "QCommonStyle", &QCommonStyle::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCommonStyle::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCommonStyle", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCommonStyle::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCommonStyle", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCommonStyle::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QStyle::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QCommonStyle", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCommonStyle.setMetaObject( metaObj );
    return metaObj;
}

void* QCommonStyle::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCommonStyle" ) )
	return this;
    return QStyle::qt_cast( clname );
}

bool QCommonStyle::qt_invoke( int _id, QUObject* _o )
{
    return QStyle::qt_invoke(_id,_o);
}

bool QCommonStyle::qt_emit( int _id, QUObject* _o )
{
    return QStyle::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCommonStyle::qt_property( int id, int f, QVariant* v)
{
    return QStyle::qt_property( id, f, v);
}

bool QCommonStyle::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QNetworkProtocol::className() const
{
    return "QNetworkProtocol";
}

QMetaObject *QNetworkProtocol::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QNetworkProtocol( "QNetworkProtocol", &QNetworkProtocol::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QNetworkProtocol::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QNetworkProtocol", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QNetworkProtocol::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QNetworkProtocol", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QNetworkProtocol::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "old", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_0 = {"processNextOperation", 1, param_slot_0 };
    static const QUMethod slot_1 = {"startOps", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "i", &static_QUType_ptr, "QUrlInfo", QUParameter::In },
	{ "op", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_2 = {"emitNewChildren", 2, param_slot_2 };
    static const QUMethod slot_3 = {"removeMe", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "processNextOperation(QNetworkOperation*)", &slot_0, QMetaData::Private },
	{ "startOps()", &slot_1, QMetaData::Private },
	{ "emitNewChildren(const QUrlInfo&,QNetworkOperation*)", &slot_2, QMetaData::Private },
	{ "removeMe()", &slot_3, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_varptr, "\x1d", QUParameter::In },
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_0 = {"data", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In },
	{ "data", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"connectionStateChanged", 2, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_2 = {"finished", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_3 = {"start", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "QValueList<QUrlInfo>", QUParameter::In },
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_4 = {"newChildren", 2, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_ptr, "QUrlInfo", QUParameter::In },
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_5 = {"newChild", 2, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_ptr, "QUrlInfo", QUParameter::In },
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_6 = {"createdDirectory", 2, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_7 = {"removed", 1, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_8 = {"itemChanged", 1, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ "bytesDone", &static_QUType_int, 0, QUParameter::In },
	{ "bytesTotal", &static_QUType_int, 0, QUParameter::In },
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_9 = {"dataTransferProgress", 3, param_signal_9 };
    static const QMetaData signal_tbl[] = {
	{ "data(const QByteArray&,QNetworkOperation*)", &signal_0, QMetaData::Public },
	{ "connectionStateChanged(int,const QString&)", &signal_1, QMetaData::Public },
	{ "finished(QNetworkOperation*)", &signal_2, QMetaData::Public },
	{ "start(QNetworkOperation*)", &signal_3, QMetaData::Public },
	{ "newChildren(const QValueList<QUrlInfo>&,QNetworkOperation*)", &signal_4, QMetaData::Public },
	{ "newChild(const QUrlInfo&,QNetworkOperation*)", &signal_5, QMetaData::Public },
	{ "createdDirectory(const QUrlInfo&,QNetworkOperation*)", &signal_6, QMetaData::Public },
	{ "removed(QNetworkOperation*)", &signal_7, QMetaData::Public },
	{ "itemChanged(QNetworkOperation*)", &signal_8, QMetaData::Public },
	{ "dataTransferProgress(int,int,QNetworkOperation*)", &signal_9, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QNetworkProtocol", parentObject,
	slot_tbl, 4,
	signal_tbl, 10,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QNetworkProtocol.setMetaObject( metaObj );
    return metaObj;
}

void* QNetworkProtocol::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QNetworkProtocol" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL data
void QNetworkProtocol::data( const QByteArray& t0, QNetworkOperation* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_varptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL connectionStateChanged
void QNetworkProtocol::connectionStateChanged( int t0, const QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL finished
void QNetworkProtocol::finished( QNetworkOperation* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL start
void QNetworkProtocol::start( QNetworkOperation* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL newChildren
void QNetworkProtocol::newChildren( const QValueList<QUrlInfo>& t0, QNetworkOperation* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL newChild
void QNetworkProtocol::newChild( const QUrlInfo& t0, QNetworkOperation* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL createdDirectory
void QNetworkProtocol::createdDirectory( const QUrlInfo& t0, QNetworkOperation* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL removed
void QNetworkProtocol::removed( QNetworkOperation* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL itemChanged
void QNetworkProtocol::itemChanged( QNetworkOperation* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL dataTransferProgress
void QNetworkProtocol::dataTransferProgress( int t0, int t1, QNetworkOperation* t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_ptr.set(o+3,t2);
    activate_signal( clist, o );
}

bool QNetworkProtocol::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: processNextOperation((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 1: startOps(); break;
    case 2: emitNewChildren((const QUrlInfo&)*((const QUrlInfo*)static_QUType_ptr.get(_o+1)),(QNetworkOperation*)static_QUType_ptr.get(_o+2)); break;
    case 3: removeMe(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QNetworkProtocol::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: data((const QByteArray&)*((const QByteArray*)static_QUType_ptr.get(_o+1)),(QNetworkOperation*)static_QUType_ptr.get(_o+2)); break;
    case 1: connectionStateChanged((int)static_QUType_int.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 2: finished((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 3: start((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 4: newChildren((const QValueList<QUrlInfo>&)*((const QValueList<QUrlInfo>*)static_QUType_ptr.get(_o+1)),(QNetworkOperation*)static_QUType_ptr.get(_o+2)); break;
    case 5: newChild((const QUrlInfo&)*((const QUrlInfo*)static_QUType_ptr.get(_o+1)),(QNetworkOperation*)static_QUType_ptr.get(_o+2)); break;
    case 6: createdDirectory((const QUrlInfo&)*((const QUrlInfo*)static_QUType_ptr.get(_o+1)),(QNetworkOperation*)static_QUType_ptr.get(_o+2)); break;
    case 7: removed((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 8: itemChanged((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 9: dataTransferProgress((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(QNetworkOperation*)static_QUType_ptr.get(_o+3)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QNetworkProtocol::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QNetworkProtocol::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QNetworkOperation::className() const
{
    return "QNetworkOperation";
}

QMetaObject *QNetworkOperation::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QNetworkOperation( "QNetworkOperation", &QNetworkOperation::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QNetworkOperation::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QNetworkOperation", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QNetworkOperation::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QNetworkOperation", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QNetworkOperation::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"deleteMe", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "deleteMe()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QNetworkOperation", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QNetworkOperation.setMetaObject( metaObj );
    return metaObj;
}

void* QNetworkOperation::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QNetworkOperation" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QNetworkOperation::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: deleteMe(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QNetworkOperation::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QNetworkOperation::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QNetworkOperation::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QGPlugin::className() const
{
    return "QGPlugin";
}

QMetaObject *QGPlugin::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QGPlugin( "QGPlugin", &QGPlugin::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QGPlugin::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGPlugin", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QGPlugin::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGPlugin", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QGPlugin::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QGPlugin", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QGPlugin.setMetaObject( metaObj );
    return metaObj;
}

void* QGPlugin::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QGPlugin" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QGPlugin::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QGPlugin::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QGPlugin::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QGPlugin::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QGrid::className() const
{
    return "QGrid";
}

QMetaObject *QGrid::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QGrid( "QGrid", &QGrid::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QGrid::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGrid", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QGrid::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGrid", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QGrid::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QGrid", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QGrid.setMetaObject( metaObj );
    return metaObj;
}

void* QGrid::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QGrid" ) )
	return this;
    return QFrame::qt_cast( clname );
}

bool QGrid::qt_invoke( int _id, QUObject* _o )
{
    return QFrame::qt_invoke(_id,_o);
}

bool QGrid::qt_emit( int _id, QUObject* _o )
{
    return QFrame::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QGrid::qt_property( int id, int f, QVariant* v)
{
    return QFrame::qt_property( id, f, v);
}

bool QGrid::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSpinWidget::className() const
{
    return "QSpinWidget";
}

QMetaObject *QSpinWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSpinWidget( "QSpinWidget", &QSpinWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSpinWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSpinWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSpinWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSpinWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSpinWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"stepUp", 0, 0 };
    static const QUMethod slot_1 = {"stepDown", 0, 0 };
    static const QUMethod slot_2 = {"timerDone", 0, 0 };
    static const QUMethod slot_3 = {"timerDoneEx", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "stepUp()", &slot_0, QMetaData::Public },
	{ "stepDown()", &slot_1, QMetaData::Public },
	{ "timerDone()", &slot_2, QMetaData::Private },
	{ "timerDoneEx()", &slot_3, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"stepUpPressed", 0, 0 };
    static const QUMethod signal_1 = {"stepDownPressed", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "stepUpPressed()", &signal_0, QMetaData::Public },
	{ "stepDownPressed()", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSpinWidget", parentObject,
	slot_tbl, 4,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSpinWidget.setMetaObject( metaObj );
    return metaObj;
}

void* QSpinWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSpinWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL stepUpPressed
void QSpinWidget::stepUpPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL stepDownPressed
void QSpinWidget::stepDownPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool QSpinWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: stepUp(); break;
    case 1: stepDown(); break;
    case 2: timerDone(); break;
    case 3: timerDoneEx(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSpinWidget::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: stepUpPressed(); break;
    case 1: stepDownPressed(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QSpinWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QSpinWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QButtonGroup::className() const
{
    return "QButtonGroup";
}

QMetaObject *QButtonGroup::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QButtonGroup( "QButtonGroup", &QButtonGroup::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QButtonGroup::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QButtonGroup", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QButtonGroup::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QButtonGroup", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QButtonGroup::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGroupBox::staticMetaObject();
    static const QUMethod slot_0 = {"buttonPressed", 0, 0 };
    static const QUMethod slot_1 = {"buttonReleased", 0, 0 };
    static const QUMethod slot_2 = {"buttonClicked", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "on", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"buttonToggled", 1, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "buttonPressed()", &slot_0, QMetaData::Protected },
	{ "buttonReleased()", &slot_1, QMetaData::Protected },
	{ "buttonClicked()", &slot_2, QMetaData::Protected },
	{ "buttonToggled(bool)", &slot_3, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"pressed", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"released", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"clicked", 1, param_signal_2 };
    static const QMetaData signal_tbl[] = {
	{ "pressed(int)", &signal_0, QMetaData::Public },
	{ "released(int)", &signal_1, QMetaData::Public },
	{ "clicked(int)", &signal_2, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[3] = {
 	{ "bool","exclusive", 0x12000103, &QButtonGroup::metaObj, 0, -1 },
	{ "bool","radioButtonExclusive", 0x12000103, &QButtonGroup::metaObj, 0, -1 },
	{ "int","selectedId", 0x10000003, &QButtonGroup::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QButtonGroup", parentObject,
	slot_tbl, 4,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	props_tbl, 3,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QButtonGroup.setMetaObject( metaObj );
    return metaObj;
}

void* QButtonGroup::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QButtonGroup" ) )
	return this;
    return QGroupBox::qt_cast( clname );
}

// SIGNAL pressed
void QButtonGroup::pressed( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL released
void QButtonGroup::released( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL clicked
void QButtonGroup::clicked( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

bool QButtonGroup::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: buttonPressed(); break;
    case 1: buttonReleased(); break;
    case 2: buttonClicked(); break;
    case 3: buttonToggled((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QGroupBox::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QButtonGroup::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: pressed((int)static_QUType_int.get(_o+1)); break;
    case 1: released((int)static_QUType_int.get(_o+1)); break;
    case 2: clicked((int)static_QUType_int.get(_o+1)); break;
    default:
	return QGroupBox::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QButtonGroup::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setExclusive(v->asBool()); break;
	case 1: *v = QVariant( this->isExclusive(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setRadioButtonExclusive(v->asBool()); break;
	case 1: *v = QVariant( this->isRadioButtonExclusive(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setButton(v->asInt()); break;
	case 1: *v = QVariant( this->selectedId() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QGroupBox::qt_property( id, f, v );
    }
    return TRUE;
}

bool QButtonGroup::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDateTimeEditBase::className() const
{
    return "QDateTimeEditBase";
}

QMetaObject *QDateTimeEditBase::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDateTimeEditBase( "QDateTimeEditBase", &QDateTimeEditBase::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDateTimeEditBase::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDateTimeEditBase", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDateTimeEditBase::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDateTimeEditBase", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDateTimeEditBase::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"stepUp", 0, 0 };
    static const QUMethod slot_1 = {"stepDown", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "stepUp()", &slot_0, QMetaData::Public },
	{ "stepDown()", &slot_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDateTimeEditBase", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDateTimeEditBase.setMetaObject( metaObj );
    return metaObj;
}

void* QDateTimeEditBase::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDateTimeEditBase" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QDateTimeEditBase::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: stepUp(); break;
    case 1: stepDown(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDateTimeEditBase::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDateTimeEditBase::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QDateTimeEditBase::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDateEdit::className() const
{
    return "QDateEdit";
}

QMetaObject *QDateEdit::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDateEdit( "QDateEdit", &QDateEdit::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDateEdit::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDateEdit", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDateEdit::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDateEdit", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDateEdit::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDateTimeEditBase::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "DMY",  (int) QDateEdit::DMY },
	{ "MDY",  (int) QDateEdit::MDY },
	{ "YMD",  (int) QDateEdit::YMD },
	{ "YDM",  (int) QDateEdit::YDM }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "Order", 4, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "date", &static_QUType_varptr, "\x1a", QUParameter::In }
    };
    static const QUMethod slot_0 = {"setDate", 1, param_slot_0 };
    static const QUMethod slot_1 = {"updateButtons", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setDate(const QDate&)", &slot_0, QMetaData::Public },
	{ "updateButtons()", &slot_1, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ "date", &static_QUType_varptr, "\x1a", QUParameter::In }
    };
    static const QUMethod signal_0 = {"valueChanged", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "valueChanged(const QDate&)", &signal_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[5] = {
 	{ "Order","order", 0x0107, &QDateEdit::metaObj, &enum_tbl[0], -1 },
	{ "QDate","date", 0x1a000103, &QDateEdit::metaObj, 0, -1 },
	{ "bool","autoAdvance", 0x12000103, &QDateEdit::metaObj, 0, -1 },
	{ "QDate","maxValue", 0x1a000103, &QDateEdit::metaObj, 0, -1 },
	{ "QDate","minValue", 0x1a000103, &QDateEdit::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QDateEdit", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	props_tbl, 5,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDateEdit.setMetaObject( metaObj );
    return metaObj;
}

void* QDateEdit::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDateEdit" ) )
	return this;
    return QDateTimeEditBase::qt_cast( clname );
}

// SIGNAL valueChanged
void QDateEdit::valueChanged( const QDate& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_varptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool QDateEdit::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setDate((const QDate&)*((const QDate*)static_QUType_ptr.get(_o+1))); break;
    case 1: updateButtons(); break;
    default:
	return QDateTimeEditBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDateEdit::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: valueChanged((const QDate&)*((const QDate*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QDateTimeEditBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QDateEdit::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setOrder((Order&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->order() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setDate(v->asDate()); break;
	case 1: *v = QVariant( this->date() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setAutoAdvance(v->asBool()); break;
	case 1: *v = QVariant( this->autoAdvance(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setMaxValue(v->asDate()); break;
	case 1: *v = QVariant( this->maxValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setMinValue(v->asDate()); break;
	case 1: *v = QVariant( this->minValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QDateTimeEditBase::qt_property( id, f, v );
    }
    return TRUE;
}

bool QDateEdit::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTimeEdit::className() const
{
    return "QTimeEdit";
}

QMetaObject *QTimeEdit::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTimeEdit( "QTimeEdit", &QTimeEdit::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTimeEdit::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTimeEdit", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTimeEdit::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTimeEdit", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTimeEdit::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDateTimeEditBase::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "Hours",  (int) QTimeEdit::Hours },
	{ "Minutes",  (int) QTimeEdit::Minutes },
	{ "Seconds",  (int) QTimeEdit::Seconds },
	{ "AMPM",  (int) QTimeEdit::AMPM }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "Display", 4, enum_0, TRUE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "time", &static_QUType_varptr, "\x1b", QUParameter::In }
    };
    static const QUMethod slot_0 = {"setTime", 1, param_slot_0 };
    static const QUMethod slot_1 = {"updateButtons", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setTime(const QTime&)", &slot_0, QMetaData::Public },
	{ "updateButtons()", &slot_1, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ "time", &static_QUType_varptr, "\x1b", QUParameter::In }
    };
    static const QUMethod signal_0 = {"valueChanged", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "valueChanged(const QTime&)", &signal_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[5] = {
 	{ "QTime","time", 0x1b000103, &QTimeEdit::metaObj, 0, -1 },
	{ "bool","autoAdvance", 0x12000103, &QTimeEdit::metaObj, 0, -1 },
	{ "QTime","maxValue", 0x1b000103, &QTimeEdit::metaObj, 0, -1 },
	{ "QTime","minValue", 0x1b000103, &QTimeEdit::metaObj, 0, -1 },
	{ "Display","display", 0x0107, &QTimeEdit::metaObj, &enum_tbl[0], -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QTimeEdit", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	props_tbl, 5,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTimeEdit.setMetaObject( metaObj );
    return metaObj;
}

void* QTimeEdit::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTimeEdit" ) )
	return this;
    return QDateTimeEditBase::qt_cast( clname );
}

// SIGNAL valueChanged
void QTimeEdit::valueChanged( const QTime& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_varptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool QTimeEdit::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setTime((const QTime&)*((const QTime*)static_QUType_ptr.get(_o+1))); break;
    case 1: updateButtons(); break;
    default:
	return QDateTimeEditBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QTimeEdit::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: valueChanged((const QTime&)*((const QTime*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QDateTimeEditBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QTimeEdit::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setTime(v->asTime()); break;
	case 1: *v = QVariant( this->time() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setAutoAdvance(v->asBool()); break;
	case 1: *v = QVariant( this->autoAdvance(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setMaxValue(v->asTime()); break;
	case 1: *v = QVariant( this->maxValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setMinValue(v->asTime()); break;
	case 1: *v = QVariant( this->minValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setDisplay(v->asUInt()); break;
	case 1: *v = QVariant( (int)this->display() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QDateTimeEditBase::qt_property( id, f, v );
    }
    return TRUE;
}

bool QTimeEdit::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDateTimeEdit::className() const
{
    return "QDateTimeEdit";
}

QMetaObject *QDateTimeEdit::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDateTimeEdit( "QDateTimeEdit", &QDateTimeEdit::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDateTimeEdit::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDateTimeEdit", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDateTimeEdit::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDateTimeEdit", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDateTimeEdit::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "dt", &static_QUType_varptr, "\x1c", QUParameter::In }
    };
    static const QUMethod slot_0 = {"setDateTime", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "d", &static_QUType_varptr, "\x1a", QUParameter::In }
    };
    static const QUMethod slot_1 = {"newValue", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "t", &static_QUType_varptr, "\x1b", QUParameter::In }
    };
    static const QUMethod slot_2 = {"newValue", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "setDateTime(const QDateTime&)", &slot_0, QMetaData::Public },
	{ "newValue(const QDate&)", &slot_1, QMetaData::Protected },
	{ "newValue(const QTime&)", &slot_2, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ "datetime", &static_QUType_varptr, "\x1c", QUParameter::In }
    };
    static const QUMethod signal_0 = {"valueChanged", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "valueChanged(const QDateTime&)", &signal_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[1] = {
 	{ "QDateTime","dateTime", 0x1c000103, &QDateTimeEdit::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QDateTimeEdit", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	props_tbl, 1,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDateTimeEdit.setMetaObject( metaObj );
    return metaObj;
}

void* QDateTimeEdit::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDateTimeEdit" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL valueChanged
void QDateTimeEdit::valueChanged( const QDateTime& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_varptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool QDateTimeEdit::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setDateTime((const QDateTime&)*((const QDateTime*)static_QUType_ptr.get(_o+1))); break;
    case 1: newValue((const QDate&)*((const QDate*)static_QUType_ptr.get(_o+1))); break;
    case 2: newValue((const QTime&)*((const QTime*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDateTimeEdit::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: valueChanged((const QDateTime&)*((const QDateTime*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QDateTimeEdit::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setDateTime(v->asDateTime()); break;
	case 1: *v = QVariant( this->dateTime() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QDateTimeEdit::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QHBox::className() const
{
    return "QHBox";
}

QMetaObject *QHBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QHBox( "QHBox", &QHBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QHBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QHBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QHBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QHBox", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QHBox.setMetaObject( metaObj );
    return metaObj;
}

void* QHBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QHBox" ) )
	return this;
    return QFrame::qt_cast( clname );
}

bool QHBox::qt_invoke( int _id, QUObject* _o )
{
    return QFrame::qt_invoke(_id,_o);
}

bool QHBox::qt_emit( int _id, QUObject* _o )
{
    return QFrame::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QHBox::qt_property( int id, int f, QVariant* v)
{
    return QFrame::qt_property( id, f, v);
}

bool QHBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QHButtonGroup::className() const
{
    return "QHButtonGroup";
}

QMetaObject *QHButtonGroup::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QHButtonGroup( "QHButtonGroup", &QHButtonGroup::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QHButtonGroup::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHButtonGroup", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QHButtonGroup::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHButtonGroup", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QHButtonGroup::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QButtonGroup::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QHButtonGroup", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QHButtonGroup.setMetaObject( metaObj );
    return metaObj;
}

void* QHButtonGroup::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QHButtonGroup" ) )
	return this;
    return QButtonGroup::qt_cast( clname );
}

bool QHButtonGroup::qt_invoke( int _id, QUObject* _o )
{
    return QButtonGroup::qt_invoke(_id,_o);
}

bool QHButtonGroup::qt_emit( int _id, QUObject* _o )
{
    return QButtonGroup::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QHButtonGroup::qt_property( int id, int f, QVariant* v)
{
    return QButtonGroup::qt_property( id, f, v);
}

bool QHButtonGroup::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QHGroupBox::className() const
{
    return "QHGroupBox";
}

QMetaObject *QHGroupBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QHGroupBox( "QHGroupBox", &QHGroupBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QHGroupBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHGroupBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QHGroupBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHGroupBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QHGroupBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGroupBox::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QHGroupBox", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QHGroupBox.setMetaObject( metaObj );
    return metaObj;
}

void* QHGroupBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QHGroupBox" ) )
	return this;
    return QGroupBox::qt_cast( clname );
}

bool QHGroupBox::qt_invoke( int _id, QUObject* _o )
{
    return QGroupBox::qt_invoke(_id,_o);
}

bool QHGroupBox::qt_emit( int _id, QUObject* _o )
{
    return QGroupBox::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QHGroupBox::qt_property( int id, int f, QVariant* v)
{
    return QGroupBox::qt_property( id, f, v);
}

bool QHGroupBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSocketNotifier::className() const
{
    return "QSocketNotifier";
}

QMetaObject *QSocketNotifier::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSocketNotifier( "QSocketNotifier", &QSocketNotifier::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSocketNotifier::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSocketNotifier", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSocketNotifier::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSocketNotifier", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSocketNotifier::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ "socket", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"activated", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "activated(int)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSocketNotifier", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSocketNotifier.setMetaObject( metaObj );
    return metaObj;
}

void* QSocketNotifier::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSocketNotifier" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL activated
void QSocketNotifier::activated( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool QSocketNotifier::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QSocketNotifier::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: activated((int)static_QUType_int.get(_o+1)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QSocketNotifier::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QSocketNotifier::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QEventLoop::className() const
{
    return "QEventLoop";
}

QMetaObject *QEventLoop::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QEventLoop( "QEventLoop", &QEventLoop::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QEventLoop::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QEventLoop", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QEventLoop::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QEventLoop", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QEventLoop::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod signal_0 = {"awake", 0, 0 };
    static const QUMethod signal_1 = {"aboutToBlock", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "awake()", &signal_0, QMetaData::Public },
	{ "aboutToBlock()", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QEventLoop", parentObject,
	0, 0,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QEventLoop.setMetaObject( metaObj );
    return metaObj;
}

void* QEventLoop::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QEventLoop" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL awake
void QEventLoop::awake()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL aboutToBlock
void QEventLoop::aboutToBlock()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool QEventLoop::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QEventLoop::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: awake(); break;
    case 1: aboutToBlock(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QEventLoop::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QEventLoop::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QHttp::className() const
{
    return "QHttp";
}

QMetaObject *QHttp::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QHttp( "QHttp", &QHttp::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QHttp::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHttp", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QHttp::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHttp", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QHttp::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QNetworkProtocol::staticMetaObject();
    static const QUMethod slot_0 = {"abort", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "rep", &static_QUType_ptr, "QHttpResponseHeader", QUParameter::In }
    };
    static const QUMethod slot_1 = {"clientReply", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"clientDone", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"clientStateChanged", 1, param_slot_3 };
    static const QUMethod slot_4 = {"startNextRequest", 0, 0 };
    static const QUMethod slot_5 = {"slotReadyRead", 0, 0 };
    static const QUMethod slot_6 = {"slotConnected", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"slotError", 1, param_slot_7 };
    static const QUMethod slot_8 = {"slotClosed", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"slotBytesWritten", 1, param_slot_9 };
    static const QMetaData slot_tbl[] = {
	{ "abort()", &slot_0, QMetaData::Public },
	{ "clientReply(const QHttpResponseHeader&)", &slot_1, QMetaData::Private },
	{ "clientDone(bool)", &slot_2, QMetaData::Private },
	{ "clientStateChanged(int)", &slot_3, QMetaData::Private },
	{ "startNextRequest()", &slot_4, QMetaData::Private },
	{ "slotReadyRead()", &slot_5, QMetaData::Private },
	{ "slotConnected()", &slot_6, QMetaData::Private },
	{ "slotError(int)", &slot_7, QMetaData::Private },
	{ "slotClosed()", &slot_8, QMetaData::Private },
	{ "slotBytesWritten(int)", &slot_9, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"stateChanged", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "resp", &static_QUType_ptr, "QHttpResponseHeader", QUParameter::In }
    };
    static const QUMethod signal_1 = {"responseHeaderReceived", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "resp", &static_QUType_ptr, "QHttpResponseHeader", QUParameter::In }
    };
    static const QUMethod signal_2 = {"readyRead", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"dataSendProgress", 2, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"dataReadProgress", 2, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_5 = {"requestStarted", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_6 = {"requestFinished", 2, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_7 = {"done", 1, param_signal_7 };
    static const QMetaData signal_tbl[] = {
	{ "stateChanged(int)", &signal_0, QMetaData::Public },
	{ "responseHeaderReceived(const QHttpResponseHeader&)", &signal_1, QMetaData::Public },
	{ "readyRead(const QHttpResponseHeader&)", &signal_2, QMetaData::Public },
	{ "dataSendProgress(int,int)", &signal_3, QMetaData::Public },
	{ "dataReadProgress(int,int)", &signal_4, QMetaData::Public },
	{ "requestStarted(int)", &signal_5, QMetaData::Public },
	{ "requestFinished(int,bool)", &signal_6, QMetaData::Public },
	{ "done(bool)", &signal_7, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QHttp", parentObject,
	slot_tbl, 10,
	signal_tbl, 8,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QHttp.setMetaObject( metaObj );
    return metaObj;
}

void* QHttp::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QHttp" ) )
	return this;
    return QNetworkProtocol::qt_cast( clname );
}

// SIGNAL stateChanged
void QHttp::stateChanged( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL responseHeaderReceived
void QHttp::responseHeaderReceived( const QHttpResponseHeader& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL readyRead
void QHttp::readyRead( const QHttpResponseHeader& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL dataSendProgress
void QHttp::dataSendProgress( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL dataReadProgress
void QHttp::dataReadProgress( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL requestStarted
void QHttp::requestStarted( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 5, t0 );
}

// SIGNAL requestFinished
void QHttp::requestFinished( int t0, bool t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_bool.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL done
void QHttp::done( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 7, t0 );
}

bool QHttp::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: abort(); break;
    case 1: clientReply((const QHttpResponseHeader&)*((const QHttpResponseHeader*)static_QUType_ptr.get(_o+1))); break;
    case 2: clientDone((bool)static_QUType_bool.get(_o+1)); break;
    case 3: clientStateChanged((int)static_QUType_int.get(_o+1)); break;
    case 4: startNextRequest(); break;
    case 5: slotReadyRead(); break;
    case 6: slotConnected(); break;
    case 7: slotError((int)static_QUType_int.get(_o+1)); break;
    case 8: slotClosed(); break;
    case 9: slotBytesWritten((int)static_QUType_int.get(_o+1)); break;
    default:
	return QNetworkProtocol::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QHttp::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 1: responseHeaderReceived((const QHttpResponseHeader&)*((const QHttpResponseHeader*)static_QUType_ptr.get(_o+1))); break;
    case 2: readyRead((const QHttpResponseHeader&)*((const QHttpResponseHeader*)static_QUType_ptr.get(_o+1))); break;
    case 3: dataSendProgress((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 4: dataReadProgress((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 5: requestStarted((int)static_QUType_int.get(_o+1)); break;
    case 6: requestFinished((int)static_QUType_int.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 7: done((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QNetworkProtocol::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QHttp::qt_property( int id, int f, QVariant* v)
{
    return QNetworkProtocol::qt_property( id, f, v);
}

bool QHttp::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QAction::className() const
{
    return "QAction";
}

QMetaObject *QAction::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAction( "QAction", &QAction::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAction::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAction", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAction::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAction", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAction::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"activate", 0, 0 };
    static const QUMethod slot_1 = {"toggle", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setOn", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"setEnabled", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setDisabled", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setVisible", 1, param_slot_5 };
    static const QUMethod slot_6 = {"internalActivation", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"toolButtonToggled", 1, param_slot_7 };
    static const QUMethod slot_8 = {"objectDestroyed", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"menuStatusText", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"showStatusText", 1, param_slot_10 };
    static const QUMethod slot_11 = {"clearStatusText", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "activate()", &slot_0, QMetaData::Public },
	{ "toggle()", &slot_1, QMetaData::Public },
	{ "setOn(bool)", &slot_2, QMetaData::Public },
	{ "setEnabled(bool)", &slot_3, QMetaData::Public },
	{ "setDisabled(bool)", &slot_4, QMetaData::Public },
	{ "setVisible(bool)", &slot_5, QMetaData::Public },
	{ "internalActivation()", &slot_6, QMetaData::Private },
	{ "toolButtonToggled(bool)", &slot_7, QMetaData::Private },
	{ "objectDestroyed()", &slot_8, QMetaData::Private },
	{ "menuStatusText(int)", &slot_9, QMetaData::Private },
	{ "showStatusText(const QString&)", &slot_10, QMetaData::Private },
	{ "clearStatusText()", &slot_11, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"activated", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"toggled", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "activated()", &signal_0, QMetaData::Public },
	{ "toggled(bool)", &signal_1, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[11] = {
 	{ "bool","toggleAction", 0x12000103, &QAction::metaObj, 0, -1 },
	{ "bool","on", 0x12000103, &QAction::metaObj, 0, -1 },
	{ "bool","enabled", 0x12000103, &QAction::metaObj, 0, -1 },
	{ "QIconSet","iconSet", 0xd000103, &QAction::metaObj, 0, -1 },
	{ "QString","text", 0x3000103, &QAction::metaObj, 0, -1 },
	{ "QString","menuText", 0x3000103, &QAction::metaObj, 0, -1 },
	{ "QString","toolTip", 0x3000103, &QAction::metaObj, 0, -1 },
	{ "QString","statusTip", 0x3000103, &QAction::metaObj, 0, -1 },
	{ "QString","whatsThis", 0x3000103, &QAction::metaObj, 0, -1 },
	{ "QKeySequence","accel", 0x1f000103, &QAction::metaObj, 0, -1 },
	{ "bool","visible", 0x12000103, &QAction::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QAction", parentObject,
	slot_tbl, 12,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	props_tbl, 11,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAction.setMetaObject( metaObj );
    return metaObj;
}

void* QAction::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAction" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL activated
void QAction::activated()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL toggled
void QAction::toggled( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 1, t0 );
}

bool QAction::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: activate(); break;
    case 1: toggle(); break;
    case 2: setOn((bool)static_QUType_bool.get(_o+1)); break;
    case 3: setEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 4: setDisabled((bool)static_QUType_bool.get(_o+1)); break;
    case 5: setVisible((bool)static_QUType_bool.get(_o+1)); break;
    case 6: internalActivation(); break;
    case 7: toolButtonToggled((bool)static_QUType_bool.get(_o+1)); break;
    case 8: objectDestroyed(); break;
    case 9: menuStatusText((int)static_QUType_int.get(_o+1)); break;
    case 10: showStatusText((const QString&)static_QUType_QString.get(_o+1)); break;
    case 11: clearStatusText(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QAction::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: activated(); break;
    case 1: toggled((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QAction::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setToggleAction(v->asBool()); break;
	case 1: *v = QVariant( this->isToggleAction(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setOn(v->asBool()); break;
	case 1: *v = QVariant( this->isOn(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setIconSet(v->asIconSet()); break;
	case 1: *v = QVariant( this->iconSet() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setText(v->asString()); break;
	case 1: *v = QVariant( this->text() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setMenuText(v->asString()); break;
	case 1: *v = QVariant( this->menuText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setToolTip(v->asString()); break;
	case 1: *v = QVariant( this->toolTip() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setStatusTip(v->asString()); break;
	case 1: *v = QVariant( this->statusTip() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setWhatsThis(v->asString()); break;
	case 1: *v = QVariant( this->whatsThis() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setAccel(v->asKeySequence()); break;
	case 1: *v = QVariant( this->accel() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 0: setVisible(v->asBool()); break;
	case 1: *v = QVariant( this->isVisible(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QObject::qt_property( id, f, v );
    }
    return TRUE;
}

bool QAction::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QActionGroup::className() const
{
    return "QActionGroup";
}

QMetaObject *QActionGroup::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QActionGroup( "QActionGroup", &QActionGroup::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QActionGroup::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActionGroup", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QActionGroup::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QActionGroup", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QActionGroup::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QAction::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"childToggled", 1, param_slot_0 };
    static const QUMethod slot_1 = {"childDestroyed", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"internalComboBoxActivated", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"internalComboBoxHighlighted", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QAction", QUParameter::In }
    };
    static const QUMethod slot_4 = {"internalToggle", 1, param_slot_4 };
    static const QUMethod slot_5 = {"objectDestroyed", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "childToggled(bool)", &slot_0, QMetaData::Private },
	{ "childDestroyed()", &slot_1, QMetaData::Private },
	{ "internalComboBoxActivated(int)", &slot_2, QMetaData::Private },
	{ "internalComboBoxHighlighted(int)", &slot_3, QMetaData::Private },
	{ "internalToggle(QAction*)", &slot_4, QMetaData::Private },
	{ "objectDestroyed()", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QAction", QUParameter::In }
    };
    static const QUMethod signal_0 = {"selected", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "selected(QAction*)", &signal_0, QMetaData::Protected }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[2] = {
 	{ "bool","exclusive", 0x12000103, &QActionGroup::metaObj, 0, -1 },
	{ "bool","usesDropDown", 0x12000103, &QActionGroup::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QActionGroup", parentObject,
	slot_tbl, 6,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	props_tbl, 2,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QActionGroup.setMetaObject( metaObj );
    return metaObj;
}

void* QActionGroup::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QActionGroup" ) )
	return this;
    return QAction::qt_cast( clname );
}

// SIGNAL selected
void QActionGroup::selected( QAction* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QActionGroup::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: childToggled((bool)static_QUType_bool.get(_o+1)); break;
    case 1: childDestroyed(); break;
    case 2: internalComboBoxActivated((int)static_QUType_int.get(_o+1)); break;
    case 3: internalComboBoxHighlighted((int)static_QUType_int.get(_o+1)); break;
    case 4: internalToggle((QAction*)static_QUType_ptr.get(_o+1)); break;
    case 5: objectDestroyed(); break;
    default:
	return QAction::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QActionGroup::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: selected((QAction*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QAction::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QActionGroup::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setExclusive(v->asBool()); break;
	case 1: *v = QVariant( this->isExclusive(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setUsesDropDown(v->asBool()); break;
	case 1: *v = QVariant( this->usesDropDown(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QAction::qt_property( id, f, v );
    }
    return TRUE;
}

bool QActionGroup::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QImageFormatPlugin::className() const
{
    return "QImageFormatPlugin";
}

QMetaObject *QImageFormatPlugin::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QImageFormatPlugin( "QImageFormatPlugin", &QImageFormatPlugin::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QImageFormatPlugin::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QImageFormatPlugin", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QImageFormatPlugin::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QImageFormatPlugin", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QImageFormatPlugin::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGPlugin::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QImageFormatPlugin", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QImageFormatPlugin.setMetaObject( metaObj );
    return metaObj;
}

void* QImageFormatPlugin::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QImageFormatPlugin" ) )
	return this;
    return QGPlugin::qt_cast( clname );
}

bool QImageFormatPlugin::qt_invoke( int _id, QUObject* _o )
{
    return QGPlugin::qt_invoke(_id,_o);
}

bool QImageFormatPlugin::qt_emit( int _id, QUObject* _o )
{
    return QGPlugin::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QImageFormatPlugin::qt_property( int id, int f, QVariant* v)
{
    return QGPlugin::qt_property( id, f, v);
}

bool QImageFormatPlugin::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QLineEdit::className() const
{
    return "QLineEdit";
}

QMetaObject *QLineEdit::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QLineEdit( "QLineEdit", &QLineEdit::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QLineEdit::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QLineEdit", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QLineEdit::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QLineEdit", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QLineEdit::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "Normal",  (int) QLineEdit::Normal },
	{ "NoEcho",  (int) QLineEdit::NoEcho },
	{ "Password",  (int) QLineEdit::Password }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "EchoMode", 3, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setText", 1, param_slot_0 };
    static const QUMethod slot_1 = {"selectAll", 0, 0 };
    static const QUMethod slot_2 = {"deselect", 0, 0 };
    static const QUMethod slot_3 = {"clearValidator", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"insert", 1, param_slot_4 };
    static const QUMethod slot_5 = {"clear", 0, 0 };
    static const QUMethod slot_6 = {"undo", 0, 0 };
    static const QUMethod slot_7 = {"redo", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"setMaxLength", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"setFrame", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_enum, 
#ifndef QT_NO_PROPERTIES
	  &enum_tbl[0]
#else
	  0
#endif // QT_NO_PROPERTIES
	  , QUParameter::In }
    };
    static const QUMethod slot_10 = {"setEchoMode", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"setReadOnly", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_ptr, "QValidator", QUParameter::In }
    };
    static const QUMethod slot_12 = {"setValidator", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_varptr, "\x05", QUParameter::In }
    };
    static const QUMethod slot_13 = {"setFont", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_varptr, "\x0b", QUParameter::In }
    };
    static const QUMethod slot_14 = {"setPalette", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"setSelection", 2, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"setCursorPosition", 1, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ "flag", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"setAlignment", 1, param_slot_17 };
    static const QUMethod slot_18 = {"cut", 0, 0 };
    static const QUMethod slot_19 = {"copy", 0, 0 };
    static const QUMethod slot_20 = {"paste", 0, 0 };
    static const QUParameter param_slot_21[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"setDragEnabled", 1, param_slot_21 };
    static const QUMethod slot_22 = {"clipboardChanged", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setText(const QString&)", &slot_0, QMetaData::Public },
	{ "selectAll()", &slot_1, QMetaData::Public },
	{ "deselect()", &slot_2, QMetaData::Public },
	{ "clearValidator()", &slot_3, QMetaData::Public },
	{ "insert(const QString&)", &slot_4, QMetaData::Public },
	{ "clear()", &slot_5, QMetaData::Public },
	{ "undo()", &slot_6, QMetaData::Public },
	{ "redo()", &slot_7, QMetaData::Public },
	{ "setMaxLength(int)", &slot_8, QMetaData::Public },
	{ "setFrame(bool)", &slot_9, QMetaData::Public },
	{ "setEchoMode(EchoMode)", &slot_10, QMetaData::Public },
	{ "setReadOnly(bool)", &slot_11, QMetaData::Public },
	{ "setValidator(const QValidator*)", &slot_12, QMetaData::Public },
	{ "setFont(const QFont&)", &slot_13, QMetaData::Public },
	{ "setPalette(const QPalette&)", &slot_14, QMetaData::Public },
	{ "setSelection(int,int)", &slot_15, QMetaData::Public },
	{ "setCursorPosition(int)", &slot_16, QMetaData::Public },
	{ "setAlignment(int)", &slot_17, QMetaData::Public },
	{ "cut()", &slot_18, QMetaData::Public },
	{ "copy()", &slot_19, QMetaData::Public },
	{ "paste()", &slot_20, QMetaData::Public },
	{ "setDragEnabled(bool)", &slot_21, QMetaData::Public },
	{ "clipboardChanged()", &slot_22, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"textChanged", 1, param_signal_0 };
    static const QUMethod signal_1 = {"returnPressed", 0, 0 };
    static const QUMethod signal_2 = {"lostFocus", 0, 0 };
    static const QUMethod signal_3 = {"selectionChanged", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "textChanged(const QString&)", &signal_0, QMetaData::Public },
	{ "returnPressed()", &signal_1, QMetaData::Public },
	{ "lostFocus()", &signal_2, QMetaData::Public },
	{ "selectionChanged()", &signal_3, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[19] = {
 	{ "QString","text", 0x3000103, &QLineEdit::metaObj, 0, -1 },
	{ "int","maxLength", 0x10000103, &QLineEdit::metaObj, 0, -1 },
	{ "bool","frame", 0x12000103, &QLineEdit::metaObj, 0, -1 },
	{ "EchoMode","echoMode", 0x0107, &QLineEdit::metaObj, &enum_tbl[0], -1 },
	{ "QString","displayText", 0x3000001, &QLineEdit::metaObj, 0, -1 },
	{ "int","cursorPosition", 0x10000103, &QLineEdit::metaObj, 0, -1 },
	{ "Alignment","alignment", 0x010f, &QLineEdit::metaObj, 0, -1 },
	{ "bool","edited", 0x12001103, &QLineEdit::metaObj, 0, -1 },
	{ "bool","modified", 0x12000001, &QLineEdit::metaObj, 0, -1 },
	{ "bool","hasMarkedText", 0x12001001, &QLineEdit::metaObj, 0, -1 },
	{ "bool","hasSelectedText", 0x12000001, &QLineEdit::metaObj, 0, -1 },
	{ "QString","markedText", 0x3001001, &QLineEdit::metaObj, 0, -1 },
	{ "QString","selectedText", 0x3000001, &QLineEdit::metaObj, 0, -1 },
	{ "bool","dragEnabled", 0x12000103, &QLineEdit::metaObj, 0, -1 },
	{ "bool","readOnly", 0x12000103, &QLineEdit::metaObj, 0, -1 },
	{ "bool","undoAvailable", 0x12000001, &QLineEdit::metaObj, 0, -1 },
	{ "bool","redoAvailable", 0x12000001, &QLineEdit::metaObj, 0, -1 },
	{ "QString","inputMask", 0x3000103, &QLineEdit::metaObj, 0, -1 },
	{ "bool","acceptableInput", 0x12000001, &QLineEdit::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QLineEdit", parentObject,
	slot_tbl, 23,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	props_tbl, 19,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QLineEdit.setMetaObject( metaObj );
    return metaObj;
}

void* QLineEdit::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QLineEdit" ) )
	return this;
    return QFrame::qt_cast( clname );
}

// SIGNAL textChanged
void QLineEdit::textChanged( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL returnPressed
void QLineEdit::returnPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL lostFocus
void QLineEdit::lostFocus()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL selectionChanged
void QLineEdit::selectionChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

bool QLineEdit::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setText((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: selectAll(); break;
    case 2: deselect(); break;
    case 3: clearValidator(); break;
    case 4: insert((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: clear(); break;
    case 6: undo(); break;
    case 7: redo(); break;
    case 8: setMaxLength((int)static_QUType_int.get(_o+1)); break;
    case 9: setFrame((bool)static_QUType_bool.get(_o+1)); break;
    case 10: setEchoMode((EchoMode)static_QUType_enum.get(_o+1)); break;
    case 11: setReadOnly((bool)static_QUType_bool.get(_o+1)); break;
    case 12: setValidator((const QValidator*)static_QUType_ptr.get(_o+1)); break;
    case 13: setFont((const QFont&)*((const QFont*)static_QUType_ptr.get(_o+1))); break;
    case 14: setPalette((const QPalette&)*((const QPalette*)static_QUType_ptr.get(_o+1))); break;
    case 15: setSelection((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 16: setCursorPosition((int)static_QUType_int.get(_o+1)); break;
    case 17: setAlignment((int)static_QUType_int.get(_o+1)); break;
    case 18: cut(); break;
    case 19: copy(); break;
    case 20: paste(); break;
    case 21: setDragEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 22: clipboardChanged(); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QLineEdit::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: returnPressed(); break;
    case 2: lostFocus(); break;
    case 3: selectionChanged(); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QLineEdit::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setText(v->asString()); break;
	case 1: *v = QVariant( this->text() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setMaxLength(v->asInt()); break;
	case 1: *v = QVariant( this->maxLength() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setFrame(v->asBool()); break;
	case 1: *v = QVariant( this->frame(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setEchoMode((EchoMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->echoMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 1: *v = QVariant( this->displayText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setCursorPosition(v->asInt()); break;
	case 1: *v = QVariant( this->cursorPosition() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setAlignment(v->asInt()); break;
	case 1: *v = QVariant( (int)this->alignment() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setEdited(v->asBool()); break;
	case 1: *v = QVariant( this->edited(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 1: *v = QVariant( this->isModified(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 1: *v = QVariant( this->hasMarkedText(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 1: *v = QVariant( this->hasSelectedText(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 11: switch( f ) {
	case 1: *v = QVariant( this->markedText() ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 12: switch( f ) {
	case 1: *v = QVariant( this->selectedText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 13: switch( f ) {
	case 0: setDragEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->dragEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 14: switch( f ) {
	case 0: setReadOnly(v->asBool()); break;
	case 1: *v = QVariant( this->isReadOnly(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 15: switch( f ) {
	case 1: *v = QVariant( this->isUndoAvailable(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 16: switch( f ) {
	case 1: *v = QVariant( this->isRedoAvailable(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 17: switch( f ) {
	case 0: setInputMask(v->asString()); break;
	case 1: *v = QVariant( this->inputMask() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 18: switch( f ) {
	case 1: *v = QVariant( this->hasAcceptableInput(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QFrame::qt_property( id, f, v );
    }
    return TRUE;
}

bool QLineEdit::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QMotifStyle::className() const
{
    return "QMotifStyle";
}

QMetaObject *QMotifStyle::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMotifStyle( "QMotifStyle", &QMotifStyle::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMotifStyle::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMotifStyle", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMotifStyle::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMotifStyle", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMotifStyle::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QCommonStyle::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QMotifStyle", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMotifStyle.setMetaObject( metaObj );
    return metaObj;
}

void* QMotifStyle::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMotifStyle" ) )
	return this;
    return QCommonStyle::qt_cast( clname );
}

bool QMotifStyle::qt_invoke( int _id, QUObject* _o )
{
    return QCommonStyle::qt_invoke(_id,_o);
}

bool QMotifStyle::qt_emit( int _id, QUObject* _o )
{
    return QCommonStyle::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QMotifStyle::qt_property( int id, int f, QVariant* v)
{
    return QCommonStyle::qt_property( id, f, v);
}

bool QMotifStyle::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QAccel::className() const
{
    return "QAccel";
}

QMetaObject *QAccel::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAccel( "QAccel", &QAccel::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAccel::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAccel", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAccel::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAccel", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAccel::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"activated", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"activatedAmbiguously", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "activated(int)", &signal_0, QMetaData::Public },
	{ "activatedAmbiguously(int)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QAccel", parentObject,
	0, 0,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAccel.setMetaObject( metaObj );
    return metaObj;
}

void* QAccel::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAccel" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL activated
void QAccel::activated( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL activatedAmbiguously
void QAccel::activatedAmbiguously( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

bool QAccel::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QAccel::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: activated((int)static_QUType_int.get(_o+1)); break;
    case 1: activatedAmbiguously((int)static_QUType_int.get(_o+1)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QAccel::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QAccel::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QLabel::className() const
{
    return "QLabel";
}

QMetaObject *QLabel::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QLabel( "QLabel", &QLabel::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QLabel::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QLabel", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QLabel::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QLabel", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QLabel::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setText", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_varptr, "\x06", QUParameter::In }
    };
    static const QUMethod slot_1 = {"setPixmap", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "QPicture", QUParameter::In }
    };
    static const QUMethod slot_2 = {"setPicture", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "QMovie", QUParameter::In }
    };
    static const QUMethod slot_3 = {"setMovie", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setNum", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_double, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setNum", 1, param_slot_5 };
    static const QUMethod slot_6 = {"clear", 0, 0 };
    static const QUMethod slot_7 = {"acceleratorSlot", 0, 0 };
    static const QUMethod slot_8 = {"buddyDied", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_varptr, "\x08", QUParameter::In }
    };
    static const QUMethod slot_9 = {"movieUpdated", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_varptr, "\x09", QUParameter::In }
    };
    static const QUMethod slot_10 = {"movieResized", 1, param_slot_10 };
    static const QMetaData slot_tbl[] = {
	{ "setText(const QString&)", &slot_0, QMetaData::Public },
	{ "setPixmap(const QPixmap&)", &slot_1, QMetaData::Public },
	{ "setPicture(const QPicture&)", &slot_2, QMetaData::Public },
	{ "setMovie(const QMovie&)", &slot_3, QMetaData::Public },
	{ "setNum(int)", &slot_4, QMetaData::Public },
	{ "setNum(double)", &slot_5, QMetaData::Public },
	{ "clear()", &slot_6, QMetaData::Public },
	{ "acceleratorSlot()", &slot_7, QMetaData::Private },
	{ "buddyDied()", &slot_8, QMetaData::Private },
	{ "movieUpdated(const QRect&)", &slot_9, QMetaData::Private },
	{ "movieResized(const QSize&)", &slot_10, QMetaData::Private }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[7] = {
 	{ "QString","text", 0x3000103, &QLabel::metaObj, 0, -1 },
	{ "TextFormat","textFormat", 0x010f, &QLabel::metaObj, 0, -1 },
	{ "QPixmap","pixmap", 0x6000103, &QLabel::metaObj, 0, -1 },
	{ "bool","scaledContents", 0x12000103, &QLabel::metaObj, 0, -1 },
	{ "Alignment","alignment", 0x010f, &QLabel::metaObj, 0, -1 },
	{ "int","indent", 0x10000103, &QLabel::metaObj, 0, -1 },
	{ "BackgroundMode","backgroundMode", 0x2820c, &QLabel::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QLabel", parentObject,
	slot_tbl, 11,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 7,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QLabel.setMetaObject( metaObj );
    return metaObj;
}

void* QLabel::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QLabel" ) )
	return this;
    return QFrame::qt_cast( clname );
}

bool QLabel::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setText((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: setPixmap((const QPixmap&)*((const QPixmap*)static_QUType_ptr.get(_o+1))); break;
    case 2: setPicture((const QPicture&)*((const QPicture*)static_QUType_ptr.get(_o+1))); break;
    case 3: setMovie((const QMovie&)*((const QMovie*)static_QUType_ptr.get(_o+1))); break;
    case 4: setNum((int)static_QUType_int.get(_o+1)); break;
    case 5: setNum((double)static_QUType_double.get(_o+1)); break;
    case 6: clear(); break;
    case 7: acceleratorSlot(); break;
    case 8: buddyDied(); break;
    case 9: movieUpdated((const QRect&)*((const QRect*)static_QUType_ptr.get(_o+1))); break;
    case 10: movieResized((const QSize&)*((const QSize*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QLabel::qt_emit( int _id, QUObject* _o )
{
    return QFrame::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QLabel::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setText(v->asString()); break;
	case 1: *v = QVariant( this->text() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setTextFormat((TextFormat&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->textFormat() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setPixmap(v->asPixmap()); break;
	case 1: if ( this->pixmap() ) *v = QVariant( *pixmap() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setScaledContents(v->asBool()); break;
	case 1: *v = QVariant( this->hasScaledContents(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setAlignment(v->asInt()); break;
	case 1: *v = QVariant( (int)this->alignment() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setIndent(v->asInt()); break;
	case 1: *v = QVariant( this->indent() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: case 1: case 4: case 5: goto resolve;
	case 3: break;
	default: return FALSE;
    } break;
    default:
	return QFrame::qt_property( id, f, v );
    }
    return TRUE;
resolve:
    return QFrame::qt_property( staticMetaObject()->resolveProperty(id), f, v );
}

bool QLabel::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QLayout::className() const
{
    return "QLayout";
}

QMetaObject *QLayout::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QLayout( "QLayout", &QLayout::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QLayout::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QLayout", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QLayout::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QLayout", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QLayout::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "FreeResize",  (int) QLayout::FreeResize },
	{ "Minimum",  (int) QLayout::Minimum },
	{ "Fixed",  (int) QLayout::Fixed },
	{ "Auto",  (int) QLayout::Auto }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "ResizeMode", 4, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[3] = {
 	{ "int","margin", 0x10000103, &QLayout::metaObj, 0, -1 },
	{ "int","spacing", 0x10000103, &QLayout::metaObj, 0, -1 },
	{ "ResizeMode","resizeMode", 0x0107, &QLayout::metaObj, &enum_tbl[0], -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QLayout", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 3,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QLayout.setMetaObject( metaObj );
    return metaObj;
}

void* QLayout::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QLayout" ) )
	return this;
    if ( !qstrcmp( clname, "QLayoutItem" ) )
	return (QLayoutItem*)this;
    return QObject::qt_cast( clname );
}

bool QLayout::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QLayout::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QLayout::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setMargin(v->asInt()); break;
	case 1: *v = QVariant( this->margin() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setSpacing(v->asInt()); break;
	case 1: *v = QVariant( this->spacing() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setResizeMode((ResizeMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->resizeMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QObject::qt_property( id, f, v );
    }
    return TRUE;
}

bool QLayout::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QGridLayout::className() const
{
    return "QGridLayout";
}

QMetaObject *QGridLayout::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QGridLayout( "QGridLayout", &QGridLayout::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QGridLayout::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGridLayout", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QGridLayout::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGridLayout", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QGridLayout::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QLayout::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QGridLayout", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QGridLayout.setMetaObject( metaObj );
    return metaObj;
}

void* QGridLayout::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QGridLayout" ) )
	return this;
    return QLayout::qt_cast( clname );
}

bool QGridLayout::qt_invoke( int _id, QUObject* _o )
{
    return QLayout::qt_invoke(_id,_o);
}

bool QGridLayout::qt_emit( int _id, QUObject* _o )
{
    return QLayout::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QGridLayout::qt_property( int id, int f, QVariant* v)
{
    return QLayout::qt_property( id, f, v);
}

bool QGridLayout::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QBoxLayout::className() const
{
    return "QBoxLayout";
}

QMetaObject *QBoxLayout::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QBoxLayout( "QBoxLayout", &QBoxLayout::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QBoxLayout::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QBoxLayout", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QBoxLayout::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QBoxLayout", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QBoxLayout::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QLayout::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QBoxLayout", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QBoxLayout.setMetaObject( metaObj );
    return metaObj;
}

void* QBoxLayout::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QBoxLayout" ) )
	return this;
    return QLayout::qt_cast( clname );
}

bool QBoxLayout::qt_invoke( int _id, QUObject* _o )
{
    return QLayout::qt_invoke(_id,_o);
}

bool QBoxLayout::qt_emit( int _id, QUObject* _o )
{
    return QLayout::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QBoxLayout::qt_property( int id, int f, QVariant* v)
{
    return QLayout::qt_property( id, f, v);
}

bool QBoxLayout::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QHBoxLayout::className() const
{
    return "QHBoxLayout";
}

QMetaObject *QHBoxLayout::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QHBoxLayout( "QHBoxLayout", &QHBoxLayout::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QHBoxLayout::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHBoxLayout", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QHBoxLayout::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHBoxLayout", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QHBoxLayout::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QBoxLayout::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QHBoxLayout", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QHBoxLayout.setMetaObject( metaObj );
    return metaObj;
}

void* QHBoxLayout::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QHBoxLayout" ) )
	return this;
    return QBoxLayout::qt_cast( clname );
}

bool QHBoxLayout::qt_invoke( int _id, QUObject* _o )
{
    return QBoxLayout::qt_invoke(_id,_o);
}

bool QHBoxLayout::qt_emit( int _id, QUObject* _o )
{
    return QBoxLayout::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QHBoxLayout::qt_property( int id, int f, QVariant* v)
{
    return QBoxLayout::qt_property( id, f, v);
}

bool QHBoxLayout::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QVBoxLayout::className() const
{
    return "QVBoxLayout";
}

QMetaObject *QVBoxLayout::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QVBoxLayout( "QVBoxLayout", &QVBoxLayout::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QVBoxLayout::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVBoxLayout", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QVBoxLayout::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVBoxLayout", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QVBoxLayout::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QBoxLayout::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QVBoxLayout", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QVBoxLayout.setMetaObject( metaObj );
    return metaObj;
}

void* QVBoxLayout::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QVBoxLayout" ) )
	return this;
    return QBoxLayout::qt_cast( clname );
}

bool QVBoxLayout::qt_invoke( int _id, QUObject* _o )
{
    return QBoxLayout::qt_invoke(_id,_o);
}

bool QVBoxLayout::qt_emit( int _id, QUObject* _o )
{
    return QBoxLayout::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QVBoxLayout::qt_property( int id, int f, QVariant* v)
{
    return QBoxLayout::qt_property( id, f, v);
}

bool QVBoxLayout::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QLCDNumber::className() const
{
    return "QLCDNumber";
}

QMetaObject *QLCDNumber::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QLCDNumber( "QLCDNumber", &QLCDNumber::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QLCDNumber::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QLCDNumber", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QLCDNumber::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QLCDNumber", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QLCDNumber::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "Hex",  (int) QLCDNumber::Hex },
	{ "Dec",  (int) QLCDNumber::Dec },
	{ "Oct",  (int) QLCDNumber::Oct },
	{ "Bin",  (int) QLCDNumber::Bin },
	{ "HEX",  (int) QLCDNumber::HEX },
	{ "DEC",  (int) QLCDNumber::DEC },
	{ "OCT",  (int) QLCDNumber::OCT },
	{ "BIN",  (int) QLCDNumber::BIN }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "Outline",  (int) QLCDNumber::Outline },
	{ "Filled",  (int) QLCDNumber::Filled },
	{ "Flat",  (int) QLCDNumber::Flat }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "Mode", 8, enum_0, FALSE },
	{ "SegmentStyle", 3, enum_1, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"display", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "num", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"display", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "num", &static_QUType_double, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"display", 1, param_slot_2 };
    static const QUMethod slot_3 = {"setHexMode", 0, 0 };
    static const QUMethod slot_4 = {"setDecMode", 0, 0 };
    static const QUMethod slot_5 = {"setOctMode", 0, 0 };
    static const QUMethod slot_6 = {"setBinMode", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"setSmallDecimalPoint", 1, param_slot_7 };
    static const QMetaData slot_tbl[] = {
	{ "display(const QString&)", &slot_0, QMetaData::Public },
	{ "display(int)", &slot_1, QMetaData::Public },
	{ "display(double)", &slot_2, QMetaData::Public },
	{ "setHexMode()", &slot_3, QMetaData::Public },
	{ "setDecMode()", &slot_4, QMetaData::Public },
	{ "setOctMode()", &slot_5, QMetaData::Public },
	{ "setBinMode()", &slot_6, QMetaData::Public },
	{ "setSmallDecimalPoint(bool)", &slot_7, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"overflow", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "overflow()", &signal_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[6] = {
 	{ "bool","smallDecimalPoint", 0x12000103, &QLCDNumber::metaObj, 0, -1 },
	{ "int","numDigits", 0x10000103, &QLCDNumber::metaObj, 0, -1 },
	{ "Mode","mode", 0x0107, &QLCDNumber::metaObj, &enum_tbl[0], -1 },
	{ "SegmentStyle","segmentStyle", 0x0107, &QLCDNumber::metaObj, &enum_tbl[1], -1 },
	{ "double","value", 0x13000003, &QLCDNumber::metaObj, 0, -1 },
	{ "int","intValue", 0x10000003, &QLCDNumber::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QLCDNumber", parentObject,
	slot_tbl, 8,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	props_tbl, 6,
	enum_tbl, 2,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QLCDNumber.setMetaObject( metaObj );
    return metaObj;
}

void* QLCDNumber::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QLCDNumber" ) )
	return this;
    return QFrame::qt_cast( clname );
}

// SIGNAL overflow
void QLCDNumber::overflow()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool QLCDNumber::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: display((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: display((int)static_QUType_int.get(_o+1)); break;
    case 2: display((double)static_QUType_double.get(_o+1)); break;
    case 3: setHexMode(); break;
    case 4: setDecMode(); break;
    case 5: setOctMode(); break;
    case 6: setBinMode(); break;
    case 7: setSmallDecimalPoint((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QLCDNumber::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: overflow(); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QLCDNumber::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setSmallDecimalPoint(v->asBool()); break;
	case 1: *v = QVariant( this->smallDecimalPoint(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setNumDigits(v->asInt()); break;
	case 1: *v = QVariant( this->numDigits() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setMode((Mode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->mode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setSegmentStyle((SegmentStyle&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->segmentStyle() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: display(v->asDouble()); break;
	case 1: *v = QVariant( this->value() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: display(v->asInt()); break;
	case 1: *v = QVariant( this->intValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QFrame::qt_property( id, f, v );
    }
    return TRUE;
}

bool QLCDNumber::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QInputDialog::className() const
{
    return "QInputDialog";
}

QMetaObject *QInputDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QInputDialog( "QInputDialog", &QInputDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QInputDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QInputDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QInputDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QInputDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QInputDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "s", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"textChanged", 1, param_slot_0 };
    static const QUMethod slot_1 = {"tryAccept", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "textChanged(const QString&)", &slot_0, QMetaData::Private },
	{ "tryAccept()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QInputDialog", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QInputDialog.setMetaObject( metaObj );
    return metaObj;
}

void* QInputDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QInputDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool QInputDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: textChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: tryAccept(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QInputDialog::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QInputDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool QInputDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QScrollBar::className() const
{
    return "QScrollBar";
}

QMetaObject *QScrollBar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QScrollBar( "QScrollBar", &QScrollBar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QScrollBar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QScrollBar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QScrollBar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QScrollBar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QScrollBar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setValue", 1, param_slot_0 };
    static const QUMethod slot_1 = {"doAutoRepeat", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setValue(int)", &slot_0, QMetaData::Public },
	{ "doAutoRepeat()", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"valueChanged", 1, param_signal_0 };
    static const QUMethod signal_1 = {"sliderPressed", 0, 0 };
    static const QUParameter param_signal_2[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"sliderMoved", 1, param_signal_2 };
    static const QUMethod signal_3 = {"sliderReleased", 0, 0 };
    static const QUMethod signal_4 = {"nextLine", 0, 0 };
    static const QUMethod signal_5 = {"prevLine", 0, 0 };
    static const QUMethod signal_6 = {"nextPage", 0, 0 };
    static const QUMethod signal_7 = {"prevPage", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "valueChanged(int)", &signal_0, QMetaData::Public },
	{ "sliderPressed()", &signal_1, QMetaData::Public },
	{ "sliderMoved(int)", &signal_2, QMetaData::Public },
	{ "sliderReleased()", &signal_3, QMetaData::Public },
	{ "nextLine()", &signal_4, QMetaData::Public },
	{ "prevLine()", &signal_5, QMetaData::Public },
	{ "nextPage()", &signal_6, QMetaData::Public },
	{ "prevPage()", &signal_7, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[8] = {
 	{ "int","minValue", 0x10000103, &QScrollBar::metaObj, 0, -1 },
	{ "int","maxValue", 0x10000103, &QScrollBar::metaObj, 0, -1 },
	{ "int","lineStep", 0x10000103, &QScrollBar::metaObj, 0, -1 },
	{ "int","pageStep", 0x10000103, &QScrollBar::metaObj, 0, -1 },
	{ "int","value", 0x10000103, &QScrollBar::metaObj, 0, -1 },
	{ "bool","tracking", 0x12000103, &QScrollBar::metaObj, 0, -1 },
	{ "bool","draggingSlider", 0x12000001, &QScrollBar::metaObj, 0, -1 },
	{ "Orientation","orientation", 0x010f, &QScrollBar::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QScrollBar", parentObject,
	slot_tbl, 2,
	signal_tbl, 8,
#ifndef QT_NO_PROPERTIES
	props_tbl, 8,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QScrollBar.setMetaObject( metaObj );
    return metaObj;
}

void* QScrollBar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QScrollBar" ) )
	return this;
    if ( !qstrcmp( clname, "QRangeControl" ) )
	return (QRangeControl*)this;
    return QWidget::qt_cast( clname );
}

// SIGNAL valueChanged
void QScrollBar::valueChanged( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL sliderPressed
void QScrollBar::sliderPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL sliderMoved
void QScrollBar::sliderMoved( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL sliderReleased
void QScrollBar::sliderReleased()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL nextLine
void QScrollBar::nextLine()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL prevLine
void QScrollBar::prevLine()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

// SIGNAL nextPage
void QScrollBar::nextPage()
{
    activate_signal( staticMetaObject()->signalOffset() + 6 );
}

// SIGNAL prevPage
void QScrollBar::prevPage()
{
    activate_signal( staticMetaObject()->signalOffset() + 7 );
}

bool QScrollBar::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setValue((int)static_QUType_int.get(_o+1)); break;
    case 1: doAutoRepeat(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QScrollBar::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 1: sliderPressed(); break;
    case 2: sliderMoved((int)static_QUType_int.get(_o+1)); break;
    case 3: sliderReleased(); break;
    case 4: nextLine(); break;
    case 5: prevLine(); break;
    case 6: nextPage(); break;
    case 7: prevPage(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QScrollBar::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setMinValue(v->asInt()); break;
	case 1: *v = QVariant( this->minValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setMaxValue(v->asInt()); break;
	case 1: *v = QVariant( this->maxValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setLineStep(v->asInt()); break;
	case 1: *v = QVariant( this->lineStep() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setPageStep(v->asInt()); break;
	case 1: *v = QVariant( this->pageStep() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setValue(v->asInt()); break;
	case 1: *v = QVariant( this->value() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setTracking(v->asBool()); break;
	case 1: *v = QVariant( this->tracking(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 1: *v = QVariant( this->draggingSlider(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setOrientation((Orientation&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->orientation() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QScrollBar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QScrollView::className() const
{
    return "QScrollView";
}

QMetaObject *QScrollView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QScrollView( "QScrollView", &QScrollView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QScrollView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QScrollView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QScrollView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QScrollView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QScrollView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "Default",  (int) QScrollView::Default },
	{ "Manual",  (int) QScrollView::Manual },
	{ "AutoOne",  (int) QScrollView::AutoOne },
	{ "AutoOneFit",  (int) QScrollView::AutoOneFit }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "Auto",  (int) QScrollView::Auto },
	{ "AlwaysOff",  (int) QScrollView::AlwaysOff },
	{ "AlwaysOn",  (int) QScrollView::AlwaysOn }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "ResizePolicy", 4, enum_0, FALSE },
	{ "ScrollBarMode", 3, enum_1, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "w", &static_QUType_int, 0, QUParameter::In },
	{ "h", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"resizeContents", 2, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "dx", &static_QUType_int, 0, QUParameter::In },
	{ "dy", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"scrollBy", 2, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setContentsPos", 2, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"ensureVisible", 2, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In },
	{ "xmargin", &static_QUType_int, 0, QUParameter::In },
	{ "ymargin", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"ensureVisible", 4, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"center", 2, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In },
	{ "xmargin", &static_QUType_ptr, "float", QUParameter::In },
	{ "ymargin", &static_QUType_ptr, "float", QUParameter::In }
    };
    static const QUMethod slot_6 = {"center", 4, param_slot_6 };
    static const QUMethod slot_7 = {"updateScrollBars", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ "enable", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"setEnabled", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"hslide", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"vslide", 1, param_slot_10 };
    static const QUMethod slot_11 = {"hbarIsPressed", 0, 0 };
    static const QUMethod slot_12 = {"hbarIsReleased", 0, 0 };
    static const QUMethod slot_13 = {"vbarIsPressed", 0, 0 };
    static const QUMethod slot_14 = {"vbarIsReleased", 0, 0 };
    static const QUMethod slot_15 = {"doDragAutoScroll", 0, 0 };
    static const QUMethod slot_16 = {"startDragAutoScroll", 0, 0 };
    static const QUMethod slot_17 = {"stopDragAutoScroll", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "resizeContents(int,int)", &slot_0, QMetaData::Public },
	{ "scrollBy(int,int)", &slot_1, QMetaData::Public },
	{ "setContentsPos(int,int)", &slot_2, QMetaData::Public },
	{ "ensureVisible(int,int)", &slot_3, QMetaData::Public },
	{ "ensureVisible(int,int,int,int)", &slot_4, QMetaData::Public },
	{ "center(int,int)", &slot_5, QMetaData::Public },
	{ "center(int,int,float,float)", &slot_6, QMetaData::Public },
	{ "updateScrollBars()", &slot_7, QMetaData::Public },
	{ "setEnabled(bool)", &slot_8, QMetaData::Public },
	{ "hslide(int)", &slot_9, QMetaData::Private },
	{ "vslide(int)", &slot_10, QMetaData::Private },
	{ "hbarIsPressed()", &slot_11, QMetaData::Private },
	{ "hbarIsReleased()", &slot_12, QMetaData::Private },
	{ "vbarIsPressed()", &slot_13, QMetaData::Private },
	{ "vbarIsReleased()", &slot_14, QMetaData::Private },
	{ "doDragAutoScroll()", &slot_15, QMetaData::Private },
	{ "startDragAutoScroll()", &slot_16, QMetaData::Private },
	{ "stopDragAutoScroll()", &slot_17, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"contentsMoving", 2, param_signal_0 };
    static const QUMethod signal_1 = {"horizontalSliderPressed", 0, 0 };
    static const QUMethod signal_2 = {"horizontalSliderReleased", 0, 0 };
    static const QUMethod signal_3 = {"verticalSliderPressed", 0, 0 };
    static const QUMethod signal_4 = {"verticalSliderReleased", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "contentsMoving(int,int)", &signal_0, QMetaData::Public },
	{ "horizontalSliderPressed()", &signal_1, QMetaData::Public },
	{ "horizontalSliderReleased()", &signal_2, QMetaData::Public },
	{ "verticalSliderPressed()", &signal_3, QMetaData::Public },
	{ "verticalSliderReleased()", &signal_4, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[10] = {
 	{ "ResizePolicy","resizePolicy", 0x0107, &QScrollView::metaObj, &enum_tbl[0], -1 },
	{ "ScrollBarMode","vScrollBarMode", 0x0107, &QScrollView::metaObj, &enum_tbl[1], -1 },
	{ "ScrollBarMode","hScrollBarMode", 0x0107, &QScrollView::metaObj, &enum_tbl[1], -1 },
	{ "int","visibleWidth", 0x10000001, &QScrollView::metaObj, 0, -1 },
	{ "int","visibleHeight", 0x10000001, &QScrollView::metaObj, 0, -1 },
	{ "int","contentsWidth", 0x10000001, &QScrollView::metaObj, 0, -1 },
	{ "int","contentsHeight", 0x10000001, &QScrollView::metaObj, 0, -1 },
	{ "int","contentsX", 0x10000001, &QScrollView::metaObj, 0, -1 },
	{ "int","contentsY", 0x10000001, &QScrollView::metaObj, 0, -1 },
	{ "bool","dragAutoScroll", 0x12000103, &QScrollView::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QScrollView", parentObject,
	slot_tbl, 18,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	props_tbl, 10,
	enum_tbl, 2,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QScrollView.setMetaObject( metaObj );
    return metaObj;
}

void* QScrollView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QScrollView" ) )
	return this;
    return QFrame::qt_cast( clname );
}

// SIGNAL contentsMoving
void QScrollView::contentsMoving( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL horizontalSliderPressed
void QScrollView::horizontalSliderPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL horizontalSliderReleased
void QScrollView::horizontalSliderReleased()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL verticalSliderPressed
void QScrollView::verticalSliderPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL verticalSliderReleased
void QScrollView::verticalSliderReleased()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

bool QScrollView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: resizeContents((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 1: scrollBy((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 2: setContentsPos((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 3: ensureVisible((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 4: ensureVisible((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4)); break;
    case 5: center((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 6: center((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(float)(*((float*)static_QUType_ptr.get(_o+3))),(float)(*((float*)static_QUType_ptr.get(_o+4)))); break;
    case 7: updateScrollBars(); break;
    case 8: setEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 9: hslide((int)static_QUType_int.get(_o+1)); break;
    case 10: vslide((int)static_QUType_int.get(_o+1)); break;
    case 11: hbarIsPressed(); break;
    case 12: hbarIsReleased(); break;
    case 13: vbarIsPressed(); break;
    case 14: vbarIsReleased(); break;
    case 15: doDragAutoScroll(); break;
    case 16: startDragAutoScroll(); break;
    case 17: stopDragAutoScroll(); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QScrollView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: contentsMoving((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 1: horizontalSliderPressed(); break;
    case 2: horizontalSliderReleased(); break;
    case 3: verticalSliderPressed(); break;
    case 4: verticalSliderReleased(); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QScrollView::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setResizePolicy((ResizePolicy&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->resizePolicy() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setVScrollBarMode((ScrollBarMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->vScrollBarMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setHScrollBarMode((ScrollBarMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->hScrollBarMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 1: *v = QVariant( this->visibleWidth() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 1: *v = QVariant( this->visibleHeight() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 1: *v = QVariant( this->contentsWidth() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 1: *v = QVariant( this->contentsHeight() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 1: *v = QVariant( this->contentsX() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 1: *v = QVariant( this->contentsY() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setDragAutoScroll(v->asBool()); break;
	case 1: *v = QVariant( this->dragAutoScroll(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QFrame::qt_property( id, f, v );
    }
    return TRUE;
}

bool QScrollView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWindowsStyle::className() const
{
    return "QWindowsStyle";
}

QMetaObject *QWindowsStyle::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWindowsStyle( "QWindowsStyle", &QWindowsStyle::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWindowsStyle::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWindowsStyle", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWindowsStyle::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWindowsStyle", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWindowsStyle::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QCommonStyle::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QWindowsStyle", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWindowsStyle.setMetaObject( metaObj );
    return metaObj;
}

void* QWindowsStyle::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWindowsStyle" ) )
	return this;
    return QCommonStyle::qt_cast( clname );
}

bool QWindowsStyle::qt_invoke( int _id, QUObject* _o )
{
    return QCommonStyle::qt_invoke(_id,_o);
}

bool QWindowsStyle::qt_emit( int _id, QUObject* _o )
{
    return QCommonStyle::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QWindowsStyle::qt_property( int id, int f, QVariant* v)
{
    return QCommonStyle::qt_property( id, f, v);
}

bool QWindowsStyle::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSignal::className() const
{
    return "QSignal";
}

QMetaObject *QSignal::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSignal( "QSignal", &QSignal::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSignal::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSignal", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSignal::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSignal", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSignal::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QVariant, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"signal", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"intSignal", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "signal(const QVariant&)", &signal_0, QMetaData::Public },
	{ "intSignal(int)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSignal", parentObject,
	0, 0,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSignal.setMetaObject( metaObj );
    return metaObj;
}

void* QSignal::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSignal" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL signal
void QSignal::signal( const QVariant& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_QVariant.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL intSignal
void QSignal::intSignal( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

bool QSignal::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QSignal::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: signal((const QVariant&)static_QUType_QVariant.get(_o+1)); break;
    case 1: intSignal((int)static_QUType_int.get(_o+1)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QSignal::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QSignal::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QMessageBox::className() const
{
    return "QMessageBox";
}

QMetaObject *QMessageBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMessageBox( "QMessageBox", &QMessageBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMessageBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMessageBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMessageBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMessageBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMessageBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "NoIcon",  (int) QMessageBox::NoIcon },
	{ "Information",  (int) QMessageBox::Information },
	{ "Warning",  (int) QMessageBox::Warning },
	{ "Critical",  (int) QMessageBox::Critical },
	{ "Question",  (int) QMessageBox::Question }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "Icon", 5, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUMethod slot_0 = {"buttonClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "buttonClicked()", &slot_0, QMetaData::Private }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[4] = {
 	{ "QString","text", 0x3000103, &QMessageBox::metaObj, 0, -1 },
	{ "Icon","icon", 0x0107, &QMessageBox::metaObj, &enum_tbl[0], -1 },
	{ "QPixmap","iconPixmap", 0x6000103, &QMessageBox::metaObj, 0, -1 },
	{ "TextFormat","textFormat", 0x010f, &QMessageBox::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QMessageBox", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 4,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMessageBox.setMetaObject( metaObj );
    return metaObj;
}

void* QMessageBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMessageBox" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool QMessageBox::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: buttonClicked(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QMessageBox::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QMessageBox::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setText(v->asString()); break;
	case 1: *v = QVariant( this->text() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setIcon((Icon&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->icon() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setIconPixmap(v->asPixmap()); break;
	case 1: if ( this->iconPixmap() ) *v = QVariant( *iconPixmap() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setTextFormat((TextFormat&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->textFormat() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QDialog::qt_property( id, f, v );
    }
    return TRUE;
}

bool QMessageBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QHeader::className() const
{
    return "QHeader";
}

QMetaObject *QHeader::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QHeader( "QHeader", &QHeader::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QHeader::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHeader", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QHeader::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QHeader", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QHeader::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "enable", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setUpdatesEnabled", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "pos", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setOffset", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "setUpdatesEnabled(bool)", &slot_0, QMetaData::Public },
	{ "setOffset(int)", &slot_1, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "section", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"clicked", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "section", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"pressed", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "section", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"released", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ "section", &static_QUType_int, 0, QUParameter::In },
	{ "oldSize", &static_QUType_int, 0, QUParameter::In },
	{ "newSize", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"sizeChange", 3, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ "section", &static_QUType_int, 0, QUParameter::In },
	{ "fromIndex", &static_QUType_int, 0, QUParameter::In },
	{ "toIndex", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"indexChange", 3, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_5 = {"sectionClicked", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_6 = {"moved", 2, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ "section", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_7 = {"sectionHandleDoubleClicked", 1, param_signal_7 };
    static const QMetaData signal_tbl[] = {
	{ "clicked(int)", &signal_0, QMetaData::Public },
	{ "pressed(int)", &signal_1, QMetaData::Public },
	{ "released(int)", &signal_2, QMetaData::Public },
	{ "sizeChange(int,int,int)", &signal_3, QMetaData::Public },
	{ "indexChange(int,int,int)", &signal_4, QMetaData::Public },
	{ "sectionClicked(int)", &signal_5, QMetaData::Public },
	{ "moved(int,int)", &signal_6, QMetaData::Public },
	{ "sectionHandleDoubleClicked(int)", &signal_7, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[6] = {
 	{ "Orientation","orientation", 0x010f, &QHeader::metaObj, 0, -1 },
	{ "bool","tracking", 0x12000103, &QHeader::metaObj, 0, -1 },
	{ "int","count", 0x10000001, &QHeader::metaObj, 0, -1 },
	{ "int","offset", 0x10000103, &QHeader::metaObj, 0, -1 },
	{ "bool","moving", 0x12000003, &QHeader::metaObj, 0, -1 },
	{ "bool","stretching", 0x12000003, &QHeader::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QHeader", parentObject,
	slot_tbl, 2,
	signal_tbl, 8,
#ifndef QT_NO_PROPERTIES
	props_tbl, 6,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QHeader.setMetaObject( metaObj );
    return metaObj;
}

void* QHeader::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QHeader" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL clicked
void QHeader::clicked( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL pressed
void QHeader::pressed( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL released
void QHeader::released( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL sizeChange
void QHeader::sizeChange( int t0, int t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL indexChange
void QHeader::indexChange( int t0, int t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL sectionClicked
void QHeader::sectionClicked( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 5, t0 );
}

// SIGNAL moved
void QHeader::moved( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL sectionHandleDoubleClicked
void QHeader::sectionHandleDoubleClicked( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 7, t0 );
}

bool QHeader::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setUpdatesEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 1: setOffset((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QHeader::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: clicked((int)static_QUType_int.get(_o+1)); break;
    case 1: pressed((int)static_QUType_int.get(_o+1)); break;
    case 2: released((int)static_QUType_int.get(_o+1)); break;
    case 3: sizeChange((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 4: indexChange((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 5: sectionClicked((int)static_QUType_int.get(_o+1)); break;
    case 6: moved((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 7: sectionHandleDoubleClicked((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QHeader::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setOrientation((Orientation&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->orientation() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setTracking(v->asBool()); break;
	case 1: *v = QVariant( this->tracking(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 1: *v = QVariant( this->count() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setOffset(v->asInt()); break;
	case 1: *v = QVariant( this->offset() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setMovingEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isMovingEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setStretchEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isStretchEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QHeader::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QMotifPlusStyle::className() const
{
    return "QMotifPlusStyle";
}

QMetaObject *QMotifPlusStyle::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMotifPlusStyle( "QMotifPlusStyle", &QMotifPlusStyle::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMotifPlusStyle::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMotifPlusStyle", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMotifPlusStyle::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMotifPlusStyle", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMotifPlusStyle::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMotifStyle::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QMotifPlusStyle", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMotifPlusStyle.setMetaObject( metaObj );
    return metaObj;
}

void* QMotifPlusStyle::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMotifPlusStyle" ) )
	return this;
    return QMotifStyle::qt_cast( clname );
}

bool QMotifPlusStyle::qt_invoke( int _id, QUObject* _o )
{
    return QMotifStyle::qt_invoke(_id,_o);
}

bool QMotifPlusStyle::qt_emit( int _id, QUObject* _o )
{
    return QMotifStyle::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QMotifPlusStyle::qt_property( int id, int f, QVariant* v)
{
    return QMotifStyle::qt_property( id, f, v);
}

bool QMotifPlusStyle::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QCDEStyle::className() const
{
    return "QCDEStyle";
}

QMetaObject *QCDEStyle::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCDEStyle( "QCDEStyle", &QCDEStyle::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCDEStyle::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCDEStyle", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCDEStyle::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCDEStyle", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCDEStyle::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMotifStyle::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QCDEStyle", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCDEStyle.setMetaObject( metaObj );
    return metaObj;
}

void* QCDEStyle::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCDEStyle" ) )
	return this;
    return QMotifStyle::qt_cast( clname );
}

bool QCDEStyle::qt_invoke( int _id, QUObject* _o )
{
    return QMotifStyle::qt_invoke(_id,_o);
}

bool QCDEStyle::qt_emit( int _id, QUObject* _o )
{
    return QMotifStyle::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCDEStyle::qt_property( int id, int f, QVariant* v)
{
    return QMotifStyle::qt_property( id, f, v);
}

bool QCDEStyle::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QButton::className() const
{
    return "QButton";
}

QMetaObject *QButton::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QButton( "QButton", &QButton::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QButton::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QButton", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QButton::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QButton", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QButton::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "SingleShot",  (int) QButton::SingleShot },
	{ "Toggle",  (int) QButton::Toggle },
	{ "Tristate",  (int) QButton::Tristate }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "Off",  (int) QButton::Off },
	{ "NoChange",  (int) QButton::NoChange },
	{ "On",  (int) QButton::On }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "ToggleType", 3, enum_0, FALSE },
	{ "ToggleState", 3, enum_1, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUMethod slot_0 = {"animateClick", 0, 0 };
    static const QUMethod slot_1 = {"toggle", 0, 0 };
    static const QUMethod slot_2 = {"animateTimeout", 0, 0 };
    static const QUMethod slot_3 = {"autoRepeatTimeout", 0, 0 };
    static const QUMethod slot_4 = {"emulateClick", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "animateClick()", &slot_0, QMetaData::Public },
	{ "toggle()", &slot_1, QMetaData::Public },
	{ "animateTimeout()", &slot_2, QMetaData::Private },
	{ "autoRepeatTimeout()", &slot_3, QMetaData::Private },
	{ "emulateClick()", &slot_4, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"pressed", 0, 0 };
    static const QUMethod signal_1 = {"released", 0, 0 };
    static const QUMethod signal_2 = {"clicked", 0, 0 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"toggled", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"stateChanged", 1, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "pressed()", &signal_0, QMetaData::Public },
	{ "released()", &signal_1, QMetaData::Public },
	{ "clicked()", &signal_2, QMetaData::Public },
	{ "toggled(bool)", &signal_3, QMetaData::Public },
	{ "stateChanged(int)", &signal_4, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[11] = {
 	{ "QString","text", 0x3000103, &QButton::metaObj, 0, -1 },
	{ "QPixmap","pixmap", 0x6000103, &QButton::metaObj, 0, -1 },
	{ "QKeySequence","accel", 0x1f000103, &QButton::metaObj, 0, -1 },
	{ "bool","toggleButton", 0x12000001, &QButton::metaObj, 0, -1 },
	{ "ToggleType","toggleType", 0x0005, &QButton::metaObj, &enum_tbl[0], -1 },
	{ "bool","down", 0x12001103, &QButton::metaObj, 0, -1 },
	{ "bool","on", 0x12000001, &QButton::metaObj, 0, -1 },
	{ "ToggleState","toggleState", 0x0005, &QButton::metaObj, &enum_tbl[1], -1 },
	{ "bool","autoResize", 0x12001103, &QButton::metaObj, 0, -1 },
	{ "bool","autoRepeat", 0x12000103, &QButton::metaObj, 0, -1 },
	{ "bool","exclusiveToggle", 0x12000001, &QButton::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QButton", parentObject,
	slot_tbl, 5,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	props_tbl, 11,
	enum_tbl, 2,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QButton.setMetaObject( metaObj );
    return metaObj;
}

void* QButton::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QButton" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL pressed
void QButton::pressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL released
void QButton::released()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL clicked
void QButton::clicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL toggled
void QButton::toggled( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 3, t0 );
}

// SIGNAL stateChanged
void QButton::stateChanged( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 4, t0 );
}

bool QButton::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: animateClick(); break;
    case 1: toggle(); break;
    case 2: animateTimeout(); break;
    case 3: autoRepeatTimeout(); break;
    case 4: emulateClick(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QButton::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: pressed(); break;
    case 1: released(); break;
    case 2: clicked(); break;
    case 3: toggled((bool)static_QUType_bool.get(_o+1)); break;
    case 4: stateChanged((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QButton::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setText(v->asString()); break;
	case 1: *v = QVariant( this->text() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setPixmap(v->asPixmap()); break;
	case 1: if ( this->pixmap() ) *v = QVariant( *pixmap() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setAccel(v->asKeySequence()); break;
	case 1: *v = QVariant( this->accel() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 1: *v = QVariant( this->isToggleButton(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 1: *v = QVariant( (int)this->toggleType() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setDown(v->asBool()); break;
	case 1: *v = QVariant( this->isDown(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 1: *v = QVariant( this->isOn(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 1: *v = QVariant( (int)this->state() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setAutoResize(v->asBool()); break;
	case 1: *v = QVariant( this->autoResize(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setAutoRepeat(v->asBool()); break;
	case 1: *v = QVariant( this->autoRepeat(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 1: *v = QVariant( this->isExclusiveToggle(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QButton::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QFtp::className() const
{
    return "QFtp";
}

QMetaObject *QFtp::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFtp( "QFtp", &QFtp::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFtp::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFtp", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFtp::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFtp", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFtp::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QNetworkProtocol::staticMetaObject();
    static const QUMethod slot_0 = {"abort", 0, 0 };
    static const QUMethod slot_1 = {"startNextCommand", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"piFinished", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"piError", 2, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"piConnectState", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"piFtpReply", 2, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_ptr, "QUrlInfo", QUParameter::In }
    };
    static const QUMethod slot_6 = {"npListInfo", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"npDone", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"npStateChanged", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"npDataTransferProgress", 2, param_slot_9 };
    static const QUMethod slot_10 = {"npReadyRead", 0, 0 };
    static const QUMethod slot_11 = {"hostFound", 0, 0 };
    static const QUMethod slot_12 = {"connected", 0, 0 };
    static const QUMethod slot_13 = {"closed", 0, 0 };
    static const QUMethod slot_14 = {"dataHostFound", 0, 0 };
    static const QUMethod slot_15 = {"dataConnected", 0, 0 };
    static const QUMethod slot_16 = {"dataClosed", 0, 0 };
    static const QUMethod slot_17 = {"dataReadyRead", 0, 0 };
    static const QUParameter param_slot_18[] = {
	{ "nbytes", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"dataBytesWritten", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"error", 1, param_slot_19 };
    static const QMetaData slot_tbl[] = {
	{ "abort()", &slot_0, QMetaData::Public },
	{ "startNextCommand()", &slot_1, QMetaData::Private },
	{ "piFinished(const QString&)", &slot_2, QMetaData::Private },
	{ "piError(int,const QString&)", &slot_3, QMetaData::Private },
	{ "piConnectState(int)", &slot_4, QMetaData::Private },
	{ "piFtpReply(int,const QString&)", &slot_5, QMetaData::Private },
	{ "npListInfo(const QUrlInfo&)", &slot_6, QMetaData::Private },
	{ "npDone(bool)", &slot_7, QMetaData::Private },
	{ "npStateChanged(int)", &slot_8, QMetaData::Private },
	{ "npDataTransferProgress(int,int)", &slot_9, QMetaData::Private },
	{ "npReadyRead()", &slot_10, QMetaData::Private },
	{ "hostFound()", &slot_11, QMetaData::Protected },
	{ "connected()", &slot_12, QMetaData::Protected },
	{ "closed()", &slot_13, QMetaData::Protected },
	{ "dataHostFound()", &slot_14, QMetaData::Protected },
	{ "dataConnected()", &slot_15, QMetaData::Protected },
	{ "dataClosed()", &slot_16, QMetaData::Protected },
	{ "dataReadyRead()", &slot_17, QMetaData::Protected },
	{ "dataBytesWritten(int)", &slot_18, QMetaData::Protected },
	{ "error(int)", &slot_19, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"stateChanged", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "QUrlInfo", QUParameter::In }
    };
    static const QUMethod signal_1 = {"listInfo", 1, param_signal_1 };
    static const QUMethod signal_2 = {"readyRead", 0, 0 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"dataTransferProgress", 2, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"rawCommandReply", 2, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_5 = {"commandStarted", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_6 = {"commandFinished", 2, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_7 = {"done", 1, param_signal_7 };
    static const QMetaData signal_tbl[] = {
	{ "stateChanged(int)", &signal_0, QMetaData::Public },
	{ "listInfo(const QUrlInfo&)", &signal_1, QMetaData::Public },
	{ "readyRead()", &signal_2, QMetaData::Public },
	{ "dataTransferProgress(int,int)", &signal_3, QMetaData::Public },
	{ "rawCommandReply(int,const QString&)", &signal_4, QMetaData::Public },
	{ "commandStarted(int)", &signal_5, QMetaData::Public },
	{ "commandFinished(int,bool)", &signal_6, QMetaData::Public },
	{ "done(bool)", &signal_7, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QFtp", parentObject,
	slot_tbl, 20,
	signal_tbl, 8,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFtp.setMetaObject( metaObj );
    return metaObj;
}

void* QFtp::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFtp" ) )
	return this;
    return QNetworkProtocol::qt_cast( clname );
}

// SIGNAL stateChanged
void QFtp::stateChanged( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL listInfo
void QFtp::listInfo( const QUrlInfo& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL readyRead
void QFtp::readyRead()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL dataTransferProgress
void QFtp::dataTransferProgress( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL rawCommandReply
void QFtp::rawCommandReply( int t0, const QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL commandStarted
void QFtp::commandStarted( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 5, t0 );
}

// SIGNAL commandFinished
void QFtp::commandFinished( int t0, bool t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_bool.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL done
void QFtp::done( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 7, t0 );
}

bool QFtp::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: abort(); break;
    case 1: startNextCommand(); break;
    case 2: piFinished((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: piError((int)static_QUType_int.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 4: piConnectState((int)static_QUType_int.get(_o+1)); break;
    case 5: piFtpReply((int)static_QUType_int.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 6: npListInfo((const QUrlInfo&)*((const QUrlInfo*)static_QUType_ptr.get(_o+1))); break;
    case 7: npDone((bool)static_QUType_bool.get(_o+1)); break;
    case 8: npStateChanged((int)static_QUType_int.get(_o+1)); break;
    case 9: npDataTransferProgress((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 10: npReadyRead(); break;
    case 11: hostFound(); break;
    case 12: connected(); break;
    case 13: closed(); break;
    case 14: dataHostFound(); break;
    case 15: dataConnected(); break;
    case 16: dataClosed(); break;
    case 17: dataReadyRead(); break;
    case 18: dataBytesWritten((int)static_QUType_int.get(_o+1)); break;
    case 19: error((int)static_QUType_int.get(_o+1)); break;
    default:
	return QNetworkProtocol::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QFtp::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: stateChanged((int)static_QUType_int.get(_o+1)); break;
    case 1: listInfo((const QUrlInfo&)*((const QUrlInfo*)static_QUType_ptr.get(_o+1))); break;
    case 2: readyRead(); break;
    case 3: dataTransferProgress((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 4: rawCommandReply((int)static_QUType_int.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 5: commandStarted((int)static_QUType_int.get(_o+1)); break;
    case 6: commandFinished((int)static_QUType_int.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 7: done((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QNetworkProtocol::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QFtp::qt_property( int id, int f, QVariant* v)
{
    return QNetworkProtocol::qt_property( id, f, v);
}

bool QFtp::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QGuardedPtrPrivate::className() const
{
    return "QGuardedPtrPrivate";
}

QMetaObject *QGuardedPtrPrivate::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QGuardedPtrPrivate( "QGuardedPtrPrivate", &QGuardedPtrPrivate::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QGuardedPtrPrivate::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGuardedPtrPrivate", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QGuardedPtrPrivate::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGuardedPtrPrivate", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QGuardedPtrPrivate::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"objectDestroyed", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "objectDestroyed()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QGuardedPtrPrivate", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QGuardedPtrPrivate.setMetaObject( metaObj );
    return metaObj;
}

void* QGuardedPtrPrivate::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QGuardedPtrPrivate" ) )
	return this;
    if ( !qstrcmp( clname, "QShared" ) )
	return (QShared*)this;
    return QObject::qt_cast( clname );
}

bool QGuardedPtrPrivate::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: objectDestroyed(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QGuardedPtrPrivate::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QGuardedPtrPrivate::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QGuardedPtrPrivate::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QObjectCleanupHandler::className() const
{
    return "QObjectCleanupHandler";
}

QMetaObject *QObjectCleanupHandler::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QObjectCleanupHandler( "QObjectCleanupHandler", &QObjectCleanupHandler::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QObjectCleanupHandler::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QObjectCleanupHandler", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QObjectCleanupHandler::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QObjectCleanupHandler", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QObjectCleanupHandler::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_0 = {"objectDestroyed", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "objectDestroyed(QObject*)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QObjectCleanupHandler", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QObjectCleanupHandler.setMetaObject( metaObj );
    return metaObj;
}

void* QObjectCleanupHandler::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QObjectCleanupHandler" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QObjectCleanupHandler::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: objectDestroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QObjectCleanupHandler::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QObjectCleanupHandler::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QObjectCleanupHandler::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QColorDialog::className() const
{
    return "QColorDialog";
}

QMetaObject *QColorDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QColorDialog( "QColorDialog", &QColorDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QColorDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QColorDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QColorDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QColorDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QColorDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QColorDialog", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QColorDialog.setMetaObject( metaObj );
    return metaObj;
}

void* QColorDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QColorDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool QColorDialog::qt_invoke( int _id, QUObject* _o )
{
    return QDialog::qt_invoke(_id,_o);
}

bool QColorDialog::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QColorDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool QColorDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QListView::className() const
{
    return "QListView";
}

QMetaObject *QListView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QListView( "QListView", &QListView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QListView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QListView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QListView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QListView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QListView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QScrollView::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "Single",  (int) QListView::Single },
	{ "Multi",  (int) QListView::Multi },
	{ "Extended",  (int) QListView::Extended },
	{ "NoSelection",  (int) QListView::NoSelection }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "NoColumn",  (int) QListView::NoColumn },
	{ "AllColumns",  (int) QListView::AllColumns },
	{ "LastColumn",  (int) QListView::LastColumn }
    };
    static const QMetaEnum::Item enum_2[] = {
	{ "Accept",  (int) QListView::Accept },
	{ "Reject",  (int) QListView::Reject }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "SelectionMode", 4, enum_0, FALSE },
	{ "ResizeMode", 3, enum_1, FALSE },
	{ "RenameAction", 2, enum_2, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUMethod slot_0 = {"clear", 0, 0 };
    static const QUMethod slot_1 = {"invertSelection", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "select", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"selectAll", 1, param_slot_2 };
    static const QUMethod slot_3 = {"triggerUpdate", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setContentsPos", 2, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"adjustColumn", 1, param_slot_5 };
    static const QUMethod slot_6 = {"updateContents", 0, 0 };
    static const QUMethod slot_7 = {"doAutoScroll", 0, 0 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"changeSortColumn", 1, param_slot_8 };
    static const QUMethod slot_9 = {"handleIndexChange", 0, 0 };
    static const QUMethod slot_10 = {"updateDirtyItems", 0, 0 };
    static const QUMethod slot_11 = {"makeVisible", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"handleSizeChange", 3, param_slot_12 };
    static const QUMethod slot_13 = {"startRename", 0, 0 };
    static const QUMethod slot_14 = {"openFocusItem", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "clear()", &slot_0, QMetaData::Public },
	{ "invertSelection()", &slot_1, QMetaData::Public },
	{ "selectAll(bool)", &slot_2, QMetaData::Public },
	{ "triggerUpdate()", &slot_3, QMetaData::Public },
	{ "setContentsPos(int,int)", &slot_4, QMetaData::Public },
	{ "adjustColumn(int)", &slot_5, QMetaData::Public },
	{ "updateContents()", &slot_6, QMetaData::Protected },
	{ "doAutoScroll()", &slot_7, QMetaData::Protected },
	{ "changeSortColumn(int)", &slot_8, QMetaData::Private },
	{ "handleIndexChange()", &slot_9, QMetaData::Private },
	{ "updateDirtyItems()", &slot_10, QMetaData::Private },
	{ "makeVisible()", &slot_11, QMetaData::Private },
	{ "handleSizeChange(int,int,int)", &slot_12, QMetaData::Private },
	{ "startRename()", &slot_13, QMetaData::Private },
	{ "openFocusItem()", &slot_14, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"selectionChanged", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_1 = {"selectionChanged", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_2 = {"currentChanged", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_3 = {"clicked", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"clicked", 3, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_5 = {"pressed", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_6 = {"pressed", 3, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_7 = {"doubleClicked", 1, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_8 = {"doubleClicked", 3, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_9 = {"returnPressed", 1, param_signal_9 };
    static const QUParameter param_signal_10[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_10 = {"spacePressed", 1, param_signal_10 };
    static const QUParameter param_signal_11[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_11 = {"rightButtonClicked", 3, param_signal_11 };
    static const QUParameter param_signal_12[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_12 = {"rightButtonPressed", 3, param_signal_12 };
    static const QUParameter param_signal_13[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_13 = {"mouseButtonPressed", 4, param_signal_13 };
    static const QUParameter param_signal_14[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_14 = {"mouseButtonClicked", 4, param_signal_14 };
    static const QUParameter param_signal_15[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_15 = {"contextMenuRequested", 3, param_signal_15 };
    static const QUParameter param_signal_16[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_16 = {"onItem", 1, param_signal_16 };
    static const QUMethod signal_17 = {"onViewport", 0, 0 };
    static const QUParameter param_signal_18[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_18 = {"expanded", 1, param_signal_18 };
    static const QUParameter param_signal_19[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod signal_19 = {"collapsed", 1, param_signal_19 };
    static const QUParameter param_signal_20[] = {
	{ "e", &static_QUType_ptr, "QDropEvent", QUParameter::In }
    };
    static const QUMethod signal_20 = {"dropped", 1, param_signal_20 };
    static const QUParameter param_signal_21[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_21 = {"itemRenamed", 3, param_signal_21 };
    static const QUParameter param_signal_22[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_22 = {"itemRenamed", 2, param_signal_22 };
    static const QMetaData signal_tbl[] = {
	{ "selectionChanged()", &signal_0, QMetaData::Public },
	{ "selectionChanged(QListViewItem*)", &signal_1, QMetaData::Public },
	{ "currentChanged(QListViewItem*)", &signal_2, QMetaData::Public },
	{ "clicked(QListViewItem*)", &signal_3, QMetaData::Public },
	{ "clicked(QListViewItem*,const QPoint&,int)", &signal_4, QMetaData::Public },
	{ "pressed(QListViewItem*)", &signal_5, QMetaData::Public },
	{ "pressed(QListViewItem*,const QPoint&,int)", &signal_6, QMetaData::Public },
	{ "doubleClicked(QListViewItem*)", &signal_7, QMetaData::Public },
	{ "doubleClicked(QListViewItem*,const QPoint&,int)", &signal_8, QMetaData::Public },
	{ "returnPressed(QListViewItem*)", &signal_9, QMetaData::Public },
	{ "spacePressed(QListViewItem*)", &signal_10, QMetaData::Public },
	{ "rightButtonClicked(QListViewItem*,const QPoint&,int)", &signal_11, QMetaData::Public },
	{ "rightButtonPressed(QListViewItem*,const QPoint&,int)", &signal_12, QMetaData::Public },
	{ "mouseButtonPressed(int,QListViewItem*,const QPoint&,int)", &signal_13, QMetaData::Public },
	{ "mouseButtonClicked(int,QListViewItem*,const QPoint&,int)", &signal_14, QMetaData::Public },
	{ "contextMenuRequested(QListViewItem*,const QPoint&,int)", &signal_15, QMetaData::Public },
	{ "onItem(QListViewItem*)", &signal_16, QMetaData::Public },
	{ "onViewport()", &signal_17, QMetaData::Public },
	{ "expanded(QListViewItem*)", &signal_18, QMetaData::Public },
	{ "collapsed(QListViewItem*)", &signal_19, QMetaData::Public },
	{ "dropped(QDropEvent*)", &signal_20, QMetaData::Public },
	{ "itemRenamed(QListViewItem*,int,const QString&)", &signal_21, QMetaData::Public },
	{ "itemRenamed(QListViewItem*,int)", &signal_22, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[12] = {
 	{ "int","columns", 0x10000001, &QListView::metaObj, 0, -1 },
	{ "bool","multiSelection", 0x12001103, &QListView::metaObj, 0, -1 },
	{ "SelectionMode","selectionMode", 0x0107, &QListView::metaObj, &enum_tbl[0], -1 },
	{ "int","childCount", 0x10000001, &QListView::metaObj, 0, -1 },
	{ "bool","allColumnsShowFocus", 0x12000103, &QListView::metaObj, 0, -1 },
	{ "bool","showSortIndicator", 0x12000103, &QListView::metaObj, 0, -1 },
	{ "int","itemMargin", 0x10000103, &QListView::metaObj, 0, -1 },
	{ "bool","rootIsDecorated", 0x12000103, &QListView::metaObj, 0, -1 },
	{ "bool","showToolTips", 0x12000103, &QListView::metaObj, 0, -1 },
	{ "ResizeMode","resizeMode", 0x0107, &QListView::metaObj, &enum_tbl[1], -1 },
	{ "int","treeStepSize", 0x10000103, &QListView::metaObj, 0, -1 },
	{ "RenameAction","defaultRenameAction", 0x0107, &QListView::metaObj, &enum_tbl[2], -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QListView", parentObject,
	slot_tbl, 15,
	signal_tbl, 23,
#ifndef QT_NO_PROPERTIES
	props_tbl, 12,
	enum_tbl, 3,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QListView.setMetaObject( metaObj );
    return metaObj;
}

void* QListView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QListView" ) )
	return this;
    return QScrollView::qt_cast( clname );
}

// SIGNAL selectionChanged
void QListView::selectionChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL selectionChanged
void QListView::selectionChanged( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL currentChanged
void QListView::currentChanged( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL clicked
void QListView::clicked( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL clicked
void QListView::clicked( QListViewItem* t0, const QPoint& t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL pressed
void QListView::pressed( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL pressed
void QListView::pressed( QListViewItem* t0, const QPoint& t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL doubleClicked
void QListView::doubleClicked( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL doubleClicked
void QListView::doubleClicked( QListViewItem* t0, const QPoint& t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL returnPressed
void QListView::returnPressed( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL spacePressed
void QListView::spacePressed( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 10 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL rightButtonClicked
void QListView::rightButtonClicked( QListViewItem* t0, const QPoint& t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 11 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL rightButtonPressed
void QListView::rightButtonPressed( QListViewItem* t0, const QPoint& t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 12 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL mouseButtonPressed
void QListView::mouseButtonPressed( int t0, QListViewItem* t1, const QPoint& t2, int t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 13 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_int.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    static_QUType_varptr.set(o+3,&t2);
    static_QUType_int.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL mouseButtonClicked
void QListView::mouseButtonClicked( int t0, QListViewItem* t1, const QPoint& t2, int t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 14 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_int.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    static_QUType_varptr.set(o+3,&t2);
    static_QUType_int.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL contextMenuRequested
void QListView::contextMenuRequested( QListViewItem* t0, const QPoint& t1, int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 15 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    static_QUType_int.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL onItem
void QListView::onItem( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 16 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL onViewport
void QListView::onViewport()
{
    activate_signal( staticMetaObject()->signalOffset() + 17 );
}

// SIGNAL expanded
void QListView::expanded( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 18 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL collapsed
void QListView::collapsed( QListViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 19 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL dropped
void QListView::dropped( QDropEvent* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 20 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL itemRenamed
void QListView::itemRenamed( QListViewItem* t0, int t1, const QString& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 21 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL itemRenamed
void QListView::itemRenamed( QListViewItem* t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 22 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

bool QListView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: clear(); break;
    case 1: invertSelection(); break;
    case 2: selectAll((bool)static_QUType_bool.get(_o+1)); break;
    case 3: triggerUpdate(); break;
    case 4: setContentsPos((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 5: adjustColumn((int)static_QUType_int.get(_o+1)); break;
    case 6: updateContents(); break;
    case 7: doAutoScroll(); break;
    case 8: changeSortColumn((int)static_QUType_int.get(_o+1)); break;
    case 9: handleIndexChange(); break;
    case 10: updateDirtyItems(); break;
    case 11: makeVisible(); break;
    case 12: handleSizeChange((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 13: startRename(); break;
    case 14: openFocusItem(); break;
    default:
	return QScrollView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QListView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: selectionChanged(); break;
    case 1: selectionChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 2: currentChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 3: clicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 4: clicked((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 5: pressed((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 6: pressed((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 7: doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 8: doubleClicked((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 9: returnPressed((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 10: spacePressed((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 11: rightButtonClicked((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 12: rightButtonPressed((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 13: mouseButtonPressed((int)static_QUType_int.get(_o+1),(QListViewItem*)static_QUType_ptr.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3)),(int)static_QUType_int.get(_o+4)); break;
    case 14: mouseButtonClicked((int)static_QUType_int.get(_o+1),(QListViewItem*)static_QUType_ptr.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3)),(int)static_QUType_int.get(_o+4)); break;
    case 15: contextMenuRequested((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 16: onItem((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 17: onViewport(); break;
    case 18: expanded((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 19: collapsed((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 20: dropped((QDropEvent*)static_QUType_ptr.get(_o+1)); break;
    case 21: itemRenamed((QListViewItem*)static_QUType_ptr.get(_o+1),(int)static_QUType_int.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 22: itemRenamed((QListViewItem*)static_QUType_ptr.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QScrollView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QListView::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 1: *v = QVariant( this->columns() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setMultiSelection(v->asBool()); break;
	case 1: *v = QVariant( this->isMultiSelection(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setSelectionMode((SelectionMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->selectionMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 1: *v = QVariant( this->childCount() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setAllColumnsShowFocus(v->asBool()); break;
	case 1: *v = QVariant( this->allColumnsShowFocus(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setShowSortIndicator(v->asBool()); break;
	case 1: *v = QVariant( this->showSortIndicator(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setItemMargin(v->asInt()); break;
	case 1: *v = QVariant( this->itemMargin() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setRootIsDecorated(v->asBool()); break;
	case 1: *v = QVariant( this->rootIsDecorated(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setShowToolTips(v->asBool()); break;
	case 1: *v = QVariant( this->showToolTips(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setResizeMode((ResizeMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->resizeMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 0: setTreeStepSize(v->asInt()); break;
	case 1: *v = QVariant( this->treeStepSize() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 11: switch( f ) {
	case 0: setDefaultRenameAction((RenameAction&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->defaultRenameAction() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QScrollView::qt_property( id, f, v );
    }
    return TRUE;
}

bool QListView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDragObject::className() const
{
    return "QDragObject";
}

QMetaObject *QDragObject::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDragObject( "QDragObject", &QDragObject::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDragObject::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDragObject", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDragObject::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDragObject", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDragObject::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QDragObject", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDragObject.setMetaObject( metaObj );
    return metaObj;
}

void* QDragObject::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDragObject" ) )
	return this;
    if ( !qstrcmp( clname, "QMimeSource" ) )
	return (QMimeSource*)this;
    return QObject::qt_cast( clname );
}

bool QDragObject::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QDragObject::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDragObject::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QDragObject::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QStoredDrag::className() const
{
    return "QStoredDrag";
}

QMetaObject *QStoredDrag::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QStoredDrag( "QStoredDrag", &QStoredDrag::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QStoredDrag::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QStoredDrag", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QStoredDrag::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QStoredDrag", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QStoredDrag::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDragObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QStoredDrag", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QStoredDrag.setMetaObject( metaObj );
    return metaObj;
}

void* QStoredDrag::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QStoredDrag" ) )
	return this;
    return QDragObject::qt_cast( clname );
}

bool QStoredDrag::qt_invoke( int _id, QUObject* _o )
{
    return QDragObject::qt_invoke(_id,_o);
}

bool QStoredDrag::qt_emit( int _id, QUObject* _o )
{
    return QDragObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QStoredDrag::qt_property( int id, int f, QVariant* v)
{
    return QDragObject::qt_property( id, f, v);
}

bool QStoredDrag::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTextDrag::className() const
{
    return "QTextDrag";
}

QMetaObject *QTextDrag::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTextDrag( "QTextDrag", &QTextDrag::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTextDrag::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextDrag", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTextDrag::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextDrag", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTextDrag::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDragObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QTextDrag", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTextDrag.setMetaObject( metaObj );
    return metaObj;
}

void* QTextDrag::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTextDrag" ) )
	return this;
    return QDragObject::qt_cast( clname );
}

bool QTextDrag::qt_invoke( int _id, QUObject* _o )
{
    return QDragObject::qt_invoke(_id,_o);
}

bool QTextDrag::qt_emit( int _id, QUObject* _o )
{
    return QDragObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QTextDrag::qt_property( int id, int f, QVariant* v)
{
    return QDragObject::qt_property( id, f, v);
}

bool QTextDrag::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QImageDrag::className() const
{
    return "QImageDrag";
}

QMetaObject *QImageDrag::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QImageDrag( "QImageDrag", &QImageDrag::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QImageDrag::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QImageDrag", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QImageDrag::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QImageDrag", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QImageDrag::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDragObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QImageDrag", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QImageDrag.setMetaObject( metaObj );
    return metaObj;
}

void* QImageDrag::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QImageDrag" ) )
	return this;
    return QDragObject::qt_cast( clname );
}

bool QImageDrag::qt_invoke( int _id, QUObject* _o )
{
    return QDragObject::qt_invoke(_id,_o);
}

bool QImageDrag::qt_emit( int _id, QUObject* _o )
{
    return QDragObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QImageDrag::qt_property( int id, int f, QVariant* v)
{
    return QDragObject::qt_property( id, f, v);
}

bool QImageDrag::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QUriDrag::className() const
{
    return "QUriDrag";
}

QMetaObject *QUriDrag::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QUriDrag( "QUriDrag", &QUriDrag::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QUriDrag::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QUriDrag", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QUriDrag::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QUriDrag", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QUriDrag::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QStoredDrag::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QUriDrag", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QUriDrag.setMetaObject( metaObj );
    return metaObj;
}

void* QUriDrag::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QUriDrag" ) )
	return this;
    return QStoredDrag::qt_cast( clname );
}

bool QUriDrag::qt_invoke( int _id, QUObject* _o )
{
    return QStoredDrag::qt_invoke(_id,_o);
}

bool QUriDrag::qt_emit( int _id, QUObject* _o )
{
    return QStoredDrag::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QUriDrag::qt_property( int id, int f, QVariant* v)
{
    return QStoredDrag::qt_property( id, f, v);
}

bool QUriDrag::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QColorDrag::className() const
{
    return "QColorDrag";
}

QMetaObject *QColorDrag::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QColorDrag( "QColorDrag", &QColorDrag::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QColorDrag::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QColorDrag", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QColorDrag::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QColorDrag", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QColorDrag::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QStoredDrag::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QColorDrag", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QColorDrag.setMetaObject( metaObj );
    return metaObj;
}

void* QColorDrag::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QColorDrag" ) )
	return this;
    return QStoredDrag::qt_cast( clname );
}

bool QColorDrag::qt_invoke( int _id, QUObject* _o )
{
    return QStoredDrag::qt_invoke(_id,_o);
}

bool QColorDrag::qt_emit( int _id, QUObject* _o )
{
    return QStoredDrag::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QColorDrag::qt_property( int id, int f, QVariant* v)
{
    return QStoredDrag::qt_property( id, f, v);
}

bool QColorDrag::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDragManager::className() const
{
    return "QDragManager";
}

QMetaObject *QDragManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDragManager( "QDragManager", &QDragManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDragManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDragManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDragManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDragManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDragManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QDragManager", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDragManager.setMetaObject( metaObj );
    return metaObj;
}

void* QDragManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDragManager" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QDragManager::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QDragManager::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDragManager::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QDragManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QIconDrag::className() const
{
    return "QIconDrag";
}

QMetaObject *QIconDrag::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QIconDrag( "QIconDrag", &QIconDrag::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QIconDrag::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QIconDrag", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QIconDrag::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QIconDrag", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QIconDrag::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDragObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QIconDrag", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QIconDrag.setMetaObject( metaObj );
    return metaObj;
}

void* QIconDrag::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QIconDrag" ) )
	return this;
    return QDragObject::qt_cast( clname );
}

bool QIconDrag::qt_invoke( int _id, QUObject* _o )
{
    return QDragObject::qt_invoke(_id,_o);
}

bool QIconDrag::qt_emit( int _id, QUObject* _o )
{
    return QDragObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QIconDrag::qt_property( int id, int f, QVariant* v)
{
    return QDragObject::qt_property( id, f, v);
}

bool QIconDrag::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QIconView::className() const
{
    return "QIconView";
}

QMetaObject *QIconView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QIconView( "QIconView", &QIconView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QIconView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QIconView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QIconView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QIconView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QIconView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QScrollView::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "Single",  (int) QIconView::Single },
	{ "Multi",  (int) QIconView::Multi },
	{ "Extended",  (int) QIconView::Extended },
	{ "NoSelection",  (int) QIconView::NoSelection }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "LeftToRight",  (int) QIconView::LeftToRight },
	{ "TopToBottom",  (int) QIconView::TopToBottom }
    };
    static const QMetaEnum::Item enum_2[] = {
	{ "Fixed",  (int) QIconView::Fixed },
	{ "Adjust",  (int) QIconView::Adjust }
    };
    static const QMetaEnum::Item enum_3[] = {
	{ "Bottom",  (int) QIconView::Bottom },
	{ "Right",  (int) QIconView::Right }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "SelectionMode", 4, enum_0, FALSE },
	{ "Arrangement", 2, enum_1, FALSE },
	{ "ResizeMode", 2, enum_2, FALSE },
	{ "ItemTextPos", 2, enum_3, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "grid", &static_QUType_varptr, "\x09", QUParameter::In }
    };
    static const QUMethod slot_0 = {"arrangeItemsInGrid", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "grid", &static_QUType_varptr, "\x09", QUParameter::In },
	{ "update", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"arrangeItemsInGrid", 2, param_slot_1 };
    static const QUMethod slot_2 = {"arrangeItemsInGrid", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "update", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"arrangeItemsInGrid", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "x", &static_QUType_int, 0, QUParameter::In },
	{ "y", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setContentsPos", 2, param_slot_4 };
    static const QUMethod slot_5 = {"updateContents", 0, 0 };
    static const QUMethod slot_6 = {"doAutoScroll", 0, 0 };
    static const QUMethod slot_7 = {"adjustItems", 0, 0 };
    static const QUMethod slot_8 = {"slotUpdate", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ "dx", &static_QUType_int, 0, QUParameter::In },
	{ "dy", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"movedContents", 2, param_slot_9 };
    static const QMetaData slot_tbl[] = {
	{ "arrangeItemsInGrid(const QSize&)", &slot_0, QMetaData::Public },
	{ "arrangeItemsInGrid(const QSize&,bool)", &slot_1, QMetaData::Public },
	{ "arrangeItemsInGrid()", &slot_2, QMetaData::Public },
	{ "arrangeItemsInGrid(bool)", &slot_3, QMetaData::Public },
	{ "setContentsPos(int,int)", &slot_4, QMetaData::Public },
	{ "updateContents()", &slot_5, QMetaData::Public },
	{ "doAutoScroll()", &slot_6, QMetaData::Protected },
	{ "adjustItems()", &slot_7, QMetaData::Protected },
	{ "slotUpdate()", &slot_8, QMetaData::Protected },
	{ "movedContents(int,int)", &slot_9, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"selectionChanged", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod signal_1 = {"selectionChanged", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod signal_2 = {"currentChanged", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod signal_3 = {"clicked", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_4 = {"clicked", 2, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod signal_5 = {"pressed", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_ptr, "QIconViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_6 = {"pressed", 2, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod signal_7 = {"doubleClicked", 1, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod signal_8 = {"returnPressed", 1, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_9 = {"rightButtonClicked", 2, param_signal_9 };
    static const QUParameter param_signal_10[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_10 = {"rightButtonPressed", 2, param_signal_10 };
    static const QUParameter param_signal_11[] = {
	{ "button", &static_QUType_int, 0, QUParameter::In },
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_11 = {"mouseButtonPressed", 3, param_signal_11 };
    static const QUParameter param_signal_12[] = {
	{ "button", &static_QUType_int, 0, QUParameter::In },
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_12 = {"mouseButtonClicked", 3, param_signal_12 };
    static const QUParameter param_signal_13[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_13 = {"contextMenuRequested", 2, param_signal_13 };
    static const QUParameter param_signal_14[] = {
	{ "e", &static_QUType_ptr, "QDropEvent", QUParameter::In },
	{ "lst", &static_QUType_ptr, "QValueList<QIconDragItem>", QUParameter::In }
    };
    static const QUMethod signal_14 = {"dropped", 2, param_signal_14 };
    static const QUMethod signal_15 = {"moved", 0, 0 };
    static const QUParameter param_signal_16[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod signal_16 = {"onItem", 1, param_signal_16 };
    static const QUMethod signal_17 = {"onViewport", 0, 0 };
    static const QUParameter param_signal_18[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_18 = {"itemRenamed", 2, param_signal_18 };
    static const QUParameter param_signal_19[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod signal_19 = {"itemRenamed", 1, param_signal_19 };
    static const QMetaData signal_tbl[] = {
	{ "selectionChanged()", &signal_0, QMetaData::Public },
	{ "selectionChanged(QIconViewItem*)", &signal_1, QMetaData::Public },
	{ "currentChanged(QIconViewItem*)", &signal_2, QMetaData::Public },
	{ "clicked(QIconViewItem*)", &signal_3, QMetaData::Public },
	{ "clicked(QIconViewItem*,const QPoint&)", &signal_4, QMetaData::Public },
	{ "pressed(QIconViewItem*)", &signal_5, QMetaData::Public },
	{ "pressed(QIconViewItem*,const QPoint&)", &signal_6, QMetaData::Public },
	{ "doubleClicked(QIconViewItem*)", &signal_7, QMetaData::Public },
	{ "returnPressed(QIconViewItem*)", &signal_8, QMetaData::Public },
	{ "rightButtonClicked(QIconViewItem*,const QPoint&)", &signal_9, QMetaData::Public },
	{ "rightButtonPressed(QIconViewItem*,const QPoint&)", &signal_10, QMetaData::Public },
	{ "mouseButtonPressed(int,QIconViewItem*,const QPoint&)", &signal_11, QMetaData::Public },
	{ "mouseButtonClicked(int,QIconViewItem*,const QPoint&)", &signal_12, QMetaData::Public },
	{ "contextMenuRequested(QIconViewItem*,const QPoint&)", &signal_13, QMetaData::Public },
	{ "dropped(QDropEvent*,const QValueList<QIconDragItem>&)", &signal_14, QMetaData::Public },
	{ "moved()", &signal_15, QMetaData::Public },
	{ "onItem(QIconViewItem*)", &signal_16, QMetaData::Public },
	{ "onViewport()", &signal_17, QMetaData::Public },
	{ "itemRenamed(QIconViewItem*,const QString&)", &signal_18, QMetaData::Public },
	{ "itemRenamed(QIconViewItem*)", &signal_19, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[17] = {
 	{ "bool","sorting", 0x12000001, &QIconView::metaObj, 0, -1 },
	{ "bool","sortDirection", 0x12000001, &QIconView::metaObj, 0, -1 },
	{ "SelectionMode","selectionMode", 0x0107, &QIconView::metaObj, &enum_tbl[0], -1 },
	{ "int","gridX", 0x10000103, &QIconView::metaObj, 0, -1 },
	{ "int","gridY", 0x10000103, &QIconView::metaObj, 0, -1 },
	{ "int","spacing", 0x10000103, &QIconView::metaObj, 0, -1 },
	{ "ItemTextPos","itemTextPos", 0x0107, &QIconView::metaObj, &enum_tbl[3], -1 },
	{ "QBrush","itemTextBackground", 0x7000103, &QIconView::metaObj, 0, -1 },
	{ "Arrangement","arrangement", 0x0107, &QIconView::metaObj, &enum_tbl[1], -1 },
	{ "ResizeMode","resizeMode", 0x0107, &QIconView::metaObj, &enum_tbl[2], -1 },
	{ "int","maxItemWidth", 0x10000103, &QIconView::metaObj, 0, -1 },
	{ "int","maxItemTextLength", 0x10000103, &QIconView::metaObj, 0, -1 },
	{ "bool","autoArrange", 0x12000103, &QIconView::metaObj, 0, -1 },
	{ "bool","itemsMovable", 0x12000103, &QIconView::metaObj, 0, -1 },
	{ "bool","wordWrapIconText", 0x12000103, &QIconView::metaObj, 0, -1 },
	{ "bool","showToolTips", 0x12000103, &QIconView::metaObj, 0, -1 },
	{ "uint","count", 0x11000001, &QIconView::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QIconView", parentObject,
	slot_tbl, 10,
	signal_tbl, 20,
#ifndef QT_NO_PROPERTIES
	props_tbl, 17,
	enum_tbl, 4,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QIconView.setMetaObject( metaObj );
    return metaObj;
}

void* QIconView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QIconView" ) )
	return this;
    return QScrollView::qt_cast( clname );
}

// SIGNAL selectionChanged
void QIconView::selectionChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL selectionChanged
void QIconView::selectionChanged( QIconViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL currentChanged
void QIconView::currentChanged( QIconViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL clicked
void QIconView::clicked( QIconViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL clicked
void QIconView::clicked( QIconViewItem* t0, const QPoint& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL pressed
void QIconView::pressed( QIconViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL pressed
void QIconView::pressed( QIconViewItem* t0, const QPoint& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL doubleClicked
void QIconView::doubleClicked( QIconViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL returnPressed
void QIconView::returnPressed( QIconViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL rightButtonClicked
void QIconView::rightButtonClicked( QIconViewItem* t0, const QPoint& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL rightButtonPressed
void QIconView::rightButtonPressed( QIconViewItem* t0, const QPoint& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 10 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL mouseButtonPressed
void QIconView::mouseButtonPressed( int t0, QIconViewItem* t1, const QPoint& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 11 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    static_QUType_varptr.set(o+3,&t2);
    activate_signal( clist, o );
}

// SIGNAL mouseButtonClicked
void QIconView::mouseButtonClicked( int t0, QIconViewItem* t1, const QPoint& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 12 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    static_QUType_varptr.set(o+3,&t2);
    activate_signal( clist, o );
}

// SIGNAL contextMenuRequested
void QIconView::contextMenuRequested( QIconViewItem* t0, const QPoint& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 13 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL dropped
void QIconView::dropped( QDropEvent* t0, const QValueList<QIconDragItem>& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 14 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL moved
void QIconView::moved()
{
    activate_signal( staticMetaObject()->signalOffset() + 15 );
}

// SIGNAL onItem
void QIconView::onItem( QIconViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 16 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL onViewport
void QIconView::onViewport()
{
    activate_signal( staticMetaObject()->signalOffset() + 17 );
}

// SIGNAL itemRenamed
void QIconView::itemRenamed( QIconViewItem* t0, const QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 18 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL itemRenamed
void QIconView::itemRenamed( QIconViewItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 19 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QIconView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: arrangeItemsInGrid((const QSize&)*((const QSize*)static_QUType_ptr.get(_o+1))); break;
    case 1: arrangeItemsInGrid((const QSize&)*((const QSize*)static_QUType_ptr.get(_o+1)),(bool)static_QUType_bool.get(_o+2)); break;
    case 2: arrangeItemsInGrid(); break;
    case 3: arrangeItemsInGrid((bool)static_QUType_bool.get(_o+1)); break;
    case 4: setContentsPos((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 5: updateContents(); break;
    case 6: doAutoScroll(); break;
    case 7: adjustItems(); break;
    case 8: slotUpdate(); break;
    case 9: movedContents((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QScrollView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QIconView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: selectionChanged(); break;
    case 1: selectionChanged((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 2: currentChanged((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 3: clicked((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 4: clicked((QIconViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 5: pressed((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 6: pressed((QIconViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 7: doubleClicked((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 8: returnPressed((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 9: rightButtonClicked((QIconViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 10: rightButtonPressed((QIconViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 11: mouseButtonPressed((int)static_QUType_int.get(_o+1),(QIconViewItem*)static_QUType_ptr.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3))); break;
    case 12: mouseButtonClicked((int)static_QUType_int.get(_o+1),(QIconViewItem*)static_QUType_ptr.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3))); break;
    case 13: contextMenuRequested((QIconViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 14: dropped((QDropEvent*)static_QUType_ptr.get(_o+1),(const QValueList<QIconDragItem>&)*((const QValueList<QIconDragItem>*)static_QUType_ptr.get(_o+2))); break;
    case 15: moved(); break;
    case 16: onItem((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 17: onViewport(); break;
    case 18: itemRenamed((QIconViewItem*)static_QUType_ptr.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 19: itemRenamed((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QScrollView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QIconView::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 1: *v = QVariant( this->sorting(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 1: *v = QVariant( this->sortDirection(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setSelectionMode((SelectionMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->selectionMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setGridX(v->asInt()); break;
	case 1: *v = QVariant( this->gridX() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setGridY(v->asInt()); break;
	case 1: *v = QVariant( this->gridY() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setSpacing(v->asInt()); break;
	case 1: *v = QVariant( this->spacing() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setItemTextPos((ItemTextPos&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->itemTextPos() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setItemTextBackground(v->asBrush()); break;
	case 1: *v = QVariant( this->itemTextBackground() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setArrangement((Arrangement&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->arrangement() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setResizeMode((ResizeMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->resizeMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 0: setMaxItemWidth(v->asInt()); break;
	case 1: *v = QVariant( this->maxItemWidth() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 11: switch( f ) {
	case 0: setMaxItemTextLength(v->asInt()); break;
	case 1: *v = QVariant( this->maxItemTextLength() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 12: switch( f ) {
	case 0: setAutoArrange(v->asBool()); break;
	case 1: *v = QVariant( this->autoArrange(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 13: switch( f ) {
	case 0: setItemsMovable(v->asBool()); break;
	case 1: *v = QVariant( this->itemsMovable(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 14: switch( f ) {
	case 0: setWordWrapIconText(v->asBool()); break;
	case 1: *v = QVariant( this->wordWrapIconText(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 15: switch( f ) {
	case 0: setShowToolTips(v->asBool()); break;
	case 1: *v = QVariant( this->showToolTips(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 16: switch( f ) {
	case 1: *v = QVariant( this->count() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QScrollView::qt_property( id, f, v );
    }
    return TRUE;
}

bool QIconView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QPlatinumStyle::className() const
{
    return "QPlatinumStyle";
}

QMetaObject *QPlatinumStyle::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPlatinumStyle( "QPlatinumStyle", &QPlatinumStyle::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPlatinumStyle::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPlatinumStyle", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPlatinumStyle::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPlatinumStyle", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPlatinumStyle::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWindowsStyle::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QPlatinumStyle", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPlatinumStyle.setMetaObject( metaObj );
    return metaObj;
}

void* QPlatinumStyle::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPlatinumStyle" ) )
	return this;
    return QWindowsStyle::qt_cast( clname );
}

bool QPlatinumStyle::qt_invoke( int _id, QUObject* _o )
{
    return QWindowsStyle::qt_invoke(_id,_o);
}

bool QPlatinumStyle::qt_emit( int _id, QUObject* _o )
{
    return QWindowsStyle::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPlatinumStyle::qt_property( int id, int f, QVariant* v)
{
    return QWindowsStyle::qt_property( id, f, v);
}

bool QPlatinumStyle::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QErrorMessage::className() const
{
    return "QErrorMessage";
}

QMetaObject *QErrorMessage::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QErrorMessage( "QErrorMessage", &QErrorMessage::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QErrorMessage::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QErrorMessage", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QErrorMessage::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QErrorMessage", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QErrorMessage::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"message", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "message(const QString&)", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QErrorMessage", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QErrorMessage.setMetaObject( metaObj );
    return metaObj;
}

void* QErrorMessage::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QErrorMessage" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool QErrorMessage::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: message((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QErrorMessage::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QErrorMessage::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool QErrorMessage::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QPopupMenu::className() const
{
    return "QPopupMenu";
}

QMetaObject *QPopupMenu::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPopupMenu( "QPopupMenu", &QPopupMenu::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPopupMenu::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPopupMenu", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPopupMenu::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPopupMenu", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPopupMenu::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"subActivated", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"subHighlighted", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"accelActivated", 1, param_slot_2 };
    static const QUMethod slot_3 = {"accelDestroyed", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_4 = {"popupDestroyed", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"modalActivation", 1, param_slot_5 };
    static const QUMethod slot_6 = {"subMenuTimer", 0, 0 };
    static const QUMethod slot_7 = {"subScrollTimer", 0, 0 };
    static const QUMethod slot_8 = {"allowAnimation", 0, 0 };
    static const QUMethod slot_9 = {"toggleTearOff", 0, 0 };
    static const QUMethod slot_10 = {"performDelayedChanges", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "subActivated(int)", &slot_0, QMetaData::Private },
	{ "subHighlighted(int)", &slot_1, QMetaData::Private },
	{ "accelActivated(int)", &slot_2, QMetaData::Private },
	{ "accelDestroyed()", &slot_3, QMetaData::Private },
	{ "popupDestroyed(QObject*)", &slot_4, QMetaData::Private },
	{ "modalActivation(int)", &slot_5, QMetaData::Private },
	{ "subMenuTimer()", &slot_6, QMetaData::Private },
	{ "subScrollTimer()", &slot_7, QMetaData::Private },
	{ "allowAnimation()", &slot_8, QMetaData::Private },
	{ "toggleTearOff()", &slot_9, QMetaData::Private },
	{ "performDelayedChanges()", &slot_10, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"activated", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"highlighted", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"activatedRedirect", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"highlightedRedirect", 1, param_signal_3 };
    static const QUMethod signal_4 = {"aboutToShow", 0, 0 };
    static const QUMethod signal_5 = {"aboutToHide", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "activated(int)", &signal_0, QMetaData::Public },
	{ "highlighted(int)", &signal_1, QMetaData::Public },
	{ "activatedRedirect(int)", &signal_2, QMetaData::Public },
	{ "highlightedRedirect(int)", &signal_3, QMetaData::Public },
	{ "aboutToShow()", &signal_4, QMetaData::Public },
	{ "aboutToHide()", &signal_5, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[1] = {
 	{ "bool","checkable", 0x12000103, &QPopupMenu::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QPopupMenu", parentObject,
	slot_tbl, 11,
	signal_tbl, 6,
#ifndef QT_NO_PROPERTIES
	props_tbl, 1,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPopupMenu.setMetaObject( metaObj );
    return metaObj;
}

void* QPopupMenu::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPopupMenu" ) )
	return this;
    if ( !qstrcmp( clname, "QMenuData" ) )
	return (QMenuData*)this;
    return QFrame::qt_cast( clname );
}

// SIGNAL activated
void QPopupMenu::activated( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL highlighted
void QPopupMenu::highlighted( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL activatedRedirect
void QPopupMenu::activatedRedirect( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL highlightedRedirect
void QPopupMenu::highlightedRedirect( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 3, t0 );
}

// SIGNAL aboutToShow
void QPopupMenu::aboutToShow()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL aboutToHide
void QPopupMenu::aboutToHide()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

bool QPopupMenu::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: subActivated((int)static_QUType_int.get(_o+1)); break;
    case 1: subHighlighted((int)static_QUType_int.get(_o+1)); break;
    case 2: accelActivated((int)static_QUType_int.get(_o+1)); break;
    case 3: accelDestroyed(); break;
    case 4: popupDestroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 5: modalActivation((int)static_QUType_int.get(_o+1)); break;
    case 6: subMenuTimer(); break;
    case 7: subScrollTimer(); break;
    case 8: allowAnimation(); break;
    case 9: toggleTearOff(); break;
    case 10: performDelayedChanges(); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPopupMenu::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: activated((int)static_QUType_int.get(_o+1)); break;
    case 1: highlighted((int)static_QUType_int.get(_o+1)); break;
    case 2: activatedRedirect((int)static_QUType_int.get(_o+1)); break;
    case 3: highlightedRedirect((int)static_QUType_int.get(_o+1)); break;
    case 4: aboutToShow(); break;
    case 5: aboutToHide(); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QPopupMenu::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setCheckable(v->asBool()); break;
	case 1: *v = QVariant( this->isCheckable(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QFrame::qt_property( id, f, v );
    }
    return TRUE;
}

bool QPopupMenu::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QPrintDialog::className() const
{
    return "QPrintDialog";
}

QMetaObject *QPrintDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPrintDialog( "QPrintDialog", &QPrintDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPrintDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPrintDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPrintDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPrintDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPrintDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"browseClicked", 0, 0 };
    static const QUMethod slot_1 = {"okClicked", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"printerOrFileSelected", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"landscapeSelected", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"paperSizeSelected", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"orientSelected", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"pageOrderSelected", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"colorModeSelected", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"setNumCopies", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"printRangeSelected", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"setFirstPage", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"setLastPage", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"fileNameEditChanged", 1, param_slot_12 };
    static const QMetaData slot_tbl[] = {
	{ "browseClicked()", &slot_0, QMetaData::Private },
	{ "okClicked()", &slot_1, QMetaData::Private },
	{ "printerOrFileSelected(int)", &slot_2, QMetaData::Private },
	{ "landscapeSelected(int)", &slot_3, QMetaData::Private },
	{ "paperSizeSelected(int)", &slot_4, QMetaData::Private },
	{ "orientSelected(int)", &slot_5, QMetaData::Private },
	{ "pageOrderSelected(int)", &slot_6, QMetaData::Private },
	{ "colorModeSelected(int)", &slot_7, QMetaData::Private },
	{ "setNumCopies(int)", &slot_8, QMetaData::Private },
	{ "printRangeSelected(int)", &slot_9, QMetaData::Private },
	{ "setFirstPage(int)", &slot_10, QMetaData::Private },
	{ "setLastPage(int)", &slot_11, QMetaData::Private },
	{ "fileNameEditChanged(const QString&)", &slot_12, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QPrintDialog", parentObject,
	slot_tbl, 13,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPrintDialog.setMetaObject( metaObj );
    return metaObj;
}

void* QPrintDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPrintDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool QPrintDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: browseClicked(); break;
    case 1: okClicked(); break;
    case 2: printerOrFileSelected((int)static_QUType_int.get(_o+1)); break;
    case 3: landscapeSelected((int)static_QUType_int.get(_o+1)); break;
    case 4: paperSizeSelected((int)static_QUType_int.get(_o+1)); break;
    case 5: orientSelected((int)static_QUType_int.get(_o+1)); break;
    case 6: pageOrderSelected((int)static_QUType_int.get(_o+1)); break;
    case 7: colorModeSelected((int)static_QUType_int.get(_o+1)); break;
    case 8: setNumCopies((int)static_QUType_int.get(_o+1)); break;
    case 9: printRangeSelected((int)static_QUType_int.get(_o+1)); break;
    case 10: setFirstPage((int)static_QUType_int.get(_o+1)); break;
    case 11: setLastPage((int)static_QUType_int.get(_o+1)); break;
    case 12: fileNameEditChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPrintDialog::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPrintDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool QPrintDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QProcess::className() const
{
    return "QProcess";
}

QMetaObject *QProcess::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QProcess( "QProcess", &QProcess::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QProcess::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProcess", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QProcess::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProcess", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QProcess::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"tryTerminate", 0, 0 };
    static const QUMethod slot_1 = {"kill", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "buf", &static_QUType_varptr, "\x1d", QUParameter::In }
    };
    static const QUMethod slot_2 = {"writeToStdin", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "buf", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"writeToStdin", 1, param_slot_3 };
    static const QUMethod slot_4 = {"closeStdin", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "fd", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"socketRead", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "fd", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"socketWrite", 1, param_slot_6 };
    static const QUMethod slot_7 = {"timeout", 0, 0 };
    static const QUMethod slot_8 = {"closeStdinLaunch", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "tryTerminate()", &slot_0, QMetaData::Public },
	{ "kill()", &slot_1, QMetaData::Public },
	{ "writeToStdin(const QByteArray&)", &slot_2, QMetaData::Public },
	{ "writeToStdin(const QString&)", &slot_3, QMetaData::Public },
	{ "closeStdin()", &slot_4, QMetaData::Public },
	{ "socketRead(int)", &slot_5, QMetaData::Private },
	{ "socketWrite(int)", &slot_6, QMetaData::Private },
	{ "timeout()", &slot_7, QMetaData::Private },
	{ "closeStdinLaunch()", &slot_8, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"readyReadStdout", 0, 0 };
    static const QUMethod signal_1 = {"readyReadStderr", 0, 0 };
    static const QUMethod signal_2 = {"processExited", 0, 0 };
    static const QUMethod signal_3 = {"wroteToStdin", 0, 0 };
    static const QUMethod signal_4 = {"launchFinished", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "readyReadStdout()", &signal_0, QMetaData::Public },
	{ "readyReadStderr()", &signal_1, QMetaData::Public },
	{ "processExited()", &signal_2, QMetaData::Public },
	{ "wroteToStdin()", &signal_3, QMetaData::Public },
	{ "launchFinished()", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QProcess", parentObject,
	slot_tbl, 9,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QProcess.setMetaObject( metaObj );
    return metaObj;
}

void* QProcess::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QProcess" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL readyReadStdout
void QProcess::readyReadStdout()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL readyReadStderr
void QProcess::readyReadStderr()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL processExited
void QProcess::processExited()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL wroteToStdin
void QProcess::wroteToStdin()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL launchFinished
void QProcess::launchFinished()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

bool QProcess::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: tryTerminate(); break;
    case 1: kill(); break;
    case 2: writeToStdin((const QByteArray&)*((const QByteArray*)static_QUType_ptr.get(_o+1))); break;
    case 3: writeToStdin((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: closeStdin(); break;
    case 5: socketRead((int)static_QUType_int.get(_o+1)); break;
    case 6: socketWrite((int)static_QUType_int.get(_o+1)); break;
    case 7: timeout(); break;
    case 8: closeStdinLaunch(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QProcess::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: readyReadStdout(); break;
    case 1: readyReadStderr(); break;
    case 2: processExited(); break;
    case 3: wroteToStdin(); break;
    case 4: launchFinished(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QProcess::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QProcess::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QProgressBar::className() const
{
    return "QProgressBar";
}

QMetaObject *QProgressBar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QProgressBar( "QProgressBar", &QProgressBar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QProgressBar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProgressBar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QProgressBar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProgressBar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QProgressBar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUMethod slot_0 = {"reset", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "totalSteps", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setTotalSteps", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "progress", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setProgress", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "progress", &static_QUType_int, 0, QUParameter::In },
	{ "totalSteps", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"setProgress", 2, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "reset()", &slot_0, QMetaData::Public },
	{ "setTotalSteps(int)", &slot_1, QMetaData::Public },
	{ "setProgress(int)", &slot_2, QMetaData::Public },
	{ "setProgress(int,int)", &slot_3, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[6] = {
 	{ "int","totalSteps", 0x10000103, &QProgressBar::metaObj, 0, -1 },
	{ "int","progress", 0x10000103, &QProgressBar::metaObj, 0, -1 },
	{ "QString","progressString", 0x3000001, &QProgressBar::metaObj, 0, -1 },
	{ "bool","centerIndicator", 0x12000103, &QProgressBar::metaObj, 0, -1 },
	{ "bool","indicatorFollowsStyle", 0x12000103, &QProgressBar::metaObj, 0, -1 },
	{ "bool","percentageVisible", 0x12000103, &QProgressBar::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QProgressBar", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 6,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QProgressBar.setMetaObject( metaObj );
    return metaObj;
}

void* QProgressBar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QProgressBar" ) )
	return this;
    return QFrame::qt_cast( clname );
}

bool QProgressBar::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: reset(); break;
    case 1: setTotalSteps((int)static_QUType_int.get(_o+1)); break;
    case 2: setProgress((int)static_QUType_int.get(_o+1)); break;
    case 3: setProgress((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QProgressBar::qt_emit( int _id, QUObject* _o )
{
    return QFrame::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QProgressBar::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setTotalSteps(v->asInt()); break;
	case 1: *v = QVariant( this->totalSteps() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setProgress(v->asInt()); break;
	case 1: *v = QVariant( this->progress() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 1: *v = QVariant( this->progressString() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setCenterIndicator(v->asBool()); break;
	case 1: *v = QVariant( this->centerIndicator(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setIndicatorFollowsStyle(v->asBool()); break;
	case 1: *v = QVariant( this->indicatorFollowsStyle(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setPercentageVisible(v->asBool()); break;
	case 1: *v = QVariant( this->percentageVisible(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QFrame::qt_property( id, f, v );
    }
    return TRUE;
}

bool QProgressBar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSemiModal::className() const
{
    return "QSemiModal";
}

QMetaObject *QSemiModal::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSemiModal( "QSemiModal", &QSemiModal::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSemiModal::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSemiModal", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSemiModal::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSemiModal", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSemiModal::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QSemiModal", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSemiModal.setMetaObject( metaObj );
    return metaObj;
}

void* QSemiModal::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSemiModal" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool QSemiModal::qt_invoke( int _id, QUObject* _o )
{
    return QDialog::qt_invoke(_id,_o);
}

bool QSemiModal::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSemiModal::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool QSemiModal::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QStyleSheet::className() const
{
    return "QStyleSheet";
}

QMetaObject *QStyleSheet::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QStyleSheet( "QStyleSheet", &QStyleSheet::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QStyleSheet::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QStyleSheet", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QStyleSheet::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QStyleSheet", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QStyleSheet::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QStyleSheet", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QStyleSheet.setMetaObject( metaObj );
    return metaObj;
}

void* QStyleSheet::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QStyleSheet" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QStyleSheet::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QStyleSheet::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QStyleSheet::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QStyleSheet::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QPushButton::className() const
{
    return "QPushButton";
}

QMetaObject *QPushButton::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QPushButton( "QPushButton", &QPushButton::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QPushButton::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPushButton", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QPushButton::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QPushButton", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QPushButton::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QButton::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setOn", 1, param_slot_0 };
    static const QUMethod slot_1 = {"popupPressed", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setOn(bool)", &slot_0, QMetaData::Public },
	{ "popupPressed()", &slot_1, QMetaData::Private }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[8] = {
 	{ "bool","autoDefault", 0x12000103, &QPushButton::metaObj, 0, -1 },
	{ "bool","default", 0x12000103, &QPushButton::metaObj, 0, -1 },
	{ "bool","menuButton", 0x12001001, &QPushButton::metaObj, 0, -1 },
	{ "QIconSet","iconSet", 0xd000103, &QPushButton::metaObj, 0, -1 },
	{ "bool","toggleButton", 0x1202a302, &QPushButton::metaObj, 0, -1 },
	{ "bool","on", 0x1202a302, &QPushButton::metaObj, 0, -1 },
	{ "bool","flat", 0x12000103, &QPushButton::metaObj, 0, -1 },
	{ "bool","autoMask", 0x12020200, &QPushButton::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QPushButton", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 8,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QPushButton.setMetaObject( metaObj );
    return metaObj;
}

void* QPushButton::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QPushButton" ) )
	return this;
    return QButton::qt_cast( clname );
}

bool QPushButton::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setOn((bool)static_QUType_bool.get(_o+1)); break;
    case 1: popupPressed(); break;
    default:
	return QButton::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QPushButton::qt_emit( int _id, QUObject* _o )
{
    return QButton::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QPushButton::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setAutoDefault(v->asBool()); break;
	case 1: *v = QVariant( this->autoDefault(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setDefault(v->asBool()); break;
	case 1: *v = QVariant( this->isDefault(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 1: *v = QVariant( this->isMenuButton(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setIconSet(v->asIconSet()); break;
	case 1: if ( this->iconSet() ) *v = QVariant( *iconSet() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setToggleButton(v->asBool()); break;
	case 1: case 3: case 4: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setOn(v->asBool()); break;
	case 1: case 3: case 4: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setFlat(v->asBool()); break;
	case 1: *v = QVariant( this->isFlat(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	case 3: case 4: break;
	default: return FALSE;
    } break;
    default:
	return QButton::qt_property( id, f, v );
    }
    return TRUE;
resolve:
    return QButton::qt_property( staticMetaObject()->resolveProperty(id), f, v );
}

bool QPushButton::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QRadioButton::className() const
{
    return "QRadioButton";
}

QMetaObject *QRadioButton::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRadioButton( "QRadioButton", &QRadioButton::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRadioButton::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRadioButton", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRadioButton::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRadioButton", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRadioButton::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QButton::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "check", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setChecked", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "setChecked(bool)", &slot_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[2] = {
 	{ "bool","checked", 0x12000103, &QRadioButton::metaObj, 0, -1 },
	{ "bool","autoMask", 0x12020200, &QRadioButton::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QRadioButton", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 2,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRadioButton.setMetaObject( metaObj );
    return metaObj;
}

void* QRadioButton::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRadioButton" ) )
	return this;
    return QButton::qt_cast( clname );
}

bool QRadioButton::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setChecked((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QButton::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QRadioButton::qt_emit( int _id, QUObject* _o )
{
    return QButton::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRadioButton::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setChecked(v->asBool()); break;
	case 1: *v = QVariant( this->isChecked(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	case 3: case 4: break;
	default: return FALSE;
    } break;
    default:
	return QButton::qt_property( id, f, v );
    }
    return TRUE;
resolve:
    return QButton::qt_property( staticMetaObject()->resolveProperty(id), f, v );
}

bool QRadioButton::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDial::className() const
{
    return "QDial";
}

QMetaObject *QDial::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDial( "QDial", &QDial::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDial::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDial", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDial::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDial", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDial::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setValue", 1, param_slot_0 };
    static const QUMethod slot_1 = {"addLine", 0, 0 };
    static const QUMethod slot_2 = {"subtractLine", 0, 0 };
    static const QUMethod slot_3 = {"addPage", 0, 0 };
    static const QUMethod slot_4 = {"subtractPage", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setNotchesVisible", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "on", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"setWrapping", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "enable", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"setTracking", 1, param_slot_7 };
    static const QMetaData slot_tbl[] = {
	{ "setValue(int)", &slot_0, QMetaData::Public },
	{ "addLine()", &slot_1, QMetaData::Public },
	{ "subtractLine()", &slot_2, QMetaData::Public },
	{ "addPage()", &slot_3, QMetaData::Public },
	{ "subtractPage()", &slot_4, QMetaData::Public },
	{ "setNotchesVisible(bool)", &slot_5, QMetaData::Public },
	{ "setWrapping(bool)", &slot_6, QMetaData::Public },
	{ "setTracking(bool)", &slot_7, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"valueChanged", 1, param_signal_0 };
    static const QUMethod signal_1 = {"dialPressed", 0, 0 };
    static const QUParameter param_signal_2[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"dialMoved", 1, param_signal_2 };
    static const QUMethod signal_3 = {"dialReleased", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "valueChanged(int)", &signal_0, QMetaData::Public },
	{ "dialPressed()", &signal_1, QMetaData::Public },
	{ "dialMoved(int)", &signal_2, QMetaData::Public },
	{ "dialReleased()", &signal_3, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[10] = {
 	{ "bool","tracking", 0x12000103, &QDial::metaObj, 0, -1 },
	{ "bool","wrapping", 0x12000103, &QDial::metaObj, 0, -1 },
	{ "int","notchSize", 0x10000001, &QDial::metaObj, 0, -1 },
	{ "double","notchTarget", 0x13000103, &QDial::metaObj, 0, -1 },
	{ "bool","notchesVisible", 0x12000103, &QDial::metaObj, 0, -1 },
	{ "int","minValue", 0x10000103, &QDial::metaObj, 0, -1 },
	{ "int","maxValue", 0x10000103, &QDial::metaObj, 0, -1 },
	{ "int","lineStep", 0x10000103, &QDial::metaObj, 0, -1 },
	{ "int","pageStep", 0x10000103, &QDial::metaObj, 0, -1 },
	{ "int","value", 0x10000103, &QDial::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QDial", parentObject,
	slot_tbl, 8,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	props_tbl, 10,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDial.setMetaObject( metaObj );
    return metaObj;
}

void* QDial::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDial" ) )
	return this;
    if ( !qstrcmp( clname, "QRangeControl" ) )
	return (QRangeControl*)this;
    return QWidget::qt_cast( clname );
}

// SIGNAL valueChanged
void QDial::valueChanged( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL dialPressed
void QDial::dialPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL dialMoved
void QDial::dialMoved( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL dialReleased
void QDial::dialReleased()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

bool QDial::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setValue((int)static_QUType_int.get(_o+1)); break;
    case 1: addLine(); break;
    case 2: subtractLine(); break;
    case 3: addPage(); break;
    case 4: subtractPage(); break;
    case 5: setNotchesVisible((bool)static_QUType_bool.get(_o+1)); break;
    case 6: setWrapping((bool)static_QUType_bool.get(_o+1)); break;
    case 7: setTracking((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDial::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 1: dialPressed(); break;
    case 2: dialMoved((int)static_QUType_int.get(_o+1)); break;
    case 3: dialReleased(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QDial::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setTracking(v->asBool()); break;
	case 1: *v = QVariant( this->tracking(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setWrapping(v->asBool()); break;
	case 1: *v = QVariant( this->wrapping(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 1: *v = QVariant( this->notchSize() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setNotchTarget(v->asDouble()); break;
	case 1: *v = QVariant( this->notchTarget() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setNotchesVisible(v->asBool()); break;
	case 1: *v = QVariant( this->notchesVisible(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setMinValue(v->asInt()); break;
	case 1: *v = QVariant( this->minValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setMaxValue(v->asInt()); break;
	case 1: *v = QVariant( this->maxValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setLineStep(v->asInt()); break;
	case 1: *v = QVariant( this->lineStep() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setPageStep(v->asInt()); break;
	case 1: *v = QVariant( this->pageStep() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setValue(v->asInt()); break;
	case 1: *v = QVariant( this->value() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QDial::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDockAreaLayout::className() const
{
    return "QDockAreaLayout";
}

QMetaObject *QDockAreaLayout::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDockAreaLayout( "QDockAreaLayout", &QDockAreaLayout::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDockAreaLayout::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDockAreaLayout", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDockAreaLayout::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDockAreaLayout", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDockAreaLayout::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QLayout::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QDockAreaLayout", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDockAreaLayout.setMetaObject( metaObj );
    return metaObj;
}

void* QDockAreaLayout::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDockAreaLayout" ) )
	return this;
    return QLayout::qt_cast( clname );
}

bool QDockAreaLayout::qt_invoke( int _id, QUObject* _o )
{
    return QLayout::qt_invoke(_id,_o);
}

bool QDockAreaLayout::qt_emit( int _id, QUObject* _o )
{
    return QLayout::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDockAreaLayout::qt_property( int id, int f, QVariant* v)
{
    return QLayout::qt_property( id, f, v);
}

bool QDockAreaLayout::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDockArea::className() const
{
    return "QDockArea";
}

QMetaObject *QDockArea::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDockArea( "QDockArea", &QDockArea::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDockArea::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDockArea", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDockArea::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDockArea", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDockArea::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "Normal",  (int) QDockArea::Normal },
	{ "Reverse",  (int) QDockArea::Reverse }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "HandlePosition", 2, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "keepNewLines", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"lineUp", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "lineUp(bool)", &slot_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[4] = {
 	{ "Orientation","orientation", 0x000d, &QDockArea::metaObj, 0, -1 },
	{ "int","count", 0x10000001, &QDockArea::metaObj, 0, -1 },
	{ "bool","empty", 0x12000001, &QDockArea::metaObj, 0, -1 },
	{ "HandlePosition","handlePosition", 0x0005, &QDockArea::metaObj, &enum_tbl[0], -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QDockArea", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 4,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDockArea.setMetaObject( metaObj );
    return metaObj;
}

void* QDockArea::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDockArea" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QDockArea::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: lineUp((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDockArea::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDockArea::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 1: *v = QVariant( (int)this->orientation() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 1: *v = QVariant( this->count() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 1: *v = QVariant( this->isEmpty(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 1: *v = QVariant( (int)this->handlePosition() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QDockArea::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QClipboard::className() const
{
    return "QClipboard";
}

QMetaObject *QClipboard::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QClipboard( "QClipboard", &QClipboard::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QClipboard::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClipboard", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QClipboard::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QClipboard", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QClipboard::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"ownerDestroyed", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "ownerDestroyed()", &slot_0, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"selectionChanged", 0, 0 };
    static const QUMethod signal_1 = {"dataChanged", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "selectionChanged()", &signal_0, QMetaData::Public },
	{ "dataChanged()", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QClipboard", parentObject,
	slot_tbl, 1,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QClipboard.setMetaObject( metaObj );
    return metaObj;
}

void* QClipboard::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QClipboard" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL selectionChanged
void QClipboard::selectionChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL dataChanged
void QClipboard::dataChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool QClipboard::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: ownerDestroyed(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QClipboard::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: selectionChanged(); break;
    case 1: dataChanged(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QClipboard::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QClipboard::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QListBox::className() const
{
    return "QListBox";
}

QMetaObject *QListBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QListBox( "QListBox", &QListBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QListBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QListBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QListBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QListBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QListBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QScrollView::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "Single",  (int) QListBox::Single },
	{ "Multi",  (int) QListBox::Multi },
	{ "Extended",  (int) QListBox::Extended },
	{ "NoSelection",  (int) QListBox::NoSelection }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "FixedNumber",  (int) QListBox::FixedNumber },
	{ "FitToWidth",  (int) QListBox::FitToWidth },
	{ "FitToHeight",  (int) QListBox::FitToHeight },
	{ "Variable",  (int) QListBox::Variable }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "SelectionMode", 4, enum_0, FALSE },
	{ "LayoutMode", 4, enum_1, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUMethod slot_0 = {"clear", 0, 0 };
    static const QUMethod slot_1 = {"ensureCurrentVisible", 0, 0 };
    static const QUMethod slot_2 = {"clearSelection", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "select", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"selectAll", 1, param_slot_3 };
    static const QUMethod slot_4 = {"invertSelection", 0, 0 };
    static const QUMethod slot_5 = {"clearInputString", 0, 0 };
    static const QUMethod slot_6 = {"refreshSlot", 0, 0 };
    static const QUMethod slot_7 = {"doAutoScroll", 0, 0 };
    static const QUMethod slot_8 = {"adjustItems", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "clear()", &slot_0, QMetaData::Public },
	{ "ensureCurrentVisible()", &slot_1, QMetaData::Public },
	{ "clearSelection()", &slot_2, QMetaData::Public },
	{ "selectAll(bool)", &slot_3, QMetaData::Public },
	{ "invertSelection()", &slot_4, QMetaData::Public },
	{ "clearInputString()", &slot_5, QMetaData::Protected },
	{ "refreshSlot()", &slot_6, QMetaData::Private },
	{ "doAutoScroll()", &slot_7, QMetaData::Private },
	{ "adjustItems()", &slot_8, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"highlighted", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"selected", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"highlighted", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"selected", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod signal_4 = {"highlighted", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod signal_5 = {"selected", 1, param_signal_5 };
    static const QUMethod signal_6 = {"selectionChanged", 0, 0 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod signal_7 = {"selectionChanged", 1, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod signal_8 = {"currentChanged", 1, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod signal_9 = {"clicked", 1, param_signal_9 };
    static const QUParameter param_signal_10[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_10 = {"clicked", 2, param_signal_10 };
    static const QUParameter param_signal_11[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod signal_11 = {"pressed", 1, param_signal_11 };
    static const QUParameter param_signal_12[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_12 = {"pressed", 2, param_signal_12 };
    static const QUParameter param_signal_13[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod signal_13 = {"doubleClicked", 1, param_signal_13 };
    static const QUParameter param_signal_14[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod signal_14 = {"returnPressed", 1, param_signal_14 };
    static const QUParameter param_signal_15[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_15 = {"rightButtonClicked", 2, param_signal_15 };
    static const QUParameter param_signal_16[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_16 = {"rightButtonPressed", 2, param_signal_16 };
    static const QUParameter param_signal_17[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_17 = {"mouseButtonPressed", 3, param_signal_17 };
    static const QUParameter param_signal_18[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_18 = {"mouseButtonClicked", 3, param_signal_18 };
    static const QUParameter param_signal_19[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_19 = {"contextMenuRequested", 2, param_signal_19 };
    static const QUParameter param_signal_20[] = {
	{ "item", &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod signal_20 = {"onItem", 1, param_signal_20 };
    static const QUMethod signal_21 = {"onViewport", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "highlighted(int)", &signal_0, QMetaData::Public },
	{ "selected(int)", &signal_1, QMetaData::Public },
	{ "highlighted(const QString&)", &signal_2, QMetaData::Public },
	{ "selected(const QString&)", &signal_3, QMetaData::Public },
	{ "highlighted(QListBoxItem*)", &signal_4, QMetaData::Public },
	{ "selected(QListBoxItem*)", &signal_5, QMetaData::Public },
	{ "selectionChanged()", &signal_6, QMetaData::Public },
	{ "selectionChanged(QListBoxItem*)", &signal_7, QMetaData::Public },
	{ "currentChanged(QListBoxItem*)", &signal_8, QMetaData::Public },
	{ "clicked(QListBoxItem*)", &signal_9, QMetaData::Public },
	{ "clicked(QListBoxItem*,const QPoint&)", &signal_10, QMetaData::Public },
	{ "pressed(QListBoxItem*)", &signal_11, QMetaData::Public },
	{ "pressed(QListBoxItem*,const QPoint&)", &signal_12, QMetaData::Public },
	{ "doubleClicked(QListBoxItem*)", &signal_13, QMetaData::Public },
	{ "returnPressed(QListBoxItem*)", &signal_14, QMetaData::Public },
	{ "rightButtonClicked(QListBoxItem*,const QPoint&)", &signal_15, QMetaData::Public },
	{ "rightButtonPressed(QListBoxItem*,const QPoint&)", &signal_16, QMetaData::Public },
	{ "mouseButtonPressed(int,QListBoxItem*,const QPoint&)", &signal_17, QMetaData::Public },
	{ "mouseButtonClicked(int,QListBoxItem*,const QPoint&)", &signal_18, QMetaData::Public },
	{ "contextMenuRequested(QListBoxItem*,const QPoint&)", &signal_19, QMetaData::Public },
	{ "onItem(QListBoxItem*)", &signal_20, QMetaData::Public },
	{ "onViewport()", &signal_21, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[13] = {
 	{ "uint","count", 0x11000001, &QListBox::metaObj, 0, -1 },
	{ "int","numItemsVisible", 0x10000001, &QListBox::metaObj, 0, -1 },
	{ "int","currentItem", 0x10000103, &QListBox::metaObj, 0, -1 },
	{ "QString","currentText", 0x3000001, &QListBox::metaObj, 0, -1 },
	{ "int","topItem", 0x10001103, &QListBox::metaObj, 0, -1 },
	{ "SelectionMode","selectionMode", 0x0107, &QListBox::metaObj, &enum_tbl[0], -1 },
	{ "bool","multiSelection", 0x12001103, &QListBox::metaObj, 0, -1 },
	{ "LayoutMode","columnMode", 0x0107, &QListBox::metaObj, &enum_tbl[1], -1 },
	{ "LayoutMode","rowMode", 0x0107, &QListBox::metaObj, &enum_tbl[1], -1 },
	{ "int","numColumns", 0x10000001, &QListBox::metaObj, 0, -1 },
	{ "int","numRows", 0x10000001, &QListBox::metaObj, 0, -1 },
	{ "bool","variableWidth", 0x12000103, &QListBox::metaObj, 0, -1 },
	{ "bool","variableHeight", 0x12000103, &QListBox::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QListBox", parentObject,
	slot_tbl, 9,
	signal_tbl, 22,
#ifndef QT_NO_PROPERTIES
	props_tbl, 13,
	enum_tbl, 2,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QListBox.setMetaObject( metaObj );
    return metaObj;
}

void* QListBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QListBox" ) )
	return this;
    return QScrollView::qt_cast( clname );
}

// SIGNAL highlighted
void QListBox::highlighted( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL selected
void QListBox::selected( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL highlighted
void QListBox::highlighted( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL selected
void QListBox::selected( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 3, t0 );
}

// SIGNAL highlighted
void QListBox::highlighted( QListBoxItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL selected
void QListBox::selected( QListBoxItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL selectionChanged
void QListBox::selectionChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 6 );
}

// SIGNAL selectionChanged
void QListBox::selectionChanged( QListBoxItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL currentChanged
void QListBox::currentChanged( QListBoxItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL clicked
void QListBox::clicked( QListBoxItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL clicked
void QListBox::clicked( QListBoxItem* t0, const QPoint& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 10 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL pressed
void QListBox::pressed( QListBoxItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 11 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL pressed
void QListBox::pressed( QListBoxItem* t0, const QPoint& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 12 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL doubleClicked
void QListBox::doubleClicked( QListBoxItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 13 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL returnPressed
void QListBox::returnPressed( QListBoxItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 14 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL rightButtonClicked
void QListBox::rightButtonClicked( QListBoxItem* t0, const QPoint& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 15 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL rightButtonPressed
void QListBox::rightButtonPressed( QListBoxItem* t0, const QPoint& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 16 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL mouseButtonPressed
void QListBox::mouseButtonPressed( int t0, QListBoxItem* t1, const QPoint& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 17 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    static_QUType_varptr.set(o+3,&t2);
    activate_signal( clist, o );
}

// SIGNAL mouseButtonClicked
void QListBox::mouseButtonClicked( int t0, QListBoxItem* t1, const QPoint& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 18 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_ptr.set(o+2,t1);
    static_QUType_varptr.set(o+3,&t2);
    activate_signal( clist, o );
}

// SIGNAL contextMenuRequested
void QListBox::contextMenuRequested( QListBoxItem* t0, const QPoint& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 19 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL onItem
void QListBox::onItem( QListBoxItem* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 20 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL onViewport
void QListBox::onViewport()
{
    activate_signal( staticMetaObject()->signalOffset() + 21 );
}

bool QListBox::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: clear(); break;
    case 1: ensureCurrentVisible(); break;
    case 2: clearSelection(); break;
    case 3: selectAll((bool)static_QUType_bool.get(_o+1)); break;
    case 4: invertSelection(); break;
    case 5: clearInputString(); break;
    case 6: refreshSlot(); break;
    case 7: doAutoScroll(); break;
    case 8: adjustItems(); break;
    default:
	return QScrollView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QListBox::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: highlighted((int)static_QUType_int.get(_o+1)); break;
    case 1: selected((int)static_QUType_int.get(_o+1)); break;
    case 2: highlighted((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: selected((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: highlighted((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 5: selected((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 6: selectionChanged(); break;
    case 7: selectionChanged((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 8: currentChanged((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 9: clicked((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 10: clicked((QListBoxItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 11: pressed((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 12: pressed((QListBoxItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 13: doubleClicked((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 14: returnPressed((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 15: rightButtonClicked((QListBoxItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 16: rightButtonPressed((QListBoxItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 17: mouseButtonPressed((int)static_QUType_int.get(_o+1),(QListBoxItem*)static_QUType_ptr.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3))); break;
    case 18: mouseButtonClicked((int)static_QUType_int.get(_o+1),(QListBoxItem*)static_QUType_ptr.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3))); break;
    case 19: contextMenuRequested((QListBoxItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 20: onItem((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 21: onViewport(); break;
    default:
	return QScrollView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QListBox::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 1: *v = QVariant( this->count() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 1: *v = QVariant( this->numItemsVisible() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setCurrentItem(v->asInt()); break;
	case 1: *v = QVariant( this->currentItem() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 1: *v = QVariant( this->currentText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setTopItem(v->asInt()); break;
	case 1: *v = QVariant( this->topItem() ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setSelectionMode((SelectionMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->selectionMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setMultiSelection(v->asBool()); break;
	case 1: *v = QVariant( this->isMultiSelection(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setColumnMode((LayoutMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->columnMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setRowMode((LayoutMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->rowMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 1: *v = QVariant( this->numColumns() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 1: *v = QVariant( this->numRows() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 11: switch( f ) {
	case 0: setVariableWidth(v->asBool()); break;
	case 1: *v = QVariant( this->variableWidth(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 12: switch( f ) {
	case 0: setVariableHeight(v->asBool()); break;
	case 1: *v = QVariant( this->variableHeight(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QScrollView::qt_property( id, f, v );
    }
    return TRUE;
}

bool QListBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QGridView::className() const
{
    return "QGridView";
}

QMetaObject *QGridView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QGridView( "QGridView", &QGridView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QGridView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGridView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QGridView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGridView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QGridView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QScrollView::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[4] = {
 	{ "int","numRows", 0x10000103, &QGridView::metaObj, 0, -1 },
	{ "int","numCols", 0x10000103, &QGridView::metaObj, 0, -1 },
	{ "int","cellWidth", 0x10000103, &QGridView::metaObj, 0, -1 },
	{ "int","cellHeight", 0x10000103, &QGridView::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QGridView", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 4,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QGridView.setMetaObject( metaObj );
    return metaObj;
}

void* QGridView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QGridView" ) )
	return this;
    return QScrollView::qt_cast( clname );
}

bool QGridView::qt_invoke( int _id, QUObject* _o )
{
    return QScrollView::qt_invoke(_id,_o);
}

bool QGridView::qt_emit( int _id, QUObject* _o )
{
    return QScrollView::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QGridView::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setNumRows(v->asInt()); break;
	case 1: *v = QVariant( this->numRows() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setNumCols(v->asInt()); break;
	case 1: *v = QVariant( this->numCols() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setCellWidth(v->asInt()); break;
	case 1: *v = QVariant( this->cellWidth() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setCellHeight(v->asInt()); break;
	case 1: *v = QVariant( this->cellHeight() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QScrollView::qt_property( id, f, v );
    }
    return TRUE;
}

bool QGridView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QProgressDialog::className() const
{
    return "QProgressDialog";
}

QMetaObject *QProgressDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QProgressDialog( "QProgressDialog", &QProgressDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QProgressDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProgressDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QProgressDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QProgressDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QProgressDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"cancel", 0, 0 };
    static const QUMethod slot_1 = {"reset", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "totalSteps", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setTotalSteps", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "progress", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"setProgress", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "progress", &static_QUType_int, 0, QUParameter::In },
	{ "totalSteps", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setProgress", 2, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setLabelText", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"setCancelButtonText", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "ms", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"setMinimumDuration", 1, param_slot_7 };
    static const QUMethod slot_8 = {"forceShow", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "cancel()", &slot_0, QMetaData::Public },
	{ "reset()", &slot_1, QMetaData::Public },
	{ "setTotalSteps(int)", &slot_2, QMetaData::Public },
	{ "setProgress(int)", &slot_3, QMetaData::Public },
	{ "setProgress(int,int)", &slot_4, QMetaData::Public },
	{ "setLabelText(const QString&)", &slot_5, QMetaData::Public },
	{ "setCancelButtonText(const QString&)", &slot_6, QMetaData::Public },
	{ "setMinimumDuration(int)", &slot_7, QMetaData::Public },
	{ "forceShow()", &slot_8, QMetaData::Protected }
    };
    static const QUMethod signal_0 = {"cancelled", 0, 0 };
    static const QUMethod signal_1 = {"canceled", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "cancelled()", &signal_0, QMetaData::Public },
	{ "canceled()", &signal_1, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[8] = {
 	{ "bool","wasCancelled", 0x12011001, &QProgressDialog::metaObj, 0, -1 },
	{ "bool","wasCanceled", 0x12000001, &QProgressDialog::metaObj, 0, -1 },
	{ "int","totalSteps", 0x10000103, &QProgressDialog::metaObj, 0, -1 },
	{ "int","progress", 0x10000103, &QProgressDialog::metaObj, 0, -1 },
	{ "bool","autoReset", 0x12000103, &QProgressDialog::metaObj, 0, -1 },
	{ "bool","autoClose", 0x12000103, &QProgressDialog::metaObj, 0, -1 },
	{ "int","minimumDuration", 0x10000103, &QProgressDialog::metaObj, 0, -1 },
	{ "QString","labelText", 0x3000103, &QProgressDialog::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QProgressDialog", parentObject,
	slot_tbl, 9,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	props_tbl, 8,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QProgressDialog.setMetaObject( metaObj );
    return metaObj;
}

void* QProgressDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QProgressDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

// SIGNAL cancelled
void QProgressDialog::cancelled()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL canceled
void QProgressDialog::canceled()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool QProgressDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: cancel(); break;
    case 1: reset(); break;
    case 2: setTotalSteps((int)static_QUType_int.get(_o+1)); break;
    case 3: setProgress((int)static_QUType_int.get(_o+1)); break;
    case 4: setProgress((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 5: setLabelText((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: setCancelButtonText((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: setMinimumDuration((int)static_QUType_int.get(_o+1)); break;
    case 8: forceShow(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QProgressDialog::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: cancelled(); break;
    case 1: canceled(); break;
    default:
	return QDialog::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QProgressDialog::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 1: *v = QVariant( this->wasCancelled(), 0 ); break;
	case 4: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 1: *v = QVariant( this->wasCanceled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setTotalSteps(v->asInt()); break;
	case 1: *v = QVariant( this->totalSteps() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setProgress(v->asInt()); break;
	case 1: *v = QVariant( this->progress() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setAutoReset(v->asBool()); break;
	case 1: *v = QVariant( this->autoReset(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setAutoClose(v->asBool()); break;
	case 1: *v = QVariant( this->autoClose(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setMinimumDuration(v->asInt()); break;
	case 1: *v = QVariant( this->minimumDuration() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setLabelText(v->asString()); break;
	case 1: *v = QVariant( this->labelText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QDialog::qt_property( id, f, v );
    }
    return TRUE;
}

bool QProgressDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSessionManager::className() const
{
    return "QSessionManager";
}

QMetaObject *QSessionManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSessionManager( "QSessionManager", &QSessionManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSessionManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSessionManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSessionManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSessionManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSessionManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QSessionManager", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSessionManager.setMetaObject( metaObj );
    return metaObj;
}

void* QSessionManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSessionManager" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QSessionManager::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QSessionManager::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSessionManager::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QSessionManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSGIStyle::className() const
{
    return "QSGIStyle";
}

QMetaObject *QSGIStyle::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSGIStyle( "QSGIStyle", &QSGIStyle::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSGIStyle::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSGIStyle", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSGIStyle::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSGIStyle", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSGIStyle::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMotifStyle::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QSGIStyle", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSGIStyle.setMetaObject( metaObj );
    return metaObj;
}

void* QSGIStyle::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSGIStyle" ) )
	return this;
    return QMotifStyle::qt_cast( clname );
}

bool QSGIStyle::qt_invoke( int _id, QUObject* _o )
{
    return QMotifStyle::qt_invoke(_id,_o);
}

bool QSGIStyle::qt_emit( int _id, QUObject* _o )
{
    return QMotifStyle::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSGIStyle::qt_property( int id, int f, QVariant* v)
{
    return QMotifStyle::qt_property( id, f, v);
}

bool QSGIStyle::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QFontDialog::className() const
{
    return "QFontDialog";
}

QMetaObject *QFontDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFontDialog( "QFontDialog", &QFontDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFontDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFontDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFontDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFontDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFontDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"sizeChanged", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"familyHighlighted", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"scriptHighlighted", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"styleHighlighted", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"sizeHighlighted", 1, param_slot_4 };
    static const QUMethod slot_5 = {"updateSample", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "sizeChanged(const QString&)", &slot_0, QMetaData::Private },
	{ "familyHighlighted(int)", &slot_1, QMetaData::Private },
	{ "scriptHighlighted(int)", &slot_2, QMetaData::Private },
	{ "styleHighlighted(int)", &slot_3, QMetaData::Private },
	{ "sizeHighlighted(const QString&)", &slot_4, QMetaData::Private },
	{ "updateSample()", &slot_5, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QFontDialog", parentObject,
	slot_tbl, 6,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFontDialog.setMetaObject( metaObj );
    return metaObj;
}

void* QFontDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFontDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool QFontDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: sizeChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: familyHighlighted((int)static_QUType_int.get(_o+1)); break;
    case 2: scriptHighlighted((int)static_QUType_int.get(_o+1)); break;
    case 3: styleHighlighted((int)static_QUType_int.get(_o+1)); break;
    case 4: sizeHighlighted((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: updateSample(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QFontDialog::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QFontDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool QFontDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTimer::className() const
{
    return "QTimer";
}

QMetaObject *QTimer::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTimer( "QTimer", &QTimer::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTimer::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTimer", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTimer::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTimer", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTimer::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod signal_0 = {"timeout", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "timeout()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QTimer", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTimer.setMetaObject( metaObj );
    return metaObj;
}

void* QTimer::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTimer" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL timeout
void QTimer::timeout()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool QTimer::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QTimer::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: timeout(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QTimer::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QTimer::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSignalMapper::className() const
{
    return "QSignalMapper";
}

QMetaObject *QSignalMapper::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSignalMapper( "QSignalMapper", &QSignalMapper::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSignalMapper::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSignalMapper", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSignalMapper::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSignalMapper", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSignalMapper::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"map", 0, 0 };
    static const QUMethod slot_1 = {"removeMapping", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "map()", &slot_0, QMetaData::Public },
	{ "removeMapping()", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"mapped", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"mapped", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "mapped(int)", &signal_0, QMetaData::Public },
	{ "mapped(const QString&)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSignalMapper", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSignalMapper.setMetaObject( metaObj );
    return metaObj;
}

void* QSignalMapper::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSignalMapper" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL mapped
void QSignalMapper::mapped( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL mapped
void QSignalMapper::mapped( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

bool QSignalMapper::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: map(); break;
    case 1: removeMapping(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSignalMapper::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: mapped((int)static_QUType_int.get(_o+1)); break;
    case 1: mapped((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QSignalMapper::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QSignalMapper::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSizeGrip::className() const
{
    return "QSizeGrip";
}

QMetaObject *QSizeGrip::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSizeGrip( "QSizeGrip", &QSizeGrip::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSizeGrip::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSizeGrip", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSizeGrip::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSizeGrip", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSizeGrip::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QSizeGrip", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSizeGrip.setMetaObject( metaObj );
    return metaObj;
}

void* QSizeGrip::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSizeGrip" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool QSizeGrip::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool QSizeGrip::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSizeGrip::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QSizeGrip::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSlider::className() const
{
    return "QSlider";
}

QMetaObject *QSlider::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSlider( "QSlider", &QSlider::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSlider::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSlider", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSlider::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSlider", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSlider::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "NoMarks",  (int) QSlider::NoMarks },
	{ "Above",  (int) QSlider::Above },
	{ "Left",  (int) QSlider::Left },
	{ "Below",  (int) QSlider::Below },
	{ "Right",  (int) QSlider::Right },
	{ "Both",  (int) QSlider::Both }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "TickSetting", 6, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setValue", 1, param_slot_0 };
    static const QUMethod slot_1 = {"addStep", 0, 0 };
    static const QUMethod slot_2 = {"subtractStep", 0, 0 };
    static const QUMethod slot_3 = {"addLine", 0, 0 };
    static const QUMethod slot_4 = {"subtractLine", 0, 0 };
    static const QUMethod slot_5 = {"repeatTimeout", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setValue(int)", &slot_0, QMetaData::Public },
	{ "addStep()", &slot_1, QMetaData::Public },
	{ "subtractStep()", &slot_2, QMetaData::Public },
	{ "addLine()", &slot_3, QMetaData::Public },
	{ "subtractLine()", &slot_4, QMetaData::Public },
	{ "repeatTimeout()", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"valueChanged", 1, param_signal_0 };
    static const QUMethod signal_1 = {"sliderPressed", 0, 0 };
    static const QUParameter param_signal_2[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"sliderMoved", 1, param_signal_2 };
    static const QUMethod signal_3 = {"sliderReleased", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "valueChanged(int)", &signal_0, QMetaData::Public },
	{ "sliderPressed()", &signal_1, QMetaData::Public },
	{ "sliderMoved(int)", &signal_2, QMetaData::Public },
	{ "sliderReleased()", &signal_3, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[9] = {
 	{ "int","minValue", 0x10000103, &QSlider::metaObj, 0, -1 },
	{ "int","maxValue", 0x10000103, &QSlider::metaObj, 0, -1 },
	{ "int","lineStep", 0x10000103, &QSlider::metaObj, 0, -1 },
	{ "int","pageStep", 0x10000103, &QSlider::metaObj, 0, -1 },
	{ "int","value", 0x10000103, &QSlider::metaObj, 0, -1 },
	{ "bool","tracking", 0x12000103, &QSlider::metaObj, 0, -1 },
	{ "Orientation","orientation", 0x010f, &QSlider::metaObj, 0, -1 },
	{ "TickSetting","tickmarks", 0x0107, &QSlider::metaObj, &enum_tbl[0], -1 },
	{ "int","tickInterval", 0x10000103, &QSlider::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QSlider", parentObject,
	slot_tbl, 6,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	props_tbl, 9,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSlider.setMetaObject( metaObj );
    return metaObj;
}

void* QSlider::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSlider" ) )
	return this;
    if ( !qstrcmp( clname, "QRangeControl" ) )
	return (QRangeControl*)this;
    return QWidget::qt_cast( clname );
}

// SIGNAL valueChanged
void QSlider::valueChanged( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL sliderPressed
void QSlider::sliderPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL sliderMoved
void QSlider::sliderMoved( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL sliderReleased
void QSlider::sliderReleased()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

bool QSlider::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setValue((int)static_QUType_int.get(_o+1)); break;
    case 1: addStep(); break;
    case 2: subtractStep(); break;
    case 3: addLine(); break;
    case 4: subtractLine(); break;
    case 5: repeatTimeout(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSlider::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 1: sliderPressed(); break;
    case 2: sliderMoved((int)static_QUType_int.get(_o+1)); break;
    case 3: sliderReleased(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QSlider::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setMinValue(v->asInt()); break;
	case 1: *v = QVariant( this->minValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setMaxValue(v->asInt()); break;
	case 1: *v = QVariant( this->maxValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setLineStep(v->asInt()); break;
	case 1: *v = QVariant( this->lineStep() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setPageStep(v->asInt()); break;
	case 1: *v = QVariant( this->pageStep() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setValue(v->asInt()); break;
	case 1: *v = QVariant( this->value() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setTracking(v->asBool()); break;
	case 1: *v = QVariant( this->tracking(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setOrientation((Orientation&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->orientation() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setTickmarks((TickSetting&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->tickmarks() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setTickInterval(v->asInt()); break;
	case 1: *v = QVariant( this->tickInterval() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QSlider::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSocket::className() const
{
    return "QSocket";
}

QMetaObject *QSocket::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSocket( "QSocket", &QSocket::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSocket::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSocket", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSocket::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSocket", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSocket::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"sn_read", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "force", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"sn_read", 1, param_slot_1 };
    static const QUMethod slot_2 = {"sn_write", 0, 0 };
    static const QUMethod slot_3 = {"tryConnecting", 0, 0 };
    static const QUMethod slot_4 = {"emitErrorConnectionRefused", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "sn_read()", &slot_0, QMetaData::Protected },
	{ "sn_read(bool)", &slot_1, QMetaData::Protected },
	{ "sn_write()", &slot_2, QMetaData::Protected },
	{ "tryConnecting()", &slot_3, QMetaData::Private },
	{ "emitErrorConnectionRefused()", &slot_4, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"hostFound", 0, 0 };
    static const QUMethod signal_1 = {"connected", 0, 0 };
    static const QUMethod signal_2 = {"connectionClosed", 0, 0 };
    static const QUMethod signal_3 = {"delayedCloseFinished", 0, 0 };
    static const QUMethod signal_4 = {"readyRead", 0, 0 };
    static const QUParameter param_signal_5[] = {
	{ "nbytes", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_5 = {"bytesWritten", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_6 = {"error", 1, param_signal_6 };
    static const QMetaData signal_tbl[] = {
	{ "hostFound()", &signal_0, QMetaData::Public },
	{ "connected()", &signal_1, QMetaData::Public },
	{ "connectionClosed()", &signal_2, QMetaData::Public },
	{ "delayedCloseFinished()", &signal_3, QMetaData::Public },
	{ "readyRead()", &signal_4, QMetaData::Public },
	{ "bytesWritten(int)", &signal_5, QMetaData::Public },
	{ "error(int)", &signal_6, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSocket", parentObject,
	slot_tbl, 5,
	signal_tbl, 7,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSocket.setMetaObject( metaObj );
    return metaObj;
}

void* QSocket::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSocket" ) )
	return this;
    if ( !qstrcmp( clname, "QIODevice" ) )
	return (QIODevice*)this;
    return QObject::qt_cast( clname );
}

// SIGNAL hostFound
void QSocket::hostFound()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL connected
void QSocket::connected()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL connectionClosed
void QSocket::connectionClosed()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL delayedCloseFinished
void QSocket::delayedCloseFinished()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL readyRead
void QSocket::readyRead()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL bytesWritten
void QSocket::bytesWritten( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 5, t0 );
}

// SIGNAL error
void QSocket::error( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 6, t0 );
}

bool QSocket::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: sn_read(); break;
    case 1: sn_read((bool)static_QUType_bool.get(_o+1)); break;
    case 2: sn_write(); break;
    case 3: tryConnecting(); break;
    case 4: emitErrorConnectionRefused(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSocket::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: hostFound(); break;
    case 1: connected(); break;
    case 2: connectionClosed(); break;
    case 3: delayedCloseFinished(); break;
    case 4: readyRead(); break;
    case 5: bytesWritten((int)static_QUType_int.get(_o+1)); break;
    case 6: error((int)static_QUType_int.get(_o+1)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QSocket::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QSocket::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QServerSocket::className() const
{
    return "QServerSocket";
}

QMetaObject *QServerSocket::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QServerSocket( "QServerSocket", &QServerSocket::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QServerSocket::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QServerSocket", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QServerSocket::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QServerSocket", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QServerSocket::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "socket", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"incomingConnection", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "incomingConnection(int)", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QServerSocket", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QServerSocket.setMetaObject( metaObj );
    return metaObj;
}

void* QServerSocket::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QServerSocket" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QServerSocket::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: incomingConnection((int)static_QUType_int.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QServerSocket::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QServerSocket::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QServerSocket::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDns::className() const
{
    return "QDns";
}

QMetaObject *QDns::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDns( "QDns", &QDns::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDns::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDns", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDns::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDns", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDns::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"startQuery", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "startQuery()", &slot_0, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"resultsReady", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "resultsReady()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDns", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDns.setMetaObject( metaObj );
    return metaObj;
}

void* QDns::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDns" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL resultsReady
void QDns::resultsReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool QDns::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: startQuery(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDns::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: resultsReady(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QDns::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QDns::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDnsSocket::className() const
{
    return "QDnsSocket";
}

QMetaObject *QDnsSocket::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDnsSocket( "QDnsSocket", &QDnsSocket::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDnsSocket::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDnsSocket", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDnsSocket::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDnsSocket", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDnsSocket::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"cleanCache", 0, 0 };
    static const QUMethod slot_1 = {"retransmit", 0, 0 };
    static const QUMethod slot_2 = {"answer", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "cleanCache()", &slot_0, QMetaData::Private },
	{ "retransmit()", &slot_1, QMetaData::Private },
	{ "answer()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDnsSocket", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDnsSocket.setMetaObject( metaObj );
    return metaObj;
}

void* QDnsSocket::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDnsSocket" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QDnsSocket::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: cleanCache(); break;
    case 1: retransmit(); break;
    case 2: answer(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDnsSocket::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDnsSocket::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QDnsSocket::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSound::className() const
{
    return "QSound";
}

QMetaObject *QSound::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSound( "QSound", &QSound::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSound::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSound", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSound::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSound", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSound::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"play", 0, 0 };
    static const QUMethod slot_1 = {"stop", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "play()", &slot_0, QMetaData::Public },
	{ "stop()", &slot_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSound", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSound.setMetaObject( metaObj );
    return metaObj;
}

void* QSound::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSound" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QSound::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: play(); break;
    case 1: stop(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSound::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSound::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QSound::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QAuServer::className() const
{
    return "QAuServer";
}

QMetaObject *QAuServer::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QAuServer( "QAuServer", &QAuServer::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QAuServer::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAuServer", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QAuServer::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QAuServer", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QAuServer::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QAuServer", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QAuServer.setMetaObject( metaObj );
    return metaObj;
}

void* QAuServer::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QAuServer" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QAuServer::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QAuServer::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QAuServer::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QAuServer::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSpinBox::className() const
{
    return "QSpinBox";
}

QMetaObject *QSpinBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSpinBox( "QSpinBox", &QSpinBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSpinBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSpinBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSpinBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSpinBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSpinBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "UpDownArrows",  (int) QSpinBox::UpDownArrows },
	{ "PlusMinus",  (int) QSpinBox::PlusMinus }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "ButtonSymbols", 2, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setValue", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setPrefix", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setSuffix", 1, param_slot_2 };
    static const QUMethod slot_3 = {"stepUp", 0, 0 };
    static const QUMethod slot_4 = {"stepDown", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "enabled", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setEnabled", 1, param_slot_5 };
    static const QUMethod slot_6 = {"selectAll", 0, 0 };
    static const QUMethod slot_7 = {"textChanged", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setValue(int)", &slot_0, QMetaData::Public },
	{ "setPrefix(const QString&)", &slot_1, QMetaData::Public },
	{ "setSuffix(const QString&)", &slot_2, QMetaData::Public },
	{ "stepUp()", &slot_3, QMetaData::Public },
	{ "stepDown()", &slot_4, QMetaData::Public },
	{ "setEnabled(bool)", &slot_5, QMetaData::Public },
	{ "selectAll()", &slot_6, QMetaData::Public },
	{ "textChanged()", &slot_7, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"valueChanged", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "valueText", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"valueChanged", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "valueChanged(int)", &signal_0, QMetaData::Public },
	{ "valueChanged(const QString&)", &signal_1, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[11] = {
 	{ "QString","text", 0x3000001, &QSpinBox::metaObj, 0, -1 },
	{ "QString","prefix", 0x3000103, &QSpinBox::metaObj, 0, -1 },
	{ "QString","suffix", 0x3000103, &QSpinBox::metaObj, 0, -1 },
	{ "QString","cleanText", 0x3000001, &QSpinBox::metaObj, 0, -1 },
	{ "QString","specialValueText", 0x3000103, &QSpinBox::metaObj, 0, -1 },
	{ "bool","wrapping", 0x12000103, &QSpinBox::metaObj, 0, -1 },
	{ "ButtonSymbols","buttonSymbols", 0x0107, &QSpinBox::metaObj, &enum_tbl[0], -1 },
	{ "int","maxValue", 0x10000103, &QSpinBox::metaObj, 0, -1 },
	{ "int","minValue", 0x10000103, &QSpinBox::metaObj, 0, -1 },
	{ "int","lineStep", 0x10000103, &QSpinBox::metaObj, 0, -1 },
	{ "int","value", 0x10000103, &QSpinBox::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QSpinBox", parentObject,
	slot_tbl, 8,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	props_tbl, 11,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSpinBox.setMetaObject( metaObj );
    return metaObj;
}

void* QSpinBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSpinBox" ) )
	return this;
    if ( !qstrcmp( clname, "QRangeControl" ) )
	return (QRangeControl*)this;
    return QWidget::qt_cast( clname );
}

// SIGNAL valueChanged
void QSpinBox::valueChanged( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL valueChanged
void QSpinBox::valueChanged( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

bool QSpinBox::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setValue((int)static_QUType_int.get(_o+1)); break;
    case 1: setPrefix((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: setSuffix((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: stepUp(); break;
    case 4: stepDown(); break;
    case 5: setEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 6: selectAll(); break;
    case 7: textChanged(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSpinBox::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: valueChanged((int)static_QUType_int.get(_o+1)); break;
    case 1: valueChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QSpinBox::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 1: *v = QVariant( this->text() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setPrefix(v->asString()); break;
	case 1: *v = QVariant( this->prefix() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setSuffix(v->asString()); break;
	case 1: *v = QVariant( this->suffix() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 1: *v = QVariant( this->cleanText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setSpecialValueText(v->asString()); break;
	case 1: *v = QVariant( this->specialValueText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setWrapping(v->asBool()); break;
	case 1: *v = QVariant( this->wrapping(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setButtonSymbols((ButtonSymbols&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->buttonSymbols() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setMaxValue(v->asInt()); break;
	case 1: *v = QVariant( this->maxValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setMinValue(v->asInt()); break;
	case 1: *v = QVariant( this->minValue() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setLineStep(v->asInt()); break;
	case 1: *v = QVariant( this->lineStep() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 0: setValue(v->asInt()); break;
	case 1: *v = QVariant( this->value() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QSpinBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSplashScreen::className() const
{
    return "QSplashScreen";
}

QMetaObject *QSplashScreen::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSplashScreen( "QSplashScreen", &QSplashScreen::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSplashScreen::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSplashScreen", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSplashScreen::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSplashScreen", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSplashScreen::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"message", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In },
	{ "flags", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"message", 2, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In },
	{ "flags", &static_QUType_int, 0, QUParameter::In },
	{ "color", &static_QUType_varptr, "\x0a", QUParameter::In }
    };
    static const QUMethod slot_2 = {"message", 3, param_slot_2 };
    static const QUMethod slot_3 = {"clear", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "message(const QString&)", &slot_0, QMetaData::Public },
	{ "message(const QString&,int)", &slot_1, QMetaData::Public },
	{ "message(const QString&,int,const QColor&)", &slot_2, QMetaData::Public },
	{ "clear()", &slot_3, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"messageChanged", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "messageChanged(const QString&)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSplashScreen", parentObject,
	slot_tbl, 4,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSplashScreen.setMetaObject( metaObj );
    return metaObj;
}

void* QSplashScreen::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSplashScreen" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL messageChanged
void QSplashScreen::messageChanged( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool QSplashScreen::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: message((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: message((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 2: message((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(const QColor&)*((const QColor*)static_QUType_ptr.get(_o+3))); break;
    case 3: clear(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSplashScreen::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: messageChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QSplashScreen::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QSplashScreen::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSplitter::className() const
{
    return "QSplitter";
}

QMetaObject *QSplitter::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSplitter( "QSplitter", &QSplitter::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSplitter::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSplitter", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSplitter::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSplitter", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSplitter::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[4] = {
 	{ "Orientation","orientation", 0x010f, &QSplitter::metaObj, 0, -1 },
	{ "bool","opaqueResize", 0x12000103, &QSplitter::metaObj, 0, -1 },
	{ "int","handleWidth", 0x10000103, &QSplitter::metaObj, 0, -1 },
	{ "bool","childrenCollapsible", 0x12000103, &QSplitter::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QSplitter", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 4,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSplitter.setMetaObject( metaObj );
    return metaObj;
}

void* QSplitter::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSplitter" ) )
	return this;
    return QFrame::qt_cast( clname );
}

bool QSplitter::qt_invoke( int _id, QUObject* _o )
{
    return QFrame::qt_invoke(_id,_o);
}

bool QSplitter::qt_emit( int _id, QUObject* _o )
{
    return QFrame::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSplitter::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setOrientation((Orientation&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->orientation() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setOpaqueResize(v->asBool()); break;
	case 1: *v = QVariant( this->opaqueResize(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setHandleWidth(v->asInt()); break;
	case 1: *v = QVariant( this->handleWidth() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setChildrenCollapsible(v->asBool()); break;
	case 1: *v = QVariant( this->childrenCollapsible(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QFrame::qt_property( id, f, v );
    }
    return TRUE;
}

bool QSplitter::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSqlResultShared::className() const
{
    return "QSqlResultShared";
}

QMetaObject *QSqlResultShared::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSqlResultShared( "QSqlResultShared", &QSqlResultShared::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSqlResultShared::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSqlResultShared", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSqlResultShared::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSqlResultShared", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSqlResultShared::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"slotResultDestroyed", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotResultDestroyed()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSqlResultShared", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSqlResultShared.setMetaObject( metaObj );
    return metaObj;
}

void* QSqlResultShared::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSqlResultShared" ) )
	return this;
    if ( !qstrcmp( clname, "QShared" ) )
	return (QShared*)this;
    return QObject::qt_cast( clname );
}

bool QSqlResultShared::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotResultDestroyed(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSqlResultShared::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSqlResultShared::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QSqlResultShared::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSqlDriverPlugin::className() const
{
    return "QSqlDriverPlugin";
}

QMetaObject *QSqlDriverPlugin::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSqlDriverPlugin( "QSqlDriverPlugin", &QSqlDriverPlugin::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSqlDriverPlugin::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSqlDriverPlugin", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSqlDriverPlugin::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSqlDriverPlugin", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSqlDriverPlugin::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGPlugin::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QSqlDriverPlugin", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSqlDriverPlugin.setMetaObject( metaObj );
    return metaObj;
}

void* QSqlDriverPlugin::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSqlDriverPlugin" ) )
	return this;
    return QGPlugin::qt_cast( clname );
}

bool QSqlDriverPlugin::qt_invoke( int _id, QUObject* _o )
{
    return QGPlugin::qt_invoke(_id,_o);
}

bool QSqlDriverPlugin::qt_emit( int _id, QUObject* _o )
{
    return QGPlugin::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSqlDriverPlugin::qt_property( int id, int f, QVariant* v)
{
    return QGPlugin::qt_property( id, f, v);
}

bool QSqlDriverPlugin::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSqlDriver::className() const
{
    return "QSqlDriver";
}

QMetaObject *QSqlDriver::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSqlDriver( "QSqlDriver", &QSqlDriver::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSqlDriver::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSqlDriver", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSqlDriver::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSqlDriver", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSqlDriver::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QSqlDriver", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSqlDriver.setMetaObject( metaObj );
    return metaObj;
}

void* QSqlDriver::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSqlDriver" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QSqlDriver::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QSqlDriver::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSqlDriver::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QSqlDriver::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSqlForm::className() const
{
    return "QSqlForm";
}

QMetaObject *QSqlForm::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSqlForm( "QSqlForm", &QSqlForm::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSqlForm::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSqlForm", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSqlForm::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSqlForm", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSqlForm::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "widget", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_0 = {"readField", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "widget", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_1 = {"writeField", 1, param_slot_1 };
    static const QUMethod slot_2 = {"readFields", 0, 0 };
    static const QUMethod slot_3 = {"writeFields", 0, 0 };
    static const QUMethod slot_4 = {"clear", 0, 0 };
    static const QUMethod slot_5 = {"clearValues", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "nullify", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"clearValues", 1, param_slot_6 };
    static const QMetaData slot_tbl[] = {
	{ "readField(QWidget*)", &slot_0, QMetaData::Public },
	{ "writeField(QWidget*)", &slot_1, QMetaData::Public },
	{ "readFields()", &slot_2, QMetaData::Public },
	{ "writeFields()", &slot_3, QMetaData::Public },
	{ "clear()", &slot_4, QMetaData::Public },
	{ "clearValues()", &slot_5, QMetaData::Public },
	{ "clearValues(bool)", &slot_6, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QSqlForm", parentObject,
	slot_tbl, 7,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSqlForm.setMetaObject( metaObj );
    return metaObj;
}

void* QSqlForm::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSqlForm" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QSqlForm::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: readField((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 1: writeField((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 2: readFields(); break;
    case 3: writeFields(); break;
    case 4: clear(); break;
    case 5: clearValues(); break;
    case 6: clearValues((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QSqlForm::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSqlForm::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QSqlForm::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTable::className() const
{
    return "QTable";
}

QMetaObject *QTable::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTable( "QTable", &QTable::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTable::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTable", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTable::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTable", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTable::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QScrollView::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "Single",  (int) QTable::Single },
	{ "Multi",  (int) QTable::Multi },
	{ "SingleRow",  (int) QTable::SingleRow },
	{ "MultiRow",  (int) QTable::MultiRow },
	{ "NoSelection",  (int) QTable::NoSelection }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "FollowStyle",  (int) QTable::FollowStyle },
	{ "SpreadSheet",  (int) QTable::SpreadSheet }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "SelectionMode", 5, enum_0, FALSE },
	{ "FocusStyle", 2, enum_1, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "r", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setNumRows", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "r", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setNumCols", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setShowGrid", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"hideRow", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"hideColumn", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"showRow", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"showColumn", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "row", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"isRowHidden", 2, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"isColumnHidden", 2, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "w", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"setColumnWidth", 2, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "h", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"setRowHeight", 2, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"adjustColumn", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"adjustRow", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "stretch", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"setColumnStretchable", 2, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "stretch", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"setRowStretchable", 2, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"isColumnStretchable", 2, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "row", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"isRowStretchable", 2, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"setSorting", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ "row1", &static_QUType_int, 0, QUParameter::In },
	{ "row2", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"swapRows", 2, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ "row1", &static_QUType_int, 0, QUParameter::In },
	{ "row2", &static_QUType_int, 0, QUParameter::In },
	{ "swapHeader", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"swapRows", 3, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ "col1", &static_QUType_int, 0, QUParameter::In },
	{ "col2", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_20 = {"swapColumns", 2, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ "col1", &static_QUType_int, 0, QUParameter::In },
	{ "col2", &static_QUType_int, 0, QUParameter::In },
	{ "swapHeader", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"swapColumns", 3, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ "row1", &static_QUType_int, 0, QUParameter::In },
	{ "col1", &static_QUType_int, 0, QUParameter::In },
	{ "row2", &static_QUType_int, 0, QUParameter::In },
	{ "col2", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_22 = {"swapCells", 4, param_slot_22 };
    static const QUParameter param_slot_23[] = {
	{ "m", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_23 = {"setLeftMargin", 1, param_slot_23 };
    static const QUParameter param_slot_24[] = {
	{ "m", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_24 = {"setTopMargin", 1, param_slot_24 };
    static const QUParameter param_slot_25[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_25 = {"setCurrentCell", 2, param_slot_25 };
    static const QUMethod slot_26 = {"clearSelection", 0, 0 };
    static const QUParameter param_slot_27[] = {
	{ "repaint", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_27 = {"clearSelection", 1, param_slot_27 };
    static const QUParameter param_slot_28[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_28 = {"setColumnMovingEnabled", 1, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"setRowMovingEnabled", 1, param_slot_29 };
    static const QUParameter param_slot_30[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_30 = {"setReadOnly", 1, param_slot_30 };
    static const QUParameter param_slot_31[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "ro", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_31 = {"setRowReadOnly", 2, param_slot_31 };
    static const QUParameter param_slot_32[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "ro", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"setColumnReadOnly", 2, param_slot_32 };
    static const QUParameter param_slot_33[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_33 = {"setDragEnabled", 1, param_slot_33 };
    static const QUParameter param_slot_34[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out }
    };
    static const QUMethod slot_34 = {"dragEnabled", 1, param_slot_34 };
    static const QUParameter param_slot_35[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_35 = {"insertRows", 1, param_slot_35 };
    static const QUParameter param_slot_36[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "count", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_36 = {"insertRows", 2, param_slot_36 };
    static const QUParameter param_slot_37[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_37 = {"insertColumns", 1, param_slot_37 };
    static const QUParameter param_slot_38[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "count", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_38 = {"insertColumns", 2, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_39 = {"removeRow", 1, param_slot_39 };
    static const QUParameter param_slot_40[] = {
	{ "rows", &static_QUType_ptr, "QMemArray<int>", QUParameter::In }
    };
    static const QUMethod slot_40 = {"removeRows", 1, param_slot_40 };
    static const QUParameter param_slot_41[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_41 = {"removeColumn", 1, param_slot_41 };
    static const QUParameter param_slot_42[] = {
	{ "cols", &static_QUType_ptr, "QMemArray<int>", QUParameter::In }
    };
    static const QUMethod slot_42 = {"removeColumns", 1, param_slot_42 };
    static const QUParameter param_slot_43[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_43 = {"editCell", 2, param_slot_43 };
    static const QUParameter param_slot_44[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "replace", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_44 = {"editCell", 3, param_slot_44 };
    static const QUParameter param_slot_45[] = {
	{ "labels", &static_QUType_varptr, "\x04", QUParameter::In }
    };
    static const QUMethod slot_45 = {"setRowLabels", 1, param_slot_45 };
    static const QUParameter param_slot_46[] = {
	{ "labels", &static_QUType_varptr, "\x04", QUParameter::In }
    };
    static const QUMethod slot_46 = {"setColumnLabels", 1, param_slot_46 };
    static const QUParameter param_slot_47[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_47 = {"columnWidthChanged", 1, param_slot_47 };
    static const QUParameter param_slot_48[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_48 = {"rowHeightChanged", 1, param_slot_48 };
    static const QUParameter param_slot_49[] = {
	{ "section", &static_QUType_int, 0, QUParameter::In },
	{ "fromIndex", &static_QUType_int, 0, QUParameter::In },
	{ "toIndex", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_49 = {"columnIndexChanged", 3, param_slot_49 };
    static const QUParameter param_slot_50[] = {
	{ "section", &static_QUType_int, 0, QUParameter::In },
	{ "fromIndex", &static_QUType_int, 0, QUParameter::In },
	{ "toIndex", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_50 = {"rowIndexChanged", 3, param_slot_50 };
    static const QUParameter param_slot_51[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_51 = {"columnClicked", 1, param_slot_51 };
    static const QUMethod slot_52 = {"doAutoScroll", 0, 0 };
    static const QUMethod slot_53 = {"doValueChanged", 0, 0 };
    static const QUMethod slot_54 = {"updateGeometriesSlot", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setNumRows(int)", &slot_0, QMetaData::Public },
	{ "setNumCols(int)", &slot_1, QMetaData::Public },
	{ "setShowGrid(bool)", &slot_2, QMetaData::Public },
	{ "hideRow(int)", &slot_3, QMetaData::Public },
	{ "hideColumn(int)", &slot_4, QMetaData::Public },
	{ "showRow(int)", &slot_5, QMetaData::Public },
	{ "showColumn(int)", &slot_6, QMetaData::Public },
	{ "isRowHidden(int)", &slot_7, QMetaData::Public },
	{ "isColumnHidden(int)", &slot_8, QMetaData::Public },
	{ "setColumnWidth(int,int)", &slot_9, QMetaData::Public },
	{ "setRowHeight(int,int)", &slot_10, QMetaData::Public },
	{ "adjustColumn(int)", &slot_11, QMetaData::Public },
	{ "adjustRow(int)", &slot_12, QMetaData::Public },
	{ "setColumnStretchable(int,bool)", &slot_13, QMetaData::Public },
	{ "setRowStretchable(int,bool)", &slot_14, QMetaData::Public },
	{ "isColumnStretchable(int)", &slot_15, QMetaData::Public },
	{ "isRowStretchable(int)", &slot_16, QMetaData::Public },
	{ "setSorting(bool)", &slot_17, QMetaData::Public },
	{ "swapRows(int,int)", &slot_18, QMetaData::Public },
	{ "swapRows(int,int,bool)", &slot_19, QMetaData::Public },
	{ "swapColumns(int,int)", &slot_20, QMetaData::Public },
	{ "swapColumns(int,int,bool)", &slot_21, QMetaData::Public },
	{ "swapCells(int,int,int,int)", &slot_22, QMetaData::Public },
	{ "setLeftMargin(int)", &slot_23, QMetaData::Public },
	{ "setTopMargin(int)", &slot_24, QMetaData::Public },
	{ "setCurrentCell(int,int)", &slot_25, QMetaData::Public },
	{ "clearSelection()", &slot_26, QMetaData::Public },
	{ "clearSelection(bool)", &slot_27, QMetaData::Public },
	{ "setColumnMovingEnabled(bool)", &slot_28, QMetaData::Public },
	{ "setRowMovingEnabled(bool)", &slot_29, QMetaData::Public },
	{ "setReadOnly(bool)", &slot_30, QMetaData::Public },
	{ "setRowReadOnly(int,bool)", &slot_31, QMetaData::Public },
	{ "setColumnReadOnly(int,bool)", &slot_32, QMetaData::Public },
	{ "setDragEnabled(bool)", &slot_33, QMetaData::Public },
	{ "dragEnabled()", &slot_34, QMetaData::Public },
	{ "insertRows(int)", &slot_35, QMetaData::Public },
	{ "insertRows(int,int)", &slot_36, QMetaData::Public },
	{ "insertColumns(int)", &slot_37, QMetaData::Public },
	{ "insertColumns(int,int)", &slot_38, QMetaData::Public },
	{ "removeRow(int)", &slot_39, QMetaData::Public },
	{ "removeRows(const QMemArray<int>&)", &slot_40, QMetaData::Public },
	{ "removeColumn(int)", &slot_41, QMetaData::Public },
	{ "removeColumns(const QMemArray<int>&)", &slot_42, QMetaData::Public },
	{ "editCell(int,int)", &slot_43, QMetaData::Public },
	{ "editCell(int,int,bool)", &slot_44, QMetaData::Public },
	{ "setRowLabels(const QStringList&)", &slot_45, QMetaData::Public },
	{ "setColumnLabels(const QStringList&)", &slot_46, QMetaData::Public },
	{ "columnWidthChanged(int)", &slot_47, QMetaData::Protected },
	{ "rowHeightChanged(int)", &slot_48, QMetaData::Protected },
	{ "columnIndexChanged(int,int,int)", &slot_49, QMetaData::Protected },
	{ "rowIndexChanged(int,int,int)", &slot_50, QMetaData::Protected },
	{ "columnClicked(int)", &slot_51, QMetaData::Protected },
	{ "doAutoScroll()", &slot_52, QMetaData::Private },
	{ "doValueChanged()", &slot_53, QMetaData::Private },
	{ "updateGeometriesSlot()", &slot_54, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"currentChanged", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "button", &static_QUType_int, 0, QUParameter::In },
	{ "mousePos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_1 = {"clicked", 4, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "button", &static_QUType_int, 0, QUParameter::In },
	{ "mousePos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_2 = {"doubleClicked", 4, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "button", &static_QUType_int, 0, QUParameter::In },
	{ "mousePos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_3 = {"pressed", 4, param_signal_3 };
    static const QUMethod signal_4 = {"selectionChanged", 0, 0 };
    static const QUParameter param_signal_5[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_5 = {"valueChanged", 2, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_6 = {"contextMenuRequested", 3, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ "e", &static_QUType_ptr, "QDropEvent", QUParameter::In }
    };
    static const QUMethod signal_7 = {"dropped", 1, param_signal_7 };
    static const QMetaData signal_tbl[] = {
	{ "currentChanged(int,int)", &signal_0, QMetaData::Protected },
	{ "clicked(int,int,int,const QPoint&)", &signal_1, QMetaData::Protected },
	{ "doubleClicked(int,int,int,const QPoint&)", &signal_2, QMetaData::Protected },
	{ "pressed(int,int,int,const QPoint&)", &signal_3, QMetaData::Protected },
	{ "selectionChanged()", &signal_4, QMetaData::Protected },
	{ "valueChanged(int,int)", &signal_5, QMetaData::Protected },
	{ "contextMenuRequested(int,int,const QPoint&)", &signal_6, QMetaData::Protected },
	{ "dropped(QDropEvent*)", &signal_7, QMetaData::Protected }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[10] = {
 	{ "int","numRows", 0x10000103, &QTable::metaObj, 0, -1 },
	{ "int","numCols", 0x10000103, &QTable::metaObj, 0, -1 },
	{ "bool","showGrid", 0x12000103, &QTable::metaObj, 0, -1 },
	{ "bool","rowMovingEnabled", 0x12000103, &QTable::metaObj, 0, -1 },
	{ "bool","columnMovingEnabled", 0x12000103, &QTable::metaObj, 0, -1 },
	{ "bool","readOnly", 0x12000103, &QTable::metaObj, 0, -1 },
	{ "bool","sorting", 0x12000103, &QTable::metaObj, 0, -1 },
	{ "SelectionMode","selectionMode", 0x0107, &QTable::metaObj, &enum_tbl[0], -1 },
	{ "FocusStyle","focusStyle", 0x0107, &QTable::metaObj, &enum_tbl[1], -1 },
	{ "int","numSelections", 0x10000001, &QTable::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QTable", parentObject,
	slot_tbl, 55,
	signal_tbl, 8,
#ifndef QT_NO_PROPERTIES
	props_tbl, 10,
	enum_tbl, 2,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTable.setMetaObject( metaObj );
    return metaObj;
}

void* QTable::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTable" ) )
	return this;
    return QScrollView::qt_cast( clname );
}

// SIGNAL currentChanged
void QTable::currentChanged( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL clicked
void QTable::clicked( int t0, int t1, int t2, const QPoint& t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    static_QUType_varptr.set(o+4,&t3);
    activate_signal( clist, o );
}

// SIGNAL doubleClicked
void QTable::doubleClicked( int t0, int t1, int t2, const QPoint& t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    static_QUType_varptr.set(o+4,&t3);
    activate_signal( clist, o );
}

// SIGNAL pressed
void QTable::pressed( int t0, int t1, int t2, const QPoint& t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_int.set(o+3,t2);
    static_QUType_varptr.set(o+4,&t3);
    activate_signal( clist, o );
}

// SIGNAL selectionChanged
void QTable::selectionChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL valueChanged
void QTable::valueChanged( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL contextMenuRequested
void QTable::contextMenuRequested( int t0, int t1, const QPoint& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_varptr.set(o+3,&t2);
    activate_signal( clist, o );
}

// SIGNAL dropped
void QTable::dropped( QDropEvent* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QTable::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setNumRows((int)static_QUType_int.get(_o+1)); break;
    case 1: setNumCols((int)static_QUType_int.get(_o+1)); break;
    case 2: setShowGrid((bool)static_QUType_bool.get(_o+1)); break;
    case 3: hideRow((int)static_QUType_int.get(_o+1)); break;
    case 4: hideColumn((int)static_QUType_int.get(_o+1)); break;
    case 5: showRow((int)static_QUType_int.get(_o+1)); break;
    case 6: showColumn((int)static_QUType_int.get(_o+1)); break;
    case 7: static_QUType_bool.set(_o,isRowHidden((int)static_QUType_int.get(_o+1))); break;
    case 8: static_QUType_bool.set(_o,isColumnHidden((int)static_QUType_int.get(_o+1))); break;
    case 9: setColumnWidth((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 10: setRowHeight((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 11: adjustColumn((int)static_QUType_int.get(_o+1)); break;
    case 12: adjustRow((int)static_QUType_int.get(_o+1)); break;
    case 13: setColumnStretchable((int)static_QUType_int.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 14: setRowStretchable((int)static_QUType_int.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 15: static_QUType_bool.set(_o,isColumnStretchable((int)static_QUType_int.get(_o+1))); break;
    case 16: static_QUType_bool.set(_o,isRowStretchable((int)static_QUType_int.get(_o+1))); break;
    case 17: setSorting((bool)static_QUType_bool.get(_o+1)); break;
    case 18: swapRows((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 19: swapRows((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(bool)static_QUType_bool.get(_o+3)); break;
    case 20: swapColumns((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 21: swapColumns((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(bool)static_QUType_bool.get(_o+3)); break;
    case 22: swapCells((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4)); break;
    case 23: setLeftMargin((int)static_QUType_int.get(_o+1)); break;
    case 24: setTopMargin((int)static_QUType_int.get(_o+1)); break;
    case 25: setCurrentCell((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 26: clearSelection(); break;
    case 27: clearSelection((bool)static_QUType_bool.get(_o+1)); break;
    case 28: setColumnMovingEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 29: setRowMovingEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 30: setReadOnly((bool)static_QUType_bool.get(_o+1)); break;
    case 31: setRowReadOnly((int)static_QUType_int.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 32: setColumnReadOnly((int)static_QUType_int.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 33: setDragEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 34: static_QUType_bool.set(_o,dragEnabled()); break;
    case 35: insertRows((int)static_QUType_int.get(_o+1)); break;
    case 36: insertRows((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 37: insertColumns((int)static_QUType_int.get(_o+1)); break;
    case 38: insertColumns((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 39: removeRow((int)static_QUType_int.get(_o+1)); break;
    case 40: removeRows((const QMemArray<int>&)*((const QMemArray<int>*)static_QUType_ptr.get(_o+1))); break;
    case 41: removeColumn((int)static_QUType_int.get(_o+1)); break;
    case 42: removeColumns((const QMemArray<int>&)*((const QMemArray<int>*)static_QUType_ptr.get(_o+1))); break;
    case 43: editCell((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 44: editCell((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(bool)static_QUType_bool.get(_o+3)); break;
    case 45: setRowLabels((const QStringList&)*((const QStringList*)static_QUType_ptr.get(_o+1))); break;
    case 46: setColumnLabels((const QStringList&)*((const QStringList*)static_QUType_ptr.get(_o+1))); break;
    case 47: columnWidthChanged((int)static_QUType_int.get(_o+1)); break;
    case 48: rowHeightChanged((int)static_QUType_int.get(_o+1)); break;
    case 49: columnIndexChanged((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 50: rowIndexChanged((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 51: columnClicked((int)static_QUType_int.get(_o+1)); break;
    case 52: doAutoScroll(); break;
    case 53: doValueChanged(); break;
    case 54: updateGeometriesSlot(); break;
    default:
	return QScrollView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QTable::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: currentChanged((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 1: clicked((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 2: doubleClicked((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 3: pressed((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 4: selectionChanged(); break;
    case 5: valueChanged((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 6: contextMenuRequested((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+3))); break;
    case 7: dropped((QDropEvent*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QScrollView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QTable::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setNumRows(v->asInt()); break;
	case 1: *v = QVariant( this->numRows() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setNumCols(v->asInt()); break;
	case 1: *v = QVariant( this->numCols() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setShowGrid(v->asBool()); break;
	case 1: *v = QVariant( this->showGrid(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setRowMovingEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->rowMovingEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setColumnMovingEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->columnMovingEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setReadOnly(v->asBool()); break;
	case 1: *v = QVariant( this->isReadOnly(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setSorting(v->asBool()); break;
	case 1: *v = QVariant( this->sorting(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setSelectionMode((SelectionMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->selectionMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setFocusStyle((FocusStyle&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->focusStyle() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 1: *v = QVariant( this->numSelections() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QScrollView::qt_property( id, f, v );
    }
    return TRUE;
}

bool QTable::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QSqlDatabase::className() const
{
    return "QSqlDatabase";
}

QMetaObject *QSqlDatabase::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QSqlDatabase( "QSqlDatabase", &QSqlDatabase::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QSqlDatabase::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSqlDatabase", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QSqlDatabase::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QSqlDatabase", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QSqlDatabase::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[6] = {
 	{ "QString","databaseName", 0x3000103, &QSqlDatabase::metaObj, 0, -1 },
	{ "QString","userName", 0x3000103, &QSqlDatabase::metaObj, 0, -1 },
	{ "QString","password", 0x3000103, &QSqlDatabase::metaObj, 0, -1 },
	{ "QString","hostName", 0x3000103, &QSqlDatabase::metaObj, 0, -1 },
	{ "int","port", 0x10000103, &QSqlDatabase::metaObj, 0, -1 },
	{ "QString","connectOptions", 0x3000103, &QSqlDatabase::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QSqlDatabase", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 6,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QSqlDatabase.setMetaObject( metaObj );
    return metaObj;
}

void* QSqlDatabase::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QSqlDatabase" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QSqlDatabase::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QSqlDatabase::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QSqlDatabase::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setDatabaseName(v->asString()); break;
	case 1: *v = QVariant( this->databaseName() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setUserName(v->asString()); break;
	case 1: *v = QVariant( this->userName() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setPassword(v->asString()); break;
	case 1: *v = QVariant( this->password() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setHostName(v->asString()); break;
	case 1: *v = QVariant( this->hostName() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setPort(v->asInt()); break;
	case 1: *v = QVariant( this->port() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setConnectOptions(v->asString()); break;
	case 1: *v = QVariant( this->connectOptions() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QObject::qt_property( id, f, v );
    }
    return TRUE;
}

bool QSqlDatabase::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDataBrowser::className() const
{
    return "QDataBrowser";
}

QMetaObject *QDataBrowser::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDataBrowser( "QDataBrowser", &QDataBrowser::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDataBrowser::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDataBrowser", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDataBrowser::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDataBrowser", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDataBrowser::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"refresh", 0, 0 };
    static const QUMethod slot_1 = {"insert", 0, 0 };
    static const QUMethod slot_2 = {"update", 0, 0 };
    static const QUMethod slot_3 = {"del", 0, 0 };
    static const QUMethod slot_4 = {"first", 0, 0 };
    static const QUMethod slot_5 = {"last", 0, 0 };
    static const QUMethod slot_6 = {"next", 0, 0 };
    static const QUMethod slot_7 = {"prev", 0, 0 };
    static const QUMethod slot_8 = {"readFields", 0, 0 };
    static const QUMethod slot_9 = {"writeFields", 0, 0 };
    static const QUMethod slot_10 = {"clearValues", 0, 0 };
    static const QUMethod slot_11 = {"updateBoundary", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "refresh()", &slot_0, QMetaData::Public },
	{ "insert()", &slot_1, QMetaData::Public },
	{ "update()", &slot_2, QMetaData::Public },
	{ "del()", &slot_3, QMetaData::Public },
	{ "first()", &slot_4, QMetaData::Public },
	{ "last()", &slot_5, QMetaData::Public },
	{ "next()", &slot_6, QMetaData::Public },
	{ "prev()", &slot_7, QMetaData::Public },
	{ "readFields()", &slot_8, QMetaData::Public },
	{ "writeFields()", &slot_9, QMetaData::Public },
	{ "clearValues()", &slot_10, QMetaData::Public },
	{ "updateBoundary()", &slot_11, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "available", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"firstRecordAvailable", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "available", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"lastRecordAvailable", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "available", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"nextRecordAvailable", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ "available", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"prevRecordAvailable", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ "record", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_4 = {"currentChanged", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_5 = {"primeInsert", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_6 = {"primeUpdate", 1, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_7 = {"primeDelete", 1, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_8 = {"beforeInsert", 1, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_9 = {"beforeUpdate", 1, param_signal_9 };
    static const QUParameter param_signal_10[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_10 = {"beforeDelete", 1, param_signal_10 };
    static const QUParameter param_signal_11[] = {
	{ "mode", &static_QUType_ptr, "QSqlCursor::Mode", QUParameter::In }
    };
    static const QUMethod signal_11 = {"cursorChanged", 1, param_signal_11 };
    static const QMetaData signal_tbl[] = {
	{ "firstRecordAvailable(bool)", &signal_0, QMetaData::Public },
	{ "lastRecordAvailable(bool)", &signal_1, QMetaData::Public },
	{ "nextRecordAvailable(bool)", &signal_2, QMetaData::Public },
	{ "prevRecordAvailable(bool)", &signal_3, QMetaData::Public },
	{ "currentChanged(const QSqlRecord*)", &signal_4, QMetaData::Public },
	{ "primeInsert(QSqlRecord*)", &signal_5, QMetaData::Public },
	{ "primeUpdate(QSqlRecord*)", &signal_6, QMetaData::Public },
	{ "primeDelete(QSqlRecord*)", &signal_7, QMetaData::Public },
	{ "beforeInsert(QSqlRecord*)", &signal_8, QMetaData::Public },
	{ "beforeUpdate(QSqlRecord*)", &signal_9, QMetaData::Public },
	{ "beforeDelete(QSqlRecord*)", &signal_10, QMetaData::Public },
	{ "cursorChanged(QSqlCursor::Mode)", &signal_11, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[10] = {
 	{ "bool","boundaryChecking", 0x12000103, &QDataBrowser::metaObj, 0, -1 },
	{ "QString","filter", 0x3000103, &QDataBrowser::metaObj, 0, -1 },
	{ "QStringList","sort", 0x4000103, &QDataBrowser::metaObj, 0, -1 },
	{ "bool","confirmEdits", 0x12000103, &QDataBrowser::metaObj, 0, -1 },
	{ "bool","confirmInsert", 0x12000103, &QDataBrowser::metaObj, 0, -1 },
	{ "bool","confirmUpdate", 0x12000103, &QDataBrowser::metaObj, 0, -1 },
	{ "bool","confirmDelete", 0x12000103, &QDataBrowser::metaObj, 0, -1 },
	{ "bool","confirmCancels", 0x12000103, &QDataBrowser::metaObj, 0, -1 },
	{ "bool","readOnly", 0x12000103, &QDataBrowser::metaObj, 0, -1 },
	{ "bool","autoEdit", 0x12000103, &QDataBrowser::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QDataBrowser", parentObject,
	slot_tbl, 12,
	signal_tbl, 12,
#ifndef QT_NO_PROPERTIES
	props_tbl, 10,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDataBrowser.setMetaObject( metaObj );
    return metaObj;
}

void* QDataBrowser::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDataBrowser" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL firstRecordAvailable
void QDataBrowser::firstRecordAvailable( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL lastRecordAvailable
void QDataBrowser::lastRecordAvailable( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL nextRecordAvailable
void QDataBrowser::nextRecordAvailable( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL prevRecordAvailable
void QDataBrowser::prevRecordAvailable( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 3, t0 );
}

// SIGNAL currentChanged
void QDataBrowser::currentChanged( const QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL primeInsert
void QDataBrowser::primeInsert( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL primeUpdate
void QDataBrowser::primeUpdate( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL primeDelete
void QDataBrowser::primeDelete( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL beforeInsert
void QDataBrowser::beforeInsert( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL beforeUpdate
void QDataBrowser::beforeUpdate( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL beforeDelete
void QDataBrowser::beforeDelete( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 10 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL cursorChanged
void QDataBrowser::cursorChanged( QSqlCursor::Mode t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 11 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool QDataBrowser::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: refresh(); break;
    case 1: insert(); break;
    case 2: update(); break;
    case 3: del(); break;
    case 4: first(); break;
    case 5: last(); break;
    case 6: next(); break;
    case 7: prev(); break;
    case 8: readFields(); break;
    case 9: writeFields(); break;
    case 10: clearValues(); break;
    case 11: updateBoundary(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDataBrowser::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: firstRecordAvailable((bool)static_QUType_bool.get(_o+1)); break;
    case 1: lastRecordAvailable((bool)static_QUType_bool.get(_o+1)); break;
    case 2: nextRecordAvailable((bool)static_QUType_bool.get(_o+1)); break;
    case 3: prevRecordAvailable((bool)static_QUType_bool.get(_o+1)); break;
    case 4: currentChanged((const QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 5: primeInsert((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 6: primeUpdate((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 7: primeDelete((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 8: beforeInsert((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 9: beforeUpdate((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 10: beforeDelete((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 11: cursorChanged((QSqlCursor::Mode)(*((QSqlCursor::Mode*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QDataBrowser::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setBoundaryChecking(v->asBool()); break;
	case 1: *v = QVariant( this->boundaryChecking(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setFilter(v->asString()); break;
	case 1: *v = QVariant( this->filter() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setSort(v->asStringList()); break;
	case 1: *v = QVariant( this->sort() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setConfirmEdits(v->asBool()); break;
	case 1: *v = QVariant( this->confirmEdits(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setConfirmInsert(v->asBool()); break;
	case 1: *v = QVariant( this->confirmInsert(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setConfirmUpdate(v->asBool()); break;
	case 1: *v = QVariant( this->confirmUpdate(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setConfirmDelete(v->asBool()); break;
	case 1: *v = QVariant( this->confirmDelete(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setConfirmCancels(v->asBool()); break;
	case 1: *v = QVariant( this->confirmCancels(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setReadOnly(v->asBool()); break;
	case 1: *v = QVariant( this->isReadOnly(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setAutoEdit(v->asBool()); break;
	case 1: *v = QVariant( this->autoEdit(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QDataBrowser::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QStatusBar::className() const
{
    return "QStatusBar";
}

QMetaObject *QStatusBar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QStatusBar( "QStatusBar", &QStatusBar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QStatusBar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QStatusBar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QStatusBar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QStatusBar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QStatusBar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"message", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"message", 2, param_slot_1 };
    static const QUMethod slot_2 = {"clear", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "message(const QString&)", &slot_0, QMetaData::Public },
	{ "message(const QString&,int)", &slot_1, QMetaData::Public },
	{ "clear()", &slot_2, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"messageChanged", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "messageChanged(const QString&)", &signal_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[1] = {
 	{ "bool","sizeGripEnabled", 0x12000103, &QStatusBar::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QStatusBar", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	props_tbl, 1,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QStatusBar.setMetaObject( metaObj );
    return metaObj;
}

void* QStatusBar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QStatusBar" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL messageChanged
void QStatusBar::messageChanged( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool QStatusBar::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: message((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: message((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 2: clear(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QStatusBar::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: messageChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QStatusBar::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setSizeGripEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isSizeGripEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QStatusBar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QMenuBar::className() const
{
    return "QMenuBar";
}

QMetaObject *QMenuBar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMenuBar( "QMenuBar", &QMenuBar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMenuBar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMenuBar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMenuBar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMenuBar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMenuBar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "Never",  (int) QMenuBar::Never },
	{ "InWindowsStyle",  (int) QMenuBar::InWindowsStyle }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "Separator", 2, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"subActivated", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"subHighlighted", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"accelActivated", 1, param_slot_2 };
    static const QUMethod slot_3 = {"accelDestroyed", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_4 = {"popupDestroyed", 1, param_slot_4 };
    static const QUMethod slot_5 = {"performDelayedChanges", 0, 0 };
    static const QUMethod slot_6 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "subActivated(int)", &slot_0, QMetaData::Private },
	{ "subHighlighted(int)", &slot_1, QMetaData::Private },
	{ "accelActivated(int)", &slot_2, QMetaData::Private },
	{ "accelDestroyed()", &slot_3, QMetaData::Private },
	{ "popupDestroyed(QObject*)", &slot_4, QMetaData::Private },
	{ "performDelayedChanges()", &slot_5, QMetaData::Private },
	{ "languageChange()", &slot_6, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"activated", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "itemId", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"highlighted", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "activated(int)", &signal_0, QMetaData::Public },
	{ "highlighted(int)", &signal_1, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[2] = {
 	{ "Separator","separator", 0x1107, &QMenuBar::metaObj, &enum_tbl[0], -1 },
	{ "bool","defaultUp", 0x12000103, &QMenuBar::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QMenuBar", parentObject,
	slot_tbl, 7,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	props_tbl, 2,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMenuBar.setMetaObject( metaObj );
    return metaObj;
}

void* QMenuBar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMenuBar" ) )
	return this;
    if ( !qstrcmp( clname, "QMenuData" ) )
	return (QMenuData*)this;
    return QFrame::qt_cast( clname );
}

// SIGNAL activated
void QMenuBar::activated( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL highlighted
void QMenuBar::highlighted( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

bool QMenuBar::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: subActivated((int)static_QUType_int.get(_o+1)); break;
    case 1: subHighlighted((int)static_QUType_int.get(_o+1)); break;
    case 2: accelActivated((int)static_QUType_int.get(_o+1)); break;
    case 3: accelDestroyed(); break;
    case 4: popupDestroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    case 5: performDelayedChanges(); break;
    case 6: languageChange(); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QMenuBar::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: activated((int)static_QUType_int.get(_o+1)); break;
    case 1: highlighted((int)static_QUType_int.get(_o+1)); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QMenuBar::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setSeparator((Separator&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->separator() ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setDefaultUp(v->asBool()); break;
	case 1: *v = QVariant( this->isDefaultUp(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QFrame::qt_property( id, f, v );
    }
    return TRUE;
}

bool QMenuBar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QCanvas::className() const
{
    return "QCanvas";
}

QMetaObject *QCanvas::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCanvas( "QCanvas", &QCanvas::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCanvas::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCanvas", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCanvas::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCanvas", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCanvas::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"advance", 0, 0 };
    static const QUMethod slot_1 = {"update", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "advance()", &slot_0, QMetaData::Public },
	{ "update()", &slot_1, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"resized", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "resized()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCanvas", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCanvas.setMetaObject( metaObj );
    return metaObj;
}

void* QCanvas::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCanvas" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL resized
void QCanvas::resized()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool QCanvas::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: advance(); break;
    case 1: update(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCanvas::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: resized(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCanvas::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QCanvas::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QCanvasView::className() const
{
    return "QCanvasView";
}

QMetaObject *QCanvasView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCanvasView( "QCanvasView", &QCanvasView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCanvasView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCanvasView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCanvasView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCanvasView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCanvasView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QScrollView::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"cMoving", 2, param_slot_0 };
    static const QUMethod slot_1 = {"updateContentsSize", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "cMoving(int,int)", &slot_0, QMetaData::Private },
	{ "updateContentsSize()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCanvasView", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCanvasView.setMetaObject( metaObj );
    return metaObj;
}

void* QCanvasView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCanvasView" ) )
	return this;
    return QScrollView::qt_cast( clname );
}

bool QCanvasView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: cMoving((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 1: updateContentsSize(); break;
    default:
	return QScrollView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCanvasView::qt_emit( int _id, QUObject* _o )
{
    return QScrollView::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCanvasView::qt_property( int id, int f, QVariant* v)
{
    return QScrollView::qt_property( id, f, v);
}

bool QCanvasView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTranslator::className() const
{
    return "QTranslator";
}

QMetaObject *QTranslator::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTranslator( "QTranslator", &QTranslator::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTranslator::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTranslator", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTranslator::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTranslator", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTranslator::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QTranslator", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTranslator.setMetaObject( metaObj );
    return metaObj;
}

void* QTranslator::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTranslator" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QTranslator::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QTranslator::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QTranslator::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QTranslator::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QStylePlugin::className() const
{
    return "QStylePlugin";
}

QMetaObject *QStylePlugin::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QStylePlugin( "QStylePlugin", &QStylePlugin::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QStylePlugin::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QStylePlugin", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QStylePlugin::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QStylePlugin", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QStylePlugin::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGPlugin::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QStylePlugin", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QStylePlugin.setMetaObject( metaObj );
    return metaObj;
}

void* QStylePlugin::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QStylePlugin" ) )
	return this;
    return QGPlugin::qt_cast( clname );
}

bool QStylePlugin::qt_invoke( int _id, QUObject* _o )
{
    return QGPlugin::qt_invoke(_id,_o);
}

bool QStylePlugin::qt_emit( int _id, QUObject* _o )
{
    return QGPlugin::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QStylePlugin::qt_property( int id, int f, QVariant* v)
{
    return QGPlugin::qt_property( id, f, v);
}

bool QStylePlugin::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTextEdit::className() const
{
    return "QTextEdit";
}

QMetaObject *QTextEdit::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTextEdit( "QTextEdit", &QTextEdit::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTextEdit::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextEdit", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTextEdit::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextEdit", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTextEdit::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QScrollView::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "NoWrap",  (int) QTextEdit::NoWrap },
	{ "WidgetWidth",  (int) QTextEdit::WidgetWidth },
	{ "FixedPixelWidth",  (int) QTextEdit::FixedPixelWidth },
	{ "FixedColumnWidth",  (int) QTextEdit::FixedColumnWidth }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "AtWordBoundary",  (int) QTextEdit::AtWordBoundary },
	{ "AtWhiteSpace",  (int) QTextEdit::AtWhiteSpace },
	{ "Anywhere",  (int) QTextEdit::Anywhere },
	{ "AtWordOrDocumentBoundary",  (int) QTextEdit::AtWordOrDocumentBoundary }
    };
    static const QMetaEnum::Item enum_2[] = {
	{ "AutoNone",  (int) QTextEdit::AutoNone },
	{ "AutoBulletList",  (int) QTextEdit::AutoBulletList },
	{ "AutoAll",  (int) QTextEdit::AutoAll }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "WordWrap", 4, enum_0, FALSE },
	{ "WrapPolicy", 4, enum_1, FALSE },
	{ "AutoFormatting", 3, enum_2, TRUE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setEnabled", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "factory", &static_QUType_ptr, "QMimeSourceFactory", QUParameter::In }
    };
    static const QUMethod slot_1 = {"setMimeSourceFactory", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "styleSheet", &static_QUType_ptr, "QStyleSheet", QUParameter::In }
    };
    static const QUMethod slot_2 = {"setStyleSheet", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "name", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"scrollToAnchor", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "pap", &static_QUType_varptr, "\x07", QUParameter::In }
    };
    static const QUMethod slot_4 = {"setPaper", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setLinkUnderline", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "mode", &static_QUType_enum, 
#ifndef QT_NO_PROPERTIES
	  &enum_tbl[0]
#else
	  0
#endif // QT_NO_PROPERTIES
	  , QUParameter::In }
    };
    static const QUMethod slot_6 = {"setWordWrap", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"setWrapColumnOrWidth", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "policy", &static_QUType_enum, 
#ifndef QT_NO_PROPERTIES
	  &enum_tbl[1]
#else
	  0
#endif // QT_NO_PROPERTIES
	  , QUParameter::In }
    };
    static const QUMethod slot_8 = {"setWrapPolicy", 1, param_slot_8 };
    static const QUMethod slot_9 = {"copy", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"append", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "txt", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"setText", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "txt", &static_QUType_QString, 0, QUParameter::In },
	{ "context", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"setText", 2, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "f", &static_QUType_ptr, "TextFormat", QUParameter::In }
    };
    static const QUMethod slot_13 = {"setTextFormat", 1, param_slot_13 };
    static const QUMethod slot_14 = {"selectAll", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ "select", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"selectAll", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "ts", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"setTabStopWidth", 1, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ "range", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"zoomIn", 1, param_slot_17 };
    static const QUMethod slot_18 = {"zoomIn", 0, 0 };
    static const QUParameter param_slot_19[] = {
	{ "range", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"zoomOut", 1, param_slot_19 };
    static const QUMethod slot_20 = {"zoomOut", 0, 0 };
    static const QUParameter param_slot_21[] = {
	{ "size", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"zoomTo", 1, param_slot_21 };
    static const QUMethod slot_22 = {"sync", 0, 0 };
    static const QUParameter param_slot_23[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_23 = {"setReadOnly", 1, param_slot_23 };
    static const QUMethod slot_24 = {"undo", 0, 0 };
    static const QUMethod slot_25 = {"redo", 0, 0 };
    static const QUMethod slot_26 = {"cut", 0, 0 };
    static const QUMethod slot_27 = {"paste", 0, 0 };
    static const QUParameter param_slot_28[] = {
	{ "subtype", &static_QUType_varptr, "\x14", QUParameter::In }
    };
    static const QUMethod slot_28 = {"pasteSubType", 1, param_slot_28 };
    static const QUMethod slot_29 = {"clear", 0, 0 };
    static const QUMethod slot_30 = {"del", 0, 0 };
    static const QUMethod slot_31 = {"indent", 0, 0 };
    static const QUParameter param_slot_32[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"setItalic", 1, param_slot_32 };
    static const QUParameter param_slot_33[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_33 = {"setBold", 1, param_slot_33 };
    static const QUParameter param_slot_34[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_34 = {"setUnderline", 1, param_slot_34 };
    static const QUParameter param_slot_35[] = {
	{ "f", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_35 = {"setFamily", 1, param_slot_35 };
    static const QUParameter param_slot_36[] = {
	{ "s", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_36 = {"setPointSize", 1, param_slot_36 };
    static const QUParameter param_slot_37[] = {
	{ "c", &static_QUType_varptr, "\x0a", QUParameter::In }
    };
    static const QUMethod slot_37 = {"setColor", 1, param_slot_37 };
    static const QUParameter param_slot_38[] = {
	{ "f", &static_QUType_varptr, "\x05", QUParameter::In }
    };
    static const QUMethod slot_38 = {"setFont", 1, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ "a", &static_QUType_ptr, "VerticalAlignment", QUParameter::In }
    };
    static const QUMethod slot_39 = {"setVerticalAlignment", 1, param_slot_39 };
    static const QUParameter param_slot_40[] = {
	{ "a", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_40 = {"setAlignment", 1, param_slot_40 };
    static const QUParameter param_slot_41[] = {
	{ "dm", &static_QUType_ptr, "QStyleSheetItem::DisplayMode", QUParameter::In },
	{ "listStyle", &static_QUType_ptr, "QStyleSheetItem::ListStyle", QUParameter::In }
    };
    static const QUMethod slot_41 = {"setParagType", 2, param_slot_41 };
    static const QUParameter param_slot_42[] = {
	{ "parag", &static_QUType_int, 0, QUParameter::In },
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_42 = {"setCursorPosition", 2, param_slot_42 };
    static const QUParameter param_slot_43[] = {
	{ "parag_from", &static_QUType_int, 0, QUParameter::In },
	{ "index_from", &static_QUType_int, 0, QUParameter::In },
	{ "parag_to", &static_QUType_int, 0, QUParameter::In },
	{ "index_to", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_43 = {"setSelection", 4, param_slot_43 };
    static const QUParameter param_slot_44[] = {
	{ "parag_from", &static_QUType_int, 0, QUParameter::In },
	{ "index_from", &static_QUType_int, 0, QUParameter::In },
	{ "parag_to", &static_QUType_int, 0, QUParameter::In },
	{ "index_to", &static_QUType_int, 0, QUParameter::In },
	{ "selNum", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_44 = {"setSelection", 5, param_slot_44 };
    static const QUParameter param_slot_45[] = {
	{ "selNum", &static_QUType_int, 0, QUParameter::In },
	{ "back", &static_QUType_varptr, "\x0a", QUParameter::In },
	{ "invertText", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_45 = {"setSelectionAttributes", 3, param_slot_45 };
    static const QUParameter param_slot_46[] = {
	{ "m", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_46 = {"setModified", 1, param_slot_46 };
    static const QUMethod slot_47 = {"resetFormat", 0, 0 };
    static const QUParameter param_slot_48[] = {
	{ "d", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_48 = {"setUndoDepth", 1, param_slot_48 };
    static const QUParameter param_slot_49[] = {
	{ "f", &static_QUType_ptr, "QTextFormat", QUParameter::In },
	{ "flags", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_49 = {"setFormat", 2, param_slot_49 };
    static const QUMethod slot_50 = {"ensureCursorVisible", 0, 0 };
    static const QUParameter param_slot_51[] = {
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_51 = {"placeCursor", 1, param_slot_51 };
    static const QUParameter param_slot_52[] = {
	{ "pos", &static_QUType_varptr, "\x0e", QUParameter::In },
	{ "c", &static_QUType_ptr, "QTextCursor", QUParameter::In }
    };
    static const QUMethod slot_52 = {"placeCursor", 2, param_slot_52 };
    static const QUParameter param_slot_53[] = {
	{ "action", &static_QUType_ptr, "CursorAction", QUParameter::In },
	{ "select", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_53 = {"moveCursor", 2, param_slot_53 };
    static const QUParameter param_slot_54[] = {
	{ "action", &static_QUType_ptr, "KeyboardAction", QUParameter::In }
    };
    static const QUMethod slot_54 = {"doKeyboardAction", 1, param_slot_54 };
    static const QUMethod slot_55 = {"removeSelectedText", 0, 0 };
    static const QUParameter param_slot_56[] = {
	{ "selNum", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_56 = {"removeSelectedText", 1, param_slot_56 };
    static const QUMethod slot_57 = {"removeSelection", 0, 0 };
    static const QUParameter param_slot_58[] = {
	{ "selNum", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_58 = {"removeSelection", 1, param_slot_58 };
    static const QUParameter param_slot_59[] = {
	{ "f", &static_QUType_varptr, "\x05", QUParameter::In }
    };
    static const QUMethod slot_59 = {"setCurrentFont", 1, param_slot_59 };
    static const QUParameter param_slot_60[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_60 = {"setOverwriteMode", 1, param_slot_60 };
    static const QUMethod slot_61 = {"scrollToBottom", 0, 0 };
    static const QUParameter param_slot_62[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_62 = {"insert", 1, param_slot_62 };
    static const QUParameter param_slot_63[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In },
	{ "insertionFlags", &static_QUType_varptr, "\x11", QUParameter::In }
    };
    static const QUMethod slot_63 = {"insert", 2, param_slot_63 };
    static const QUParameter param_slot_64[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_64 = {"insert", 2, param_slot_64 };
    static const QUParameter param_slot_65[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_65 = {"insert", 3, param_slot_65 };
    static const QUParameter param_slot_66[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_66 = {"insert", 4, param_slot_66 };
    static const QUParameter param_slot_67[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In },
	{ "para", &static_QUType_int, 0, QUParameter::In },
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_67 = {"insertAt", 3, param_slot_67 };
    static const QUParameter param_slot_68[] = {
	{ "para", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_68 = {"removeParagraph", 1, param_slot_68 };
    static const QUParameter param_slot_69[] = {
	{ "text", &static_QUType_QString, 0, QUParameter::In },
	{ "para", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_69 = {"insertParagraph", 2, param_slot_69 };
    static const QUParameter param_slot_70[] = {
	{ "para", &static_QUType_int, 0, QUParameter::In },
	{ "bg", &static_QUType_varptr, "\x0a", QUParameter::In }
    };
    static const QUMethod slot_70 = {"setParagraphBackgroundColor", 2, param_slot_70 };
    static const QUParameter param_slot_71[] = {
	{ "para", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_71 = {"clearParagraphBackground", 1, param_slot_71 };
    static const QUParameter param_slot_72[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_72 = {"setUndoRedoEnabled", 1, param_slot_72 };
    static const QUParameter param_slot_73[] = {
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_73 = {"setTabChangesFocus", 1, param_slot_73 };
    static const QUMethod slot_74 = {"polish", 0, 0 };
    static const QUParameter param_slot_75[] = {
	{ "numLines", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_75 = {"setMaxLogLines", 1, param_slot_75 };
    static const QUParameter param_slot_76[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_76 = {"maxLogLines", 1, param_slot_76 };
    static const QUMethod slot_77 = {"doChangeInterval", 0, 0 };
    static const QUMethod slot_78 = {"sliderReleased", 0, 0 };
    static const QUMethod slot_79 = {"formatMore", 0, 0 };
    static const QUMethod slot_80 = {"doResize", 0, 0 };
    static const QUMethod slot_81 = {"autoScrollTimerDone", 0, 0 };
    static const QUMethod slot_82 = {"blinkCursor", 0, 0 };
    static const QUMethod slot_83 = {"setModified", 0, 0 };
    static const QUMethod slot_84 = {"startDrag", 0, 0 };
    static const QUParameter param_slot_85[] = {
	{ "w", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_85 = {"documentWidthChanged", 1, param_slot_85 };
    static const QUMethod slot_86 = {"clipboardChanged", 0, 0 };
    static const QUMethod slot_87 = {"optimDoAutoScroll", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setEnabled(bool)", &slot_0, QMetaData::Public },
	{ "setMimeSourceFactory(QMimeSourceFactory*)", &slot_1, QMetaData::Public },
	{ "setStyleSheet(QStyleSheet*)", &slot_2, QMetaData::Public },
	{ "scrollToAnchor(const QString&)", &slot_3, QMetaData::Public },
	{ "setPaper(const QBrush&)", &slot_4, QMetaData::Public },
	{ "setLinkUnderline(bool)", &slot_5, QMetaData::Public },
	{ "setWordWrap(WordWrap)", &slot_6, QMetaData::Public },
	{ "setWrapColumnOrWidth(int)", &slot_7, QMetaData::Public },
	{ "setWrapPolicy(WrapPolicy)", &slot_8, QMetaData::Public },
	{ "copy()", &slot_9, QMetaData::Public },
	{ "append(const QString&)", &slot_10, QMetaData::Public },
	{ "setText(const QString&)", &slot_11, QMetaData::Public },
	{ "setText(const QString&,const QString&)", &slot_12, QMetaData::Public },
	{ "setTextFormat(TextFormat)", &slot_13, QMetaData::Public },
	{ "selectAll()", &slot_14, QMetaData::Public },
	{ "selectAll(bool)", &slot_15, QMetaData::Public },
	{ "setTabStopWidth(int)", &slot_16, QMetaData::Public },
	{ "zoomIn(int)", &slot_17, QMetaData::Public },
	{ "zoomIn()", &slot_18, QMetaData::Public },
	{ "zoomOut(int)", &slot_19, QMetaData::Public },
	{ "zoomOut()", &slot_20, QMetaData::Public },
	{ "zoomTo(int)", &slot_21, QMetaData::Public },
	{ "sync()", &slot_22, QMetaData::Public },
	{ "setReadOnly(bool)", &slot_23, QMetaData::Public },
	{ "undo()", &slot_24, QMetaData::Public },
	{ "redo()", &slot_25, QMetaData::Public },
	{ "cut()", &slot_26, QMetaData::Public },
	{ "paste()", &slot_27, QMetaData::Public },
	{ "pasteSubType(const QCString&)", &slot_28, QMetaData::Public },
	{ "clear()", &slot_29, QMetaData::Public },
	{ "del()", &slot_30, QMetaData::Public },
	{ "indent()", &slot_31, QMetaData::Public },
	{ "setItalic(bool)", &slot_32, QMetaData::Public },
	{ "setBold(bool)", &slot_33, QMetaData::Public },
	{ "setUnderline(bool)", &slot_34, QMetaData::Public },
	{ "setFamily(const QString&)", &slot_35, QMetaData::Public },
	{ "setPointSize(int)", &slot_36, QMetaData::Public },
	{ "setColor(const QColor&)", &slot_37, QMetaData::Public },
	{ "setFont(const QFont&)", &slot_38, QMetaData::Public },
	{ "setVerticalAlignment(VerticalAlignment)", &slot_39, QMetaData::Public },
	{ "setAlignment(int)", &slot_40, QMetaData::Public },
	{ "setParagType(QStyleSheetItem::DisplayMode,QStyleSheetItem::ListStyle)", &slot_41, QMetaData::Public },
	{ "setCursorPosition(int,int)", &slot_42, QMetaData::Public },
	{ "setSelection(int,int,int,int)", &slot_43, QMetaData::Public },
	{ "setSelection(int,int,int,int,int)", &slot_44, QMetaData::Public },
	{ "setSelectionAttributes(int,const QColor&,bool)", &slot_45, QMetaData::Public },
	{ "setModified(bool)", &slot_46, QMetaData::Public },
	{ "resetFormat()", &slot_47, QMetaData::Public },
	{ "setUndoDepth(int)", &slot_48, QMetaData::Public },
	{ "setFormat(QTextFormat*,int)", &slot_49, QMetaData::Public },
	{ "ensureCursorVisible()", &slot_50, QMetaData::Public },
	{ "placeCursor(const QPoint&)", &slot_51, QMetaData::Public },
	{ "placeCursor(const QPoint&,QTextCursor*)", &slot_52, QMetaData::Public },
	{ "moveCursor(CursorAction,bool)", &slot_53, QMetaData::Public },
	{ "doKeyboardAction(KeyboardAction)", &slot_54, QMetaData::Public },
	{ "removeSelectedText()", &slot_55, QMetaData::Public },
	{ "removeSelectedText(int)", &slot_56, QMetaData::Public },
	{ "removeSelection()", &slot_57, QMetaData::Public },
	{ "removeSelection(int)", &slot_58, QMetaData::Public },
	{ "setCurrentFont(const QFont&)", &slot_59, QMetaData::Public },
	{ "setOverwriteMode(bool)", &slot_60, QMetaData::Public },
	{ "scrollToBottom()", &slot_61, QMetaData::Public },
	{ "insert(const QString&)", &slot_62, QMetaData::Public },
	{ "insert(const QString&,uint)", &slot_63, QMetaData::Public },
	{ "insert(const QString&,bool)", &slot_64, QMetaData::Public },
	{ "insert(const QString&,bool,bool)", &slot_65, QMetaData::Public },
	{ "insert(const QString&,bool,bool,bool)", &slot_66, QMetaData::Public },
	{ "insertAt(const QString&,int,int)", &slot_67, QMetaData::Public },
	{ "removeParagraph(int)", &slot_68, QMetaData::Public },
	{ "insertParagraph(const QString&,int)", &slot_69, QMetaData::Public },
	{ "setParagraphBackgroundColor(int,const QColor&)", &slot_70, QMetaData::Public },
	{ "clearParagraphBackground(int)", &slot_71, QMetaData::Public },
	{ "setUndoRedoEnabled(bool)", &slot_72, QMetaData::Public },
	{ "setTabChangesFocus(bool)", &slot_73, QMetaData::Public },
	{ "polish()", &slot_74, QMetaData::Public },
	{ "setMaxLogLines(int)", &slot_75, QMetaData::Public },
	{ "maxLogLines()", &slot_76, QMetaData::Public },
	{ "doChangeInterval()", &slot_77, QMetaData::Protected },
	{ "sliderReleased()", &slot_78, QMetaData::Protected },
	{ "formatMore()", &slot_79, QMetaData::Private },
	{ "doResize()", &slot_80, QMetaData::Private },
	{ "autoScrollTimerDone()", &slot_81, QMetaData::Private },
	{ "blinkCursor()", &slot_82, QMetaData::Private },
	{ "setModified()", &slot_83, QMetaData::Private },
	{ "startDrag()", &slot_84, QMetaData::Private },
	{ "documentWidthChanged(int)", &slot_85, QMetaData::Private },
	{ "clipboardChanged()", &slot_86, QMetaData::Private },
	{ "optimDoAutoScroll()", &slot_87, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"textChanged", 0, 0 };
    static const QUMethod signal_1 = {"selectionChanged", 0, 0 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"copyAvailable", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ "yes", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"undoAvailable", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ "yes", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"redoAvailable", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ "f", &static_QUType_varptr, "\x05", QUParameter::In }
    };
    static const QUMethod signal_5 = {"currentFontChanged", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ "c", &static_QUType_varptr, "\x0a", QUParameter::In }
    };
    static const QUMethod signal_6 = {"currentColorChanged", 1, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ "a", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_7 = {"currentAlignmentChanged", 1, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ "a", &static_QUType_ptr, "VerticalAlignment", QUParameter::In }
    };
    static const QUMethod signal_8 = {"currentVerticalAlignmentChanged", 1, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ "c", &static_QUType_ptr, "QTextCursor", QUParameter::In }
    };
    static const QUMethod signal_9 = {"cursorPositionChanged", 1, param_signal_9 };
    static const QUParameter param_signal_10[] = {
	{ "para", &static_QUType_int, 0, QUParameter::In },
	{ "pos", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_10 = {"cursorPositionChanged", 2, param_signal_10 };
    static const QUMethod signal_11 = {"returnPressed", 0, 0 };
    static const QUParameter param_signal_12[] = {
	{ "m", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_12 = {"modificationChanged", 1, param_signal_12 };
    static const QUParameter param_signal_13[] = {
	{ "parag", &static_QUType_int, 0, QUParameter::In },
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_13 = {"clicked", 2, param_signal_13 };
    static const QUParameter param_signal_14[] = {
	{ "parag", &static_QUType_int, 0, QUParameter::In },
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_14 = {"doubleClicked", 2, param_signal_14 };
    static const QMetaData signal_tbl[] = {
	{ "textChanged()", &signal_0, QMetaData::Public },
	{ "selectionChanged()", &signal_1, QMetaData::Public },
	{ "copyAvailable(bool)", &signal_2, QMetaData::Public },
	{ "undoAvailable(bool)", &signal_3, QMetaData::Public },
	{ "redoAvailable(bool)", &signal_4, QMetaData::Public },
	{ "currentFontChanged(const QFont&)", &signal_5, QMetaData::Public },
	{ "currentColorChanged(const QColor&)", &signal_6, QMetaData::Public },
	{ "currentAlignmentChanged(int)", &signal_7, QMetaData::Public },
	{ "currentVerticalAlignmentChanged(VerticalAlignment)", &signal_8, QMetaData::Public },
	{ "cursorPositionChanged(QTextCursor*)", &signal_9, QMetaData::Public },
	{ "cursorPositionChanged(int,int)", &signal_10, QMetaData::Public },
	{ "returnPressed()", &signal_11, QMetaData::Public },
	{ "modificationChanged(bool)", &signal_12, QMetaData::Public },
	{ "clicked(int,int)", &signal_13, QMetaData::Public },
	{ "doubleClicked(int,int)", &signal_14, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[19] = {
 	{ "TextFormat","textFormat", 0x010f, &QTextEdit::metaObj, 0, -1 },
	{ "QString","text", 0x3000103, &QTextEdit::metaObj, 0, -1 },
	{ "QBrush","paper", 0x7000103, &QTextEdit::metaObj, 0, -1 },
	{ "bool","linkUnderline", 0x12000103, &QTextEdit::metaObj, 0, -1 },
	{ "QString","documentTitle", 0x3000001, &QTextEdit::metaObj, 0, -1 },
	{ "int","length", 0x10000001, &QTextEdit::metaObj, 0, -1 },
	{ "WordWrap","wordWrap", 0x0107, &QTextEdit::metaObj, &enum_tbl[0], -1 },
	{ "int","wrapColumnOrWidth", 0x10000103, &QTextEdit::metaObj, 0, -1 },
	{ "WrapPolicy","wrapPolicy", 0x0107, &QTextEdit::metaObj, &enum_tbl[1], -1 },
	{ "bool","hasSelectedText", 0x12000001, &QTextEdit::metaObj, 0, -1 },
	{ "QString","selectedText", 0x3000001, &QTextEdit::metaObj, 0, -1 },
	{ "int","undoDepth", 0x10000103, &QTextEdit::metaObj, 0, -1 },
	{ "bool","overwriteMode", 0x12000103, &QTextEdit::metaObj, 0, -1 },
	{ "bool","modified", 0x12001103, &QTextEdit::metaObj, 0, -1 },
	{ "bool","readOnly", 0x12000103, &QTextEdit::metaObj, 0, -1 },
	{ "bool","undoRedoEnabled", 0x12000103, &QTextEdit::metaObj, 0, -1 },
	{ "int","tabStopWidth", 0x10000103, &QTextEdit::metaObj, 0, -1 },
	{ "bool","tabChangesFocus", 0x12000103, &QTextEdit::metaObj, 0, -1 },
	{ "AutoFormatting","autoFormatting", 0x0107, &QTextEdit::metaObj, &enum_tbl[2], -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QTextEdit", parentObject,
	slot_tbl, 88,
	signal_tbl, 15,
#ifndef QT_NO_PROPERTIES
	props_tbl, 19,
	enum_tbl, 3,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTextEdit.setMetaObject( metaObj );
    return metaObj;
}

void* QTextEdit::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTextEdit" ) )
	return this;
    return QScrollView::qt_cast( clname );
}

// SIGNAL textChanged
void QTextEdit::textChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL selectionChanged
void QTextEdit::selectionChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL copyAvailable
void QTextEdit::copyAvailable( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL undoAvailable
void QTextEdit::undoAvailable( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 3, t0 );
}

// SIGNAL redoAvailable
void QTextEdit::redoAvailable( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 4, t0 );
}

// SIGNAL currentFontChanged
void QTextEdit::currentFontChanged( const QFont& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_varptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL currentColorChanged
void QTextEdit::currentColorChanged( const QColor& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_varptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL currentAlignmentChanged
void QTextEdit::currentAlignmentChanged( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 7, t0 );
}

// SIGNAL currentVerticalAlignmentChanged
void QTextEdit::currentVerticalAlignmentChanged( VerticalAlignment t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL cursorPositionChanged
void QTextEdit::cursorPositionChanged( QTextCursor* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL cursorPositionChanged
void QTextEdit::cursorPositionChanged( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 10 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL returnPressed
void QTextEdit::returnPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 11 );
}

// SIGNAL modificationChanged
void QTextEdit::modificationChanged( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 12, t0 );
}

// SIGNAL clicked
void QTextEdit::clicked( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 13 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL doubleClicked
void QTextEdit::doubleClicked( int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 14 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

bool QTextEdit::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 1: setMimeSourceFactory((QMimeSourceFactory*)static_QUType_ptr.get(_o+1)); break;
    case 2: setStyleSheet((QStyleSheet*)static_QUType_ptr.get(_o+1)); break;
    case 3: scrollToAnchor((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: setPaper((const QBrush&)*((const QBrush*)static_QUType_ptr.get(_o+1))); break;
    case 5: setLinkUnderline((bool)static_QUType_bool.get(_o+1)); break;
    case 6: setWordWrap((WordWrap)static_QUType_enum.get(_o+1)); break;
    case 7: setWrapColumnOrWidth((int)static_QUType_int.get(_o+1)); break;
    case 8: setWrapPolicy((WrapPolicy)static_QUType_enum.get(_o+1)); break;
    case 9: copy(); break;
    case 10: append((const QString&)static_QUType_QString.get(_o+1)); break;
    case 11: setText((const QString&)static_QUType_QString.get(_o+1)); break;
    case 12: setText((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 13: setTextFormat((TextFormat)(*((TextFormat*)static_QUType_ptr.get(_o+1)))); break;
    case 14: selectAll(); break;
    case 15: selectAll((bool)static_QUType_bool.get(_o+1)); break;
    case 16: setTabStopWidth((int)static_QUType_int.get(_o+1)); break;
    case 17: zoomIn((int)static_QUType_int.get(_o+1)); break;
    case 18: zoomIn(); break;
    case 19: zoomOut((int)static_QUType_int.get(_o+1)); break;
    case 20: zoomOut(); break;
    case 21: zoomTo((int)static_QUType_int.get(_o+1)); break;
    case 22: sync(); break;
    case 23: setReadOnly((bool)static_QUType_bool.get(_o+1)); break;
    case 24: undo(); break;
    case 25: redo(); break;
    case 26: cut(); break;
    case 27: paste(); break;
    case 28: pasteSubType((const QCString&)*((const QCString*)static_QUType_ptr.get(_o+1))); break;
    case 29: clear(); break;
    case 30: del(); break;
    case 31: indent(); break;
    case 32: setItalic((bool)static_QUType_bool.get(_o+1)); break;
    case 33: setBold((bool)static_QUType_bool.get(_o+1)); break;
    case 34: setUnderline((bool)static_QUType_bool.get(_o+1)); break;
    case 35: setFamily((const QString&)static_QUType_QString.get(_o+1)); break;
    case 36: setPointSize((int)static_QUType_int.get(_o+1)); break;
    case 37: setColor((const QColor&)*((const QColor*)static_QUType_ptr.get(_o+1))); break;
    case 38: setFont((const QFont&)*((const QFont*)static_QUType_ptr.get(_o+1))); break;
    case 39: setVerticalAlignment((VerticalAlignment)(*((VerticalAlignment*)static_QUType_ptr.get(_o+1)))); break;
    case 40: setAlignment((int)static_QUType_int.get(_o+1)); break;
    case 41: setParagType((QStyleSheetItem::DisplayMode)(*((QStyleSheetItem::DisplayMode*)static_QUType_ptr.get(_o+1))),(QStyleSheetItem::ListStyle)(*((QStyleSheetItem::ListStyle*)static_QUType_ptr.get(_o+2)))); break;
    case 42: setCursorPosition((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 43: setSelection((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4)); break;
    case 44: setSelection((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(int)static_QUType_int.get(_o+4),(int)static_QUType_int.get(_o+5)); break;
    case 45: setSelectionAttributes((int)static_QUType_int.get(_o+1),(const QColor&)*((const QColor*)static_QUType_ptr.get(_o+2)),(bool)static_QUType_bool.get(_o+3)); break;
    case 46: setModified((bool)static_QUType_bool.get(_o+1)); break;
    case 47: resetFormat(); break;
    case 48: setUndoDepth((int)static_QUType_int.get(_o+1)); break;
    case 49: setFormat((QTextFormat*)static_QUType_ptr.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 50: ensureCursorVisible(); break;
    case 51: placeCursor((const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+1))); break;
    case 52: placeCursor((const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+1)),(QTextCursor*)static_QUType_ptr.get(_o+2)); break;
    case 53: moveCursor((CursorAction)(*((CursorAction*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2)); break;
    case 54: doKeyboardAction((KeyboardAction)(*((KeyboardAction*)static_QUType_ptr.get(_o+1)))); break;
    case 55: removeSelectedText(); break;
    case 56: removeSelectedText((int)static_QUType_int.get(_o+1)); break;
    case 57: removeSelection(); break;
    case 58: removeSelection((int)static_QUType_int.get(_o+1)); break;
    case 59: setCurrentFont((const QFont&)*((const QFont*)static_QUType_ptr.get(_o+1))); break;
    case 60: setOverwriteMode((bool)static_QUType_bool.get(_o+1)); break;
    case 61: scrollToBottom(); break;
    case 62: insert((const QString&)static_QUType_QString.get(_o+1)); break;
    case 63: insert((const QString&)static_QUType_QString.get(_o+1),(uint)(*((uint*)static_QUType_ptr.get(_o+2)))); break;
    case 64: insert((const QString&)static_QUType_QString.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 65: insert((const QString&)static_QUType_QString.get(_o+1),(bool)static_QUType_bool.get(_o+2),(bool)static_QUType_bool.get(_o+3)); break;
    case 66: insert((const QString&)static_QUType_QString.get(_o+1),(bool)static_QUType_bool.get(_o+2),(bool)static_QUType_bool.get(_o+3),(bool)static_QUType_bool.get(_o+4)); break;
    case 67: insertAt((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 68: removeParagraph((int)static_QUType_int.get(_o+1)); break;
    case 69: insertParagraph((const QString&)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 70: setParagraphBackgroundColor((int)static_QUType_int.get(_o+1),(const QColor&)*((const QColor*)static_QUType_ptr.get(_o+2))); break;
    case 71: clearParagraphBackground((int)static_QUType_int.get(_o+1)); break;
    case 72: setUndoRedoEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 73: setTabChangesFocus((bool)static_QUType_bool.get(_o+1)); break;
    case 74: polish(); break;
    case 75: setMaxLogLines((int)static_QUType_int.get(_o+1)); break;
    case 76: static_QUType_int.set(_o,maxLogLines()); break;
    case 77: doChangeInterval(); break;
    case 78: sliderReleased(); break;
    case 79: formatMore(); break;
    case 80: doResize(); break;
    case 81: autoScrollTimerDone(); break;
    case 82: blinkCursor(); break;
    case 83: setModified(); break;
    case 84: startDrag(); break;
    case 85: documentWidthChanged((int)static_QUType_int.get(_o+1)); break;
    case 86: clipboardChanged(); break;
    case 87: optimDoAutoScroll(); break;
    default:
	return QScrollView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QTextEdit::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: textChanged(); break;
    case 1: selectionChanged(); break;
    case 2: copyAvailable((bool)static_QUType_bool.get(_o+1)); break;
    case 3: undoAvailable((bool)static_QUType_bool.get(_o+1)); break;
    case 4: redoAvailable((bool)static_QUType_bool.get(_o+1)); break;
    case 5: currentFontChanged((const QFont&)*((const QFont*)static_QUType_ptr.get(_o+1))); break;
    case 6: currentColorChanged((const QColor&)*((const QColor*)static_QUType_ptr.get(_o+1))); break;
    case 7: currentAlignmentChanged((int)static_QUType_int.get(_o+1)); break;
    case 8: currentVerticalAlignmentChanged((VerticalAlignment)(*((VerticalAlignment*)static_QUType_ptr.get(_o+1)))); break;
    case 9: cursorPositionChanged((QTextCursor*)static_QUType_ptr.get(_o+1)); break;
    case 10: cursorPositionChanged((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 11: returnPressed(); break;
    case 12: modificationChanged((bool)static_QUType_bool.get(_o+1)); break;
    case 13: clicked((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 14: doubleClicked((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QScrollView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QTextEdit::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setTextFormat((TextFormat&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->textFormat() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setText(v->asString()); break;
	case 1: *v = QVariant( this->text() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setPaper(v->asBrush()); break;
	case 1: *v = QVariant( this->paper() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setLinkUnderline(v->asBool()); break;
	case 1: *v = QVariant( this->linkUnderline(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 1: *v = QVariant( this->documentTitle() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 1: *v = QVariant( this->length() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setWordWrap((WordWrap&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->wordWrap() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setWrapColumnOrWidth(v->asInt()); break;
	case 1: *v = QVariant( this->wrapColumnOrWidth() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setWrapPolicy((WrapPolicy&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->wrapPolicy() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 1: *v = QVariant( this->hasSelectedText(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 1: *v = QVariant( this->selectedText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 11: switch( f ) {
	case 0: setUndoDepth(v->asInt()); break;
	case 1: *v = QVariant( this->undoDepth() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 12: switch( f ) {
	case 0: setOverwriteMode(v->asBool()); break;
	case 1: *v = QVariant( this->isOverwriteMode(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 13: switch( f ) {
	case 0: setModified(v->asBool()); break;
	case 1: *v = QVariant( this->isModified(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 14: switch( f ) {
	case 0: setReadOnly(v->asBool()); break;
	case 1: *v = QVariant( this->isReadOnly(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 15: switch( f ) {
	case 0: setUndoRedoEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isUndoRedoEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 16: switch( f ) {
	case 0: setTabStopWidth(v->asInt()); break;
	case 1: *v = QVariant( this->tabStopWidth() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 17: switch( f ) {
	case 0: setTabChangesFocus(v->asBool()); break;
	case 1: *v = QVariant( this->tabChangesFocus(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 18: switch( f ) {
	case 0: setAutoFormatting(v->asUInt()); break;
	case 1: *v = QVariant( (int)this->autoFormatting() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QScrollView::qt_property( id, f, v );
    }
    return TRUE;
}

bool QTextEdit::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTabBar::className() const
{
    return "QTabBar";
}

QMetaObject *QTabBar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTabBar( "QTabBar", &QTabBar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTabBar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTabBar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTabBar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTabBar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTabBar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "RoundedAbove",  (int) QTabBar::RoundedAbove },
	{ "RoundedBelow",  (int) QTabBar::RoundedBelow },
	{ "TriangularAbove",  (int) QTabBar::TriangularAbove },
	{ "TriangularBelow",  (int) QTabBar::TriangularBelow }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "Shape", 4, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setCurrentTab", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QTab", QUParameter::In }
    };
    static const QUMethod slot_1 = {"setCurrentTab", 1, param_slot_1 };
    static const QUMethod slot_2 = {"scrollTabs", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setCurrentTab(int)", &slot_0, QMetaData::Public },
	{ "setCurrentTab(QTab*)", &slot_1, QMetaData::Public },
	{ "scrollTabs()", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"selected", 1, param_signal_0 };
    static const QUMethod signal_1 = {"layoutChanged", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "selected(int)", &signal_0, QMetaData::Public },
	{ "layoutChanged()", &signal_1, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[4] = {
 	{ "Shape","shape", 0x0107, &QTabBar::metaObj, &enum_tbl[0], -1 },
	{ "int","currentTab", 0x10000103, &QTabBar::metaObj, 0, -1 },
	{ "int","count", 0x10000001, &QTabBar::metaObj, 0, -1 },
	{ "int","keyboardFocusTab", 0x10000001, &QTabBar::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QTabBar", parentObject,
	slot_tbl, 3,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	props_tbl, 4,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTabBar.setMetaObject( metaObj );
    return metaObj;
}

void* QTabBar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTabBar" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL selected
void QTabBar::selected( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL layoutChanged
void QTabBar::layoutChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool QTabBar::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setCurrentTab((int)static_QUType_int.get(_o+1)); break;
    case 1: setCurrentTab((QTab*)static_QUType_ptr.get(_o+1)); break;
    case 2: scrollTabs(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QTabBar::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: selected((int)static_QUType_int.get(_o+1)); break;
    case 1: layoutChanged(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QTabBar::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setShape((Shape&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->shape() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setCurrentTab(v->asInt()); break;
	case 1: *v = QVariant( this->currentTab() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 1: *v = QVariant( this->count() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 1: *v = QVariant( this->keyboardFocusTab() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QTabBar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTabDialog::className() const
{
    return "QTabDialog";
}

QMetaObject *QTabDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTabDialog( "QTabDialog", &QTabDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTabDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTabDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTabDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTabDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTabDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "i", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"showTab", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "showTab(int)", &slot_0, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"aboutToShow", 0, 0 };
    static const QUMethod signal_1 = {"applyButtonPressed", 0, 0 };
    static const QUMethod signal_2 = {"cancelButtonPressed", 0, 0 };
    static const QUMethod signal_3 = {"defaultButtonPressed", 0, 0 };
    static const QUMethod signal_4 = {"helpButtonPressed", 0, 0 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_5 = {"currentChanged", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_6 = {"selected", 1, param_signal_6 };
    static const QMetaData signal_tbl[] = {
	{ "aboutToShow()", &signal_0, QMetaData::Protected },
	{ "applyButtonPressed()", &signal_1, QMetaData::Protected },
	{ "cancelButtonPressed()", &signal_2, QMetaData::Protected },
	{ "defaultButtonPressed()", &signal_3, QMetaData::Protected },
	{ "helpButtonPressed()", &signal_4, QMetaData::Protected },
	{ "currentChanged(QWidget*)", &signal_5, QMetaData::Protected },
	{ "selected(const QString&)", &signal_6, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"QTabDialog", parentObject,
	slot_tbl, 1,
	signal_tbl, 7,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTabDialog.setMetaObject( metaObj );
    return metaObj;
}

void* QTabDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTabDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

// SIGNAL aboutToShow
void QTabDialog::aboutToShow()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL applyButtonPressed
void QTabDialog::applyButtonPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL cancelButtonPressed
void QTabDialog::cancelButtonPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL defaultButtonPressed
void QTabDialog::defaultButtonPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL helpButtonPressed
void QTabDialog::helpButtonPressed()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL currentChanged
void QTabDialog::currentChanged( QWidget* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL selected
void QTabDialog::selected( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 6, t0 );
}

bool QTabDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: showTab((int)static_QUType_int.get(_o+1)); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QTabDialog::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: aboutToShow(); break;
    case 1: applyButtonPressed(); break;
    case 2: cancelButtonPressed(); break;
    case 3: defaultButtonPressed(); break;
    case 4: helpButtonPressed(); break;
    case 5: currentChanged((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 6: selected((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QDialog::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QTabDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool QTabDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTabWidget::className() const
{
    return "QTabWidget";
}

QMetaObject *QTabWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTabWidget( "QTabWidget", &QTabWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTabWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTabWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTabWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTabWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTabWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "Top",  (int) QTabWidget::Top },
	{ "Bottom",  (int) QTabWidget::Bottom }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "Rounded",  (int) QTabWidget::Rounded },
	{ "Triangular",  (int) QTabWidget::Triangular }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "TabPosition", 2, enum_0, FALSE },
	{ "TabShape", 2, enum_1, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setCurrentPage", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_1 = {"showPage", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_2 = {"removePage", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"showTab", 1, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "setCurrentPage(int)", &slot_0, QMetaData::Public },
	{ "showPage(QWidget*)", &slot_1, QMetaData::Public },
	{ "removePage(QWidget*)", &slot_2, QMetaData::Public },
	{ "showTab(int)", &slot_3, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"currentChanged", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"selected", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "currentChanged(QWidget*)", &signal_0, QMetaData::Protected },
	{ "selected(const QString&)", &signal_1, QMetaData::Protected }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[6] = {
 	{ "TabPosition","tabPosition", 0x0107, &QTabWidget::metaObj, &enum_tbl[0], -1 },
	{ "TabShape","tabShape", 0x0107, &QTabWidget::metaObj, &enum_tbl[1], -1 },
	{ "int","margin", 0x10000103, &QTabWidget::metaObj, 0, -1 },
	{ "int","currentPage", 0x10000103, &QTabWidget::metaObj, 0, -1 },
	{ "int","count", 0x10000001, &QTabWidget::metaObj, 0, -1 },
	{ "bool","autoMask", 0x12020200, &QTabWidget::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QTabWidget", parentObject,
	slot_tbl, 4,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	props_tbl, 6,
	enum_tbl, 2,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTabWidget.setMetaObject( metaObj );
    return metaObj;
}

void* QTabWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTabWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL currentChanged
void QTabWidget::currentChanged( QWidget* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL selected
void QTabWidget::selected( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

bool QTabWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setCurrentPage((int)static_QUType_int.get(_o+1)); break;
    case 1: showPage((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 2: removePage((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 3: showTab((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QTabWidget::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: currentChanged((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 1: selected((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QTabWidget::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setTabPosition((TabPosition&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->tabPosition() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setTabShape((TabShape&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->tabShape() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setMargin(v->asInt()); break;
	case 1: *v = QVariant( this->margin() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setCurrentPage(v->asInt()); break;
	case 1: *v = QVariant( this->currentPageIndex() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 1: *v = QVariant( this->count() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	case 3: case 4: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
resolve:
    return QWidget::qt_property( staticMetaObject()->resolveProperty(id), f, v );
}

bool QTabWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTextBrowser::className() const
{
    return "QTextBrowser";
}

QMetaObject *QTextBrowser::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTextBrowser( "QTextBrowser", &QTextBrowser::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTextBrowser::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextBrowser", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTextBrowser::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextBrowser", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTextBrowser::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QTextEdit::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "name", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setSource", 1, param_slot_0 };
    static const QUMethod slot_1 = {"backward", 0, 0 };
    static const QUMethod slot_2 = {"forward", 0, 0 };
    static const QUMethod slot_3 = {"home", 0, 0 };
    static const QUMethod slot_4 = {"reload", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "txt", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setText", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "txt", &static_QUType_QString, 0, QUParameter::In },
	{ "context", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"setText", 2, param_slot_6 };
    static const QMetaData slot_tbl[] = {
	{ "setSource(const QString&)", &slot_0, QMetaData::Public },
	{ "backward()", &slot_1, QMetaData::Public },
	{ "forward()", &slot_2, QMetaData::Public },
	{ "home()", &slot_3, QMetaData::Public },
	{ "reload()", &slot_4, QMetaData::Public },
	{ "setText(const QString&)", &slot_5, QMetaData::Public },
	{ "setText(const QString&,const QString&)", &slot_6, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"backwardAvailable", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"forwardAvailable", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"sourceChanged", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"highlighted", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"linkClicked", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_5 = {"anchorClicked", 2, param_signal_5 };
    static const QMetaData signal_tbl[] = {
	{ "backwardAvailable(bool)", &signal_0, QMetaData::Public },
	{ "forwardAvailable(bool)", &signal_1, QMetaData::Public },
	{ "sourceChanged(const QString&)", &signal_2, QMetaData::Public },
	{ "highlighted(const QString&)", &signal_3, QMetaData::Public },
	{ "linkClicked(const QString&)", &signal_4, QMetaData::Public },
	{ "anchorClicked(const QString&,const QString&)", &signal_5, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[6] = {
 	{ "QString","source", 0x3000103, &QTextBrowser::metaObj, 0, -1 },
	{ "int","undoDepth", 0x10025200, &QTextBrowser::metaObj, 0, -1 },
	{ "bool","overwriteMode", 0x12025200, &QTextBrowser::metaObj, 0, -1 },
	{ "bool","modified", 0x12026200, &QTextBrowser::metaObj, 0, -1 },
	{ "bool","readOnly", 0x12025200, &QTextBrowser::metaObj, 0, -1 },
	{ "bool","undoRedoEnabled", 0x12025200, &QTextBrowser::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QTextBrowser", parentObject,
	slot_tbl, 7,
	signal_tbl, 6,
#ifndef QT_NO_PROPERTIES
	props_tbl, 6,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTextBrowser.setMetaObject( metaObj );
    return metaObj;
}

void* QTextBrowser::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTextBrowser" ) )
	return this;
    return QTextEdit::qt_cast( clname );
}

// SIGNAL backwardAvailable
void QTextBrowser::backwardAvailable( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL forwardAvailable
void QTextBrowser::forwardAvailable( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL sourceChanged
void QTextBrowser::sourceChanged( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL highlighted
void QTextBrowser::highlighted( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 3, t0 );
}

// SIGNAL linkClicked
void QTextBrowser::linkClicked( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 4, t0 );
}

// SIGNAL anchorClicked
void QTextBrowser::anchorClicked( const QString& t0, const QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

bool QTextBrowser::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setSource((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: backward(); break;
    case 2: forward(); break;
    case 3: home(); break;
    case 4: reload(); break;
    case 5: setText((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: setText((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    default:
	return QTextEdit::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QTextBrowser::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: backwardAvailable((bool)static_QUType_bool.get(_o+1)); break;
    case 1: forwardAvailable((bool)static_QUType_bool.get(_o+1)); break;
    case 2: sourceChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: highlighted((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: linkClicked((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: anchorClicked((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    default:
	return QTextEdit::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QTextBrowser::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setSource(v->asString()); break;
	case 1: *v = QVariant( this->source() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: case 1: case 3: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	default: return FALSE;
    } break;
    default:
	return QTextEdit::qt_property( id, f, v );
    }
    return TRUE;
resolve:
    return QTextEdit::qt_property( staticMetaObject()->resolveProperty(id), f, v );
}

bool QTextBrowser::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTextCodecPlugin::className() const
{
    return "QTextCodecPlugin";
}

QMetaObject *QTextCodecPlugin::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTextCodecPlugin( "QTextCodecPlugin", &QTextCodecPlugin::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTextCodecPlugin::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextCodecPlugin", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTextCodecPlugin::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextCodecPlugin", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTextCodecPlugin::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGPlugin::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QTextCodecPlugin", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTextCodecPlugin.setMetaObject( metaObj );
    return metaObj;
}

void* QTextCodecPlugin::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTextCodecPlugin" ) )
	return this;
    return QGPlugin::qt_cast( clname );
}

bool QTextCodecPlugin::qt_invoke( int _id, QUObject* _o )
{
    return QGPlugin::qt_invoke(_id,_o);
}

bool QTextCodecPlugin::qt_emit( int _id, QUObject* _o )
{
    return QGPlugin::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QTextCodecPlugin::qt_property( int id, int f, QVariant* v)
{
    return QGPlugin::qt_property( id, f, v);
}

bool QTextCodecPlugin::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QMultiLineEdit::className() const
{
    return "QMultiLineEdit";
}

QMetaObject *QMultiLineEdit::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMultiLineEdit( "QMultiLineEdit", &QMultiLineEdit::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMultiLineEdit::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMultiLineEdit", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMultiLineEdit::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMultiLineEdit", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMultiLineEdit::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QTextEdit::staticMetaObject();
    static const QUMethod slot_0 = {"deselect", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "deselect()", &slot_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[5] = {
 	{ "int","numLines", 0x10000001, &QMultiLineEdit::metaObj, 0, -1 },
	{ "bool","atBeginning", 0x12000001, &QMultiLineEdit::metaObj, 0, -1 },
	{ "bool","atEnd", 0x12000001, &QMultiLineEdit::metaObj, 0, -1 },
	{ "Alignment","alignment", 0x010f, &QMultiLineEdit::metaObj, 0, -1 },
	{ "bool","edited", 0x12001103, &QMultiLineEdit::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QMultiLineEdit", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 5,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMultiLineEdit.setMetaObject( metaObj );
    return metaObj;
}

void* QMultiLineEdit::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMultiLineEdit" ) )
	return this;
    return QTextEdit::qt_cast( clname );
}

bool QMultiLineEdit::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: deselect(); break;
    default:
	return QTextEdit::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QMultiLineEdit::qt_emit( int _id, QUObject* _o )
{
    return QTextEdit::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QMultiLineEdit::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 1: *v = QVariant( this->numLines() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 1: *v = QVariant( this->atBeginning(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 1: *v = QVariant( this->atEnd(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setAlignment(v->asInt()); break;
	case 1: *v = QVariant( (int)this->alignment() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setEdited(v->asBool()); break;
	case 1: *v = QVariant( this->edited(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QTextEdit::qt_property( id, f, v );
    }
    return TRUE;
}

bool QMultiLineEdit::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QToolBar::className() const
{
    return "QToolBar";
}

QMetaObject *QToolBar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QToolBar( "QToolBar", &QToolBar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QToolBar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QToolBar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QToolBar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QToolBar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QToolBar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDockWindow::staticMetaObject();
    static const QUMethod slot_0 = {"createPopup", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "createPopup()", &slot_0, QMetaData::Private }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[1] = {
 	{ "QString","label", 0x3000103, &QToolBar::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QToolBar", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 1,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QToolBar.setMetaObject( metaObj );
    return metaObj;
}

void* QToolBar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QToolBar" ) )
	return this;
    return QDockWindow::qt_cast( clname );
}

bool QToolBar::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: createPopup(); break;
    default:
	return QDockWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QToolBar::qt_emit( int _id, QUObject* _o )
{
    return QDockWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QToolBar::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setLabel(v->asString()); break;
	case 1: *v = QVariant( this->label() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QDockWindow::qt_property( id, f, v );
    }
    return TRUE;
}

bool QToolBar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTextView::className() const
{
    return "QTextView";
}

QMetaObject *QTextView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTextView( "QTextView", &QTextView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTextView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTextView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTextView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QTextEdit::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[5] = {
 	{ "int","undoDepth", 0x10025200, &QTextView::metaObj, 0, -1 },
	{ "bool","overwriteMode", 0x12025200, &QTextView::metaObj, 0, -1 },
	{ "bool","modified", 0x12026200, &QTextView::metaObj, 0, -1 },
	{ "bool","readOnly", 0x12025200, &QTextView::metaObj, 0, -1 },
	{ "bool","undoRedoEnabled", 0x12025200, &QTextView::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QTextView", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 5,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTextView.setMetaObject( metaObj );
    return metaObj;
}

void* QTextView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTextView" ) )
	return this;
    return QTextEdit::qt_cast( clname );
}

bool QTextView::qt_invoke( int _id, QUObject* _o )
{
    return QTextEdit::qt_invoke(_id,_o);
}

bool QTextView::qt_emit( int _id, QUObject* _o )
{
    return QTextEdit::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QTextView::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: case 1: case 3: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	default: return FALSE;
    } break;
    default:
	return QTextEdit::qt_property( id, f, v );
    }
    return TRUE;
resolve:
    return QTextEdit::qt_property( staticMetaObject()->resolveProperty(id), f, v );
}

bool QTextView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDataPump::className() const
{
    return "QDataPump";
}

QMetaObject *QDataPump::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDataPump( "QDataPump", &QDataPump::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDataPump::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDataPump", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDataPump::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDataPump", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDataPump::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"kickStart", 0, 0 };
    static const QUMethod slot_1 = {"tryToPump", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "kickStart()", &slot_0, QMetaData::Private },
	{ "tryToPump()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDataPump", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDataPump.setMetaObject( metaObj );
    return metaObj;
}

void* QDataPump::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDataPump" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QDataPump::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: kickStart(); break;
    case 1: tryToPump(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDataPump::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDataPump::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QDataPump::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QMainWindow::className() const
{
    return "QMainWindow";
}

QMetaObject *QMainWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMainWindow( "QMainWindow", &QMainWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMainWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMainWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMainWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMainWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMainWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setRightJustification", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setUsesBigPixmaps", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setUsesTextLabel", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"setDockWindowsMovable", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setOpaqueMoving", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"setDockMenuEnabled", 1, param_slot_5 };
    static const QUMethod slot_6 = {"whatsThis", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ "dw", &static_QUType_ptr, "QDockWindow", QUParameter::In },
	{ "a", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"setAppropriate", 2, param_slot_7 };
    static const QUMethod slot_8 = {"customize", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"setToolBarsMovable", 1, param_slot_9 };
    static const QUMethod slot_10 = {"setUpLayout", 0, 0 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "globalPos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_11 = {"showDockMenu", 2, param_slot_11 };
    static const QUMethod slot_12 = {"menuAboutToShow", 0, 0 };
    static const QUMethod slot_13 = {"slotPlaceChanged", 0, 0 };
    static const QUMethod slot_14 = {"doLineUp", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setRightJustification(bool)", &slot_0, QMetaData::Public },
	{ "setUsesBigPixmaps(bool)", &slot_1, QMetaData::Public },
	{ "setUsesTextLabel(bool)", &slot_2, QMetaData::Public },
	{ "setDockWindowsMovable(bool)", &slot_3, QMetaData::Public },
	{ "setOpaqueMoving(bool)", &slot_4, QMetaData::Public },
	{ "setDockMenuEnabled(bool)", &slot_5, QMetaData::Public },
	{ "whatsThis()", &slot_6, QMetaData::Public },
	{ "setAppropriate(QDockWindow*,bool)", &slot_7, QMetaData::Public },
	{ "customize()", &slot_8, QMetaData::Public },
	{ "setToolBarsMovable(bool)", &slot_9, QMetaData::Public },
	{ "setUpLayout()", &slot_10, QMetaData::Protected },
	{ "showDockMenu(const QPoint&)", &slot_11, QMetaData::Protected },
	{ "menuAboutToShow()", &slot_12, QMetaData::Protected },
	{ "slotPlaceChanged()", &slot_13, QMetaData::Private },
	{ "doLineUp()", &slot_14, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"pixmapSizeChanged", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"usesTextLabelChanged", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "QDockWindow", QUParameter::In }
    };
    static const QUMethod signal_2 = {"dockWindowPositionChanged", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "QToolBar", QUParameter::In }
    };
    static const QUMethod signal_3 = {"toolBarPositionChanged", 1, param_signal_3 };
    static const QMetaData signal_tbl[] = {
	{ "pixmapSizeChanged(bool)", &signal_0, QMetaData::Public },
	{ "usesTextLabelChanged(bool)", &signal_1, QMetaData::Public },
	{ "dockWindowPositionChanged(QDockWindow*)", &signal_2, QMetaData::Public },
	{ "toolBarPositionChanged(QToolBar*)", &signal_3, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[5] = {
 	{ "bool","rightJustification", 0x12001103, &QMainWindow::metaObj, 0, -1 },
	{ "bool","usesBigPixmaps", 0x12000103, &QMainWindow::metaObj, 0, -1 },
	{ "bool","usesTextLabel", 0x12000103, &QMainWindow::metaObj, 0, -1 },
	{ "bool","dockWindowsMovable", 0x12000103, &QMainWindow::metaObj, 0, -1 },
	{ "bool","opaqueMoving", 0x12000103, &QMainWindow::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QMainWindow", parentObject,
	slot_tbl, 15,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	props_tbl, 5,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMainWindow.setMetaObject( metaObj );
    return metaObj;
}

void* QMainWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMainWindow" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL pixmapSizeChanged
void QMainWindow::pixmapSizeChanged( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL usesTextLabelChanged
void QMainWindow::usesTextLabelChanged( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL dockWindowPositionChanged
void QMainWindow::dockWindowPositionChanged( QDockWindow* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL toolBarPositionChanged
void QMainWindow::toolBarPositionChanged( QToolBar* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QMainWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setRightJustification((bool)static_QUType_bool.get(_o+1)); break;
    case 1: setUsesBigPixmaps((bool)static_QUType_bool.get(_o+1)); break;
    case 2: setUsesTextLabel((bool)static_QUType_bool.get(_o+1)); break;
    case 3: setDockWindowsMovable((bool)static_QUType_bool.get(_o+1)); break;
    case 4: setOpaqueMoving((bool)static_QUType_bool.get(_o+1)); break;
    case 5: setDockMenuEnabled((bool)static_QUType_bool.get(_o+1)); break;
    case 6: whatsThis(); break;
    case 7: setAppropriate((QDockWindow*)static_QUType_ptr.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 8: customize(); break;
    case 9: setToolBarsMovable((bool)static_QUType_bool.get(_o+1)); break;
    case 10: setUpLayout(); break;
    case 11: static_QUType_bool.set(_o,showDockMenu((const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+1)))); break;
    case 12: menuAboutToShow(); break;
    case 13: slotPlaceChanged(); break;
    case 14: doLineUp(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QMainWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: pixmapSizeChanged((bool)static_QUType_bool.get(_o+1)); break;
    case 1: usesTextLabelChanged((bool)static_QUType_bool.get(_o+1)); break;
    case 2: dockWindowPositionChanged((QDockWindow*)static_QUType_ptr.get(_o+1)); break;
    case 3: toolBarPositionChanged((QToolBar*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QMainWindow::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setRightJustification(v->asBool()); break;
	case 1: *v = QVariant( this->rightJustification(), 0 ); break;
	case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setUsesBigPixmaps(v->asBool()); break;
	case 1: *v = QVariant( this->usesBigPixmaps(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setUsesTextLabel(v->asBool()); break;
	case 1: *v = QVariant( this->usesTextLabel(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setDockWindowsMovable(v->asBool()); break;
	case 1: *v = QVariant( this->dockWindowsMovable(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setOpaqueMoving(v->asBool()); break;
	case 1: *v = QVariant( this->opaqueMoving(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QMainWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QToolBox::className() const
{
    return "QToolBox";
}

QMetaObject *QToolBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QToolBox( "QToolBox", &QToolBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QToolBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QToolBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QToolBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QToolBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QToolBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setCurrentIndex", 1, param_slot_0 };
    static const QUMethod slot_1 = {"buttonClicked", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "QObject", QUParameter::In }
    };
    static const QUMethod slot_2 = {"itemDestroyed", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "setCurrentIndex(int)", &slot_0, QMetaData::Public },
	{ "buttonClicked()", &slot_1, QMetaData::Private },
	{ "itemDestroyed(QObject*)", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"currentChanged", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "currentChanged(int)", &signal_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[2] = {
 	{ "int","currentIndex", 0x10000103, &QToolBox::metaObj, 0, -1 },
	{ "int","count", 0x10000001, &QToolBox::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QToolBox", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	props_tbl, 2,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QToolBox.setMetaObject( metaObj );
    return metaObj;
}

void* QToolBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QToolBox" ) )
	return this;
    return QFrame::qt_cast( clname );
}

// SIGNAL currentChanged
void QToolBox::currentChanged( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool QToolBox::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setCurrentIndex((int)static_QUType_int.get(_o+1)); break;
    case 1: buttonClicked(); break;
    case 2: itemDestroyed((QObject*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QToolBox::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: currentChanged((int)static_QUType_int.get(_o+1)); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QToolBox::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setCurrentIndex(v->asInt()); break;
	case 1: *v = QVariant( this->currentIndex() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 1: *v = QVariant( this->count() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QFrame::qt_property( id, f, v );
    }
    return TRUE;
}

bool QToolBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QToolButton::className() const
{
    return "QToolButton";
}

QMetaObject *QToolButton::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QToolButton( "QToolButton", &QToolButton::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QToolButton::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QToolButton", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QToolButton::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QToolButton", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QToolButton::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QButton::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "BesideIcon",  (int) QToolButton::BesideIcon },
	{ "BelowIcon",  (int) QToolButton::BelowIcon },
	{ "Right",  (int) QToolButton::Right },
	{ "Under",  (int) QToolButton::Under }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "TextPosition", 4, enum_0, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ "enable", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setUsesBigPixmap", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "enable", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setUsesTextLabel", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setTextLabel", 2, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "enable", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"setToggleButton", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "enable", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setOn", 1, param_slot_4 };
    static const QUMethod slot_5 = {"toggle", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"setTextLabel", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "pos", &static_QUType_enum, 
#ifndef QT_NO_PROPERTIES
	  &enum_tbl[0]
#else
	  0
#endif // QT_NO_PROPERTIES
	  , QUParameter::In }
    };
    static const QUMethod slot_7 = {"setTextPosition", 1, param_slot_7 };
    static const QUMethod slot_8 = {"popupTimerDone", 0, 0 };
    static const QUMethod slot_9 = {"popupPressed", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setUsesBigPixmap(bool)", &slot_0, QMetaData::Public },
	{ "setUsesTextLabel(bool)", &slot_1, QMetaData::Public },
	{ "setTextLabel(const QString&,bool)", &slot_2, QMetaData::Public },
	{ "setToggleButton(bool)", &slot_3, QMetaData::Public },
	{ "setOn(bool)", &slot_4, QMetaData::Public },
	{ "toggle()", &slot_5, QMetaData::Public },
	{ "setTextLabel(const QString&)", &slot_6, QMetaData::Public },
	{ "setTextPosition(TextPosition)", &slot_7, QMetaData::Public },
	{ "popupTimerDone()", &slot_8, QMetaData::Private },
	{ "popupPressed()", &slot_9, QMetaData::Private }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[13] = {
 	{ "QIconSet","iconSet", 0xd000103, &QToolButton::metaObj, 0, -1 },
	{ "QIconSet","onIconSet", 0xd011103, &QToolButton::metaObj, 0, -1 },
	{ "QIconSet","offIconSet", 0xd011103, &QToolButton::metaObj, 0, -1 },
	{ "bool","usesBigPixmap", 0x12000103, &QToolButton::metaObj, 0, -1 },
	{ "bool","usesTextLabel", 0x12000103, &QToolButton::metaObj, 0, -1 },
	{ "QString","textLabel", 0x3000103, &QToolButton::metaObj, 0, -1 },
	{ "int","popupDelay", 0x10000103, &QToolButton::metaObj, 0, -1 },
	{ "bool","autoRaise", 0x12000103, &QToolButton::metaObj, 0, -1 },
	{ "TextPosition","textPosition", 0x0107, &QToolButton::metaObj, &enum_tbl[0], -1 },
	{ "bool","toggleButton", 0x1202a302, &QToolButton::metaObj, 0, -1 },
	{ "bool","on", 0x1202a302, &QToolButton::metaObj, 0, -1 },
	{ "QPixmap","pixmap", 0x6019200, &QToolButton::metaObj, 0, -1 },
	{ "BackgroundMode","backgroundMode", 0x2820c, &QToolButton::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QToolButton", parentObject,
	slot_tbl, 10,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 13,
	enum_tbl, 1,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QToolButton.setMetaObject( metaObj );
    return metaObj;
}

void* QToolButton::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QToolButton" ) )
	return this;
    return QButton::qt_cast( clname );
}

bool QToolButton::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setUsesBigPixmap((bool)static_QUType_bool.get(_o+1)); break;
    case 1: setUsesTextLabel((bool)static_QUType_bool.get(_o+1)); break;
    case 2: setTextLabel((const QString&)static_QUType_QString.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 3: setToggleButton((bool)static_QUType_bool.get(_o+1)); break;
    case 4: setOn((bool)static_QUType_bool.get(_o+1)); break;
    case 5: toggle(); break;
    case 6: setTextLabel((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: setTextPosition((TextPosition)static_QUType_enum.get(_o+1)); break;
    case 8: popupTimerDone(); break;
    case 9: popupPressed(); break;
    default:
	return QButton::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QToolButton::qt_emit( int _id, QUObject* _o )
{
    return QButton::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QToolButton::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setIconSet(v->asIconSet()); break;
	case 1: *v = QVariant( this->iconSet() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setOnIconSet(v->asIconSet()); break;
	case 1: *v = QVariant( this->onIconSet() ); break;
	case 4: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setOffIconSet(v->asIconSet()); break;
	case 1: *v = QVariant( this->offIconSet() ); break;
	case 4: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setUsesBigPixmap(v->asBool()); break;
	case 1: *v = QVariant( this->usesBigPixmap(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setUsesTextLabel(v->asBool()); break;
	case 1: *v = QVariant( this->usesTextLabel(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setTextLabel(v->asString()); break;
	case 1: *v = QVariant( this->textLabel() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setPopupDelay(v->asInt()); break;
	case 1: *v = QVariant( this->popupDelay() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setAutoRaise(v->asBool()); break;
	case 1: *v = QVariant( this->autoRaise(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setTextPosition((TextPosition&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->textPosition() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setToggleButton(v->asBool()); break;
	case 1: case 3: case 4: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 0: setOn(v->asBool()); break;
	case 1: case 3: case 4: case 5: goto resolve;
	default: return FALSE;
    } break;
    case 11: switch( f ) {
	case 0: case 1: case 4: goto resolve;
	default: return FALSE;
    } break;
    case 12: switch( f ) {
	case 0: case 1: case 4: case 5: goto resolve;
	case 3: break;
	default: return FALSE;
    } break;
    default:
	return QButton::qt_property( id, f, v );
    }
    return TRUE;
resolve:
    return QButton::qt_property( staticMetaObject()->resolveProperty(id), f, v );
}

bool QToolButton::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QToolTipGroup::className() const
{
    return "QToolTipGroup";
}

QMetaObject *QToolTipGroup::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QToolTipGroup( "QToolTipGroup", &QToolTipGroup::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QToolTipGroup::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QToolTipGroup", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QToolTipGroup::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QToolTipGroup", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QToolTipGroup::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setDelay", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setEnabled", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "setDelay(bool)", &slot_0, QMetaData::Public },
	{ "setEnabled(bool)", &slot_1, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"showTip", 1, param_signal_0 };
    static const QUMethod signal_1 = {"removeTip", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "showTip(const QString&)", &signal_0, QMetaData::Public },
	{ "removeTip()", &signal_1, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[2] = {
 	{ "bool","delay", 0x12000103, &QToolTipGroup::metaObj, 0, -1 },
	{ "bool","enabled", 0x12000103, &QToolTipGroup::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QToolTipGroup", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	props_tbl, 2,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QToolTipGroup.setMetaObject( metaObj );
    return metaObj;
}

void* QToolTipGroup::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QToolTipGroup" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL showTip
void QToolTipGroup::showTip( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL removeTip
void QToolTipGroup::removeTip()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool QToolTipGroup::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setDelay((bool)static_QUType_bool.get(_o+1)); break;
    case 1: setEnabled((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QToolTipGroup::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: showTip((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: removeTip(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QToolTipGroup::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setDelay(v->asBool()); break;
	case 1: *v = QVariant( this->delay(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->enabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QObject::qt_property( id, f, v );
    }
    return TRUE;
}

bool QToolTipGroup::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDesktopWidget::className() const
{
    return "QDesktopWidget";
}

QMetaObject *QDesktopWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDesktopWidget( "QDesktopWidget", &QDesktopWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDesktopWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDesktopWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDesktopWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDesktopWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDesktopWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"resized", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"workAreaResized", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "resized(int)", &signal_0, QMetaData::Public },
	{ "workAreaResized(int)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDesktopWidget", parentObject,
	0, 0,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDesktopWidget.setMetaObject( metaObj );
    return metaObj;
}

void* QDesktopWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDesktopWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL resized
void QDesktopWidget::resized( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL workAreaResized
void QDesktopWidget::workAreaResized( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

bool QDesktopWidget::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool QDesktopWidget::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: resized((int)static_QUType_int.get(_o+1)); break;
    case 1: workAreaResized((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QDesktopWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QDesktopWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QUrlOperator::className() const
{
    return "QUrlOperator";
}

QMetaObject *QUrlOperator::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QUrlOperator( "QUrlOperator", &QUrlOperator::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QUrlOperator::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QUrlOperator", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QUrlOperator::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QUrlOperator", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QUrlOperator::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QNetworkOperation", QUParameter::Out },
	{ "op", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_0 = {"startOperation", 2, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "data", &static_QUType_varptr, "\x1d", QUParameter::In },
	{ "op", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_1 = {"copyGotData", 2, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "op", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_2 = {"continueCopy", 1, param_slot_2 };
    static const QUMethod slot_3 = {"finishedCopy", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "i", &static_QUType_ptr, "QValueList<QUrlInfo>", QUParameter::In }
    };
    static const QUMethod slot_4 = {"addEntry", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "op", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_5 = {"slotItemChanged", 1, param_slot_5 };
    static const QMetaData slot_tbl[] = {
	{ "startOperation(QNetworkOperation*)", &slot_0, QMetaData::Private },
	{ "copyGotData(const QByteArray&,QNetworkOperation*)", &slot_1, QMetaData::Private },
	{ "continueCopy(QNetworkOperation*)", &slot_2, QMetaData::Private },
	{ "finishedCopy()", &slot_3, QMetaData::Private },
	{ "addEntry(const QValueList<QUrlInfo>&)", &slot_4, QMetaData::Private },
	{ "slotItemChanged(QNetworkOperation*)", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "QValueList<QUrlInfo>", QUParameter::In },
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_0 = {"newChildren", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_1 = {"finished", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_2 = {"start", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "QUrlInfo", QUParameter::In },
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_3 = {"createdDirectory", 2, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_4 = {"removed", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_5 = {"itemChanged", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_varptr, "\x1d", QUParameter::In },
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_6 = {"data", 2, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ "bytesDone", &static_QUType_int, 0, QUParameter::In },
	{ "bytesTotal", &static_QUType_int, 0, QUParameter::In },
	{ "res", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod signal_7 = {"dataTransferProgress", 3, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ "lst", &static_QUType_ptr, "QPtrList<QNetworkOperation>", QUParameter::In }
    };
    static const QUMethod signal_8 = {"startedNextCopy", 1, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ "state", &static_QUType_int, 0, QUParameter::In },
	{ "data", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_9 = {"connectionStateChanged", 2, param_signal_9 };
    static const QMetaData signal_tbl[] = {
	{ "newChildren(const QValueList<QUrlInfo>&,QNetworkOperation*)", &signal_0, QMetaData::Public },
	{ "finished(QNetworkOperation*)", &signal_1, QMetaData::Public },
	{ "start(QNetworkOperation*)", &signal_2, QMetaData::Public },
	{ "createdDirectory(const QUrlInfo&,QNetworkOperation*)", &signal_3, QMetaData::Public },
	{ "removed(QNetworkOperation*)", &signal_4, QMetaData::Public },
	{ "itemChanged(QNetworkOperation*)", &signal_5, QMetaData::Public },
	{ "data(const QByteArray&,QNetworkOperation*)", &signal_6, QMetaData::Public },
	{ "dataTransferProgress(int,int,QNetworkOperation*)", &signal_7, QMetaData::Public },
	{ "startedNextCopy(const QPtrList<QNetworkOperation>&)", &signal_8, QMetaData::Public },
	{ "connectionStateChanged(int,const QString&)", &signal_9, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QUrlOperator", parentObject,
	slot_tbl, 6,
	signal_tbl, 10,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QUrlOperator.setMetaObject( metaObj );
    return metaObj;
}

void* QUrlOperator::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QUrlOperator" ) )
	return this;
    if ( !qstrcmp( clname, "QUrl" ) )
	return (QUrl*)this;
    return QObject::qt_cast( clname );
}

// SIGNAL newChildren
void QUrlOperator::newChildren( const QValueList<QUrlInfo>& t0, QNetworkOperation* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL finished
void QUrlOperator::finished( QNetworkOperation* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL start
void QUrlOperator::start( QNetworkOperation* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL createdDirectory
void QUrlOperator::createdDirectory( const QUrlInfo& t0, QNetworkOperation* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL removed
void QUrlOperator::removed( QNetworkOperation* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL itemChanged
void QUrlOperator::itemChanged( QNetworkOperation* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL data
void QUrlOperator::data( const QByteArray& t0, QNetworkOperation* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_varptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL dataTransferProgress
void QUrlOperator::dataTransferProgress( int t0, int t1, QNetworkOperation* t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_ptr.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL startedNextCopy
void QUrlOperator::startedNextCopy( const QPtrList<QNetworkOperation>& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL connectionStateChanged
void QUrlOperator::connectionStateChanged( int t0, const QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

bool QUrlOperator::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: static_QUType_ptr.set(_o,startOperation((QNetworkOperation*)static_QUType_ptr.get(_o+1))); break;
    case 1: copyGotData((const QByteArray&)*((const QByteArray*)static_QUType_ptr.get(_o+1)),(QNetworkOperation*)static_QUType_ptr.get(_o+2)); break;
    case 2: continueCopy((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 3: finishedCopy(); break;
    case 4: addEntry((const QValueList<QUrlInfo>&)*((const QValueList<QUrlInfo>*)static_QUType_ptr.get(_o+1))); break;
    case 5: slotItemChanged((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QUrlOperator::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: newChildren((const QValueList<QUrlInfo>&)*((const QValueList<QUrlInfo>*)static_QUType_ptr.get(_o+1)),(QNetworkOperation*)static_QUType_ptr.get(_o+2)); break;
    case 1: finished((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 2: start((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 3: createdDirectory((const QUrlInfo&)*((const QUrlInfo*)static_QUType_ptr.get(_o+1)),(QNetworkOperation*)static_QUType_ptr.get(_o+2)); break;
    case 4: removed((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 5: itemChanged((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 6: data((const QByteArray&)*((const QByteArray*)static_QUType_ptr.get(_o+1)),(QNetworkOperation*)static_QUType_ptr.get(_o+2)); break;
    case 7: dataTransferProgress((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(QNetworkOperation*)static_QUType_ptr.get(_o+3)); break;
    case 8: startedNextCopy((const QPtrList<QNetworkOperation>&)*((const QPtrList<QNetworkOperation>*)static_QUType_ptr.get(_o+1))); break;
    case 9: connectionStateChanged((int)static_QUType_int.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QUrlOperator::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QUrlOperator::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QFileIconProvider::className() const
{
    return "QFileIconProvider";
}

QMetaObject *QFileIconProvider::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFileIconProvider( "QFileIconProvider", &QFileIconProvider::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFileIconProvider::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFileIconProvider", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFileIconProvider::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFileIconProvider", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFileIconProvider::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QFileIconProvider", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFileIconProvider.setMetaObject( metaObj );
    return metaObj;
}

void* QFileIconProvider::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFileIconProvider" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QFileIconProvider::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QFileIconProvider::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QFileIconProvider::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QFileIconProvider::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QFileDialog::className() const
{
    return "QFileDialog";
}

QMetaObject *QFileDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QFileDialog( "QFileDialog", &QFileDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QFileDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFileDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QFileDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QFileDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QFileDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaEnum::Item enum_0[] = {
	{ "AnyFile",  (int) QFileDialog::AnyFile },
	{ "ExistingFile",  (int) QFileDialog::ExistingFile },
	{ "Directory",  (int) QFileDialog::Directory },
	{ "ExistingFiles",  (int) QFileDialog::ExistingFiles },
	{ "DirectoryOnly",  (int) QFileDialog::DirectoryOnly }
    };
    static const QMetaEnum::Item enum_1[] = {
	{ "Detail",  (int) QFileDialog::Detail },
	{ "List",  (int) QFileDialog::List }
    };
    static const QMetaEnum::Item enum_2[] = {
	{ "NoPreview",  (int) QFileDialog::NoPreview },
	{ "Contents",  (int) QFileDialog::Contents },
	{ "Info",  (int) QFileDialog::Info }
    };
    static const QMetaEnum enum_tbl[] = {
	{ "Mode", 5, enum_0, FALSE },
	{ "ViewMode", 2, enum_1, FALSE },
	{ "PreviewMode", 3, enum_2, FALSE }
    };
#endif // QT_NO_PROPERTIES
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"done", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setDir", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "url", &static_QUType_ptr, "QUrlOperator", QUParameter::In }
    };
    static const QUMethod slot_2 = {"setUrl", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"setFilter", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setFilters", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_ptr, "char*", QUParameter::In }
    };
    static const QUMethod slot_5 = {"setFilters", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_varptr, "\x04", QUParameter::In }
    };
    static const QUMethod slot_6 = {"setFilters", 1, param_slot_6 };
    static const QUMethod slot_7 = {"detailViewSelectionChanged", 0, 0 };
    static const QUMethod slot_8 = {"listBoxSelectionChanged", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"changeMode", 1, param_slot_9 };
    static const QUMethod slot_10 = {"fileNameEditReturnPressed", 0, 0 };
    static const QUMethod slot_11 = {"stopCopy", 0, 0 };
    static const QUMethod slot_12 = {"removeProgressDia", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"fileSelected", 1, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"fileHighlighted", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"dirSelected", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"pathSelected", 1, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_17 = {"updateFileNameEdit", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_18 = {"selectDirectoryOrFile", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"popupContextMenu", 3, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_20 = {"popupContextMenu", 2, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod slot_21 = {"updateFileNameEdit", 1, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ 0, &static_QUType_ptr, "QListBoxItem", QUParameter::In }
    };
    static const QUMethod slot_22 = {"selectDirectoryOrFile", 1, param_slot_22 };
    static const QUMethod slot_23 = {"fileNameEditDone", 0, 0 };
    static const QUMethod slot_24 = {"okClicked", 0, 0 };
    static const QUMethod slot_25 = {"filterClicked", 0, 0 };
    static const QUMethod slot_26 = {"cancelClicked", 0, 0 };
    static const QUMethod slot_27 = {"cdUpClicked", 0, 0 };
    static const QUMethod slot_28 = {"newFolderClicked", 0, 0 };
    static const QUMethod slot_29 = {"fixupNameEdit", 0, 0 };
    static const QUMethod slot_30 = {"doMimeTypeLookup", 0, 0 };
    static const QUMethod slot_31 = {"updateGeometries", 0, 0 };
    static const QUMethod slot_32 = {"modeButtonsDestroyed", 0, 0 };
    static const QUParameter param_slot_33[] = {
	{ "op", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_33 = {"urlStart", 1, param_slot_33 };
    static const QUParameter param_slot_34[] = {
	{ "op", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_34 = {"urlFinished", 1, param_slot_34 };
    static const QUParameter param_slot_35[] = {
	{ "bytesDone", &static_QUType_int, 0, QUParameter::In },
	{ "bytesTotal", &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_35 = {"dataTransferProgress", 3, param_slot_35 };
    static const QUParameter param_slot_36[] = {
	{ "fi", &static_QUType_ptr, "QValueList<QUrlInfo>", QUParameter::In },
	{ "op", &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_36 = {"insertEntry", 2, param_slot_36 };
    static const QUParameter param_slot_37[] = {
	{ 0, &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_37 = {"removeEntry", 1, param_slot_37 };
    static const QUParameter param_slot_38[] = {
	{ "info", &static_QUType_ptr, "QUrlInfo", QUParameter::In },
	{ 0, &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_38 = {"createdDirectory", 2, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ 0, &static_QUType_ptr, "QNetworkOperation", QUParameter::In }
    };
    static const QUMethod slot_39 = {"itemChanged", 1, param_slot_39 };
    static const QUMethod slot_40 = {"goBack", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "done(int)", &slot_0, QMetaData::Public },
	{ "setDir(const QString&)", &slot_1, QMetaData::Public },
	{ "setUrl(const QUrlOperator&)", &slot_2, QMetaData::Public },
	{ "setFilter(const QString&)", &slot_3, QMetaData::Public },
	{ "setFilters(const QString&)", &slot_4, QMetaData::Public },
	{ "setFilters(const char**)", &slot_5, QMetaData::Public },
	{ "setFilters(const QStringList&)", &slot_6, QMetaData::Public },
	{ "detailViewSelectionChanged()", &slot_7, QMetaData::Private },
	{ "listBoxSelectionChanged()", &slot_8, QMetaData::Private },
	{ "changeMode(int)", &slot_9, QMetaData::Private },
	{ "fileNameEditReturnPressed()", &slot_10, QMetaData::Private },
	{ "stopCopy()", &slot_11, QMetaData::Private },
	{ "removeProgressDia()", &slot_12, QMetaData::Private },
	{ "fileSelected(int)", &slot_13, QMetaData::Private },
	{ "fileHighlighted(int)", &slot_14, QMetaData::Private },
	{ "dirSelected(int)", &slot_15, QMetaData::Private },
	{ "pathSelected(int)", &slot_16, QMetaData::Private },
	{ "updateFileNameEdit(QListViewItem*)", &slot_17, QMetaData::Private },
	{ "selectDirectoryOrFile(QListViewItem*)", &slot_18, QMetaData::Private },
	{ "popupContextMenu(QListViewItem*,const QPoint&,int)", &slot_19, QMetaData::Private },
	{ "popupContextMenu(QListBoxItem*,const QPoint&)", &slot_20, QMetaData::Private },
	{ "updateFileNameEdit(QListBoxItem*)", &slot_21, QMetaData::Private },
	{ "selectDirectoryOrFile(QListBoxItem*)", &slot_22, QMetaData::Private },
	{ "fileNameEditDone()", &slot_23, QMetaData::Private },
	{ "okClicked()", &slot_24, QMetaData::Private },
	{ "filterClicked()", &slot_25, QMetaData::Private },
	{ "cancelClicked()", &slot_26, QMetaData::Private },
	{ "cdUpClicked()", &slot_27, QMetaData::Private },
	{ "newFolderClicked()", &slot_28, QMetaData::Private },
	{ "fixupNameEdit()", &slot_29, QMetaData::Private },
	{ "doMimeTypeLookup()", &slot_30, QMetaData::Private },
	{ "updateGeometries()", &slot_31, QMetaData::Private },
	{ "modeButtonsDestroyed()", &slot_32, QMetaData::Private },
	{ "urlStart(QNetworkOperation*)", &slot_33, QMetaData::Private },
	{ "urlFinished(QNetworkOperation*)", &slot_34, QMetaData::Private },
	{ "dataTransferProgress(int,int,QNetworkOperation*)", &slot_35, QMetaData::Private },
	{ "insertEntry(const QValueList<QUrlInfo>&,QNetworkOperation*)", &slot_36, QMetaData::Private },
	{ "removeEntry(QNetworkOperation*)", &slot_37, QMetaData::Private },
	{ "createdDirectory(const QUrlInfo&,QNetworkOperation*)", &slot_38, QMetaData::Private },
	{ "itemChanged(QNetworkOperation*)", &slot_39, QMetaData::Private },
	{ "goBack()", &slot_40, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"fileHighlighted", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"fileSelected", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_varptr, "\x04", QUParameter::In }
    };
    static const QUMethod signal_2 = {"filesSelected", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"dirEntered", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"filterSelected", 1, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "fileHighlighted(const QString&)", &signal_0, QMetaData::Protected },
	{ "fileSelected(const QString&)", &signal_1, QMetaData::Protected },
	{ "filesSelected(const QStringList&)", &signal_2, QMetaData::Protected },
	{ "dirEntered(const QString&)", &signal_3, QMetaData::Protected },
	{ "filterSelected(const QString&)", &signal_4, QMetaData::Protected }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[10] = {
 	{ "QString","selectedFile", 0x3000001, &QFileDialog::metaObj, 0, -1 },
	{ "QString","selectedFilter", 0x3000001, &QFileDialog::metaObj, 0, -1 },
	{ "QStringList","selectedFiles", 0x4000001, &QFileDialog::metaObj, 0, -1 },
	{ "QString","dirPath", 0x3000001, &QFileDialog::metaObj, 0, -1 },
	{ "bool","showHiddenFiles", 0x12000103, &QFileDialog::metaObj, 0, -1 },
	{ "Mode","mode", 0x0107, &QFileDialog::metaObj, &enum_tbl[0], -1 },
	{ "ViewMode","viewMode", 0x0107, &QFileDialog::metaObj, &enum_tbl[1], -1 },
	{ "PreviewMode","previewMode", 0x0107, &QFileDialog::metaObj, &enum_tbl[2], -1 },
	{ "bool","infoPreview", 0x12000003, &QFileDialog::metaObj, 0, -1 },
	{ "bool","contentsPreview", 0x12000003, &QFileDialog::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QFileDialog", parentObject,
	slot_tbl, 41,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	props_tbl, 10,
	enum_tbl, 3,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QFileDialog.setMetaObject( metaObj );
    return metaObj;
}

void* QFileDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QFileDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

// SIGNAL fileHighlighted
void QFileDialog::fileHighlighted( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL fileSelected
void QFileDialog::fileSelected( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL filesSelected
void QFileDialog::filesSelected( const QStringList& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_varptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL dirEntered
void QFileDialog::dirEntered( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 3, t0 );
}

// SIGNAL filterSelected
void QFileDialog::filterSelected( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 4, t0 );
}

bool QFileDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: done((int)static_QUType_int.get(_o+1)); break;
    case 1: setDir((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: setUrl((const QUrlOperator&)*((const QUrlOperator*)static_QUType_ptr.get(_o+1))); break;
    case 3: setFilter((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: setFilters((const QString&)static_QUType_QString.get(_o+1)); break;
    case 5: setFilters((const char**)static_QUType_ptr.get(_o+1)); break;
    case 6: setFilters((const QStringList&)*((const QStringList*)static_QUType_ptr.get(_o+1))); break;
    case 7: detailViewSelectionChanged(); break;
    case 8: listBoxSelectionChanged(); break;
    case 9: changeMode((int)static_QUType_int.get(_o+1)); break;
    case 10: fileNameEditReturnPressed(); break;
    case 11: stopCopy(); break;
    case 12: removeProgressDia(); break;
    case 13: fileSelected((int)static_QUType_int.get(_o+1)); break;
    case 14: fileHighlighted((int)static_QUType_int.get(_o+1)); break;
    case 15: dirSelected((int)static_QUType_int.get(_o+1)); break;
    case 16: pathSelected((int)static_QUType_int.get(_o+1)); break;
    case 17: updateFileNameEdit((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 18: selectDirectoryOrFile((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 19: popupContextMenu((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 20: popupContextMenu((QListBoxItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 21: updateFileNameEdit((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 22: selectDirectoryOrFile((QListBoxItem*)static_QUType_ptr.get(_o+1)); break;
    case 23: fileNameEditDone(); break;
    case 24: okClicked(); break;
    case 25: filterClicked(); break;
    case 26: cancelClicked(); break;
    case 27: cdUpClicked(); break;
    case 28: newFolderClicked(); break;
    case 29: fixupNameEdit(); break;
    case 30: doMimeTypeLookup(); break;
    case 31: updateGeometries(); break;
    case 32: modeButtonsDestroyed(); break;
    case 33: urlStart((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 34: urlFinished((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 35: dataTransferProgress((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(QNetworkOperation*)static_QUType_ptr.get(_o+3)); break;
    case 36: insertEntry((const QValueList<QUrlInfo>&)*((const QValueList<QUrlInfo>*)static_QUType_ptr.get(_o+1)),(QNetworkOperation*)static_QUType_ptr.get(_o+2)); break;
    case 37: removeEntry((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 38: createdDirectory((const QUrlInfo&)*((const QUrlInfo*)static_QUType_ptr.get(_o+1)),(QNetworkOperation*)static_QUType_ptr.get(_o+2)); break;
    case 39: itemChanged((QNetworkOperation*)static_QUType_ptr.get(_o+1)); break;
    case 40: goBack(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QFileDialog::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: fileHighlighted((const QString&)static_QUType_QString.get(_o+1)); break;
    case 1: fileSelected((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: filesSelected((const QStringList&)*((const QStringList*)static_QUType_ptr.get(_o+1))); break;
    case 3: dirEntered((const QString&)static_QUType_QString.get(_o+1)); break;
    case 4: filterSelected((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QDialog::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QFileDialog::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 1: *v = QVariant( this->selectedFile() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 1: *v = QVariant( this->selectedFilter() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 1: *v = QVariant( this->selectedFiles() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 1: *v = QVariant( this->dirPath() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setShowHiddenFiles(v->asBool()); break;
	case 1: *v = QVariant( this->showHiddenFiles(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setMode((Mode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->mode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setViewMode((ViewMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->viewMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setPreviewMode((PreviewMode&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->previewMode() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setInfoPreviewEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isInfoPreviewEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setContentsPreviewEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->isContentsPreviewEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QDialog::qt_property( id, f, v );
    }
    return TRUE;
}

bool QFileDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QValidator::className() const
{
    return "QValidator";
}

QMetaObject *QValidator::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QValidator( "QValidator", &QValidator::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QValidator::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QValidator", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QValidator::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QValidator", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QValidator::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QValidator", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QValidator.setMetaObject( metaObj );
    return metaObj;
}

void* QValidator::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QValidator" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QValidator::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QValidator::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QValidator::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QValidator::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QIntValidator::className() const
{
    return "QIntValidator";
}

QMetaObject *QIntValidator::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QIntValidator( "QIntValidator", &QIntValidator::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QIntValidator::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QIntValidator", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QIntValidator::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QIntValidator", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QIntValidator::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QValidator::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[2] = {
 	{ "int","bottom", 0x10000103, &QIntValidator::metaObj, 0, -1 },
	{ "int","top", 0x10000103, &QIntValidator::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QIntValidator", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 2,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QIntValidator.setMetaObject( metaObj );
    return metaObj;
}

void* QIntValidator::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QIntValidator" ) )
	return this;
    return QValidator::qt_cast( clname );
}

bool QIntValidator::qt_invoke( int _id, QUObject* _o )
{
    return QValidator::qt_invoke(_id,_o);
}

bool QIntValidator::qt_emit( int _id, QUObject* _o )
{
    return QValidator::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QIntValidator::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setBottom(v->asInt()); break;
	case 1: *v = QVariant( this->bottom() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setTop(v->asInt()); break;
	case 1: *v = QVariant( this->top() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QValidator::qt_property( id, f, v );
    }
    return TRUE;
}

bool QIntValidator::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDoubleValidator::className() const
{
    return "QDoubleValidator";
}

QMetaObject *QDoubleValidator::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDoubleValidator( "QDoubleValidator", &QDoubleValidator::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDoubleValidator::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDoubleValidator", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDoubleValidator::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDoubleValidator", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDoubleValidator::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QValidator::staticMetaObject();
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[3] = {
 	{ "double","bottom", 0x13000103, &QDoubleValidator::metaObj, 0, -1 },
	{ "double","top", 0x13000103, &QDoubleValidator::metaObj, 0, -1 },
	{ "int","decimals", 0x10000103, &QDoubleValidator::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QDoubleValidator", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 3,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDoubleValidator.setMetaObject( metaObj );
    return metaObj;
}

void* QDoubleValidator::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDoubleValidator" ) )
	return this;
    return QValidator::qt_cast( clname );
}

bool QDoubleValidator::qt_invoke( int _id, QUObject* _o )
{
    return QValidator::qt_invoke(_id,_o);
}

bool QDoubleValidator::qt_emit( int _id, QUObject* _o )
{
    return QValidator::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QDoubleValidator::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setBottom(v->asDouble()); break;
	case 1: *v = QVariant( this->bottom() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setTop(v->asDouble()); break;
	case 1: *v = QVariant( this->top() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setDecimals(v->asInt()); break;
	case 1: *v = QVariant( this->decimals() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QValidator::qt_property( id, f, v );
    }
    return TRUE;
}

bool QDoubleValidator::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QRegExpValidator::className() const
{
    return "QRegExpValidator";
}

QMetaObject *QRegExpValidator::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QRegExpValidator( "QRegExpValidator", &QRegExpValidator::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QRegExpValidator::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegExpValidator", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QRegExpValidator::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QRegExpValidator", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QRegExpValidator::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QValidator::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QRegExpValidator", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QRegExpValidator.setMetaObject( metaObj );
    return metaObj;
}

void* QRegExpValidator::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QRegExpValidator" ) )
	return this;
    return QValidator::qt_cast( clname );
}

bool QRegExpValidator::qt_invoke( int _id, QUObject* _o )
{
    return QValidator::qt_invoke(_id,_o);
}

bool QRegExpValidator::qt_emit( int _id, QUObject* _o )
{
    return QValidator::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QRegExpValidator::qt_property( int id, int f, QVariant* v)
{
    return QValidator::qt_property( id, f, v);
}

bool QRegExpValidator::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDataTable::className() const
{
    return "QDataTable";
}

QMetaObject *QDataTable::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDataTable( "QDataTable", &QDataTable::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDataTable::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDataTable", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDataTable::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDataTable", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDataTable::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QTable::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "str", &static_QUType_QString, 0, QUParameter::In },
	{ "caseSensitive", &static_QUType_bool, 0, QUParameter::In },
	{ "backwards", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"find", 3, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"sortAscending", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"sortDescending", 1, param_slot_2 };
    static const QUMethod slot_3 = {"refresh", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "w", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setColumnWidth", 2, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"adjustColumn", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "stretch", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"setColumnStretchable", 2, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "col1", &static_QUType_int, 0, QUParameter::In },
	{ "col2", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"swapColumns", 2, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "col1", &static_QUType_int, 0, QUParameter::In },
	{ "col2", &static_QUType_int, 0, QUParameter::In },
	{ "swapHeaders", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"swapColumns", 3, param_slot_8 };
    static const QUMethod slot_9 = {"loadNextPage", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"setCurrentSelection", 2, param_slot_10 };
    static const QUMethod slot_11 = {"updateCurrentSelection", 0, 0 };
    static const QUMethod slot_12 = {"sliderPressed", 0, 0 };
    static const QUMethod slot_13 = {"sliderReleased", 0, 0 };
    static const QUMethod slot_14 = {"doInsertCurrent", 0, 0 };
    static const QUMethod slot_15 = {"doUpdateCurrent", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "find(const QString&,bool,bool)", &slot_0, QMetaData::Public },
	{ "sortAscending(int)", &slot_1, QMetaData::Public },
	{ "sortDescending(int)", &slot_2, QMetaData::Public },
	{ "refresh()", &slot_3, QMetaData::Public },
	{ "setColumnWidth(int,int)", &slot_4, QMetaData::Public },
	{ "adjustColumn(int)", &slot_5, QMetaData::Public },
	{ "setColumnStretchable(int,bool)", &slot_6, QMetaData::Public },
	{ "swapColumns(int,int)", &slot_7, QMetaData::Public },
	{ "swapColumns(int,int,bool)", &slot_8, QMetaData::Public },
	{ "loadNextPage()", &slot_9, QMetaData::Private },
	{ "setCurrentSelection(int,int)", &slot_10, QMetaData::Private },
	{ "updateCurrentSelection()", &slot_11, QMetaData::Private },
	{ "sliderPressed()", &slot_12, QMetaData::Private },
	{ "sliderReleased()", &slot_13, QMetaData::Private },
	{ "doInsertCurrent()", &slot_14, QMetaData::Private },
	{ "doUpdateCurrent()", &slot_15, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "record", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_0 = {"currentChanged", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_1 = {"primeInsert", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_2 = {"primeUpdate", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_3 = {"primeDelete", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_4 = {"beforeInsert", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_5 = {"beforeUpdate", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ "buf", &static_QUType_ptr, "QSqlRecord", QUParameter::In }
    };
    static const QUMethod signal_6 = {"beforeDelete", 1, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ "mode", &static_QUType_ptr, "QSql::Op", QUParameter::In }
    };
    static const QUMethod signal_7 = {"cursorChanged", 1, param_signal_7 };
    static const QMetaData signal_tbl[] = {
	{ "currentChanged(QSqlRecord*)", &signal_0, QMetaData::Public },
	{ "primeInsert(QSqlRecord*)", &signal_1, QMetaData::Public },
	{ "primeUpdate(QSqlRecord*)", &signal_2, QMetaData::Public },
	{ "primeDelete(QSqlRecord*)", &signal_3, QMetaData::Public },
	{ "beforeInsert(QSqlRecord*)", &signal_4, QMetaData::Public },
	{ "beforeUpdate(QSqlRecord*)", &signal_5, QMetaData::Public },
	{ "beforeDelete(QSqlRecord*)", &signal_6, QMetaData::Public },
	{ "cursorChanged(QSql::Op)", &signal_7, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[14] = {
 	{ "QString","nullText", 0x3000103, &QDataTable::metaObj, 0, -1 },
	{ "QString","trueText", 0x3000103, &QDataTable::metaObj, 0, -1 },
	{ "QString","falseText", 0x3000103, &QDataTable::metaObj, 0, -1 },
	{ "DateFormat","dateFormat", 0x010f, &QDataTable::metaObj, 0, -1 },
	{ "bool","confirmEdits", 0x12000103, &QDataTable::metaObj, 0, -1 },
	{ "bool","confirmInsert", 0x12000103, &QDataTable::metaObj, 0, -1 },
	{ "bool","confirmUpdate", 0x12000103, &QDataTable::metaObj, 0, -1 },
	{ "bool","confirmDelete", 0x12000103, &QDataTable::metaObj, 0, -1 },
	{ "bool","confirmCancels", 0x12000103, &QDataTable::metaObj, 0, -1 },
	{ "bool","autoEdit", 0x12000103, &QDataTable::metaObj, 0, -1 },
	{ "QString","filter", 0x3000103, &QDataTable::metaObj, 0, -1 },
	{ "QStringList","sort", 0x4000103, &QDataTable::metaObj, 0, -1 },
	{ "int","numCols", 0x10000001, &QDataTable::metaObj, 0, -1 },
	{ "int","numRows", 0x10000001, &QDataTable::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QDataTable", parentObject,
	slot_tbl, 16,
	signal_tbl, 8,
#ifndef QT_NO_PROPERTIES
	props_tbl, 14,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDataTable.setMetaObject( metaObj );
    return metaObj;
}

void* QDataTable::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDataTable" ) )
	return this;
    return QTable::qt_cast( clname );
}

// SIGNAL currentChanged
void QDataTable::currentChanged( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL primeInsert
void QDataTable::primeInsert( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL primeUpdate
void QDataTable::primeUpdate( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL primeDelete
void QDataTable::primeDelete( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL beforeInsert
void QDataTable::beforeInsert( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL beforeUpdate
void QDataTable::beforeUpdate( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL beforeDelete
void QDataTable::beforeDelete( QSqlRecord* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

// SIGNAL cursorChanged
void QDataTable::cursorChanged( QSql::Op t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool QDataTable::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: find((const QString&)static_QUType_QString.get(_o+1),(bool)static_QUType_bool.get(_o+2),(bool)static_QUType_bool.get(_o+3)); break;
    case 1: sortAscending((int)static_QUType_int.get(_o+1)); break;
    case 2: sortDescending((int)static_QUType_int.get(_o+1)); break;
    case 3: refresh(); break;
    case 4: setColumnWidth((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 5: adjustColumn((int)static_QUType_int.get(_o+1)); break;
    case 6: setColumnStretchable((int)static_QUType_int.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 7: swapColumns((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 8: swapColumns((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(bool)static_QUType_bool.get(_o+3)); break;
    case 9: loadNextPage(); break;
    case 10: setCurrentSelection((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 11: updateCurrentSelection(); break;
    case 12: sliderPressed(); break;
    case 13: sliderReleased(); break;
    case 14: doInsertCurrent(); break;
    case 15: doUpdateCurrent(); break;
    default:
	return QTable::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDataTable::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: currentChanged((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 1: primeInsert((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 2: primeUpdate((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 3: primeDelete((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 4: beforeInsert((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 5: beforeUpdate((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 6: beforeDelete((QSqlRecord*)static_QUType_ptr.get(_o+1)); break;
    case 7: cursorChanged((QSql::Op)(*((QSql::Op*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QTable::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QDataTable::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setNullText(v->asString()); break;
	case 1: *v = QVariant( this->nullText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setTrueText(v->asString()); break;
	case 1: *v = QVariant( this->trueText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: setFalseText(v->asString()); break;
	case 1: *v = QVariant( this->falseText() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 3: switch( f ) {
	case 0: setDateFormat((DateFormat&)v->asInt()); break;
	case 1: *v = QVariant( (int)this->dateFormat() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 4: switch( f ) {
	case 0: setConfirmEdits(v->asBool()); break;
	case 1: *v = QVariant( this->confirmEdits(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 5: switch( f ) {
	case 0: setConfirmInsert(v->asBool()); break;
	case 1: *v = QVariant( this->confirmInsert(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 6: switch( f ) {
	case 0: setConfirmUpdate(v->asBool()); break;
	case 1: *v = QVariant( this->confirmUpdate(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 7: switch( f ) {
	case 0: setConfirmDelete(v->asBool()); break;
	case 1: *v = QVariant( this->confirmDelete(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 8: switch( f ) {
	case 0: setConfirmCancels(v->asBool()); break;
	case 1: *v = QVariant( this->confirmCancels(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 9: switch( f ) {
	case 0: setAutoEdit(v->asBool()); break;
	case 1: *v = QVariant( this->autoEdit(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 10: switch( f ) {
	case 0: setFilter(v->asString()); break;
	case 1: *v = QVariant( this->filter() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 11: switch( f ) {
	case 0: setSort(v->asStringList()); break;
	case 1: *v = QVariant( this->sort() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 12: switch( f ) {
	case 1: *v = QVariant( this->numCols() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 13: switch( f ) {
	case 1: *v = QVariant( this->numRows() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QTable::qt_property( id, f, v );
    }
    return TRUE;
}

bool QDataTable::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QVBox::className() const
{
    return "QVBox";
}

QMetaObject *QVBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QVBox( "QVBox", &QVBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QVBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QVBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QVBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QHBox::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QVBox", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QVBox.setMetaObject( metaObj );
    return metaObj;
}

void* QVBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QVBox" ) )
	return this;
    return QHBox::qt_cast( clname );
}

bool QVBox::qt_invoke( int _id, QUObject* _o )
{
    return QHBox::qt_invoke(_id,_o);
}

bool QVBox::qt_emit( int _id, QUObject* _o )
{
    return QHBox::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QVBox::qt_property( int id, int f, QVariant* v)
{
    return QHBox::qt_property( id, f, v);
}

bool QVBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QVButtonGroup::className() const
{
    return "QVButtonGroup";
}

QMetaObject *QVButtonGroup::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QVButtonGroup( "QVButtonGroup", &QVButtonGroup::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QVButtonGroup::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVButtonGroup", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QVButtonGroup::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVButtonGroup", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QVButtonGroup::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QButtonGroup::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QVButtonGroup", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QVButtonGroup.setMetaObject( metaObj );
    return metaObj;
}

void* QVButtonGroup::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QVButtonGroup" ) )
	return this;
    return QButtonGroup::qt_cast( clname );
}

bool QVButtonGroup::qt_invoke( int _id, QUObject* _o )
{
    return QButtonGroup::qt_invoke(_id,_o);
}

bool QVButtonGroup::qt_emit( int _id, QUObject* _o )
{
    return QButtonGroup::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QVButtonGroup::qt_property( int id, int f, QVariant* v)
{
    return QButtonGroup::qt_property( id, f, v);
}

bool QVButtonGroup::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QVGroupBox::className() const
{
    return "QVGroupBox";
}

QMetaObject *QVGroupBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QVGroupBox( "QVGroupBox", &QVGroupBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QVGroupBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVGroupBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QVGroupBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QVGroupBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QVGroupBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGroupBox::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QVGroupBox", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QVGroupBox.setMetaObject( metaObj );
    return metaObj;
}

void* QVGroupBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QVGroupBox" ) )
	return this;
    return QGroupBox::qt_cast( clname );
}

bool QVGroupBox::qt_invoke( int _id, QUObject* _o )
{
    return QGroupBox::qt_invoke(_id,_o);
}

bool QVGroupBox::qt_emit( int _id, QUObject* _o )
{
    return QGroupBox::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QVGroupBox::qt_property( int id, int f, QVariant* v)
{
    return QGroupBox::qt_property( id, f, v);
}

bool QVGroupBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QApplication::className() const
{
    return "QApplication";
}

QMetaObject *QApplication::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QApplication( "QApplication", &QApplication::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QApplication::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QApplication", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QApplication::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QApplication", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QApplication::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"quit", 0, 0 };
    static const QUMethod slot_1 = {"closeAllWindows", 0, 0 };
    static const QUMethod slot_2 = {"aboutQt", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "quit()", &slot_0, QMetaData::Public },
	{ "closeAllWindows()", &slot_1, QMetaData::Public },
	{ "aboutQt()", &slot_2, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"lastWindowClosed", 0, 0 };
    static const QUMethod signal_1 = {"aboutToQuit", 0, 0 };
    static const QUMethod signal_2 = {"guiThreadAwake", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "lastWindowClosed()", &signal_0, QMetaData::Public },
	{ "aboutToQuit()", &signal_1, QMetaData::Public },
	{ "guiThreadAwake()", &signal_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QApplication", parentObject,
	slot_tbl, 3,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QApplication.setMetaObject( metaObj );
    return metaObj;
}

void* QApplication::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QApplication" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL lastWindowClosed
void QApplication::lastWindowClosed()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL aboutToQuit
void QApplication::aboutToQuit()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL guiThreadAwake
void QApplication::guiThreadAwake()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

bool QApplication::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: quit(); break;
    case 1: closeAllWindows(); break;
    case 2: aboutQt(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QApplication::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: lastWindowClosed(); break;
    case 1: aboutToQuit(); break;
    case 2: guiThreadAwake(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QApplication::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QApplication::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWidgetPlugin::className() const
{
    return "QWidgetPlugin";
}

QMetaObject *QWidgetPlugin::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWidgetPlugin( "QWidgetPlugin", &QWidgetPlugin::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWidgetPlugin::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWidgetPlugin", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWidgetPlugin::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWidgetPlugin", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWidgetPlugin::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGPlugin::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QWidgetPlugin", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWidgetPlugin.setMetaObject( metaObj );
    return metaObj;
}

void* QWidgetPlugin::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWidgetPlugin" ) )
	return this;
    return QGPlugin::qt_cast( clname );
}

bool QWidgetPlugin::qt_invoke( int _id, QUObject* _o )
{
    return QGPlugin::qt_invoke(_id,_o);
}

bool QWidgetPlugin::qt_emit( int _id, QUObject* _o )
{
    return QGPlugin::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QWidgetPlugin::qt_property( int id, int f, QVariant* v)
{
    return QGPlugin::qt_property( id, f, v);
}

bool QWidgetPlugin::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWidgetStack::className() const
{
    return "QWidgetStack";
}

QMetaObject *QWidgetStack::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWidgetStack( "QWidgetStack", &QWidgetStack::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWidgetStack::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWidgetStack", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWidgetStack::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWidgetStack", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWidgetStack::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"raiseWidget", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_1 = {"raiseWidget", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "raiseWidget(int)", &slot_0, QMetaData::Public },
	{ "raiseWidget(QWidget*)", &slot_1, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"aboutToShow", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_1 = {"aboutToShow", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "aboutToShow(int)", &signal_0, QMetaData::Public },
	{ "aboutToShow(QWidget*)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QWidgetStack", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWidgetStack.setMetaObject( metaObj );
    return metaObj;
}

void* QWidgetStack::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWidgetStack" ) )
	return this;
    return QFrame::qt_cast( clname );
}

// SIGNAL aboutToShow
void QWidgetStack::aboutToShow( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL aboutToShow
void QWidgetStack::aboutToShow( QWidget* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QWidgetStack::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: raiseWidget((int)static_QUType_int.get(_o+1)); break;
    case 1: raiseWidget((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QFrame::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QWidgetStack::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: aboutToShow((int)static_QUType_int.get(_o+1)); break;
    case 1: aboutToShow((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QWidgetStack::qt_property( int id, int f, QVariant* v)
{
    return QFrame::qt_property( id, f, v);
}

bool QWidgetStack::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QCheckBox::className() const
{
    return "QCheckBox";
}

QMetaObject *QCheckBox::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCheckBox( "QCheckBox", &QCheckBox::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCheckBox::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCheckBox", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCheckBox::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCheckBox", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCheckBox::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QButton::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "check", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setChecked", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "setChecked(bool)", &slot_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[3] = {
 	{ "bool","checked", 0x12000103, &QCheckBox::metaObj, 0, -1 },
	{ "bool","tristate", 0x12000103, &QCheckBox::metaObj, 0, -1 },
	{ "bool","autoMask", 0x12020200, &QCheckBox::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QCheckBox", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	props_tbl, 3,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCheckBox.setMetaObject( metaObj );
    return metaObj;
}

void* QCheckBox::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCheckBox" ) )
	return this;
    return QButton::qt_cast( clname );
}

bool QCheckBox::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setChecked((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return QButton::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QCheckBox::qt_emit( int _id, QUObject* _o )
{
    return QButton::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QCheckBox::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setChecked(v->asBool()); break;
	case 1: *v = QVariant( this->isChecked(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setTristate(v->asBool()); break;
	case 1: *v = QVariant( this->isTristate(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 2: switch( f ) {
	case 0: case 1: case 5: goto resolve;
	case 3: case 4: break;
	default: return FALSE;
    } break;
    default:
	return QButton::qt_property( id, f, v );
    }
    return TRUE;
resolve:
    return QButton::qt_property( staticMetaObject()->resolveProperty(id), f, v );
}

bool QCheckBox::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWizard::className() const
{
    return "QWizard";
}

QMetaObject *QWizard::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWizard( "QWizard", &QWizard::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWizard::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWizard", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWizard::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWizard", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWizard::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setBackEnabled", 2, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setNextEnabled", 2, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"setFinishEnabled", 2, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"setHelpEnabled", 2, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"setFinish", 2, param_slot_4 };
    static const QUMethod slot_5 = {"back", 0, 0 };
    static const QUMethod slot_6 = {"next", 0, 0 };
    static const QUMethod slot_7 = {"help", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setBackEnabled(QWidget*,bool)", &slot_0, QMetaData::Public },
	{ "setNextEnabled(QWidget*,bool)", &slot_1, QMetaData::Public },
	{ "setFinishEnabled(QWidget*,bool)", &slot_2, QMetaData::Public },
	{ "setHelpEnabled(QWidget*,bool)", &slot_3, QMetaData::Public },
	{ "setFinish(QWidget*,bool)", &slot_4, QMetaData::Public },
	{ "back()", &slot_5, QMetaData::Protected },
	{ "next()", &slot_6, QMetaData::Protected },
	{ "help()", &slot_7, QMetaData::Protected }
    };
    static const QUMethod signal_0 = {"helpClicked", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"selected", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "helpClicked()", &signal_0, QMetaData::Protected },
	{ "selected(const QString&)", &signal_1, QMetaData::Protected }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[1] = {
 	{ "QFont","titleFont", 0x5000103, &QWizard::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QWizard", parentObject,
	slot_tbl, 8,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	props_tbl, 1,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWizard.setMetaObject( metaObj );
    return metaObj;
}

void* QWizard::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWizard" ) )
	return this;
    return QDialog::qt_cast( clname );
}

// SIGNAL helpClicked
void QWizard::helpClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL selected
void QWizard::selected( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

bool QWizard::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setBackEnabled((QWidget*)static_QUType_ptr.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 1: setNextEnabled((QWidget*)static_QUType_ptr.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 2: setFinishEnabled((QWidget*)static_QUType_ptr.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 3: setHelpEnabled((QWidget*)static_QUType_ptr.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 4: setFinish((QWidget*)static_QUType_ptr.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 5: back(); break;
    case 6: next(); break;
    case 7: help(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QWizard::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: helpClicked(); break;
    case 1: selected((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QDialog::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QWizard::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setTitleFont(v->asFont()); break;
	case 1: *v = QVariant( this->titleFont() ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QDialog::qt_property( id, f, v );
    }
    return TRUE;
}

bool QWizard::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWorkspace::className() const
{
    return "QWorkspace";
}

QMetaObject *QWorkspace::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWorkspace( "QWorkspace", &QWorkspace::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWorkspace::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWorkspace", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWorkspace::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWorkspace", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWorkspace::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"cascade", 0, 0 };
    static const QUMethod slot_1 = {"tile", 0, 0 };
    static const QUMethod slot_2 = {"closeActiveWindow", 0, 0 };
    static const QUMethod slot_3 = {"closeAllWindows", 0, 0 };
    static const QUMethod slot_4 = {"activateNextWindow", 0, 0 };
    static const QUMethod slot_5 = {"activatePrevWindow", 0, 0 };
    static const QUMethod slot_6 = {"normalizeActiveWindow", 0, 0 };
    static const QUMethod slot_7 = {"minimizeActiveWindow", 0, 0 };
    static const QUMethod slot_8 = {"showOperationMenu", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_9 = {"popupOperationMenu", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"operationMenuActivated", 1, param_slot_10 };
    static const QUMethod slot_11 = {"operationMenuAboutToShow", 0, 0 };
    static const QUMethod slot_12 = {"toolMenuAboutToShow", 0, 0 };
    static const QUMethod slot_13 = {"activatePreviousWindow", 0, 0 };
    static const QUMethod slot_14 = {"dockWindowsShow", 0, 0 };
    static const QUMethod slot_15 = {"scrollBarChanged", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "cascade()", &slot_0, QMetaData::Public },
	{ "tile()", &slot_1, QMetaData::Public },
	{ "closeActiveWindow()", &slot_2, QMetaData::Public },
	{ "closeAllWindows()", &slot_3, QMetaData::Public },
	{ "activateNextWindow()", &slot_4, QMetaData::Public },
	{ "activatePrevWindow()", &slot_5, QMetaData::Public },
	{ "normalizeActiveWindow()", &slot_6, QMetaData::Private },
	{ "minimizeActiveWindow()", &slot_7, QMetaData::Private },
	{ "showOperationMenu()", &slot_8, QMetaData::Private },
	{ "popupOperationMenu(const QPoint&)", &slot_9, QMetaData::Private },
	{ "operationMenuActivated(int)", &slot_10, QMetaData::Private },
	{ "operationMenuAboutToShow()", &slot_11, QMetaData::Private },
	{ "toolMenuAboutToShow()", &slot_12, QMetaData::Private },
	{ "activatePreviousWindow()", &slot_13, QMetaData::Private },
	{ "dockWindowsShow()", &slot_14, QMetaData::Private },
	{ "scrollBarChanged()", &slot_15, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "w", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"windowActivated", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "windowActivated(QWidget*)", &signal_0, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[1] = {
 	{ "bool","scrollBarsEnabled", 0x12000103, &QWorkspace::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QWorkspace", parentObject,
	slot_tbl, 16,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	props_tbl, 1,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWorkspace.setMetaObject( metaObj );
    return metaObj;
}

void* QWorkspace::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWorkspace" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL windowActivated
void QWorkspace::windowActivated( QWidget* t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,t0);
    activate_signal( clist, o );
}

bool QWorkspace::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: cascade(); break;
    case 1: tile(); break;
    case 2: closeActiveWindow(); break;
    case 3: closeAllWindows(); break;
    case 4: activateNextWindow(); break;
    case 5: activatePrevWindow(); break;
    case 6: normalizeActiveWindow(); break;
    case 7: minimizeActiveWindow(); break;
    case 8: showOperationMenu(); break;
    case 9: popupOperationMenu((const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+1))); break;
    case 10: operationMenuActivated((int)static_QUType_int.get(_o+1)); break;
    case 11: operationMenuAboutToShow(); break;
    case 12: toolMenuAboutToShow(); break;
    case 13: activatePreviousWindow(); break;
    case 14: dockWindowsShow(); break;
    case 15: scrollBarChanged(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QWorkspace::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: windowActivated((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QWorkspace::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setScrollBarsEnabled(v->asBool()); break;
	case 1: *v = QVariant( this->scrollBarsEnabled(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QWorkspace::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QLocalFs::className() const
{
    return "QLocalFs";
}

QMetaObject *QLocalFs::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QLocalFs( "QLocalFs", &QLocalFs::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QLocalFs::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QLocalFs", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QLocalFs::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QLocalFs", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QLocalFs::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QNetworkProtocol::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QLocalFs", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QLocalFs.setMetaObject( metaObj );
    return metaObj;
}

void* QLocalFs::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QLocalFs" ) )
	return this;
    return QNetworkProtocol::qt_cast( clname );
}

bool QLocalFs::qt_invoke( int _id, QUObject* _o )
{
    return QNetworkProtocol::qt_invoke(_id,_o);
}

bool QLocalFs::qt_emit( int _id, QUObject* _o )
{
    return QNetworkProtocol::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QLocalFs::qt_property( int id, int f, QVariant* v)
{
    return QNetworkProtocol::qt_property( id, f, v);
}

bool QLocalFs::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTextDocument::className() const
{
    return "QTextDocument";
}

QMetaObject *QTextDocument::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTextDocument( "QTextDocument", &QTextDocument::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTextDocument::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextDocument", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTextDocument::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTextDocument", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTextDocument::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"minimumWidthChanged", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "minimumWidthChanged(int)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QTextDocument", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTextDocument.setMetaObject( metaObj );
    return metaObj;
}

void* QTextDocument::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTextDocument" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL minimumWidthChanged
void QTextDocument::minimumWidthChanged( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool QTextDocument::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QTextDocument::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: minimumWidthChanged((int)static_QUType_int.get(_o+1)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QTextDocument::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QTextDocument::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QTitleBar::className() const
{
    return "QTitleBar";
}

QMetaObject *QTitleBar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QTitleBar( "QTitleBar", &QTitleBar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QTitleBar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTitleBar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QTitleBar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QTitleBar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QTitleBar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setActive", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "title", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"setCaption", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "icon", &static_QUType_varptr, "\x06", QUParameter::In }
    };
    static const QUMethod slot_2 = {"setIcon", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "setActive(bool)", &slot_0, QMetaData::Public },
	{ "setCaption(const QString&)", &slot_1, QMetaData::Public },
	{ "setIcon(const QPixmap&)", &slot_2, QMetaData::Public }
    };
    static const QUMethod signal_0 = {"doActivate", 0, 0 };
    static const QUMethod signal_1 = {"doNormal", 0, 0 };
    static const QUMethod signal_2 = {"doClose", 0, 0 };
    static const QUMethod signal_3 = {"doMaximize", 0, 0 };
    static const QUMethod signal_4 = {"doMinimize", 0, 0 };
    static const QUMethod signal_5 = {"doShade", 0, 0 };
    static const QUMethod signal_6 = {"showOperationMenu", 0, 0 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod signal_7 = {"popupOperationMenu", 1, param_signal_7 };
    static const QUMethod signal_8 = {"doubleClicked", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "doActivate()", &signal_0, QMetaData::Public },
	{ "doNormal()", &signal_1, QMetaData::Public },
	{ "doClose()", &signal_2, QMetaData::Public },
	{ "doMaximize()", &signal_3, QMetaData::Public },
	{ "doMinimize()", &signal_4, QMetaData::Public },
	{ "doShade()", &signal_5, QMetaData::Public },
	{ "showOperationMenu()", &signal_6, QMetaData::Public },
	{ "popupOperationMenu(const QPoint&)", &signal_7, QMetaData::Public },
	{ "doubleClicked()", &signal_8, QMetaData::Public }
    };
#ifndef QT_NO_PROPERTIES
    static const QMetaProperty props_tbl[2] = {
 	{ "bool","autoRaise", 0x12000103, &QTitleBar::metaObj, 0, -1 },
	{ "bool","movable", 0x12000103, &QTitleBar::metaObj, 0, -1 }
    };
#endif // QT_NO_PROPERTIES
    metaObj = QMetaObject::new_metaobject(
	"QTitleBar", parentObject,
	slot_tbl, 3,
	signal_tbl, 9,
#ifndef QT_NO_PROPERTIES
	props_tbl, 2,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QTitleBar.setMetaObject( metaObj );
    return metaObj;
}

void* QTitleBar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QTitleBar" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL doActivate
void QTitleBar::doActivate()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL doNormal
void QTitleBar::doNormal()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL doClose
void QTitleBar::doClose()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL doMaximize
void QTitleBar::doMaximize()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL doMinimize
void QTitleBar::doMinimize()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL doShade
void QTitleBar::doShade()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

// SIGNAL showOperationMenu
void QTitleBar::showOperationMenu()
{
    activate_signal( staticMetaObject()->signalOffset() + 6 );
}

// SIGNAL popupOperationMenu
void QTitleBar::popupOperationMenu( const QPoint& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_varptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL doubleClicked
void QTitleBar::doubleClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 8 );
}

bool QTitleBar::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setActive((bool)static_QUType_bool.get(_o+1)); break;
    case 1: setCaption((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: setIcon((const QPixmap&)*((const QPixmap*)static_QUType_ptr.get(_o+1))); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QTitleBar::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: doActivate(); break;
    case 1: doNormal(); break;
    case 2: doClose(); break;
    case 3: doMaximize(); break;
    case 4: doMinimize(); break;
    case 5: doShade(); break;
    case 6: showOperationMenu(); break;
    case 7: popupOperationMenu((const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+1))); break;
    case 8: doubleClicked(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QTitleBar::qt_property( int id, int f, QVariant* v)
{
    switch ( id - staticMetaObject()->propertyOffset() ) {
    case 0: switch( f ) {
	case 0: setAutoRaise(v->asBool()); break;
	case 1: *v = QVariant( this->autoRaise(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    case 1: switch( f ) {
	case 0: setMovable(v->asBool()); break;
	case 1: *v = QVariant( this->isMovable(), 0 ); break;
	case 3: case 4: case 5: break;
	default: return FALSE;
    } break;
    default:
	return QWidget::qt_property( id, f, v );
    }
    return TRUE;
}

bool QTitleBar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QDialogButtons::className() const
{
    return "QDialogButtons";
}

QMetaObject *QDialogButtons::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QDialogButtons( "QDialogButtons", &QDialogButtons::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QDialogButtons::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDialogButtons", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QDialogButtons::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QDialogButtons", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QDialogButtons::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"handleClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "handleClicked()", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "Button", QUParameter::In }
    };
    static const QUMethod signal_0 = {"clicked", 1, param_signal_0 };
    static const QUMethod signal_1 = {"acceptClicked", 0, 0 };
    static const QUMethod signal_2 = {"rejectClicked", 0, 0 };
    static const QUMethod signal_3 = {"helpClicked", 0, 0 };
    static const QUMethod signal_4 = {"applyClicked", 0, 0 };
    static const QUMethod signal_5 = {"allClicked", 0, 0 };
    static const QUMethod signal_6 = {"retryClicked", 0, 0 };
    static const QUMethod signal_7 = {"ignoreClicked", 0, 0 };
    static const QUMethod signal_8 = {"abortClicked", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "clicked(Button)", &signal_0, QMetaData::Private },
	{ "acceptClicked()", &signal_1, QMetaData::Private },
	{ "rejectClicked()", &signal_2, QMetaData::Private },
	{ "helpClicked()", &signal_3, QMetaData::Private },
	{ "applyClicked()", &signal_4, QMetaData::Private },
	{ "allClicked()", &signal_5, QMetaData::Private },
	{ "retryClicked()", &signal_6, QMetaData::Private },
	{ "ignoreClicked()", &signal_7, QMetaData::Private },
	{ "abortClicked()", &signal_8, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"QDialogButtons", parentObject,
	slot_tbl, 1,
	signal_tbl, 9,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QDialogButtons.setMetaObject( metaObj );
    return metaObj;
}

void* QDialogButtons::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QDialogButtons" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL clicked
void QDialogButtons::clicked( Button t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL acceptClicked
void QDialogButtons::acceptClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL rejectClicked
void QDialogButtons::rejectClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL helpClicked
void QDialogButtons::helpClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL applyClicked
void QDialogButtons::applyClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL allClicked
void QDialogButtons::allClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

// SIGNAL retryClicked
void QDialogButtons::retryClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 6 );
}

// SIGNAL ignoreClicked
void QDialogButtons::ignoreClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 7 );
}

// SIGNAL abortClicked
void QDialogButtons::abortClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 8 );
}

bool QDialogButtons::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: handleClicked(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QDialogButtons::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: clicked((Button)(*((Button*)static_QUType_ptr.get(_o+1)))); break;
    case 1: acceptClicked(); break;
    case 2: rejectClicked(); break;
    case 3: helpClicked(); break;
    case 4: applyClicked(); break;
    case 5: allClicked(); break;
    case 6: retryClicked(); break;
    case 7: ignoreClicked(); break;
    case 8: abortClicked(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QDialogButtons::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool QDialogButtons::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWidgetResizeHandler::className() const
{
    return "QWidgetResizeHandler";
}

QMetaObject *QWidgetResizeHandler::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWidgetResizeHandler( "QWidgetResizeHandler", &QWidgetResizeHandler::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWidgetResizeHandler::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWidgetResizeHandler", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWidgetResizeHandler::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWidgetResizeHandler", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWidgetResizeHandler::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod signal_0 = {"activate", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "activate()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QWidgetResizeHandler", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWidgetResizeHandler.setMetaObject( metaObj );
    return metaObj;
}

void* QWidgetResizeHandler::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWidgetResizeHandler" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL activate
void QWidgetResizeHandler::activate()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool QWidgetResizeHandler::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QWidgetResizeHandler::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: activate(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QWidgetResizeHandler::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QWidgetResizeHandler::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QGfxDriverPlugin::className() const
{
    return "QGfxDriverPlugin";
}

QMetaObject *QGfxDriverPlugin::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QGfxDriverPlugin( "QGfxDriverPlugin", &QGfxDriverPlugin::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QGfxDriverPlugin::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGfxDriverPlugin", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QGfxDriverPlugin::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QGfxDriverPlugin", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QGfxDriverPlugin::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGPlugin::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QGfxDriverPlugin", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QGfxDriverPlugin.setMetaObject( metaObj );
    return metaObj;
}

void* QGfxDriverPlugin::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QGfxDriverPlugin" ) )
	return this;
    return QGPlugin::qt_cast( clname );
}

bool QGfxDriverPlugin::qt_invoke( int _id, QUObject* _o )
{
    return QGPlugin::qt_invoke(_id,_o);
}

bool QGfxDriverPlugin::qt_emit( int _id, QUObject* _o )
{
    return QGPlugin::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QGfxDriverPlugin::qt_property( int id, int f, QVariant* v)
{
    return QGPlugin::qt_property( id, f, v);
}

bool QGfxDriverPlugin::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QKbdDriverPlugin::className() const
{
    return "QKbdDriverPlugin";
}

QMetaObject *QKbdDriverPlugin::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QKbdDriverPlugin( "QKbdDriverPlugin", &QKbdDriverPlugin::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QKbdDriverPlugin::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QKbdDriverPlugin", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QKbdDriverPlugin::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QKbdDriverPlugin", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QKbdDriverPlugin::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGPlugin::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QKbdDriverPlugin", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QKbdDriverPlugin.setMetaObject( metaObj );
    return metaObj;
}

void* QKbdDriverPlugin::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QKbdDriverPlugin" ) )
	return this;
    return QGPlugin::qt_cast( clname );
}

bool QKbdDriverPlugin::qt_invoke( int _id, QUObject* _o )
{
    return QGPlugin::qt_invoke(_id,_o);
}

bool QKbdDriverPlugin::qt_emit( int _id, QUObject* _o )
{
    return QGPlugin::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QKbdDriverPlugin::qt_property( int id, int f, QVariant* v)
{
    return QGPlugin::qt_property( id, f, v);
}

bool QKbdDriverPlugin::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QMouseDriverPlugin::className() const
{
    return "QMouseDriverPlugin";
}

QMetaObject *QMouseDriverPlugin::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QMouseDriverPlugin( "QMouseDriverPlugin", &QMouseDriverPlugin::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QMouseDriverPlugin::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMouseDriverPlugin", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QMouseDriverPlugin::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QMouseDriverPlugin", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QMouseDriverPlugin::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QGPlugin::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QMouseDriverPlugin", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QMouseDriverPlugin.setMetaObject( metaObj );
    return metaObj;
}

void* QMouseDriverPlugin::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QMouseDriverPlugin" ) )
	return this;
    return QGPlugin::qt_cast( clname );
}

bool QMouseDriverPlugin::qt_invoke( int _id, QUObject* _o )
{
    return QGPlugin::qt_invoke(_id,_o);
}

bool QMouseDriverPlugin::qt_emit( int _id, QUObject* _o )
{
    return QGPlugin::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QMouseDriverPlugin::qt_property( int id, int f, QVariant* v)
{
    return QGPlugin::qt_property( id, f, v);
}

bool QMouseDriverPlugin::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QCopChannel::className() const
{
    return "QCopChannel";
}

QMetaObject *QCopChannel::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QCopChannel( "QCopChannel", &QCopChannel::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QCopChannel::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCopChannel", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QCopChannel::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QCopChannel", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QCopChannel::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ "msg", &static_QUType_varptr, "\x14", QUParameter::In },
	{ "data", &static_QUType_varptr, "\x1d", QUParameter::In }
    };
    static const QUMethod signal_0 = {"received", 2, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "received(const QCString&,const QByteArray&)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QCopChannel", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QCopChannel.setMetaObject( metaObj );
    return metaObj;
}

void* QCopChannel::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QCopChannel" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL received
void QCopChannel::received( const QCString& t0, const QByteArray& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_varptr.set(o+1,&t0);
    static_QUType_varptr.set(o+2,&t1);
    activate_signal( clist, o );
}

bool QCopChannel::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QCopChannel::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: received((const QCString&)*((const QCString*)static_QUType_ptr.get(_o+1)),(const QByteArray&)*((const QByteArray*)static_QUType_ptr.get(_o+2))); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QCopChannel::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QCopChannel::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWSSoundServer::className() const
{
    return "QWSSoundServer";
}

QMetaObject *QWSSoundServer::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWSSoundServer( "QWSSoundServer", &QWSSoundServer::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWSSoundServer::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSSoundServer", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWSSoundServer::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSSoundServer", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWSSoundServer::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QWSSoundServer", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWSSoundServer.setMetaObject( metaObj );
    return metaObj;
}

void* QWSSoundServer::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWSSoundServer" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QWSSoundServer::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool QWSSoundServer::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QWSSoundServer::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QWSSoundServer::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWSSoundClient::className() const
{
    return "QWSSoundClient";
}

QMetaObject *QWSSoundClient::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWSSoundClient( "QWSSoundClient", &QWSSoundClient::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWSSoundClient::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSSoundClient", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWSSoundClient::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSSoundClient", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWSSoundClient::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QSocket::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QWSSoundClient", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWSSoundClient.setMetaObject( metaObj );
    return metaObj;
}

void* QWSSoundClient::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWSSoundClient" ) )
	return this;
    return QSocket::qt_cast( clname );
}

bool QWSSoundClient::qt_invoke( int _id, QUObject* _o )
{
    return QSocket::qt_invoke(_id,_o);
}

bool QWSSoundClient::qt_emit( int _id, QUObject* _o )
{
    return QSocket::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QWSSoundClient::qt_property( int id, int f, QVariant* v)
{
    return QSocket::qt_property( id, f, v);
}

bool QWSSoundClient::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWSSoundServerClient::className() const
{
    return "QWSSoundServerClient";
}

QMetaObject *QWSSoundServerClient::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWSSoundServerClient( "QWSSoundServerClient", &QWSSoundServerClient::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWSSoundServerClient::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSSoundServerClient", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWSSoundServerClient::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSSoundServerClient", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWSSoundServerClient::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QSocket::staticMetaObject();
    static const QUMethod slot_0 = {"destruct", 0, 0 };
    static const QUMethod slot_1 = {"tryReadCommand", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "destruct()", &slot_0, QMetaData::Private },
	{ "tryReadCommand()", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"play", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "play(const QString&)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QWSSoundServerClient", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWSSoundServerClient.setMetaObject( metaObj );
    return metaObj;
}

void* QWSSoundServerClient::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWSSoundServerClient" ) )
	return this;
    return QSocket::qt_cast( clname );
}

// SIGNAL play
void QWSSoundServerClient::play( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool QWSSoundServerClient::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: destruct(); break;
    case 1: tryReadCommand(); break;
    default:
	return QSocket::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QWSSoundServerClient::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: play((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QSocket::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QWSSoundServerClient::qt_property( int id, int f, QVariant* v)
{
    return QSocket::qt_property( id, f, v);
}

bool QWSSoundServerClient::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWSSoundServerSocket::className() const
{
    return "QWSSoundServerSocket";
}

QMetaObject *QWSSoundServerSocket::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWSSoundServerSocket( "QWSSoundServerSocket", &QWSSoundServerSocket::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWSSoundServerSocket::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSSoundServerSocket", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWSSoundServerSocket::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSSoundServerSocket", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWSSoundServerSocket::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QServerSocket::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ "filename", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"playFile", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "playFile(const QString&)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QWSSoundServerSocket", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWSSoundServerSocket.setMetaObject( metaObj );
    return metaObj;
}

void* QWSSoundServerSocket::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWSSoundServerSocket" ) )
	return this;
    return QServerSocket::qt_cast( clname );
}

// SIGNAL playFile
void QWSSoundServerSocket::playFile( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool QWSSoundServerSocket::qt_invoke( int _id, QUObject* _o )
{
    return QServerSocket::qt_invoke(_id,_o);
}

bool QWSSoundServerSocket::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: playFile((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QServerSocket::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QWSSoundServerSocket::qt_property( int id, int f, QVariant* v)
{
    return QServerSocket::qt_property( id, f, v);
}

bool QWSSoundServerSocket::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWSSocket::className() const
{
    return "QWSSocket";
}

QMetaObject *QWSSocket::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWSSocket( "QWSSocket", &QWSSocket::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWSSocket::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSSocket", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWSSocket::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSSocket", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWSSocket::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QSocket::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QWSSocket", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWSSocket.setMetaObject( metaObj );
    return metaObj;
}

void* QWSSocket::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWSSocket" ) )
	return this;
    return QSocket::qt_cast( clname );
}

bool QWSSocket::qt_invoke( int _id, QUObject* _o )
{
    return QSocket::qt_invoke(_id,_o);
}

bool QWSSocket::qt_emit( int _id, QUObject* _o )
{
    return QSocket::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QWSSocket::qt_property( int id, int f, QVariant* v)
{
    return QSocket::qt_property( id, f, v);
}

bool QWSSocket::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWSServerSocket::className() const
{
    return "QWSServerSocket";
}

QMetaObject *QWSServerSocket::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWSServerSocket( "QWSServerSocket", &QWSServerSocket::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWSServerSocket::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSServerSocket", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWSServerSocket::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSServerSocket", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWSServerSocket::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QServerSocket::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"QWSServerSocket", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWSServerSocket.setMetaObject( metaObj );
    return metaObj;
}

void* QWSServerSocket::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWSServerSocket" ) )
	return this;
    return QServerSocket::qt_cast( clname );
}

bool QWSServerSocket::qt_invoke( int _id, QUObject* _o )
{
    return QServerSocket::qt_invoke(_id,_o);
}

bool QWSServerSocket::qt_emit( int _id, QUObject* _o )
{
    return QServerSocket::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QWSServerSocket::qt_property( int id, int f, QVariant* v)
{
    return QServerSocket::qt_property( id, f, v);
}

bool QWSServerSocket::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWSManager::className() const
{
    return "QWSManager";
}

QMetaObject *QWSManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWSManager( "QWSManager", &QWSManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWSManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWSManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWSManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"menuActivated", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"styleMenuActivated", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "menuActivated(int)", &slot_0, QMetaData::Protected },
	{ "styleMenuActivated(int)", &slot_1, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"QWSManager", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWSManager.setMetaObject( metaObj );
    return metaObj;
}

void* QWSManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWSManager" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool QWSManager::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: menuActivated((int)static_QUType_int.get(_o+1)); break;
    case 1: styleMenuActivated((int)static_QUType_int.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QWSManager::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool QWSManager::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QWSManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWSServer::className() const
{
    return "QWSServer";
}

QMetaObject *QWSServer::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWSServer( "QWSServer", &QWSServer::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWSServer::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSServer", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWSServer::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSServer", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWSServer::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWSServerSocket::staticMetaObject();
    static const QUMethod slot_0 = {"clientClosed", 0, 0 };
    static const QUMethod slot_1 = {"doClient", 0, 0 };
    static const QUMethod slot_2 = {"deleteWindowsLater", 0, 0 };
    static const QUMethod slot_3 = {"screenSaverWake", 0, 0 };
    static const QUMethod slot_4 = {"screenSaverSleep", 0, 0 };
    static const QUMethod slot_5 = {"screenSaverTimeout", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "clientClosed()", &slot_0, QMetaData::Private },
	{ "doClient()", &slot_1, QMetaData::Private },
	{ "deleteWindowsLater()", &slot_2, QMetaData::Private },
	{ "screenSaverWake()", &slot_3, QMetaData::Private },
	{ "screenSaverSleep()", &slot_4, QMetaData::Private },
	{ "screenSaverTimeout()", &slot_5, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "w", &static_QUType_ptr, "QWSWindow", QUParameter::In },
	{ "e", &static_QUType_ptr, "QWSServer::WindowEvent", QUParameter::In }
    };
    static const QUMethod signal_0 = {"windowEvent", 2, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "channel", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"newChannel", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "channel", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"removedChannel", 1, param_signal_2 };
    static const QMetaData signal_tbl[] = {
	{ "windowEvent(QWSWindow*,QWSServer::WindowEvent)", &signal_0, QMetaData::Public },
	{ "newChannel(const QString&)", &signal_1, QMetaData::Public },
	{ "removedChannel(const QString&)", &signal_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QWSServer", parentObject,
	slot_tbl, 6,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWSServer.setMetaObject( metaObj );
    return metaObj;
}

void* QWSServer::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWSServer" ) )
	return this;
    return QWSServerSocket::qt_cast( clname );
}

// SIGNAL windowEvent
void QWSServer::windowEvent( QWSWindow* t0, QWSServer::WindowEvent t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL newChannel
void QWSServer::newChannel( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL removedChannel
void QWSServer::removedChannel( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

bool QWSServer::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: clientClosed(); break;
    case 1: doClient(); break;
    case 2: deleteWindowsLater(); break;
    case 3: screenSaverWake(); break;
    case 4: screenSaverSleep(); break;
    case 5: screenSaverTimeout(); break;
    default:
	return QWSServerSocket::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QWSServer::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: windowEvent((QWSWindow*)static_QUType_ptr.get(_o+1),(QWSServer::WindowEvent)(*((QWSServer::WindowEvent*)static_QUType_ptr.get(_o+2)))); break;
    case 1: newChannel((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: removedChannel((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return QWSServerSocket::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QWSServer::qt_property( int id, int f, QVariant* v)
{
    return QWSServerSocket::qt_property( id, f, v);
}

bool QWSServer::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *QWSClient::className() const
{
    return "QWSClient";
}

QMetaObject *QWSClient::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QWSClient( "QWSClient", &QWSClient::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QWSClient::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSClient", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QWSClient::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QWSClient", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QWSClient::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"closeHandler", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"errorHandler", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "closeHandler()", &slot_0, QMetaData::Private },
	{ "errorHandler(int)", &slot_1, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"connectionClosed", 0, 0 };
    static const QUMethod signal_1 = {"readyRead", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "connectionClosed()", &signal_0, QMetaData::Public },
	{ "readyRead()", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QWSClient", parentObject,
	slot_tbl, 2,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QWSClient.setMetaObject( metaObj );
    return metaObj;
}

void* QWSClient::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QWSClient" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL connectionClosed
void QWSClient::connectionClosed()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL readyRead
void QWSClient::readyRead()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool QWSClient::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: closeHandler(); break;
    case 1: errorHandler((int)static_QUType_int.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QWSClient::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: connectionClosed(); break;
    case 1: readyRead(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QWSClient::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool QWSClient::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
