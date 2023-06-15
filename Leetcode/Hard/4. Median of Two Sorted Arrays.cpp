#include "common.h"

// Beats 94% time, 97% memory

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = nums1.size(), size2 = nums2.size();
        int sum = size1 + size2;
        // Edge cases
        if (size1 == 0) return (size2 % 2 == 1) ? nums2[size2 / 2] : (nums2[size2 / 2] + nums2[size2 / 2 - 1]) / 2.0;
        else if (size2 == 0) return (size1 % 2 == 1) ? nums1[size1 / 2] : (nums1[size1 / 2] + nums1[size1 / 2 - 1]) / 2.0;
        
        int i = 0, j = 0;
        bool at_1 = true;
        while ( (i + j) < (sum / 2) )
        {
            if (i == size1)
            {
                j++; at_1 = false;
            }
            else if (j == size2)
            {
                i++; at_1 = true;
            }
            else
            {
                if (nums1[i] < nums2[j]) { i++; at_1 = true; }
                else { j++; at_1 = false; }
            }
        }

        int next;
        if (i == size1)
        {
            next = nums2[j];
        }
        else if (j == size2)
        {
            next = nums1[i];
        }
        else
        {
            if (nums1[i] < nums2[j]) { next = nums1[i]; }
            else { next = nums2[j]; }
        }

        if (sum % 2 == 1)
        {
            return next;
        }
        else
        {
            if (at_1) return (next + nums1[i - 1]) / 2.0;
            else return (next + nums2[j - 1]) / 2.0;
        }
    }
};