vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>ans;
        stack<int>st;
        int n=positions.size();
        vector<int>ids;
        for(int i=0;i<n;i++){
            ids.push_back(i);
        }
        auto compare = [&](int id1,int id2){
            return positions[id1]<=positions[id2];
        };
        sort(ids.begin(),ids.end(),compare);
        for(auto it:ids){
            if(directions[it]=='R'){
                st.push(it);
            }
            else{
                while(!st.empty() && healths[it]>0){
                    if(healths[st.top()] > healths[it]){
                        healths[st.top()]--;
                        healths[it]=0;
                    }
                    else if(healths[it] > healths[st.top()]){
                        healths[it]--;
                        healths[st.top()]=0;
                        st.pop();
                    }
                    else{
                        healths[it]=0;
                        healths[st.top()]=0;
                        st.pop();
                    }
                }
            }
        }
        for(auto it:healths){
            if(it>0){
                ans.push_back(it);
            }
        }
        return ans;
    }
