/*!
 *  \file    MConceptBoolAll.hpp Template checking conception. Checks if
 *           template arguments types can be used with all boolean operators.
 *  \brief   Template checking conception for using with all boolean operators.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.01.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template checking conception for using with all boolean operators.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Operators conception checking
    VERSION:   1.0
    CREATED:   16.01.2006 21:53:25

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
#ifndef __MCONCEPTBOOLALL_HPP__
#define __MCONCEPTBOOLALL_HPP__
/*==========================================================================*/
#include <Depth/include/concept/MRequiresConcept2.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Template checking conception class for using with all boolean operators.
/*!
    This conception checks if template argument types can  be  used  with  all
    boolean operators.
*/
template <typename T_FirstType, typename T_SecondType = T_FirstType>
class MConceptBoolAll :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

  //! Method for checking of using '==' operator.
  /*!
      \return Boolean value.
  */
  Tbool constraintsEqualOperator();
  //! Method for checking of using '!=' operator.
  /*!
      \return Boolean value.
  */
  Tbool constraintsNotEqualOperator();
  //! Method for checking of using '<' operator.
  /*!
      \return Boolean value.
  */
  Tbool constraintsLessThanOperator();
  //! Method for checking of using '>' operator.
  /*!
      \return Boolean value.
  */
  Tbool constraintsMoreThanOperator();
  //! Method for checking of using '<=' operator.
  /*!
      \return Boolean value.
  */
  Tbool constraintsLessEqualOperator();
  //! Method for checking of using '>=' operator.
  /*!
      \return Boolean value.
  */
  Tbool constraintsMoreEqualOperator();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptBoolAll();
  //! Meta-class protected destructor.
  virtual ~MConceptBoolAll();

private:
  typename NTraits::MTraitsConcept<T_FirstType>::attribute  m_X; //!< First operator value.
  typename NTraits::MTraitsConcept<T_SecondType>::attribute m_Y; //!< Second operator value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/operators/MConceptBoolAll.inl>
/*==========================================================================*/
#endif
