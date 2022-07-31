class Solution
{
public:
    long long countExcellentPairs(vector<int> &nums, int k)
    {
        vector<int> arr;
        unordered_set<int> Set(nums.begin(), nums.end());

        long long ret = 0;
        for (auto x : Set)
        {
            arr.push_back(hw(x));
        }

        sort(arr.begin(), arr.end());

        long long n = arr.size();
        long long j = n - 1;
        for (int i = 0; i < n; i++)
        {
            while (j >= 0 && arr[i] + arr[j] >= k)
                j--;
            if (j >= i)
                ret += n - (j + 1);
            else
                ret += n - (i + 1);
        }
        ret *= 2;

        for (auto x : arr)
        {
            if (x * 2 >= k)
                ret++;
        }

        return ret;
    }

    int hw(int n)
    {
        int cnt = 0;
        while (n != 0)
        {
            cnt++;
            n &= n - 1;
        }
        return cnt;
    }
};

// set number = humming weight of the bit string = number of 1's
// 1 & 1 + 1 || 1 = 2
// 1 & 0 + 1 || 0 = 1
// 0 & 1 + 0 || 1 = 1
// 0 & 0 + 0 || 0 = 0
