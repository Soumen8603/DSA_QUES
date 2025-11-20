int intersectionSizeTwo(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[0] > b[0]; 
        });
        int end = intervals[0][1];
        int prevend = intervals[0][1] - 1;
        int count = 2;
        for(int i = 1;i < intervals.size();i++){
            if(intervals[i][0] < end && intervals[i][0] <= prevend){
                continue;
            }
            else if(intervals[i][0] <= end && intervals[i][0] > prevend){
                count++;
               prevend = end;
               end = intervals[i][1];
            }
            else{
                count += 2;
                end = intervals[i][1];
                prevend = end - 1;
            }
        }
        return count;
    }
