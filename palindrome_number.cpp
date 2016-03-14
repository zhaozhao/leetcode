#include "catch.hpp"

bool isPalindrome(int x) {
    int i = x, n = 0;
    while (i > 0) {
        n = n * 10 + i % 10;
        i = i / 10;
    }
    return n == x;
}

TEST_CASE("palindrome number") {
    REQUIRE(isPalindrome(1));
    REQUIRE(isPalindrome(11));
    REQUIRE(!isPalindrome(-1));
}