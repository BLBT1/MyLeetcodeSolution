# 55. Jump Game

从左往右， 每一次都是更新目前最右能达到的点 rightMax。遍历每个点，一旦当前点超过了rightMax， 说明当前点到达不了，就返回false。
