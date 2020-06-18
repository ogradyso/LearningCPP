#include <cstdio>
#include <memory>
#pragma warning(disable: 4996)

using FileGuard = std::shared_ptr<FILE>;

struct Hal {
	Hal(std::shared_ptr<FILE> file) {
		this->file = file;
		fprintf(file.get(), "HELLO DAVE\n");
	};
	~Hal() {
		fprintf(file.get(), "STOP DAVE\n");
	};
	void write_status() {
		fprintf(file.get(), "I'm completely operational.\n");
	};
	std::shared_ptr<FILE> file;
};

int main() {
	auto file = fopen("HAL9000", "w");
	if (!file) return errno;
	FileGuard file_guard{ file, fclose };
	//file open here:
	Hal myFileInstance(file_guard);
	myFileInstance.write_status();
	Hal myFileInstance2(file_guard);
	myFileInstance2.write_status();
	Hal myFileInstance3(file_guard);
	myFileInstance3.write_status();
	//File closed here:
	return 0;
}