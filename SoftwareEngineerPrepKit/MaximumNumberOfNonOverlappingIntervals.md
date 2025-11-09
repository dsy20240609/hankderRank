Input:

meetings = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output:

3

Explanation:

Step 1: Sort meetings by end time → [[1,2],[2,3],[1,3],[3,4]].
Step 2: Select [1,2] (count=1, last_end=2).
Step 3: [2,3] has start 2 ≥ 2, select (count=2, last_end=3).
Step 4: [1,3] start 1 < 3, skip.
Step 5: [3,4] start 3 ≥ 3, select (count=3). Result = 3.

actually i am not fully understand this algorithm.
you need to keep record of preEnd and compare it with the next start. 