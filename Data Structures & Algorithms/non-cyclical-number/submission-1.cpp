class Solution {
public:
    bool isHappy(int n) {
        map<int,bool> seen;
        seen[n] = true;
        while (n != 1) {
            cout << n << endl;
            n = helper(n);
            if (seen.count(n)) {
                return false;
            }
            seen[n] = true;
        }
        return true;
    }
    int helper(int n) {
        int res = 0;
        while (n != 0) {
            int dig = n % 10;
            res += pow(dig, 2);
            n = n/10;
        }
        return res;
    }
};
