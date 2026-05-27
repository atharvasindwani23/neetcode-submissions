class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>> ordering;
        for (vector<int> vec : prerequisites) {
            int first = vec[0];
            int after = vec[1];
            ordering[first].push_back(after);
        }
        map<int,bool>visited;
        map<int,bool> recStack;
        vector<int> res = {};
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && cycle(ordering, visited, recStack, i, res)) {
                cout << i << endl;
                return {};
            }
        }
        cout << "here" << endl;
        return res;
    }

    bool cycle(map<int,vector<int>>& ordering, map<int,bool>& visited, map<int,bool>& recStack, int curr, vector<int>& res) {
        visited[curr] = true;
        recStack[curr] = true;
        //cout << curr << endl;
      //  res.push_back(curr);
        for (int ele : ordering[curr]) {
            if (recStack[ele]) {
                return true;
            } else if (!visited[ele]){
                if (cycle(ordering, visited, recStack, ele, res)) {
                    return true;
                }
            }
        }
        recStack[curr] = false;
        res.push_back(curr);
        return false;
    }

};
