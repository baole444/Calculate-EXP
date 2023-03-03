#include <iostream>
#include <charconv>
int calexp(const std::string& level,const std::string& exp) {
    int lvl = 0;
    double xp = 0.0;
    auto [lvl_ptr, lvl_err] = std::from_chars(level.data(), level.data() + level.size(), lvl);
    auto [xp_ptr, xp_err] = std::from_chars(exp.data(), exp.data() + exp.size(), xp);
    if (lvl_err != std::errc() || xp_err != std::errc()) {
        std::cerr << "Invalid input\n";
        return -1;
    }
    double base = lvl + xp;
    double basesqr = std::sqrt(base);
    if (base <= 15) return base * (base + 6);
    else if (base <= 30) return 5/2 * basesqr - 81/2 * base + 360;
    else if (base <= 1000000000) return 9/2 * basesqr - 325/2 * base + 2220;
    else return -1;
}
