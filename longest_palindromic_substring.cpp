#include "catch.hpp"

using namespace std;

string expandPalindrome(string s, int left, int right) {
    while (left >= 0 && right <= s.length() && s[left]==s[right]) {
        left--;
        right++;
    }
    return s.substr(left+1, right-left-1);
}

string longestPalindrome(string s) {
    string longest;
    for (int i = 0; i < s.length(); i++){
        string palindrome = expandPalindrome(s, i, i);
        if (longest.length()<palindrome.length()) longest = palindrome;
        palindrome = expandPalindrome(s, i, i+1);
        if (longest.length()<palindrome.length()) longest = palindrome;
    }
    return longest;
}

TEST_CASE("longest palindrome substring") {
    string s = "aba";
    REQUIRE( expandPalindrome(s, 1, 1) ==  "aba" );
    REQUIRE( expandPalindrome(s, 1, 2) ==  "" );
    REQUIRE( longestPalindrome(s) == "aba" );
}