#ifndef _PEEK_BACK_QUEUE
#define _PEEK_BACK_QUEUE
#include "IQueue.h"
#include "PeekBack.h"

template<typename T>
class IPeekBackQueue : virtual public IQueue<T>, public PeekBack<T>
{
public:
	IPeekBackQueue()									= default;
	virtual ~IPeekBackQueue()							= default;
	IPeekBackQueue(const IPeekBackQueue&)				= delete;
	IPeekBackQueue& operator=(const IPeekBackQueue&)	= delete;
};
#endif // !_PEEK_BACK_QUEUE

