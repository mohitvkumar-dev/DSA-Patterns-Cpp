/*
-------------------------------------------------------
Problem    : Maximum Absolute Sum of Any Subarray
Platform   : LeetCode
Problem No.: 1749
Pattern    : Kadane's Algorithm (Max + Min Variant)
Difficulty : Medium

Intuition :
- We need to maximize the absolute value of a
  subarray sum.
- Because of absolute value, the answer can come
  from either:

    1. A very large positive subarray sum.
    2. A very small (most negative) subarray sum.

Example:

    maxSubarraySum =  8  -> abs = 8
    minSubarraySum = -12 -> abs = 12

    Answer = 12

- Therefore, normal Kadane's Algorithm alone is
  not enough.
- We need to find both:
      maxSum -> Maximum subarray sum.
      minSum -> Minimum subarray sum.



Approach :
- Initialize:

      maxEnding = nums[0]
      minEnding = nums[0]

      maxSum = nums[0]
      minSum = nums[0]

- Traverse the array from index 1.

- For every nums[i]:

    • Find the maximum subarray sum ending at i:

      maxEnding =
          max(nums[i], maxEnding + nums[i]);

      maxSum =
          max(maxSum, maxEnding);


    • Find the minimum subarray sum ending at i:

      minEnding =
          min(nums[i], minEnding + nums[i]);

      minSum =
          min(minSum, minEnding);

- Finally, compare the absolute values of both
  extremes:

      answer =
          max(abs(maxSum), abs(minSum));

- Return answer.

Why does this work?
- Absolute value converts both large positive and
  large negative sums into positive candidates.
- Therefore, the maximum absolute sum must come
  from one of the two extremes:
      • Maximum subarray sum.
      • Minimum subarray sum.
- Kadane's Algorithm finds both extremes in a
  single traversal.

Time Complexity  : O(n)

Space Complexity : O(1)






  class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnding=nums[0];
        int minEnding=nums[0];
        int minSum=nums[0];
        int maxSum=nums[0];
        

        for(int i=1; i<nums.size(); i++){
            maxEnding=max(nums[i], maxEnding+nums[i]);
            maxSum= max(maxSum,maxEnding);

            minEnding=min(nums[i], minEnding+nums[i]);
            minSum=min(minSum,minEnding);
        }

        return max(abs(maxSum),abs(minSum));
    }
};
