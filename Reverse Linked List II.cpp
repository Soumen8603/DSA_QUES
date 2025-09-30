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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);

        dummy -> next = head;
        ListNode* leftprev = dummy;
        ListNode* curr = head;

        for(int i = 0;i < left - 1;i++){
            leftprev = leftprev -> next;
            curr = curr -> next;
        }

        ListNode* pre = NULL;
        ListNode* subhead = curr;
        for(int i = 0;i <= right - left;i++){
            ListNode* nextNode = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = nextNode;
        }

        leftprev -> next = pre;
        subhead -> next = curr;
        return dummy -> next;
    }
};
