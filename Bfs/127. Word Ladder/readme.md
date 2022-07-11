# 127. Word Ladder

- 需要自己先构造一个图做搜索

- 因为我们需要知道的是最短的路径有几层， 所以用bfs

- 构图时，如何判断两个单词只有哟个字母的区别？
  - 我们遍历单词的每个位置， 每个位置尝试更换26个字母组成新的单词，再用set判断变换了一个字母的单词是不是出现 wordList 里

- Time Complexity of constructing the graph: 26*NLlog(N)
  - N is number of words in the word List

  - L is avg length of all the words in the wordList

- 做bfs时， 我们要像 level order traversal一样 一层一层pop， 因为所有 相差一个char的word都算作一层
