/****************************************************************************
** $Id: qt/qptrqueue.h   3.3.3   edited May 27 2003 $
**
** Definition of QPtrQueue template/macro class
**
** Created : 920917
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of the tools module of the Qt GUI Toolkit.
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
** Licensees holding valid Qt Enterprise Edition or Qt Professional Edition
** licenses may use this file in accordance with the Qt Commercial License
** Agreement provided with the Software.
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

#ifndef QPTRQUEUE_H
#define QPTRQUEUE_H

#ifndef QT_H
#include "qglist.h"
#endif // QT_H

template<class type>
class QPtrQueue : protected QGList
{
public:
    QPtrQueue()				{}
    QPtrQueue( const QPtrQueue<type> &q ) : QGList(q) {}
    ~QPtrQueue()			{ clear(); }
    QPtrQueue<type>& operator=(const QPtrQueue<type> &q)
			{ return (QPtrQueue<type>&)QGList::operator=(q); }
    bool  autoDelete() const		{ return QPtrCollection::autoDelete(); }
    void  setAutoDelete( bool del )	{ QPtrCollection::setAutoDelete(del); }
    uint  count()   const		{ return QGList::count(); }
    bool  isEmpty() const		{ return QGList::count() == 0; }
    void  enqueue( const type *d )	{ QGList::append(Item(d)); }
    type *dequeue()			{ return (type *)QGList::takeFirst();}
    bool  remove()			{ return QGList::removeFirst(); }
    void  clear()			{ QGList::clear(); }
    type *head()    const		{ return (type *)QGList::cfirst(); }
	  operator type *() const	{ return (type *)QGList::cfirst(); }
    type *current() const		{ return (type *)QGList::cfirst(); }

#ifdef Q_QDOC
protected:
    virtual QDataStream& read( QDataStream&, QPtrCollection::Item& );
    virtual QDataStream& write( QDataStream&, QPtrCollection::Item ) const;
#endif

private:
    void  deleteItem( Item d );
};

#if !defined(Q_BROKEN_TEMPLATE_SPECIALIZATION)
template<> inline void QPtrQueue<void>::deleteItem( QPtrCollection::Item )
{
}
#endif

template<class type> inline void QPtrQueue<type>::deleteItem( QPtrCollection::Item d )
{
    if ( del_item ) delete (type *)d;
}

#ifndef QT_NO_COMPAT
#define QQueue QPtrQueue
#endif

#endif // QPTRQUEUE_H
