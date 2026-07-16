
Problem    : Container With Most Water
Platform   : LeetCode
Problem No.: 11
Pattern    : Two Pointers
Difficulty : Medium

Approach 1 (Brute Force):
- Use two nested loops.
- Fix the first line using index i.
- Traverse the remaining lines using index j.
- Calculate:
    • height = min(nums[i], nums[j])
    • width  = j - i
    • area   = height × width
- Update the maximum area for every pair.

Time Complexity  : O(n²)
Space Complexity : O(1)

-------------------------------------------------------

Approach 2 (Optimal - Two Pointers):
- Place one pointer (low) at the beginning.
- Place another pointer (high) at the end.
- Calculate:
    • height = min(nums[low], nums[high])
    • width  = high - low
    • area   = height × width
- Update the maximum area.
- If nums[low] < nums[high]:
    • Move low forward.
- Otherwise:
    • Move high backward.
- Continue until low >= high.

Reason:
- The area depends on both height and width.
- Moving the taller line cannot increase the minimum height,
  while the width definitely decreases.
- Therefore, move the pointer with the smaller height to
  get a chance of finding a taller line and a larger area.

Time Complexity  : O(n)
Space Complexity : O(1)



  class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int maxA=0;
        int low=0;
        int high= n-1;

        while(low<high){
            int width= high- low;
            int H= min(height[low], height[high]);
            int area = width*H;

            maxA= max(maxA, area);

            if(height[low]<height[high]){
                low++;
            }else{
                high--;
            }
        }
        return maxA;
        
    }
};
