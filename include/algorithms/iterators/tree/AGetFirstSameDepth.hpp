/*!
 *  \file    AGetFirstSameDepth.hpp Contains implementation of the algorithm
 *           which searches first tree node with same depth as in given one.
 *  \brief   Algorithm to find first tree node with same depth.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find first tree node with same depth.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template tree iterators algorithms
    VERSION:   1.0
    CREATED:   30.06.2006 00:52:28

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

    This program is distributed in the  hope  that  it  will  be  useful,  but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General  Public  License
    for more details.

    You should have received a copy of the GNU General  Public  License  along
    with this program; if not, write to the Free Software Foundation, Inc., 59
    Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#ifndef __AGETFIRSTSAMEDEPTH_HPP__
#define __AGETFIRSTSAMEDEPTH_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/tree/AGetPrevSameDepth.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*--------------------------------------------------------------------------*/
namespace NTree {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Get first node with same depth as in given one.
/*!
    Algorithm searches for the first node with same depth as in given one  and
    return its iterator. If given node is the first node with the same  depth,
    returned iterator will be equal to the given one.

    \param a_crTreeIterator - Constant reference to the tree iterator.
    \return Iterator to the first tree node with same depth.
*/
template <class T_TreeIterator>
T_TreeIterator getFirstSameDepth(const T_TreeIterator& a_crTreeIterator);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/tree/AGetFirstSameDepth.inl>
/*==========================================================================*/
#endif
