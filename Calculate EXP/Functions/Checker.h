#include <iostream>
#include <string.h>
using std::cin; using std::cout; using std::string; using std::endl; using std::istringstream; using std::stod;
int validatelvl(string level) {
    int output;
    std::string::size_type sz;
    double checker;
    checker = 0;
    output = 0;
    try {
        checker = stod(level, &sz);
        if (checker == 0 || checker >= 1) output = 1;
        else {
            cout << "Invalid input, please try again." << endl;
            output = 0;            
        }
    }
    catch (std::exception& ia) {
        cout << "Invalid input, please try again." << endl;
        output = 0;
    }
    return output;
}
int validatexp(string exp) {
    int output;
    std::string::size_type sz;
    double checker;
    checker = 0.0;
    output = 0;
    try {
        checker = stod(exp, &sz);
        if (checker < 1 && checker >= 0) output = 1;
        else {
            output = 0;
            cout << "Invalid input, please try again." << endl;
        }
    }
    catch (std::exception& ia) {
        output = 0;
        cout << "Invalid input, please try again." << endl;
    }
    return output;    
}