有两种做法： https://github.com/wisdompeak/LeetCode/tree/master/Trie/1268.Search-Suggestions-System

```c++
class TrieNode {
    public:
    TrieNode* next[26]; 
    bool isEnd;

    TrieNode (){
        for(int i =0; i < 26; ++i) 
            next[i] = nullptr;
        isEnd = false;
    }
};

class Solution {
    TrieNode *root;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        this->root = new TrieNode();

        // build the Trie
        for(auto &word : products) {
            TrieNode *curr = root;
            for (auto c: word) {
                if (curr->next[c-'a'] == nullptr) {
                    curr->next[c-'a'] = new TrieNode();
                }
                curr = curr->next[c-'a'];                    
            }
            curr->isEnd =true;
        }

        // search in the trie
        vector<vector<string>> res;
        string prefix;
        TrieNode *curr = root;
        for(int i = 0; i < searchWord.size(); ++i){
            char c = searchWord[i];
            prefix += c;

            if(curr->next[c-'a'] == nullptr) {
                // no word in product matches prefix, so new word could match future prefices
                for (int j = i; j < searchWord.size(); ++j)
                    res.push_back({});
                return res;
            }
            
            vector<string> currRes;
            string currWord;
            dfs(curr->next[c-'a'], currRes, currWord);
            for(int j = 0; j < currRes.size(); ++j){
                currRes[j] = prefix+currRes[j];
            }
            res.push_back(currRes);

            curr = curr->next[c-'a'];
        }

        return res;
    } 

    void dfs(TrieNode *curr, vector<string> &currRes, string &currWord) {
        if(currRes.size() == 3) return;
        
        if (curr->isEnd)
            currRes.push_back(currWord);

        for(int i = 0; i < 26; ++i){
            if(curr->next[i] == nullptr) continue;
            currWord += i +'a';
            dfs(curr->next[i], currRes, currWord);
            currWord.pop_back();
        }
    }
};
```
