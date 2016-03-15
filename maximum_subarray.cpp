#include "catch.hpp"

using namespace std;

int maxSubArray(vector<int> &nums) {
    int current = 0;
    int max_value = nums.front();
    for (int i : nums) {
        current += i;
        max_value = max(max_value, current);
        if(current < 0) {
            current =0;
        }
    }
    return max_value;
}

TEST_CASE("maximum sub array") {
    vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    REQUIRE(maxSubArray(array) == 6);
}
