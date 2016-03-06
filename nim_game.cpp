#include "catch.hpp"

bool canWinNim(int n) {
    if (n % 4 == 0) {
        return false;
    }
    return true;
}

TEST_CASE("nim game") {
    REQUIRE(canWinNim(1) == true);
    REQUIRE(canWinNim(2) == true);
    REQUIRE(canWinNim(3) == true);
    REQUIRE(canWinNim(4) == false);
}

