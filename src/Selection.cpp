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

#include "Selection.h"
#include "Parser.h"
#include "QueryUtil.h"
#include "Node.h"

CSelection::CSelection(GumboNode* apNode)
{
	mNodes.push_back(apNode);
}

CSelection CSelection::find(const std::string& aSelector) const
{
    CSelector* sel = CParser::create(aSelector);
	std::vector<GumboNode*> ret;
    for (std::vector<GumboNode*>::const_iterator it = mNodes.begin(); it != mNodes.end(); ++it)
	{
        ret = CQueryUtil::unionNodes(ret, sel->matchAll(*it));
	}
	sel->release();
	return CSelection(ret);
}

bool CSelection::hasMatch() const
{
    return mNodes.size() > 0;
}

CNode CSelection::nodeAt(size_t i) const
{
    return i < mNodes.size() ? CNode(mNodes[i]) : CNode();
}

size_t CSelection::nodeNum() const
{
	return mNodes.size();
}

CSelection::iterator CSelection::begin() const
{
    return CSelection::iterator(this, 0);
}

CSelection::iterator CSelection::end() const
{
    return CSelection::iterator(this, nodeNum());
}

CNode CSelection::operator[](size_t i) const
{
    return nodeAt(i);
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */

