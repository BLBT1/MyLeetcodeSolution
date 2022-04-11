/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnts;
        for (auto i : nums)
        {
            cnts[i]++;
        }
        vector<pair<int, int>> arr;
        for (auto &p : cnts)
        {
            arr.push_back(p);
        }

        int f = quickSelect(arr, k, 0, arr.size() - 1);

        vector<int> res;
        for (auto &p : arr) // p: {element, cnt}
        {
            if (p.second >= f)
                res.push_back(p.first);
        }
        return res;
    }

    int quickSelect(vector<pair<int, int>> &arr, int k, int begin, int end)
    {
        int pivot = begin + (end - begin) / 2;
        int p = arr[pivot].second;

        // rank(arr[p])
        int i = 0;   // i is first element after smaller
        int j = end; // j is the last element before greater
        int t = 0;   // is element being examined
        while (t <= j)
        {
            if (arr[t].second < p)
            {
                swap(arr[i], arr[t]);
                i++;
                t++;
            }
            else if (arr[t].second > p)
            {
                swap(arr[t], arr[j]);
                --j;
            }
            else
            {
                ++t;
            }
        }

        int leftSize = i - begin;
        int rightSize = end - j;

        if (rightSize >= k)
            return quickSelect(arr, k, j + 1, end);
        else if (end - i + 1 >= k)
            return p;
        else
            return quickSelect(arr, k - (end - i + 1), begin, i - 1);
    }
};

//  [SSS SPPPPGGGG]
//            i
//            t
//           j
// @lc code=end
