class Solution {
private:
    bool isanagram(string s1,string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1==s2)return true;
        return false;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<bool>check(n,true);
        for(int i = 1;i < n;i++){
            if(isanagram(words[i],words[i-1]))check[i] = false;
        }
        for(int i = words.size() - 1;i >= 0;i--){
            if(check[i] == false){
                words.erase(words.begin()+i);
            }
        }
        return words;
    }
};
