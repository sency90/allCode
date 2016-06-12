/****************************************************************************
** $Id: qt/structureparser.cpp   3.3.3   edited Jun 12 2003 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "structureparser.h"

#include <stdio.h>
#include <qstring.h>
 
bool StructureParser::startDocument()
{
    indent = "";
    return TRUE;
}

bool StructureParser::startElement( const QString&, const QString&, 
                                    const QString& qName, 
                                    const QXmlAttributes& )
{
    printf( "%s%s\n", (const char*)indent, (const char*)qName );
    indent += "    ";
    return TRUE;
}

bool StructureParser::endElement( const QString&, const QString&, const QString& )
{
    indent.remove( (uint)0, 4 );
    return TRUE;
}
