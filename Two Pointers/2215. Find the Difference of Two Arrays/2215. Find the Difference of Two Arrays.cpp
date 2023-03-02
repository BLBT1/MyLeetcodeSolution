class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        int m = nums1.size(), n = nums2.size();
        vector<int> vec1, vec2;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                vec1.push_back(nums1[i]);
                do
                    ++i;
                while (i >= 1 && i < m && nums1[i] == nums1[i - 1]);
            }
            else if (nums1[i] == nums2[j])
            {
                do
                    ++i;
                while (i >= 1 && i < m && nums1[i] == nums1[i - 1]);
                do
                    ++j;
                while (j >= 1 && j < n && nums2[j] == nums2[j - 1]);
            }
            else
            {
                vec2.push_back(nums2[j]);
                do
                    ++j;
                while (j >= 1 && j < n && nums2[j] == nums2[j - 1]);
            }
        }
        while (i < m)
        {
            vec1.push_back(nums1[i]);
            do
                ++i;
            while (i >= 1 && i < m && nums1[i] == nums1[i - 1]);
        }
        while (j < n)
        {
            vec2.push_back(nums2[j]);
            do
                ++j;
            while (j >= 1 && j < n && nums2[j] == nums2[j - 1]);
        }
        return {vec1, vec2};
    }
};
