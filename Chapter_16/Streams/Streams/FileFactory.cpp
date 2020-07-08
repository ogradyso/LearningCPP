//#include <fstream>
//#include <string>
//
//using namespace std;
//
//ifstream open(const char* path, ios_base::openmode mode = ios_base::in) {
//	ifstream file{ path, mode };
//	if (!file.is_open()) {
//		string err{ "Unable to open file " };
//		err.append(path);
//		throw runtime_error{ err };
//	}
//	file.exceptions(ifstream::badbit);
//	return file;
//}
//
