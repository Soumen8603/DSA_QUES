int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<>());
        int total = 0;
        for(int i = 0;i < apple.size();i++){
            total += apple[i];
        }

        int totalCapacity = 0;
        int ans = -1;
        for(int i = 0;i < capacity.size();i++){
            totalCapacity += capacity[i];
            if(totalCapacity >= total){
                ans =  i - 0 + 1;
                break;
            }
        }
        return ans;
    }
