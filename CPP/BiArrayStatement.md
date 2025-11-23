You are given four integers: , , , . You will use them in order to create the sequence  with the following pseudo-code.

a[0] = S (modulo 2^31)
for i = 1 to N-1
    a[i] = a[i-1]*P+Q (modulo 2^31) 
Your task is to calculate the number of distinct integers in the sequence .

Input Format

Four space separated integers on a single line, , , , and  respectively.

Output Format

A single integer that denotes the number of distinct integers in the sequence .

Constraints




Sample Input

3 1 1 1
Sample Output

3
Explanation


Hence, there are  different integers in the sequence.

chat gpt hint

🧠 Key Idea

This is a linear congruential generator (LCG), and the sequence will eventually repeat (it forms a cycle).
So instead of generating all N values (which could be very large), we can stop when we detect a repeat.

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    long long N, S, P, Q;
    cin >> N >> S >> P >> Q;

    const long long MOD = 1LL << 31;

    long long a = S % MOD;
    unordered_set<long long> seen;
    seen.insert(a);

    for (long long i = 1; i < N; ++i) {
        a = (a * P + Q) % MOD;
        seen.insert(a);
        if (seen.size() < i + 1) break; // found a duplicate → sequence starts repeating
    }

    cout << seen.size() << endl;
    return 0;
}

⚡ Optimized (No Extra Memory)

If memory is a concern, you can use Floyd’s cycle detection to find when repetition starts, then calculate distinct count without a set.

Would you like me to show that optimized version (O(1) space)?

Perfect 👍 — here’s the optimized C++ solution using Floyd’s Cycle Detection (Tortoise and Hare) —
so you can find the number of distinct elements in the sequence a efficiently in O(N) time and O(1) memory.

#include <iostream>
using namespace std;

int main() {
    long long N, S, P, Q;
    cin >> N >> S >> P >> Q;

    const unsigned long long MOD = 1ULL << 31;

    auto next = [&](unsigned long long x) {
        return (x * P + Q) % MOD;
    };

    // Step 1: Detect cycle using Floyd’s algorithm
    unsigned long long tortoise = next(S);
    unsigned long long hare = next(next(S));
    while (tortoise != hare) {
        tortoise = next(tortoise);
        hare = next(next(hare));
    }

    // Step 2: Find start of the cycle (mu)
    unsigned long long mu = 0;
    tortoise = S;
    while (tortoise != hare) {
        tortoise = next(tortoise);
        hare = next(hare);
        mu++;
    }

    // Step 3: Find cycle length (lambda)
    unsigned long long lambda = 1;
    hare = next(tortoise);
    while (tortoise != hare) {
        hare = next(hare);
        lambda++;
    }

    // Step 4: The number of distinct elements is:
    // either N (if we never reach the cycle),
    // or min(N, mu + lambda)
    unsigned long long distinct = (N < mu + lambda) ? N : (mu + lambda);

    cout << distinct << endl;
    return 0;
}

🧩 Explanation

next(x) — generates the next element in the sequence:

𝑎
[
𝑖
]
=
(
𝑎
[
𝑖
−
1
]
∗
𝑃
+
𝑄
)
 
m
o
d
 
2
31
a[i]=(a[i−1]∗P+Q)mod2
31

Floyd’s Cycle Detection:

Uses two pointers (tortoise, hare) moving at different speeds.

When they meet → a cycle exists.

Then find:

μ = index where the cycle starts

λ = length of the cycle

The total number of distinct values:

If sequence length N ends before the cycle starts → distinct = N

Otherwise → distinct = μ + λ

this problem is related to bit array

Excellent observation 💡 — yes, you’re absolutely right.

This “distinct elements in LCG sequence” problem can also be solved using a bit array (bitset / bitmap) approach —
that’s the most direct and practical method used in competitive programming when memory allows it.

Let’s unpack how that works 👇

🧩 1. Why “bit array” applies here

The modulus is fixed:

MOD = 2^31 = 2147483648


That means every generated number a[i] lies in [0, 2^31 - 1].

To know if a value has appeared before, you could track it in a boolean array of size 2^31 —
but that would require 2^31 bytes ≈ 2 GB, which is too big.

However, since each value is just “seen or not seen,”
you can store one bit per value — that’s only 2^31 bits = 256 MB, which is heavy but feasible in C++ (with std::vector<unsigned int> or std::bitset if memory allows).

🧠 2. Bit array idea

We create a bit array seen where:

Each index corresponds to a possible value in [0, 2^31)

Each bit indicates whether the value has been seen

Then:

Generate sequence a[i] normally

Check if its bit is already set

If yes → repetition → stop

If no → mark it

Count how many unique values we saw before stopping or reaching N

#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long long N, S, P, Q;
    cin >> N >> S >> P >> Q;

    const unsigned long long MOD = 1ULL << 31;

    vector<unsigned int> bits((1ULL << 31) / 32, 0); // 2^31 bits = 256 MB
    auto setBit = [&](unsigned long long x) {
        bits[x >> 5] |= (1U << (x & 31));
    };
    auto getBit = [&](unsigned long long x) -> bool {
        return bits[x >> 5] & (1U << (x & 31));
    };

    unsigned long long a = S % MOD;
    unsigned long long count = 0;

    for (unsigned long long i = 0; i < N; ++i) {
        if (getBit(a)) break;
        setBit(a);
        count++;
        a = (a * P + Q) % MOD;
    }

    cout << count << endl;
    return 0;
}


| Method                      | Memory                         | Speed         | Comment                                     |
| --------------------------- | ------------------------------ | ------------- | ------------------------------------------- |
| `unordered_set`             | O(N) (~8–16 bytes per element) | Fast          | Easy to implement but memory heavy          |
| **Bit array**               | **256 MB fixed**               | **Very fast** | Excellent tradeoff if you have RAM          |
| **Floyd’s cycle detection** | **O(1)**                       | O(N)          | Theoretically best; no memory use           |
| Hybrid                      | O(1–small)                     | O(N)          | Combine Floyd for detection + partial cache |
