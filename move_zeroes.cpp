#include "catch.hpp"

using namespace std;

void moveZeroes(vector<int> &nums) {
    int zeroPosition = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            zeroPosition = i;
            break;
        }
    }
    if (zeroPosition == -1) return;
    int swapPostion = zeroPosition + 1;
    while (swapPostion != nums.size()) {
        if (nums[swapPostion] != 0) {
            swap(nums[zeroPosition], nums[swapPostion]);
            ++zeroPosition;
        }
        ++swapPostion;
    }
}


TEST_CASE("move zeroes") {
    SECTION("none zero") {
        vector<int> test = {1, 1, 3, 3, 12};
        moveZeroes(test);
        REQUIRE(test == vector<int>({1, 1, 3, 3, 12}));
    }
    SECTION("leetcode example") {
        vector<int> test = {0, 1, 0, 3, 12};
        moveZeroes(test);
        REQUIRE(test == vector<int>({1, 3, 12, 0, 0}));
    }
}