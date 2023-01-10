class LRUCache
{
    list<int> elts; // list of keys
    unordered_map<int, int> key2val;
    unordered_map<int, list<int>::iterator> key2itr;
    int cap;

public:
    LRUCache(int capacity) { cap = capacity; }

    int get(int key)
    {
        if (key2val.find(key) == key2val.end())
            return -1;
        // move the node to front
        elts.erase(key2itr[key]);
        elts.push_front(key);
        key2itr[key] = elts.begin();
        return key2val[elts.front()];
    }

    void put(int key, int val)
    {
        if (get(key) != -1)
        {
            key2val[key] = val;
        }
        else
        {
            if (cap == elts.size())
            {
                // evict the last elt in list
                int LRUKey = elts.back();
                key2itr.erase(LRUKey);
                key2val.erase(LRUKey);
                elts.pop_back();
            }
            elts.push_front(key);
            key2val[key] = val;
            key2itr[key] = elts.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// we need to move any element from mid to front in O(1) => front is the most recently used elemen
//  MRU k1 k2 k3 k4 ... kn => LRU
//  we need to use a linked list

// this helper us to get in O(1) time
// so we need map for => {key -> val}
// after get back the key, we need to update the itr as well

// // this let us to add to front in O(1) time, also remove from the back in O(1) time
// linked list
// most recent used XXX k XXX list recent used
