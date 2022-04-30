#ifndef _BAD_QUEUE_
#define _BAD_QUEUE_
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
class IQueue<T>::BadQueue
{
private:
	const std::string _message;

public:
	BadQueue(IQueue<T>::QueueProblem p)
		: _message(to_string(p))
	{
		return;
	}

	~BadQueue()
	{
		return;
	}

	inline void print_diagnosis(ostream& o) const
	{
		o << _message << '\n';
	}


private:
	inline std::string to_string(const QueueProblem) const;
};

template<typename T>
inline std::string IQueue<T>::BadQueue::to_string(const QueueProblem problem) const
{
	switch (problem)
	{
	case QueueProblem::EMPTY_QUEUE_FRONT:
		return "Empty queue has no front.";
	case QueueProblem::EMPTY_QUEUE_POP:
		return "Cannot pop from an empty queue.";
	case QueueProblem::FULL_QUEUE_PUT:
		return "Cannot put to a full queue.";
	default:
		return "The problem wasn not stated";
	}
}
#endif // !_BAD_QUEUE_