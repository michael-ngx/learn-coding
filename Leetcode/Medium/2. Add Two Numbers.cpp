#include "common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int du = 0;
        int val = l1->val + l2->val;
        du = (val >= 10) ? 1 : 0;
        val = val % 10;
        ListNode* l3 = new ListNode(val);
        ListNode* on3 = l3;
        l1 = l1->next;
        l2 = l2->next;

        while(l1 != nullptr || l2 != nullptr)
        {
            int val = du;
            if (l1 != nullptr)
            {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                val += l2->val;
                l2 = l2->next;
            }
            
            du = (val >= 10) ? 1 : 0;
            val = val % 10;

            on3->next = new ListNode(val);
            on3 = on3->next;
        }
        if (du == 1) on3->next = new ListNode(1);

        return l3;
    }
};