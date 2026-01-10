class Solution {
private:
    void solve(int open,int close,string& curr,int si,vector<string>&ans){
    if(curr.size() == si){
        ans.push_back(curr);
        return;
    }
        if(close < open)return;
        if(open > 0){
            curr += '(';
            open--;
            solve(open,close,curr,si,ans);
            curr.pop_back();
            open++;
        }
        if(close > 0){
            curr += ')';
            close--;
            solve(open,close,curr,si,ans);
            curr.pop_back();
            close++;
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        int count = 0;
         int open = n;
         int close = n;
         string curr = "";
         vector<string>ans;
         solve(open,close,curr,2*n,ans);
         return ans;
    }
};
