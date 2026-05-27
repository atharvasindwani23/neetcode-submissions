class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int returner = INT_MAX;
        int maxi = 0;
        for (int num : piles) {
            maxi = max(maxi, num);
        }
        int lower = 1;
        int upper = maxi;
        while (lower <= upper) {
            int mid = (lower + upper) / 2;
            if (h < calculator(piles, mid)) {
                lower = mid + 1;
            } else {
                std::cout << "NIGGER" << std::endl;
                returner = min(returner, mid);
                upper = mid - 1;
            }
        }
        return returner;
    }
    int calculator(vector<int>& piles, int num) {
        int returner = 0;
        for (int n : piles) {
            returner += ceil(double(n) / double(num));
        }
        return returner;
    }
};



//1 4 3 2
// can j say infinite and do everything in piles.size()
//trick is to notice the fact that min is mentioned
// what if we do 1, well that would take 1+4+3+2 which is > 9
// what if we do 2, that would be 1 + 2 + 2 + 1 which < 9 and seems perfect!
// upper bound is the max element in the array obviously
// lower bound is 1, so now we have a range, have to do it in O(nlogm) time
// n is size of array, m is the max value in the array
//makes sense cuz in a way you are applying a binary search on [1... m], select an element go through piles check how much it is, if < h, go left, if > h go right, keep min variable ready