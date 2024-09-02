 int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        
        
        int maxi = INT_MAX;
        
        // Code here
         vector<vector<int>> dist( n , vector<int> (n, maxi));  
        dist[0][0]=grid[0][0];
        
        set<pair<int,pair<int,int>>>st;
        st.insert({grid[0][0],{0,0}});
        
        while(!st.empty()){
            auto it = *(st.begin());
            pair<int,int>node = it.second;
            int dis = it.first;
            st.erase(it);
            
            //For left side traversal
            
            if(node.second - 1 >= 0){
                pair<int,int>adjNode = {node.first,node.second - 1};
                int edgew = grid[node.first][node.second-1];
                
                if(dis + edgew < dist[adjNode.first][adjNode.second]){
                    if(dist[adjNode.first][adjNode.second] != maxi){
                        st.erase({dist[adjNode.first][adjNode.second],{adjNode.first,adjNode.second}});
                        
                    }
                    dist[adjNode.first][adjNode.second] = dis + edgew;
                    st.insert({ dist[adjNode.first][adjNode.second],{adjNode.first,adjNode.second}});
                }
            }
            
            //For right side traversal
             if(node.second + 1 < n){
                pair<int,int>adjNode = {node.first,node.second + 1};
                int edgew = grid[node.first][node.second+1];
                
                if(dis + edgew < dist[adjNode.first][adjNode.second]){
                    if(dist[adjNode.first][adjNode.second] != maxi){
                        st.erase({dist[adjNode.first][adjNode.second],{adjNode.first,adjNode.second}});
                        
                    }
                    dist[adjNode.first][adjNode.second] = dis + edgew;
                    st.insert({ dist[adjNode.first][adjNode.second],{adjNode.first,adjNode.second}});
                }
            }
            
            //For up traversal
            if(node.first - 1 >= 0){
                pair<int,int>adjNode = {node.first - 1,node.second};
                int edgew = grid[node.first - 1][node.second];
                
                if(dis + edgew < dist[adjNode.first][adjNode.second]){
                    if(dist[adjNode.first][adjNode.second] != maxi){
                        st.erase({dist[adjNode.first][adjNode.second],{adjNode.first,adjNode.second}});
                        
                    }
                    dist[adjNode.first][adjNode.second] = dis + edgew;
                    st.insert({ dist[adjNode.first][adjNode.second],{adjNode.first,adjNode.second}});
                }
            }
            
            //For down traversal
            if(node.first + 1 < n){
                pair<int,int>adjNode = {node.first + 1,node.second};
                int edgew = grid[node.first + 1][node.second];
                
                if(dis + edgew < dist[adjNode.first][adjNode.second]){
                    if(dist[adjNode.first][adjNode.second] != maxi){
                        st.erase({dist[adjNode.first][adjNode.second],{adjNode.first,adjNode.second}});
                        
                    }
                    dist[adjNode.first][adjNode.second] = dis + edgew;
                    st.insert({ dist[adjNode.first][adjNode.second],{adjNode.first,adjNode.second}});
                }
            }
            
            
        }
        
        return dist[n-1][n-1];
        
        
    }
