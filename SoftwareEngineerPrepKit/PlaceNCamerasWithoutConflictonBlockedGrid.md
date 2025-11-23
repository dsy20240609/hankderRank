I can also recognize this problems as the sub problem of N queues and the different is the there are grid location marked with 1 which means that it
is a block already, and the return value of n queue is a combination of successfully placement.
主要问题

allZero(grid[n])

你的意思应该是“这一行还有空位可以放摄像头”，但 grid[n] 中原来的值 1 表示阻挡格子。

allZero 会返回 false 如果有任何阻挡格子，所以你可能直接跳过了合法行。

递归参数混乱

你用 index 作为行号，但同时又在标记对角线时用 index - i + r、i + index - r，逻辑不够清晰，容易错。

n 表示剩余要放的摄像头数，但在循环里你直接用 n 作为行索引，这会导致访问越界或者跳过行。

回溯标记方法太复杂

你在放置摄像头后把整行、整列和对角线全部标为 1，再递归，然后再改回 0。

这种直接在 grid 上修改的方法不仅容易覆盖原本阻挡格子，也难以管理对角线标记。

行/列对角线冲突没有单独标记

对于 N 皇后类问题，一般用三个数组标记 列、主对角线、副对角线，这样不会破坏原始 grid，也更高效。