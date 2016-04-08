#include "catch.hpp"

using namespace std;

vector<int> countBits(int num) {
    vector<int> ret(num + 1);
    for (int i = 1; i <= num; ++i)
        ret[i] = ret[i & (i - 1)] + 1;
    return ret;
}

TEST_CASE("counting bits") {
    SECTION("leetcode") {
        vector<int> expected = {0, 1, 1, 2, 1, 2};
        REQUIRE(countBits(5) == expected);
    }
}
