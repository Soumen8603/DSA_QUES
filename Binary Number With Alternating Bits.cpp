bool hasAlternatingBits(int n) {
        bool firstOne = false;
        int prev = -1;
        for(int i = 31;i >= 0;i--){
            int bit = (n >> i) & 1;
            if(firstOne == true){
                if(bit == prev)return false;
                prev = bit;
            }
            else if(bit == 1 && firstOne == false){
                firstOne = true;
                prev = 1;
            }
        }
        return true;
    }
