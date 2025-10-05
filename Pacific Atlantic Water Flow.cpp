class Solution {
    int m,n;
    vector<vector<int>>directions = {{0,1},{0,-1},{1,0},{-1,0}};
private:
    void dfs(int r,int c,vector<vector<int>>& heights,vector<vector<bool>>&oceanReachable){
        if(oceanReachable[r][c])return;
        oceanReachable[r][c] = true;

        for(const auto& dir : directions){
           int newRow = r + dir[0];
           int newCol = c + dir[1];

           if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n
           && heights[newRow][newCol] >= heights[r][c]){
            dfs(newRow,newCol,heights,oceanReachable);
           }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      m = heights.size();
      n = heights[0].size();
      vector<vector<bool>>pacificReachable(m,vector<bool>(n,false));  
      vector<vector<bool>>atlanticReachable(m,vector<bool>(n,false));

      for(int i = 0;i < m;i++){
        dfs(i,0,heights,pacificReachable);
      }  

      for(int j = 0;j < n;j++){
        dfs(0,j,heights,pacificReachable);
      }

      for(int i = 0;i < m;i++){
        dfs(i,n-1,heights,atlanticReachable);
      }
      for(int j = 0;j < n;j++){
        dfs(m-1,j,heights,atlanticReachable);
      }

      vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacificReachable[i][j] && atlanticReachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
