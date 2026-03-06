bool checkOnesSegment(string s) {
        int n = s.size();
        int i  = 0;
        int seg = 0;
        bool check = false;
        while(i < n){
            if(s[i] == '1' && check == false){
                check = true;
                seg++;
            }
            else if(s[i] == '0' && check == true){
                check = false;
            }
            i++;
        }
        if(seg == 1)return true;
        return false;
    }
