
Problem    : 3Sum
Platform   : LeetCode
Problem No.: 15
Pattern    : Two Pointers
Difficulty : Medium

Approach :
- Sort the array.
- Iterate through the array and fix one element nums[i].
- For every fixed element, the problem becomes finding
  two numbers whose sum equals -nums[i].
- Set:
    low = i + 1
    high = n - 1
- Apply the Two Pointers technique:
    • If nums[low] + nums[high] == target:
        - Store the triplet.
        - Move both pointers.
        - Skip duplicate values for low.
        - Skip duplicate values for high.
    • If sum < target:
        - Move low forward.
    • If sum > target:
        - Move high backward.
- Before fixing the next element, skip duplicate values
  of nums[i] to avoid duplicate triplets.

Time Complexity  : O(n²)
Space Complexity : O(1)   // Excluding the output array




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            if (nums[i] > 0) {
                break;
            }

            int target = -nums[i];
            int low = i + 1;
            int high = n - 1;

            while (low < high) {

                int sum = nums[low] + nums[high];

                if (sum == target) {

                    result.push_back({nums[i], nums[low], nums[high]});

                    low++;
                    high--;

                    while (low < high && nums[low] == nums[low - 1]) {
                        low++;
                    }

                    while (low < high && nums[high] == nums[high + 1]) {
                        high--;
                    }
                }
                else if (sum < target) {
                    low++;
                }
                else {
                    high--;
                }
            }
        }

        return result;
    }
};
