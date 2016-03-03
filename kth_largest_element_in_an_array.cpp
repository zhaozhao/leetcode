#include "catch.hpp"

using namespace std;

int partition(vector<int>& array, int start, int end) {
    int pivot = array[start];
    int l = start + 1;
    int r = end;
    while(l <= r) {
        if (array[l] > pivot && array[r] < pivot) {
            swap(array[l++], array[r--]);
        }
        if (array[l] <= pivot) l++;
        if (array[r] >= pivot) r--;
    }
    swap(array[start], array[r]);
    return r;
}

int findKthLargest(vector<int>& nums, int k) {
    int target = nums.size() - k;
    int left = 0, right = nums.size() - 1;
    while (true) {
        int tmp = partition(nums, left, right);
        if (tmp == target) return nums[tmp];
        if (tmp < target) left = tmp+1;
        if (tmp > target)  right = tmp-1;
    }
}

TEST_CASE("kth largest element in an array"){
    vector<int> c = {1,2};
    swap(c[0], c[1]);
    REQUIRE( c[0] == 2 );
    vector<int> inc = {1,2,3};
    REQUIRE( partition(inc, 0, 2) == 0 );
    REQUIRE( findKthLargest(inc, 2) == 2 );
}
