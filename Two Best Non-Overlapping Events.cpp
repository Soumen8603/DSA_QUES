class Solution {
private:
    int binary_search(vector<vector<int>>& events,int end){
        int low = 0;
        int high = events.size() - 1;
        int result = events.size();
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(events[mid][0] > end){
                result =  mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return result;
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<int>dp(n,-1);
        sort(events.begin(),events.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0] < b[0];
        });
        dp[n-1] = events[n-1][2];
        for(int i = n-2;i >= 0;i--){
            dp[i] = max(dp[i+1],events[i][2]);
        }
        int ans = INT_MIN;
        for(int i = 0;i < n;i++){
            int endTime = events[i][1];
            int currProfit = events[i][2];
            ans = max(ans,currProfit);
            int next = binary_search(events , endTime);
            if(next < n){
                ans = max(ans,currProfit + dp[next]);
            }
        }
        return ans;

    }
};

// Line sweep Algorithm

int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int max_val = 0;
        int ans = 0;
        for(auto& e : events){
            int start = e[0];
            int end = e[1];
            int val = e[2];
            while(!pq.empty() && pq.top().first < start){
                max_val = max(max_val,pq.top().second);
                pq.pop();
            }
            ans = max(ans,val + max_val);
            pq.push({end,val});
        }
        return ans;
    }
