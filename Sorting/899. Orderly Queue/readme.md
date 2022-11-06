# 899. Orderly Queue

这个题目的难点是要想到如何证明， 当 k >= 2 时，我们可以通过他给个操作得到任何的s的permutation。 也就是说，如果当k>=2时， 我们只需要return s 的sort就ok了。

证明如下

- 证明 s = fxxxxx 这样一段 string时，通过rotate xxxx的位置， f能够插到任意想要的位置
  - 每次我们只需要固定f为第一位的数字， 当 k >= 2时， 那我们就能想走马灯一样移动xxxx的rotation
  - 假设 s = fxxxwxxx， 我们想把f插到 w之后的位置， 那我们就能
    1. f[xxxwxxx] => f[xxxxxxw], 等同于不断移动第二位的char，直到w是最后一位
    2. xxxxxxwf， 等同于移动第一位的char到最后一位
- 证明任何一个char都能够是f
  - s = xxxwxx，我们想把w变成f，然后插进剩余的x中
  - 我们可以不断的移动第一位的char到最后，直到w是第一位了

综上所述，当k>=2时， 我们能都通过允许的操作把任意位置的char 先挪到首位，再插进任意位置。所以我们可以得到任何的s的permutation
