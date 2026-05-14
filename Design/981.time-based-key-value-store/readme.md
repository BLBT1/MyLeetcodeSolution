```c++
class TimeMap {
    // vector is ok because of all timestamp input is assumed to be increasing
    unordered_map<string, vector<int>> timestamps;
    unordered_map<string, unordered_map<int, string>> vals;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        vals[key][timestamp] = value;
        timestamps[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(vals.find(key) == vals.end())
            return "";

        auto it = upper_bound(timestamps[key].begin(), timestamps[key].end(), timestamp);
        if(it == timestamps[key].begin())
            return "";
        else it--;

        return vals[key][*it];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


//  key -> t1 -> v1
//      -> t2 -> v2
//      ... 

// get(key, timestamp) --> return (timestamp_prev <= timestamp)
//     -> return greatest timestamp because t -> sorted + binary search

```