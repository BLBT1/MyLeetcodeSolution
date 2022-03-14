# 33. Search in Rotated Sorted Array

```rotated array``` 可以被分成两个 sorted array, 如以下:

```html

        0 1 2 3 4 5 6
nums: [4 5 6 7 0 1 2]
upper:[4 5 6 7]
lower:        [0 1 2]

```

- 所以当我们用二分搜索的时候我需要考虑 mid 可能出现在 upper 和 lower两个地方

- 如何知道 mid 在哪个部分呢？我们注意到， 所有upper 的数字都 >= nums[left], 而所有的lower的数字都是 < nums[left]

- 当 mid 在 upper， 我们需要考虑:

  - nums[l] <= target <= nums[mid]
    - mid 和 l 都可能是 target -> r = mid;

  - target > nums[mid]
    - mid = l+1

- 当 mid 在 lower， 我们需要考虑：
  - nums[mid] < target <= nums[right]
    - l = l+1
  - target >= nums[mid]
    - r = mid;
