/***************************************************************************
 *
 * $Id$
 *
 **************************************************************************/

/**
 * @file $HeadURL$
 * @author $Author$(hoping@baimashi.com)
 * @date $Date$
 * @version $Revision$
 * @brief
 *
 **/

#include "SelectionIterator.h"
#include "Node.h"
#include "Selection.h"

CSelectionIterator::value_type CSelectionIterator::operator*() const
{ return sel->nodeAt(idx); }

CSelectionIterator::value_type CSelectionIterator::operator[](CSelectionIterator::difference_type n) const
{ return sel->nodeAt(idx); }

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
