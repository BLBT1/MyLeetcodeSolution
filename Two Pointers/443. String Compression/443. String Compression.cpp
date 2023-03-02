class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        int i = 0;
        int cnt = 0;
        while (i < n && chars[i] != 0)
        {
            int j = i;
            while (j < n && chars[j] == chars[i])
            {
                j++;
            }
            int len = j - i;
            if (len == 1)
            {
                cnt += 1;
                i += 1;
            }
            else
            {
                string num_string = to_string(len);
                int k = 0;
                while (k < num_string.size())
                {
                    chars[k + i + 1] = num_string[k];
                    ++k;
                }
                if (len - 1 > num_string.size())
                {
                    int to_move = len - num_string.size() - 1;
                    int z = j;
                    for (; z < n; ++z)
                    {
                        chars[z - to_move] = chars[z];
                        chars[z] = 0;
                    }
                    while (z - to_move < j)
                    {
                        chars[z - to_move] = 0;
                        ++z;
                    }
                }
                if (j >= n)
                    i = j;
                else
                    i += num_string.size() + 1;
                cnt += num_string.size() + 1;
            }
        }
        return cnt;
    }
};

// cnt  = 4
//  0  1  2  3  4  5  6
// [a, 2, b, b, c, c, c]
//              i
//                       j
// ["a","a","a","b","b","a","a"]
