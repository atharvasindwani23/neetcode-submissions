class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int l = 0, r = 0;
        for (int w : weights) {
            l = max(l, w);  // minimum capacity = heaviest item
            r += w;         // maximum capacity = ship all in one day
        }

        int res = r;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (canShip(weights, mid, days)) {
                res = mid;
                r = mid - 1; // try smaller valid capacity
            } else {
                l = mid + 1; // need more capacity
            }
        }
        return res;
    }

private:
    bool canShip(vector<int>& weights, int capacity, int days) {
        int dayCount = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                dayCount++;        // new day
                currentLoad = w;   // start day with this weight
                if (dayCount > days) return false; // too many days
            } else {
                currentLoad += w;
            }
        }
        return true;
    }
};
