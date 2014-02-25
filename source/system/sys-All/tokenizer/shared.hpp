/*!
 *  \file    shared.hpp Depth tokenizer shared library implementation header
 *           contains valid SHARED_LIBRARY_CLASS and include definitions.
 *  \brief   Depth tokenizer shared library implementation header.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.04.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Depth tokenizer shared library implementation header.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   20.04.2009 02:42:54

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
#ifndef __SHARED_HPP__
#define __SHARED_HPP__
/*==========================================================================*/
#include <Depth/include/tokenizer.hpp>
/*==========================================================================*/
// Define the name of the shared library.
#define SHARED_LIBRARY_NAME DepthTokenizer
// Define full class name of the shared library (including namespace).
#define SHARED_LIBRARY_CLASS NDepth::NSystem::CSystemTokenizer
// Include the header file of the shared library.
#include <Depth/include/system/CSystemTokenizer.hpp>
/*==========================================================================*/
#endif