/*!
 *  \file    CFilterUTF32.hpp UTF-32 string filter class converts given ASCII
 *           and Unicode strings into the UTF-32 equivalents.
 *  \brief   UTF-32 string filter class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: UTF-32 string filter class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream text
    VERSION:   1.0
    CREATED:   02.11.2009 02:31:32

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
#ifndef __CFILTERUTF32_HPP__
#define __CFILTERUTF32_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/IFilter.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NText {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! UTF-32 string filter.
/*!
    UTF-32 string filter class is intended to  convert  on  a  fly  ASCII  and
    Unicode strings to their UTF equivalents.
*/
class BASE_API CFilterUTF32 :
  public IFilter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CFilterUTF32 TDepthCheckType;

  // Check CFilterUTF32 class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Create disconnected filter.
  /*!
      \param a_cIsBigEndian - Is the UFT-32 (Big-Endian) encoding used (default is NConstants::CConstants::isBigEndian).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterUTF32(const Tbool a_cIsBigEndian = NConstants::CConstants::isBigEndian, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_cIsBigEndian - Is the UFT-32 (Big-Endian) encoding used (default is NConstants::CConstants::isBigEndian).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterUTF32(IReader* a_pReader, const Tbool a_cIsBigEndian = NConstants::CConstants::isBigEndian, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given writer.
  /*!
      \param a_pWriter - Pointer to the writer interface.
      \param a_cIsBigEndian - Is the UFT-32 (Big-Endian) encoding used (default is NConstants::CConstants::isBigEndian).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterUTF32(IWriter* a_pWriter, const Tbool a_cIsBigEndian = NConstants::CConstants::isBigEndian, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader & writer.
  /*!
      \param a_pReaderWriter - Pointer to the reader & writer interface.
      \param a_cIsBigEndian - Is the UFT-32 (Big-Endian) encoding used (default is NConstants::CConstants::isBigEndian).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterUTF32(IReaderWriter* a_pReaderWriter, const Tbool a_cIsBigEndian = NConstants::CConstants::isBigEndian, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given separate reader and writer.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_pWriter - Pointer to the writer interface.
      \param a_cIsBigEndian - Is the UFT-32 (Big-Endian) encoding used (default is NConstants::CConstants::isBigEndian).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterUTF32(IReader* a_pReader, IWriter* a_pWriter, const Tbool a_cIsBigEndian = NConstants::CConstants::isBigEndian, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterUTF32 class.
  */
  CFilterUTF32(const CFilterUTF32& a_crInstance);
  //! Class virtual destructor.
  virtual ~CFilterUTF32();

  //! Operator: Assign another CFilterUTF32 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterUTF32 class.
      \return Reference to the current class instance.
  */
  CFilterUTF32& operator = (const CFilterUTF32& a_crInstance);

  //! Set another CFilterUTF32 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterUTF32 class.
      \return true  - if another filter was successfully set. \n
              false - if another filter was not successfully set. \n
  */
  Tbool set(const CFilterUTF32& a_crInstance);

  //! Is the UFT-32 (Big-Endian) encoding used?
  /*!
      \return true  - if the UFT-32 (Big-Endian) encoding used. \n
              false - if the UFT-32 (Little-Endian) encoding used. \n
  */
  Tbool isBigEndian() const;

  //! Serialize CFilterUTF32 class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CFilterUTF32 class instances.
  /*!
      \param a_rInstance - Reference to another CFilterUTF32 class instance.
  */
  void swap(CFilterUTF32& a_rInstance);

protected:
  // IFilter interface overriding methods.
  virtual Tuint onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize);

private:
  Tbool m_IsBigEndian;                  //!< Is the UFT-32 (Big-Endian) encoding used?
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/text/CFilterUTF32.inl>
/*==========================================================================*/
#endif
