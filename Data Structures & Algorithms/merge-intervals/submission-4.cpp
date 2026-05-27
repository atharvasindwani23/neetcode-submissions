class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
    return a[0] < b[0];
    });
        vector<vector<int>> returner;
        if (intervals.size() == 1) {
            return intervals;
        }
        vector<int> flag = mergeHelper(intervals[0], intervals[1]);
        if (flag.size() == 0) {
            std::cout << "yum" << std::endl;
            returner.push_back(intervals[0]);
            returner.push_back(intervals[1]);
        } else {
            std::cout << "meow";
            std::cout << flag[0];
            std::cout << flag[1];
            returner.push_back(flag);
        }
        for (int i = 2; i < intervals.size(); i++) {
            if (mergeHelper(returner[returner.size() - 1], intervals[i]).size() == 0) {
                returner.push_back(intervals[i]);
            } else {
                returner[returner.size() - 1] = mergeHelper(returner[returner.size() - 1], intervals[i]);
            }
        }
        return returner;
    }
    //do this first then the question for inserting them together
    // whats the logic for merging?
    // fuck anyrhything and just think logically, when would you merge? when theres an overlap
    // complete or partial-> even partial would work
    // [1,4] -> [3,5] -> [1,5] ie if the element after i is less than the .second of the first merge
    //how do you merge? -> first.first, second.second
    // [1,4], [3,5], [4,6] => [1,6] -> need to edit array asap?
    //work with an additional vector at all times, this vector returner will represent what you need to enter out of
    //create a helper function for merge, this merge would take in the current interval, and what we j saw/added
    //
    vector<int> mergeHelper(vector<int> pair1, vector<int> pair2) {
        vector<int> returner;
        if (pair1[1] >= pair2[0]) {
            returner.push_back(pair1[0]);
            returner.push_back(max(pair2[1], pair1[1]));
        }
        return returner;
    }
};
