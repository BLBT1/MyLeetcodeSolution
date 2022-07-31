# 489. Robot Room Cleaner

1. 这题目的难点是如何确认下一步的方向，可以用 (currDir + k) % 4

2. 用初始位置作为 0 0，每个位置都编成 string 用 set 记录

3. 到达下一个位置是， 回溯时候要 turnRight 两次，再 move， 回溯后要再 turnRight() 两次，把位置调回初始
