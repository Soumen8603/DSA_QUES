class Solution {
private:
    int lowerBound(vector<int>& arr,long long target){
        int left = 0,right = arr.size() - 1;
        int ans = arr.size();
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(arr[mid] >= target){
                ans = mid;
                right = mid - 1;
            }
            else{
                left =  mid + 1;
            }
        }
        return ans;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        sort(potions.begin(),potions.end());
        vector<int>res(spells.size());
        for(int i = 0;i < spells.size();i++){
            long long need = (success + spells[i] - 1) / spells[i];
            

            int idx = lowerBound(potions,need);
            res[i] = n - idx;
        }
        return res;
    }
};
