vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool>knowSecret(n,false);
        knowSecret[0] = true;
        knowSecret[firstPerson] = true;
        sort(meetings.begin(),meetings.end(),[](const vector<int>&a,const vector<int>& b){
            return a[2] < b[2];
        });
        int i = 0;
        int m = meetings.size();
        while(i < m){
            int currTime = meetings[i][2];
            map<int,vector<int>>adj;
            set<int>peopleAtTime;
            while(i < m && meetings[i][2] == currTime){
                int u = meetings[i][0];
                int v = meetings[i][1];
                adj[u].push_back(v);
                adj[v].push_back(u);
                peopleAtTime.insert(u);
                peopleAtTime.insert(v);
                i++;

            }
            queue<int>q;
            for(int people :  peopleAtTime){
                if( knowSecret[people]){
                    q.push(people);
                }
            }
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                for(int neighbour : adj[curr]){
                    if(!knowSecret[neighbour]){
                        knowSecret[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }

        vector<int>result;
        for(int i = 0;i < n;i++){
            if(knowSecret[i])result.push_back(i);
        }
        return result;
    }
