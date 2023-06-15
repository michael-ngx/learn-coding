#include "common.h"

/*******************************************************************************************************************************
 * First Attempt - Expand on 2 sides (start expand if bb or bab)(optimized in second attempt)
 * Beats 83.41% time, 88.75% memory
 ********************************************************************************************************************************/
class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        int start = -1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                int space = 1;
                while (i - 1 - space >= 0 && i + space < s.size() && s[i - 1 - space] == s[i + space])
                {
                    space++;
                }
                int length = 2 + (space - 1) * 2;
                if (length > longest)
                {
                    longest = length;
                    start = i - space;
                }
            }
            if (i > 1 && s[i] == s[i - 2])
            {
                int space = 1;
                while (i - 2 - space >= 0 && i + space < s.size() && s[i - 2 - space] == s[i + space])
                {
                    space++;
                }
                int length = 3 + (space - 1) * 2;
                if (length > longest)
                {
                    longest = length;
                    start = i - space - 1;
                }
            }
        }
        if (start == -1)
        {
            string str1(1, s[0]);
            return str1;
        }
        return s.substr(start, longest);
    }
};

/*******************************************************************************************************************************
 * Smart Attempt - Expand on 2 sides
 * Beats 98.59% time, 68.35% memory
 ********************************************************************************************************************************/
class Solution {
public:
    string longestPalindrome(string s) {
        int start, end;
        int p = 0, subStart = 0;
        int maxLen = 0;
        while(p < s.size()) {
            start = p, end = p;
            //***** Move "end" to skip all similar char <start>bbbb....bbb<end>
            while(s[end+1] == s[end]) end++;
            p = end + 1;
            //***** Now expand 2 sides and check palindrome as normal
            while(start > 0 && s[end + 1] == s[start - 1]) {
                start--;
                end++;
            }
            if ((end - start + 1) > maxLen) {
                maxLen = end - start + 1;
                subStart = start;
            }
        }
        return s.substr(subStart, maxLen);
    }
};