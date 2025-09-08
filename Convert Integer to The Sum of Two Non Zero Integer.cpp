class Solution {
private:
    bool isNoZero(int num) {
        // check if number contains digit '0'
        while (num > 0) {
            if (num % 10 == 0)
                return false;
            num /= 10;
        }
        return true;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n / 2;
        int b = n - a;

        // adjust until both are No-Zero
        while (!isNoZero(a) || !isNoZero(b)) {
            a++;
            b = n - a;
        }

        return {a, b};
    }
};
