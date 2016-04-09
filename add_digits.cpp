#include "catch.hpp"


int addDigits(int num) {
    return (num - 1) % 9 + 1;
}

TEST_CASE("add digits") {
    REQUIRE(addDigits(0) == 0);
    REQUIRE(addDigits(1) == 1);
    REQUIRE(addDigits(2) == 2);
    REQUIRE(addDigits(9) == 9);
    REQUIRE(addDigits(10) == 1);
    REQUIRE(addDigits(38) == 2);
}