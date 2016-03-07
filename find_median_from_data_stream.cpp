#include "catch.hpp"
#include <queue>

using namespace std;

class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (small.size() == large.size()) {
            large.push(num);
            small.push(large.top());
            large.pop();
        } else {
            small.push(num);
            large.push(small.top());
            small.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (small.size() == large.size()) {
            return (small.top() + large.top()) / 2.0;
        }
        return small.top();

    }

private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

};

TEST_CASE("find median from data stream") {
    MedianFinder finder;
    finder.addNum(1);
    REQUIRE(finder.findMedian() == 1.0);
    finder.addNum(2);
    REQUIRE(finder.findMedian() == 1.5);
    finder.addNum(3);
    REQUIRE(finder.findMedian() == 2.0);
}