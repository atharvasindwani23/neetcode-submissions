class Solution {
public:
    void sortColors(vector<int>& nums) {
      map<int,int> freq;
      for (int num : nums) {
        freq[num]++;
      }
      int zeroes = freq[0];
      int ones = freq[1];
      int twos = freq[2];
      for (int i = 0; i < nums.size(); i++) {
        if (i >= 0 && i < zeroes) {
            cout << i << endl;
            nums[i] = 0;
        }
        else if (i >= zeroes && i < zeroes + ones) {
            nums[i] = 1;
        } else {
            nums[i] = 2;
        }
      }
    }
};