 int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int mini = min(height[low], height[high]);
        int miniIndex;

        if (mini == height[low]) {
            miniIndex = low;
        } else {
            miniIndex = high;
        }
        int res = mini * (high - low);
        while (low < high) {
            if (miniIndex == high) {
                high--;
            } else {
                low++;
            }
            mini = min(height[low], height[high]);
            if (mini * (high - low) > res) {
                res = mini * (high - low);
            }
            if (mini == height[low]) {
                miniIndex = low;
            } else {
                miniIndex = high;
            }
        }
        return res;
    }
