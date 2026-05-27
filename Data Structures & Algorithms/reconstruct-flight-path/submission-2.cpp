class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
map<string, priority_queue<string, vector<string>, greater<string>>> neighbours;
        for (int i = 0; i < tickets.size(); i++) {
            string from = tickets[i][0];
            string to  = tickets[i][1];
            neighbours[from].push(to);
        }
        vector<string> res;
        dfs(neighbours, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(map<string, priority_queue<string, vector<string>, greater<string>>> &neighbours
, string current, vector<string>& res) {
    while (!neighbours[current].empty()) {
        string next = neighbours[current].top();
        neighbours[current].pop();
        dfs(neighbours, next, res);
    }
    res.push_back(current);
}




    //make a map first of all thats what you need to start off with, then you know ki you need to start off from jfk, then return the shortest path,
    //okay the only reason why this is slightly tricky is cuz you need to have a proper idea on what youre returning
    //ur returning a path so topop sort?

};
