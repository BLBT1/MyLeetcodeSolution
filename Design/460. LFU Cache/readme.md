```c++
class LFUCache {
    int cap = 0;
    int minFreq = 0;
    unordered_map<int, list<int>::iterator> key2itr;
    unordered_map<int, int> key2val;
    unordered_map<int, int> key2frq;
    unordered_map<int, list<int>> frq2itrs; // each list is a list of key with the same frequency

public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(key2val.find(key) == key2val.end())
            return -1;

        // increase the freq
        auto itr = key2itr[key];
        int currFrq = key2frq[key];
        key2frq[key] += 1;
        frq2itrs[currFrq].erase(itr);
        frq2itrs[currFrq+1].push_front(key);
        key2itr[key] = frq2itrs[currFrq+1].begin();

        // update minFreq if currFrq was minFreq
        if(frq2itrs[currFrq].size() == 0 && currFrq == minFreq)
            minFreq = currFrq+1;

        return key2val[key];
    }
    
    void put(int key, int value) {
        // check if the key is exist or not
        if(get(key) != -1){
            // key exist and also updated the freq
            // only need to update val
            key2val[key] = value; 
            return;
        }

        // evict first than insert so minFrq is not messed up
        if(key2val.size() == cap){
            // need to evict
            int evict = frq2itrs[minFreq].back();
            auto itr = key2itr[evict]; 
            frq2itrs[minFreq].erase(itr);
            key2frq.erase(evict);
            key2val.erase(evict);
            key2itr.erase(evict);
        }

        // key does not exist, add the key
        int freq = 1;
        key2frq[key] = freq;
        frq2itrs[freq].push_front(key);
        key2itr[key] = frq2itrs[freq].begin();
        key2val[key] = value;
        minFreq = 1; // because new key got added, minFrq to 1.
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// we don't need to know the total order, 
// just need to need to keep track of what is minFreq
// Also for each frequency, we want to evict the LRU one. 
```
