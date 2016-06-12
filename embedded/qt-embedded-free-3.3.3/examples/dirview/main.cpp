/****************************************************************************
** $Id: qt/main.cpp   3.3.3   edited May 27 2003 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include <qapplication.h>
#include <qfileinfo.h>
#include <qdir.h>
#include "dirview.h"

int main( int argc, char ** argv )
{
    QApplication a( argc, argv );

    DirectoryView mw;

    mw.addColumn( "Name" );
    mw.addColumn( "Type" );
    mw.setTreeStepSize( 20 );

    const QFileInfoList* roots = QDir::drives();
    QPtrListIterator<QFileInfo> i(*roots);
    QFileInfo* fi;
    while ( (fi = *i) ) {
	++i;
	Directory * root = new Directory( &mw, fi->filePath() );
	if ( roots->count() <= 1 )
	    root->setOpen( TRUE ); // be interesting
    }

    mw.resize( 400, 400 );
    mw.setCaption( "Qt Example - Directory Browser" );
    mw.setAllColumnsShowFocus( TRUE );
    a.setMainWidget( &mw );
    mw.show();

    return a.exec();
}
