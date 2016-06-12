/****************************************************************************
** $Id: qt/fontdisplayer.h   3.3.3   edited May 27 2003 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef FontDisplayer_H
#define FontDisplayer_H

#include <qframe.h>
#include <qmainwindow.h>

class QSlider;

class FontRowTable : public QFrame {
    Q_OBJECT
public:
    FontRowTable( QWidget* parent=0, const char* name=0 );

    QSize sizeHint() const;

signals:
    void fontInformation(const QString&);

public slots:
    void setRow(int);
    void chooseFont();


protected:
    QSize cellSize() const;
    void paintEvent( QPaintEvent* );
private:
    QFont tablefont;
    int row;
};

class FontDisplayer : public QMainWindow {
    Q_OBJECT
public:
    FontDisplayer( QWidget* parent=0, const char* name=0 );
};

#endif
