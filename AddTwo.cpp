/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* ret = new ListNode(0, l3);
        bool one;
        while (l1 != nullptr || l2 != nullptr || one) {
            l3->val = ((l1 != nullptr ? l1->val : 0) + (l2 != nullptr ? l2->val : 0)) + (one ? 1 : 0);
            if (l3->val >= 10) {
                one = true;
                l3->val -= 10;
            }
            else one = false;
            l1 = (l1 != nullptr ? l1->next : l1);
            l2 = (l2 != nullptr ? l2->next : l2);
            l3->next = ((l1 != nullptr || l2 != nullptr || one) ? new ListNode() : nullptr);
            l3 = l3->next;
        }
        return ret->next;
    }
};
