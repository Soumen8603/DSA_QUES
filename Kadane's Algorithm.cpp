int maxSubarraySum(vector<int> &arr) {
        // code here...
        int n = arr.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += arr[i];
            maxi = max(sum,maxi);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
