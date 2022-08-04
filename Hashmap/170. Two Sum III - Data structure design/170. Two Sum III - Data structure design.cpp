class TwoSum
{
    unordered_map<int, int> mp;

public:
    TwoSum() {}

    void add(int number)
    {
        mp[number]++;
    }

    bool find(int val)
    {
        for (auto itr = mp.begin(); itr != mp.end(); ++itr)
        {
            long i = itr->first;
            long diff = val - i;
            if (mp.find(diff) != mp.end() && diff != i)
            {
                return true;
            }
            if (2 * i == val && itr->second > 1)
                return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */