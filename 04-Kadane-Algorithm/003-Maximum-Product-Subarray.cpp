
Problem    : Maximum Product Subarray
Platform   : LeetCode
Problem No.: 152
Pattern    : Kadane's Algorithm (Product Variant)
Difficulty : Medium

Intuition :
- Similar to Maximum Subarray (LC 53), use the
  "ending at i" idea.
- In maximum sum, tracking only the maximum value
  ending at the current index is enough.
- But in product, negative numbers can completely
  change the result because:

      Negative × Negative = Positive

- Therefore, the current minimum product may become
  the maximum product after multiplying by a negative
  number.

- Hence, at every index we maintain:

      maxEnding = Maximum product subarray
                  ending exactly at index i.

      minEnding = Minimum product subarray
                  ending exactly at index i.

At every index i, there are three possibilities:

1. Start a new subarray:
      nums[i]

2. Continue with previous maximum:
      prevMax * nums[i]

3. Continue with previous minimum:
      prevMin * nums[i]

Therefore:

maxEnding = max(nums[i],
                prevMax * nums[i],
                prevMin * nums[i]);

minEnding = min(nums[i],
                prevMax * nums[i],
                prevMin * nums[i]);

Why do we need minEnding?
- A large negative product may look useless now,
  but if another negative number appears later,
  it can become a large positive product.

Example:

      prevMin = -6
      nums[i] = -4

      (-6) * (-4) = 24

- Therefore, the previous minimum can become the
  new maximum.

Approach :
- Initialize:

      maxEnding = nums[0]
      minEnding = nums[0]
      answer    = nums[0]

- Traverse from index 1.

- Before updating, store the previous values:

      prevMax = maxEnding
      prevMin = minEnding

- For every nums[i], calculate:

      maxEnding = max(nums[i],
                      prevMax * nums[i],
                      prevMin * nums[i]);

      minEnding = min(nums[i],
                      prevMax * nums[i],
                      prevMin * nums[i]);

- Update the global answer:

      answer = max(answer, maxEnding);

- Return answer.

Important :
- Do not compare minEnding with the final answer.
- minEnding is maintained only because it may become
  a future maximum after multiplication by a negative
  number.

Time Complexity  : O(n)

Space Complexity : O(1)



  class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnd=nums[0];
        int minEnd=nums[0];
        int ans=nums[0];

        for(int i=1; i<nums.size(); i++){
            int v1=nums[i];
            int v2=minEnd*nums[i];
            int v3=maxEnd*nums[i];

            maxEnd=max(v1,max(v2,v3));
            minEnd=min(v1,min(v2,v3));

            ans= max(ans,max(maxEnd,minEnd));
        }
        return ans;
    }
};
