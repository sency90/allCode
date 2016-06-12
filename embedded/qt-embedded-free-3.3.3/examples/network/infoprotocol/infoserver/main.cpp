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

#include "server.h"

int main( int argc, char** argv )
{
    QApplication app( argc, argv );
    Q_UINT16 port = ( argc > 1 ) ? QString( argv[ 1 ] ).toInt() : infoPort;
    ServerInfo info( port, 0, "server info" );
    app.setMainWidget( &info );
    info.show();
    return app.exec();
}
