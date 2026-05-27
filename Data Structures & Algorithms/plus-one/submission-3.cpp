class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    long num  = 0;
    for (int i  = 0; i < digits.size(); i++) {
        num += pow(10, digits.size() - 1 - i) * digits[i];
    }
    num += 1;
    std::cout << num << std::endl;
    return helper(num);
}
  vector<int> helper(long num) {
    vector<int> res;
    while (num != 0) {
        res.push_back(num % 10);
        num = num / 10;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
