class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> neighbours;
        vector<int> indegree(numCourses, 0);
        for (vector<int> vec : prerequisites) {
            neighbours[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
        }   
        queue<int> sources;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                sources.push(i);
            }
        }
        int count = 0;
        while (!sources.empty()) {
            int curr = sources.front();
            sources.pop();
            count++;
            for (int neighbour : neighbours[curr]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    sources.push(neighbour);
                }
            }
        }
        return count == numCourses;
    }
};
