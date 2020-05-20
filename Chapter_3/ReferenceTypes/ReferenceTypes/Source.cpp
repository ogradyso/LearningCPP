#include <cstdio>

int main() {
	//pointers
	// pointers encode an objects type and its address
	int gettysburg{};
	printf("gettysburg: %d\n", gettysburg);
	int *gettysburg_address = &gettysburg;
	printf("&gettysburg: %p\n", gettysburg_address);

}