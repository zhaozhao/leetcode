#include "catch.hpp"

using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    int left = 0;
    int right = x;
    while (left < right) {
      int mid = (left + right) / 2;
      if (u_long(mid + 1) * u_long(mid + 1) <= u_long(x)) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
TEST_CASE("sqrt x") {
  Solution solution;
  REQUIRE(solution.mySqrt(4) == 2);
  REQUIRE(solution.mySqrt(8) == 2);
}
