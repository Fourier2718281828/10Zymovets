#ifndef _LIST_QUEUE_
#define _LIST_QUEUE_
#include "IQueue.h"
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

template<typename T>
class ListQueue : public IQueue<T>
{
private:
	using IQueue<T>::QueueProblem;
public:
	using Iterator = ListQueueIterator<false, T>;
	using ConstIterator = ListQueueIterator<true, T>;
private:
	Node<T>* _front;
	Node<T>* _back;
	size_t	 _size;
public:
	ListQueue();
	~ListQueue();
	ListQueue(const ListQueue&)				= delete;
	ListQueue& operator=(const ListQueue&)	= delete;
	inline ConstIterator attach() const;
	inline Iterator attach();
private:
	virtual inline ostream& do_print(ostream&)	const	override;
	virtual inline bool		do_empty()			const	override;
	virtual inline bool		do_full()			const	override;
	virtual inline const T& do_front()			const	override;
	virtual inline size_t	do_capacity()		const	override;
	virtual inline size_t	do_size()			const	override;
	virtual inline void		do_pop()					override;
	virtual inline void		do_put(const T& value)		override;
};

template<typename T>
inline ListQueue<T>::ListQueue()
	: _front(nullptr), _back(nullptr), _size(0)
{
	return;
}

template<typename T>
inline ListQueue<T>::~ListQueue()
{
	Node<T>* prev;
	while (_front)
	{
		prev = _front;
		_front = _front->_next;
		delete prev;
	}

	_back = nullptr;
	_size = 0;

	return;
}

template<typename T>
inline typename ListQueue<T>::ConstIterator ListQueue<T>::attach() const
{
	return ConstIterator(_front);
}

template<typename T>
inline typename ListQueue<T>::Iterator ListQueue<T>::attach()
{
	return Iterator(_front);
}

template<typename T>
inline ostream& ListQueue<T>::do_print(ostream& o) const
{
	o << '[';
	Node<T>* itor = _front;
	while (itor)
	{
		o << itor->_value;
		if (itor = itor->_next)
		{
			o << ", ";
		}
	}

	return o << ']' << ':' << IQueue<T>::size();
}

template<typename T>
inline bool ListQueue<T>::do_empty() const
{
	return _front == nullptr;
}

template<typename T>
inline bool ListQueue<T>::do_full() const
{
	return false;
}

template<typename T>
inline const T& ListQueue<T>::do_front() const
{
	if(IQueue<T>::empty())
		throw IQueue<T>::BadQueue(QueueProblem::EMPTY_QUEUE_FRONT);
	return _front->_value;
}
template<typename T>
inline size_t ListQueue<T>::do_capacity() const
{
	return -1;
}

template<typename T>
inline size_t ListQueue<T>::do_size() const
{
	return _size;
}

template<typename T>
inline void ListQueue<T>::do_pop()
{
	if (IQueue<T>::empty())
		throw IQueue<T>::BadQueue(QueueProblem::EMPTY_QUEUE_POP);
	--_size;
	Node<T>* old_front = _front;
	_front = _front->_next;
	delete old_front;
	
	return;
}

template<typename T>
inline void ListQueue<T>::do_put(const T& value)
{
	++_size;

	if (IQueue<T>::empty())
	{
		_back = _front = new Node<T>(value, nullptr);
		return;
	}

	_back = _back->_next = new Node<T>(value, nullptr);

	return;
}
#endif // !_LIST_QUEUE_