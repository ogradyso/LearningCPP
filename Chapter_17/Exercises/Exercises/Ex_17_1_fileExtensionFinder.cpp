//#include <filesystem>
//#include <iomanip>
//#include <iostream>
//
//using namespace std;
//using namespace std::filesystem;
//
//void explore(const directory_entry& directory, const std::string extension) {
//    for (const auto& entry : recursive_directory_iterator{ directory.path() }) {
//        if (entry.is_directory()) {
//            //do nothing
//        }
//        else if (entry.path().extension().string() == extension) {
//            cout << entry.path().string() << endl;
//        }
//    }
//}
//
//int main(int argc, const char** argv) {
//    if (argc != 3) {
//        cerr << "Please enter a file path and file extension to search for.";
//        return -1;
//    }
//    const path sys_path{ argv[1] };
//    const auto extension{ argv[2] };
//    cout << "Files matching extension:\n";
//    cout << "----------------------------------\n";
//    for (const auto& entry : directory_iterator{ sys_path }) {
//        try {
//            if (entry.is_directory()) {
//                explore(entry, extension);
//            }
//            else if (entry.path().extension().string() == extension) {
//                cout << entry.path().string() << endl;
//            }
//        }
//        catch (const exception&) {
//        }
//    }
//}