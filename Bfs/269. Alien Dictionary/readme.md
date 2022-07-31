# 269. Alien Dictionary

这个题目的难点在构建图标，把所有的单词两个两个对比， 如果发现不一样， 当前排后的单词当前位置的char就要小。 代码如下

```cpp
        unordered_map<char, int> indegree;
        for (int i = 0; i < words.size(); i++)
            for (int j = 0; j < words[i].size(); j++)
                indegree[words[i][j]] = 0;

        for (int i = 1; i < words.size(); i++)
        {
            string word1 = words[i - 1];
            string word2 = words[i];

            // shorter word should be high in order
            if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2)
                return "";

            for (int i = 0; i < min(word1.size(), word2.size()); i++)
            {
                if (word1[i] == word2[i])
                    continue;
                if (mp[word1[i]].find(word2[i]) == mp[word1[i]].end())
                {
                    mp[word1[i]].insert(word2[i]);
                    indegree[word2[i]]++;
                }
                break;
            }
        }

```

有了图，且是有向图，我们就可以用拓扑排序了
