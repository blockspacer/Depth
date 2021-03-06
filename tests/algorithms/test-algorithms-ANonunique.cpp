/*!
 *  \file    test-algorithms-ANonunique.cpp Testing of the iterator non 
 *           unique algorithm.
 *  \brief   Testing of the iterator non unique algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the iterator non unique algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   05.06.2007 02:07:42

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
// Common headers.
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/algorithms/containers/ANonunique.hpp>
#include <Depth/include/algorithms/containers/ANonuniqueCopy.hpp>
#include <Depth/include/algorithms/containers/ANonuniqueCount.hpp>
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/CListDC.hpp>
#include <Depth/include/containers/CListDL.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NContainers;
using namespace NDepth::NAlgorithms::NIterators;
using namespace NDepth::NContainers;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CArray<Tsint> array;
    CListDC<Tsint> circle;
    CListDL<Tsint> list;

    // Fill the array.
    UT_ASSERT(array.insertLast(1));
    UT_ASSERT(array.insertLast(2));
    UT_ASSERT(array.insertLast(2));
    UT_ASSERT(array.insertLast(3));
    UT_ASSERT(array.insertLast(4));
    UT_ASSERT(array.insertLast(4));
    UT_ASSERT(array.insertLast(4));
    UT_ASSERT(array.insertLast(5));
    UT_ASSERT(array.insertLast(6));
    UT_ASSERT(array.insertLast(6));
    UT_ASSERT(array.insertLast(6));
    UT_ASSERT(array.insertLast(6));

    // Fill the double circled list.
    UT_ASSERT(circle.insertCurrentForward(1));
    UT_ASSERT(circle.insertNext(6));
    UT_ASSERT(circle.insertNext(6));
    UT_ASSERT(circle.insertNext(6));
    UT_ASSERT(circle.insertNext(6));
    UT_ASSERT(circle.insertNext(5));
    UT_ASSERT(circle.insertNext(4));
    UT_ASSERT(circle.insertNext(4));
    UT_ASSERT(circle.insertNext(4));
    UT_ASSERT(circle.insertNext(3));
    UT_ASSERT(circle.insertNext(2));
    UT_ASSERT(circle.insertNext(2));

    // Fill the double linked list.
    UT_ASSERT(list.insertLast(1));
    UT_ASSERT(list.insertLast(2));
    UT_ASSERT(list.insertLast(2));
    UT_ASSERT(list.insertLast(3));
    UT_ASSERT(list.insertLast(4));
    UT_ASSERT(list.insertLast(4));
    UT_ASSERT(list.insertLast(4));
    UT_ASSERT(list.insertLast(5));
    UT_ASSERT(list.insertLast(6));
    UT_ASSERT(list.insertLast(6));
    UT_ASSERT(list.insertLast(6));
    UT_ASSERT(list.insertLast(6));

    // Check non unique items counts.
    UT_ASSERT_EQUAL(nonuniqueCount(array), 3);
    UT_ASSERT_EQUAL(nonuniqueCountPrev(array.getItLast()), 3);
    UT_ASSERT_EQUAL(nonuniqueCount(circle), 3);
    UT_ASSERT_EQUAL(nonuniqueCountPrev(circle.getItCurrent().getBackward()), 3);
    UT_ASSERT_EQUAL(nonuniqueCount(list), 3);
    UT_ASSERT_EQUAL(nonuniqueCountPrev(list.getItLast()), 3);

    // Non unique containers.
    CArray<Tsint> array_circle;
    CArray<Tsint> array_list;

    UT_ASSERT(nonunique(array));
    UT_ASSERT_EQUAL(nonuniqueCopy(circle, array_circle), 3);
    UT_ASSERT_EQUAL(nonuniqueCopy(list, array_list), 3);

    // Check containers content.
    UT_ASSERT_CHECK_ARRAY(array);
    UT_ASSERT_CHECK_ARRAY(array_circle);
    UT_ASSERT_CHECK_ARRAY(array_list);

    UT_ACCEPT;
  }

  // Check the given instance of the CArray<Tsint> class.
  void UT_ASSERT_CHECK_ARRAY(const CArray<Tsint>& a_crArray)
  { CALL
    Tsint value = 2;
    CArray<Tsint>::TIteratorConst it = a_crArray.getItFirst();
    if (it.isValid())
    {
      do
      {
        UT_ASSERT_EQUAL(*it, value);
        value += 2;
      } while (it.stepForward() == 1);
    }
    UT_ASSERT_EQUAL(value, 8);
  }
} the_Test;
/*==========================================================================*/
