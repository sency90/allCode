/****************************************************************************
** $Id: qt/buttongroups.h   3.3.3   edited May 27 2003 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef BUTTONS_GROUPS_H
#define BUTTONS_GROUPS_H

#include <qwidget.h>

class QCheckBox;
class QRadioButton;

class ButtonsGroups : public QWidget
{
    Q_OBJECT

public:
    ButtonsGroups( QWidget *parent = 0, const char *name = 0 );

protected:
    QCheckBox *state;
    QRadioButton *rb21, *rb22, *rb23;

protected slots:    
    void slotChangeGrp3State();

};

#endif
