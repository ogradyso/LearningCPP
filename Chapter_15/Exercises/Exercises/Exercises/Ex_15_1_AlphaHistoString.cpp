//#define CATCH_CONFIG_MAIN
//#include "catch.h"
//
//#include <cstdio>
//#include <cstdint>
//#include <string>
//
//
//constexpr char pos_A{ 65 }, pos_Z{ 90 }, pos_a{ 97 }, pos_z{ 122 };
//constexpr bool within_AZ(char x) { return pos_A <= x && pos_Z >= x; }
//constexpr bool within_az(char x) { return pos_a <= x && pos_z >= x; }
//
//struct AlphaHistogram {
//	void ingest(char x);
//	void print() const;
//private:
//	size_t counts[26]{};
//};
//
//void AlphaHistogram::ingest(char x) {
//	size_t index{};
//		if (within_AZ(x)) counts[x - pos_A]++;
//		else if (within_az(x)) counts[x - pos_a]++;
//		index++;
//}
//
//void AlphaHistogram::print() const {
//	for (auto index{ pos_A }; index <= pos_Z; index++) {
//		printf("%c: ", index);
//		auto n_asterisks = counts[index - pos_A];
//		while (n_asterisks--) printf("*");
//		printf("\n");
//	}
//}
//
//int main(int argc, char** argv) {
//	AlphaHistogram hist;
//	std::string_view currentArgument{};
//	for (size_t i{ 1 }; i < argc; i++) {
//		currentArgument = argv[i];
//		for (auto letter : currentArgument) {
//			hist.ingest(letter);
//		}
//	}
//	hist.print();
//}