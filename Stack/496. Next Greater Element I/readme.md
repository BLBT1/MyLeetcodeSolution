# 496. Next Greater Element I

- 因为要找到每个 elt 的 ```next greater element```， 所以要从后往前traverse nums，并且保持 单调栈 non-increasing， 这样栈顶元素肯定是 ```next greater element```

- 因为要找到后面比他大的数字中最小的一个， 所以是单调递减，
