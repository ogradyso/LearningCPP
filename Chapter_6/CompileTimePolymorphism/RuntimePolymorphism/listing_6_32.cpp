#include <stdexcept>

template <typename T, size_t Length>
T& get(T(&arr)[Length], size_t index) {
	if (index >= Length) throw std::out_of_range{ "Out of bounds" };
	return arr[index];
}