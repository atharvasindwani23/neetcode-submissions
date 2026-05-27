#include <map>
#include <string>

class TimeMap {
public:
    // This map stores: key -> (timestamp -> value)
    // The inner map is automatically sorted by timestamp, which is crucial.
    std::map<std::string, std::map<int, std::string>> timeMap;

    TimeMap() {
        // Constructor is correct
    }
    
    // Time Complexity: O(log N) where N is the number of timestamps for the key
    void set(std::string key, std::string value, int timestamp) {
        // The [] operator will create the inner map if the key doesn't exist,
        // then insert the timestamp/value pair.
        timeMap[key][timestamp] = value;
    }
    
    // Time Complexity: O(log M) where M is the number of timestamps for the key
    std::string get(std::string key, int timestamp) {
        // 1. Check if the key exists in the outer map
        if (timeMap.find(key) == timeMap.end()) {
            return "";
        }

        // Get a reference to the inner map (timestamp -> value)
        std::map<int, std::string>& innerMap = timeMap[key];
        
        // The logic for 'get' requires finding the largest timestamp <= the input timestamp.
        // std::map::upper_bound(timestamp) returns an iterator to the first element
        // *strictly greater* than 'timestamp'.
        auto it = innerMap.upper_bound(timestamp);

        // If 'it' is the beginning of the inner map, it means all timestamps
        // are greater than the requested 'timestamp', so no valid value exists.
        if (it == innerMap.begin()) {
            return "";
        }

        // The element *before* upper_bound(timestamp) will be the element 
        // with the largest timestamp less than or equal to the requested 'timestamp'.
        --it;
        
        // The iterator 'it' now points to the correct (timestamp, value) pair.
        return it->second;
    }
};

// Notes on the Data Structure:
// * Using std::map<string, std::map<int, string>> is the standard and most idiomatic 
//     C++ solution for this problem.
// * The **outer map** maps the `key` string to its time series data.
// * The **inner map** maps `timestamp` to `value`. Because `std::map` is ordered by its key,
//     the inner map keeps the timestamps sorted, enabling an efficient search.
// * The `get` operation leverages `std::map::upper_bound` which performs a binary search 
//     on the timestamps in $\mathcal{O}(\log M)$ time.