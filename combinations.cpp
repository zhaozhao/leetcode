#include "catch.hpp"

using namespace std;

void combine(vector<vector<int>> &result, vector<int> &now, int n, int k) {
    if (now.size() == k) {
        result.push_back(now);
        return;
    }
    for (int i = now.empty() ? 1 : now.back() + 1; i <= n; i++) {
        now.push_back(i);
        combine(result, now, n, k);
        now.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> now;
    combine(result, now, n, k);
    return result;
}

TEST_CASE("combinations") {
    auto result = combine(4, 2);
    vector<vector<int>> expected = {{1, 2},
                                    {1, 3},
                                    {1, 4},
                                    {2, 3},
                                    {2, 4},
                                    {3, 4}};
    REQUIRE(result == expected);
}
