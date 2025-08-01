vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        int index = 1;
        vector<int>prev(1);
        vector<int>curr(1);
        while(index < numRows){
            curr.clear();
            curr.resize(index+1);
            int elements = 0;
            curr[0] = 1;
            elements++;
            int n = curr.size();
            curr[index] = 1;
            elements++;
            for(int i = 0;i < n-1 && elements < n;i++){
                curr[elements - 1] = prev[i]+prev[i+1];
                elements++;

            }
            ans.push_back(curr);
            prev.clear();
            prev.resize(index+1);
            prev = curr;
            index++;
        }

    return ans;
    }
