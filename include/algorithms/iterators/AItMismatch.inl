/*!
 *  \file    AItMismatch.inl Contains general template implementation of the
 *           iterator two sequences mismatch test algorithm.
 *  \brief   Iterator two sequences mismatch test algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator two sequences mismatch test algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   15.09.2006 02:42:53

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
#ifndef __AITMISMATCH_INL__
#define __AITMISMATCH_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_Iterator1, class T_Iterator2>
inline NUtility::CPair<T_Iterator1, T_Iterator2> mismatchNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2)
{ CALL
  return mismatchNext(a_crIterator1, a_crIterator2, NFunctions::FBoolEqual<const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
inline NUtility::CPair<T_Iterator1, T_Iterator2> mismatchNext(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator1 class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator1> >();
  // Check T_Iterator2 class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator2> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&> >();

  // Search only in valid iterators.
  T_Iterator1 it1(a_crIterator1);
  T_Iterator2 it2(a_crIterator2);
  if (it1.isValid() && it2.isValid())
  {
    do
    {
      if (!a_fEqual(it1.getValueRef(), it2.getValueRef()))
        return NUtility::CPair<T_Iterator1, T_Iterator2>(it1, it2);
    } while ((it1.stepForward() > 0) && (it1 != a_crIterator1) && (it2.stepForward() > 0) && (it2 != a_crIterator2));
    // Invalidate first iterator if we reach its sequence end.
    if ((it1 == a_crIterator1) || (it1.stepForward() == 0))
      it1 = T_Iterator1();
    // Invalidate second iterator if we reach its sequence end.
    if ((it2 == a_crIterator2) || (it2.stepForward() == 0))
      it2 = T_Iterator2();
  }
  return NUtility::CPair<T_Iterator1, T_Iterator2>(it1, it2);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2>
inline NUtility::CPair<T_Iterator1, T_Iterator2> mismatchPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2)
{ CALL
  return mismatchNext(reverceIt(a_crIterator1), reverceIt(a_crIterator2), NFunctions::FBoolEqual<const typename T_Iterator1::TReturn&, const typename T_Iterator2::TReturn&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator1, class T_Iterator2, typename T_BinaryPredicate>
inline NUtility::CPair<T_Iterator1, T_Iterator2> mismatchPrev(const T_Iterator1& a_crIterator1, const T_Iterator2& a_crIterator2, T_BinaryPredicate a_fEqual)
{ CALL
  return mismatchNext(reverceIt(a_crIterator1), reverceIt(a_crIterator2), a_fEqual);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
