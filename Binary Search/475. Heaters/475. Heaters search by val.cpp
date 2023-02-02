class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        // search by value
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int low = 0;
        int hi = 1e9;
        while (low < hi)
        {
            int mid = (hi - low) / 2 + low;
            if (canCover(houses, heaters, mid))
                hi = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    // O(n)
    int canCover(vector<int> &houses, vector<int> &heaters, int r)
    {
        int m = houses.size();
        int n = heaters.size();
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {
            if (houses[i] < heaters[j] - r)
                return false;
            else if (houses[i] > heaters[j] + r)
                ++j;
            else
                ++i;
        }
        return i == m;
    }
};

// guess a number
//         67
// [1, 4, 5, 8, 9, 10]

// [6, 7]
// r = 4

// [1,5]
// [10]