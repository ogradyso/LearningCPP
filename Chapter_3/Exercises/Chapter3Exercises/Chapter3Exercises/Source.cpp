#include <cstdio>

//exercise 2:
char read_from(char arrayToRead[], int indexToRead) {
	return arrayToRead[indexToRead];
};

void write_to(char arrayToWrite[], int indexToWrite, char charToWrite) {
	size_t n_elements = sizeof(arrayToWrite);
	if (indexToWrite > n_elements - 1) printf("Index out of bounds.");
	else arrayToWrite[indexToWrite] = charToWrite;
	printf("String: %s\n", arrayToWrite);
};

//exercise 3: 
struct Element {
	Element* next{};
	Element* previous{};
	void insert_after(Element* new_element) {
		new_element->next = this->next;
		new_element->previous = this;
		this->next = new_element;
	}
	void insert_before(Element* new_element) {
		new_element->previous = this->previous;
		new_element->next = this;
		(this->previous)->next = new_element;
		this->previous = new_element;
	}
	char prefix[2];
	short operating_number;
};

int main() {

	//Exercise 2:
	char lower[] = "abc?e";
	char upper[] = "ABC?E";
	char* upper_ptr = upper;

	lower[3] = 'd';
	upper_ptr[3] = 'D';

	char letter_d = lower[3];
	char letter_D = upper_ptr[3];

	printf("lower: %s\nupper: %s\n", lower, upper);
	char read_letter = read_from(lower, 2);
	printf("Testing read_from: %c\n", read_letter);
	write_to(upper, 3, 'f');
	write_to(upper, 10, '5');

	//Exercise 3:
	Element trooper1, trooper2, trooper3, trooper4;
	trooper1.prefix[0] = 'T';
	trooper1.prefix[1] = 'K';
	trooper1.operating_number = 421;
	trooper1.insert_after(&trooper2);
	trooper2.prefix[0] = 'F';
	trooper2.prefix[1] = 'N';
	trooper2.operating_number = 2187;
	trooper2.insert_after(&trooper3);
	trooper3.prefix[0] = 'L';
	trooper3.prefix[1] = 'S';
	trooper3.operating_number = 005;
	trooper3.insert_before(&trooper4);
	trooper4.prefix[0] = 'S';
	trooper4.prefix[1] = 'O';
	trooper4.operating_number = 42;

	for (Element* cursor = &trooper1; cursor; cursor = cursor->next) {
		printf("stormtrooper %c%c-%d\n",
			cursor->prefix[0],
			cursor->prefix[1],
			cursor->operating_number);
	}
	for (Element* cursor = &trooper3; cursor; cursor = cursor->previous) {
		printf("stormtrooper %c%c-%d\n",
			cursor->prefix[0],
			cursor->prefix[1],
			cursor->operating_number);
	}

	//exercise 4:
	auto original = 100;
	auto& original_ref = original;
	printf("Original: %d\n.", original);
	printf("Reference: %d\n", original_ref);

	auto new_value = 200;
	original_ref = new_value;
	printf("New Value: %d\n", original);
	printf("New Value: %d\n", new_value);
	printf("Reference: %d\n", original_ref);



}