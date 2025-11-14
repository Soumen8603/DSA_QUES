vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        vector<vector<int>>diff(n+1,vector<int>(n+1,0));
        int m = queries.size();
        for(int i = 0;i < m;i++){
            int startR = queries[i][0],startC = queries[i][1];
            int endR = queries[i][2],endC = queries[i][3];
            diff[startR][startC]++;
            diff[endR + 1][startC]--;
            diff[startR][endC+1]--;
            diff[endR+1][endC+1]++;
        }
        for(int i = 0;i < n+1;i++){
            for(int j = 1;j < n+1;j++){
                diff[i][j] += diff[i][j-1];
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 1;j < n;j++){
                diff[j][i] += diff[j-1][i];
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                mat[i][j] += diff[i][j];
            }
        }
        return mat;
    }
