bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1)
            return true;
        int furthest = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                int dist = 0;
                if (i + nums[i] < n - 1) {
                    dist = i + nums[i];
                } else {

                    return true;
                }
                furthest = max(furthest, dist);
            } else {
                if (nums[furthest] == 0 && furthest == i) {
                    return false;
                }
            }
        }
        return true;
    }
