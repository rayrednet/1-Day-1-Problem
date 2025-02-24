## Problem: Climbing Stairs (LeetCode)  
[View problem on LeetCode](https://leetcode.com/problems/climbing-stairs/description/?envType=problem-list-v2&envId=dynamic-programming)

### A. Problem Statement 💁‍♀️  
You are climbing a staircase. It takes `n` steps to reach the top.  
Each time you can either climb **1 or 2 steps**. How many distinct ways can you climb to the top?  

### B. Problem Examples 😌  
#### ✨ Example 1:
**Input:** `n = 2`  
**Output:** `2`  
**Explanation:** There are two ways to climb to the top:
1. 1 step + 1 step
2. 2 steps  

#### ✨ Example 2:
**Input:** `n = 3`  
**Output:** `3`  
**Explanation:** There are three ways to climb to the top:
1. 1 step + 1 step + 1 step  
2. 1 step + 2 steps  
3. 2 steps + 1 step  

### C. Problem Constraints 🫡  
`1 <= n <= 45`

---

### D. My Approach 😁  
We can observe that to reach step `n`, we can either:  
- Take **one step** from `n-1`  
- Take **two steps** from `n-2`  

This means the number of ways to reach `n` is the sum of ways to reach `n-1` and `n-2`.  
This follows the **Fibonacci sequence**:

\[ f(n) = f(n-1) + f(n-2) \]

with base cases:
- `f(1) = 1`
- `f(2) = 2`

Let's analyze a few cases:
| `n`  | Ways to climb |
|------|--------------|
| `1`  | 1 (1) |
| `2`  | 2 (1+1, 2) |
| `3`  | 3 (1+1+1, 1+2, 2+1) |
| `4`  | 5 (1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2) |
| `5`  | 8 (1+1+1+1+1, 1+1+1+2, 1+1+2+1, 1+2+1+1, 2+1+1+1, 2+2+1, 2+1+2, 1+2+2) |

---

### E. Recursive Approach (Exponential Time Complexity) 🚀  
A simple recursive approach follows the Fibonacci pattern:
```python
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        return self.climbStairs(n - 1) + self.climbStairs(n - 2)
```

However, this approach **recomputes values multiple times**, leading to **O(2^n) exponential time complexity**.
For example, when `n = 5`:
```plaintext
climb_stairs(5)
  ├─ climb_stairs(4)
  │   ├─ climb_stairs(3)
  │   │   ├─ climb_stairs(2)  ✅
  │   │   ├─ climb_stairs(1)  ✅
  │   ├─ climb_stairs(2)  ❌ (redundant)
  ├─ climb_stairs(3)
      ├─ climb_stairs(2)  ❌ (redundant)
      ├─ climb_stairs(1)  ✅
```
The call `climb_stairs(2)` **is computed multiple times**, making this approach inefficient.

---

### F. Optimized Approach: Memoization (Top-Down DP) 🏎️💨  
To avoid redundant calculations, we use **memoization** with `@lru_cache(None)`, which stores already computed values:
```python
from functools import lru_cache

class Solution:
    @lru_cache(None)
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2
        return self.climbStairs(n - 1) + self.climbStairs(n - 2)
```
This reduces the **time complexity to O(n)** while still using recursion.

---

### G. Optimized Approach: Bottom-Up DP (Iterative) 🏆  
A **better solution** avoids recursion altogether by using **Dynamic Programming (Bottom-Up Approach)**:
```python
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2

        prev1, prev2 = 2, 1  # Base cases
        for _ in range(3, n + 1):
            current = prev1 + prev2
            prev2 = prev1
            prev1 = current

        return prev1  # Final answer
```
✅ **Time Complexity:** `O(n)`  
✅ **Space Complexity:** `O(1)` (No extra memory used)

---

### H. Submission Details 🎯  

#### **Python Submission:**  
![Python Submission](img/python.png)  

---
### **Final Thoughts** ✨
- The naive recursive approach is **too slow** for large `n`.
- Memoization (**Top-Down DP**) speeds it up but still **uses recursion**.
- **Bottom-Up DP (Iterative)** is the **best approach** 🚀 (fast and memory efficient).

This problem is a great introduction to **Dynamic Programming (DP)** because it follows a **Fibonacci-like recurrence**. 💡

