class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int n = words.size();
        vector<string> res;
        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            int j = i; // => words[i:j] is the words to place in a line
            while (j < words.size() && cnt <= maxWidth)
            {
                if (j == i)
                {
                    cnt += words[j].size();
                }
                else
                {
                    cnt += 1 + words[j].size();
                }
                ++j;
            }

            --j;

            if (cnt > maxWidth)
            {
                cnt -= 1 + words[j].size();
                j--;
            }

            // need to consider a edge case: last line
            if (j == n - 1)
            {
                res.push_back(processLast(words, i, maxWidth));
            }
            else
            {

                res.push_back(processLine(words, i, j, maxWidth));
            }

            i = j;
        }

        return res;
    }

    string processLine(vector<string> &words, int i, int j, int maxWidth)
    {
        if (i == j)
        {
            return words[i] + kSpace(maxWidth - words[i].size());
        }

        string res = "";
        int gaps = j - i;
        int letters = 0;
        for (int w = i; w <= j; ++w)
        {
            letters += words[w].size();
        }

        int baseSpace = (maxWidth - letters) / gaps;
        int needExtra = maxWidth - letters - gaps * baseSpace;

        for (int w = i; w < i + needExtra; ++w)
        {
            res += words[w];
            res += kSpace(baseSpace + 1); // add k space
        }

        for (int w = i + needExtra; w < j; ++w)
        {
            res += words[w];
            res += kSpace(baseSpace);
        }
        res += words[j];

        return res;
    }

    string processLast(vector<string> &words, int i, int maxWidth)
    {
        string res = "";
        for (int w = i; w < words.size(); ++w)
        {
            res += words[w];
            if (res.size() < maxWidth)
                res += " ";
        }
        if (res.size() < maxWidth)
            res += kSpace(maxWidth - res.size());
        return res;
    }

    string kSpace(int k)
    {
        string res = "";
        for (int i = 0; i < k; ++i)
            res += " ";
        return res;
    }
};

// [xxx,xxx,xxxx, xxx]
//           j
// // xxx xxx xxxx
// //  i       j