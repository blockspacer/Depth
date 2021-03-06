/*!
 *  \file    AStringReplaceAll.hpp Contains general template implementation of
 *           the algorithm to find and replace all (sub)strings in the given
 *           string object using the given searching algorithm.
 *  \brief   Algorithm to find and replace all (sub)strings in the given string using the given searching algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find and replace all (sub)strings in the given string using the given searching algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   12.01.2010 02:53:46

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
#ifndef __ASTRINGREPLACEALL_HPP__
#define __ASTRINGREPLACEALL_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/string/AStringSearch.hpp>
#include <Depth/include/concept/types/MConceptIString.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Forward find and replace all (sub)strings in the given string using the given searching algorithm.
/*!
    Forward find and replace all (sub)strings in the given  string  using  the
    given searching algorithm.

    \param a_rSource - Reference to the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \param a_crReplacePattern - Constant reference to the replace pattern string.
    \param a_StringSearchAlgorithm - Instance of the given string searching algorithm.
    \return true  - if (sub)string was found and replaced. \n
            false - if (sub)string was not found and replaced. \n
*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
Tbool stringReplaceAllNext(T_SourceStringClass& a_rSource, const T_PatternStringType& a_crPattern, const T_ReplacePatternStringType& a_crReplacePattern, T_StringSearchAlgorithm a_StringSearchAlgorithm);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward find and replace all (sub)strings in the given string using the given searching algorithm (maximal length version).
/*!
    Forward find and replace all (sub)strings in the given  string  using  the
    given searching algorithm.

    \param a_rSource - Reference to the source string.
    \param a_cSourceLength - Maximal length value of the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \param a_cPatternLength - Maximal length value of the pattern string.
    \param a_crReplacePattern - Constant reference to the replace pattern string.
    \param a_cReplacePatternLength - Maximal length value of the replace pattern string.
    \param a_StringSearchAlgorithm - Instance of the given string searching algorithm.
    \return true  - if (sub)string was found and replaced. \n
            false - if (sub)string was not found and replaced. \n
*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
Tbool stringReplaceAllNext(T_SourceStringClass& a_rSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward find and replace all (sub)strings in the given string using the given searching algorithm (index offset and maximal length version).
/*!
    Forward find and replace all (sub)strings in the given  string  using  the
    given searching algorithm.

    \param a_rSource - Reference to the source string.
    \param a_cSourceIndex - Index offset value of the source string.
    \param a_cSourceLength - Maximal length value of the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \param a_cPatternIndex - Index offset value of the pattern string.
    \param a_cPatternLength - Maximal length value of the pattern string.
    \param a_crReplacePattern - Constant reference to the replace pattern string.
    \param a_cReplacePatternIndex - Index offset value of the replace pattern string.
    \param a_cReplacePatternLength - Maximal length value of the replace pattern string.
    \param a_StringSearchAlgorithm - Instance of the given string searching algorithm.
    \return true  - if (sub)string was found and replaced. \n
            false - if (sub)string was not found and replaced. \n
*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
Tbool stringReplaceAllNext(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternIndex, const Tuint a_cReplacePatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward find and replace all (sub)strings in the given string using the given searching algorithm.
/*!
    Backward find and replace all (sub)strings in the given string  using  the
    given searching algorithm.

    \param a_rSource - Reference to the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \param a_crReplacePattern - Constant reference to the replace pattern string.
    \param a_StringSearchAlgorithm - Instance of the given string searching algorithm.
    \return true  - if (sub)string was found and replaced. \n
            false - if (sub)string was not found and replaced. \n
*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
Tbool stringReplaceAllPrev(T_SourceStringClass& a_rSource, const T_PatternStringType& a_crPattern, const T_ReplacePatternStringType& a_crReplacePattern, T_StringSearchAlgorithm a_StringSearchAlgorithm);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward find and replace all (sub)strings in the given string using the given searching algorithm (maximal length version).
/*!
    Backward find and replace all (sub)strings in the given string  using  the
    given searching algorithm.

    \param a_rSource - Reference to the source string.
    \param a_cSourceLength - Maximal length value of the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \param a_cPatternLength - Maximal length value of the pattern string.
    \param a_crReplacePattern - Constant reference to the replace pattern string.
    \param a_cReplacePatternLength - Maximal length value of the replace pattern string.
    \param a_StringSearchAlgorithm - Instance of the given string searching algorithm.
    \return true  - if (sub)string was found and replaced. \n
            false - if (sub)string was not found and replaced. \n
*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
Tbool stringReplaceAllPrev(T_SourceStringClass& a_rSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward find and replace all (sub)strings in the given string using the given searching algorithm (index offset and maximal length version).
/*!
    Backward find and replace all (sub)strings in the given string  using  the
    given searching algorithm.

    \param a_rSource - Reference to the source string.
    \param a_cSourceIndex - Index offset value of the source string.
    \param a_cSourceLength - Maximal length value of the source string.
    \param a_crPattern - Constant reference to the pattern string.
    \param a_cPatternIndex - Index offset value of the pattern string.
    \param a_cPatternLength - Maximal length value of the pattern string.
    \param a_crReplacePattern - Constant reference to the replace pattern string.
    \param a_cReplacePatternIndex - Index offset value of the replace pattern string.
    \param a_cReplacePatternLength - Maximal length value of the replace pattern string.
    \param a_StringSearchAlgorithm - Instance of the given string searching algorithm.
    \return true  - if (sub)string was found and replaced. \n
            false - if (sub)string was not found and replaced. \n
*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType, typename T_StringSearchAlgorithm>
Tbool stringReplaceAllPrev(T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternIndex, const Tuint a_cReplacePatternLength, T_StringSearchAlgorithm a_StringSearchAlgorithm);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/string/AStringReplaceAll.inl>
/*==========================================================================*/
#endif
