
Problem    : Maximum Sum Circular Subarray
Platform   : LeetCode
Problem No.: 918
Pattern    : Kadane's Algorithm (Circular Variant)
Difficulty : Medium

Intuition :
- Normal Kadane's Algorithm finds the maximum sum
  subarray in a linear array.
- Here, the array is circular, so the maximum subarray
  can also wrap from the end back to the beginning.

There are two possible cases:

1. Normal Subarray:
   - The maximum subarray does not wrap around.
   - Find it using normal Kadane's Algorithm.

2. Circular Subarray:
   - The maximum subarray wraps from the end to the
     beginning.
   - Instead of directly finding the wrapped subarray,
     think about the part that is NOT selected.
   - The removed part must be a continuous minimum-sum
     subarray.

Therefore:

    Circular Sum = Total Sum - Minimum Subarray Sum

So the final answer is:

    max(
        Maximum Subarray Sum,
        Total Sum - Minimum Subarray Sum
    )

Important Edge Case :
- If all elements are negative, then:

      maxSum < 0

- In this case:

      totalSum - minSum = 0

  which represents an empty subarray, but an empty
  subarray is not allowed.
- Therefore, if all elements are negative, return
  maxSum directly.

Approach :
- Maintain:

      totalSum
      maxEnding
      maxSum
      minEnding
      minSum

- Initialize all Kadane states using nums[0].

- Traverse the array from index 1.

Step 1 : Calculate Total Sum

      totalSum += nums[i];

Step 2 : Maximum Kadane

- At every index, either start a new subarray or
  extend the previous maximum subarray.

      maxEnding =
          max(nums[i],
              maxEnding + nums[i]);

      maxSum =
          max(maxSum,
              maxEnding);

Step 3 : Minimum Kadane

- At every index, either start a new subarray or
  extend the previous minimum subarray.

      minEnding =
          min(nums[i],
              minEnding + nums[i]);

      minSum =
          min(minSum,
              minEnding);

Step 4 : Handle All-Negative Case

      if (maxSum < 0)
          return maxSum;

- Otherwise, the answer can be either a normal
  maximum subarray or a circular subarray.

      return max(maxSum,
                 totalSum - minSum);

Why does this work?
- A non-wrapping maximum subarray is directly found
  by maximum Kadane.
- A wrapping maximum subarray consists of the total
  array excluding one continuous minimum-sum subarray.
- Therefore: 

 Circular Maximum
      = Total Sum - Minimum Subarray Sum

- Taking the maximum of these two cases gives the
  overall maximum circular subarray sum.

Time Complexity  : O(n)

Space Complexity : O(1)



  class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int totalSum = nums[0];

        int maxEnding = nums[0];
        int maxSum = nums[0];

        int minEnding = nums[0];
        int minSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            totalSum += nums[i];

            // Maximum Kadane
            maxEnding = max(nums[i],
                            maxEnding + nums[i]);
            maxSum = max(maxSum,
                         maxEnding);

            // Minimum Kadane
            minEnding = min(nums[i],
                            minEnding + nums[i]);
            minSum = min(minSum,
                         minEnding);
        }

        // All elements are negative
        if (maxSum < 0)
            return maxSum;

        return max(maxSum,
                   totalSum - minSum);
    }
};
