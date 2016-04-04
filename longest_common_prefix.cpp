#include "catch.hpp"

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return string();
    for (int index = 0; index < strs[0].size(); ++index) {
        string::value_type tmp = strs[0][index];
        for (int i = 1; i < strs.size(); ++i) {
            if (index >= strs[i].size() || strs[i][index] != tmp)
                return string(strs[0], 0, index);
        }
    }
    return string(strs[0]);
}

TEST_CASE("longest common prefix") {
    SECTION("a, ab, ac") {
        vector<string> strings = {"a", "ab", "ac"};
        REQUIRE(longestCommonPrefix(strings) == string("a"));
    }
    SECTION("a, , ac") {
        vector<string> strings = {"a", "", "ac"};
        REQUIRE(longestCommonPrefix(strings) == string(""));
    }
}