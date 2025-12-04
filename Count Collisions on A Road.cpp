int countCollisions(string directions) {
        int n = directions.size();
        if(directions.length() == 1)return 0;
        int count = 0;
        int left = 0,right = n-1;
        
            while(left < n && directions[left] == 'L'){
                left++;
            }
            while(right >= 0 && directions[right] == 'R'){
                right --;
            }
            for(int i = left;i <= right;i++){
                if(directions[i] != 'S'){
                    count++;
                }
            }
        return count;
    }
