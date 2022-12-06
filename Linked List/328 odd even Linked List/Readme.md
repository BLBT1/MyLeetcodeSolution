# 328 Odd Even Linked List

## 需要注意

- 首先要思考需要保存的node是哪些， 这里是oddHead 和 evenHead

- 其次注意的是如果odd-> next 位置更新后，直接 odd = odd->next 就可以跳过去了。 even 同理
