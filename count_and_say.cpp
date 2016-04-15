#include "catch.hpp"

using namespace std;

string countAndSay(int n) {
    string res = "1";
    while (--n) {
        string cur;
        for (int i = 0; i < res.size(); ++i) {
            char ch = res[i];
            int count = 1;
            while (i + 1 < res.size() && res[i] == res[i + 1]) {
                ++i;
                ++count;
            }
            cur += to_string(count) + ch;
        }
        res = std::move(cur);
    }
    return res;
}

TEST_CASE("count and say") {
    REQUIRE(countAndSay(1) == string("1"));
    REQUIRE(countAndSay(2) == string("11"));
    REQUIRE(countAndSay(3) == string("21"));
    REQUIRE(countAndSay(4) == string("1211"));
}