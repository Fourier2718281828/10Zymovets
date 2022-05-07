#ifndef _PEEKBACK_LIST_QUEUE_
#define _PEEKBACK_LIST_QUEUE_

#include "PeekBack.h"
#include "ListQueue.h"

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

template<typename T>
class PeekBackListQueue : public ListQueue<T>, public PeekBack<T>
{
public:
	PeekBackListQueue()										= default;
	virtual ~PeekBackListQueue()							= default;
	PeekBackListQueue(const PeekBackListQueue&)				= delete;
	PeekBackListQueue& operator=(const PeekBackListQueue&)	= delete;
private:
	virtual inline const T& do_peekback(const size_t) const override;
};

template<typename T>
inline const T& PeekBackListQueue<T>::do_peekback(const size_t i) const
{
	return *(ListQueue<T>::attach() += i);
}

#endif // !_PEEKBACK_LIST_QUEUE_
