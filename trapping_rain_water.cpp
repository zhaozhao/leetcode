#include "catch.hpp"

using namespace std;

int trap(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int water = 0, level = 0;
    while (left <= right) {
        int lower = height[height[left] < height[right] ? left++ : right--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
}

TEST_CASE("trapping rain water") {
    SECTION("leetcode example") {
        vector<int> example = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        REQUIRE(trap(example) == 6);
    }
}
