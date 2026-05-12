# 127. Word Ladder

- 需要自己先构造一个图做搜索

- 因为我们需要知道的是最短的路径有几层， 所以用bfs

- 构图时，如何判断两个单词只有哟个字母的区别？
  - 我们遍历单词的每个位置， 每个位置尝试更换26个字母组成新的单词，再用set判断变换了一个字母的单词是不是出现 wordList 里

- Time Complexity of constructing the graph: 26*NLlog(N)
  - N is number of words in the word List

  - L is avg length of all the words in the wordList

- 做bfs时， 我们要像 level order traversal一样 一层一层pop， 因为所有 相差一个char的word都算作一层


// 也可构图，在便利过程中filter
```c++
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        
        int n = beginWord.size();

        queue<string> q;
        int count = 0;
        int step = 1;

        q.push(beginWord);
        visited.insert(beginWord);

        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; ++i){
                string curr = q.front();
                q.pop();

                if(curr == endWord)
                    return step;

                // find next word;
                for(int k = 0; k < n; ++k){
                    for(char c = 'a'; c <= 'z'; ++c){
                        if(curr[k] == c)
                            continue; // skip curr letter
                                                    
                        string nxtWord = curr;
                        nxtWord[k] = c;
                        
                        if(visited.find(nxtWord) != visited.end())
                            continue;
                        
                        if(wordSet.find(nxtWord) == wordSet.end())
                            continue;
                        
                        q.push(nxtWord);
                        visited.insert(nxtWord);
                    }
                }
            }

            step++;
       }
       return 0;
    }
};

// hit -> ait, bit, cit ... zit
//     -> hat, hbt, ... hzt
//     -> hia, hib ... hiz

// --> check if any of this W*25 words are in the word list,
//     if it is in the work list, we can get to there

// idea to do a bfs from start work to end word
```
