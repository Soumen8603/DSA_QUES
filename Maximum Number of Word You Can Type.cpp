 int canBeTypedWords(string text, string brokenLetters) {
        vector<bool>check(26,false);
        for(int i = 0;i < brokenLetters.size();i++){
            check[brokenLetters[i] - 'a'] = true;
        }
        bool flag = true;
        int ans = 0;
        for(int i = 0;i < text.size();i++){
            if(text[i] == ' ' && flag == true){
                ans++;
                
            }
            else if(text[i] == ' ' && flag == false){
                flag = true;
            }
            else{
                if(check[text[i] - 'a']){
                    flag = false;
                    int index = i + 1;
                    while(index < text.size() && text[index] != ' '){
                        index++;
                    }
                }
            }

        }
        if(flag == true){
            ans++;
        }
        return ans;
    }
