#include "catch.hpp"

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    if (target <= nums[start]) {
      return start;
    } else if (target > nums[end]) {
      return end + 1;
    } else if (target == nums[end]) {
      return end;
    }

    for (;;) {
      int middle = (start + end) / 2;
      if (target < nums[middle]) {
        end = middle;
      } else if (target > nums[middle]) {
        start = middle;
      } else {
        return middle;
      }
      if (start + 1 == end) {
        return end;
      }
    }

    return 1;
  }
};

TEST_CASE("search insert position") {
  Solution solution;
  vector<int> input = {1, 3, 5, 6};
  REQUIRE(solution.searchInsert(input, 5) == 2);
  REQUIRE(solution.searchInsert(input, 2) == 1);
  REQUIRE(solution.searchInsert(input, 7) == 4);
  REQUIRE(solution.searchInsert(input, 0) == 0);
}