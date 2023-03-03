#include <iostream>
#include <fstream>
#include <filesystem>
using std::cin; using std::cout; using std::endl; using std::ofstream;
namespace fs = std::filesystem;

int logger(const double& base,const double& raw) {

    const auto logpath = "./Memory/Log.txt";

    ofstream data;
    data.open(logpath, std::ios::ate | std::ios::in | std::ios::out);

    if (!data.is_open()) {

        cout << "" << endl;
        cout << "Log not found, generating..." << endl;

        fs::create_directories("./Memory");

        data.open(logpath, std::ios::ate | std::ios::in | std::ios::out | std::ios::trunc);

        if (!data.is_open()) {cout << "Cannot create directory." << endl;}
    }
    else {
        data << "Base = " << base << " | Raw = " << raw << endl;
        data << "\n";
        data.close();
    }

    return 0;

}
