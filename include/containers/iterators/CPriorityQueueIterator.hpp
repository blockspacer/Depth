/*!
 *  \file    CPriorityQueueIterator.hpp Priority queue non constant iterator
 *           definitions. It gives ability to get and modify priority queue
 *           items.
 *  \brief   Priority queue non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    07.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Priority queue non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   07.05.2007 23:37:23

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
#ifndef __CPRIORITYQUEUEITERATOR_HPP__
#define __CPRIORITYQUEUEITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorInsertAssociative.hpp>
#include <Depth/include/common/iterators/IIteratorMoveBackward.hpp>
#include <Depth/include/common/iterators/IIteratorRemoveAssociative.hpp>
#include <Depth/include/containers/CPriorityQueue.hpp>
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
//! Priority queue non constant iterator class.
/*!
    Priority queue non constant iterator represents priority queue  iterations
    method. With this iterator you can perform  looking  into  priority  queue
    items and also modify them.
*/
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class CPriorityQueueIterator :
  public NCommon::NIterators::IIterator<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveBackward<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorInsertAssociative<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Priority, T_Type, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorRemoveAssociative<CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Priority, T_Type, NUtility::CPair<T_Type, T_Priority>, T_Type, CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
  // Friend class: Priority queue class (CPriorityQueue).
  friend class CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>;
  // Friend class: Priority queue constant iterator class (CPriorityQueueIteratorConst).
  friend class CPriorityQueueIteratorConst<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>;

  //! Type for MConceptConstructible constraint checking.
  typedef T_Type TTypeConstructibleCheckType;
  //! Type for MConceptConstructible constraint checking.
  typedef T_Priority TPriorityConstructibleCheckType;
  //! Type for MConceptAssociative constraint checking.
  typedef T_AssociativeContainer<NUtility::CPair<T_Type, T_Priority>, NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>, T_Allocator> TAssociativeCheckType;
  //! Type for MConceptAssociativeConst constraint checking.
  typedef T_AssociativeContainer<NUtility::CPair<T_Type, T_Priority>, NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>, T_Allocator> TAssociativeConstCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Priority& TPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_BinaryPredicate TPredicate2CheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TDepthCheckType;

  // Check T_Type template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TTypeConstructibleCheckType);
  // Check T_Priority template argument constraint to be a constructible type.
  REQUIRES_CONCEPT1(NConcept::NClass, MConceptConstructible, TPriorityConstructibleCheckType);
  // Check T_AssociativeContainer template argument constraint to be a non constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociative, TAssociativeCheckType);
  // Check T_AssociativeContainer template argument constraint to be a constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociativeConst, TAssociativeConstCheckType);
  // Check T_BinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TPredicate2CheckType, TPredicate2ArgumentCheckType, TPredicate2ArgumentCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CPriorityQueueIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator associative key type.
  typedef T_Priority TKey;
  //! Iterator associative value type.
  typedef T_Type TValue;

  //! Iterator value type.
  typedef NUtility::CPair<T_Type, T_Priority> TType;
  //! Iterator return type.
  typedef T_Type TReturn;
  //! Iterator container type.
  typedef CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> TIterator;

  //! Container binary predicate type.
  typedef T_BinaryPredicate TLessThanPredicate;
  //! Base associative container type.
  typedef T_AssociativeContainer<NUtility::CPair<T_Type, T_Priority>, NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>, T_Allocator> TAssociativeContainer;
  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CPriorityQueueIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPriorityQueueIterator class.
  */
  CPriorityQueueIterator(const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CPriorityQueueIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, typename T_OtherPriority, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CPriorityQueueIteratorConst<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, typename T_OtherPriority, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CPriorityQueueIteratorConst<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType, typename T_OtherPriority, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, typename T_OtherPriority, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CPriorityQueueIteratorConst<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, typename T_OtherPriority, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CPriorityQueueIteratorConst<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType, typename T_OtherPriority, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator = (const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, typename T_OtherPriority, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator> operator + (const CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType, typename T_OtherPriority, typename T_OtherBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator> operator - (const CPriorityQueueIterator<T_OtherType, T_OtherPriority, T_OtherBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Set another CPriorityQueueIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CPriorityQueueIterator class.
  */
  void set(const CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method uses 'stepForward()' iterator method to get  a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method uses 'stepBackward()' iterator method to get a backward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> getBackward() const;

  //! Get constant reference to the iterator priority value.
  /*!
      Method returns constant reference to the iterator priority  value.  Note
      that result may be  broken  if  iterator  is  not  initialized.  So  use
      'isValid()' method before to check its valid state.

      \return Constant reference to the iterator priority value.
  */
  virtual const T_Priority& getPriorityRef() const;
  //! Get constant pointer to the iterator priority value.
  /*!
      Method returns constant pointer to the  iterator  priority  value.  Note
      that result  may  be  NULL  if  iterator  is  not  initialized.  So  use
      'isValid()' method before to check its valid state or use NULL  checking
      strategy to define iterator is not initialized state alternatively.

      \return Constant pointer to the iterator priority value.
  */
  virtual const T_Priority* getPriorityPtr() const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& getContainerRef() const;
  virtual CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>* getContainerPtr() const;
  virtual T_Type& getValueRef() const;
  virtual T_Type* getValuePtr() const;

  // IIteratorMoveBackward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  // IIteratorInsertAssociative interface overriding methods.
  virtual Tbool insert(const T_Type& a_crItem, const T_Priority& a_crPriority = T_Priority(), const Tbool a_cUpdate = false);
  virtual Tbool insert(const NUtility::CPair<T_Type, T_Priority>& a_crValuePriorityPair, const Tbool a_cUpdate = false);

  // IIteratorRemoveAssociative interface overriding methods.
  virtual Tbool remove();
  virtual Tbool remove(T_Type& a_rItem);
  virtual Tbool remove(T_Type& a_rItem, T_Priority& a_rPriority);
  virtual Tbool remove(NUtility::CPair<T_Type, T_Priority>& a_rValuePriorityPair);

  //! Serialization load CPriorityQueueIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CPriorityQueueIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CPriorityQueueIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CPriorityQueueIterator class instances.
  /*!
      \param a_rInstance - Reference to another CPriorityQueueIterator class instance.
  */
  void swap(CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance);

private:
  CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>* m_pContainer;                                                                                     //!< Pointer to the iterator container.
  typename T_AssociativeContainer<NUtility::CPair<T_Type, T_Priority>, NAlgorithms::NFunctions::FPriorityComparator<T_Type, T_Priority, T_BinaryPredicate>, T_Allocator>::TIterator m_Iterator; //!< Base associative container non constant iterator.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CPriorityQueueIterator(CPriorityQueue<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>* a_pContainer);

  //! Get non constant reference to the priority queue iterator key/value pair.
  /*!
      Method returns non constant reference  to  the  priority queue  iterator  key/value
      pair. This method is unsafe and only for internal usage.

      \return Non constant reference to the priority queue iterator key/value pair.
  */
  NUtility::CPair<T_Type, T_Priority>& getPairRef() const;
  //! Get non constant pointer to the priority queue iterator key/value pair.
  /*!
      Method returns non constant pointer to the priority queue iterator key/value  pair.
      This method is unsafe and only for internal usage.

      \return Non constant pointer to the priority queue iterator key/value pair.
  */
  NUtility::CPair<T_Type, T_Priority>* getPairPtr() const;
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
//! Traits meta-class: priority queue non constant iterator's traits specialization.
template <typename T_Type, typename T_Priority, typename T_BinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> > :
  public MType<NContainers::NIterators::CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CPriorityQueueIterator<T_Type, T_Priority, T_BinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = false; //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = false; //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false; //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = true;  //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = true;  //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = true;  //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/containers/iterators/CPriorityQueueIterator.inl>
/*==========================================================================*/
#endif
