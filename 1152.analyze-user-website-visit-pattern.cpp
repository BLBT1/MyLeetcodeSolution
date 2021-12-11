class Solution
{
public:
    vector<string> mostVisitedPattern(vector<string> &user, vector<int> &t, vector<string> &site)
    {
        //1. Use a hash map of maps to group users and sort their visits (map).
        //2. For each user, collect all 3-sequences using a hash set (ts).
        //3. Count 3-sequences between users using a hash map (count);
        //4. Find and return the 3-sequence with the largest count.
        unordered_map<string, map<int, string>> map; //{user, map{timestamp, site}}
                                                     // site now sorted by map in nlogn
        unordered_map<string, int> count;

        //nlogn
        for (auto i = 0; i < user.size(); ++i)
            map[user[i]][t[i]] = site[i];

        for (auto &u : map)
        {
            unordered_set<string> ts;
            for (auto it = begin(u.second); it != end(u.second); ++it)
                for (auto it1 = next(it); it1 != end(u.second); ++it1)
                    for (auto it2 = next(it1); it2 != end(u.second); ++it2)
                        ts.insert(it->second + " " + it1->second + " " + it2->second);
            for (auto s : ts)
                ++count[s];
        }

        pair<string, int> resPair = *count.begin();
        for (auto &pair : count)
        {
            if (pair.second > resPair.second)
            {
                resPair = pair;
            }
            else if (pair.second == resPair.second)
            {
                if (resPair.first > pair.first)
                    resPair = pair;
            }
        }
        stringstream ss(resPair.first);
        vector<string> resVec;
        string word;
        while (ss >> word)
        {
            resVec.push_back(word);
        }
        return resVec;
    }
};