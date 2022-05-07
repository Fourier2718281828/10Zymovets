#include "ArrayQueue.h"
#include "ListQueue.h"
#include "UnboundedQueue.h"
#include "PeekBackArrayQueue.h"
#include "PeekBackListQueue.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

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


//Const iterators?
//Make iterator exceptions

int main(void)
{
	ArrayQueue<5, int> aq;
	ArrayQueue<5, int>::Iterator itaq = aq.attach();
	aq.put(1);
	aq.put(2);
	aq.put(3);
	cout << *(++itaq) << endl;


	PeekBackListQueue<int> pb;
	pb.put(1);
	pb.put(2);
	pb.put(3);
	cout << &pb.front() << endl;
	cout << pb.peekback(1) << endl;
	pb.pop();
	pb.pop();
	pb.pop();

	pb.put(4);
	pb.put(5);
	pb.put(6);
	cout << &pb.front() << endl;
	cout << pb.peekback(1) << endl;

	ListQueue<int> a;
	a.put(1);
	a.put(2);
	a.put(3);

	ListQueue<int>::Iterator itor = a.attach();
	/*auto itor = a.attach();
	cout << *itor << endl;
	itor += 2;
	cout << *itor << endl;*/
	/*while (!itor.stop())
	{
		cout << *itor << ',';
		++itor;
	}*/
	//PeekBackArrayQueue<2, int> pbaq;
	//PeekBackArrayQueue<2, int> pbaq2;
	////pbaq = pbaq2;
	//pbaq.put(2);
	//cout << pbaq << endl;
	//ArrayQueue<2, int> aq;
	////auto itor = ArrayQueue<2, int>::iterator;
	////itor = itor2;
	//try
	//{
	//	aq.front();
	//}
	//catch(const ArrayQueue<2,int>::BadQueue& b)
	//{
	//	b.print_diagnosis(cout);
	//}

	/*UnboundedQueue<int> uq;
	for (int i = 0; i < 20; ++i)
	{
		cout << uq << endl;
		uq.put(i);
	}
	uq.pop();
	cout << uq << endl;
	uq.put(20);
	cout << uq << endl;
	for (int i = 0; i < 20; ++i)
	{
		uq.pop();
		cout << uq << endl;
	}*/
	/*ListQueue<int> q;
	cout << q << endl;
	q.put(10);
	cout << q << endl;
	q.put(20);
	cout << q << endl;
	q.pop();
	cout << q << endl;
	q.pop();
	cout << q << endl;
	q.put(10);
	cout << q << endl;
	q.put(20);
	cout << q << endl;
	q.pop();
	cout << q << endl;
	q.pop();
	cout << q << endl;*/

	/*ArrayQueue<20, int> aq;
	cout << aq << endl;
	aq.put(10);
	cout << aq << endl;
	aq.put(20);
	cout << aq << endl;
	aq.pop();
	cout << aq << endl;
	aq.pop();
	cout << aq << endl;
	aq.put(10);
	cout << aq << endl;
	aq.put(20);
	cout << aq << endl;
	aq.pop();
	cout << aq << endl;
	aq.pop();
	cout << aq << endl;
	cout << aq << endl;
	aq.put(1);
	aq.put(2);
	aq.put(3);
	aq.put(4);
	aq.pop();
	aq.pop();
	aq.put(5);
	
	cout << aq << endl;
	cout << q << endl;*/

	/*IQueue<int>* iq = new ListQueue<int>();
	iq->put(10);
	iq->put(20);
	iq->put(30);
	delete iq;*/

	/*PeekBackArrayQueue<5, int> pbaq;
	for (int i = 0; i < 4; ++i)
	{
		pbaq.put(i);
	}
	cout << pbaq[0] << endl;
	pbaq.pop();
	cout << pbaq[0] << endl;
	pbaq.put(10);
	cout << pbaq[3] << endl;*/
	return 0;
}