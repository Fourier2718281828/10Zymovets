#ifndef _QUEUE_NODE_
#define _QUEUE_NODE_

template<typename T>
struct Node
{
	T _value;
	Node* _next;

	Node(const T& value, Node* next)
		: _value(value), _next(next)
	{
		return;
	}
};
#endif // !_QUEUE_NODE_