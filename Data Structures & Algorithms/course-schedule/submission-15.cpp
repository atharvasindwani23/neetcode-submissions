class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //lets think about how we want to do this
        // we pretty much want to make this into a dag; and kinda do a topo sort on it
        //while performing said topo sort we want to ensure one simple thing
        //how many elements were i able to topo sort? if i was able to topo sort everything good else bad

        unordered_map<int, vector<int>> neighbours;
        int count = 0;
        unordered_map<int,int> inorder;
        for (vector<int> prereq : prerequisites) {
            inorder[prereq[0]]++;
            neighbours[prereq[1]].push_back(prereq[0]);
        }
        queue<int> sources;

        for (int i = 0; i < numCourses; i++) {
            if (inorder[i] == 0) {
                sources.push(i);
            }
        }
        while (!sources.empty()) {
            int curr = sources.front();
            sources.pop();
            count++;

            for (int ele : neighbours[curr]) {
                inorder[ele]--;
                    if (inorder[ele] == 0) {
                    sources.push(ele);
                    }
                }
            }
        return count == numCourses;
    }
};
