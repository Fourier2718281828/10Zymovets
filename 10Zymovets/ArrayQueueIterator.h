#ifndef _ARRAY_QUEUE_ITERATOR_
#define _ARRAY_QUEUE_ITERATOR_
#include "ArrayQueue.h"
#include "AbstractIterator.h"

template<size_t Capacity, typename T>
class ArrayQueue<Capacity, T>::Iterator : public AbstractIterator<T>
{
private:
	typename ArrayQueue<Capacity, T>&	_container;
	T *const							_start;
	mutable T*							_current;
	mutable T*							_end;
public:
	Iterator(typename ArrayQueue<Capacity, T>&);
	Iterator(const Iterator&);
	virtual ~Iterator()	= default;
	virtual Iterator& clone()									override;
	virtual void start()										override;
	virtual bool stop()									const	override;
	virtual const Iterator& operator++()				const	override;
	virtual const Iterator& operator+=(const size_t)	const 	override;
	virtual const T& operator*()						const	override;
	virtual T& operator*()										override;
};

template<size_t Capacity, typename T>
inline ArrayQueue<Capacity, T>::Iterator::Iterator(typename ArrayQueue<Capacity, T>& aq)
	:	
		_container	(aq), 
		_start		(&aq._allocator[0]),
		_current	(&aq._allocator[0]),
		_end		(&aq._allocator[0] + aq.size())
{
	return;
}

template<size_t Capacity, typename T>
inline ArrayQueue<Capacity, T>::Iterator::Iterator(const ArrayQueue<Capacity, T>::Iterator& itor)
	:	_container	(itor._container),
		_start		(itor._start),
		_current	(itor._current),
		_end		(itor._end)
{
	return;
}

template<size_t Capacity, typename T> inline 
typename ArrayQueue<Capacity, T>::Iterator& ArrayQueue<Capacity, T>::Iterator::clone()
{
	return *(new Iterator(*this));
}

template<size_t Capacity, typename T>
inline void ArrayQueue<Capacity, T>::Iterator::start()
{
	_current	= &_container._allocator[0];
	_end		= &_container._allocator[0] + _container.size();

	return;
}

template<size_t Capacity, typename T>
inline bool ArrayQueue<Capacity, T>::Iterator::stop() const
{
	return _current == _end;
}

template<size_t Capacity, typename T>
inline const typename ArrayQueue<Capacity, T>::Iterator& 
ArrayQueue<Capacity, T>::Iterator::operator++() const
{
	++_current;
	return *this;
}

template<size_t Capacity, typename T>
inline const typename ArrayQueue<Capacity, T>::Iterator&
ArrayQueue<Capacity, T>::Iterator::operator+=(const size_t i) const
{
	_current = (_current + i >= _end) ? _end : _current + i;
	return *this;
}

template<size_t Capacity, typename T>
inline const T& ArrayQueue<Capacity, T>::Iterator::operator*() const
{
	return *_current;
}

template<size_t Capacity, typename T>
inline T& ArrayQueue<Capacity, T>::Iterator::operator*()
{
	return *_current;
}

#endif // !_ARRAY_QUEUE_ITERATOR_