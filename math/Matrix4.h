#ifndef _gameutil_Matrix4_h
#define _gameutil_Matrix4_h


namespace gameutil 
{

template <typename T>
typename std::enable_if<std::is_number<T>::value, T>::type foo() { ... }
class {
	std::vector<T> mat(4*4);
public:


};

} // namespace

template< class T >
struct is_number : std::integral_constant<
	bool,
	std::is_same<float, typename std::remove_cv<T>::type>::value ||
	std::is_same<double, typename std::remove_cv<T>::type>::value ||
	std::is_same<long double, typename std::remove_cv<T>::type>::value ||
	std::is_same<int, typename std::remove_cv<T>::type>::value
> {};

#endif // _gameutil_Matrix4_h