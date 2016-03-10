#include "catch.hpp"

bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    if (n == 1) return true;
    if (n % 3) return false;
    return isPowerOfThree(n / 3);
}

TEST_CASE("is power of three") {
    REQUIRE(!isPowerOfThree(0));
    REQUIRE(isPowerOfThree(1));
    REQUIRE(!isPowerOfThree(2));
    REQUIRE(isPowerOfThree(3));
    REQUIRE(!isPowerOfThree(4));
    REQUIRE(!isPowerOfThree(5));
    REQUIRE(isPowerOfThree(9));
}