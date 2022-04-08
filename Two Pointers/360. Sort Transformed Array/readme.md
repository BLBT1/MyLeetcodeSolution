# 360. Sort Transformed Array

这是个双指针题，但是本质是数学。在抛物线里，可以通过抛物线上的点到抛物线中点的距离来判断大小

- if a == 0, 那已经单调函数
  - b < 0, 要 reverse

- if a > 0, like a U, so greater abs(x) is greater f(x)
- if a < 0, like a n, so smaller abs(x) is greater f(x)
- 中线的x的位置是 x = (-b)/(2a)
