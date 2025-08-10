class Solution {
private:
    unordered_map<int, int> convertmap(int n) {
        unordered_map<int, int> ans;
        while (n != 0) {
            int number = n % 10;
            ans[number]++;
            n = n / 10;
        }
        return ans;
    }

public:
    bool reorderedPowerOf2(int n) {
        if ((n & (n - 1)) == 0) {
            return true;
        } else {
            unordered_map<int, int> mp;
            vector<int> num;
            int count = 0;
            while (n != 0) {
                int number = n % 10;
                mp[number]++;
                count++;
                num.push_back(number);
                n = n / 10;
            }
            sort(num.begin(), num.end());
            int small = 0;
            int big = 0;
            int flag = 0;
            if (num[0] == 0) {
                // Find first non-zero digit
                int firstNonZero = 1;
                while (firstNonZero < num.size() && num[firstNonZero] == 0) {
                    firstNonZero++;
                }
                // Swap it to front
                swap(num[0], num[firstNonZero]);
            }
            for (int d : num) {
                small = small * 10 + d;
            }

            int n = num.size();
            for (int i = n - 1; i >= 0; i--) {
                big = (big * 10) + num[i];
            }

            for (int i = 0; i <= 30; i++) {
                int num = pow(2, i);
                if (num < small)
                    continue;
                if (num > big) {
                    return false;
                }
                unordered_map<int, int> mp1 = convertmap(num);
                if (mp1 == mp)
                    return true;
            }
        }
        return false;
    }
};
