class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) {
            return true;
        }
        unordered_map<int, vector<int>> neighbors;
        unordered_map<int, int> indegree;
        int finish = 0;
        for (vector<int> prerequisite : prerequisites) {
            int courseBefore = prerequisite[1];
            int courseAfter = prerequisite[0];
            indegree[courseAfter]++;
            neighbors[courseBefore].push_back(courseAfter);
        }
        queue<int> sources;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                sources.push(i);
            }
        }

        while (!sources.empty()) {
            cout << "MEOWWWW" << endl;
            int curr = sources.front();
            sources.pop();
            finish++;
            for (int course : neighbors[curr]) {
                cout << course << endl;
                indegree[course]--;
                if (indegree[course] == 0) {
                    sources.push(course);
                }
            }
        }
        cout << finish << endl;
        return (finish == numCourses);
    }
};
