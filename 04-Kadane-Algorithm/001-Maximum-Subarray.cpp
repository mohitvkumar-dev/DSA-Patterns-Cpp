
Problem    : Maximum Subarray
Platform   : LeetCode
Problem No.: 53
Pattern    : Kadane's Algorithm
Difficulty : Medium

Intuition :
- Every maximum subarray must end at some index i.
- Therefore, at every index, calculate the maximum
  subarray sum that ends exactly at that index.
- Let bestEnding represent the maximum subarray sum
  ending at the current index.

At every index i, we have exactly two choices:

1. Continue the previous subarray:
      bestEnding + nums[i]

2. Discard the previous subarray and start a new
   subarray from the current element:
      nums[i]

Therefore:

    bestEnding = max(nums[i],
                     bestEnding + nums[i]);

- bestEnding is a local state: the best subarray
  ending at the current index.
- answer is the global maximum among all bestEnding
  values.

Approach :
- Initialize:
      bestEnding = nums[0]
      answer = nums[0]

- Start traversing from index 1.

- For every nums[i]:
    • Calculate whether it is better to continue the
      previous subarray or start fresh from nums[i].

      bestEnding = max(nums[i],
                       bestEnding + nums[i]);

    • Update the global maximum:

      answer = max(answer, bestEnding);

- After processing the entire array, return answer.

Why initialize with nums[0]?
- The array may contain only negative numbers.
- Initializing answer with 0 would incorrectly allow
  an empty subarray.

Example:
    nums = [-5, -2, -8]

Correct answer = -2

Therefore:
    bestEnding = nums[0]
    answer = nums[0]

Why does this work?
- At every index, any subarray ending there either:
    • extends the best subarray ending at i-1, or
    • starts fresh from the current element.
- There is no third possibility.
- By finding the best ending at every index and taking
  the maximum among them, we obtain the maximum
  subarray sum.

Time Complexity  : O(n)

Space Complexity : O(1)



  class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestEnding=nums[0];
        int ans=nums[0];

        for(int i=1; i<nums.size(); i++){
           int v1=bestEnding+nums[i];
           int v2=nums[i];

           bestEnding=max(v1,v2);

           ans=max(ans,bestEnding);
        }
        return ans;
    }
};
