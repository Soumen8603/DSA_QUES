vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        vector<int>ans(2);
        int high = numbers.size() - 1;
        while(low < high){
            if(numbers[low] + numbers[high] > target){
                high--;

            }
            else if(numbers[low] + numbers[high] < target){
                low++;
            }
            else if(numbers[low] + numbers[high] == target){
                ans[0] = low + 1;
                ans[1] = high + 1;
                break;
            }
        }
        return ans;
    }
