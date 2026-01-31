 char nextGreatestLetter(vector<char>& letters, char target) {
        bool check = false;
        char ans;
        for(int i = 0;i  < letters.size();i++){
            if(letters[i] - target > 0){
                ans = letters[i];
                check = true;
                break;
            }
        }
        if(check == false)return letters[0];
        return ans;
    }
