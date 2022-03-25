# 3. Longest Substring Without Repeating Characters

- r 正常移动探索新的字符， l 伺机而动，去除重复的字符

- 用一个 map 来记录每个 char 最后一次出现的位置

- 如果 s[r] 与 s[l:r] 之间的字符有重复 Map.find(s[r]) != Map.end()

- 那我们就要移动 l 了， 那 l 移动到哪里? 理论上就是 Map[s[r]]+1, 但是这样不行，思考以下例子

```cpp
" a b b a"
      l
        r 


Map:
a:0
b:2
```

这个时候就问题了，a 的上一次出现是 0 的位置， 而 如果 l = Map[s[r]]+1, l就反而要倒退了，因为a是之前s[l:r]的残留。为了防止l倒退，l = max(l,Map[s[r]]+1)
