class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //brute force method, to consider every single subarray => o(n^2)
        int res = 0;
        int currSum = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        for (int num : nums) {
            currSum += num;
            int diff = currSum - k;
            res += prefixSum[diff];
            prefixSum[currSum]++;
        }

        return res;    

    } 

};