class Solution {
    

public:
   

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, unordered_set<string>> graph;
    unordered_map<string, string> email_to_name;

    // Build graph
    for (auto& account : accounts) {
        string name = account[0];
        string first_email = account[1];
        for (int i = 1; i < account.size(); i++) {
            graph[first_email].insert(account[i]);
            graph[account[i]].insert(first_email);
            email_to_name[account[i]] = name;
        }
    }

    unordered_set<string> visited;
    vector<vector<string>> result;

    for (auto& [email, name] : email_to_name) {
        if (visited.count(email)) continue;

        // BFS
        queue<string> q;
        q.push(email);
        visited.insert(email);
        vector<string> component;

        while (!q.empty()) {
            string node = q.front(); q.pop();
            component.push_back(node);
            for (auto& neighbor : graph[node]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        sort(component.begin(), component.end());
        component.insert(component.begin(), name);
        result.push_back(component);
    }

    return result;
}
};