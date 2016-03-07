#include "catch.hpp"

using namespace std;

void wiggleSort(vector<int> &nums) {
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end(), greater<int>());
    int s = sorted.size() / 2;
    int l = 0;
    bool is_small = true;
    for (int i = 0; i < nums.size(); i++) {
        nums[i] = is_small ? sorted[s++] : sorted[l++];
        is_small = !is_small;
    }
}

bool check(vector<int> &nums) {
    for (int i = 0; i + 1 < nums.size(); i++) {
        if (i % 2 && nums[i] <= nums[i + 1])
            return false;
        if (i % 2 == 0 && nums[i] >= nums[i + 1])
            return false;
    }
    return true;
}

TEST_CASE("wiggle sort II") {
    vector<int> nums1 = {1, 2, 3, 4};
    REQUIRE(check(nums1) == false);
    wiggleSort(nums1);
    REQUIRE(check(nums1));
}