template <typename T>
struct SimpleUniquePointer {
	SimpleUniquePointer() = default;
	SimpleUniquePointer(T* pointer)
		: pointer{ pointer } {
	}
	~SimpleUniquePointer() {
		if (pointer) delete pointer;
	}
	SimpleUniquePointer(const SimpleUniquePointer&) = delete;
	SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete;
	SimpleUniquePointer(SimpleUniquePointer&& other) noexcept
		: pointer{ other.pointer } {
		other.pointer = nullptr;
	}
	SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept {
		if (pointer) delete pointer;
		pointer = other.pointer;
		other.pointer = nullptr;
		return *this;
	}
	T* get() {
		return pointer;
	}
private:
	T* pointer;
};