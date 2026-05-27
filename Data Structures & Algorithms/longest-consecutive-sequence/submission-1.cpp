class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::map<int,bool> flag;
        for (int i : nums) {
            flag[i] = false;
        }
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> starter;
        for (int i = 0; i < nums.size(); i++) {
            if (!flag.count(nums[i] - 1)) {
                starter.push_back(nums[i]);
            }
        }
        std::cout << starter[0] << std::endl;
        int returner = 0;
        for (int i = 0; i < starter.size(); i++) {
            int maxi = 0;
            int start = starter[i];
            std::cout << start << std::endl;
            while (flag.count(start)) {
                maxi++;
                start += 1;
            }
            returner = max(returner, maxi);
        }
        return returner;
    }
            
};
