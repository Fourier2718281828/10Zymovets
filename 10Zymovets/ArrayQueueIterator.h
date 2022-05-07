#ifndef _ARRAY_QUEUE_ITERATOR_
#define _ARRAY_QUEUE_ITERATOR_
#include "ArrayQueue.h"
#include "AbstractIterator.h"

template<size_t Size, typename T>
class ArrayQueue<Size, T>::Iterator : public AbstractIterator<T>
{
private:
	typename ArrayQueue<Size, T>&	_container;
	T *const						_start;
	mutable T*						_current;
	mutable T*						_end;
public:
			Iterator(typename ArrayQueue<Size, T>&);
			Iterator(const Iterator&);
	virtual ~Iterator()							   = default;
	virtual Iterator& clone()						override;
	virtual void start()							override;
	virtual bool stop()						const	override;
	virtual const Iterator& operator++()	const	override;
	virtual const T& operator*()			const	override;
	virtual T& operator*()							override;
};

template<size_t Size, typename T>
inline ArrayQueue<Size, T>::Iterator::Iterator(typename ArrayQueue<Size, T>& aq)
	:	
		_container	(aq), 
		_start		(&aq._allocator[0]),
		_current	(&aq._allocator[0]),
		_end		(&aq._allocator[0] + aq.size())
{
	return;
}

template<size_t Size, typename T>
inline ArrayQueue<Size, T>::Iterator::Iterator(const ArrayQueue<Size, T>::Iterator& itor)
	:	_container	(itor._container),
		_start		(itor._start),
		_current	(itor._current),
		_end		(itor._end)
{
	return;
}

template<size_t Size, typename T> inline 
typename ArrayQueue<Size, T>::Iterator& ArrayQueue<Size, T>::Iterator::clone()
{
	return *(new Iterator(*this));
}

template<size_t Size, typename T>
inline void ArrayQueue<Size, T>::Iterator::start()
{
	_current	= &_container._allocator[0];
	_end		= &_container._allocator[0] + _container.size();

	return;
}

template<size_t Size, typename T>
inline bool ArrayQueue<Size, T>::Iterator::stop() const
{
	return _current == _end;
}

template<size_t Size, typename T>
inline const typename ArrayQueue<Size, T>::Iterator& 
ArrayQueue<Size, T>::Iterator::operator++() const
{
	++_current;
	return *this;
}

template<size_t Size, typename T>
inline const T& ArrayQueue<Size, T>::Iterator::operator*() const
{
	return *_current;
}

template<size_t Size, typename T>
inline T& ArrayQueue<Size, T>::Iterator::operator*()
{
	return *_current;
}
#endif // !_ARRAY_QUEUE_ITERATOR_