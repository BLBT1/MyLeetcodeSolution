class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &pts)
    {
        int n = pts.size();
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            unordered_map<double, int> cnt; // cnt the number of dist
            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    double d = dist(pts[i], pts[j]);
                    cnt[d]++;
                }
            }
            for (auto i : cnt)
            {
                res += i.second * (i.second - 1);
            }
        }

        return res;
    }

    double dist(const vector<int> &a, const vector<int> &b)
    {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};