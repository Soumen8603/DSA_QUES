 int minOperations(vector<string>& logs) {
        int depth=0;
        
        int n=logs.size();
        for(int i=0;i<n;i++){
            if(logs[i]=="../"){
                if(depth>0){
                depth--;
                }
            }
            else if(logs[i]=="./"){
                depth=depth;
            }
            else{
                depth++;
            }

        }
        return depth;

    }
