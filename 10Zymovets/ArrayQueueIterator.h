#ifndef _ARRAY_QUEUE_ITERATOR_
#define _ARRAY_QUEUE_ITERATOR_
#include "ArrayQueue.h"
#include "AbstractIterator.h"
#include "ListQueueIterator.h"

//***********************************************************
//	Визначити клас абстрактних черг за наведеним нижче 
//	зразком. Побудувати реалізації абстрактного класу
//	а) на базі масиву (обмежена черга)
//	б) на базі списку
//	в) на базі масиву (необмежена черга) *** (бонусна опція)
//	Як в черзі улаштувати підглядання?
//	Developed by Ruslan Zymovets (SE, group 1) on April 30
//	Version 1.0
//***********************************************************

//template<size_t Capacity, typename T>
//class ArrayQueue<Capacity, T>::_Iterator : public AbstractIterator<T>
//{
//private:
//	T *const	_array_begining;
//	T *const	_start;
//	T *const	_end;
//	mutable T*	_current;
//public:
//	_Iterator(T *const, T *const, T *const);
//	_Iterator(const _Iterator&);
//	virtual ~_Iterator()	= default;
//private:
//	virtual inline _Iterator& do_clone()									override;
//	virtual inline void do_start()											override;
//	virtual inline bool do_stop()									const	override;
//	virtual inline const _Iterator& do_preincrement()				const	override;
//	virtual inline const _Iterator& do_assign_plus(const size_t)	const 	override;//TODO iterator problems
//	virtual inline const T& do_operator_star()						const	override;
//	virtual inline T& do_operator_star()									override;
//private:
//	inline T* const step_forward(T* const, const size_t) const;
//private:
//	using AbstractIterator<IsConstant, T>::ItorProblem;
//	using AbstractIterator<IsConstant, T>::BadIterator;
//};
//
//template<size_t Capacity, typename T>
//inline ArrayQueue<Capacity, T>::_Iterator::_Iterator(T* const array_beginning, T *const start, T *const end)
//	:	_array_begining	(array_beginning),
//		_start			(start),
//		_end			(end),
//		_current		(start)
//{
//	return;
//}
//
//template<size_t Capacity, typename T>
//inline ArrayQueue<Capacity, T>::_Iterator::_Iterator(const ArrayQueue<Capacity, T>::_Iterator& itor)
//	:	_array_begining	(itor._array_begining),
//		_start			(itor._start),
//		_end			(itor._end),
//		_current		(itor._current)
//{
//	return;
//}
//
//template<size_t Capacity, typename T> inline 
//typename ArrayQueue<Capacity, T>::_Iterator& ArrayQueue<Capacity, T>::_Iterator::do_clone()
//{
//	return *(new _Iterator(*this));
//}
//
//template<size_t Capacity, typename T>
//inline void ArrayQueue<Capacity, T>::_Iterator::do_start()
//{
//	_current = _start;
//	return;
//}
//
//template<size_t Capacity, typename T>
//inline bool ArrayQueue<Capacity, T>::_Iterator::do_stop() const
//{
//	return nullptr == _current;
//}
//
//template<size_t Capacity, typename T>
//inline const typename ArrayQueue<Capacity, T>::_Iterator&
//ArrayQueue<Capacity, T>::_Iterator::do_preincrement() const
//{
//	return do_assign_plus(1);
//}
//
//template<size_t Capacity, typename T>
//inline const typename ArrayQueue<Capacity, T>::_Iterator&
//ArrayQueue<Capacity, T>::_Iterator::do_assign_plus(const size_t i) const
//{
//	_current = step_forward(_current, i);
//
//	if (nullptr == _current)
//	{
//		throw BadIterator(ItorProblem::ITERATOR_HAS_STOPPED);
//	}
//
//	return *this;
//}
//
//template<size_t Capacity, typename T>
//inline const T& ArrayQueue<Capacity, T>::_Iterator::do_operator_star() const
//{
//	return *_current;
//}
//
//template<size_t Capacity, typename T>
//inline T& ArrayQueue<Capacity, T>::_Iterator::do_operator_star()
//{
//	return *_current;
//}
//
//template<size_t Capacity, typename T>
//inline T* const ArrayQueue<Capacity, T>::_Iterator::step_forward(T* const curr, const size_t steps) const
//{
//	size_t curr_index = (curr >= _start)	
//						? curr - _start 
//						: Capacity - (_end - curr);
//
//	if (curr_index > Capacity)
//	{
//		throw BadIterator(ItorProblem::POINTER_OUT_OF_BOUNDS);
//	}
//
//	return	curr_index == Capacity
//		? nullptr
//		: _array_begining + (curr_index + steps) % Capacity;
//
//}

#endif // !_ARRAY_QUEUE_ITERATOR_