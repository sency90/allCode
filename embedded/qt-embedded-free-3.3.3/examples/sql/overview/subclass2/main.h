/****************************************************************************
** $Id: qt/main.h   3.3.3   edited May 27 2003 $
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

class QSqlRecord;

class InvoiceItemCursor : public QSqlCursor
{
    public:
	InvoiceItemCursor();
};


