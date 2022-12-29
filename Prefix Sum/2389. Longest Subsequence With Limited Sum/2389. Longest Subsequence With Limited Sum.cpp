class Solution
{
    int n;
    vector<int> presum;

public:
    vector<int> answerQueries(vector<int> &nums,
                              vector<int> &queries)
    {
        this->n = nums.size();
        const int m = queries.size();
        sort(nums.begin(), nums.end());
        presum = vector<int>(n, 0);
        vector<int> res(m, 0);
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            presum[i] = sum;
        }

        for (int i = 0; i < m; ++i)
        {
            // all elts in nums are positive, so presum is already sorted
            res[i] = binary_search(queries[i]) + 1;
        }

        return res;
    }

    // find the last elt presum <= to x
    int binary_search(int x)
    {
        int l = 0;
        int r = n - 1;
        int mid;
        while (l < r)
        {
            mid = (r - l + 1) / 2 + l;
            if (presum[mid] <= x)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (presum[l] <= x)
            return l;
        else // if the first elt is still > x, return -1;
            return -1;
    }
};

// time (m+n)*logn
