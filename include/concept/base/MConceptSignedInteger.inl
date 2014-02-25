/*!
 *  \file    MConceptSignedInteger.inl Template checking conception. Checks if
 *           template argument is signed integer number.
 *  \brief   Signed integer number template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    15.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Signed integer number template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base types conception checking
    VERSION:   1.0
    CREATED:   15.01.2006 21:45:24

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
#ifndef __MCONCEPTSIGNEDINTEGER_INL__
#define __MCONCEPTSIGNEDINTEGER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <typename T_Type>
inline MConceptSignedInteger<T_Type>::MConceptSignedInteger() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline MConceptSignedInteger<T_Type>::~MConceptSignedInteger()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void MConceptSignedInteger<T_Type>::constraints()
{ CALL
  // Check T_Type template argument constraint to be a constructible type.
  MConstraint::requiresConcept<NClass::MConceptConstructible<T_Type> >();

  Tbool logic;

  // Check for initialize with signed integer number.
  m_X = (T_Type)0;
  // Check for assign operators.
  m_X = m_Y;
  // Check for additional assign operators.
  m_X +=  m_Y;
  m_X -=  m_Y;
  m_X *=  m_Y;
  m_X /=  m_Y;
  m_X %=  m_Y;
  m_X &=  m_Y;
  m_X |=  m_Y;
  m_X ^=  m_Y;
  m_X >>= m_Y;
  m_X <<= m_Y;
  // Check for unary operators.
  m_X = +m_Y;
  m_X = -m_Y;
  m_X = ~m_Y;
  m_X = !m_Y;
  // Check for increment/decrement operators.
  m_X = ++m_Y;
  m_X = m_Y++;
  m_X = --m_Y;
  m_X = m_Y--;
  // Check for binary operators.
  m_X = (m_X +  m_Y);
  m_X = (m_X -  m_Y);
  m_X = (m_X *  m_Y);
  m_X = (m_X /  m_Y);
  m_X = (m_X %  m_Y);
  m_X = (m_X &  m_Y);
  m_X = (m_X |  m_Y);
  m_X = (m_X ^  m_Y);
  m_X = (m_X >> m_Y);
  m_X = (m_X << m_Y);
  // Check for compare operators.
  logic = (m_X == m_Y);
  logic = (m_X != m_Y);
  logic = (m_X <  m_Y);
  logic = (m_X >  m_Y);
  logic = (m_X <= m_Y);
  logic = (m_X >= m_Y);
  // Check for logic operators.
  logic = (m_X && m_Y);
  logic = (m_X || m_Y);
}
/*--------------------------------------------------------------------------*/
inline MConceptSignedInteger<Tsint08>::MConceptSignedInteger() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptSignedInteger<Tsint08>::~MConceptSignedInteger()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptSignedInteger<Tsint08>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptSignedInteger<Tsint16>::MConceptSignedInteger() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptSignedInteger<Tsint16>::~MConceptSignedInteger()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptSignedInteger<Tsint16>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptSignedInteger<Tsint32>::MConceptSignedInteger() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptSignedInteger<Tsint32>::~MConceptSignedInteger()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptSignedInteger<Tsint32>::constraints()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptSignedInteger<Tsint64>::MConceptSignedInteger() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline MConceptSignedInteger<Tsint64>::~MConceptSignedInteger()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline void MConceptSignedInteger<Tsint64>::constraints()
{ CALL

}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif