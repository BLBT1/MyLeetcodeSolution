# 6. Zigzag Conversion

应为是zigzag，所以要先从上往下，再从下往上，需要注意：

 1. 尽管例子中是有空挡的，其实可以忽略空挡，因为我们最后返回的res里也是没有空挡的

 2. 当从上往下fill结束后, currRow -= 2, 因为while 结束后,我们是在 numRows + 1 的位置。因为最后一行已经fill 过了，　我们要折回去从倒数第二行开始往上fill, 所以说　numRows -= 2，到达倒数第二行的位置

 3. 从下往上fill, 第一行是不用fill的，　因为从上往下fill时是从第一行开始的

```cpp
        vector<string> zig(numRows, "");
        int i = 0;
        while(i < s.size())
        {
            // from up to down
            int currRow = 0;
            while(currRow < numRows && i < s.size())
            {
                zig[currRow].push_back(s[i]);
                ++i;
                ++currRow;
            }
            
            currRow -= 2;
            
            // from bottom up
            while(currRow > 0 && i < s.size())
            {
                zig[currRow].push_back(s[i]);
                ++i;
                --currRow;
            }
        }

```
