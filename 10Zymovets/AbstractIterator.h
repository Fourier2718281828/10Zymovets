#ifndef _ABSTRACT_ITERATOR_
#define _ABSTRACT_ITERATOR_
template <class T>
class AbstractIterator
{
public:
	AbstractIterator()			= default;
	virtual ~AbstractIterator() = default;
	AbstractIterator& clone();
	void start();
	bool stop()											const;
	const AbstractIterator& operator++()				const;
	const AbstractIterator& operator+=(const size_t)	const;
	const T& operator*()								const;
	T& operator*();
private:
	virtual AbstractIterator& do_clone()									= 0;
	virtual void do_start()													= 0;
	virtual bool do_stop()											const	= 0;
	virtual const AbstractIterator& do_preincrement()				const	= 0;
	virtual const AbstractIterator& do_assign_plus(const size_t)	const	= 0;
	virtual const T& do_operator_star()								const	= 0;
	virtual T& do_operator_star()											= 0;
};

template<class T>
inline AbstractIterator<T>& AbstractIterator<T>::clone()
{
	return do_clone();
}

template<class T>
inline void AbstractIterator<T>::start()
{
	do_start();
	return;
}

template<class T>
inline bool AbstractIterator<T>::stop() const
{
	return do_stop();
}

template<class T>
inline const AbstractIterator<T>& AbstractIterator<T>::operator++() const
{
	return do_preincrement();
}
template<class T>
inline const AbstractIterator<T>& AbstractIterator<T>::operator+=(const size_t i) const
{
	return do_assign_plus(i);
}
template<class T>
inline const T& AbstractIterator<T>::operator*() const
{
	return do_operator_star();
}
template<class T>
inline T& AbstractIterator<T>::operator*()
{
	return do_operator_star();
}
#endif // !_ABSTRACT_ITERATOR_