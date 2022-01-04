# 147. Insertion Sort List

### Insertion Sort
- 确保我们保持最左边的 list 是sorted的
- 在我的implementation 里， curr是sorted list 的最后一个
- ```curr->next``` 是我们正在 examine 的数字， 
    - 如果他比他前面的curr的数字大： 什么都不用干，直接curr = curr->next来增加 sorted list的大小
    - 不然我们需要重新把curr->next 插到 sorted list 里正确的位置：
        - 注意一般在 ```array``` 里 implement ```insertion sort```, 我们的习惯思维都是不断往前swap直到他在正确的位置。 
        - 而 ```singly linked list```里往前swap是很麻烦的事情，所以我们要做两步：
            1. remove 当前的node
            2. 从sorted list 的 第一个数字开始， ```从前往后```找到正确的位置，再插入 当前的node 

### time
 O(N^2)

### space
O(1)