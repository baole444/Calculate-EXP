#include <iostream>
#include <fstream>
#include <filesystem>
using std::cin; using std::cout; using std::endl; using std::fstream;
namespace fs = std::filesystem;

int logger(double base, double raw) {

    fstream data;
    data.open("./Memory/Log.txt", std::ios::ate | std::ios::in | std::ios::out);
    if (data.is_open()) {
    data << "Base = " << base << " | Raw = " << raw << endl;
    data << "\n";
    data.close();
    }
    else {
        cout << "" << endl;
        cout << "Log not found, generating..." << endl;

        fs::create_directories("./Memory");

        data.open("./Memory/Log.txt", std::ios::ate | std::ios::in | std::ios::out | std::ios::trunc);
        if (data.is_open()) {
        data << "Base = " << base << " | Raw = " << raw << endl;
        data << "\n";
        data.close();    
        }
        else {
            cout << "Cannot create directory." << endl;
        }  
    }
    return 0;
}