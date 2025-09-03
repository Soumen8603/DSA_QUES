int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>&p1,const vector<int>&p2){
            return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];
        });
        int n = points.size();
        int count = 0;
        for(int i = 0;i < n;i++){
            int bottom_right_y = INT_MIN;
            for(int j = i+1;j < n;j++){
                if(points[i][1] >= points[j][1] && points[j][1] > bottom_right_y){
                    count++;
                    bottom_right_y = points[j][1];
                }
            }
        }
        return count;
    }
