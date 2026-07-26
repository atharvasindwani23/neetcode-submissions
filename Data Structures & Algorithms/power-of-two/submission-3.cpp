class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) {
            return false;
        }
        int log = log2(n);

        return (pow(2, log) == n);
    }
};