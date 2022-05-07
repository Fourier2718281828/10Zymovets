#ifndef _UNBOUNDED_QUEUE_
#define _UNBOUNDED_QUEUE_
#include "IQueue.h"

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
class UnboundedQueue : public IQueue<T>
{
private:
	class _Iterator;
	size_t _size;
	size_t _capacity;
	size_t _front;
	size_t _back;
	T* _allocator;
	static const size_t DEFAULT_CAPACITY;
public:
	explicit UnboundedQueue(const size_t = DEFAULT_CAPACITY);
	~UnboundedQueue();
	UnboundedQueue(const UnboundedQueue&)				= delete;
	UnboundedQueue& operator=(const UnboundedQueue&)	= delete;
private:
			inline void		resize(const size_t);
			inline size_t	next_index(size_t)	const;
	virtual inline ostream& do_print(ostream&)	const	override;
	virtual inline bool		do_empty()			const	override;
	virtual inline bool		do_full()			const	override;
	virtual inline const T& do_front()			const	override;
	virtual inline size_t	do_capacity()		const	override;
	virtual inline size_t	do_size()			const	override;
	virtual inline void		do_pop()					override;
	virtual inline void		do_put(const T& value)		override;
private:
	//private inner types:
	using IQueue<T>::QueueProblem;
public:
	//inner types for users:
	using iterator = _Iterator;
};

template<typename T>
const size_t UnboundedQueue<T>::DEFAULT_CAPACITY = 0;

template<typename T>
inline UnboundedQueue<T>::UnboundedQueue(const size_t capacity)
	:	_size(0), _capacity(capacity), _front(0),
		_back(-1), _allocator(new T[capacity])
{
	return;
}

template<typename T>
inline UnboundedQueue<T>::~UnboundedQueue()
{
	delete _allocator;
	_allocator = nullptr;
	_size = _capacity = _front = _back = 0;
}

template<typename T>
inline void UnboundedQueue<T>::resize(const size_t new_capacity)
{
	T* prev = _allocator;
	_allocator = new T[new_capacity];
	if (IQueue<T>::size() == 1)
	{
		_allocator[0] = std::move(prev[_front]);
	}
	else
	{
		for (size_t i = 0, j = _front; j != _back + 1; j = next_index(j), ++i)
		{
			_allocator[i] = std::move(prev[j]);
		}
	}
	delete prev;
	prev = nullptr;
	_capacity = new_capacity;
	_front = 0;
	_back = IQueue<T>::size() - 1;

	return;
}

template<typename T>
inline size_t UnboundedQueue<T>::next_index(size_t i) const
{
	return (i < IQueue<T>::capacity()) ? (i + 1) : 0;
}

template<typename T>
inline ostream& UnboundedQueue<T>::do_print(ostream& o) const
{
	o << '[';
	for (size_t i = _front; i != next_index(_back); i = next_index(i))
	{
		o << _allocator[i] << ((i == _back) ? "" : ", ");
	}
	return o << ']' << ':' << IQueue<T>::size() << '/' << IQueue<T>::capacity();
}

template<typename T>
inline bool UnboundedQueue<T>::do_empty() const
{
	return IQueue<T>::size() == 0;
}

template<typename T>
inline bool UnboundedQueue<T>::do_full() const
{
	return IQueue<T>::size() == IQueue<T>::capacity();
}

template<typename T>
inline const T& UnboundedQueue<T>::do_front() const
{
	if (IQueue<T>::empty()) 
		throw IQueue<T>::BadQueue(QueueProblem::EMPTY_QUEUE_FRONT);
	return _allocator[_front];
}

template<typename T>
inline size_t UnboundedQueue<T>::do_capacity() const
{
	return _capacity;
}

template<typename T>
inline size_t UnboundedQueue<T>::do_size() const
{
	return _size;
}

template<typename T>
inline void UnboundedQueue<T>::do_pop()
{
	if (IQueue<T>::empty()) 
		throw IQueue<T>::BadQueue(QueueProblem::EMPTY_QUEUE_POP);
	--_size;
	_front = next_index(_front);
	if (IQueue<T>::size() <= IQueue<T>::capacity() / 4)
	{
		resize(2 * IQueue<T>::size());
	}
	return;
}

template<typename T>
inline void UnboundedQueue<T>::do_put(const T& value)
{
	if (UnboundedQueue<T>::full())
	{
		resize(2 * IQueue<T>::capacity() + 1);
	}
	++_size;
	_allocator[_back = next_index(_back)] = value;
	return;
}
#endif // !_UNBOUNDED_QUEUE_