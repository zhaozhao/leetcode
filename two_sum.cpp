#include "catch.hpp"
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++){
        int tmp = nums[i];
        int pair = target - tmp;
        auto search = hash.find(pair);
        if (search != hash.end()) {
            result.push_back(search->second);
            result.push_back(i);
            return result;
        }
        hash[tmp] = i;
    }
}


TEST_CASE("Two sum case", "[two sum]") {
    vector<int> test_nums = {1, 2, 3};
    REQUIRE( twoSum(test_nums, 3) == vector<int>({0, 1}) );
}
