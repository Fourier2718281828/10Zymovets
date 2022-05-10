#ifndef _MY_CONDITIONAL_
#define _MY_CONDITIONAL_

/*
* I've developed my analogue of std::conditional
* to prove that I don't blindly use the library's
* useful tools, but understand their inner structure
* 
* I needed "conditional" to avoid implementing const 
* iterators separately from non-const ones. Those are separate
* as types, but in code the're represented by one template.
*/
namespace lab10
{
	template<bool Condition, typename T, typename U>
	struct conditional
	{
		using _type = T;
	};

	template<typename T, typename U>
	struct conditional<false, T, U>
	{
		using _type = U;
	};

	template<bool Condition, typename T, typename U>
	using conditional_t = typename conditional<Condition, T, U>::_type;
}
#endif // !_MY_CONDITIONAL_