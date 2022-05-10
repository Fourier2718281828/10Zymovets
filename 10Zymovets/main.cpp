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
void test(IPeekBackQueue<T>& pbb)
{

	cout << "--------------------------" << endl;
	pbb.put(1);
	cout << pbb << endl;
	pbb.put(2);
	cout << pbb << endl;
	pbb.put(3);
	cout << pbb << endl;
	pbb.put(4);
	cout << pbb << endl;

	for (int i = 0; i < pbb.size(); ++i)
		cout << pbb.peekback(i) << endl;

	/*auto itorr = pbb.attach();
	*itorr = 10;*/
	cout << pbb << endl;

	try
	{
		pbb.pop();
		cout << pbb << endl;
		pbb.pop();
		cout << pbb << endl;
		pbb.pop();
		cout << pbb << endl;
		pbb.pop();
		cout << pbb << endl;
		pbb.pop();
		cout << pbb << endl;
	}
	catch (const IQueue<T>::BadQueue& er)
	{
		er.print_diagnosis(std::cerr);
	}

	pbb.put(1);
	cout << pbb << endl;
	pbb.put(2);
	cout << pbb << endl;
	pbb.put(3);
	cout << pbb << endl;
	pbb.put(4);
	cout << pbb << endl;
	pbb.pop();
	cout << pbb << endl;
	pbb.put(5);
	cout << pbb << endl;


	for (int i = 0; i < pbb.size(); ++i)
		cout << pbb.peekback(i) << endl;
	cout << pbb << endl;
	cout << "--------------------------" << endl;
}

int main(void)
{
	PeekBackArrayQueue<5, int> p1;
	PeekBackListQueue<int> p2;
	PeekBackUnboundedQueue<int> p3;//PROBLEM HERE (iTERATOR WRONG)
	/*pbb.put(1);
	pbb.put(2);
	pbb.put(3);
	pbb.put(4);
	pbb.pop();
	pbb.pop();
	pbb.pop();
	pbb.pop();
	pbb.put(1);
	pbb.put(2);
	pbb.put(3);
	pbb.put(4);
	pbb.pop();
	pbb.put(5);*/

	
	test(p1);
	test(p2);
	test(p3);//PROBLEM HERE!!!
	
	ArrayQueue<2, int> a;
	ArrayQueue<2, int>::Iterator& itor(a.attach());
	IQueue<int>::Iterator & it_ref = itor;
	delete& itor;

	return 0;
}