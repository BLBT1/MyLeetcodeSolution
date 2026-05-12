if in 2 lists of account, one of the account have identital name, it belong to one person
note, name maybe repeated.

key is to find out all connected components

accounts = 
[
    ["John","johnsmith@mail.com","john_newyork@mail.com"],
    ["John","johnsmith@mail.com","john00@mail.com"],
    ["Mary","mary@mail.com"],
    ["John","johnnybravo@mail.com"]
    ["John","johnsmith@mail.com"]
]

--> need to store a a inverted index from mail -> account-id

johnsmith@mail.com -> 0,1,4
john_newyork@mail.com ->0
john00@mail.com -> 1
mary@mail.com -> 2
johnnybravo@mail.com -> 3

-> links -> [[0,1], [1, 4]]

-> find fathers -> merge


all merge account with father {original id -> ordered set of accounts}
need to make sure the smaller original account id one is already the father
this can help ensure the name is always the first

```c++
class Solution {
    vector<int> fathers;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        fathers = vector(n, 0);
        for(int i = 0; i < n; ++i){
            fathers[i] = i;
        }

        unordered_map<string, vector<int>> index;
        for(int i = 0; i < n; ++i) {

            // skip the name
            for(int j = 1; j < accounts[i].size(); ++j) {
                index[accounts[i][j]].push_back(i);
            }
        }

        for(auto p: index){
            auto aList = p.second;
            // for each 2, form an edge
            if(aList.size() < 2){
                continue;
            }

            for(int i = 0; i < aList.size()-1; ++i){
                int x = aList[i];
                int y = aList[i+1];

                if(findFather(x) != findFather(y)){
                    unionSet(x, y);
                }
            }
        }

        // all merge account with father {original id -> ordered set of accounts}
        // need to make sure the smaller original account id one is already the father
        // this can help ensure the name is always the first
        unordered_map<int, set<string>> mergedSet;
        unordered_map<int, string> names;
        for(int i = 0; i < n; ++i){
            int f = findFather(i);
            
            if(f == i){
                // self if root
                names[i] = accounts[i][0];
            }

            // skip the name
            for(int j = 1; j < accounts[i].size(); ++j) {
                string a = accounts[i][j];
                
                // this should also sort it
                mergedSet[f].insert(a);
            }
        }

        vector<vector<string>> res;
        for (auto p: names){
            vector<string> ma;
            ma.push_back(p.second);
            for(string s: mergedSet[p.first]){
                ma.push_back(s);
            }
            res.push_back(ma);
        }

        return res;
    }

    int findFather(int x){
        if(x == fathers[x])
            return x;
        return findFather(fathers[x]);
    }

    void unionSet(int x, int y){
        int xFather = findFather(x);
        int yFather= findFather(y);

        // ensure samller to be root
        if(xFather < yFather)
            fathers[yFather] = xFather;
        else
            fathers[xFather] = yFather;
    }
};
```