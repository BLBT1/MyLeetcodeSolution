# 536. Construct Binary Tree from String

- 用一个stack模拟树的建造

- Stack.top() 是正在建的树的root

- 看到 '(' 说明开始新的一层建造，所以把前一个node 推进 stack最 root

- 看到 ')' 说明结束了当前层的子树的建设，用 cuur 保存 建设完成的 子树的 root
