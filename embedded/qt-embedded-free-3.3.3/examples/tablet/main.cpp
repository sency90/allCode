/****************************************************************************
** $Id: qt/main.cpp   3.3.3   edited May 27 2003 $
**
** Copyright ( C ) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "scribble.h"
#include "tabletstats.h"
#include <qapplication.h>
#include <qtabwidget.h>


int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    QTabWidget tab;
    Scribble scribble(&tab, "scribble");
    TabletStats tabStats( &tab, "tablet stats" );
    
    scribble.setMinimumSize( 500, 350 );
    tabStats.setMinimumSize( 500, 350 );
    tab.addTab(&scribble, "Scribble" );
    tab.addTab(&tabStats, "Tablet Stats" );
    
    a.setMainWidget( &tab );
    if ( QApplication::desktop()->width() > 550
	 && QApplication::desktop()->height() > 366 )
	tab.show();
    else
	tab.showMaximized();
    return a.exec();
}
