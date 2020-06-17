#include <new>

static size_t n_allocated, n_deallocated;

template <typename T>
struct MyAllocator {
	using value_type = T;
	MyAllocator() noexcept {}
	template <typename U>
	MyAllocator(const MyAllocator<U>&) noexcept {}
	T* allocate(size_t n) {
		auto p = operator new(sizeof(T) * n);
		++n_allocated;
		return static_cast<T*>(p);
	}
	void deallocate(T* p, size_t n) {
		operator delete(p);
		++n_deallocated;
	}
};

template <typename T1, typename T2>
bool operator==(const MyAllocator<T1>&, const MyAllocator<T2>&) {
	return true;
}
template <typename T1, typename T2>
bool operator!=(const MyAllocator<T1>&, const MyAllocator<T2>&) {
	return false;
}

