class TimeMap {
public:
    unordered_map<string, map<int,string>> timestamps;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timestamps[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        map<int, string> ordered = timestamps[key];
        auto it = ordered.upper_bound(timestamp);   
        if (it == ordered.begin()) {
            return  "";
        }
        --it;
        return it->second;
    }



    //[1->3] = 1
    //[1->4] = 2
    //[1->5] = 3

    //all timestamps need to be stored in some manner which is smart

};
