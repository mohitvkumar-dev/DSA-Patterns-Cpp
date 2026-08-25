
Problem    : Continuous Subarray Sum
Platform   : LeetCode
Problem No.: 523
Pattern    : Prefix Sum + Remainder + HashMap
Difficulty : Medium

Intuition :
- We need to find whether there exists a contiguous
  subarray such that:

      1. Length >= 2
      2. Sum is a multiple of k

Condition:

      sum % k == 0

- 0 is also a multiple of k because:

      0 = k * 0

- But a single element [0] is not valid because the
  subarray length must be at least 2.

-------------------------------------------------------

Approach 1 (Brute Force)

Idea :
- Consider every possible starting index.
- Extend the subarray using another pointer and
  maintain its running sum.
- Whenever:

      length >= 2
      AND
      sum % k == 0

  return true.

- If no valid subarray is found, return false.

Time Complexity  : O(n^2)

Space Complexity : O(1)

-------------------------------------------------------

Approach 2 (Optimized - Prefix Remainder + HashMap)

Intuition :
- Let prefixSum be the sum from index 0 to i.
- Instead of storing the complete prefix sum, we only
  care about its remainder when divided by k.

Suppose:

      prefixSum[i] % k = r

and an earlier prefix had the same remainder:

      prefixSum[j] % k = r

Then:

      (prefixSum[i] - prefixSum[j]) % k = 0

Therefore, the subarray from j + 1 to i has a sum
that is a multiple of k.

So, we only need to remember the FIRST index where
each remainder appeared.

-------------------------------------------------------

HashMap :

Store:

      freq[remainder] = first index where
                         this remainder appeared

Example:

      remainder -> first index

- If the same remainder appears again at index i,
  calculate:

      length = i - freq[remainder]

- If length >= 2, a valid subarray exists.

-------------------------------------------------------

Why store only the FIRST occurrence?

- We need a subarray of length at least 2.
- For the longest possible distance, we want the
  earliest index where the same remainder occurred.

Example:

      remainder = 3

      first occurrence = 1
      current index    = 5

      length = 5 - 1 = 4

- If we overwrite index 1 with a later occurrence,
  the resulting length would become smaller.
- Therefore, once a remainder is stored, do not
  update its index.

-------------------------------------------------------

Important Initialization :

Before starting the loop:

      freq[0] = -1;

Why?

- Before processing any element, prefix sum is 0.
- Therefore its remainder is also 0.
- We conceptually place remainder 0 at index -1.

This allows us to correctly calculate the length of
a valid subarray starting from index 0.

Example:

      nums = [6, 0]
      k = 6

Prefix at index 1:

      sum = 6
      remainder = 0

Previous remainder 0 was at:

      index = -1

Therefore:

      length = 1 - (-1)
             = 2

So [6, 0] is valid.

-------------------------------------------------------

Approach :

1. Initialize:

      sum = 0

2. Store the initial remainder:

      freq[0] = -1

3. Traverse the array.

For every index i:

4. Update prefix sum:

      sum += nums[i]

5. Calculate remainder:

      remainder = sum % k

6. Check whether this remainder already exists.

   If yes:

      previousIndex = freq[remainder]

      length = i - previousIndex

      if (length >= 2)
          return true

7. If the remainder has never appeared before,
   store its FIRST occurrence:

      freq[remainder] = i

8. If no valid subarray is found after the complete
   traversal:

      return false

-------------------------------------------------------

Why does this work?

If two prefix sums have the same remainder:

      prefix1 % k = prefix2 % k

then their difference is divisible by k:

      (prefix2 - prefix1) % k = 0

That difference represents the sum of the subarray
between those two prefix indices.

Therefore, repeated prefix remainders directly identify
subarrays whose sum is a multiple of k.

-------------------------------------------------------

Important Difference from LC 974 :

LC 974:
- Count all subarrays divisible by k.
- Store remainder frequency.

LC 523:
- Only need to know whether at least one valid
  subarray exists.
- Need length >= 2.
- Therefore, store the FIRST index of each remainder.

-------------------------------------------------------

Time Complexity  : O(n) average

Space Complexity : O(n)




  class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();
        int sum=0; 
        unordered_map<int,int>f;
        
        f[0]=-1;

        for(int i=0 ; i<n ; i++){
            sum=sum+nums[i];
            int rem= sum%k;
            if(f.count(rem)){
                int j=f[rem]; //  old idx jispe i se phle rem mili thi
                int len=i-j;
                if(len >= 2) {
                    return true;
                }
            }

           else{
             f[rem]= i;
           }
        }
       return false;
    }
   
};
