class Solution {
public:
    vector<int> countBits(int n) {
    vector<int>bruh(n + 1, 0);
     for (int i  = 0; i <= n; i++) {
        bruh[i] = hammingWeight(i);
     }
     return bruh;
    }
    int hammingWeight(uint32_t n) {
    int returner = 0;
    std::string binaryString = std::bitset<32>(n).to_string(); // Assuming 32-bit int
    for (int i = 0; i < binaryString.size(); i++) {
        if (binaryString[i] == '1')
        returner += 1;
    }
    return returner;
    }
};
