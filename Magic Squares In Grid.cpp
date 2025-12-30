class Solution {
    private:
    bool rowSumCheck(int row,int col,vector<vector<int>>& grid){
        unordered_map<int,int>mp;
        for(int i = row;i < row + 3;i++){
            int sum = 0;
            for(int j = col;j < col + 3;j++){
                if(mp[grid[i][j]] > 0 || grid[i][j] > 9)return false;
                mp[grid[i][j]]++;
                sum += grid[i][j];
            }
            if(sum != 15)return false;
        }
        return true;
    }
    bool colSumCheck(int row,int col,vector<vector<int>>& grid){
        for(int i = col;i < col + 3;i++){
            int sum = 0;
            for(int j = row;j < row + 3;j++){
                sum += grid[j][i];
            }
            if(sum != 15)return false;
        }
        return true;
    }
    bool diagonalCheck(int row,int col,vector<vector<int>>& grid){
        //diagonal check
        if(grid[row][col] + grid[row+1][col+1]+grid[row+2][col+2] != 15)return false;
        if(grid[row+2][col] + grid[row+1][col+1] + grid[row][col+2] != 15)return false;
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int ans = 0;
        for(int i = 0;i <= m -3;i++){
            for(int j = 0;j <= n-3;j++){
                if(rowSumCheck(i,j,grid) && colSumCheck(i,j,grid) && diagonalCheck(i,j,grid)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
