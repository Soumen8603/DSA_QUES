 bool ispar(string x)
    {
        // Your code here
        int n = x.size();
        
        stack<char>st;
        
        for(int i = 0;i < n;i++){
            if(x[i] == '(' || x[i] == '{' || x[i] == '['){
                st.push(x[i]);
            }
            else{
                if(st.empty())return false;
                char c = st.top();
                if((c == '(' && x[i] == ')') || (c == '{' && x[i] == '}') || (c == '[' && x[i] == ']')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        return st.empty();
    }
