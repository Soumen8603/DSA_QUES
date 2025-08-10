class Solution {
private:
    // Function to compute digit frequency map for a number
    array<int, 10> digitCount(int n) {
        array<int, 10> count = {0};
        while (n > 0) {
            count[n % 10]++;
            n /= 10;
        }
        return count;
    }
public:
    bool reorderedPowerOf2(int n) {
         // Digit frequency of the given number
        array<int, 10> target = digitCount(n);

        // Compare with every power of 2 up to 2^30
        for (int i = 0; i <= 30; i++) {
            if (digitCount(1 << i) == target) {
                return true;
            }
        }
        return false;
    }
};
