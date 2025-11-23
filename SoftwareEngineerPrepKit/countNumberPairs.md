💡 解题思路：双指针 O(n)

因为数组是已排序的正整数，我们可以用两端指针来高效统计：

left = 0, right = n - 1

如果 arr[left] + arr[right] <= target：

所有从 left 到 right-1 的组合都满足条件（因为数组递增）

所以增加 count += (right - left)

然后移动左指针 left++

否则（太大）：

需要减小和，移动右指针 right--

举例 
prices = [1,2,3,4,5]
budget = 7
1+5 =6 < 7
so 1,5/1,2/1,3/1,4 are all workable pairs
then move left to check, if exceed the budget, then move right
use the feature that the vector are sorted, you can complete this on O(n) times

if not sorted, two level loops will take O(n2)
