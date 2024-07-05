vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        vector<int>indexvec;
        int prev=head->val;
        int mindist=INT_MAX;
        ListNode* temp=head->next;
        int index=2;
        while(temp->next!=NULL){
            if((temp->val<prev && temp->val<temp->next->val) || (temp->val>prev && temp->val>temp->next->val)){
                indexvec.push_back(index);
            }
            index++;
            prev=temp->val;
            temp=temp->next;
        }
        if(indexvec.size()<2){

            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
      else{
        int n=indexvec.size();
        for(int i=1;i<n;i++){
          mindist=min(mindist,indexvec[i]-indexvec[i-1]);
        }
        int max=indexvec[n-1]-indexvec[0];
        ans.push_back(mindist);
        ans.push_back(max);
        return ans;
      }
    }
