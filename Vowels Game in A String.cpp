class Solution {
private:
bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        else{
            return false;
        }
}
public:
    
    bool doesAliceWin(string s) {
        int n = s.size();
        int vowelCount = 0;
        for(int i = 0;i < n;i++){
            if(isVowel(s[i])){
                vowelCount++;
            }
        }
        if(vowelCount == 0)return false;
        else return true;

    }
};
