#ifndef _PEEKBACK_ARRAY_QUEUE_
#define _PEEKBACK_ARRAY_QUEUE_
#include "PeekBack.h"
#include "ArrayQueue.h"

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

template<size_t Capacity, typename T>
class PeekBackArrayQueue : public ArrayQueue<Capacity, T>, public PeekBack<T>
{
public:
	PeekBackArrayQueue()										= default;
	virtual ~PeekBackArrayQueue()								= default;
	PeekBackArrayQueue(const PeekBackArrayQueue&)				= delete;
	PeekBackArrayQueue& operator=(const PeekBackArrayQueue&)	= delete;
private:
	virtual inline const T& do_peekback(const size_t) const override;
};

template<size_t Capacity, typename T>
inline const T& PeekBackArrayQueue<Capacity, T>::do_peekback(const size_t i) const
{
	return *(ArrayQueue<Capacity, T>::attach() += i);
}
#endif // !_PEEKBACK_ARRAY_QUEUE_