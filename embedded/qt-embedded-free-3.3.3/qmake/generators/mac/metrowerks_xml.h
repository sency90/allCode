/****************************************************************************
** $Id: qt/metrowerks_xml.h   3.3.3   edited May 30 2003 $
**
** Definition of MetrowerksMakefileGenerator class.
**
** Copyright (C) 1992-2003 Trolltech AS.  All rights reserved.
**
** This file is part of qmake.
**
** This file may be distributed under the terms of the Q Public License
** as defined by Trolltech AS of Norway and appearing in the file
** LICENSE.QPL included in the packaging of this file.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition licenses may use this
** file in accordance with the Qt Commercial License Agreement provided
** with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/qpl/ for QPL licensing information.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef __METROWERKS_XML_H__
#define __METROWERKS_XML_H__

#include "makefile.h"

class MetrowerksMakefileGenerator : public MakefileGenerator
{
    bool createFork(const QString &f);
    bool fixifyToMacPath(QString &c, QString &v, bool exists=TRUE);

    bool init_flag;

    bool writeMakeParts(QTextStream &);
    bool writeSubDirs(QTextStream &);

    bool writeMakefile(QTextStream &);
    QString findTemplate(const QString &file);
    void init();
public:
    MetrowerksMakefileGenerator(QMakeProject *p);
    ~MetrowerksMakefileGenerator();

    bool openOutput(QFile &file) const;
protected:
    virtual void processPrlFiles();
    virtual void processPrlVariable(const QString &var, const QStringList &l);
    virtual bool doDepends() const { return FALSE; } //never necesary
};

inline MetrowerksMakefileGenerator::~MetrowerksMakefileGenerator()
{ }

#endif /* __METROWERKS_XML_H__ */
