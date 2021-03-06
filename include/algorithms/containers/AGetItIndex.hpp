/*!
 *  \file    AGetItIndex.hpp Contains general template implementation of the
 *           get indexed container's iterator algorithm.
 *  \brief   Get indexed container's iterator algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    28.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Get indexed container's iterator algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   28.03.2007 01:45:28

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
#ifndef __AGETITINDEX_HPP__
#define __AGETITINDEX_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/details/CGetItIndexHelper.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Get indexed container's iterator.
/*!
    \param a_rContainer - Reference to the container.
    \param a_cIndex - Indexed position to return.
    \return Iterator to the indexed container's value, or invalid iterator.
*/
template <class T_Container>
typename NTraits::MTraitsContainer<T_Container>::iterator getItIndex(T_Container& a_rContainer, const Tuint a_cIndex);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItIndex.inl>
/*==========================================================================*/
#endif
