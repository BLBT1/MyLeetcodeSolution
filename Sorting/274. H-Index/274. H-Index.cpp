class Solution
{
public:
    int hIndex(vector<int> &cit)
    {
        sort(cit.begin(), cit.end());
        int cnt = 1;
        for (int i = cit.size() - 1; i >= 0; --i)
        {
            if (cnt <= cit[i])
                cnt++; // cnt-> number paper with cit more then cit[h]
        }
        return cnt - 1;
    }
};