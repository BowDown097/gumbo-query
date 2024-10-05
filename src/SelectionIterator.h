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

#ifndef SELECTIONITERATOR_H_
#define SELECTIONITERATOR_H_

#include <iterator>

class CNode;
class CSelection;

class CSelectionIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = CNode;
    using difference_type = std::ptrdiff_t;
    using reference = value_type&;
    using pointer = value_type*;

    CSelectionIterator(const CSelection* sel, unsigned idx)
        : idx(idx), sel(sel) {}

    value_type operator*() const;

    CSelectionIterator& operator++()
    {
        ++idx;
        return *this;
    }

    CSelectionIterator operator++(int)
    {
        CSelectionIterator temp = *this;
        ++(*this);
        return temp;
    }

    CSelectionIterator& operator--()
    {
        --idx;
        return *this;
    }

    CSelectionIterator operator--(int)
    {
        CSelectionIterator temp = *this;
        --(*this);
        return temp;
    }

    value_type operator[](difference_type n) const;

    CSelectionIterator& operator+=(difference_type n)
    {
        idx += n;
        return *this;
    }

    CSelectionIterator operator+(difference_type n)
    {
        CSelectionIterator temp = *this;
        *this += n;
        return temp;
    }

    CSelectionIterator& operator-=(difference_type n)
    {
        idx -= n;
        return *this;
    }

    CSelectionIterator operator-(difference_type n)
    {
        CSelectionIterator temp = *this;
        *this -= n;
        return temp;
    }

    const CSelectionIterator& base() const
    { return *this; }

    [[nodiscard]] friend bool operator==(const CSelectionIterator& lhs, const CSelectionIterator& rhs)
    { return lhs.idx == rhs.idx && lhs.sel == rhs.sel; }
    [[nodiscard]] friend bool operator!=(const CSelectionIterator& lhs, const CSelectionIterator& rhs)
    { return !(lhs == rhs); }
    [[nodiscard]] friend bool operator<(const CSelectionIterator& lhs, const CSelectionIterator& rhs)
    { return lhs.idx < rhs.idx; }
    [[nodiscard]] friend bool operator>(const CSelectionIterator& lhs, const CSelectionIterator& rhs)
    { return lhs.idx > rhs.idx; }
    [[nodiscard]] friend bool operator<=(const CSelectionIterator& lhs, const CSelectionIterator& rhs)
    { return lhs < rhs || lhs == rhs; }
    [[nodiscard]] friend bool operator>=(const CSelectionIterator& lhs, const CSelectionIterator& rhs)
    { return lhs > rhs || lhs == rhs; }
private:
    const CSelection* sel;
    unsigned idx;
};

#endif /* SELECTION_H_ */

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
