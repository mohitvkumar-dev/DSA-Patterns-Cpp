
Problem    : Range Sum Query - Immutable
Platform   : LeetCode
Problem No.: 303
Pattern    : Prefix Sum
Difficulty : Easy

Intuition :
- We need to answer multiple range-sum queries:

      sumRange(left, right)

- The array is immutable, meaning its values do not
  change after initialization.

-------------------------------------------------------

Approach 1 (Brute Force)

Idea :
- For every query, traverse from left to right and
  calculate the sum directly.

      for (int i = left; i <= right; i++)
          sum += nums[i];

- The same elements may be added repeatedly for
  different queries.

Complexity :

Constructor:
    O(n)      // storing/copying the input array

Each Query:
    O(right - left + 1)

Worst Case:
    O(n)

For q queries:
    O(q * n)

Space:
    O(n)

Problem :
- If there are many queries, repeatedly calculating
  the same range sums becomes expensive.

-------------------------------------------------------

Approach 2 (Optimized - Prefix Sum)

Intuition :
- Since the array is immutable, we can do some
  preprocessing once in the constructor.
- Build a prefix sum array so that every range sum
  can be calculated using subtraction in O(1).

Definition:

    prefix[i] = sum of first i elements

Therefore:

    prefix[0] = 0

    prefix[i + 1] =
        prefix[i] + nums[i]

-------------------------------------------------------

Range Sum Formula

For query:

    sumRange(left, right)

We use:

    prefix[right + 1] - prefix[left]

Why?

    prefix[right + 1]
        = sum from index 0 to right

    prefix[left]
        = sum from index 0 to left - 1

Subtracting them removes the common prefix:

    prefix[right + 1] - prefix[left]
        = sum from left to right

-------------------------------------------------------

Approach :

1. Create a prefix array of size n + 1.

      prefix.resize(n + 1);

2. Initialize:

      prefix[0] = 0;

3. Build the prefix sum:

      for (int i = 1; i < n; i++)
          prefix[i] =
              prefix[i-1] + nums[i-1];

4. For every query:

      return prefix[right + 1] - prefix[left];

-------------------------------------------------------

Why n + 1 size?

- nums contains n elements.
- We also need prefix[0] to represent the sum of
  the first 0 elements.

Therefore:

      prefix has n + 1 elements.


This makes the range-sum formula uniform for every
possible left index, including left = 0.

-------------------------------------------------------

Why prefix[0] = 0?

- The sum of the first 0 elements is 0.
- It acts as the base case.

First iteration:

    prefix[1]
        = prefix[0] + nums[0]
        = 0 + nums[0]

-------------------------------------------------------

Important Trade-off :

Brute Force:

    Preprocessing : O(n)
    Query         : O(n)

Prefix Sum:

    Preprocessing : O(n)
    Query         : O(1)

Since the array is immutable and there may be many
queries, doing O(n) preprocessing once is better than
recalculating every range repeatedly.

-------------------------------------------------------

Time Complexity :

Constructor / Prefix Sum : O(n)

Each sumRange Query      : O(1)

Space Complexity         : O(n)

--------------


class NumArray {
public:
vector<int>sum;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        sum.resize(n+1);
    
        sum[0]=0;
        for(int i=1 ; i<=n; i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        
        return sum[right+1]-sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
