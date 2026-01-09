class Solution {
private:
    int memo[21][10001];
    int offset = 5000;
    int solve(vector<int>& rods,int start,int diff){
        if(start == rods.size()){
            return (diff == 0) ? 0 : -1e9;
        }
        if(memo[start][diff + offset] != -1)return memo[start][diff + offset];
        int res = solve(rods,start+1,diff);
        res = max(res,rods[start] + solve(rods,start+1,diff + rods[start]));
        res = max(res,solve(rods,start+1,diff - rods[start]));
        return memo[start][diff+offset] = res;
    }
public:
    int tallestBillboard(vector<int>& rods) {
        memset(memo,-1,sizeof(memo));
        int res = solve(rods,0,0);
        return res < 0 ? 0 : res;
    }
};
