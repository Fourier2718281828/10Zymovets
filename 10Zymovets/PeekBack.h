#ifndef _PEEK_BACK_
#define _PEEK_BACK_
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
class PeekBack
{
public:
	PeekBack()					= default;
	virtual ~PeekBack()	= default;
	inline const T& operator[](const size_t) const;
private:
	virtual inline const T& do_peekback(const size_t) const = 0;
};

template<typename T>
inline const T& PeekBack<T>::operator[](const size_t i) const
{
	return do_peekback(i);
}
#endif // !_PEEK_BACK_