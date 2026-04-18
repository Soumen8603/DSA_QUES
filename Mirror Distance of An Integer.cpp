class Solution {
private:
    int reverseDigit(int num){
        aint ans = 0;
        while(num > 0){
            int digit = num % 10;
            ans = ans * 10 + digit;
            num = num / 10;
        }
        return ans;
    }
public:
    int mirrorDistance(int n) {
        return abs(n - reverseDigit(n));
    }
};
