/****************************************************************************
** $Id: qt/main.cpp   3.3.3   edited May 27 2003 $
**
** Copyright (C) 1992-2002 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include <qapplication.h>
#include <qsqldatabase.h>
#include <qsqlcursor.h>
#include "../connection.h"

int main( int argc, char *argv[] )
{
    QApplication app( argc, argv, FALSE );

    if ( createConnections() ) {
	QSqlCursor cur( "prices" ); 
	QSqlRecord *buffer = cur.primeInsert();
	buffer->setValue( "id",	   53981 );
	buffer->setValue( "name",  "Thingy" );
	buffer->setValue( "price", 105.75 );
	cur.insert();
    }

    return 0;
}
