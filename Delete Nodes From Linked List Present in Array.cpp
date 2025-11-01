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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(int i = 0;i < nums.size();i++){
            mp[nums[i]]++;
        }
        ListNode* prev = new ListNode(0);
        prev -> next = head;
        ListNode* currprev = prev;
        ListNode* curr = head;
        while(curr != nullptr){
            if(mp[curr -> val] > 0){
                currprev -> next = curr -> next;
                curr = curr -> next;
            }
            else{
                currprev = curr;
                curr = curr -> next;
            }
        }
        return prev -> next;
    }
};
