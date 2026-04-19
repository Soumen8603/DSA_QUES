 int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;int right = 0;
        int ans = 0;
        while(left < m && right < n){
            while(right < n && nums1[left] <= nums2[right]){
                right++;
            }
            ans = max(ans,right-left-1);
            left++;
        }
        return ans;
    }
