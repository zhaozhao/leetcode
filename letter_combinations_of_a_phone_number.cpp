#include "catch.hpp"
#include <map>

using namespace std;
map<char, string> panel = {{'2', "abc"},
                           {'3', "def"},
                           {'4', "ghi"},
                           {'5', "jkl"},
                           {'6', "mno"},
                           {'7', "pqrs"},
                           {'8', "tuv"},
                           {'9', "wxyz"}
};

void _backtracking(vector<string> &rev, string &res, int pos, string &digits) {
    if (pos == digits.size()) {
        rev.push_back(res);
        return;
    }
    char cur = digits[pos];
    for (char ch: panel[cur]) {
        res.push_back(ch);
        _backtracking(rev, res, pos + 1, digits);
        res.pop_back();
    }
    return;
}

vector<string> letterCombinations(string digits) {
    vector<string> rev;
    if (digits.empty()) return rev;
    string res;
    _backtracking(rev, res, 0, digits);
    return rev;
}

TEST_CASE("letter combinations of a phone number") {
    SECTION("leetcode") {
        string input = "23";
        vector<string> expected = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
        REQUIRE(letterCombinations(input) == expected);
    }
}
