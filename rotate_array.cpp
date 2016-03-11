#include "catch.hpp"

using namespace std;

void rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
}

TEST_CASE("rotate array") {
    vector<int> one_to_seven = {1, 2, 3, 4, 5, 6, 7};
    rotate(one_to_seven, 3);
    REQUIRE(one_to_seven == vector<int>({5, 6, 7, 1, 2, 3, 4}));
}