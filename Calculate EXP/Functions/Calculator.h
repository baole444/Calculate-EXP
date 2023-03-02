#include <iostream>
#include <string.h>
#include <math.h>
#include <sstream>
#include <limits>
using std::cin; using std::cout; using std::string;
using std::stringstream; using std::endl;
int calexp(string level, string exp) {
    std::string::size_type sz;
    double lbigxp,lmedixp,lsmallxp,output,xp;
    int lvl;
/*    
    stringstream containerLVL(level);
    containerLVL >> lvl;
    stringstream containerXP(exp);
    containerXP >> xp;
*/    
    try {
        lvl = stoi(level,&sz);
        xp = stod(exp,&sz);
    }
    catch (std::exception &ia) {
        cout << "Internal error: " << ia.what() << endl;
    }
    lbigxp = roundf(9/2 * ((lvl + xp) * (lvl + xp)) - 325/2 * (lvl + xp) + 2220);
    lmedixp = roundf(5/2 * ((lvl + xp) * (lvl + xp)) - 81/2 * (lvl + xp) + 360);
    lsmallxp = roundf((lvl + xp) * ((lvl + xp)+ 6));
    if(xp + lvl<=15) output = lsmallxp;
    else
        if(xp + lvl<=30) output = lmedixp;
    else
        if(xp + lvl<=1000000000) output = lbigxp;
    return output;
}