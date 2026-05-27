class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> neighbors;
        for (vector<int> edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]); 
        }
        unordered_set<int> visited;
        int connected = 0;
        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                bfs(neighbors, i, visited);
                connected++;
            }
        }
        return connected;
    }

    void bfs(unordered_map<int, vector<int>> neighbors, int curr, unordered_set<int>& visited) {
        queue<int> elements;
        elements.push(curr);
        visited.insert(curr);
        while (!elements.empty()) {
            int element = elements.front();
            elements.pop();
            for (int ele : neighbors[element]) {
                if (!visited.count(ele)) {
                    visited.insert(ele);
                    elements.push(ele);
                }
            }
        }
    }

};
