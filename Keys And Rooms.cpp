 bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visited(n,false);
        stack<int>st;
        st.push(0);
        visited[0] = true;
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            for(int i = 0;i < rooms[curr].size();i++){
                if(!visited[rooms[curr][i]]){
                    st.push(rooms[curr][i]);
                    visited[rooms[curr][i]] = true;
                }
            }
        }
        for(int i = 0;i < n;i++){
            if(visited[i] == false){
                return false;
            }
        }
        return true;
    }
