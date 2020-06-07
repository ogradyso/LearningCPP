#pragma once

struct PrimeNumberIterator {
	bool operator!=(int x) const {
		return x >= current;
	}
	PrimeNumberIterator& operator++() {
		current += 2;
		for (long divisor{ 2 }; divisor < current; divisor++) {
			if (current % divisor == 0) {
				current += 2;
			}
		}
		return *this;
	}
	int operator*() const {
		return current;
	}
private:
	int current{ 1 };
};

struct PrimeNumberRange {
	explicit PrimeNumberRange(int max) : max{ max } {}
	PrimeNumberIterator begin() const {
		return PrimeNumberIterator{};
	}
	int end() const {
		return max;
	}
private:
	const int max;
};