/*!
 *  \file    MConceptAnyFunction.hpp.tpl Template checking conception. Checks
 *           if template argument is an any function with DEF_FUNCTION_ARITY
 *           arguments.
 *  \brief   Any function with DEF_FUNCTION_ARITY arguments template checking conception (template header).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Any function with DEF_FUNCTION_ARITY arguments template checking conception (template header).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Conception checking details (templates)
    VERSION:   1.0
    CREATED:   26.04.2006 02:03:32

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
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Any function template checking conception meta-class (any function with fixed DEF_FUNCTION_ARITY arguments).
/*!
    This conception helps to constrain template argument to be an any function
    with fixed DEF_FUNCTION_ARITY arguments.
*/
template <DEF_TEMPLATE_DECLARATION>
class DEF_CONCEPT_DECLARATION(MConceptAnyFunction)<DEF_TEMPLATE_PARAMETERS> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  DEF_CONCEPT_DECLARATION(MConceptAnyFunction)();
  //! Meta-class protected destructor.
  virtual ~DEF_CONCEPT_DECLARATION(MConceptAnyFunction)();
};
/*--------------------------------------------------------------------------*/
//! Any function template checking conception meta-class (any function with DEF_FUNCTION_ARITY arguments).
/*!
    This conception helps to constrain template argument to be an any function
    with DEF_FUNCTION_ARITY arguments.
*/
template <DEF_TEMPLATE_DECLARATION>
class MConceptAnyFunction<DEF_TEMPLATE_PARAMETERS> :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptAnyFunction();
  //! Meta-class protected destructor.
  virtual ~MConceptAnyFunction();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/details/templates/MConceptAnyFunction.inl.tpl>
/*==========================================================================*/
