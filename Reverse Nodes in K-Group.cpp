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
        int countNodes = 0;
        ListNode* curr = head;
        while(curr != NULL){
            countNodes++;
            curr = curr -> next;
        }
        int turn = countNodes / k;
        int count = 0;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* leftPrev = dummy;
        curr = head;
        ListNode* subHead = head;
        while(count < turn){
            ListNode* preNode = NULL;
            for(int i = 0;i < k;i++){
                ListNode* nextNode = curr -> next;
                curr -> next = preNode;
                preNode = curr;
                curr = nextNode;
            }
            subHead -> next = curr;
            leftPrev -> next = preNode;
            leftPrev = subHead;
            subHead = curr;
            count++;
        }
        return dummy -> next;
    
    }
};
