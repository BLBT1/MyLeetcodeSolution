class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1,
                                  vector<int> &arr2)
    {
        vector<int> cnt(1001, 0);
        vector<int> res;
        for (int i = 0; i < arr1.size(); i++)
        {
            cnt[arr1[i]]++;
        }

        for (int i : arr2)
        {
            for (int j = 0; j < cnt[i]; ++j)
            {
                res.push_back(i);
            }
            cnt[i] = 0;
        }

        for (int i = 0; i < cnt.size(); ++i)
        {
            if (cnt[i] == 0)
                continue;

            for (int j = 0; j < cnt[i]; ++j)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

// arr1 = [2,3,1,3,2,4,6,7,9,2,19],
// arr2 = [2,1,4,3,9,6]

// map2 = {2:3, 3:2, 1:1, 4:1, 6:1, 7:1, 9:1, 19:1}
