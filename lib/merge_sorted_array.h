#pragma once

#include <vector>

using namespace std;

class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        auto end = nums1.end();
        auto i = nums1.begin() + m;
        auto j = nums2.begin() + n;
        while (j > nums2.begin()) {
            if (i == nums1.begin() || *(i - 1) <= *(j - 1)) *--end = *--j;
            else *--end = *--i;
        }
    }
};
