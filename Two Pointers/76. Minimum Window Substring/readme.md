# 76. Minimum Window Substring

- 这个题目需要：右指针正常移动，左指针伺机而动

- 因为如果我们固定左指针，右指针往下尽力探索， 这样是找不到最短的 window的

- 这个题还用了一个 cnt 和 M 的技巧来判断 Map 是不是满足 Table的要求，用 cnt记录所有满足标准的char的个数， 如果满足要求的char的个数cnt == 所有有要求的char的个数，那sub string s[l:r]就满足要求。这个技巧很有用， lc395里也用了
