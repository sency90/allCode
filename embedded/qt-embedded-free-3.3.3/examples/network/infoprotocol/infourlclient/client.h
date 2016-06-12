/****************************************************************************
** $Id: qt/client.h   3.3.3   edited May 27 2003 $
**
** Copyright (C) 1992-2002 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef CLIENT_H
#define CLIENT_H

#include <qurloperator.h>

#include "clientbase.h"


class ClientInfo : public ClientInfoBase
{
    Q_OBJECT

public:
    ClientInfo( QWidget *parent = 0, const char *name = 0 );

private slots:
    void downloadFile();
    void newData( const QByteArray &ba );

private:
    QUrlOperator op;
    QString getOpenFileName();
};

#endif // CLIENT_H

