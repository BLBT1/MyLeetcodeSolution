class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int n = people.size();
        int l = 0, r = n, mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (!canCarry(people, limit, mid))
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    bool canCarry(vector<int> &people, int limit, int boat)
    {
        int i = 0, j = people.size() - 1;
        int cnt = 0;
        while (i <= j)
        {
            if (people[i] + people[j] <= limit)
            {
                i++, j--;
            }
            else
            {
                j--;
            }
            cnt++;
        }
        return cnt <= boat;
    }
};