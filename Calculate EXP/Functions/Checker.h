#include <iostream>
#include <string.h>
#include <charconv>
using std::cout; using std::string; using std::endl; using std::stod;
int validatelvl(const string& level) {

    int lvl = 0;
    int output;

    auto [lvl_ptr, lvl_err] = std::from_chars(level.data(), level.data() + level.size(), lvl);
    if (lvl_err != std::errc() || lvl < 0) {
        std::cerr << "Invalid input, required integer >= 0\n";
        output = 0;
    } else output = 1;

    return output;
}
int validatexp(const string& exp) {

    double xp = 0;
    int output;
    auto [xp_ptr, xp_err] = std::from_chars(exp.data(), exp.data() + exp.size(), xp);
    if (xp_err != std::errc() || xp > 1 || xp < 0) {
        std::cerr << "Invalid input, required decimal 0 <= exp < 1\n";
        output = 0;
    } else output = 1;
    return output;
}
