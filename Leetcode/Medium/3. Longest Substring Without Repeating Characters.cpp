#include "common.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int best_length = 0;
        int start = 0;
        int best_start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (map.find(s[i]) != map.end())
            {
                if (map[s[i]] < start){
                    map[s[i]] = i;
                    if (i == s.size() - 1 && i - start + 1 > best_length)
                    {
                        return i - start + 1;   // Including current (last) number
                    }
                }
                else
                {
                    int length = i - start;
                    if (length > best_length)
                    {
                        best_length = length;
                        best_start = start;
                    }
                    start = map[s[i]] + 1;
                    map[s[i]] = i;
                }
            }
            else
            {
                map.insert(make_pair(s[i], i));
                if (i == s.size() - 1 && i - start + 1 > best_length)
                {
                    return i - start + 1;   // Including current (last) number
                }
            }
        }
        return best_length;
    }
};