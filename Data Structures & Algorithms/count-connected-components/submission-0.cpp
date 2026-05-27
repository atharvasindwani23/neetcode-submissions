class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::map<int, vector<int>> neighbours;
        std::map<int, bool> visited;
        for (vector<int> vec : edges) {
            neighbours[vec[0]].push_back(vec[1]);
            neighbours[vec[1]].push_back(vec[0]);
        }
        int returner = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(neighbours, i, visited);
                returner++;
            }
        }
        return returner;
    }

    void dfs(std::map<int, vector<int>> neighbours, int curr, std::map<int,bool>& visited) {
        visited[curr] = true;
        for (int ele : neighbours[curr]) {
            if (!visited[ele]) {
                dfs(neighbours, ele, visited);
            }
        }
    }
};
