
Problem    : Subarray Sums Divisible by K
Platform   : LeetCode
Problem No.: 974
Pattern    : Prefix Sum + HashMap
Difficulty : Medium

Approach 1 (Brute Force)

Intuition :
- Generate every possible subarray.
- Calculate its sum and check whether the sum is
  divisible by k.

Condition:

    sum % k == 0

- There are O(n^2) possible subarrays.

Time Complexity  : O(n^2)
Space Complexity : O(1)

-------------------------------------------------------

Approach 2 (Optimal - Prefix Sum + HashMap)

Intuition :
- Let prefixSum[i] be the sum from index 0 to i.
- The sum of subarray (j + 1 ... i) is:

      prefixSum[i] - prefixSum[j]

- For this subarray to be divisible by k:

      (prefixSum[i] - prefixSum[j]) % k == 0

Therefore:

      prefixSum[i] % k == prefixSum[j] % k

- So, if two prefix sums have the same remainder
  when divided by k, the subarray between them is
  divisible by k.

Approach :
- Maintain a running prefix sum.
- Use an unordered_map to store:

      remainder -> frequency

- Initialize:

      freq[0] = 1

  This represents the empty prefix before the array
  starts and allows us to count subarrays beginning
  from index 0.

- Traverse the array.

For every nums[i]:

1. Update the running prefix sum:

      sum += nums[i];

2. Calculate the remainder:

      remainder = sum % k;

3. Handle negative remainders:

      remainder = (remainder + k) % k;

4. Check how many times this remainder has appeared:

      ans += freq[remainder];

5. Store the current remainder for future subarrays:

      freq[remainder]++;

Why does this work?
- Suppose the current prefix remainder is r and an
  earlier prefix also had remainder r.
- Their difference is divisible by k.
- Therefore, the subarray between those two prefix
  sums is divisible by k.
- The frequency tells us how many such previous
  prefix sums exist, so we add that frequency to
  the answer.

Why is negative remainder handling required?
- In C++, the `%` operator can return a negative
  remainder when sum is negative.

Example:

      -2 % 5 = -2

- We convert it into the standard range [0, k-1]:

      ((sum % k) + k) % k

- This ensures equivalent remainders are stored under
  the same key.

Important :
- We must check freq[remainder] BEFORE incrementing
  its frequency.
- Otherwise, the current prefix could incorrectly
  pair with itself.

Time Complexity  : O(n) average

Space Complexity : O(n)





class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n= nums.size();
        int ans=0;
        int sum=0;
        unordered_map<int,int>f;

        f[0]=1;

        for(int i=0 ; i<n ; i++){
           sum+=nums[i];
           int rem=sum%k;
           if(rem<0)
           rem=rem+k;

           ans+=f[rem];
           f[rem]++;
        }
        return ans;
    }
};
