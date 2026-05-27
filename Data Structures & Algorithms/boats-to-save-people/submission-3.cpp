class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        map<int,bool> taken;
        vector<int> possible;
        for (int i : people) {
            if (i >= limit) {
                count++;
            } else {
                possible.push_back(i);
            }
        }
        cout << possible.size() << endl;
        sort(possible.begin(), possible.end());
        int lower = 0;
        int upper = possible.size() - 1;
        while (lower < upper) {
            if (possible[lower] + possible[upper] > limit) {
                count++;
                upper--;
            } else {
                count++;
                lower++;
                upper--;
            }
        }
        if (lower == upper) {
            count++;
        }
        return count;
    }
    //1,2,2
        //think of an O(n) approach here, goal? to find numbers or pairs such that possible[i] + possible[j] < smth
        //two ptrs? take a lower + upper thing, disadvantage? no sorting done, matlab ki if condition is false, we dont really know what to do, can achieve by sorting
    };

    //single out the things you know wont fit fs
