int maxArea(vector<int>& height) {
        int left = 0;
        int n = height.size();
        int right = n -1;
        int maxArea = INT_MIN;
        while(left < right){
            int minHeight = min(height[left],height[right]);
            maxArea = max(maxArea ,minHeight * (right - left));
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;
    }
