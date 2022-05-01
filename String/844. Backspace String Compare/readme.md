# 844. Backspace String Compare

- 快慢指针，慢指针用来维护 s[0, i) 是 converted的string，

- 快指针探索新的指针

- 慢指针前其实是模拟一个stack， 把 j遇到非 # 的char 复制过去， 这个方法还是很巧妙
