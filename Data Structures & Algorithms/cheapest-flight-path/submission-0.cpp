#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        const int INF = 1e9;

        vector<int> prevCost(n, INF);
        prevCost[src] = 0;

        for (int edgesUsed = 0; edgesUsed <= k; ++edgesUsed) {
            // Start this round from last round’s results.
            // This snapshot prevents us from using more than (edgesUsed + 1) edges.
            vector<int> currCost = prevCost;

            for (const auto& e : flights) {
                int from  = e[0];
                int to    = e[1];
                int price = e[2];

                if (prevCost[from] == INF) continue;          // 'from' not reachable yet
                currCost[to] = min(currCost[to], prevCost[from] + price);
            }

            prevCost.swap(currCost);
        }

        return prevCost[dst] == INF ? -1 : prevCost[dst];
    }
};
