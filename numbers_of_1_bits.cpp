#include "catch.hpp"

int hammingWeight(uint32_t n) {
    int weight = 0;
    while (n) {
        n &= n - 1;
        ++weight;
    }
    return weight;
}

TEST_CASE("numbers of 1 bits") {
    REQUIRE(hammingWeight(0b00000000000000000000000000001011) == 3);
}