
Problem    : Remove Duplicates from Sorted Array
Platform   : LeetCode
Problem No.: 26
Pattern    : Two Pointers
Difficulty : Easy

Approach   :
- Keep two pointers:
  - low  -> points to the last unique element.
  - high -> traverses the array from left to right.
- Initially:
  - low = 0
  - high = 1
- If nums[low] != nums[high]:
  - Move low one step ahead.
  - Copy nums[high] to nums[low].
- Continue until high reaches the end.
- Return low + 1, which represents the number of unique elements.

Time Complexity  : O(n)
Space Complexity : O(1)





  class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low=0 ; 

        int high=1;
        for(high=1 ; high<nums.size(); high++){
            if(nums[high]!=nums[low]){
            
            low++;
         
          
             nums[low]=nums[high];
            }
            
        }
        return low+1;
    }
};
