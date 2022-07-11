# 417. Pacific Atlantic Water Flow

- 这题第一反应都是正向思维，从中间任意一点开始，用dfs判断他是不是能reach 两边但是这样做会很慢， 且要对每个点都做搜索

- 要用逆向思维， 我们只对边开始反向搜索，看每个边能搜索到哪些点，同两个 m*n 的 vector 来记录

- 最后再取能reach both ocean 的点

time： O(N*M)

space: O(N*M)
