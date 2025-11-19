class Solution {
    bool hasCycle(int node,vector<vector<int>>&adjList,vector<int>&state){
        state[node] = 1;
        for(int neighbour : adjList[node]){
            if(state[neighbour] == 1){
                return true;
            }
            if(state[neighbour] == 0){
                if(hasCycle(neighbour,adjList,state)){
                    return true;
                }
            }
        }
        state[node] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjList(numCourses);
        for(const auto &p : prerequisites){
            adjList[p[1]].push_back(p[0]);
        }
        vector<int>state(numCourses,0);
        for(int i = 0;i < numCourses;i++){
            if(state[i]==0){
                if(hasCycle(i,adjList,state)){
                    return false;
                }
            }
        }
        return true;
    }
};
