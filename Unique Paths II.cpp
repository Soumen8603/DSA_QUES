// Memoization
int solve(int n,int m,vector< vector< int> > &mat,vector<vector<int>>&dp){
    int mod = 1e9 + 7;
    if(n >= 0 && m >= 0 && mat[n][m] == -1)return 0;
    if(n == 0 && m == 0)return 1;
    if(n < 0 || m < 0)return 0;
    if(dp[n][m] != -1)return dp[n][m];
    int left = solve(n,m-1,mat,dp);
    int up = solve(n-1,m,mat,dp);
    return dp[n][m] = (left + up) % mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code her
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,mat,dp);
}
// Tabulation
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int mod = 1e9 + 7;
    for(int i = 0;i < n;i++){
        
        for(int j = 0;j < m;j++){
            if(mat[i][j] == -1)dp[i][j] = 0;
            else if(i == 0 && j == 0)dp[i][j] = 1;
            else{
                int up = 0,left = 0;
                if(i > 0){
                 up = dp[i-1][j];
                }
                if(j > 0){
                    left = dp[i][j-1];
                }
                dp[i][j] = (up + left) % mod;
            }
        }
        
    }
    return dp[n-1][m-1];
}
