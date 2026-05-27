class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> neighbours;
        int count = 0;
        vector<bool> seen(n, false);
        for (vector<int> edge : edges) {
            neighbours[edge[1]].push_back(edge[0]);
            neighbours[edge[0]].push_back(edge[1]);
        }
        for (int i = 0; i < n; i++) {
            if (seen[i] == false) {
                bfs(neighbours, seen, i);
                count++;
            }
        }
        return count;
    }
    void bfs(map<int, vector<int>>& neighbours, vector<bool>& seen, int curr) {
        
        queue<int> q;
        q.push(curr);

        while (!q.empty()) {
            int ele = q.front();
            q.pop();
            for (int nei : neighbours[ele]) {
                if (!seen[nei]) {
                    seen[nei] = true;
                    q.push(nei);
                }
            }
        }
    }

};
