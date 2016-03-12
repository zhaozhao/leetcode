#include "catch.hpp"

using namespace std;

int singleNumber(vector<int> &nums) {
    int result = 0;
    for (int i : nums) {
        result ^= i;
    }
    return result;
}

TEST_CASE("single number") {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};
    REQUIRE(singleNumber(nums) == 4);
}
