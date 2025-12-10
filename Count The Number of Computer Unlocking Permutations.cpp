class Solution {
private:
    int factorial(int n) {
        int MOD = 1e9 + 7;
        int ans = 1;
        for (int i = n; i >= 1; i--) {
          ans = (int)(((long long)ans * i) % MOD);
        }
        return ans;
    }

public:
    int countPermutations(vector<int>& complexity) {
        int mini = complexity[0];
        int n = complexity.size();
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= mini) {
                return 0;
            }
        }
        int ans = factorial(n - 1);
        return ans;
    }
};
