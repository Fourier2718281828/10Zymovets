#ifndef _IQUEUE_
#define _IQUEUE_
#include <ostream>
using std::ostream;

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

template <typename T>
class IQueue
{
public:
	IQueue()								= default;
	virtual ~IQueue()						= default; //QUESTION
	IQueue(const IQueue&)					= delete;
	IQueue& operator=(const IQueue&)		= delete;
	inline ostream& print(ostream&) const;
	inline bool		empty()			const;
	inline bool		full()			const;
	inline const T&	front()			const;
	inline size_t	capacity()		const;
	inline size_t	size()			const;
	inline void		pop();
	inline void		put(const T& value);
private:
	virtual inline ostream& do_print(ostream&)	const		= 0;
	virtual inline bool		do_empty()			const		= 0;
	virtual inline bool		do_full()			const		= 0;
	virtual inline const T& do_front()			const		= 0;
	virtual inline size_t	do_capacity()		const		= 0;
	virtual inline size_t	do_size()			const		= 0;
	virtual inline void		do_pop()						= 0;
	virtual inline void		do_put(const T& value)			= 0;
public:
	class BadQueue;
protected:
	enum class QueueProblem
	{
		EMPTY_QUEUE_FRONT,
		EMPTY_QUEUE_POP,
		FULL_QUEUE_PUT,
		PEEKBACK_INDEX_OUT_OF_BOUNDS,
	};
};

template<typename T>
inline bool IQueue<T>::empty() const
{
	return do_empty();
}

template<typename T>
inline bool IQueue<T>::full() const
{
	return do_full();
}

template<typename T>
inline const T& IQueue<T>::front() const
{
	return do_front();
}

template<typename T>
inline size_t IQueue<T>::capacity() const
{
	return do_capacity();
}

template<typename T>
inline size_t IQueue<T>::size() const
{
	return do_size();
}

template<typename T>
inline void IQueue<T>::pop()
{
	do_pop();
	return;
}

template<typename T>
inline void IQueue<T>::put(const T& value)
{
	do_put(value);
	return;
}

template<typename T>
inline ostream& IQueue<T>::print(ostream& o) const
{
	return do_print(o);
}

template<typename T>
ostream& operator<<(ostream& o, const IQueue<T>& q)
{
	return q.print(o);
}
#include "BadQueue.h"
#endif // !_IQUEUE_