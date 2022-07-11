class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> res(n, 1);

        // ensure the right child has more candy if it has higher rate
        for (int i = 1; i < n; ++i)
        {
            if (ratings[i - 1] < ratings[i])
                res[i] = res[i - 1] + 1;
        }

        // ensure the left child has more candy if it has higher rate
        for (int i = n - 1; i >= 1; --i)
        {
            if (ratings[i] < ratings[i - 1])
                res[i - 1] = max(res[i] + 1, res[i - 1]);
        }

        return accumulate(res.begin(), res.end(), 0);
    }
};

//
// [1,2,87,87,87,2,1]