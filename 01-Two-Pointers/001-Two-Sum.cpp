
Problem    : Two Sum
Platform   : LeetCode
Problem No.: 1
Pattern    : Two Pointers
Difficulty : Easy

Approach   :
- Store visited elements in a hash map.
- For every element, check if (target - current element)
  already exists in the map.
- If yes, return both indices.

Time Complexity  : O(n)
Space Complexity : O(n)


  class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;

        for(int i=0 ; i<nums.size(); i++ ){
            int x = target -nums[i];
            if(m.find(x)!=m.end()){
                return {i,m[x]};
            }else{
                
                 m[nums[i]]= i;
            }
        }
        return {};
    }
};
