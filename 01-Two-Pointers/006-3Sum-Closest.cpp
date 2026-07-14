
Problem    : 3Sum Closest
Platform   : LeetCode
Problem No.: 16
Pattern    : Two Pointers
Difficulty : Medium

Approach :
- Sort the array.
- Iterate through the array and fix one element nums[i].
- For every fixed element, use Two Pointers:
    • low = i + 1
    • high = n - 1
- Calculate the current triplet sum.
- Find the absolute difference between currentSum and target.
- If the current difference is smaller than the minimum difference found so far:
    • Update minDiff.
    • Store currentSum as the closest sum.
- If currentSum == target:
    • Return currentSum immediately.
- If currentSum < target:
    • Move low forward to increase the sum.
- If currentSum > target:
    • Move high backward to decrease the sum.
- Continue until all possible triplets are checked.
- Return the closest sum.

Time Complexity  : O(n²)

Space Complexity : O(1)



  class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
       int closestSum=0;
       int minDiff= INT_MAX;

       for(int i=0 ; i<n-2; i++){
        int low = i+1;
        int high= n-1;
       
         while(low<high){
             int currSum= nums[i]+nums[low]+nums[high];
             int diff= abs(currSum- target);

             if(diff<minDiff){
                  minDiff= diff;
                  closestSum= currSum;
             }
           

             if(currSum==target){
                return closestSum;
             }
             else if(currSum<target){
                low++;
             }
             else{
                high--;
             }
         }
       }
       
       return closestSum;
    }
};
