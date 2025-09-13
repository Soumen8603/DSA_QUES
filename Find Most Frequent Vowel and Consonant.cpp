class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        else{
            return false;
        }
    }
    int maxFreqSum(string s) {
        vector<int>letters(26,0);
        int maxVow = 0,maxCon = 0;
        for(int i = 0;i < s.size();i++){
            int index = s[i] - 'a';
            letters[index]++;
            if(isVowel(s[i]) &&  letters[index] > maxVow){
                maxVow = letters[index];
            }
            else if(!isVowel(s[i]) &&  letters[index] > maxCon){
                 maxCon = letters[index];;
            }
        }
        return maxVow +  maxCon;
    }
};
