
Problem    : Minimum Sum Subarray
Pattern    : Kadane's Algorithm (Minimum Variant)

Intuition :
- Every minimum-sum subarray must end at some index i.
- Therefore, at every index, calculate the minimum
  subarray sum that ends exactly at that index.

- At every index i, we have two choices:

  1. Continue the previous minimum-sum subarray:
         bestEnding + nums[i]

  2. Discard the previous subarray and start fresh
     from the current element:
         nums[i]

- Since we need the minimum sum, choose the smaller
  of these two choices:

      bestEnding = min(nums[i],
                       bestEnding + nums[i]);

- bestEnding represents the minimum subarray sum
  ending exactly at the current index.

- answer represents the minimum subarray sum found
  anywhere in the array.

Approach :
- Initialize:
      bestEnding = nums[0]
      answer = nums[0]

- Traverse the array from index 1.

- For every nums[i]:
    • Decide whether to continue the previous subarray
      or start a new subarray from nums[i].

      bestEnding = min(nums[i],
                       bestEnding + nums[i]);

    • Update the global minimum:

      answer = min(answer, bestEnding);

- Return answer.

Why does this work?
- Any subarray ending at index i either:
    • extends the best subarray ending at i-1, or
    • starts fresh from index i.
- Since we want the minimum sum, we choose the smaller
  of these two possibilities at every index.

Time Complexity  : O(n)

Space Complexity : O(1)




class Solution {
  public:
    int smallestSumSubarray(vector<int>& arr) {
        // Code here
        int bestEnding=arr[0];
        int ans=arr[0];
        
        for(int i=1; i<arr.size(); i++){
            int v1= bestEnding+arr[i];
            int v2= arr[i];
            
            bestEnding=min(v1,v2);
            
            ans=min(ans,bestEnding);
        }
        return ans;
    }
};  
