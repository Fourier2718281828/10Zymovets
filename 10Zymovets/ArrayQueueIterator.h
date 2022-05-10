#ifndef _ARRAY_QUEUE_ITERATOR_
#define _ARRAY_QUEUE_ITERATOR_
#include "ArrayQueue.h"
#include "AbstractIterator.h"

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
	template<bool IsConstant, typename T>
	class ArrayQueueIterator : public AbstractIterator<IsConstant, T>
	{
	private:
		using AbstractIterator<IsConstant, T>::ItorProblem;
		using AbstractIterator<IsConstant, T>::BadIterator;
	public:
		using cond_ref = conditional_t<IsConstant, const T&, T&>;
		using cond_ptr = conditional_t<IsConstant, const T*, T*>;
		using cond_const_ptr = conditional_t<IsConstant, const T* const, T* const>;
	private:
		cond_const_ptr		_array_begining;
		cond_const_ptr		_start;
		cond_const_ptr		_end;
		mutable cond_ptr	_current;
		const size_t		_capacity;
	public:
		ArrayQueueIterator(cond_const_ptr, cond_const_ptr, cond_const_ptr, const size_t capacity);
		ArrayQueueIterator(const ArrayQueueIterator&);
		virtual ~ArrayQueueIterator() = default;
	private:
		virtual inline ArrayQueueIterator& do_clone()									override;
		virtual inline void do_start()													override;
		virtual inline bool do_stop()											const	override;
		virtual inline const ArrayQueueIterator& do_preincrement()				const	override;
		virtual inline const ArrayQueueIterator& do_assign_plus(const size_t)	const 	override;
		virtual inline const T& do_operator_star()								const	override;
		virtual inline cond_ref do_operator_star()										override;
	private:
		inline cond_const_ptr step_forward(cond_const_ptr, const size_t) const;
	};

	template<bool IsConstant, typename T>
	inline ArrayQueueIterator<IsConstant, T>::ArrayQueueIterator
	(
		ArrayQueueIterator<IsConstant, T>::cond_const_ptr array_beginning,
		ArrayQueueIterator<IsConstant, T>::cond_const_ptr start,
		ArrayQueueIterator<IsConstant, T>::cond_const_ptr end,
		const size_t capacity
	)
		: _array_begining(array_beginning),
		_start(start),
		_end(end),
		_current(start),
		_capacity(capacity)
	{
		return;
	}

	template<bool IsConstant, typename T>
	inline ArrayQueueIterator<IsConstant, T>::ArrayQueueIterator(const ArrayQueueIterator& itor)
		: _array_begining(itor._array_begining),
		_start(itor._start),
		_end(itor._end),
		_current(itor._current),
		_capacity(itor._capacity)
	{
		return;
	}

	template<bool IsConstant, typename T> inline
		typename ArrayQueueIterator<IsConstant, T>& ArrayQueueIterator<IsConstant, T>::do_clone()
	{
		return *(new ArrayQueueIterator(*this));
	}

	template<bool IsConstant, typename T>
	inline void ArrayQueueIterator<IsConstant, T>::do_start()
	{
		_current = _start;
		return;
	}

	template<bool IsConstant, typename T>
	inline bool ArrayQueueIterator<IsConstant, T>::do_stop() const
	{
		return nullptr == _current;
	}

	template<bool IsConstant, typename T>
	inline const typename ArrayQueueIterator<IsConstant, T>&
		ArrayQueueIterator<IsConstant, T>::do_preincrement() const
	{
		return do_assign_plus(1);
	}

	template<bool IsConstant, typename T>
	inline const typename ArrayQueueIterator<IsConstant, T>&
		ArrayQueueIterator<IsConstant, T>::do_assign_plus(const size_t i) const
	{
		_current = step_forward(_current, i);

		if (nullptr == _current)
		{
			throw BadIterator(ItorProblem::ITERATOR_HAS_STOPPED);
		}

		return *this;
	}

	template<bool IsConstant, typename T>
	inline const T& ArrayQueueIterator<IsConstant, T>::do_operator_star() const
	{
		return *_current;
	}

	template<bool IsConstant, typename T>
	inline typename ArrayQueueIterator<IsConstant, T>::cond_ref
		ArrayQueueIterator<IsConstant, T>::do_operator_star()
	{
		return *_current;
	}

	template<bool IsConstant, typename T>
	inline typename ArrayQueueIterator<IsConstant, T>::cond_const_ptr
		ArrayQueueIterator<IsConstant, T>::step_forward
		(
			ArrayQueueIterator<IsConstant, T>::cond_const_ptr curr,
			const size_t steps
		)	const
	{
		size_t curr_index = (curr >= _start)
			? curr - _start
			: _capacity - (_end - curr);

		if (curr_index > _capacity)
		{
			throw BadIterator(ItorProblem::POINTER_OUT_OF_BOUNDS);
		}

		return	curr_index == _capacity
			? nullptr
			: _array_begining + (curr_index + steps) % _capacity;

	}
}
#endif // !_ARRAY_QUEUE_ITERATOR_