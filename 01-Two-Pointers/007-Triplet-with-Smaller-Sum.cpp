
Problem    : Triplet with Smaller Sum
Platform   : GeeksforGeeks
Pattern    : Two Pointers
Difficulty : Medium

Approach :
- Sort the array.
- Iterate through the array and fix one element nums[i].
- Set:
    • low = i + 1
    • high = n - 1
- Calculate the current triplet sum:
    currentSum = nums[i] + nums[low] + nums[high]
- If currentSum >= target:
    • Move high backward to decrease the sum.
- Otherwise (currentSum < target):
    • Since the array is sorted, every element between
      low and high also forms a valid triplet with nums[i].
    • Add (high - low) to the count.
    • Move low forward to explore more triplets.
- Continue until low >= high.
- Return the total count of valid triplets.

Time Complexity  : O(n²)

Space Complexity : O(1)




  class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        int count=0;
        int n=arr.size();
        
        for(int i=0 ; i<n-2; i++){
            int low=i+1;
            int high=n-1;
            
            while(low<high){
                int S= arr[i]+arr[low]+arr[high];
                if(S>=sum){
                    high--;
                }
                else{
                    count= count+(high-low);
                    low++;
                }
            }
        }
        return count;
        
    }
};
