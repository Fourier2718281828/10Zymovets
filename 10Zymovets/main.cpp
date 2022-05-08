#include "ArrayQueue.h"
#include "ListQueue.h"
#include "UnboundedQueue.h"
#include "PeekBackArrayQueue.h"
#include "PeekBackListQueue.h"
#include <iostream>

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
// << based on iterator?
//make Node outer class?

int main(void)
{
	PeekBackListQueue<int> pbb;
	pbb.put(1);
	pbb.put(2);
	pbb.put(3);
	pbb.put(4);

	for (int i = 0; i < pbb.size(); ++i)
		cout << pbb.peekback(i) << endl;

	auto itorr = pbb.attach();
	*itorr = 10;

	cout << pbb << endl;
	/*std::vector<int> aaa;
	ArrayQueue<5, int> aq;
	ArrayQueue<5, int>::Iterator itaq = aq.attach();
	aq.put(1);
	aq.put(2);
	aq.put(3);
	cout << *(++itaq) << endl;*/
	

	//PeekBackArrayQueue<5, int> pb;
	//pb.put(1);
	//pb.put(2);
	//pb.put(3);
	//cout << &pb.front() << endl;
	//cout << pb.peekback(1) << endl;
	//pb.pop();
	//pb.pop();
	//pb.pop();

	//pb.put(4);
	//pb.put(5);
	//pb.put(6);
	//cout << &pb.front() << endl;
	//cout << pb.peekback(1) << endl;

	return 0;
}