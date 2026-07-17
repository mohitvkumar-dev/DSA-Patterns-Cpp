
Problem    : Maximum Sum Subarray of Size K
Platform   : GeeksforGeeks
Pattern    : Sliding Window
Difficulty : Easy

Approach :
- Maintain a fixed-size window of length k.
- Initialize:
    • low = 0
    • high = k - 1
- Find the sum of the first window using a for loop.
- Store this sum as the initial maximum result.
- Now slide the window until high reaches the end of the array.
- In every iteration:
    • Move the window one step forward:
        - low++
        - high++
    • If high == n:
        - Break the loop because no complete window can be formed.
    • Update the window sum:
        sum = sum - arr[low - 1] + arr[high]
    • Update the maximum result if the new window sum is greater.
- Return the maximum sum.

Time Complexity  : O(n)

Space Complexity : O(1)


  

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
         int n= arr.size();
         int low=0;
         int high=k-1;
         int sum=0;
         
         for(int i=low ; i<=high; i++){
             sum=sum+arr[i];
         }
         int result=sum;
         
         while(high<n){
              result=max(result,sum);
              low++;
              high++;
              
              if(high==n){
                  break;
              }
              
              sum=sum-arr[low-1]+arr[high];
         }
         return result;
    }
};
