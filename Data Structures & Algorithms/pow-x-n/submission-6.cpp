class Solution {
public:
    double myPow(double x, int n) {
        int y = abs(n);
        if (n == 0) {
            return 1;
        }
        double result = helper(x, y);
        if (n < 0) {
            return 1.0/ result;
        }
        return result;
    }
    double helper(double x, int n) {
        if (n == 1) {
            return x;
        }
        if (n % 2 == 0) {
            return helper(x, n / 2) * helper(x, n / 2);
        } else {
            return x * helper(x, n / 2) * helper(x, n / 2);
        }
    }
};
