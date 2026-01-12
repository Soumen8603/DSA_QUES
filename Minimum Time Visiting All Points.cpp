int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int prevX = points[0][0];
        int prevY = points[0][1];
        int ans = 0;
        for(int i = 1;i < points.size();i++){
            int minDist = min(abs(points[i][0] - prevX),abs(points[i][1] - prevY));
            ans += minDist;
            ans = ans + (abs(points[i][0] - prevX) - minDist) + (abs(points[i][1] - prevY) - minDist);
            prevX = points[i][0];
            prevY = points[i][1];
        }
        return ans;
    }
