
Problem    : Sort Colors
Platform   : LeetCode
Problem No.: 75
Pattern    : Dutch National Flag (Three Pointers)
Difficulty : Medium

Approach :
- Maintain three pointers:
    • low  = points to the position where the next 0 should be placed.
    • mid  = traverses the array.
    • high = points to the position where the next 2 should be placed.
- Traverse the array while mid <= high.
- If nums[mid] == 0:
    • Swap nums[mid] with nums[low].
    • Increment both low and mid.
- If nums[mid] == 1:
    • It is already in the correct region.
    • Increment mid.
- If nums[mid] == 2:
    • Swap nums[mid] with nums[high].
    • Decrement high.
    • Do NOT increment mid because the swapped element
      from the high index has not been processed yet.
- Continue until mid crosses high.

Time Complexity  : O(n)

Space Complexity : O(1)




  class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int mid=0;
        int high=n-1;
        
        while(mid<=high){
           if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
           }
           else if(nums[mid]==1){
            mid++;
           }
           else{
            swap(nums[mid],nums[high]);
                high--;
            
           }
        }
        return;
    }
};
