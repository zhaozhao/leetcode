#include "catch.hpp"
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int max_length = 0;
    int head = 0;
    for(int tail = 0; tail != s.length(); tail++){
        auto search = hash.find(s[tail]);
        if (search != hash.end()){
            head = max(head, search->second + 1);
        }
        hash[s[tail]] = tail;
        max_length = max(max_length, tail - head + 1);
    }
    return max_length;
}

TEST_CASE("longest_substring_without_repeating", "[longest_substring_without_repeating]") {
    REQUIRE( lengthOfLongestSubstring("abcabcbb") == 3 );
    REQUIRE( lengthOfLongestSubstring("bbbbb") == 1 );
}
