class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> mapper;
        for (vector<int> vec : prerequisites) {
            int first = vec[1];
            int after = vec[0];
            mapper[first].push_back(after);
        }
        map<int,bool> visited;
        map<int,bool> recStack;
        for (int i = 0;  i < numCourses; i++) {
            if (!visited[i] && cycle(mapper, visited, recStack, i)) {
                return false;
            }
        }
        return true;
    }

    bool cycle(map<int,vector<int>>& mapper, map<int,bool> visited, map<int,bool> recStack, int curr) {
        visited[curr] = true;
        recStack[curr] = true;
        for (int nei : mapper[curr]) {
            if (!visited[nei]) {
                if (cycle(mapper, visited, recStack, nei)) {
                    return true;
                }
            } else if (recStack[nei]) {
                return true;
            }
        }
        recStack[curr] = false;
        return false;
    }
};
