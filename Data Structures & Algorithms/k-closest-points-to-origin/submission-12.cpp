class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    std::priority_queue<std::pair<int, vector<int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            int x_coord = points[i][0];
            int y_coord = points[i][1];
            std::cout << x_coord;
            std::cout << y_coord;
            int square_dist = ((x_coord * x_coord) + (y_coord * y_coord)) * -1;
            cout << square_dist << endl;
            pq.push({square_dist, {x_coord, y_coord}});
        }
        vector<vector<int>> res;
        while (pq.size() != 0) {
            auto x = pq.top();
            //std::cout << x.first << std::endl;
            pq.pop();
            res.push_back(x.second);
            if (res.size() == k) {
                return res;
            }
        }
        return {{}};
    }
};
