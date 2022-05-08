#ifndef _LIST_QUEUE_ITERATOR_
#define _LIST_QUEUE_ITERATOR_
#include "AbstractIterator.h"
#include "Node.h"

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

template<bool IsConstant, typename T>
class ListQueueIterator : public AbstractIterator<IsConstant, T>
{
private:
	using AbstractIterator<IsConstant, T>::ItorProblem;
	using AbstractIterator<IsConstant, T>::BadIterator;
public:
	using cond_ref = AbstractIterator<IsConstant, T>::cond_ref;
private:
	Node<T>* const		_start;
	mutable Node<T>*	_current;
public:
	ListQueueIterator(Node<T>*);
	ListQueueIterator(const ListQueueIterator&);
	virtual ~ListQueueIterator() = default;
private:
	virtual inline ListQueueIterator& do_clone()									override;
	virtual inline void do_start()													override;
	virtual inline bool do_stop()											const	override;
	virtual inline const ListQueueIterator& do_preincrement()				const	override;
	virtual inline const ListQueueIterator& do_assign_plus(const size_t)	const 	override;
	virtual inline const T& do_operator_star()								const	override;
	virtual inline cond_ref do_operator_star()										override;

};

template<bool IsConstant, typename T>
inline ListQueueIterator<IsConstant, T>::ListQueueIterator(Node<T>* start)
	:	_start(start), _current(start)
{
	return;
}

template<bool IsConstant, typename T>
inline ListQueueIterator<IsConstant, T>::ListQueueIterator(const ListQueueIterator& it)
	: _start(it._start), _current(it._current)
{
	return;
}

template<bool IsConstant, typename T>
inline ListQueueIterator<IsConstant, T>& ListQueueIterator<IsConstant, T>::do_clone()
{
	return *(new ListQueueIterator(*this));
}

template<bool IsConstant, typename T>
inline void ListQueueIterator<IsConstant, T>::do_start()
{
	_current = _start;
	return;
}

template<bool IsConstant, typename T>
inline bool ListQueueIterator<IsConstant, T>::do_stop() const
{
	return _current == nullptr;
}

template<bool IsConstant, typename T>
inline const ListQueueIterator<IsConstant, T>& 
ListQueueIterator<IsConstant, T>::do_preincrement() const
{
	if (AbstractIterator<IsConstant, T>::stop())
	{
		throw BadIterator(ItorProblem::ITERATOR_HAS_STOPPED);
	}
	_current = _current->_next;
	return *this;
}

template<bool IsConstant, typename T>
inline const ListQueueIterator<IsConstant, T>& 
ListQueueIterator<IsConstant, T>::do_assign_plus(const size_t i0) const
{
	size_t i = i0;
	while (i --> 0)
	{
		if (AbstractIterator<IsConstant, T>::stop())
		{
			throw BadIterator(ItorProblem::ITERATOR_HAS_STOPPED);
		}
		++(*this);
	}
	return *this;
}

template<bool IsConstant, typename T>
inline const T& ListQueueIterator<IsConstant, T>::do_operator_star() const
{
	return _current->_value;
}

template<bool IsConstant, typename T>
inline typename ListQueueIterator<IsConstant, T>::cond_ref 
ListQueueIterator<IsConstant, T>::do_operator_star()
{
	return _current->_value;
}

#endif // !_LIST_QUEUE_ITERATOR_