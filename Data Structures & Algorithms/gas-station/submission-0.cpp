class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i = 0; i < gas.size(); i++) {
            if (helper(gas,i,cost)) {
                return i;
            }
        }
        return -1;
    }
    bool helper(vector<int>& gas, int idx, vector<int>& cost) {
        int it = 0;
        int current = gas[idx];
        
        while (it != gas.size()) {
            if (current < cost[idx]) {
            return false;
        }
            if (idx + 1 != cost.size()) {
            current = current - cost[idx] + gas[idx + 1];
            idx++;
          } else {
            current = current - cost[idx] + gas[0];
            idx = 0;
          }
          if (current <= 0) {
            return false;
          }
          it++;
    }
    std::cout << current << std::endl;
    return current >= 0;
    }

    //1-2+1
    //0-1+2

    //circular route
    //last station connected to first station cuz circular duh
    //unlimited amount of gas can be stored but u start with an empty gas tank
    //goal is to complete the circuit
    //if imp return -1;
    //atmost one soln
    //net gas after travelling from station i to station i + 1 -> gas[i] + gas[i + 1] - cost[i]
    //keep on doing this, lets say you start at a special idx called ind, then the goal should be that after a whole round trip gas[ind] >= 0
    //you will always make n trips where n = gas.size() = cost.size(), simply keep going ahead, if aage ka idx doesnt exist reset to 0, maybe do it in a while loop?
    //figuring out net runtime will be hard because i think its o(n^2) ish in the naive way

};
