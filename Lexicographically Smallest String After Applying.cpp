class Solution {
   string ans; 
private:
    string add(string s,int a){
        string ans;
        for(int i = 0;i < s.size();i++){
            if(i % 2 == 1){
                ans += (s[i] - '0' + a) % 10 + '0';
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
    string rotate(string s,int b){
        int n = s.size();
        string ans;
        ans += s.substr(n-b);
        ans += s.substr(0,n-b);
        return ans;
    }
    void dfs(string s,int a,int b,set<string>&v){
        if(v.find(s) != v.end())return;
        v.insert(s);
        ans = min(ans,s);
        dfs(add(s,a),a,b,v);
        dfs(rotate(s,b),a,b,v);
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        ans=s;
        set<string>v;
        dfs(s,a,b,v);
        return ans;

    }
};
