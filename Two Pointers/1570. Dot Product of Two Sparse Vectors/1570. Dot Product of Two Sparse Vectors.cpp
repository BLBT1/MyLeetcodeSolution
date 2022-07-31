class SparseVector
{
public:
    vector<pair<int, int>> nonZero;
    SparseVector(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
                continue;
            nonZero.push_back({i, nums[i]});
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector &vec)
    {
        int i = 0, j = 0;
        int res = 0;
        while (i < this->nonZero.size() && j < vec.nonZero.size())
        {
            if (this->nonZero[i].first < vec.nonZero[j].first)
                ++i;
            else if (this->nonZero[i].first > vec.nonZero[j].first)
                ++j;
            else
            {
                res += this->nonZero[i].second * vec.nonZero[j].second;
                ++i, ++j;
            }
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);