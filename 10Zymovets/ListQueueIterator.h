#ifndef _LIST_QUEUE_ITERATOR_
#define _LIST_QUEUE_ITERATOR_
#include "AbstractIterator.h"
#include "ListQueue.h"


template<typename T>
class ListQueue<T>::_Iterator : public AbstractIterator<T>
{
private:
	typename ListQueue<T>::Node* const		_start;
	typename mutable ListQueue<T>::Node*	_current;
public:
	_Iterator(typename ListQueue<T>::Node*);
	_Iterator(const _Iterator&);
	virtual ~_Iterator() = default;
private:
	virtual _Iterator& do_clone()									override;
	virtual void do_start()											override;
	virtual bool do_stop()									const	override;
	virtual const _Iterator& do_preincrement()				const	override;
	virtual const _Iterator& do_assign_plus(const size_t)	const 	override;//TODO iterator problems
	virtual const T& do_operator_star()						const	override;
	virtual T& do_operator_star()									override;
};

template<typename T>
inline ListQueue<T>::_Iterator::_Iterator(typename ListQueue<T>::Node* start)
	:	_start(start), _current(start)
{
	return;
}

template<typename T>
inline ListQueue<T>::_Iterator::_Iterator(typename const ListQueue<T>::_Iterator& it)
	: _start(it._start), _current(it._current)
{
	return;
}

template<typename T>
inline typename ListQueue<T>::_Iterator& ListQueue<T>::_Iterator::do_clone()
{
	return *(new _Iterator(*this));
}

template<typename T>
inline void ListQueue<T>::_Iterator::do_start()
{
	_current = _start;
	return;
}

template<typename T>
inline bool ListQueue<T>::_Iterator::do_stop() const
{
	return _current == nullptr;
}

template<typename T>
inline const typename ListQueue<T>::_Iterator& ListQueue<T>::_Iterator::do_preincrement() const
{
	_current = _current->_next;
	return *this;
}

template<typename T>
inline const typename ListQueue<T>::_Iterator& ListQueue<T>::_Iterator::do_assign_plus(const size_t i0) const
{
	size_t i = i0;
	while (i --> 0)
	{
		if (AbstractIterator<T>::stop())
		{
			throw 1;
		}
		++(*this);
	}
	return *this;
}

template<typename T>
inline const T& ListQueue<T>::_Iterator::do_operator_star() const
{
	return _current->_value;
}

template<typename T>
inline T& ListQueue<T>::_Iterator::do_operator_star()
{
	return _current->_value;
}
#endif // !_LIST_QUEUE_ITERATOR_