vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;
        vector<int>ans;
       
        int rightlimit = n;
        int leftlimit = 0;
        int downlimit = m;
        int upperlimit = 0;
        while(ans.size() < total){
            //iterate right;
             int col = leftlimit;
             int row = upperlimit;
             while(col < rightlimit && ans.size() < total){
                ans.push_back(matrix[row][col]);
                col++;
             }
             rightlimit--;

             //iterate downwards

             col = col - 1;
             row = row + 1;
             while(row < downlimit && ans.size() < total){
                ans.push_back(matrix[row][col]);
                row++;
             }
             downlimit--;

             //iterate left
             row = row - 1;
             col = col - 1;
             while(col >= leftlimit && ans.size() < total){
                ans.push_back(matrix[row][col]);
                col--;
             }
             leftlimit++;

            //iterate upwards
             col = col + 1;
             row = row - 1;
             while(row > upperlimit && ans.size() < total){
                ans.push_back(matrix[row][col]);
                row--;
             }
             upperlimit++;
        }
        return ans;
    }
