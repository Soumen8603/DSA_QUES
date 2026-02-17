// Memoization
#include <bits/stdc++.h> 
bool solve(int index,int n,int total,vector<int>&arr, vector<vector<int>>&dp){
    
        if(total == 0){
            return true;
        }
        if(index == n)return false;

    
    
    if(dp[index][total] != -1)return dp[index][total];
    bool take = false;
    if(arr[index] <= total){
     take = solve(index+1,n,total - arr[index],arr,dp);
    }
    bool notTake =  solve(index+1,n,total,arr,dp);
    return dp[index][total] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(0,n,k,arr,dp);
}

// Tabulation

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
    for(int i = 0;i < n;i++)dp[i][0] = true;
    dp[0][arr[0]] = true;
    for(int index = 1;index < n;index++){
        for(int target = 1;target <= k;target++){
            
            bool take = false;
            if(arr[index] <= target){
                take = dp[index-1][target - arr[index]];
            }
            bool notTake =  dp[index-1][target];
            dp[index][target] = take || notTake;
        }
    }
    return dp[n-1][k];
}
