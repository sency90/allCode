/****************************************************************************
** $Id: qt/view.h   3.3.3   edited May 27 2003 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef VIEW_H
#define VIEW_H

#include <qvbox.h>
#include <qcstring.h>
#include <qurloperator.h>

class QMultiLineEdit;

class View : public QVBox
{
    Q_OBJECT
    
public:
    View();
    
private slots:
    void downloadFile();
    void newData( const QByteArray &ba );

private:
    QMultiLineEdit *fileView;
    QUrlOperator op;
    
    QString getOpenFileName();
};

#endif
