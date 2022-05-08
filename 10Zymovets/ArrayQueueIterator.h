#ifndef _ARRAY_QUEUE_ITERATOR_
#define _ARRAY_QUEUE_ITERATOR_
#include "ArrayQueue.h"
#include "AbstractIterator.h"
#include "ListQueueIterator.h"

template<size_t Capacity, typename T>
class ArrayQueue<Capacity, T>::_Iterator : public AbstractIterator<T>
{
private:
	T *const	_start;
	T *const	_end;
	mutable T*	_current;
public:
	_Iterator(T*, T*);
	_Iterator(const _Iterator&);
	virtual ~_Iterator()	= default;
private:
	virtual _Iterator& do_clone()									override;
	virtual void do_start()											override;
	virtual bool do_stop()									const	override;
	virtual const _Iterator& do_preincrement()				const	override;
	virtual const _Iterator& do_assign_plus(const size_t)	const 	override;//TODO iterator problems
	virtual const T& do_operator_star()						const	override;
	virtual T& do_operator_star()									override;
};

template<size_t Capacity, typename T>
inline ArrayQueue<Capacity, T>::_Iterator::_Iterator(T* start, T* end)
	:	_start		(start),
		_end		(end),
		_current	(start)
{
	return;
}

template<size_t Capacity, typename T>
inline ArrayQueue<Capacity, T>::_Iterator::_Iterator(const ArrayQueue<Capacity, T>::_Iterator& itor)
	:	_start		(itor._start),
		_end		(itor._end),
		_current(itor._current)
{
	return;
}

template<size_t Capacity, typename T> inline 
typename ArrayQueue<Capacity, T>::_Iterator& ArrayQueue<Capacity, T>::_Iterator::do_clone()
{
	return *(new _Iterator(*this));
}

template<size_t Capacity, typename T>
inline void ArrayQueue<Capacity, T>::_Iterator::do_start()
{
	_current = _start;
	return;
}

template<size_t Capacity, typename T>
inline bool ArrayQueue<Capacity, T>::_Iterator::do_stop() const
{
	return false;
}

template<size_t Capacity, typename T>
inline const typename ArrayQueue<Capacity, T>::_Iterator&
ArrayQueue<Capacity, T>::_Iterator::do_preincrement() const
{
	/*const size_t tmp = next_index(*_current);
	_current = (tmp == start) ? nullptr : tmp;*/
	return *this;
}

template<size_t Capacity, typename T>
inline const typename ArrayQueue<Capacity, T>::_Iterator&
ArrayQueue<Capacity, T>::_Iterator::do_assign_plus(const size_t i) const
{
	if (_current + i > _end)
		throw 1;//TODO iterator problems
	_current += i;
	return *this;
}

template<size_t Capacity, typename T>
inline const T& ArrayQueue<Capacity, T>::_Iterator::do_operator_star() const
{
	return *_current;
}

template<size_t Capacity, typename T>
inline T& ArrayQueue<Capacity, T>::_Iterator::do_operator_star()
{
	return *_current;
}

#endif // !_ARRAY_QUEUE_ITERATOR_