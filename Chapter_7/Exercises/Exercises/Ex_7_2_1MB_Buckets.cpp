#include <cstddef>
#include <new>
#include <cstdio>

struct LargeBucket {
	const static size_t data_size{ 1000000 };
	std::byte data[data_size];
};

struct Bucket {
	const static size_t data_size{ 4096 };
	std::byte data[data_size];
};

struct Heap {
	void* allocate(size_t bytes) {
		if (bytes > LargeBucket::data_size) throw std::bad_alloc{};
		else if (bytes > Bucket::data_size) {
			for (size_t i{}; i < n_heap_largeBuckets; i++) {
				if (!largeBucket_used[i]) {
					largeBucket_used[i] = true;
					return Largebuckets[i].data;
				}
			}
			throw std::bad_alloc{};
		}
		else {
			for (size_t i{}; i < n_heap_buckets; i++) {
				if (!bucket_used[i]) {
					bucket_used[i] = true;
					return buckets[i].data;
				}
			}
			throw std::bad_alloc{};
		}
	}
	void free(void* p) {
		for (size_t i{}; i < n_heap_buckets; i++) {
			if (buckets[i].data == p) {
				bucket_used[i] = false;
				return;
			}
		}
	}
	static const size_t n_heap_buckets{ 10 };
	static const size_t n_heap_largeBuckets{ 10 };
	LargeBucket Largebuckets[n_heap_buckets]{};
	Bucket buckets[n_heap_buckets]{};
	bool bucket_used[n_heap_buckets]{};
	bool largeBucket_used[n_heap_largeBuckets]{};
};

Heap heap;

//int main() {
//	printf("Buckets: %p\n", heap.buckets);
//	auto breakfast = new unsigned int{ 0xC0FFEE };
//	auto dinner = new unsigned int{ 0xDEADBEEF };
//	printf("Breakfast: %p 0x%x\n", breakfast, *breakfast);
//	printf("Dinner: %p 0x%x\n", dinner, *dinner);
//	delete breakfast;
//	delete dinner;
//	try {
//		while (true) {
//			new char;
//			printf("Allocated a char.\n");
//		}
//	}
//	catch (const std::bad_alloc&) {
//		printf("std::bad_alloc caught.\n");
//	}
//}
