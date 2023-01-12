class RandomizedSet
{
    unordered_map<int, int> num2pos;
    vector<int> nums;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (num2pos.find(val) != num2pos.end())
            return false;
        nums.push_back(val);
        num2pos[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (num2pos.find(val) == num2pos.end())
            return false;
        // move the element to delete to the end of nums
        int endElt = nums.back();
        swap(nums[num2pos[val]], nums[nums.size() - 1]);
        num2pos[endElt] = num2pos[val];
        nums.pop_back();
        num2pos.erase(val);
        return true;
    }

    int getRandom()
    {
        int randIdx = rand() % nums.size();
        return nums[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */