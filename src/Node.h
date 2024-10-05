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

#ifndef NODE_H_
#define NODE_H_

#include <string>

class CSelection;
class GumboInternalNode;

class CNode
{
public:
    CNode(GumboInternalNode* apNode = nullptr) : mpNode(apNode) {}
    virtual ~CNode() = default;

    bool valid() const;
    CNode parent() const;
    CNode nextSibling() const;
    CNode prevSibling() const;
    unsigned int childNum() const;
    CNode childAt(size_t i) const;
    std::string attribute(const std::string& key) const;
    std::string text() const;
    std::string ownText() const;
    size_t startPos() const;
    size_t endPos() const;
    size_t startPosOuter() const;
    size_t endPosOuter() const;
    std::string tag() const;
    CSelection find(const std::string& aSelector) const;
private:
    GumboInternalNode* mpNode;
};

#endif /* NODE_H_ */

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
