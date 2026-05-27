class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    string rev = "";
    std::string binaryString = std::bitset<32>(n).to_string(); // Assuming 32-bit int
    for (char ch : binaryString) {
        rev = ch + rev;
    }
    return std::bitset<32>(rev).to_ulong();    
}
};
