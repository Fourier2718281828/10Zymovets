#ifndef _PEEKBACK_ARRAY_QUEUE_
#define _PEEKBACK_ARRAY_QUEUE_
#include "PeekBackQueue.h"
#include "ArrayQueue.h"

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
	template<size_t Capacity, typename T>
	class PeekBackArrayQueue : public ArrayQueue<Capacity, T>, public IPeekBackQueue<T>
	{
	public:
		PeekBackArrayQueue() = default;
		virtual ~PeekBackArrayQueue() = default;
		PeekBackArrayQueue(const PeekBackArrayQueue&) = delete;
		PeekBackArrayQueue& operator=(const PeekBackArrayQueue&) = delete;
	private:
		virtual inline const T& do_peekback(const size_t) const override;
	};

	template<size_t Capacity, typename T>
	inline const T& PeekBackArrayQueue<Capacity, T>::do_peekback(const size_t i) const
	{
		auto& itor(ArrayQueue<Capacity, T>::attach());
		const T& res(*(itor += i));
		delete& itor;
		return res;
	}
}
#endif // !_PEEKBACK_ARRAY_QUEUE_