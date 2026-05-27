class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Adjacency structures
        map<int, vector<int>> neighbours;
        map<int, map<int,int>> costs;

        for (auto &time : times) {
            neighbours[time[0]].push_back(time[1]);
            costs[time[0]][time[1]] = time[2];
        }

        // Distance map
        map<int, int> pathCost;
        for (int i = 1; i <= n; i++) {
            pathCost[i] = INT_MAX;
        }
        pathCost[k] = 0;

        // Min-heap (cost, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [currCost, curr] = pq.top();
            pq.pop();

            if (currCost > pathCost[curr]) continue; // skip outdated entries

            for (int nei : neighbours[curr]) {
                int newCost = currCost + costs[curr][nei];
                if (newCost < pathCost[nei]) {
                    pathCost[nei] = newCost;
                    pq.push({newCost, nei});
                }
            }
        }

        // Answer: maximum distance to any node
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (pathCost[i] == INT_MAX) return -1; // unreachable node
            res = max(res, pathCost[i]);
        }
        return res;
    }
};
