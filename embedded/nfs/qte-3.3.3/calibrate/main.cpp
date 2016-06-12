#include <qapplication.h>
#include <qmainwindow.h>
#include "calibrate.h"

int main( int argc, char ** argv )
{
	QApplication a( argc, argv );

    Calibrate *c = new Calibrate;
    a.setMainWidget( c );
    c->show();

    return a.exec();
}
