# Problem Description 

Given a sum of elements (n) and a number of elements (k), find the number of distinct arrays under these conditions:

    In each array, the there are k elements whose sum is equal to n.

    In each array, each element should be greater than or equal to the element on its left.

    The elements formed in each array are distinct

Edit: elements have to be positive integers

Example:

n = 8 k = 4

Answer: 5

Explanation: [1,1,1,5], [1,1,2,4], [1,1,3,3], [1,2,2,3], [2,2,2,2]

Each array has 4 (k) elements a sum of 8 (n) with each element on the left <= element on the right. There are 5 possible distinct options.

This problem screams dynamic programming but I just don't know how to solve it. Would prefer a bottom-up solution

Explanations

```
- Hey it is indeed solvable with dynamic programming with O(n * k) time complexity, but first you need to do some math to derive a recurrence relation that is required for your DP solution. So, it's actually a bit math-intensive and not a good interview question IMHO (unless you were interviewing for a maths position that happens to also require coding).

- Math solution: let P(n, k) denote the number of distinct (order insignificant) ways to write n as the sum of k positive numbers -- let's call each of the distinct ways to sum up to n a "partition".
The recurrence relation you need for DP is P(n, k) = P(n - k, k) + P(n - 1, k - 1).

    - There will be partitions with all numbers larger than 1, and the number of those partitions is equal to P(n - k, k). Reason: for each of such partitions, if you subtract 1 from each number, you get a partition of (n - k) into k positive integers. Conversely, for each partition of (n - k), adding 1 to each number gives you a partition of n with each number larger than 1. So, there is a 1-1 mapping between those partitions and the partitions of (n - k) into k positive integers.
    Therefore the number of partitions of n into k numbers such that all numbers are larger than 1 is P(n - k, k).

    - All other partitions have at least one number being 1. For each of those, deleting one of the 1s gives you a partition of (n - 1) into (k - 1) positive integers. The mapping in the reverse direction also holds (i.e., by adding a 1 to a partition of (n - 1) into (k - 1) positive integers). So, there is a 1-1 mapping between those partitions and the partitions of (n - 1) into k positive integers.
    Therefore the number of partitions of n into k numbers such that at least one number is 1 is P(n - 1, k - 1).

- So combining both lines of reasoning above, we have P(n, k) = P(n - k, k) + P(n - 1, k - 1).

- Also notice with this recurrence relation you can start from P(1, 1) and get to P(n, k) iteratively in a double for-loop. So, it is bottom-up as well, as you wished.
```

Reference :https://math.stackexchange.com/questions/1908701/integer-partition-of-n-into-k-parts-recurrence
