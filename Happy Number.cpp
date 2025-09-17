 bool isHappy(int n) {
       unordered_map<int,int>mp;
       int num = n;
       while(mp.find(num) == mp.end()){
            mp[num]++;

            int newNum = 0;
            while(num != 0){
                newNum += pow((num % 10),2);
                num = num / 10;
            }

            if(newNum == 1)return true;
            num = newNum;
       }
       return false; 
    }
