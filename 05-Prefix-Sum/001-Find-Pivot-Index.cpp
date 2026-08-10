
Problem    : Find Pivot Index
Platform   : LeetCode
Problem No.: 724
Pattern    : Prefix Sum
Difficulty : Easy

Intuition :
- A pivot index i is an index where the sum of all
  elements to its left is equal to the sum of all
  elements to its right.
- The pivot element itself is not included in either
  left sum or right sum.

-------------------------------------------------------

Approach 1 (Brute Force - Prefix + Suffix Arrays)

Idea :
- Store the left-side sum and right-side sum for
  every index separately.

Step 1 : Prefix Array

- prefix[i] stores the sum of all elements before i.

      prefix[i] =
          nums[0] + nums[1] + ... + nums[i-1]

- Therefore:

      prefix[0] = 0

Step 2 : Suffix Array

- suffix[i] stores the sum of all elements after i.

      suffix[i] =
          nums[i+1] + ... + nums[n-1]

- Therefore:

      suffix[n-1] = 0

Step 3 : Compare

- For every index:

      if (prefix[i] == suffix[i])
          return i;

- If no pivot index exists:

      return -1;

Time Complexity  : O(n)

Space Complexity : O(n)

-------------------------------------------------------

Approach 2 (Optimal - Total Sum + Running Left Sum)

Intuition :
- We do not need to store a separate suffix array.
- First calculate the total sum of the entire array.
- At index i, the total sum can be divided into:

      leftSum + nums[i] + rightSum

Therefore:

      rightSum =
          totalSum - leftSum - nums[i];

- Now compare leftSum and rightSum.

Approach :
- First calculate:

      totalSum = sum of all elements

- Initialize:

      leftSum = 0

- Traverse the array from left to right.

- For every index i:

      rightSum =
          totalSum - leftSum - nums[i];

- Check:

      if (leftSum == rightSum)
          return i;

- Only after the comparison, add the current element
  to leftSum:

      leftSum += nums[i];

- If no pivot index is found:

      return -1;

Important Invariant :
- At the time of comparison:

      leftSum = sum of elements strictly before i

      rightSum = sum of elements strictly after i

- Therefore, nums[i] must NOT be added to leftSum
  before checking the pivot condition.

Why does this work?
- The total sum already contains every element.
- Removing the current element and the left-side sum
  leaves exactly the right-side sum.

      totalSum
          ↓
      leftSum + nums[i] + rightSum

      rightSum =
      totalSum - leftSum - nums[i]

Time Complexity  : O(n)

Space Complexity : O(1)




class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;

        for(int x : nums){
            sum+=x;
        }

        if(sum - nums[0] == 0)
          return 0;

        int left=0;
       
        for(int i=1; i<nums.size(); i++){
           
            left+=nums[i-1];
            int right= sum-left-nums[i];

            if(left==right){
                return i;
            }
        }
        return -1;
    }
};
