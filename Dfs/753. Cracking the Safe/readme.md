# 753. Cracking the Safe

这道题是一个被研究过的经典问题，称为De Bruijin序列。Wikipedia有专门介绍的页面。这个问题可以转化 hamiltonian path的问题， 且以证明是存在这种路径的。假设每个key是n位， 那我们可以把n-1看成一个node， 下一位可能的char ['0', k] 看作 edge， 做dfs

Time: (k^(k^n))

Space: (k^n)
