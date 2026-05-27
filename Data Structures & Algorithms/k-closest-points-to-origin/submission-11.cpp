class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> dist(points.size());
        std::map<int, vector<vector<int>>> pairer;
        for (int i  = 0; i < points.size(); i++) {
            dist[i] = (points[i][0]) * (points[i][0]) + (points[i][1]) * (points[i][1]);
            pairer[dist[i]].push_back(points[i]);
        }
        std::priority_queue<int> maxHeap;
        for (int num : dist) {
            maxHeap.push(num);
        }
        std::cout << maxHeap.size() << std::endl;
        for (int i  = 0; i < points.size() - k; i++) {
            std::cout << "myow" << std::endl;
            maxHeap.pop();
        }
        std::cout << maxHeap.size() << std::endl;
        vector<vector<int>> returner;
        int constp = maxHeap.size();
        for (int i  = 0; i < constp; i++) {
            int x = maxHeap.top();
            std::cout << x << std::endl;
            maxHeap.pop();
            std::cout << maxHeap.size() << std::endl;
            vector<vector<int>> nums = pairer[x];
            for (vector<int> coord : nums) {
            std::cout << "once" << std::endl;
            returner.push_back(coord);
            if (returner.size() == k) {
                std::cout << "here" << std::endl;
                return returner;
            }
            }
        }
        return returner;
    }
};
