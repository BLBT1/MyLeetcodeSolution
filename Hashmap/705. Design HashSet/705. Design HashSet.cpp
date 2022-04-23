class MyHashSet
{
    int prime;
    vector<list<int>> chain;

    // the hash naive hash function we use
    int hash(int key)
    {
        return key % prime;
    }

    list<int>::iterator search(int key)
    {
        int h = hash(key);
        return find(chain[h].begin(), chain[h].end(), key);
    }

public:
    MyHashSet() : prime(10007), chain(prime) {}

    void add(int key)
    {
        int h = hash(key);
        if (!contains(key))
            chain[h].push_back(key);
    }

    void remove(int key)
    {
        int h = hash(key);
        auto it = search(key);
        if (it != chain[h].end())
            chain[h].erase(it);
    }

    bool contains(int key)
    {
        int h = hash(key);
        return search(key) != chain[h].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */