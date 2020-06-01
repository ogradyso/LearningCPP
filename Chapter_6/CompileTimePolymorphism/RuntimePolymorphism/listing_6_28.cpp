//#include <stdexcept>
//#include <type_traits>
//#include <cstdlib>
//
//template<typename T>
//	requires std::is_copy_constructible<T>::value
//T get_copy(T* pointer) {
//	if (!pointer) throw std::runtime_error{ "Mull-pointer dereference" };
//	return *pointer;
//}
//
//struct Highlander {
//	Highlander() = default;
//	Highlander(const Highlander&) = delete;
//};
//
//int main() {
//	Highlander conner;
//	auto connor_ptr = &connor;
//	auto connor_copy = get_copy(connor_ptr);
//}