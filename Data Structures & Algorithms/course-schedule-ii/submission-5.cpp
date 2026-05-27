class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> neighbors;
        unordered_map<int, int> indegree;
        queue<int> sources;
        for (vector<int> coursePair : prerequisites) {
            int prerequisite = coursePair[1];
            int course = coursePair[0];
            neighbors[prerequisite].push_back(course);
            indegree[course]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                sources.push(i);
            }
        }
        vector<int> schedule(numCourses);
        int finish = 0;
        while (!sources.empty()) {
            int curr = sources.front();
            sources.pop();
            schedule[finish] = curr;
            finish++;
            for (int neighbor : neighbors[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    sources.push(neighbor);
                }
            }
        }
        if (finish != numCourses) {
            return {};
        }
        return schedule;
    }
};
