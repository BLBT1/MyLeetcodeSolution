class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        // time: Nlog(N)
        set<int> st;
        for (auto i : nums)
        {
            st.insert(i);
        }

        if (st.size() < 3)
            return *st.rbegin();

        int cnt = 0;
        auto it = st.rbegin();
        for (; it != st.rend(); ++it)
        {
            cnt++;
            if (cnt == 3)
                break;
        }
        return *it;
    }
};