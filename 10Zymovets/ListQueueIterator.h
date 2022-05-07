#ifndef _LIST_QUEUE_ITERATOR_
#define _LIST_QUEUE_ITERATOR_
#include "AbstractIterator.h"
#include "ListQueue.h"


template<typename T>
class ListQueue<T>::Iterator : public AbstractIterator<T>
{
private:
	typename ListQueue<T>::Node* const		_start;
	typename mutable ListQueue<T>::Node*	_current;
public:
	Iterator(typename ListQueue<T>::Node*);
	Iterator(const Iterator&);
	virtual ~Iterator() = default;
	virtual Iterator& clone()									override;
	virtual void start()										override;
	virtual bool stop()									const	override;
	virtual const Iterator& operator++()				const	override;
	virtual const Iterator& operator+=(const size_t)	const 	override;
	virtual const T& operator*()						const	override;
	virtual T& operator*()										override;
};

template<typename T>
inline ListQueue<T>::Iterator::Iterator(typename ListQueue<T>::Node* start)
	:	_start(start), _current(start)
{
	return;
}

template<typename T>
inline ListQueue<T>::Iterator::Iterator(typename const ListQueue<T>::Iterator& it)
	: _start(it._start), _current(it._current)
{
	return;
}

template<typename T>
inline typename ListQueue<T>::Iterator& ListQueue<T>::Iterator::clone()
{
	return *(new Iterator(*this));
}

template<typename T>
inline void ListQueue<T>::Iterator::start()
{
	_current = _start;
	return;
}

template<typename T>
inline bool ListQueue<T>::Iterator::stop() const
{
	return _current == nullptr;
}

template<typename T>
inline const typename ListQueue<T>::Iterator& ListQueue<T>::Iterator::operator++() const
{
	_current = _current->_next;
	return *this;
}

template<typename T>
inline const typename ListQueue<T>::Iterator& ListQueue<T>::Iterator::operator+=(const size_t i0) const
{
	size_t i = i0;
	while (i --> 0 && !stop())
	{
		++(*this);
	}
	return *this;
}

template<typename T>
inline const T& ListQueue<T>::Iterator::operator*() const
{
	return _current->_value;
}

template<typename T>
inline T& ListQueue<T>::Iterator::operator*()
{
	return _current->_value;
}
#endif // !_LIST_QUEUE_ITERATOR_