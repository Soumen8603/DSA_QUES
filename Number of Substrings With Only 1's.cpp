class Solution {
public:
int mod = 1e9+7;
    int numSub(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0;i < n;i++){
            if(s[i] == '1'){
                long long count = 0;
                int j = i;
                while(j < n && s[j] == '1'){
                    count++;
                    j++;
                }
               long long total = (count * (count + 1)) / 2;
               ans = (ans + total % mod) % mod;
                i=j-1;
            }
        }
        return (int)ans;
    }
};
