class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,int> indegree;
        map<int, vector<int>> neighbours;
        for (vector<int> vec : prerequisites) {
            indegree[vec[0]]++;
            neighbours[vec[1]].push_back(vec[0]);
        }
        int courses = 0;
        queue<int> sources;

        for (int i = 0; i < numCourses; i++) {
            if (indegree.find(i) == indegree.end()) {
                sources.push(i);
            }
        }

        while (!sources.empty()) {
            int curr = sources.front();
            cout << curr << endl;
            sources.pop();
            courses++;
            for (int ele : neighbours[curr]) {
                    indegree[ele]--;
                    if (indegree[ele] == 0) {
                    sources.push(ele);
                    }
                }
            }
          return (courses == numCourses);
        }
    };
