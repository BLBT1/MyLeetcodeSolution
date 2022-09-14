class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int res = INT_MIN;
        int left = arrays[0].front();
        int right = arrays[0].back();
        for (int i = 1; i < arrays.size(); ++i)
        {
            int curr = max(abs(arrays[i].back() - left), abs(arrays[i].front() - right));
            res = max(res, curr);
            left = min(left, arrays[i].front());
            right = max(right, arrays[i].back());
        }

        return res;
    }
};