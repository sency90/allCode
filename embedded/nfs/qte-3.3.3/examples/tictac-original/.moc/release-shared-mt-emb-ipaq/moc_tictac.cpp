/****************************************************************************
** TicTacButton meta object code from reading C++ file 'tictac.h'
**
** Created: Sat Jun 4 02:01:06 2016
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "../../tictac.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *TicTacButton::className() const
{
    return "TicTacButton";
}

QMetaObject *TicTacButton::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TicTacButton( "TicTacButton", &TicTacButton::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString TicTacButton::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TicTacButton", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TicTacButton::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TicTacButton", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TicTacButton::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QPushButton::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"TicTacButton", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TicTacButton.setMetaObject( metaObj );
    return metaObj;
}

void* TicTacButton::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TicTacButton" ) )
	return this;
    return QPushButton::qt_cast( clname );
}

bool TicTacButton::qt_invoke( int _id, QUObject* _o )
{
    return QPushButton::qt_invoke(_id,_o);
}

bool TicTacButton::qt_emit( int _id, QUObject* _o )
{
    return QPushButton::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TicTacButton::qt_property( int id, int f, QVariant* v)
{
    return QPushButton::qt_property( id, f, v);
}

bool TicTacButton::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *TicTacGameBoard::className() const
{
    return "TicTacGameBoard";
}

QMetaObject *TicTacGameBoard::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TicTacGameBoard( "TicTacGameBoard", &TicTacGameBoard::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString TicTacGameBoard::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TicTacGameBoard", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TicTacGameBoard::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TicTacGameBoard", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TicTacGameBoard::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"buttonClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "buttonClicked()", &slot_0, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"finished", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "finished()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"TicTacGameBoard", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TicTacGameBoard.setMetaObject( metaObj );
    return metaObj;
}

void* TicTacGameBoard::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TicTacGameBoard" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL finished
void TicTacGameBoard::finished()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool TicTacGameBoard::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: buttonClicked(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TicTacGameBoard::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: finished(); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool TicTacGameBoard::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool TicTacGameBoard::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *TicTacToe::className() const
{
    return "TicTacToe";
}

QMetaObject *TicTacToe::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TicTacToe( "TicTacToe", &TicTacToe::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString TicTacToe::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TicTacToe", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TicTacToe::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TicTacToe", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TicTacToe::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"newGameClicked", 0, 0 };
    static const QUMethod slot_1 = {"gameOver", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "newGameClicked()", &slot_0, QMetaData::Private },
	{ "gameOver()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"TicTacToe", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TicTacToe.setMetaObject( metaObj );
    return metaObj;
}

void* TicTacToe::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TicTacToe" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool TicTacToe::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: newGameClicked(); break;
    case 1: gameOver(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TicTacToe::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TicTacToe::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool TicTacToe::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
