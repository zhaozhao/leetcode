#include <numeric>
#include "catch.hpp"

using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) return s;
    vector<string> strings(numRows, "");
    int row = 0, step = 1;
    for (int i = 0; i != s.size(); i++) {
        strings[row].push_back(s[i]);
        if (row == 0) step = 1;
        else if (row == numRows - 1) step = -1;
        row += step;
    }
    return accumulate(strings.begin(), strings.end(), string(""));
}

TEST_CASE("zigzag conversion") {
    REQUIRE(convert("PAYPALISHIRING", 1) == "PAYPALISHIRING");
    REQUIRE(convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
}
