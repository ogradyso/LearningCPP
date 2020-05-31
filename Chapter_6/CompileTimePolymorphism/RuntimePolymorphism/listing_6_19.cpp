template<typename T>
T mean(T* values, size_t length) {
	T result{};
	for (size_t i{}; i < length; i++) {
		result += values[i];
	}
	retrun result / length;
}