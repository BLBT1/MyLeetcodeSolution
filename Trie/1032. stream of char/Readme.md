# 1032. Stream of char

前缀树的题目的代码量很大，但是思路很好想，所以熟练度很重要

### 核心思想:

每次query一个char，从那个字符开始往前看，所以建树时也要从后往前:

```cpp
        void addWord(string &str)
            {
                // add word from the back to the front
                TrieNode *ptr = root;
                for (int i = str.size() - 1; i >= 0; --i)
                {
                    char ch = str[i];
                    if (ptr->next[ch - 'a'] == nullptr)
                    {
                        ptr->next[ch - 'a'] = new TrieNode();
                    }
                    ptr = ptr->next[ch - 'a'];
                }
                ptr->isEnd = true;
            }
```

此题其他部分就走流程，先要implement一个trieNode，在把string放入即可：

```cpp 
        struct TrieNode
        {
            bool isEnd;
            TrieNode *next[26];

            //constructor
            TrieNode()
            {
                isEnd = false;
                for (int i = 0; i < 26; ++i)
                {
                    next[i] = nullptr;
                }
            }
        };
```

