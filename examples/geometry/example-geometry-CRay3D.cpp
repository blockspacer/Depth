/*!
 *  \file    example-geometry-CRay3D.cpp Example of using the CRay3D class.
 *  \brief   Example of using the CRay3D class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.07.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CRay3D class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth geometry examples
    VERSION:   1.0
    CREATED:   10.07.2008 01:38:57

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
#include <Depth/include/geometry/CRay3D.hpp>
#include <Depth/include/math/CMathConstants.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NGeometry;
using namespace NDepth::NMath;
/*==========================================================================*/
// Write instance of the CPoint3D<Treal> class into the given writer.
IWriter& operator << (IWriter& writer, const CPoint3D<Treal>& a_crPoint)
{ CALL
  return writer << STR("CPoint3D<Treal>(") << a_crPoint.m_X << STR(", ") << a_crPoint.m_Y << STR(", ") << a_crPoint.m_Z << STR(")");
}
/*--------------------------------------------------------------------------*/
// Write instance of the CVector3D class into the given writer.
IWriter& operator << (IWriter& writer, const CVector3D& a_crVector)
{ CALL
  return writer << STR("CVector3D(") << a_crVector.m_X << STR(", ") << a_crVector.m_Y << STR(", ") << a_crVector.m_Z << STR(")");
}
/*--------------------------------------------------------------------------*/
// Write instance of the CRay3D class into the given writer.
IWriter& operator << (IWriter& writer, const CRay3D& a_crRay)
{ CALL
  return writer << STR("CRay3D(") << STR("origin(") << a_crRay.m_Origin << STR(")") << STR(", ") << STR("direction(") << a_crRay.m_Direction << STR(")") << STR(")");
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

    CRay3D ray(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(-1.0, -1.0, -1.0));
    stdoutput << STR("CRay3D ray(CPoint3D<Treal>(0.0, 0.0, 0.0), CVector3D(-1.0, -1.0, -1.0));") << ln << STR(" ---> ") << ray << ln;

    ray.negate();
    stdoutput << STR("ray.negate();") << ln << STR(" ---> ") << ray << ln;

    CPoint3D<Treal> point = ray.getOffsetPoint(5.0);
    stdoutput << STR("CPoint3D<Treal> point = ray.getOffsetPoint(5.0);") << ln << STR(" ---> ") << point << ln;

    CPoint3D<Treal> projection = ray.project(CPoint3D<Treal>(8.0, 4.0, 2.0));
    stdoutput << STR("CPoint3D<Treal> projection = ray.project(CPoint3D<Treal>(8.0, 4.0, 2.0));") << ln << STR(" ---> ") << projection << ln;

    Treal distance = ray.getDistanceToPoint(CPoint3D<Treal>(2.0, 4.0, 8.0));
    stdoutput << STR("Treal distance = ray.getDistanceToPoint(CPoint3D<Treal>(2.0, 4.0, 8.0));") << ln << STR(" ---> ") << distance << ln;

    CRay3D rotated(ray);
    rotated.rotate(CMatrix3D::rotate(CVector3D(0.0, 1.0, 0.0), CMathConstants::PI_2));
    stdoutput << STR("CRay3D rotated(ray); rotated.rotate(CMatrix3D::rotate(CVector3D(0.0, 1.0, 0.0), CMathConstants::PI_2));") << ln << STR(" ---> ") << rotated << ln;

    CRay3D transformed(ray);
    transformed.transform(CMatrix4D::rotate(CVector3D(0.0, 1.0, 0.0), CMathConstants::PI_2) * CMatrix4D::translate(2.0, 4.0, 8.0));
    stdoutput << STR("CRay3D transformed(ray); transformed.transform(CMatrix4D::rotate(CVector3D(0.0, 1.0, 0.0), CMathConstants::PI_2) * CMatrix4D::translate(2.0, 4.0, 8.0));") << ln << STR(" ---> ") << transformed << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
