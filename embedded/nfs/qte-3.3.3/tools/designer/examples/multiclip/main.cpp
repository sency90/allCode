/****************************************************************************
** $Id: qt/main.cpp   3.3.3   edited May 5 2003 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include <qapplication.h>
#include "multiclip.h"


int main( int argc, char *argv[] ) 
{
    QApplication app( argc, argv );

    MulticlipForm clippingForm;
    app.setMainWidget( &clippingForm );
    clippingForm.show();

    return app.exec();
}


