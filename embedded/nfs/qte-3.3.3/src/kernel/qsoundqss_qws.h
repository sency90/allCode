/****************************************************************************
** $Id: qt/qsoundqss_qws.h   3.3.3   edited Jan 5 2004 $
**
** Definition of Qt Sound System
**
** Created : 001017
**
** Copyright (C) 2000-2002 Trolltech AS.  All rights reserved.
**
** This file is part of the kernel module of the Qt GUI Toolkit.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses for Qt/Embedded may use this file in accordance with the
** Qt Embedded Commercial License Agreement provided with the Software.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.trolltech.com/pricing.html or email sales@trolltech.com for
**   information about Qt Commercial License Agreements.
** See http://www.trolltech.com/gpl/ for GPL licensing information.
**
** Contact info@trolltech.com if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#ifndef QSOUNDQSS_QWS_H
#define QSOUNDQSS_QWS_H

#ifndef QT_H
#include "qserversocket.h"
#include "qsocket.h"
#endif // QT_H

#ifndef QT_NO_SOUND

#ifndef Q_OS_MAC

class QWSSoundServerData;

class QWSSoundServer : public QObject {
    Q_OBJECT
public:
    QWSSoundServer(QObject* parent=0);
    ~QWSSoundServer();
    void playFile( const QString& filename );

private:
    QWSSoundServerData* d;
};

#ifndef QT_NO_QWS_SOUNDSERVER
class QWSSoundClient : public QSocket {
    Q_OBJECT
public:
    QWSSoundClient( QObject* parent=0 );
    void play( const QString& filename );
};

class QWSSoundServerClient : public QSocket {
    Q_OBJECT

public:
    QWSSoundServerClient(int s, QObject* parent);
    ~QWSSoundServerClient();

signals:
    void play(const QString&);

private slots:
    void destruct();
    void tryReadCommand();
};

class QWSSoundServerSocket : public QServerSocket {
    Q_OBJECT

public:
    QWSSoundServerSocket(QObject* parent=0, const char* name=0);
    void newConnection(int s);

signals:
    void playFile(const QString& filename);
};
#endif

#endif // Q_OS_MAC
#endif // QT_NO_SOUND

#endif // QSOUNDQSS_QWS_H
