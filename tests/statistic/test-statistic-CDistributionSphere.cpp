/*!
 *  \file    test-statistic-CDistributionSphere.cpp Testing of the
 *           CDistributionSphere class.
 *  \brief   Testing of the CDistributionSphere class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the CDistributionSphere class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth statistic tests
    VERSION:   1.0
    CREATED:   09.03.2009 03:45:00

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
#include <Depth/include/math/CMath.hpp>
#include <Depth/include/statistic/CDistributionSphere.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NGeometry;
using namespace NDepth::NMath;
using namespace NDepth::NStatistic;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CDistributionSphere sphere_distribution(CPoint3D<Treal>(2.0, 2.0, 2.0), CVector3D(2.0, 2.0, 2.0));

    // Check random number generator in the distribution.
    UT_ASSERT(sphere_distribution.isValidGenerator());

    // Check sphere distributed values.
    for (Tuint i = 0; i < 1000; ++i)
    {
      CPoint3D<Treal> p = sphere_distribution.randomPoint();
      UT_ASSERT(CMath::isNormal(p.m_X) && CMath::isNormal(p.m_Y) && CMath::isNormal(p.m_Z));

      // Check sphere radius.
      CVector3D v = p - sphere_distribution.getOrigin();
      UT_ASSERT_DELTA(v.length(), 2.0, 0.0001);
    }

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
