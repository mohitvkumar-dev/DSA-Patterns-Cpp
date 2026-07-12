Problem    : Two Sum II - Input Array Is Sorted
Platform   : LeetCode
Problem No.: 167
Pattern    : Two Pointers
Difficulty : Medium

Approach   :
- Use two pointers:
  - One pointer at the beginning.
  - One pointer at the end.
- If sum == target, return indices.
- If sum < target, move left pointer forward.
- If sum > target, move right pointer backward.

Time Complexity  : O(n)
Space Complexity : O(1)

  

  class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0; 
        int j=numbers.size()-1;
        while(i<j){
            int sum= numbers[i]+numbers[j];
            if(sum==target)
              return {i+1,j+1};
             else if(sum<target)
               i++;
                else
                  j--;
               
        } 
        return {};
    }
};
