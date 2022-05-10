#include "ArrayQueue.h"
#include "ListQueue.h"
#include "UnboundedQueue.h"
#include "PeekBackArrayQueue.h"
#include "PeekBackListQueue.h"
#include "PeekBackUnboundedQueue.h"
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using namespace lab10;

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
void testQueues(IQueue<T>& p)
{
	cout << typeid(p).name() << endl;
	cout << "1). Putting some elements : " << endl;
	try
	{
		for (int i = 0; i < 6; ++i)
		{
			p.put(i);
			cout << p << endl;
		}
	}
	catch (const IQueue<T>::BadQueue& bq)
	{
		cout << "--Exception: ";
		bq.print_diagnosis(cout);
	}

	cout << "2). Now popping till empty (we also use front() method there):" << endl;
	try
	{
		typename IQueue<T>::Type front;
		while (!p.empty())
		{
			front = p.front();
			p.pop();
			cout << p << " --popped elem : " << front  << endl;
		}
		p.pop();
	}
	catch (const IQueue<T>::BadQueue& bq)
	{
		cout << "--Exception: ";
		bq.print_diagnosis(cout);
	}

	try
	{
		cout << "3). Now let's try to get the front() of empty queue:" << endl;
		p.front();
	}
	catch (const IQueue<T>::BadQueue& bq)
	{
		cout << "--Exception: ";
		bq.print_diagnosis(cout);
	}

	for (int i = 0; i < 5; ++i)
	{
		p.put(i);
	}

	cout << "4). Testing iterators :" << endl;
	typename IQueue<T>::Iterator& itor(p.attach());
	cout << "Our queue: " << p << endl;
	cout << "Let's modify the 3rd element using non-const iterator :" << endl;
	itor += 3;
	*itor = 10;
	cout << "*(itor += 3) = 10;" << endl;
	cout << "Result : " << p << endl;
	cout << "Don't forget to free memory: delete& itor;" << endl;
	delete& itor;

	cout << "-------------------------------------------------------------------" << endl;
}

template<typename T>
void testPeekBackQueues(IPeekBackQueue<T>& p)
{
	cout << typeid(p).name() << endl;
	for (int i = 0; i < 4; ++i) p.put(i);
	cout << "Our PeekBackQueue : " << p << endl;
	cout << "Let's peekBack all the elements :" << endl;
	for (int i = 0; i < p.size(); ++i)
	{
		cout << p.peekback(i) << ' ';
	}
	cout << endl;
	try
	{
		cout << "Let's try to peek the non-existent element:" << endl;
		cout << p.peekback(5) << endl;
	}
	catch (const IQueue<T>::BadQueue& bq)
	{
		cout << "--Exception: ";
		bq.print_diagnosis(cout);
	}
	cout << "-------------------------------------------------------------------" << endl;
}

int main(void)
{
	ArrayQueue<5, int> p1;
	ListQueue<int> p2;
	UnboundedQueue<int> p3;
	
	testQueues(p1);
	testQueues(p2);
	testQueues(p3);

	PeekBackArrayQueue<5, int> pb1;
	PeekBackListQueue<int> pb2;
	PeekBackUnboundedQueue<int> pb3;

	testPeekBackQueues(pb1);
	testPeekBackQueues(pb2);
	testPeekBackQueues(pb3);

	cout << "If we wanted to attach the iterator to a const container :" << endl;
	const ListQueue<int> lq;
	cout << "const ListQueue<int> lq;" << endl;
	ListQueue<int>::ConstIterator itor(lq.attach());
	cout << "ListQueue<int>::ConstIterator itor(lq.attach());" << endl;
	cout << "We would get the const iterator. And modification is now impossible." << endl;
	//*itor = 20;

	return 0;
}