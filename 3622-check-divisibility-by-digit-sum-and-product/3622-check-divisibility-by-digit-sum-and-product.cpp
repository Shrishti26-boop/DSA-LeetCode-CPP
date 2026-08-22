class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n, sum = 0, prod = 1;
        while (x) {
            int d = x % 10;
            sum += d;
            prod *= d;
            x /= 10;
        }
        return n % (sum + prod) == 0;
    }
};