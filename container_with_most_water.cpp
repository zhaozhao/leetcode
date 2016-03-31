#include "catch.hpp"

using namespace std;

int maxArea(vector<int> &height) {
    int max = 0;
    int mini_left = 0;
    for (int i = 0; i < height.size(); ++i) {
        if (height[i] <= mini_left) continue;
        mini_left = height[i];
        int mini_right = 0;
        for (int j = height.size() - 1; i < j; --j) {
            if (height[j] <= mini_right) continue;
            mini_right = height[j];
            int cur = (j - i) * min(height[i], height[j]);
            max = max > cur ? max : cur;
        }
    }
    return max;
}

TEST_CASE("container with most water") {
    SECTION("only two lines") {
        vector<int> height = {1, 1};
        REQUIRE(maxArea(height) == 1);
    }
    SECTION("three lines") {
        vector<int> height = {1, 1, 1};
        REQUIRE(maxArea(height) == 2);
    }
    SECTION("three lines") {
        vector<int> height = {2, 1, 2};
        REQUIRE(maxArea(height) == 4);
    }
}