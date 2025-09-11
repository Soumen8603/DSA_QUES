class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
           return true;
        } else {
            return false;
        }
    }
    string sortVowels(string s) {
        vector<char> vowels;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if(isVowel(s[i])){
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        string ans=s;
        int count = 0;
        for(int i = 0;i < n;i++){
            if(isVowel(s[i])){
                ans[i] = vowels[count];
                count++;
            }
            else{
                ans[i] = s[i];
            }
        }
        return ans;
    }
};
