# 1249. Minimum Remove to Make Valid Parentheses

- 括号题主要解法有二， greedy(用counter) 或 用 stack

- 这里用stack，因为有多余的左括号留下，我们需要用stack记录他们所在的index

- 还有一个小技巧：如果一个string里有多个char需要删除，可以在第一个pass里全改成特俗符合 如 '#', 再用第二个 pass check 每个char是不是'#', 再考虑要不要push进 res， 这样可以 保持在 O(N)
