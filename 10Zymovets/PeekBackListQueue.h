#ifndef _PEEKBACK_LIST_QUEUE_
#define _PEEKBACK_LIST_QUEUE_
#include "PeekBackQueue.h"
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

namespace lab10
{
	template<typename T>
	class PeekBackListQueue : public ListQueue<T>, public IPeekBackQueue<T>
	{
	private:
		using IQueue<T>::QueueProblem;
	public:
		PeekBackListQueue() = default;
		virtual ~PeekBackListQueue() = default;
		PeekBackListQueue(const PeekBackListQueue&) = delete;
		PeekBackListQueue& operator=(const PeekBackListQueue&) = delete;
	private:
		virtual inline const T& do_peekback(const size_t) const override;
	};

	template<typename T>
	inline const T& PeekBackListQueue<T>::do_peekback(const size_t i) const
	{
		if (i >= IQueue<T>::size())
		{
			throw IQueue<T>::BadQueue(QueueProblem::PEEKBACK_INDEX_OUT_OF_BOUNDS);
		}
		auto& itor(ListQueue<T>::attach());
		const T& res(*(itor += i));
		delete& itor;
		return res;
	}
}
#endif // !_PEEKBACK_LIST_QUEUE_