 int minNumberOperations(vector<int>& target) {
        int operations = target[0];
        for(int i = 1;i < target.size();i++){

            int diff = target[i] - target[i-1];
            if(diff > 0){
                operations += diff;
            }
        }
        return operations;
    }
