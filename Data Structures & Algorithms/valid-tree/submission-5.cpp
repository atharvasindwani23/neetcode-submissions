class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }
        unordered_map<int, vector<int>> neighbours;

        for (vector<int> edge : edges) {
            neighbours[edge[0]].push_back(edge[1]);
            neighbours[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        queue<pair<int, int>> sources;
        sources.push({0, -1}); //current node, parent

        while (!sources.empty()) {
            pair<int,int> curr = sources.front();
            sources.pop();
            int currNode = curr.first;
            visited.insert(currNode);
            int parNode = curr.second;
            for (int neigh : neighbours[currNode]) {
                if (!visited.count(neigh)) {
                    sources.push({neigh, currNode});
                } else {
                    if (neigh != parNode) {
                        return false;
                    }
                }
            }

        }
        return visited.size() == n;
     }
};
