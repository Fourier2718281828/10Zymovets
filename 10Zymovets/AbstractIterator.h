#ifndef _ABSTRACT_ITERATOR_
#define _ABSTRACT_ITERATOR_
//#pragma once
template <class T>
class AbstractIterator
{
public:
	AbstractIterator()			= default;
	virtual ~AbstractIterator() = default;
	virtual AbstractIterator& clone()									= 0;
	virtual void start()												= 0;
	virtual bool stop()											const	= 0;
	virtual const AbstractIterator& operator++()				const	= 0;
	virtual const AbstractIterator& operator+=(const size_t)	const	= 0;
	virtual const T& operator*()								const	= 0;
	virtual T& operator*()												= 0;
};
#endif // !_ABSTRACT_ITERATOR_