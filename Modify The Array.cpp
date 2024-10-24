vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int countzero = 0;
        for(int i = 0;i < arr.size();i++){
            if(arr[i] == 0){
                arr.erase(arr.begin()+i);
                countzero++;
                i--;
            }
            else if(i + 1 < arr.size() && arr[i] == arr[i+1]){
                
                arr[i] = 2 * arr[i];
                arr.erase(arr.begin()+i+1);
                countzero++;
            }
        }
        
        for(int i = 0;i < countzero;i++){
            arr.push_back(0);
        }
        
        return arr;
    }
