/*!
 *  \file    CSetIterator.hpp Set non constant iterator definitions. It gives
 *           ability to get and modify set items.
 *  \brief   Set non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Set non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   25.09.2006 21:16:27

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
#ifndef __CSETITERATOR_HPP__
#define __CSETITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorInsertAssociative.hpp>
#include <Depth/include/common/iterators/IIteratorMoveAssociative.hpp>
#include <Depth/include/common/iterators/IIteratorMoveBackward.hpp>
#include <Depth/include/common/iterators/IIteratorRemoveAssociative.hpp>
#include <Depth/include/containers/CSet.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Set non constant iterator class.
/*!
    Set non constant iterator represents  set  iterations  method.  With  this
    iterator you can perform looking into set items and also modify them.
*/
template <typename T_Key, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class CSetIterator :
  public NCommon::NIterators::IIterator<CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, const T_Key, CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveAssociative<CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Key, T_Key, const T_Key, CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveBackward<CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, const T_Key, CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorInsertAssociative<CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Key, T_Key, const T_Key, CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorRemoveAssociative<CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Key, T_Key, const T_Key, CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
  // Friend class: Set class (CSet).
  friend class CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>;
  // Friend class: Set constant iterator class (CSetIteratorConst).
  friend class CSetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Key TConstructibleCheckType;
  //! Type for MConceptAssociative constraint checking.
  typedef T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator> TAssociativeCheckType;
  //! Type for MConceptAssociativeConst constraint checking.
  typedef T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator> TAssociativeConstCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Key& TKeyPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_KeyBinaryPredicate TKeyPredicate2CheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TDepthCheckType;

  // Check T_Key template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TConstructibleCheckType);
  // Check T_AssociativeContainer template argument constraint to be a non constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociative, TAssociativeCheckType);
  // Check T_AssociativeContainer template argument constraint to be a constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociativeConst, TAssociativeConstCheckType);
  // Check T_KeyBinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TKeyPredicate2CheckType, TKeyPredicate2ArgumentCheckType, TKeyPredicate2ArgumentCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CSetIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator associative key type.
  typedef T_Key TKey;
  //! Iterator associative value type.
  typedef T_Key TValue;

  //! Iterator value type.
  typedef T_Key TType;
  //! Iterator return type.
  typedef const T_Key TReturn;
  //! Iterator container type.
  typedef CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TIterator;

  //! Container's key binary predicate type.
  typedef T_KeyBinaryPredicate TKeyLessThanPredicate;
  //! Base associative container type.
  typedef T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator> TAssociativeContainer;
  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CSetIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSetIterator class.
  */
  CSetIterator(const CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CSetIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CSetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CSetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator = (const CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator> operator + (const CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator> operator - (const CSetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Find iterator with given key in set.
  /*!
      \param a_crKey - Constant reference to the searching key.
      \return Iterator with given key or invalid empty iterator.
  */
  CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> operator [] (const T_Key& a_crKey) const;

  //! Set another CSetIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CSetIterator class.
  */
  void set(const CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> getBackward() const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& getContainerRef() const;
  virtual CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>* getContainerPtr() const;
  virtual const T_Key& getValueRef() const;
  virtual const T_Key* getValuePtr() const;

  // IIteratorMoveAssociative interface overriding methods.
  virtual CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> find(const T_Key& a_crKey) const;

  // IIteratorMoveBackward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  // IIteratorInsertAssociative interface overriding methods.
  virtual Tbool insert(const T_Key& a_crKey, const Tbool a_cUpdate = false);

  // IIteratorRemoveAssociative interface overriding methods.
  virtual Tbool remove();
  virtual Tbool remove(T_Key& a_rKey);

  //! Serialization load CSetIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CSetIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CSetIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CSetIterator class instances.
  /*!
      \param a_rInstance - Reference to another CSetIterator class instance.
  */
  void swap(CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance);

private:
  CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>* m_pContainer;            //!< Pointer to the iterator container.
  typename T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator>::TIterator m_Iterator; //!< Base associative container non constant iterator.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CSetIterator(CSet<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>* a_pContainer);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* ITERATOR TRAITS SPECIALIZATION DECLARATIONS                              */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: set non constant iterator's traits specialization.
template <typename T_Key, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> > :
  public MType<NContainers::NIterators::CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CSetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = true;  //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = false; //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false; //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = true;  //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = false; //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = false; //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = true;  //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CSetIterator.inl>
/*==========================================================================*/
#endif
