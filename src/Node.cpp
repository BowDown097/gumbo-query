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

#include "Node.h"
#include "Selection.h"
#include "QueryUtil.h"

bool CNode::valid() const
{
    return mpNode != nullptr;
}

CNode CNode::parent() const
{
	return CNode(mpNode->parent);
}

CNode CNode::nextSibling() const
{
	return parent().childAt(mpNode->index_within_parent + 1);
}

CNode CNode::prevSibling() const
{
	return parent().childAt(mpNode->index_within_parent - 1);
}

unsigned int CNode::childNum() const
{
    return mpNode->type == GUMBO_NODE_ELEMENT ? mpNode->v.element.children.length : 0;
}

CNode CNode::childAt(size_t i) const
{
    return mpNode->type == GUMBO_NODE_ELEMENT && i < mpNode->v.element.children.length
        ? CNode(static_cast<GumboNode*>(mpNode->v.element.children.data[i])) : CNode();
}

std::string CNode::attribute(const std::string& key) const
{
	if (mpNode->type != GUMBO_NODE_ELEMENT)
	{
		return "";
	}

	GumboVector attributes = mpNode->v.element.attributes;
	for (unsigned int i = 0; i < attributes.length; i++)
	{
        GumboAttribute* attr = static_cast<GumboAttribute*>(attributes.data[i]);
		if (key == attr->name)
		{
			return attr->value;
		}
	}

	return "";
}

std::string CNode::text() const
{
	return CQueryUtil::nodeText(mpNode);
}

std::string CNode::ownText() const
{
	return CQueryUtil::nodeOwnText(mpNode);
}

size_t CNode::startPos() const
{
	switch(mpNode->type)
	{
	  case GUMBO_NODE_ELEMENT:
		  return mpNode->v.element.start_pos.offset + mpNode->v.element.original_tag.length;
	  case GUMBO_NODE_TEXT:
		  return mpNode->v.text.start_pos.offset;
	  default:
		  return 0;
  }
}

size_t CNode::endPos() const
{
	switch(mpNode->type)
	{
	  case GUMBO_NODE_ELEMENT:
		  return mpNode->v.element.end_pos.offset;
	  case GUMBO_NODE_TEXT:
		  return mpNode->v.text.original_text.length + startPos();
	  default:
		  return 0;
	}
}

size_t CNode::startPosOuter() const
{
	switch(mpNode->type)
	{
	case GUMBO_NODE_ELEMENT:
		return mpNode->v.element.start_pos.offset;
	case GUMBO_NODE_TEXT:
		return mpNode->v.text.start_pos.offset;
	default:
		return 0;
	}
}

size_t CNode::endPosOuter() const
{
	switch(mpNode->type)
	{
	case GUMBO_NODE_ELEMENT:
		return mpNode->v.element.end_pos.offset + mpNode->v.element.original_end_tag.length;
	case GUMBO_NODE_TEXT:
		return mpNode->v.text.original_text.length + startPos();
	default:
		return 0;
	}
}

std::string CNode::tag() const
{
    return mpNode->type == GUMBO_NODE_ELEMENT ? gumbo_normalized_tagname(mpNode->v.element.tag): "";
}

CSelection CNode::find(const std::string& aSelector) const
{
    return CSelection(mpNode).find(aSelector);
}
/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
