 bool isPalindrome(string s) {
        string input = "";
        for(int i = 0;i < s.size();i++){
            if(isalnum(s[i])){
                char ch;
                if(isupper(s[i])){
                    ch = (s[i] - 'A') + 'a';
                }
                else{
                    ch = s[i];
                }
                input += ch;
            }
        }
        string check = input;
        reverse(input.begin(),input.end());
        if(check == input){
            return true;
        }
        else{
            return false;
        }
    }
