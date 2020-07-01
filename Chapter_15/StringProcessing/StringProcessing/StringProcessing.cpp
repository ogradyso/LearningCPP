#define CATCH_CONFIG_MAIN
#include "catch.h"

#include <string>

TEST_CASE("std::string supports constructing") {
	SECTION("empty strings") {
		std::string cheese;
		REQUIRE(cheese.empty());
	}
	SECTION("repeated characters") {
		std::string roadside_assistance(3, 'A');
		REQUIRE(roadside_assistance == "AAA");
	}
}

TEST_CASE("std::string supports constructing substrings ") {
	auto word = "gobbledygook";
	REQUIRE(std::string(word) == "gobbledygook");
	REQUIRE(std::string(word, 6) == "gobble");
}

TEST_CASE("std::string supports") {
	std::string word("catawampus");
	SECTION("copy constructing") {
		REQUIRE(std::string(word) == "catawampus");
	}
	SECTION("move constructing") {
		REQUIRE(std::string(move(word)) == "catawampus");
	}
	SECTION("constructing from substrings") {
		REQUIRE(std::string(word, 0, 3) == "cat");
		REQUIRE(std::string(word, 4) == "wampus");
	}
}

TEST_CASE("constructing a string with") {
	SECTION("std::string(char*) stops at embedded nulls") {
		std::string str("Idioglossia\0ellohay!");
		REQUIRE(str.length() == 11);
	}
	SECTION("operator\"\"s incorporates embedded nulls") {
		using namespace std::string_literals;
		auto str_lit = "ideoglossia\0ellohay!"s;
		REQUIRE(str_lit.length() == 20);
	}
}

TEST_CASE("string's c_str method makes null-terminated strings") {
	std::string word("horripilation");
	auto as_cstr = word.c_str();
	REQUIRE(as_cstr[0] == 'h');
	REQUIRE(as_cstr[1] == 'o');
	REQUIRE(as_cstr[11] == 'o');
	REQUIRE(as_cstr[12] == 'n');
	REQUIRE(as_cstr[13] == '\0');
}

TEST_CASE("std::string supports comparison with") {
	using namespace std::literals::string_literals;
	std::string word("allusion");
	SECTION("operator== and !=") {
		REQUIRE(word == "allusion");
		REQUIRE(word == "allusion"s);
		REQUIRE(word != "Allusion");
		REQUIRE(word != "illusion"s);
		REQUIRE_FALSE(word == "illusion"s);
	}
	SECTION("Operator<") {
		REQUIRE(word < "illusion");
		REQUIRE(word < "illusion"s);
		REQUIRE(word > "Illusion"s);
	}
}

//Manipulating string elements:
TEST_CASE("std::string supports appending with") {
	std::string word("butt");
	SECTION("push_back") {
		word.push_back('e');
		REQUIRE(word == "butte");
	}
	SECTION("operator+=") {
		word += "erfinger";
		REQUIRE(word == "butterfinger");
	}
	SECTION("append char") {
		word.append(1, 's');
		REQUIRE(word == "butts");
	}
	SECTION("append char*") {
		word.append("stockings", 5);
		REQUIRE(word == "buttstock");
	}
	SECTION("append (half-open range)") {
		std::string other("onomatopoeia");
		word.append(other.begin(), other.begin() + 2);
		REQUIRE(word == "button");
	}
}

//removing elements
TEST_CASE("std::string supports removal with") {
	std::string word("therein");
	SECTION("pop_back") {
		word.pop_back();
		word.pop_back();
		REQUIRE(word == "there");
	}
	SECTION("clear") {
		word.clear();
		REQUIRE(word.empty());
	}
	SECTION("erase using half-open range") {
		word.erase(word.begin(), word.begin() + 3);
		REQUIRE(word == "rein");
	}
	SECTION("erase using an index and length") {
		word.erase(5, 2);
		REQUIRE(word == "there");
	}
}

//replacing elements
TEST_CASE("std::string replace works with") {
	std::string word("substitution");
	SECTION("a range and a char*") {
		word.replace(word.begin() + 9, word.end(), "e");
		REQUIRE(word == "substitute");
	}
	SECTION("two ranges") {
		std::string other("innuendo");
		word.replace(word.begin(), word.begin() + 3,
			other.begin(), other.begin() + 2);
		REQUIRE(word == "institution");
	}
	SECTION("an index/length and a string") {
		std::string other("vers");
		word.replace(3, 6, other);
		REQUIRE(word == "subversion");
	}
}

//resize method:
TEST_CASE("std::string resize") {
	std::string word("shamp");
	SECTION("can remove elements") {
		word.resize(4);
		REQUIRE(word == "sham");
	}
	SECTION("can add elements") {
		word.resize(7, 'o');
		REQUIRE(word == "shampoo");
	}
}

//substring method
TEST_CASE("std::string substr with") {
	std::string word("hobbits");
	SECTION("no arguments copies the string") {
		REQUIRE(word.substr()=="hobbits");
	}
	SECTION("position takes the remainder") {
		REQUIRE(word.substr(3) == "bits");
	}
	SECTION("poswition/index takes a substring") {
		REQUIRE(word.substr(3, 3) == "bit");
	}
}

//Searching strings

TEST_CASE("std::string find") {
	using namespace std::literals::string_literals;
	std::string word("pizzazz");
	SECTION("locates substrings from strings") {
		REQUIRE(word.find("zz"s)==2);//pi(z)zazz
	}
	SECTION("acce[ts a position argument") {
		REQUIRE(word.find("zz"s, 3) == 5);// pizza(z)z
	}
	SECTION("locates substrings from char*") {
		REQUIRE(word.find("zaz") == 3); //piz(z)azz
	}
	SECTION("returns npos when not found") {
		REQUIRE(word.find('x') == std::string::npos);
	}
}

//rfind (search in reverse

TEST_CASE("std::string rfind") {
	using namespace std::literals::string_literals;
	std::string word("pizzazz");
	SECTION("locates substrings from strings") {
		REQUIRE(word.rfind("zz"s) == 5);   //pizza(z)z
	}
	SECTION("accepts a position argument") {
		REQUIRE(word.rfind("zz"s, 3) == 2); //pi(z)zazz
	}
	SECTION("locates substrings from char*") {
		REQUIRE(word.rfind("zaz") == 3);//piz(z)azz
	}

	SECTION("returns npos when not found") {
		REQUIRE(word.rfind('x') == std::string::npos);
	}
}

//find_first_of
TEST_CASE("std::string find_first_of") {
	using namespace std::literals::string_literals;
	std::string sentence("I am a Zizzer-Zazzer-Zuz as you can plainly see.");
	SECTION("locates characters within another string") {
		REQUIRE(sentence.find_first_of("Zz"s) == 7);//(Z)izzer
	}
	SECTION("accepts a position argument") {
		REQUIRE(sentence.find_first_of("Zz"s, 11) == 14);//(Z)azzer
	}
	SECTION("returns npos when not found") {
		REQUIRE(sentence.find_first_of("Xx"s) == std::string::npos);
	}
}

//variations on find_*_of
TEST_CASE("std::string") {
	using namespace std::literals::string_literals;
	std::string sentence("I am a Zizzer-Zazzer-Zuzz as you can plainly see.");
	SECTION("find_last_of finds last element withing another string") {
		REQUIRE(sentence.find_last_of("Zz"s) == 24);  //Zuz(z)
	}
	SECTION("find_first_not_of finds first element not within another string") {
		REQUIRE(sentence.find_first_not_of(" -IZaeimrz"s) == 22); //Z(u)zz
	}
	SECTION("find_last_not_of finds last element not within another string") {
		REQUIRE(sentence.find_last_not_of(" .es"s) == 43); //plainl(y)
	}
}

//Numeric conversions
TEST_CASE("STL string conversion function") {
	using namespace std::literals::string_literals;
	SECTION("to_string") {
		REQUIRE("8675309"s == std::to_string(8675309));
	}
	SECTION("to_wstring") {
		REQUIRE(L"109951.1627776"s == std::to_wstring(109951.1627776));
	}
}

TEST_CASE("STL stirng conversion function") {
	using namespace std::literals::string_literals;
	SECTION("stoi") {
		REQUIRE(std::stoi("8675309"s) == 8675309);
	}
	SECTION("stoi") {
		REQUIRE_THROWS_AS(std::stoi("1099511627776"s), std::out_of_range);
	}
	SECTION("stoul with all valid characters") {
		size_t last_character{};
		const auto result = std::stoul("0xD3C34C3D"s, &last_character, 16);
		REQUIRE(result == 0xD3C34C3D);
		REQUIRE(last_character == 10);
	}
	SECTION("stoul") {
		size_t last_character{ };
		const auto result = std::stoul("42six"s, &last_character);
		REQUIRE(result == 42);
		REQUIRE(last_character == 2);
	}
	SECTION("stod") {
		REQUIRE(std::stod("2.7182818"s) == Approx(2.7182818));
	}
}

// String view
TEST_CASE("std::string_view suppports") {
	SECTION("default construction") {
		std::string_view view;
		REQUIRE(view.data() == nullptr);
		REQUIRE(view.size() == 0);
		REQUIRE(view.empty());
	}
	SECTION("construction from string") {
		std::string word("sacrosanct");
		std::string_view view(word);
		REQUIRE(view == "sacrosanct");
	}
	SECTION("construction from C-string") {
		auto word = "viewership";
		std::string_view view(word);
		REQUIRE(view == "viewership");
	}
	SECTION("construction from C-string and length") {
		auto word = "viewership";
		std::string_view view(word, 4);
		REQUIRE(view == "view");
	}
}

TEST_CASE("std::string_view is modifiable with") {
	std::string_view view("previewing");
	SECTION("remove prefix") {
		view.remove_prefix(3);
		REQUIRE(view == "viewing");
	}
	SECTION("remove_suffix") {
		view.remove_suffix(3);
		REQUIRE(view == "preview");
	}
}

//using string_view:
#include <string_view>

size_t count_vees(std::string_view my_view) {
	size_t result{};
	for (auto letter : my_view)
		if (letter == 'v') result++;
	return result;
}

//regular expressions
#include <regex>

TEST_CASE("std::basic_regex constructs from a string literal") {
	std::regex zip_regex{ R"((\w{2})?(\d{5})(-\d{4})?)" };
	REQUIRE(zip_regex.mark_count() == 3);
}

//algorithms: matching
#include <regex>
#include <string>

TEST_CASE("std::sub_match") {
	std::regex regex{ R"((\w{2})(\d{5})(-\d{4})?)" };
	std::smatch results;
	SECTION("returns true given matching string") {
		std::string zip("NJ07936-3173");
		const auto matched = std::regex_match(zip, results, regex);
		REQUIRE(matched);
		REQUIRE(results[0] == "NJ07936-3173");
		REQUIRE(results[1] == "NJ");
		REQUIRE(results[2] == "07936");
		REQUIRE(results[3] == "-3173");
	}
	SECTION("returns false given non-matching string") {
		std::string zip("Iomega Zip 100");
		const auto matched = std::regex_match(zip, results, regex);
		REQUIRE_FALSE(matched);
	}
}

//algorithms searching
TEST_CASE("when only part of a string matches a regex, std::regex_ ") {
	std::regex regex{ R"((\w{2})(\d{5})(-\d{4}) ? )" };
	std::string sentence("The string NJ07936-3173 is a Zip code.");
	SECTION("match returns false") {
		REQUIRE_FALSE(std::regex_match(sentence, regex));
	}
	SECTION("search returns true") {
		REQUIRE(std::regex_search(sentence, regex));
	}
}

//algorithms replacing
TEST_CASE("std::regex_replace") {
	std::regex regex{ "[aeoiu]" };
	std::string phrase("queueing and cooeeing in eutopia");
	const auto result = std::regex_replace(phrase, regex, "_");
	REQUIRE(result == "q_____ng _nd c_____ng _n __t_p__");
}

//Boost::string algorithms

//boost::string predicates
#include <string>
#include <boost/algorithm/string/predicate.hpp>

TEST_CASE("boost::algorith") {
	using namespace boost::algorithm;
	using namespace std::literals::string_literals;
	std::string word("cymotrichous");
	SECTION("starts_with tests a string's beginning") {
		REQUIRE(starts_with(word, "cymo"s));
	}
	SECTION("istarts_with is case insensitive") {
		REQUIRE(istarts_with(word, "cYmO"s));
	}
}

TEST_CASE("boost::algorithm::all evalueates a predicate for all elements") {
	using namespace boost::algorithm;
	std::string word("juju");
	REQUIRE(all(word, [](auto c) {return c == 'j' || c == 'u'; }));
}