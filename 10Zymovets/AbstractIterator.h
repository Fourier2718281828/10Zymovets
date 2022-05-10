#ifndef _ABSTRACT_ITERATOR_
#define _ABSTRACT_ITERATOR_
#include "Conditional.h"
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

namespace lab10
{
	template <bool IsConstant, class T>
	class AbstractIterator
	{
	public:
		//cond_ref becomes const T& if IsConstant = true; T& - otherwise
		using cond_ref = conditional_t<IsConstant, const T&, T&>;
		class BadIterator;
	public:
		AbstractIterator()			= default;
		virtual ~AbstractIterator() = default;
		inline AbstractIterator& clone();
		inline void start();
		inline bool stop()										const;
		inline const AbstractIterator& operator++()				const;
		inline const AbstractIterator& operator+=(const size_t)	const;
		inline const T& operator*()								const;
		inline cond_ref operator*();
	private:
		virtual inline AbstractIterator& do_clone() = 0;
		virtual inline void do_start() = 0;
		virtual inline bool do_stop()											const = 0;
		virtual inline const AbstractIterator& do_preincrement()				const = 0;
		virtual inline const AbstractIterator& do_assign_plus(const size_t)		const = 0;
		virtual inline const T& do_operator_star()								const = 0;
		virtual inline cond_ref do_operator_star() = 0;
	protected:
		enum class ItorProblem
		{
			CONTAINER_MODIFIED,
			ITERATOR_HAS_STOPPED,
		};
	};

	template <bool IsConstant, class T>
	inline AbstractIterator<IsConstant, T>& AbstractIterator<IsConstant, T>::clone()
	{
		return do_clone();
	}

	template <bool IsConstant, class T>
	inline void AbstractIterator<IsConstant, T>::start()
	{
		do_start();
		return;
	}

	template <bool IsConstant, class T>
	inline bool AbstractIterator<IsConstant, T>::stop() const
	{
		return do_stop();
	}

	template <bool IsConstant, class T>
	inline const AbstractIterator<IsConstant, T>& AbstractIterator<IsConstant, T>::operator++() const
	{
		return do_preincrement();
	}

	template <bool IsConstant, class T>
	inline const AbstractIterator<IsConstant, T>& AbstractIterator<IsConstant, T>::operator+=(const size_t i) const
	{
		return do_assign_plus(i);
	}
	template <bool IsConstant, class T>
	inline const T& AbstractIterator<IsConstant, T>::operator*() const
	{
		return do_operator_star();
	}
	template <bool IsConstant, class T>
	inline typename AbstractIterator<IsConstant, T>::cond_ref
		AbstractIterator<IsConstant, T>::operator*()
	{
		return do_operator_star();
	}

	template <bool IsConstant, class T>
	class AbstractIterator<IsConstant, T>::BadIterator
	{
	private:
		const std::string _message;

	public:
		BadIterator(const ItorProblem p)
			: _message(to_string(p))
		{
			return;
		}

		~BadIterator()
		{
			return;
		}

		inline void print_diagnosis(ostream& o) const
		{
			o << _message << '\n';
		}
	private:
		inline std::string to_string(const ItorProblem) const;
	};

	template <bool IsConstant, class T>
	inline std::string AbstractIterator<IsConstant, T>::BadIterator::to_string(const ItorProblem problem) const
	{
		switch (problem)
		{
		case ItorProblem::CONTAINER_MODIFIED:
			return "Contaiter's modification during iteration.";
		case ItorProblem::ITERATOR_HAS_STOPPED:
			return "Iteration via expired iterator.";
		default:
			return "The problem was not stated";
		}
	}
}
#endif // !_ABSTRACT_ITERATOR_