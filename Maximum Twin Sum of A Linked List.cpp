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
    int pairSum(ListNode* head) {
        ListNode* fast = head, *slow = head;
        ListNode* prev1 = nullptr;
        while (fast && fast->next) {
            prev1 = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev1->next = NULL;
        
        ListNode* prev = nullptr;
        ListNode* next_node = nullptr;
        while (slow) {
            next_node = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next_node;
        }
        ListNode* head1 = prev;
        int ans = INT_MIN;
        while (head && head1) {
            ans = max(ans, (head->val + head1->val));
            head = head->next;
            head1 = head1->next;
        }
        return ans;
    }
};
