#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// possible correct answer 
int longestArithmeticSubsequence(vector<int>& arr, int k) {
    unordered_set<int> uniqueArr(arr.begin(), arr.end()); // 去重
    unordered_map<int, int> dp; // dp[x] 表示以 x 为结尾的最长长度

    int maxLen = 0;
    for (int x : uniqueArr) {
        // 如果 x-k 存在，那么以 x 结尾的长度 = dp[x-k] + 1
        dp[x] = dp.count(x - k) ? dp[x - k] + 1 : 1;
        maxLen = max(maxLen, dp[x]);
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int result = longestArithmeticSubsequence(arr, k);
    cout << result << endl;

    return 0;
}

// *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER k
 */

int findLongestArithmeticProgression(vector<int> arr, int k) {
    // 
    std::sort(arr.begin(), arr.end());

    // 
    auto it = std::unique(arr.begin(), arr.end());

    // 
    arr.erase(it, arr.end());
    vector<int> n(arr.size(),1);
    if(arr.empty()) {return 0;}
    // i can think of the dynamic programming algorithm, but i don't know the detail
    // use some thing to record the previous numbers' max subsequence with given difference
    // but i didn't make use of the relationship between n and n-1
    for(size_t i = 0 ; i < arr.size();++i) {
        int count=1;
        for(size_t j = i+1; j< arr.size();++j) {
            if(arr[j]-arr[j-1] == k) {
                count++;
                continue;
            } else {
                n[i] = count;
                break;
            }
        }
    } 
    int max=n[0];
    for(size_t i =0;i< n.size();++i) {
        if(n[i]>max) {
            max=n[i];
        }
    }
    return max;
}


逻辑问题：你只检查了连续元素的差值是否为 k，但是最长等差子序列 不一定是连续的。

例如数组 [1, 3, 2, 5, 7]，k=2。按照你现在的逻辑，只会看到 [1,3] 或 [5,7]，无法找到 [1,3,5,7]。
排序了变成了 1 2 3 5 7 也无法找到 1 3 5 7 这个数列
复杂度高：内层循环是 O(n²)，对于 n=10^5 会超时。
2. 正确高效的方法

使用 哈希表 + 动态规划，时间复杂度 O(n)：

int findLongestArithmeticProgression(vector<int> arr, int k) {
    unordered_set<int> uniqueArr(arr.begin(), arr.end()); // 去重
    unordered_map<int, int> dp; // dp[x] 表示以 x 为结尾的最长长度

    int maxLen = 0;
    for (int x : uniqueArr) {
        dp[x] = dp.count(x - k) ? dp[x - k] + 1 : 1;
        maxLen = max(maxLen, dp[x]);
    }

    return maxLen;
}

✅ 特点：

自动去重

不要求数组排序

时间复杂度 O(n)

逻辑正确，最长等差子序列可以是不连续的



int findLongestArithmeticProgression(vector<int>& arr, int k) {
    if (arr.empty()) return 0;

    //
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    unordered_map<int, int> dp;
    int maxLen = 0;

    for (int x : arr) {
        dp[x] = dp.count(x - k) ? dp[x - k] + 1 : 1;
        maxLen = max(maxLen, dp[x]);
    }

    return maxLen;
}
// 需要排序加去重
