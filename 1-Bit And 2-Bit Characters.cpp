 bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
       for(int i = 0;i < bits.size();i++){
        if(bits[i] == 1){
            if(i + 1 == n-1){
                return false;
            }
            i++;
        }
       }
       return true;
    }
