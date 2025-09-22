class Solution {
    string makestring(int start,int end){
        string s="";
        if(start == end){
            s += to_string(start);
            return s;
        }
        else{
            s += to_string(start);
            s += '-';
            s += '>';
            s += to_string(end);
            return s;
        }
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0){
            return ans;
        }
        int start = -1;
        int end;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                start = nums[i];
                end = nums[i];
                continue;
            }

            if(nums[i] == end + 1){
                end = nums[i];
            }
            else{
                string s = makestring(start,end);
                ans.push_back(s);
                start = nums[i];
                end = nums[i];
            }
        }
        string s = makestring(start,end);
        ans.push_back(s);
        return ans;
    }
};
