This problem is to exame the understanding of data structures

--> need to evict on least recently used -> need to key a order of recent used elements
    -> this order need to be modified in O(1)
    So we need a doubly linked list for ordering

--> but linked list does not support random access -> 
    need a map of key to iterator for O(1) get

--> need store key -> val
    need a map of key to val

```c++
class LRUCache {
    int cap = 0;

    // list for O(1) move node around --> ensure the recent ordering
    // list of keys
    list<int> keys;
    unordered_map<int, list<int>::iterator> key2Itr;
    unordered_map<int, int> key2Val;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // check if key exist
        if(key2Val.find(key) == key2Val.end())
            return -1;

        // 1. move the key to the front of list
        auto itr = key2Itr[key];
        keys.erase(itr);
        keys.push_front(key);
        key2Itr[key] = keys.begin();

        // 2. return the key value
        return key2Val[key];
    }
    
    void put(int key, int value) {
        // check if key has been there
        int val = get(key);
        if(val != -1){
            // key does exist, get already pust the key the front of list
            key2Val[key] = value;
            return;
        }

        // key does not exist
        keys.push_front(key);
        key2Val[key] = value;
        key2Itr[key] = keys.begin();
        
        // check if need to invalidate
        if(keys.size() > cap){
            int evict = keys.back();
            keys.pop_back();
            key2Val.erase(evict);
            key2Itr.erase(evict);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```



