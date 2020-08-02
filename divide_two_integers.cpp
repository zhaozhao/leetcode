#include "catch.hpp"
#include <iostream>

using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    long dividendl = long(dividend);
    long divisorl = long(divisor);

    if (divisor == -1 && dividend == INT32_MIN) {
      return INT32_MAX;
    }
    if (dividend > 0 && divisor > 0) {
      return this->_divide(dividendl, divisorl);
    }
    if (dividend > 0 && divisor < 0) {
      return -this->_divide(dividendl, -divisorl);
    }
    if (dividend < 0 && divisor < 0) {
      return this->_divide(-dividendl, -divisorl);
    }
    if (dividend < 0 && divisor > 0) {
      return -this->_divide(-dividendl, divisorl);
    }
    return 0;
  }
  long _divide(long dividend, long divisor) {
    if (divisor > dividend) {
      return 0;
    }
    long count = 1;
    long sum = divisor;
    while ((sum + sum) <= dividend) {
      count += count;
      sum += sum;
    }
    return count + this->_divide(dividend - sum, divisor);
  }
};
TEST_CASE("Divide Two Integers") {
  Solution solution;
  REQUIRE(solution.divide(10, 3) == 3);
  REQUIRE(solution.divide(10, 1) == 10);
  REQUIRE(solution.divide(7, -3) == -2);
  REQUIRE(solution.divide(2147483647, 1) == 2147483647);
  REQUIRE(solution.divide(-2147483648, -1) == 2147483647);
  REQUIRE(solution.divide(-2147483648, 1) == -2147483648);
}