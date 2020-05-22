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
		new_element->next = next;
		next = new_element;
	}
	void insert_before(Element* new_element) {
		new_element->previous = previous;
		previous = new_element;
	}
	char prefix[2];
	short operating_number;
};

int main() {
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
	write_to(upper,3, 'f');
	write_to(upper, 10, '5');
}