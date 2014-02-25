/*!
 *  \file    example-algorithms-AUnique.cpp Example of using the iterator 
 *           unique algorithm.
 *  \brief   Example of using the iterator unique algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the iterator unique algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   01.06.2007 21:39:32

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
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/algorithms/containers/AUnique.hpp>
#include <Depth/include/algorithms/containers/AUniqueCopy.hpp>
#include <Depth/include/algorithms/containers/AUniqueCount.hpp>
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/CListDC.hpp>
#include <Depth/include/containers/CListDL.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NContainers;
using namespace NDepth::NAlgorithms::NIterators;
/*==========================================================================*/
// Write instance of the CArray<Tsint> class into the given writer.
IWriter& operator << (IWriter& writer, const CArray<Tsint>& a_crArray)
{ CALL
  writer << STR("CArray<Tsint>(") << STR("size = ") << a_crArray.getSize() << STR(")") << ln;
  CArray<Tsint>::TIteratorConst it = a_crArray.getItFirst();
  if (it.isValid())
  {
    writer << STR("{") << ln;
    do
    {
      writer << STR(" item = ") << *it << ln;
    } while (it.stepForward() == 1);
    writer << STR("}") << ln;
  }
  return writer;
}
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    CArray<Tsint> array;
    CListDC<Tsint> circle;
    CListDL<Tsint> list;

    // Fill the array.
    array.insertLast(1);
    array.insertLast(2);
    array.insertLast(2);
    array.insertLast(3);
    array.insertLast(4);
    array.insertLast(4);
    array.insertLast(4);
    array.insertLast(5);
    array.insertLast(6);
    array.insertLast(6);
    array.insertLast(6);
    array.insertLast(6);

    // Fill the double circled list.
    circle.insertCurrentForward(1);
    circle.insertNext(6);
    circle.insertNext(6);
    circle.insertNext(6);
    circle.insertNext(6);
    circle.insertNext(5);
    circle.insertNext(4);
    circle.insertNext(4);
    circle.insertNext(4);
    circle.insertNext(3);
    circle.insertNext(2);
    circle.insertNext(2);

    // Fill the double linked list.
    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(2);
    list.insertLast(3);
    list.insertLast(4);
    list.insertLast(4);
    list.insertLast(4);
    list.insertLast(5);
    list.insertLast(6);
    list.insertLast(6);
    list.insertLast(6);
    list.insertLast(6);

    // Find unique items counts.
    stdoutput << STR("uniqueCount(array) = ") << uniqueCount(array) << ln;
    stdoutput << STR("uniqueCountPrev(array) = ") << uniqueCountPrev(array.getItLast()) << ln;
    stdoutput << STR("uniqueCount(circle) = ") << uniqueCount(circle) << ln;
    stdoutput << STR("uniqueCountPrev(circle) = ") << uniqueCountPrev(circle.getItCurrent().getBackward()) << ln;
    stdoutput << STR("uniqueCount(list) = ") << uniqueCount(list) << ln;
    stdoutput << STR("uniqueCountPrev(list) = ") << uniqueCountPrev(list.getItLast()) << ln;

    // Unique containers.
    CArray<Tsint> array_circle;
    CArray<Tsint> array_list;

    unique(array);
    uniqueCopy(circle, array_circle);
    uniqueCopy(list, array_list);

    // Show containers.
    stdoutput << array << ln << array_circle << ln << array_list << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/