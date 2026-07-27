
Problem    : Find the Duplicate Number
Platform   : LeetCode
Problem No.: 287
Pattern    : Fast & Slow Pointers (Floyd's Cycle Detection)
Difficulty : Medium

Approach 1 (Brute Force)

Intuition :
- Compare every element with all the remaining elements.
- If two elements are equal, that value is the duplicate
  number.

Approach :
- Traverse the array using index i.
- For every i, traverse the remaining array using
  index j = i + 1.
- If nums[i] == nums[j]:
      Return nums[i].
- If no duplicate is found, return -1.

Time Complexity  : O(n²)

Space Complexity : O(1)

-------------------------------------------------------

Approach 2 (Optimal - Floyd's Cycle Detection)

Intuition :
- The array cannot be modified and only O(1) extra
  space is allowed.
- Treat every index as a node and nums[i] as the next
  pointer.
- Since one value is duplicated, two different indices
  point to the same node, creating a cycle.
- Therefore, Floyd's Cycle Detection Algorithm can be
  used to find the duplicate number.

Approach :
- Initialize:
      slow = 0
      fast = 0
- Move:
      slow = nums[slow]
      fast = nums[nums[fast]]
- Continue until slow == fast.
  This gives the meeting point inside the cycle.
- Reset:
      slow = 0
- Keep fast at the meeting point.
- Move both pointers one step at a time:
      slow = nums[slow]
      fast = nums[fast]
- When slow == fast again,
  the meeting point is the entry of the cycle,
  which is the duplicate number.
- Return slow (or fast).

Why does this work?
- A duplicate value causes multiple indices to point
  to the same node, creating a cycle.
- Floyd's Algorithm first detects the cycle.
- Resetting one pointer to the beginning and moving
  both pointers one step at a time makes them meet
  exactly at the cycle entry.
- The cycle entry represents the duplicate number.

Time Complexity  : O(n)

Space Complexity : O(1)




class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;

        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];

            if(slow==fast){
                slow=0;

                while(slow!=fast){
                    slow=nums[slow];
                    fast=nums[fast];
                }

                return slow;
            }
        }
        return -1;
    }
};
