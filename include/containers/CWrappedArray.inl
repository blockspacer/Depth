/*!
 *  \file    CWrappedArray.inl Template wrapped array container class.
 *           Wrapped array represents a fixed-sized random access
 *           container which is built on a existing provided items.
 *  \brief   Template wrapped array container class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Template wrapped array container class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers
    VERSION:   1.0
    CREATED:   23.04.2007 21:05:52

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
#ifndef __CWRAPPEDARRAY_INL__
#define __CWRAPPEDARRAY_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <typename T_Type>
inline CWrappedArray<T_Type>::CWrappedArray() :
  NCommon::NContainers::IContainer<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >(),
  NCommon::NContainers::IRandomConst<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >(),
  m_Size(0),
  m_pData(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedArray<T_Type>::CWrappedArray(T_Type& a_rValue) :
  NCommon::NContainers::IContainer<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >(),
  NCommon::NContainers::IRandomConst<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >(),
  m_Size(0),
  m_pData(NULL)
{ CALL
  set(a_rValue);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <Tuint t_Size>
inline CWrappedArray<T_Type>::CWrappedArray(T_Type (&a_pArray)[t_Size]) :
  NCommon::NContainers::IContainer<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >(),
  NCommon::NContainers::IRandomConst<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >(),
  m_Size(0),
  m_pData(NULL)
{ CALL
  set(a_pArray);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedArray<T_Type>::CWrappedArray(T_Type a_pBuffer[], const Tuint a_cSize) :
  NCommon::NContainers::IContainer<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >(),
  NCommon::NContainers::IRandomConst<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >(),
  m_Size(0),
  m_pData(NULL)
{ CALL
  set(a_pBuffer, a_cSize);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedArray<T_Type>::CWrappedArray(const CWrappedArray<T_Type>& a_crInstance) :
  NCommon::NContainers::IContainer<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >(),
  NCommon::NContainers::IRandomConst<CWrappedArray<T_Type>, T_Type, CWrappedArrayIterator<T_Type>, CWrappedArrayIteratorConst<T_Type> >(),
  m_Size(0),
  m_pData(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedArray<T_Type>::~CWrappedArray()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <Tuint t_Size>
inline CWrappedArray<T_Type>& CWrappedArray<T_Type>::operator = (T_Type (&a_pArray)[t_Size])
{ CALL
  set(a_pArray);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedArray<T_Type>& CWrappedArray<T_Type>::operator = (const CWrappedArray<T_Type>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type& CWrappedArray<T_Type>::operator [] (const Tsint a_cIndex)
{ CALL
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the wrapped array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type& CWrappedArray<T_Type>::operator [] (const Tuint a_cIndex)
{ CALL
  // Verify index value and the array bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the wrapped array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& CWrappedArray<T_Type>::operator [] (const Tsint a_cIndex) const
{ CALL
  // Verify index value and the array bounds.
  VERIFY(((a_cIndex >= 0) && !isEmpty() && ((Tuint)a_cIndex < m_Size)), STR("Cannot access to the wrapped array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type& CWrappedArray<T_Type>::operator [] (const Tuint a_cIndex) const
{ CALL
  // Verify index value and the array bounds.
  VERIFY((!isEmpty() && (a_cIndex < m_Size)), STR("Cannot access to the wrapped array's item with the out of bounds index."));

  return m_pData[a_cIndex];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedArray<T_Type>::operator T_Type* ()
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline CWrappedArray<T_Type>::operator const T_Type* () const
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CWrappedArray<T_Type>::set(T_Type& a_rValue)
{ CALL
  m_Size = 1;
  m_pData = NAlgorithms::NCommon::address(a_rValue);
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <Tuint t_Size>
inline Tbool CWrappedArray<T_Type>::set(T_Type (&a_pArray)[t_Size])
{ CALL
  m_Size = t_Size;
  m_pData = a_pArray;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CWrappedArray<T_Type>::set(T_Type a_pBuffer[], const Tuint a_cSize)
{ CALL
  m_Size = a_cSize;
  m_pData = a_pBuffer;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CWrappedArray<T_Type>::set(const CWrappedArray<T_Type>& a_crInstance)
{ CALL
  // Check if the given class instance is not the same to the current one.
  ASSERT((&a_crInstance != this), STR("Setting the same CWrappedArray class instance."))
  {
    return false;
  }

  m_Size = a_crInstance.m_Size;
  m_pData = a_crInstance.m_pData;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CWrappedArray<T_Type>::getFreeSize() const
{ CALL
  return (getHiCapacity() - getSize());
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CWrappedArray<T_Type>::getLoCapacity() const
{ CALL
  return 0;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CWrappedArray<T_Type>::getHiCapacity() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline T_Type* CWrappedArray<T_Type>::getBuffer()
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline const T_Type* CWrappedArray<T_Type>::getBuffer() const
{ CALL
  return m_pData;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CWrappedArray<T_Type>::clear()
{ CALL
  m_Size = 0;
  m_pData = NULL;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tbool CWrappedArray<T_Type>::isEmpty() const
{ CALL
  return ((m_Size == 0) || (m_pData == NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline Tuint CWrappedArray<T_Type>::getSize() const
{ CALL
  return m_Size;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline typename CWrappedArray<T_Type>::TIterator CWrappedArray<T_Type>::getItFirst()
{ CALL
  TIterator it_first;

  // Filling iterator inner structure.
  it_first.m_pContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline typename CWrappedArray<T_Type>::TIteratorConst CWrappedArray<T_Type>::getItFirst() const
{ CALL
  TIteratorConst it_first;

  // Filling iterator inner structure.
  it_first.m_cpContainer = this;
  it_first.m_Index = 0;
  return it_first;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline typename CWrappedArray<T_Type>::TIterator CWrappedArray<T_Type>::getItLast()
{ CALL
  TIterator it_last;

  // Filling iterator inner structure.
  it_last.m_pContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline typename CWrappedArray<T_Type>::TIteratorConst CWrappedArray<T_Type>::getItLast() const
{ CALL
  TIteratorConst it_last;

  // Filling iterator inner structure.
  it_last.m_cpContainer = this;
  it_last.m_Index = ((m_Size > 0) ? (m_Size - 1) : 0);
  return it_last;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline typename CWrappedArray<T_Type>::TIterator CWrappedArray<T_Type>::getItIndex(const Tuint a_cIndex)
{ CALL
  TIterator it_index;

  // Filling iterator inner structure.
  it_index.m_pContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline typename CWrappedArray<T_Type>::TIteratorConst CWrappedArray<T_Type>::getItIndex(const Tuint a_cIndex) const
{ CALL
  TIteratorConst it_index;

  // Filling iterator inner structure.
  it_index.m_cpContainer = this;
  it_index.m_Index = a_cIndex;
  return it_index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CWrappedArray<T_Type>::reverse()
{ CALL
  T_Type* left = m_pData;
  T_Type* right = m_pData + m_Size - 1;

  while (left < right)
    NAlgorithms::NCommon::swap(*(left++), *(right--));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CWrappedArray<T_Type>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint size = 0;

  // Load the wrapped array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CWrappedArray<T_Type>")));
    CHECK(a_rArchive.doProperty(size, STR("size")));
  CHECK(a_rArchive.body());

  // Check if the loaded wrapped array size is equal the current one.
  ASSERT((size == m_Size), STR("Cannot load CWrappedArray class instance with different size (size = %u, m_Size = %u).") COMMA size COMMA m_Size)
  {
    return false;
  }

  // Load the wrapped array content.
  if (size > 0)
  {
    CHECK(a_rArchive.doValue(m_pData, size, STR("m_pData")));
  }

  // Load the wrapped array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CWrappedArray<T_Type>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Save the wrapped array header.
  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::CWrappedArray<T_Type>")));
    CHECK(a_rArchive.doProperty(m_Size, STR("size")));
  CHECK(a_rArchive.body());

  // Save the wrapped array content.
  if (!isEmpty())
  {
    CHECK(a_rArchive.doValue(m_pData, m_Size, STR("m_pData")));
  }

  // Save the wrapped array end.
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
template <class T_Archive>
inline Tbool CWrappedArray<T_Type>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return NSerialization::serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type>
inline void CWrappedArray<T_Type>::swap(CWrappedArray<T_Type>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Size, a_rInstance.m_Size);
  NAlgorithms::NCommon::swap(m_pData, a_rInstance.m_pData);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
