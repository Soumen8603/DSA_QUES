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
private:
    ListNode* getMid(ListNode* head){
        ListNode* fast = head -> next;
        ListNode* slow = head;
        while(fast && fast-> next){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(head1 && head2){
            if(head1 -> val < head2 -> val){
                curr -> next = head1;
                head1 = head1 -> next;
            }
            else{
                curr -> next = head2;
                head2 = head2 -> next;
            }
            curr = curr->next;
        }
        if(head1)curr -> next = head1;
        if(head2)curr -> next = head2;
       
        
        return dummy -> next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next)return head;
        ListNode* mid = getMid(head);
        ListNode* left = head;
        ListNode* right = mid -> next;
        mid -> next = nullptr;
        left = sortList(left);
        right = sortList(right);
        return merge(left,right);
    }
};
