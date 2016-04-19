#include "catch.hpp"

using namespace std;

int titleToNumber(string s) {
    int total = 0;
    int base = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        char ch = s[i];
        int tmp = ch - 'A' + 1;
        total += tmp * base;
        base *= 26;
    }
    return total;
}

TEST_CASE("excel sheet column number") {
    REQUIRE(titleToNumber("A") == 1);
    REQUIRE(titleToNumber("AA") == 27);
}
