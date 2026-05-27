class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> prereq;
        for (auto& pair : prerequisites) {
            prereq[pair[1]].push_back(pair[0]); // course depends on prereq
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);  // to track current call stack

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (dfs(i, prereq, visited, recStack)) return false; // cycle found
            }
        }
        return true;
    }

    bool dfs(int curr, map<int, vector<int>>& prereq, vector<bool>& visited, vector<bool>& recStack) {
        visited[curr] = true;
        recStack[curr] = true;

        for (int nei : prereq[curr]) {
            if (!visited[nei]) {
                if (dfs(nei, prereq, visited, recStack)) return true;
            } else if (recStack[nei]) {
                // Back edge to a node in the current DFS path = cycle
                return true;
            }
        }

        recStack[curr] = false; // backtracking
        return false;
    }
};
