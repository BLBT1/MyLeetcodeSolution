class LFUCache
{
    int cap = 0;
    int minfrq = 0;
    unordered_map<int, int> key2val;
    unordered_map<int, list<int>::iterator> key2itr;
    unordered_map<int, int> key2frq;
    unordered_map<int, list<int>> frq2list;

public:
    LFUCache(int capacity) { cap = capacity; }

    int get(int key)
    {
        if (key2val.find(key) == key2val.end())
            return -1;
        int prev_frq = key2frq[key];
        frq2list[prev_frq].erase(key2itr[key]);
        frq2list[prev_frq + 1].push_front(key);

        if (frq2list[minfrq].size() == 0)
            minfrq += 1;

        key2itr[key] = frq2list[prev_frq + 1].begin();
        key2frq[key] = prev_frq + 1;
        return key2val[key];
    }

    void put(int key, int val)
    {
        if (cap == 0)
            return;

        if (get(key) != -1)
        {
            key2val[key] = val;
        }
        else
        {
            if (key2val.size() == cap)
            {
                int FRUKey = frq2list[minfrq].back();
                frq2list[minfrq].pop_back();
                key2val.erase(FRUKey);
                key2itr.erase(FRUKey);
                key2frq.erase(FRUKey);
            }

            frq2list[1].push_front(key);
            key2val[key] = val;
            key2itr[key] = frq2list[1].begin();
            key2frq[key] = 1;
            minfrq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//          f1          f2         f3    f4 ...
//     MRU{k1,k2} LRU {k3,k4}  {k5, k6}  {k7}
