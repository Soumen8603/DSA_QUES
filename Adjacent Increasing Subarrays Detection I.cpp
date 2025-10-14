class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<pair<int, int>> index;
        int start = 0, end = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                end = i;
            } else {
                index.push_back({start, end});
                start = i;
                end = i;
            }
        }
        index.push_back({start, end});
        int n = index.size();
        for (int i = 0; i < n; i++) {
            int fi = index[i].first;
            int sec = index[i].second;
            if (sec - fi + 1 >= (2 * k)) {
                return true;
            } else {
                if (i < n - 1) {
                    int ffi = index[i + 1].first;
                    int ffs = index[i + 1].second;
                    if (sec - fi + 1 >= k && ffs - ffi + 1 >= k) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
