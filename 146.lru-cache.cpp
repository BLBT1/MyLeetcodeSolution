/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache
{
    int capacity_;
    //* we keep the back node as the most recently used
    list<int> cache;                                 //* O(1) remove + O(1) add to back
    unordered_map<int, list<int>::iterator> key2itr; //* allows use to access node in linked list in O(1)
    unordered_map<int, int> key2val;                 //* from key to val in O(1) time
public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key)
    {
        if (key2val.find(key) == key2val.end())
            return -1;
        auto itr = key2itr[key];
        int val = key2val[key];
        cache.erase(itr);
        cache.push_back(key);
        key2itr[key] = prev(cache.end());
        return val;
    }

    void put(int key, int value)
    {
        if (this->get(key) != -1)
        {
            key2val[key] = value;
        }
        else
        {
            if (key2itr.size() == capacity_)
            {
                int LRUkey = *cache.begin();
                key2val.erase(LRUkey);
                cache.erase(cache.begin());
                key2itr.erase(LRUkey);
            }
            cache.push_back(key);
            key2val[key] = value;
            key2itr[key] = prev(cache.end());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

// key4  ... key7 key3 key2 key8 end

//