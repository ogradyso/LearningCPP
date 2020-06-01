//#include <stdexcept>
//
//template<typename T>
//	requires is_copy_constructible<T>::value
//T get_copy(T* pointer) {
//	if (!pointer) throw std::runtime_error{ "Mull-pointer dereference" };
//	return *pointer;
//}