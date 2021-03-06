/*!
 *  \file    AItRemoveCopyAll.inl Contains general template implementation of
 *           the iterator remove and copy all items algorithm.
 *  \brief   Iterator remove and copy all items algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator remove and copy all items algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   16.05.2007 20:19:53

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
#ifndef __AITREMOVECOPYALL_INL__
#define __AITREMOVECOPYALL_INL__
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
template <class T_Iterator, class T_IteratorCopy>
inline Tuint removeCopyAllNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_Iterator class constraint to be a remove forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorRemoveForward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertForward<T_IteratorCopy> >();

  Tuint result = 0;

  // Copy and remove values only of valid iterators.
  T_Iterator it1(a_crIterator);
  T_IteratorCopy it2(a_crIteratorCopy);
  if (it1.isValid() && it2.isValidContainer())
  {
    // Copy and remove sequence values.
    while (it1.isValid())
    {
      // Copy current value.
      if (it2.isValid())
      {
        if (!it2.insertNext(it1.getValueRef()) || (it2.stepForward() == 0))
          return result;
      }
      else
      {
        if (!it2.insertBackward(it1.getValueRef()))
          return result;
      }
      if (!it1.removeForward())
        return result;
      ++result;
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy, typename T_ValueType>
inline Tuint removeCopyAllNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, const T_ValueType& a_crValue)
{ CALL
  return removeCopyAllNext(a_crIterator, a_crIteratorCopy, a_crValue, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const T_ValueType&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy, typename T_ValueType, typename T_BinaryPredicate>
inline Tuint removeCopyAllNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_Iterator class constraint to be a remove forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorRemoveForward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertForward<T_IteratorCopy> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const T_ValueType&> >();

  Tuint result = 0;

  // Copy and remove values only of valid iterators.
  T_Iterator it1(a_crIterator);
  T_IteratorCopy it2(a_crIteratorCopy);
  if (it1.isValid() && it2.isValidContainer())
  {
    // Copy sequence values.
    while (it1.isValid())
    {
      if (a_fEqual(it1.getValueRef(), a_crValue))
      {
        // Copy current value.
        if (it2.isValid())
        {
          if (!it2.insertNext(it1.getValueRef()) || (it2.stepForward() == 0))
            return result;
        }
        else
        {
          if (!it2.insertBackward(it1.getValueRef()))
            return result;
        }
        if (!it1.removeForward())
          return result;
        ++result;
      }
      else
      {
        if ((it1.stepForward() == 0) || (it1 == a_crIterator))
          return result;
      }
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy>
inline Tuint removeCopyAllPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_Iterator class constraint to be a remove backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorRemoveBackward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertBackward<T_IteratorCopy> >();

  Tuint result = 0;

  // Copy values only of valid iterators.
  T_Iterator it1(a_crIterator);
  T_IteratorCopy it2(a_crIteratorCopy);
  if (it1.isValid() && it2.isValidContainer())
  {
    // Copy sequence values.
    while (it1.isValid())
    {
      // Copy current value.
      if (it2.isValid())
      {
        if (!it2.insertPrev(it1.getValueRef()) || (it2.stepBackward() == 0))
          return result;
      }
      else
      {
        if (!it2.insertForward(it1.getValueRef()))
          return result;
      }
      if (!it1.removeBackward())
        return result;
      ++result;
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy, typename T_ValueType>
inline Tuint removeCopyAllPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, const T_ValueType& a_crValue)
{ CALL
  return removeCopyAllPrev(a_crIterator, a_crIteratorCopy, a_crValue, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const T_ValueType&>());
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy, typename T_ValueType, typename T_BinaryPredicate>
inline Tuint removeCopyAllPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_Iterator class constraint to be a remove forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorRemoveBackward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertBackward<T_IteratorCopy> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const T_ValueType&> >();

  Tuint result = 0;

  // Copy values only of valid iterators.
  T_Iterator it1(a_crIterator);
  T_IteratorCopy it2(a_crIteratorCopy);
  if (it1.isValid() && it2.isValidContainer())
  {
    // Copy sequence values.
    while (it1.isValid())
    {
      if (a_fEqual(it1.getValueRef(), a_crValue))
      {
        // Copy current value.
        if (it2.isValid())
        {
          if (!it2.insertPrev(it1.getValueRef()) || (it2.stepBackward() == 0))
            return result;
        }
        else
        {
          if (!it2.insertForward(it1.getValueRef()))
            return result;
        }
        if (!it1.removeBackward())
          return result;
        ++result;
      }
      else
      {
        if ((it1.stepForward() == 0) || (it1 == a_crIterator))
          return result;
      }
    }
  }
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
