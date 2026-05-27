class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> neighbours;
        for (vector<int> vec : edges) {
            neighbours[vec[0]].push_back(vec[1]);
            neighbours[vec[1]].push_back(vec[0]);
        }
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(neighbours, visited, i);
                count++;
            }
        }
        return count;
    }


    void bfs(unordered_map<int, vector<int>> neighbours, vector<bool>& visited, int node) {
        queue<int> sources;
        sources.push(node);
        while (!sources.empty()) {
            int curr = sources.front();
            visited[curr] = true;
            sources.pop();
            for (int neigh : neighbours[curr]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    sources.push(neigh);
                }
            }
        }
    }
};
