# 269. Alien Dictionary

["wrt","wrf","er","ett","rftt"]

"wrt","wrf" --> t < f
"wrf","er" --> w < e
"er","ett" --> r < t
"ett","rftt" --> e < r

-> after we can determine those edges, the problems become a top sort

--> how to find those edges?
// for every 2 different consecutive words, find the first letter that is different

"wertf"

Note:
because the order edges and indegree count can be duplicated, we don't want to double count in-degree
but this is ok because the letter is being push to final order only once when indegree becomes 0
so no need to de-dup (de-dup is okay, but not needed)

```c++
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        // for dedup in edges, but not needed as explained below
        // unordered_map<char, unordered_set<char>> inChar;

        for(auto w: words){
            for(int i = 0; i < w.size(); ++i)
                indegree[w[i]] = 0;
        }

        for(int i = 0; i < words.size()-1; ++i){
            string w1 = words[i];
            string w2 = words[i+1];

            int len = min(w1.size(), w2.size());
            int foundDiff = false;
            for(int k = 0; k < len; ++k){
                if(w1[k] != w2[k]){
                    // w1[k] --> w2[k]
                    // because the order edges and indegree count can be duplicated, we don't want to double count in-degree
                    // but this is ok because the letter is being push to final order only once when indegree becomes 0
                    // so no need to de-dup (de-dup is okay, but not needed)
                    // if(inChar[w2[k]].find(w1[k]) == inChar[w2[k]].end()){
                        // inChar[w2[k]].insert(w1[k]);
                        adj[w1[k]].push_back(w2[k]);
                        indegree[w2[k]] += 1;
                    // }
                    foundDiff = true;
                    break;
                }
            }

            if(len < w1.size() && !foundDiff){
                return "";
            }
        }

        // top sort
        queue<char> q;
        string order;
        int count = 0;
        for(auto p: indegree){
            if(p.second == 0){
                q.push(p.first);  
            }
        }

        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; ++i){
                char curr = q.front();
                q.pop();
                order += curr;
                count += 1;

                for(auto nxt: adj[curr]){
                    indegree[nxt] -= 1;
                    if(indegree[nxt] == 0){
                        q.push(nxt);
                    }
                }
            }
        }


        if (count == indegree.size())
            return order;
        return "";
    }
};


// ["wrt","wrf","er","ett","rftt"]

// "wrt","wrf" --> t < f
// "wrf","er" --> w < e
// "er","ett" --> r < t
// "ett","rftt" --> e < r

// -> after we can determine those edges, the problems become a top sort

// --> how to find those edges?
// // for every 2 different consecutive words, find the first letter that is different

// "wertf"

// Note:
// because the order edges and indegree count can be duplicated, we don't want to double count in-degree
// but this is ok because the letter is being push to final order only once when indegree becomes 0
// so no need to de-dup (de-dup is okay, but not needed)

```