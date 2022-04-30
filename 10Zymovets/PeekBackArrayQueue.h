#ifndef _PEEKBACK_ARRAY_QUEUE_
#define _PEEKBACK_ARRAY_QUEUE_
#include "PeekBack.h"
#include "IQueue.h"

template<size_t Capacity, typename T>
class PeekBackArrayQueue : public IQueue<T>, virtual public PeekBack<T>
{
private:
	size_t _size;
	size_t _front;
	size_t _back;
	T _allocator[Capacity];
public:
	PeekBackArrayQueue();
	~PeekBackArrayQueue();
	PeekBackArrayQueue(const PeekBackArrayQueue&)				= delete;
	PeekBackArrayQueue& operator=(const PeekBackArrayQueue&)	= delete;
private:
			inline size_t	next_index(size_t)			const;
			inline size_t	add_indices(size_t, size_t)	const;
	virtual inline const T& do_peekback(const size_t)	const;
	virtual inline ostream& do_print(ostream&)			const	override;
	virtual inline bool		do_empty()					const	override;
	virtual inline bool		do_full()					const	override;
	virtual inline const T& do_front()					const	override;
	virtual inline size_t	do_capacity()				const	override;
	virtual inline size_t	do_size()					const	override;
	virtual inline void		do_pop()							override;
	virtual inline void		do_put(const T& value)				override;
private:
	using IQueue<T>::QueueProblem;
};

template<typename T>
class PeekBackArrayQueue<0, T>;

template<size_t Size, typename T>
inline PeekBackArrayQueue<Size, T>::PeekBackArrayQueue()
	: _size(0), _front(0), _back(-1)
{
	return;
};

template<size_t Size, typename T>
inline PeekBackArrayQueue<Size, T>::~PeekBackArrayQueue()
{
	return;
}

template<size_t Capacity, typename T>
inline size_t PeekBackArrayQueue<Capacity, T>::next_index(size_t i) const
{
	return (i + 1) % IQueue<T>::capacity();
}

template<size_t Capacity, typename T>
inline size_t PeekBackArrayQueue<Capacity, T>::add_indices(size_t i, size_t n) const
{
	return (i + n) % IQueue<T>::capacity();
}

template<size_t Capacity, typename T>
inline const T& PeekBackArrayQueue<Capacity, T>::do_peekback(const size_t i) const
{
	if (i >= IQueue<T>::size())
		throw IQueue<T>::BadQueue(QueueProblem::PEEKBACK_INDEX_OUT_OF_BOUNDS);
	return _allocator[add_indices(_front, i)];
}

template<size_t Capacity, typename T>
inline ostream& PeekBackArrayQueue<Capacity, T>::do_print(ostream& o) const
{
	o << '[';
	for (size_t i = _front; i != next_index(_back); i = next_index(i))
	{
		o << _allocator[i] << ((i == _back) ? "" : ", ");
	}
	return o << ']' << ':' << '(' << IQueue<T>::size() << '/' << IQueue<T>::capacity() << ')';
}

template<size_t Capacity, typename T>
inline bool PeekBackArrayQueue<Capacity, T>::do_empty() const
{
	return IQueue<T>::size() == 0;
}

template<size_t Capacity, typename T>
inline bool PeekBackArrayQueue<Capacity, T>::do_full() const
{
	return IQueue<T>::size() == IQueue<T>::capacity();
}

template<size_t Capacity, typename T>
inline const T& PeekBackArrayQueue<Capacity, T>::do_front() const
{
	if (IQueue<T>::empty())
		throw IQueue<T>::BadQueue(QueueProblem::EMPTY_QUEUE_FRONT);
	return _allocator[_front];
}

template<size_t Capacity, typename T>
inline size_t PeekBackArrayQueue<Capacity, T>::do_capacity() const
{
	return Capacity;
}

template<size_t Capacity, typename T>
inline size_t PeekBackArrayQueue<Capacity, T>::do_size() const
{
	return _size;
}

template<size_t Capacity, typename T>
inline void PeekBackArrayQueue<Capacity, T>::do_pop()
{
	if (IQueue<T>::empty())
		throw IQueue<T>::BadQueue(QueueProblem::EMPTY_QUEUE_POP);
	--_size;
	_front = next_index(_front);
}

template<size_t Capacity, typename T>
inline void PeekBackArrayQueue<Capacity, T>::do_put(const T& value)
{
	if (IQueue<T>::full())
		throw IQueue<T>::BadQueue(QueueProblem::FULL_QUEUE_PUT);
	++_size;
	_allocator[_back = next_index(_back)] = value;
}
#endif // !_PEEKBACK_ARRAY_QUEUE_