#ifndef _LIST_QUEUE_
#define _LIST_QUEUE_
#include "IQueue.h"

template<typename T>
class ListQueue : public IQueue<T>
{
private:
	struct Node;
	Node*	_front;
	Node*	_back;
	size_t	_size;
public:
	ListQueue();
	~ListQueue();
	ListQueue(const ListQueue&)				= delete;
	ListQueue& operator=(const ListQueue&)	= delete;
private:
	virtual inline ostream& do_print(ostream&)	const	override;
	virtual inline bool		do_empty()			const	override;
	virtual inline bool		do_full()			const	override;
	virtual inline const T& do_front()			const	override;
	virtual inline size_t	do_capacity()		const	override;
	virtual inline size_t	do_size()			const	override;
	virtual inline void		do_pop()					override;
	virtual inline void		do_put(const T& value)		override;
private:
	using IQueue<T>::QueueProblem;
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
	Node* prev;
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
struct ListQueue<T>::Node
{
	T _value;
	Node* _next;

	Node(const T& value, Node* next) 
		: _value(value), _next(next)
	{
		return;
	}
};

template<typename T>
inline ostream& ListQueue<T>::do_print(ostream& o) const
{
	o << '[';
	Node* itor = _front;
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
		throw IQueue<T>::BadQueue(QueueProblem::EMPTY_QUEUE_POP); //TODO
	--_size;
	Node* old_front = _front;
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
		_back = _front = new Node(value, nullptr);
		return;
	}

	_back = _back->_next = new Node(value, nullptr);

	return;
}
#endif // !_LIST_QUEUE_