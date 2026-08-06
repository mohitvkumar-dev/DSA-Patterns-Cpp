
Problem    : Maximum Subarray Sum with One Deletion
Platform   : LeetCode
Problem No.: 1186
Pattern    : Kadane's Algorithm (State Variant)
Difficulty : Medium

Intuition :
- In normal Kadane's Algorithm, we maintain the best
  subarray sum ending at every index.
- Here, we are allowed to delete at most one element.
- Therefore, at every index we maintain two states:

      noDelete
      = Best subarray sum ending at current index
        without using any deletion.

      oneDelete
      = Best subarray sum where exactly one deletion
        has already been used.

State 1 : noDelete

At index i, we have two choices:

1. Start a new subarray:
      arr[i]

2. Continue the previous subarray:
      prevNoDelete + arr[i]

Therefore:

      noDelete =
          max(arr[i],
              prevNoDelete + arr[i]);


State 2 : oneDelete

There are two possibilities:

1. Deletion was already used earlier:
      prevOneDelete + arr[i]

   In this case, include the current element.

2. Delete the current element:
      prevNoDelete

   The current element contributes nothing, so the
   previous noDelete sum remains unchanged.

Therefore:

      oneDelete =
          max(prevOneDelete + arr[i],
              prevNoDelete);


Approach :
- Initialize:

      noDelete  = arr[0]
      oneDelete = INT_MIN
      answer    = arr[0]

- oneDelete is initialized with INT_MIN because before
  processing any deletion, there is no valid state
  representing a non-empty subarray with exactly one
  deletion.

- Traverse the array from index 1.

- Before updating the states, save:

      prevNoDelete = noDelete
      prevOneDelete = oneDelete

- Update:

      noDelete =
          max(arr[i],
              prevNoDelete + arr[i]);

      oneDelete =
          max(prevOneDelete + arr[i],
              prevNoDelete);

- Since deletion is optional ("at most one deletion"),
  both states can contribute to the final answer:

      answer = max(answer,
                   max(noDelete, oneDelete));

- Return answer.

Why does this work?
- Every valid solution at index i belongs to one of
  two states:
    • No deletion has been used.
    • Exactly one deletion has been used.
- For oneDelete, either the deletion happened earlier
  or the current element itself is deleted.
- These possibilities cover every valid case.

Important :
- "At most one deletion" means deletion is optional.
  Therefore, answer must consider both noDelete and
  oneDelete.
- The resulting subarray must be non-empty.

Time Complexity  : O(n)

Space Complexity : O(1)





  class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int Nodelete = arr[0];
        int Onedelete = INT_MIN;
        int ans = arr[0];

        for(int i=1 ; i<arr.size(); i++){
            int prevNodelete=Nodelete;
            int prevOnedelete=Onedelete;

            Nodelete=max(arr[i],prevNodelete+arr[i]);
           

           if(prevOnedelete==INT_MIN){
            Onedelete=prevNodelete;
           }else{
            Onedelete=max(prevOnedelete+arr[i],prevNodelete);
           }

           ans=max(ans,max(Nodelete,Onedelete));
        }
        return ans;
    }
};
