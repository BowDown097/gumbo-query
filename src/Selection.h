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

#ifndef SELECTION_H_
#define SELECTION_H_

#include "SelectionIterator.h"
#include "Object.h"
#include <vector>

class GumboInternalNode;

class CSelection: public CObject
{
public:
    using iterator = CSelectionIterator;

    explicit CSelection(GumboInternalNode* apNode);
    explicit CSelection(const std::vector<GumboInternalNode*>& aNodes) : mNodes(aNodes) {}
    virtual ~CSelection() override = default;

    CSelection find(const std::string& aSelector) const;
    bool hasMatch() const;
    CNode nodeAt(size_t i) const;
    size_t nodeNum() const;

    iterator begin() const;
    iterator end() const;
    CNode operator[](size_t i) const;
private:
    std::vector<GumboInternalNode*> mNodes;
};

#endif /* SELECTION_H_ */

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
