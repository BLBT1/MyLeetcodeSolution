# 71. Simplify Path

- 先 用 类似 split('/') 的方法 预处理 path， 存在 一个vector里 (用 str.find())

- 注意， 这样如果有 // 的情况，就会被 存为 ""

- 接下来 用 一个 stack， 这里用一个vector 的 push_back 和 pop_back 来模拟 stack， 这样方便最后的处理

- 如果看到 "..", 就 pop

- 如果 看到 "" 或者 "." 就 do nothing

- 剩下别的都push入栈

Time：O(N), Space: O(N)
