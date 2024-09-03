int lcs(string &S1, string &S2) {
    int m = S1.size();
    int n = S2.size();

    // Initializing a matrix of size (m+1)*(n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Building dp[m+1][n+1] in bottom-up fashion
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (S1[i - 1] == S2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // dp[m][n] contains length of LCS for S1[0..m-1]
    // and S2[0..n-1]
    return dp[m][n];
}


	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	   
	    int res = lcs(str1,str2);
	    
	    if(res == str2.length())return str1.length() - res;
	    
	    else{
	        
	        return (str1.length() - res) + (str2.length() - res);
	    }
	    
	} 
