/*!
 *  \file    CRectMaker.inl Utility class that helps to create CRect
 *           instances from specific values.
 *  \brief   Rectangle maker class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Rectangle maker class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Geometry
    VERSION:   1.0
    CREATED:   03.03.2006 02:17:37

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
#ifndef __CRECTMAKER_INL__
#define __CRECTMAKER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NGeometry {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline CRect<T_Type> CRectMaker::make(const T_Type a_cX1, const T_Type a_cY1, const T_Type a_cX2, const T_Type a_cY2)
{ CALL
  return CRect<T_Type>(a_cX1, a_cY1, a_cX2, a_cY2);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type> CRectMaker::make(const CPoint2D<T_Type>& a_crA, const CPoint2D<T_Type>& a_crB)
{ CALL
  return CRect<T_Type>(a_crA, a_crB);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type> CRectMaker::make(const T_Type a_cpCoordinatesBuffer[])
{ CALL
  return CRect<T_Type>(a_cpCoordinatesBuffer);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CRect<T_Type> CRectMaker::make(const CRect<T_Type>& a_crInstance)
{ CALL
  return CRect<T_Type>(a_crInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
