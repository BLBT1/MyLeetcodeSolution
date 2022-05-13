class Solution
{
    vector<int> p;

public:
    Solution(vector<int> &w)
    {
        int sum = 0;
        for (int i = 0; i < w.size(); ++i)
        {
            sum += w[i];
            p.push_back(sum);
        }
    }

    int pickIndex()
    {
        // in range [1, 15]
        int r = rand() % p.back() + 1;
        int i = binary_search(p, r);
        return i;
    }

    // find the idx of element that is >= tar
    int binary_search(vector<int> &p, int tar)
    {
        int l = 0, r = p.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (p[mid] < tar)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */