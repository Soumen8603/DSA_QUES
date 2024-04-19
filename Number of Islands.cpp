void DFS(vector<vector<char> >& M, int i, int j, int ROW,
         int COL)
{
    // Base condition
    // if i less than 0 or j less than 0 or i greater than
    // ROW-1 or j greater than COL-  or if M[i][j] != 1 then
    // we will simply return
    if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1)
        || M[i][j] != '1') {
        return;
    }
 
    if (M[i][j] == '1') {
        M[i][j] = '0';
        DFS(M, i + 1, j, ROW, COL); // right side traversal
        DFS(M, i - 1, j, ROW, COL); // left side traversal
        DFS(M, i, j + 1, ROW, COL); // upward side traversal
        DFS(M, i, j - 1, ROW,COL); // downward side traversal
        
    }
}
  int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int ans=0;
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    DFS(grid,i,j,row,col);
                    ans++;
                }
            }
        }
        return ans;
    }
