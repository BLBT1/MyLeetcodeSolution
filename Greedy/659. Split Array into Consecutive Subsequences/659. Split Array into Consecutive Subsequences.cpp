class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        unordered_map<int, int> seq; // {ending number, number of seq}
        unordered_map<int, int> cnt; // num of val not used

        for (auto x : nums)
            cnt[x]++;

        for (auto x : nums)
        {
            if (cnt[x] == 0)
                continue;

            if (seq.find(x - 1) != seq.end() && seq[x - 1] > 0)
            {
                seq[x - 1]--;
                seq[x]++;
                cnt[x]--;
            }
            else
            {
                if (cnt[x + 1] > 0 && cnt[x + 2] > 0)
                {
                    seq[x + 2]++;
                    cnt[x]--;
                    cnt[x + 1]--;
                    cnt[x + 2]--;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};