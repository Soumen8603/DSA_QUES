int minAddToMakeValid(string s) {
        stack<char>st;
        int step = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')' && (!st.empty())){
                st.pop();
            }
            else{
                step++;
            }
        }

        return (step+st.size());
    }
