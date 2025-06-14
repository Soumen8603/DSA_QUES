int minMaxDifference(int num) {
       string number = to_string(num);
      char st1;
      for(int i = 0;i < number.size();i++){
        if(number[i] != '9'){
            st1 = number[i];
            break;
        }
      }

      char st = number[0];
       string maxi,mini;
       for(int i = 0;i < number.size();i++){
        if(number[i] == st1){
            maxi[i] = '9';
        }
        else{
            maxi[i] = number[i];
        }
       }

       for(int i = 0;i < number.size();i++){
        if(number[i] == st){
            mini[i] = '0';
        }
        else{
            mini[i] = number[i];
        }
       }

       int maxii = stoi(maxi);
       int minii = stoi(mini);
       return maxii - minii;
    }
