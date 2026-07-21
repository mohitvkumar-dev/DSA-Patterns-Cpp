
Problem    : Max Consecutive Ones III
Platform   : LeetCode
Problem No.: 1004
Pattern    : Sliding Window (Variable Size)
Difficulty : Medium

Intuition :
- We are allowed to flip at most k zeroes into ones.
- The goal is to find the longest subarray containing
  at most k zeroes.
- Since the target is fixed (0's), there is no need for
  a frequency map. We only maintain the count of zeroes
  present inside the current window.

Approach :
- Use the Variable Size Sliding Window (Hire & Fire) technique.
- Maintain a window using two pointers:
    • low  -> Starting index of the current window.
    • high -> Ending index of the current window.
- Maintain a variable zeroCount to store the number of
  zeroes present inside the current window.
- Expand the window by moving high forward.
- If nums[high] == 0:
    • Increment zeroCount.
- If zeroCount becomes greater than k:
    • The current window becomes invalid.
    • Shrink the window by moving low forward.
    • If nums[low] == 0:
          zeroCount--;
    • Continue shrinking until zeroCount <= k.
- After shrinking, the window becomes valid again.
- Calculate the current window length:
      windowLength = high - low + 1
- Update the maximum answer using:
      result = max(result, windowLength)
- Continue until the entire array is traversed.
- Return the maximum window length.

Time Complexity  : O(n)

Space Complexity : O(1)



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int high=0;
        int res=0;
        int count=0;
        for(int high=0; high<n; high++){
            if(nums[high]==0)
            count++;

            while(count>k){
                if(nums[low]==0)
                count--;
                low++;
            }
            int len= high-low+1;
             res= max(res,len);

        }
        return res;
    }
};
