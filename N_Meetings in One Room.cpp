 static bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>>v;
        
        for(int i = 0;i < n;i++){
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end(),myComparison);
        
        int count = 1;
        
        
        int endTime = v[0].second;
        
        for(int i = 1;i < v.size();i++){
            if(v[i].first > endTime){
                count++;
                endTime = v[i].second;
            }
        }
        return count;
        
        
    }
