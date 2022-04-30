#include "ArrayQueue.h"
#include "ListQueue.h"
#include "UnboundedQueue.h"
#include <iostream>
using std::cout;
using std::endl;

//Can we add virtual method print to IQueue?
//Is override forbidden?
//Why not implement class BadQueue as member of abstract class? (common)
//Warning: buffer overrun while writing to _allocator


int main(void)
{
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

	UnboundedQueue<int> qq;
	try
	{
		qq.pop();
	}
	catch (const UnboundedQueue<int>::BadQueue& bq)
	{
		bq.print_diagnosis(cout);
	}

	return 0;
}