#include "common.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                ss.push(c);
            }
            else
            {
                if (ss.empty()) return false;
                if (c == ')' && ss.top() == '(' ||
                    c == ']' && ss.top() == '[' ||
                    c == '}' && ss.top() == '{')
                {
                    ss.pop();
                }
                else return false;
            }
        }
        return ss.empty();
    }
};