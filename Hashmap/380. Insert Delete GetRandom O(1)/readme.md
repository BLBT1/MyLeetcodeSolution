# 380. Insert Delete GetRandom O(1)

- 想要 O(1) getRandom, 我们必须要用有 random access的数据结构， 所以一定要用vector elts来存 之前insert过的element

- 同时我们要去重， 而且要 delete() 也是 O(1), 所以我们需要一个hashmap，记录的是每个elt 在 vector elts里的idx
