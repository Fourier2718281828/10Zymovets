#include "ArrayQueue.h"
#include "ListQueue.h"
#include "UnboundedQueue.h"
#include "PeekBackArrayQueue.h"
#include "PeekBackListQueue.h"
#include "PeekBackUnboundedQueue.h"
#include <iostream>

using std::cout;
using std::endl;

//***********************************************************
//	��������� ���� ����������� ���� �� ��������� ����� 
//	�������. ���������� ��������� ������������ �����
//	�) �� ��� ������ (�������� �����)
//	�) �� ��� ������
//	�) �� ��� ������ (���������� �����) *** (������� �����)
//	�� � ���� ���������� ����������?
//	Developed by Ruslan Zymovets (SE, group 1) on April 30
//	Version 1.0
//***********************************************************


//Const iterators?
//Make iterator exceptions
// << based on iterator?

template<typename T>
void test(IPeekBackQueue<T>& pbb)
{
	cout << "--------------------------" << endl;
	pbb.put(1);
	pbb.put(2);
	pbb.put(3);
	pbb.put(4);

	for (int i = 0; i < pbb.size(); ++i)
		cout << pbb.peekback(i) << endl;

	/*auto itorr = pbb.attach();
	*itorr = 10;*/
	cout << pbb << endl;

	try
	{
		pbb.pop();
		pbb.pop();
		pbb.pop();
		pbb.pop();
		pbb.pop();
	}
	catch (const IQueue<T>::BadQueue& er)
	{
		er.print_diagnosis(std::cerr);
	}

	pbb.put(1);
	pbb.put(2);
	pbb.put(3);
	pbb.put(4);
	pbb.pop();
	pbb.put(5);


	for (int i = 0; i < pbb.size(); ++i)
		cout << pbb.peekback(i) << endl;
	cout << "--------------------------" << endl;
}

int main(void)
{
	PeekBackArrayQueue<5, int> p1;
	PeekBackListQueue<int> p2;
	PeekBackUnboundedQueue<int> p3;

	test(p1);
	test(p2);
	test(p3);//PROBLEM HERE!!!
	

	return 0;
}