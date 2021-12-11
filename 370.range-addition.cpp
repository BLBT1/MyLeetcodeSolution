class Solution
{
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
    {
        // ided: arr[i] = diff[i] + arr[i-1]
        vector<int> diff(length, 0);
        for (auto &u : updates)
        {
            int begin = u[0];
            int end = u[1] + 1;
            int c = u[2];
            diff[begin] += c;
            if (end < length)
                diff[end] -= c;
        }

        int sum = 0;
        for (int i = 0; i < length; ++i)
        {
            sum += diff[i];
            diff[i] = sum;
        }
        return diff;
    }
};