#include <iostream>
#include <string.h>
#include <math.h>
#include <sstream>
#include <limits>
#include <fstream>
#include "../Calculator.h"
#include "../Checker.h"
#include "../logger.h"
using std::cin; using std::cout; using std::string;
using std::stringstream; using std::endl;
using std::fstream;

int main() {
    std::string::size_type sz;
    string iscontiune = "yes";
    while(iscontiune == "yes"){
        string x,y;
        int xpcheck,lvlcheck,baselvl;
        lvlcheck = 0;
        xpcheck = 0;
        double basexp,outp;
        while (lvlcheck == 0) {
            cout << "Enter your rounded level = "; cin >> x;
            lvlcheck = validatelvl(x);
        }
        while (xpcheck == 0) {
            cout << "Enter how full is your exp bar = "; cin >> y;
            xpcheck = validatexp(y);
        }
        try {
            baselvl = stoi(x,&sz);
            basexp = stod(y,&sz);
        }
        catch (std::exception &ia) {
            cout << "Internal error: " << ia.what() << endl;
        }
        double base = baselvl + basexp;
        cout << endl;
        cout << "Base = " << base << endl;
        outp = calexp(x,y);
        cout<<"Raw exp value = "<< outp << endl;
        logger(base,outp);
        cout << endl;
        cout << "Type anything to continue... " <<endl;
        cout << "Type \"stop\" to exit > "; cin >> iscontiune;
        if (iscontiune == "stop") break;
        else iscontiune = "yes";
        cout << endl;
    }
}