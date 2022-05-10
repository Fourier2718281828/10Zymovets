#ifndef _QUEUE_NODE_
#define _QUEUE_NODE_

/*
* Even though users might not need Node,
* but it was convenient to leave it in global scope
* to solve the problems of list iterators' construction.
* It is no bad for users.
*/

namespace lab10
{
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
}
#endif // !_QUEUE_NODE_