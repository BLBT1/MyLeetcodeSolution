class RandomizedCollection
{
    unordered_map<int, unordered_set<int>> num2pos;
    vector<int> nums;

public:
    RandomizedCollection() {}

    bool insert(int val)
    {
        int flag = num2pos.find(val) == num2pos.end();
        nums.push_back(val);
        num2pos[val].insert(nums.size() - 1);
        return flag;
    }

    bool remove(int val)
    {
        if (num2pos.find(val) == num2pos.end())
            return false;

        // if the back element is val
        int val2 = nums.back();
        if (val2 == val)
        {
            num2pos[val].erase(nums.size() - 1);
            nums.pop_back();

            if (num2pos[val].size() == 0)
                num2pos.erase(val);
        }
        else
        {
            int pos2 = nums.size() - 1;
            int pos = *(num2pos[val].begin());
            nums[pos] = val2;
            num2pos[val2].erase(pos2);
            num2pos[val2].insert(pos);
            num2pos[val].erase(pos);
            nums.pop_back();

            if (num2pos[val].size() == 0)
                num2pos.erase(val);
        }

        return true;
    }

    int getRandom()
    {
        int pos = rand() % nums.size();
        return nums[pos];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// 第一想法是用：
// unorderd_map<int, vector<int>> val2pos
// 这样的问题是如果要删除一个 1 的 idx，假设有k 个1，那这个操作就是O（k）了

// 所以要用 unordered_map<int, unordered_set<int>>

// 1 1 1 1 2 2 2
// 直接从 nums里随机选， 那得到的每个数字的概率就和频次成正比了
