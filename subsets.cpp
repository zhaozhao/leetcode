#include "catch.hpp"

using namespace std;

void subsets(const vector<int> &nums, vector<int> now, vector<vector<int>> &res) {
    for (int i: nums) {
        if (now.empty() || i > now.back()) {
            vector<int> subset(now);
            subset.push_back(i);
            res.push_back(subset);
            subsets(nums, subset, res);
        }
    }
}

vector<vector<int>> subsets(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    subsets(nums, vector<int>(), result);
    result.push_back(vector<int>());
    return result;
}


TEST_CASE("subsets") {
    vector<int> nums = {0, 1};
    vector<vector<int>> expected = {{0},
                                    {0, 1},
                                    {1},
                                    {}};
    REQUIRE(subsets(nums) == expected);
}