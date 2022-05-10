#ifndef _PEEK_BACK_UNBOUNDED_QUEUE_
#define _PEEK_BACK_UNBOUNDED_QUEUE_
#include "PeekBackQueue.h"
#include "UnboundedQueue.h"

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

namespace lab10
{
	template<typename T>
	class PeekBackUnboundedQueue : public UnboundedQueue<T>, public IPeekBackQueue<T>
	{
	public:
		PeekBackUnboundedQueue() = default;
		virtual ~PeekBackUnboundedQueue() = default;
		PeekBackUnboundedQueue(const PeekBackUnboundedQueue&) = delete;
		PeekBackUnboundedQueue& operator=(const PeekBackUnboundedQueue&) = delete;
	private:
		virtual inline const T& do_peekback(const size_t) const override;
	};

	template<typename T>
	inline const T& PeekBackUnboundedQueue<T>::do_peekback(const size_t i) const
	{
		auto& itor(UnboundedQueue<T>::attach());
		const T& res(*(itor += i));
		delete& itor;
		return res;
	}
}
#endif // !_PEEK_BACK_UNBOUNDED_QUEUE_