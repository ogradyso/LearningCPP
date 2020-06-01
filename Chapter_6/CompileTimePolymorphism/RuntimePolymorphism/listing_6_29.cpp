#include <type_traits>

template<typename T>
T mean(T* values, size_t length) {
	static_assert(std::is_default_constructible<T>(),
		"Type must be default constructible.");
	static_assert(std::is_copy_constructible<T>(),
		"Type must be copy constructible.");
	static_assert(std::is_arithmetic<T>(),
		"Type must support addition and division.");
	static_assert(std::is_constructible<T>(),
		"Type must be constructible from size_t.");
}
