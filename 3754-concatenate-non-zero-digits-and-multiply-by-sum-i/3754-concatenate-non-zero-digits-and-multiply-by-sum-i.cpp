class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        long long multiplier = 1; // Tracks the place value from right to left

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit != 0) {
                sum += digit;
                x = digit * multiplier + x; // Place the digit at the correct left-most position
                multiplier *= 10;           // Shift position for the next non-zero digit
            }
        }
        
        return x * sum;
    }
};
