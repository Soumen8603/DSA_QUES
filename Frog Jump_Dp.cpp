//1. O(n) time complexity and O(n) space complexity
int frogJump(int n, vector<int> &heights)
{
   if(n == 1)return 0;
    // Write your code here.
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(heights[1] - heights[0]);

    if(n == 2){
        return dp[2];
    }
    dp[3] = min(dp[2] + abs(heights[2] - heights[1]), abs(heights[2] - heights[0]));
    if(n == 3){
        return dp[3];
    }
    for(int i = 4;i <= n;i++){
        dp[i] = min(dp[i-1] + abs(heights[i-1]-heights[i-2]),dp[i-2] + abs(heights[i-1] - heights[i-3]));
    }
    return dp[n];
}
//2. O(n) time complexity and O(1) space complexity
int frogJump(int n, vector<int> &heights)
{
   if(n == 1)return 0;
    // Write your code here.
    int firstprev = 0;
    int secondprev = 0;
    firstprev = abs(heights[1] - heights[0]);

    if(n == 2){
       return firstprev;
    }
    int temp = firstprev;
    secondprev = temp;
    firstprev = min(firstprev + abs(heights[2] - heights[1]),abs(heights[2]-heights[0]));
    if(n == 3){
        firstprev;
    }
    for(int i = 4;i <= n;i++){
       temp = firstprev;
       firstprev = min(temp + abs(heights[i-1] - heights[i-2]),secondprev + abs(heights[i-1] - heights[i-3]));
       secondprev = temp;
    }
    return firstprev;
}
