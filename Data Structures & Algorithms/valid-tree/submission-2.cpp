class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }
        map<int,vector<int>> neighbours;
        for (vector<int> edge : edges) {
            neighbours[edge[0]].push_back(edge[1]);
            neighbours[edge[1]].push_back(edge[0]);
        }

        queue<pair<int,int>> curr_parent;
        curr_parent.push({0, -1});
        set<int> seen;
        while (!curr_parent.empty()) {
            int curr = curr_parent.front().first;
            seen.insert(curr);
            int parent = curr_parent.front().second;
            curr_parent.pop();
            for (int ele : neighbours[curr]) {
                if (ele == parent) {
                    continue;
                }
                if (seen.count(ele)) {
                    return false;
                }
                seen.insert(ele);
                curr_parent.push({ele, curr});
            }

        }
        return seen.size() == n;
    }
};
