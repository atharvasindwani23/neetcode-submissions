class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) {
            return false;
        }

    unordered_map<int, vector<int>> neighbors;

    for (vector<int> vec : edges) {
        neighbors[vec[0]].push_back(vec[1]);
        neighbors[vec[1]].push_back(vec[0]);
    }
        return isAcyclic(n, neighbors);
    }

    

    bool isAcyclic(int n, unordered_map<int, vector<int>> neighbors) {
        //we have to check that there are no cycles in this
        queue<pair<int, int>> node_parent;
        unordered_set<int> visited;
        visited.insert(0);
        int finish = 0;
        node_parent.push({0, -1});
        while (!node_parent.empty()) {
            int node = node_parent.front().first;
            int parent = node_parent.front().second;
            finish++;
            node_parent.pop();
            for (int ele : neighbors[node]) {
                if (!visited.count(ele)) {
                    node_parent.push({ele, node});
                    visited.insert(ele);
                } else {
                    if (parent != ele) {
                        return false;
                    }
                }
            }
        }
        return (visited.size() == n);
    } 

    bool isConnected(int n, unordered_map<int, vector<int>> neighbors) {


    }


    //only one connected component

    //acyclic + one connected component
};
