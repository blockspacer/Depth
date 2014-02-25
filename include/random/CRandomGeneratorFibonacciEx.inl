/*!
 *  \file    CRandomGeneratorFibonacciEx.inl Extended Knuth's lagged Fibonacci
 *           random number generator.
 *  \brief   Extended Knuth's lagged Fibonacci random number generator class (inline).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Extended Knuth's lagged Fibonacci random number generator class (inline).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 20:55:36

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
#ifndef __CRANDOMGENERATORFIBONACCIEX_INL__
#define __CRANDOMGENERATORFIBONACCIEX_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CRandomGeneratorFibonacciEx::CRandomGeneratorFibonacciEx(const Tuint a_cSeed/* = IRandomGenerator::getSystemSeed() */) :
  IRandomGenerator()
{ CALL
  setSeed(a_cSeed);
}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorFibonacciEx::CRandomGeneratorFibonacciEx(const CRandomGeneratorFibonacciEx& a_crInstance) :
  IRandomGenerator(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorFibonacciEx::~CRandomGeneratorFibonacciEx()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CRandomGeneratorFibonacciEx& CRandomGeneratorFibonacciEx::operator = (const CRandomGeneratorFibonacciEx& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CRandomGeneratorFibonacciEx::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NRandom::CRandomGeneratorFibonacciEx")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IRandomGenerator&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_j55, STR("m_j55")));
    CHECK(a_rArchive.doValue(m_k55, STR("m_k55")));
    CHECK(a_rArchive.doValue(m_s55, 55, STR("m_s55")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif