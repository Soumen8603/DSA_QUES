  void reverse(vector<int>& nums,int high,int low){
    while(low < high){
        swap(nums[low],nums[high]);
        low++;
        high--;
    }
   }
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;
        reverse(nums,n-k-1,0);
        reverse(nums,n-1,n-k);
        reverse(nums,n-1,0);
    }
