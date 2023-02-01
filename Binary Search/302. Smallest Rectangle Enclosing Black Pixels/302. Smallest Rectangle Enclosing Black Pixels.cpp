class Solution
{
public:
    int minArea(vector<vector<char>> &image, int x, int y)
    {
        int m = image.size();
        int n = image[0].size();
        int top = x;
        int bottom = x;
        int left = y;
        int right = y;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (image[i][j] == '1')
                {
                    if (i > top)
                        top = i;
                    if (i < bottom)
                        bottom = i;
                    if (j < left)
                        left = j;
                    if (j > right)
                        right = j;
                }
            }
        return (1 + top - bottom) * (1 + right - left);
    }
};