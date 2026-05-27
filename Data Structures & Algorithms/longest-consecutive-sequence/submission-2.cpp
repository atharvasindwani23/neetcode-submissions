class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //first do an o(n) sweep to figure out the starting elements really quickly
        //starting elements will be one whose curr value - 1 wont be present in the map
        int length = 0;
        map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<int> starting;
        for (int i = 0; i < nums.size(); i++) {
            int curr_number = nums[i];
            if (freq[curr_number - 1] == 0) {
                starting.push_back(i);
            }
        }
        
        for (int i = 0;  i < starting.size(); i++) {
            int starting_idx = starting[i];
            int curr_num = nums[starting_idx];
            std::cout << curr_num << std::endl;
            int temp = 1;
            while (freq[curr_num + 1] > 0) {
                temp++;
                curr_num += 1;
            }
            length = max(temp, length);
        }
        return length;
    } 
};
