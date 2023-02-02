class Solution
{
public:
    int minArea(vector<vector<char>> &image, int x, int y)
    {
        // O(4*NlogN) = O(NlogN)
        int top = findTop(image, x);
        int bottom = findBottom(image, x);
        int left = findLeft(image, y);
        int right = findRight(image, y);
        return (bottom - top + 1) * (right - left + 1);
    }

    int findTop(vector<vector<char>> &image, int x)
    {
        int low = 0;
        int hi = x;
        while (low < hi)
        {
            int mid = low + (hi - low) / 2;
            bool flag = false;
            for (int j = 0; j < image[0].size(); ++j)
            {
                if (image[mid][j] == '1')
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                hi = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }

    int findBottom(vector<vector<char>> &image, int x)
    {
        int low = x;
        int hi = image.size() - 1;
        while (low < hi)
        {
            int mid = low + (hi - low + 1) / 2;
            bool flag = false;
            for (int j = 0; j < image[0].size(); ++j)
            {
                if (image[mid][j] == '1')
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                low = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return low;
    }

    int findLeft(vector<vector<char>> &image, int y)
    {
        int low = 0;
        int hi = y;
        while (low < hi)
        {
            int mid = low + (hi - low) / 2;
            bool flag = false;
            for (int i = 0; i < image.size(); ++i)
            {
                if (image[i][mid] == '1')
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                hi = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }

    int findRight(vector<vector<char>> &image, int y)
    {
        int low = y;
        int hi = image[0].size() - 1;
        while (low < hi)
        {
            int mid = low + (hi - low + 1) / 2;
            bool flag = false;
            for (int i = 0; i < image.size(); ++i)
            {
                if (image[i][mid] == '1')
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
            {
                low = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return low;
    }
};