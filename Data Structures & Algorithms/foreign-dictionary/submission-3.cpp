class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        //now our goal is to simply make that adjacency list, how do we figure this out now is a challenge
        map<char, set<char>>adj;
        string bigString = "";
        for (string s : words) {
            bigString += s;
        }
        for (char ch : bigString) {
            adj[ch] = std::set<char>();
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                bool diff = false;
                for (int k = 0; k < min(words[j].size(), words[i].size()); k++) {
                    if (words[i][k] != words[j][k]) {
                        adj[words[i][k]].insert(words[j][k]);
                        diff = true;
                        break;
                    }
                }
                if (!diff && words[i].size() > words[j].size()) {
                    return "";
                }
            }
        }
        vector<char> result = topologicalSort(adj);
        string s = "";
        for (char ch : result) {
            s += ch;
        }
        return s;
    }

    vector<char> topologicalSort(const map<char, set<char>>& adj) {
    map<char, int> indegree;
    set<char> nodes;

    // Build indegree and collect all nodes
    for (const auto& [u, neighbors] : adj) {
        nodes.insert(u);
        for (char v : neighbors) {
            indegree[v]++;
            nodes.insert(v);
        }
    }

    queue<char> q;
    for (char node : nodes) {
        if (indegree[node] == 0) {
            q.push(node);
        }
    }

    vector<char> topo;
    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        topo.push_back(curr);

        if (adj.count(curr)) {
            for (char neighbor : adj.at(curr)) {
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
    }

    if (topo.size() != nodes.size()) {
        cout << "Cycle detected! Topological sort not possible.\n";
        return {};
    }

    return topo;
}

};
