class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tempratures) {
        //brute force o(n^2) method
        vector<int> res;
        bool b = false;
        for (int i = 0; i < tempratures.size(); i++) {
            int curr_temp = tempratures[i];
            b = false;
            for (int j = i + 1; j < tempratures.size(); j++) {
                if (tempratures[j] > curr_temp) {
                    b = true;
                    cout << tempratures[i] << endl;
                    cout << tempratures[j] << endl;
                    res.push_back(j - i);
                    break;
                }
            }
            if (!b) {
            res.push_back(0);
            }
        }
        return res;
    }
};
