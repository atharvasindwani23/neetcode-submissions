class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> distances;

        vector<vector<int>> closest;

        for (vector<int> point : points) {
            int x_coord = point[0];
            int y_coord = point[1];

            int distance = (x_coord * x_coord) + (y_coord * y_coord);
            distances.push({distance * -1, {x_coord, y_coord}});
        }

        for (int i = 0; i < k; i++) {
            auto x = distances.top();
            distances.pop();
            closest.push_back({x.second.first, x.second.second});
        }        
        return closest;
    }

    //k closest, can we do any way through hashmaps?
    //yes maybe we can do it using maps, where we can store distance, that stores the keys and then we can go back
    //no point tho => same runtime
};
