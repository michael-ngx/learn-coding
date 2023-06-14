#include "common.h"

/*******************************************************************************************************************************
 * First Attempt - Use Stack (bad time and memory)
 ********************************************************************************************************************************/
class Solution1 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int temp = x;
        stack<int> s;
        while (temp > 0)
        {
            s.push(temp % 10);
            temp /= 10;
        }
        while (!s.empty())
        {
            int digit = x % 10;
            if (s.top() != digit) return false;
            s.pop(); x /= 10;
        }
        return true;;
    }
};

/*******************************************************************************************************************************
 * Second Attempt - Convert to string (beats 56.76% time, 85.38% memory)
 ********************************************************************************************************************************/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        int s = str.size();
        for (int i = 0; i < s/2; i++)
        {
            if (str[i] != str[s - i - 1]) return false;
        }
        return true;
    }
};

/*******************************************************************************************************************************
 * Third Attempt - Use math for half of number (beats 36.97% time, 85.38% memory)
 ********************************************************************************************************************************/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x != 0 && x % 10 == 0) return false;
        int num = 0;
        while (x > num)
        {
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num == x || num/10 == x;
    }
};