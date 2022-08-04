class Solution
{
    unordered_set<int> st;

public:
    bool containsDuplicate(vector<int> &nums)
    {
        for (auto i : nums)
        {
            if (st.find(i) != st.end())
                return true;
            st.insert(i);
        }

        return false;
    }
};