string simplifyPath(string path) {
        stringstream ss(path);
        char delimiter = '/';
        string token;
        stack<string>st;
        while(getline(ss,token,delimiter)){
            if(token == "" || token == "."){
                continue;
            }
            else if(token == ".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(token);
            }
        }
        if(st.empty()){
            return "/";
        }

        string result="";
        while(!st.empty()){
            result = "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
