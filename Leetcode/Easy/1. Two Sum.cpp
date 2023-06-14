#include "common.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> solution(2);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            bool found = false;
            for (int j = i + 1; j < nums.size() && !found; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    solution[0] = i; solution[1] = j;
                    found = true;
                }
            }
        }
        return solution;
    }
};