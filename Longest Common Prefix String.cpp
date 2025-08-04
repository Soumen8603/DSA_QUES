string longestCommonPrefix(vector<string>& strs) {
        string prev = strs[0];
        if(strs.size() == 1){
            return strs[0];
        }
        string ans;
        for(int i = 1;i < strs.size();i++){
            ans = "";
            string check = strs[i];
            for(int j = 0;j < prev.size() && j < check.size();j++){
                if(prev[j] == check[j]){
                    ans += prev[j];
                }
                else{
                    break;
                }
            }
            prev = ans;

        }
        return prev;
    }
