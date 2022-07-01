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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 0; i < k; ++i) {
            if (temp == nullptr) {
                return head;
            }
            temp = temp->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* post = nullptr;
        for (int i = 0; i < k; ++i) {
            post = curr->next;
            curr->next = prev;
            prev = curr;
            curr = post;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
