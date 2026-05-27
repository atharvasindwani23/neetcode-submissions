class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        int t = edges.size();

        for (int i = 0; i < t; i++) {
            vector<int> edge = edges[0];
            edges.erase(edges.begin());
            
            // If removing this edge breaks the cycle → it's redundant
            if (!isCycle(edges)) {
                res = edge;
            }

            edges.push_back(edge);
        } 
        return res;
    }

    bool isCycle(vector<vector<int>> edges) {
        unordered_map<int, vector<int>> neighbours;
        for (auto &edge : edges) {
            neighbours[edge[0]].push_back(edge[1]);
            neighbours[edge[1]].push_back(edge[0]);
        }

        set<int> visited;
        for (auto &p : neighbours) {
            int start = p.first;
            if (visited.count(start)) continue;

            queue<pair<int,int>> q;
            q.push({start, -1});
            visited.insert(start);

            while (!q.empty()) {
                auto [node, parent] = q.front();
                q.pop();

                for (int neigh : neighbours[node]) {
                    if (!visited.count(neigh)) {
                        visited.insert(neigh);
                        q.push({neigh, node});
                    } else if (neigh != parent) {
                        return true; // cycle found
                    }
                }
            }
        }
        return false;
    }
};
