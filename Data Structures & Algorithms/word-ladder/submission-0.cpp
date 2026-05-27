class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>> neighbours;
        wordList.push_back(beginWord);
        std::cout << helper("hit", "jit") << std::endl;
        std::cout << helper("meow", "bhau") << std::endl;
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = 0; j < wordList.size(); j++) {
                string st = wordList[i];
                string str = wordList[j];
                if (helper(st, str)) {
                    neighbours[st].push_back(str);
                    neighbours[str].push_back(st);
                }
        }
    }
        return bfs(beginWord, endWord, neighbours);
    }

    int bfs(string beginWord, string endWord, map<string,vector<string>> neighbours) {
        map<string,int> distance;
        map<string,bool> visited;
        distance[beginWord] = 0;
        visited[beginWord] = true;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            for (string s : neighbours[curr]) {
                if (!visited[s]) {
                    visited[s] = true;
                    distance[s] = distance[curr] + 1;
                    q.push(s);
                }
                if (s == endWord) {
                    return distance[s] + 1;
                }
            }
        }
        return 0;
    }


    bool helper(string st, string str) {
        int c = 0;
        for (int i = 0; i < st.size(); i++) {
            if (st[i] != str[i]) {
                c++;
            }
        }
        return (c == 1);
    }
};