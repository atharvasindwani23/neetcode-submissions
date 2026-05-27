class Solution {
public:
    double myPow(double x, int n) {
        int y = abs(n);
        double res = mathHelper(x, y);
        if (n < 0) {
            return 1.0 / res;
        }
        return res;
    }

    double mathHelper(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n % 2 == 0) {
            double half = mathHelper(x, n / 2);
            return half * half;
        } else {
            double half = mathHelper(x, n / 2);
            return x * half * half;
        }
    }
};
