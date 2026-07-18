
Problem    : Minimum Size Subarray Sum
Platform   : LeetCode
Problem No.: 209
Pattern    : Sliding Window (Variable Size)
Difficulty : Medium

Approach (Hiring & Firing) :

Initialization:
- low = 0
- high = 0
- sum = 0
- minLength = INT_MAX

Step 1 : Hire (Expand the Window)
- Traverse the array while high < n.
- Hire the current element into the window:
      sum += nums[high]
- Continue hiring until the window sum becomes
  greater than or equal to the target.

Step 2 : Fire (Shrink the Window)
- Once sum >= target:
    • Calculate the current window length.
    • Update the minimum length.
    • Remove the first element from the window:
          sum -= nums[low]
    • Move low forward.
- Continue firing while sum >= target to obtain
  the smallest possible valid window.

Step 3 : Hire Again
- When sum becomes smaller than the target,
  expand the window again by moving:
      high++
- Repeat the same process until high reaches the end.

Time Complexity  : O(n)

Space Complexity : O(1)



  class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=0;
        int sum=0;
        int minLen=INT_MAX;

        while(high<n){
              sum = sum+nums[high];

              while(sum >= target){
                int Len = high-low+1;
                minLen = min(minLen, Len);

                sum = sum-nums[low];

                low++;
              }
              high++;
        }
        if(minLen==INT_MAX){
            return 0;
        }
        return minLen;
    }
};
