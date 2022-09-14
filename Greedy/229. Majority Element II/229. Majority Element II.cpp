class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int c1 = 0, c2 = 0;
        int ans1, ans2;
        for (auto b : nums)
        {
            if (c1 == 0 && b != ans2)
            {
                ans1 = b;
            }
            else if (c2 == 0 && b != ans1)
            {
                ans2 = b;
            }

            if (ans1 == b)
                c1++;
            else if (ans2 == b)
                c2++;
            else
            {
                c1--;
                c2--;
            }
        }

        // check
        c1 = 0;
        c2 = 0;
        vector<int> res;
        for (auto i : nums)
        {
            if (i == ans1)
                c1++;
            if (i == ans2)
                c2++;
        }
        if (c1 > nums.size() / 3)
            res.push_back(ans1);
        if (c2 > nums.size() / 3)
            res.push_back(ans2);
        return res;
    }
};
