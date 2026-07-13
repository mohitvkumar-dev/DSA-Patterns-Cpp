
Problem    : Squares of a Sorted Array
Platform   : LeetCode
Problem No.: 977
Pattern    : Two Pointers
Difficulty : Easy

Approach 1 (Merge-Based Approach):
- Handle three possible cases:
  1. All elements are non-negative.
     - Square each element and return the result.

  2. All elements are negative.
     - Square each element.
     - Reverse the array to obtain sorted order.

  3. Array contains both negative and non-negative elements.
     - Separate negative and non-negative numbers.
     - Square all elements.
     - Reverse the squared negative part.
     - Merge both sorted arrays into the final answer.
     - Works similarly to the Merge step of Merge Sort.

Time Complexity  : O(n)
Space Complexity : O(n)

-------------------------------------------------------

Approach 2 (Optimal - Two Pointers):
- Place one pointer (low) at the beginning and one pointer (high) at the end.
- Compare abs(nums[low]) and abs(nums[high]).
- The larger absolute value produces the larger square.
- Place that square at the last available position in the answer array.
- Move the corresponding pointer.
- Continue until low > high.

Time Complexity  : O(n)
Space Complexity : O(n)

-------------------------------------------------------

Approach Evolution:
Merge-Based Solution
            ↓
Optimized using
Two Pointers + Absolute Values



class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         int n = nums.size();
        vector<int>result(n);
       
        int i=0 , j=n-1;
        int idx= n-1;

        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                result[idx]=nums[i]*nums[i];
                i++;
            }
            else{
                result[idx]=nums[j]*nums[j];
                j--;
            }

            idx--;
        }
        
        return result;
    }
};

