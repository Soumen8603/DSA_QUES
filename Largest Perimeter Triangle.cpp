int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int first = 0;
        int second = 1;
        int third = 2;
        int n = nums.size();
        int maxi = 0;
        while (third < n) {
            if (nums[second] + nums[third] > nums[first]) {
                maxi = nums[first] + nums[second] + nums[third];
                break;
            }
            third++;
            second++;
            first++;
        }
        return maxi;
    }
