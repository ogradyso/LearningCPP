#include <string>
#include <iostream>
#include <cstdint>
#include <fstream>

constexpr char pos_A{ 65 }, pos_Z{ 90 }, pos_a{ 97 }, pos_z{ 122 };
constexpr bool within_AZ(char x) { return pos_A <= x && pos_Z >= x; }
constexpr bool within_az(char x) { return pos_a <= x && pos_z >= x; }

struct AlphaHistogram {
	void ingest(const char* x);
	void print() const;
private:
	size_t counts[26]{};
};

void AlphaHistogram::ingest(const char* x) {
	size_t index{};
	while (const auto c = x[index]) {
		if (within_AZ(c)) counts[c - pos_A]++;
		else if (within_az(c)) counts[c - pos_a]++;
		index++;
	}
}

void AlphaHistogram::print() const {

	for (auto index{ pos_A }; index <= pos_Z; index++) {
		std::cout << index;
		auto n_asterisks = counts[index - pos_A];
		while (n_asterisks--) std::cout << "*";
		std::cout << std::endl;
	}
}

void printFileInfo(const char* targetFilePath, std::ios_base::openmode mode = std::ios_base::in) {
	std::ifstream file{ targetFilePath, mode };
	std::string word;
	size_t count{};
	size_t length{};
	AlphaHistogram hist;
	while (file >> word) {
		count++;
		length += word.length();
		auto as_cstr = word.c_str();
		hist.ingest(as_cstr);
	}
	double averageLength = length / count;
	std::cout << "Discovered " << count << " words.\n";
	std::cout << "Average word length: " << length/count << " words.\n";
	hist.print();
}

int main() {
	const char* myFilePath;
	myFilePath = "introspection.txt";
	printFileInfo(myFilePath);
}