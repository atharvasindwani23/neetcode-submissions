class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> neighbours;
        for (auto& pre : prerequisites) {
            neighbours[pre[1]].push_back(pre[0]);  // edge: b → a
        }

        map<int, bool> visited;
        map<int, bool> onPath;

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (hasCycle(i, visited, onPath, neighbours)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool hasCycle(int curr, map<int, bool>& visited, map<int, bool>& onPath, map<int, vector<int>>& neighbours) {
        visited[curr] = true;
        onPath[curr] = true;

        for (int neighbor : neighbours[curr]) {
            if (!visited[neighbor]) {
                if (hasCycle(neighbor, visited, onPath, neighbours)) return true;
            } else if (onPath[neighbor]) {
                return true;  // back edge → cycle detected
            }
        }

        onPath[curr] = false;  // backtrack
        return false;
    }
};
