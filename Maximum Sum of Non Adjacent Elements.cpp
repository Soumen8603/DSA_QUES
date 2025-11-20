// Memoization Techniques - time - O(n), space - O(n + n)
#include <bits/stdc++.h> 
int solve(vector<int> &nums,int index,vector<int>&dp){
    if(index < 0)return 0;
    if(index == 0)return nums[0];
    if(dp[index] != -1)return dp[index];
    int pick = nums[index] + solve(nums,index-2,dp);
    int nonpick = 0 + (solve(nums,index-1,dp));
    return dp[index] = max(pick,nonpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    
    int n = nums.size();
    vector<int>dp(n,-1);
    return solve(nums,n-1,dp);
}


//Tabulization Method - time - O(n), space - O(n)
#include <bits/stdc++.h> 
int solve(vector<int> &nums,int index,vector<int>&dp){
   dp[0] = nums[0];
   int neg = 0;
   for(int i = 1;i <= index;i++){
       int prev = dp[i-1];
       int prev2;
       if(i-2 >= 0){
           prev2 = dp[i-2];
       }
       else{
           prev2 = 0;
       }
       dp[i] = max(prev2 + nums[i] , prev);
   }
   return dp[index];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    
    int n = nums.size();
    vector<int>dp(n,-1);
    return solve(nums,n-1,dp);
}

//Space Optimization - time - O(n), space - O(1)

#include <bits/stdc++.h> 
int solve(vector<int> &nums,int index){
   int prev = nums[0];
   int prev2 = 0;
   int res;
   for(int i = 1;i <= index;i++){
      int take = nums[i];
      if(i > 1){
          take += prev2;
      }
      
      int nontake = prev;
      prev2 = prev;
      prev = max(take,nontake);
   }
   return prev;
   
   
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    
    int n = nums.size();
    
    return solve(nums,n-1);
}
