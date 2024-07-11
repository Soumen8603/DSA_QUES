string reverseParentheses(string s) {
        int n=s.size();
        stack<char>st;
         for(int i=0;i<n;i++){
            if(s[i]==')'){
                string si;
                while(st.top()!='('){
                    si+=st.top();
                    st.pop();
                }
                st.pop();
                for(int j=0;j<si.size();j++){
                    st.push(si[j]);
                }
            }
            else{
                st.push(s[i]);
            }
         }
         string ans;
         while(!st.empty()){
            ans+=st.top();
            st.pop();
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
