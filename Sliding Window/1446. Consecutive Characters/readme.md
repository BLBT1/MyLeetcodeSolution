# 1446. Consecutive Characters

滑动窗口的口诀就是八个字： “右指针正常移动，左指针伺机而动”

此题中的运用：
- 维护一个窗口， 里面的所有char 都一致
- 右指针正常移动： 右指针正常探索新的char
- 左指针伺机而动： 左指针如果和右指针的 char 不同， 则需要走到右指针当前所在位置

```cpp
        for (int j = 0; j < s.size(); ++j)
        {
            if (s[i] != s[j])
            {
                i = j;
            }
            res = max(j - i + 1, res);
        }
```