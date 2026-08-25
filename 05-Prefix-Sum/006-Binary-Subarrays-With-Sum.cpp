
Problem    : Binary Subarrays With Sum
Platform   : LeetCode
Problem No.: 930
Pattern    : Prefix Sum + HashMap
Difficulty : Medium

Intuition :
- We need to count the number of subarrays whose sum
  is exactly goal.
- Since the array contains only 0 and 1, every subarray
  sum is simply the number of 1s present in it.

-------------------------------------------------------

Approach 1 (Brute Force)

Idea :
- Consider every possible starting index.
- For every starting index, keep calculating the
  subarray sum by extending the ending index.
- Whenever the current sum becomes equal to goal,
  increment the answer.

Approach :

    for every i:
        sum = 0

        for every j from i to n-1:
            sum += nums[j]

            if sum == goal:
                count++

- After checking all possible subarrays, return count.

Time Complexity  : O(n^2)

Space Complexity : O(1)

Problem :
- Every possible subarray is considered, so this can
  become slow for large arrays.

-------------------------------------------------------

Approach 2 (Optimized - Prefix Sum + HashMap)

Green-Red Intuition :

- At every index i, calculate the prefix sum:

      sum = sum of elements from index 0 to i

- Imagine the current prefix as:

      [ Red Prefix ][ Green Valid Subarray ]

- Suppose the current prefix sum is:

      sum

- We want the Green part to have sum = goal.

Therefore:

      Red Prefix + goal = Current Prefix

So:

      Red Prefix = sum - goal

- Therefore, at every index we only need to find how
  many times the prefix sum (sum - goal) has already
  appeared.

- Every previous occurrence represents one different
  valid subarray ending at the current index.

-------------------------------------------------------

HashMap :

Maintain:

      freq[prefixSum] = frequency of that prefix sum

Initialize:

      freq[0] = 1

Why?

- It represents the empty prefix before the array starts.
- This allows us to count valid subarrays that start
  from index 0.

-------------------------------------------------------

Approach :

1. Initialize:

      sum = 0
      answer = 0

2. Initialize the frequency map:

      freq[0] = 1

3. Traverse the array.

For every nums[i]:

4. Update the current prefix sum:

      sum += nums[i]

5. Find the required previous prefix:

      required = sum - goal

6. Check how many times it has appeared:

      answer += freq[required]

- If required appeared multiple times, each occurrence
  gives one valid subarray ending at the current index.

7. Store the current prefix sum for future use:

      freq[sum]++

8. Continue until the entire array is processed.

9. Return answer.

-------------------------------------------------------

Why does this work?

Suppose:

    Current Prefix = sum
    Previous Prefix = previous

The subarray between them has sum:

    sum - previous

We need:

    sum - previous = goal

Therefore:

    previous = sum - goal

So the frequency of (sum - goal) directly tells us
how many valid subarrays end at the current index.

-------------------------------------------------------

Important :

- Check freq[sum - goal] BEFORE updating freq[sum].
- Otherwise, the current prefix could incorrectly be
  used as its own previous prefix.

- freq[0] = 1 is necessary to count subarrays starting
  from index 0.

-------------------------------------------------------

Time Complexity  : O(n) average

Space Complexity : O(n)



class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans = 0;
        int sum=0;
        unordered_map<int,int>f;
           
           f[0]=1;
        for(int i=0 ; i<n ; i++){
            sum=sum+nums[i];
            int req=sum-goal;
            int count=f[req];
            ans=ans+count;

            f[sum]++;

        }
        return ans;
    }
};
