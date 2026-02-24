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

这个时候就问题了，a 的上一次出现是 0 的位置， 而 如果 l = Map[s[r]]+1, l就反而要倒退了，因为a是之前s[l:r]的残留。
所以只要防止l倒退，那之前map里没移除的char就不是问题了
为了防止l倒退，`l = max(l,Map[s[r]]+1)`

或者另一种办法就是把map里左指针跳过的元素都移除, 不如上一种方法巧妙
```
                // remove all the elements in between from map
                int j = l;
                l = min(lastAppearPos+1,int(s.size())-1); // l should always on s range
                while(j<l){
                    lastAppear.erase(s[j]);
                    ++j;
                }
```


option#1
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; // left bound of the window
        unordered_map<char, int> lastAppear; // {char -> idx}
        int res = 0;
        for(int i = 0; i < s.size(); ++i) {
            auto it = lastAppear.find(s[i]);
            if(it == lastAppear.end()){
                lastAppear[s[i]] = i;
            } else {
                // l needs to move one pos after l
                int lastAppearPos = it->second;
                l = max(l, lastAppearPos+1); // l不能倒退
                lastAppear[s[i]] = i;
            }
            res = max(res, int(i-l+1));
        }
        return res;
    }
};

// [fabc]abcbb
//  l. i  
// p -> curr end of the window
// l -> the first element in the window 
// maintain a unordered_set
// if p is not in set, add current to set
// p ++
// update max element
// else,
// move l

// "tmmzuxt"
    // l
    //    i 

```

options#2
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; // left bound of the window
        unordered_map<char, int> lastAppear; // {char -> idx}
        int res = 0;
        for(int i = 0; i < s.size(); ++i) {
            auto it = lastAppear.find(s[i]);
            if(it == lastAppear.end()){
                lastAppear[s[i]] = i;
            } else {
                // l needs to move one pos after l
                int lastAppearPos = it->second;

                // remove all the elements in between from map
                int j = l;
                l = min(lastAppearPos+1,int(s.size())-1); // l should always on s range
                while(j<l){
                    lastAppear.erase(s[j]);
                    ++j;
                }
                lastAppear[s[i]] = i;
            }
            res = max(res, int(i-l+1));
        }
        return res;
    }
};

// [fabc]abcbb
//  l. i  
// p -> curr end of the window
// l -> the first element in the window 
// maintain a unordered_set
// if p is not in set, add current to set
// p ++
// update max element
// else,
// move l

// "tmmzuxt"
    // l
    //    i 

```