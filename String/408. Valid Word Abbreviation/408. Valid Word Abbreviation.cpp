class Solution
{
public:
    bool validWordAbbreviation(string word, string abbr)
    {
        int m = word.size();
        int n = abbr.size();
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {
            if (word[i] == abbr[j])
            {
                ++i, ++j;
            }
            else
            {
                if (abbr[j] > '0' && abbr[j] <= '9')
                {
                    int jump = 0;
                    // get the entire num
                    int z = j;
                    while (z < m && abbr[z] >= '0' && abbr[z] <= '9')
                    {
                        ++z;
                    }
                    jump = stoi(abbr.substr(j, z - j));
                    j = z;
                    i += jump;
                    if (i > m)
                        return false;
                }
                else
                {
                    return false;
                }
            }
        }
        if (i < m || j < n)
            return false;

        return true;
    }
};