# leetcode
重点

430 - flatten list. 实际上是二叉树的先序遍历！

328 - odd even list. 以及 86 - partion list. list2 next 需要置空!

1171 - remove 0 sum nodes. 前缀和问题。注意，单次扫描未完成。

124 - Max Path Sum. 路径从任意节点开始。 注意，关键在于maxGain() 函数

145 - Post order. 注意，当前使用了 pair<TreeNode *, bool>. 尝试采用另一种迭代。

offer_38 - All permutations. 当前使用了回溯，注意去重条件。尝试使用next_permutation。
offer_38 - All permutations. 用next_permutation 实现。重点：找到逆序对；找到后缀中最小的大于当前值的位置(同时也是最靠后的一个大于当前值的)；交换；翻转当前位置以后的序列。

TEST
