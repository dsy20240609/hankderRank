using two stacks to simulate min stack, not using priority queue.
很好的问题 👍
其实实现 MinStack（最小栈） —— 不需要也不推荐用 priority_queue。

🚫 为什么不用 priority_queue

虽然 priority_queue 可以快速取出最小值或最大值，但它：

不能删除栈顶之外的元素（只能弹出最值）；

不能保证与栈同步（LIFO 顺序）；

因此不能满足 “栈” 的语义（先进后出 + 同步最小值）。

✅ 正确做法：用 两个栈

我们可以用：

一个普通栈 stack<int> s 存放所有值；

一个辅助栈 stack<int> minStack 存放 当前最小值。