#include "catch.hpp"

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return !(n & (n - 1));
}

TEST_CASE("is power of two") {
    REQUIRE(!isPowerOfTwo(0));
    REQUIRE(isPowerOfTwo(1));
    REQUIRE(isPowerOfTwo(2));
    REQUIRE(!isPowerOfTwo(3));
    REQUIRE(isPowerOfTwo(4));
    REQUIRE(!isPowerOfTwo(5));
}