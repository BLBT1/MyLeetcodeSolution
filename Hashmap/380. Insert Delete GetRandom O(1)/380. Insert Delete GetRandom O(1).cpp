class RandomizedSet
{
    vector<int> elts;
    unordered_map<int, int> val2pos;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (val2pos.find(val) != val2pos.end())
            return false;
        elts.push_back(val);
        val2pos[val] = elts.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (val2pos.find(val) == val2pos.end())
            return false;
        int pos = val2pos[val];
        elts[pos] = elts.back();
        val2pos[elts.back()] = pos;
        elts.pop_back();
        val2pos.erase(val);
        return true;
    }

    int getRandom()
    {
        return elts[rand() % elts.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */