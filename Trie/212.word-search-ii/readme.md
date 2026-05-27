
**save all of words in the trie**
key insight
减枝的关键是知道什么时候 继续搜索的 currWord 不在我们的words里了。

对于 lc 79，因为搜索只需要针对一个单词
我们可以 看 那个单词的 substr是不是currWord。但是这个题我们words 最多可有 3 * 10^4,
那如果我们每次都都查找 3*10^4 次 substr 对于每一步 dfs recusion。那太慢了

所以我们可以用trie提前存下所有的words，这样dfs时候就可快速减枝

搜索时， 我们要根据trie 里还有没有node 来决定， 一边走trie 一边走棋盘
如果TrieNode 是null的话，棋盘的搜索也不需要继续走了 


Note1: There might be duplicated word in the board, after adding word into the res, we can set `isWordEnd` back to false to dedup (this is better than dedup with a set)

```c++
class TrieNode {
    public:
        vector<TrieNode*> nxt; // should be 26 chars of next trie nodes 
        bool isWordEnd; // current trie node is end of a word
        TrieNode(){
            for(int i = 0; i < 26; ++i){
                nxt.push_back(nullptr); // all initialized to NULL
            }
            isWordEnd = false;
        }
};

class Solution {
    TrieNode* root;
    vector<string> res;
    vector<pair<int, int>> dir = {
        {1,0}, {0, 1}, {0, -1}, {-1, 0}
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        root = new TrieNode();

        // adding words into trie
        for(auto w: words){
            TrieNode* curr = root;
            for(auto c: w){
                if(curr->nxt[c-'a'] == nullptr)
                    curr->nxt[c-'a'] = new TrieNode();
                curr = curr->nxt[c-'a'];
            }
            curr->isWordEnd = true;
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                auto visited = vector<vector<bool>>(m, vector<bool>(n, false));
                auto curr = root;
                // for first call
                visited[i][j] = true;
                if(root->nxt[board[i][j]-'a'] != nullptr){
                    dfs(board, visited, string(1, board[i][j]), root->nxt[board[i][j]-'a'], i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, string currWord, TrieNode* curr, int x, int y){
        int m = board.size();
        int n = board[0].size();
        if(curr == nullptr) return;

        if(curr->isWordEnd){
            res.push_back(currWord);
            // need to continue as we might have word "aaaa" and "aa"
            curr->isWordEnd = false; // to dedup if same word appear twice in the board
        }

        for(auto &d: dir){
            int _x = x+d.first;
            int _y = y+d.second;
            
            if(_x < 0 || _x >= m || _y < 0 || _y >= n)
                continue;
            
            if(visited[_x][_y])
                continue;

            visited[_x][_y] = true;
            currWord.push_back(board[_x][_y]);
            dfs(board, visited, currWord, curr->nxt[board[_x][_y]-'a'], _x, _y);
            currWord.pop_back();
            visited[_x][_y] = false;
        }
    }
};
```

Note 2: because the same long word might appear many time in the board, for example
```
abcdefgh
abcdefgh
abcdefgh...
```

The trick from note-1 only dedup the word being adding into result twice, but is not saving the recursion call. 

It would be an optimization if on finding the word, we prune the trie so future DFS calls skip paths where all words have already been found.
But we need to be careful — we cannot physically delete nodes, because a shorter word might share a prefix with a longer one:

```
abc <- find this first, if we physically delete nodes a,b,c the longer word would not be found
abcdefgh
```

So instead of deleting, we track **# of words still using each node** via a `count` field.
When a word is found, we decrement `count` along its path (`remove()`).
If `count` reaches 0 on a node, no remaining words pass through it — DFS can prune there.
This avoids physical deletion while still pruning exhausted paths.


```c++
class TrieNode {
    public:
        vector<TrieNode*> nxt; // should be 26 chars of next trie nodes 
        bool isWordEnd; // current trie node is end of a word
        int count;
        TrieNode(){
            for(int i = 0; i < 26; ++i){
                nxt.push_back(nullptr); // all initialized to NULL
            }
            isWordEnd = false;
            count = 0;
        }
};

class Solution {
    TrieNode* root;
    vector<string> res;
    vector<pair<int, int>> dir = {
        {1,0}, {0, 1}, {0, -1}, {-1, 0}
    };
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        root = new TrieNode();

        // adding words into trie
        for(auto w: words){
            TrieNode* curr = root;
            for(auto c: w){
                if(curr->nxt[c-'a'] == nullptr){
                    curr->nxt[c-'a'] = new TrieNode();
                }
                curr->nxt[c-'a']->count += 1;
                curr = curr->nxt[c-'a'];
            }
            curr->isWordEnd = true;
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                auto visited = vector<vector<bool>>(m, vector<bool>(n, false));
                auto curr = root;
                // for first call
                visited[i][j] = true;
                if(root->nxt[board[i][j]-'a'] != nullptr){
                    dfs(board, visited, string(1, board[i][j]), root->nxt[board[i][j]-'a'], i, j);
                }
            }
        }
        return res;
    }

    void remove(TrieNode *root, string word){
        auto curr = root;
        for(auto c: word){
            curr->nxt[c-'a']->count--;
            curr = curr->nxt[c-'a'];
        }
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, string currWord, TrieNode* curr, int x, int y){
        int m = board.size();
        int n = board[0].size();
        if(curr == nullptr) return;

        if(curr->count == 0) return; // all word with this path had been found and record already

        if(curr->isWordEnd){
            res.push_back(currWord);
            // need to continue as we might have word "aaaa" and "aa"
            curr->isWordEnd = false; // to dedup if same word appear twice in the board
            remove(root, currWord);
        }

        for(auto &d: dir){
            int _x = x+d.first;
            int _y = y+d.second;
            
            if(_x < 0 || _x >= m || _y < 0 || _y >= n)
                continue;
            
            if(visited[_x][_y])
                continue;

            visited[_x][_y] = true;
            currWord.push_back(board[_x][_y]);
            dfs(board, visited, currWord, curr->nxt[board[_x][_y]-'a'], _x, _y);
            currWord.pop_back();
            visited[_x][_y] = false;
        }
    }
};
```
