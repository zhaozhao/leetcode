#include "catch.hpp"

using namespace std;

int getKth(vector<int>::iterator A, int m, vector<int>::iterator B, int n, int k) {
    if (m > n) return getKth(B, n, A, m, k);
    if (m ==0) return B[k-1];
    if (k == 1) return min(A[0], B[0]);

    int i = min(m, k/2);
    int j = min(n, k/2);
    if (A[i-1] > B[j-1]) return getKth(A, m, B+j, n-j, k-j);
    else return getKth(A+i, m-i, B, n, k-i);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int l = ( m + n + 1) / 2 ;
    int r = ( m + n ) / 2 + 1;
    return (getKth(nums1.begin(), m, nums2.begin(), n, l) + getKth(nums1.begin(), m, nums2.begin(), n, r)) / 2.0;
}

TEST_CASE("find median sorted arrays") {
    vector<int> A = {1,3,5};
    vector<int> B = {2,4,6};
    REQUIRE( findMedianSortedArrays(A, B) == 3.5);
}
