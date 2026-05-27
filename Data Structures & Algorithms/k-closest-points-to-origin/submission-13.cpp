class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //distance to points mapping
        priority_queue<pair<int,vector<int>>> distances;

        for (vector<int> point : points) {
            int distance = (point[0] * point[0] + point[1] * point[1]) * -1;
            distances.push({distance, point});
        }
        vector<vector<int>> closestPoints;

        for (int i = 0; i < k; i++) {
            closestPoints.push_back(distances.top().second);
            distances.pop();
        }
        return closestPoints;
    }
};
