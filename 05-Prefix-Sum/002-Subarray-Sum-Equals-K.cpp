
Problem    : Subarray Sum Equals K
Platform   : LeetCode
Problem No.: 560
Pattern    : Prefix Sum + HashMap
Difficulty : Medium

Intuition :
- We need to count the number of subarrays whose sum
  is exactly k.
- Let sum be the prefix sum from index 0 to the
  current index i.
- Suppose a previous prefix sum was prev.

Then:

    Current Prefix - Previous Prefix
    = Subarray Sum

Therefore:

    sum - prev = k

So:

    prev = sum - k

- At every index, we only need to find how many times
  the prefix sum (sum - k) has appeared previously.
- If it appeared multiple times, each occurrence
  represents a different valid subarray.

Example:

    sum - k appears 3 times

    → 3 different subarrays ending at current index
      have sum exactly k.

-------------------------------------------------------

Approach :

- Maintain:

      sum = current prefix sum
      ans = number of valid subarrays

- Use an unordered_map to store:

      prefix sum -> frequency

- Initialize:

      freq[0] = 1;

Why?

- It represents an empty prefix before the array starts.
- This allows us to count subarrays that start from
  index 0.

- Traverse the array.

For every nums[i]:

1. Update prefix sum:

      sum += nums[i];

2. Find the required previous prefix:

      required = sum - k;

3. Check how many times it has appeared:

      count = freq[required];

4. Every occurrence gives one valid subarray:

      ans += count;

5. Store the current prefix sum for future indices:

      freq[sum]++;

- Return ans.

-------------------------------------------------------

Why does this work?

Suppose:

    Previous Prefix = P
    Current Prefix  = S

Then the subarray between them has sum:

    S - P

We need:

    S - P = k

Therefore:

    P = S - k

So at every index, finding the frequency of
(sum - k) directly tells us how many valid subarrays
end at the current index.

-------------------------------------------------------

Important :

Do NOT simply check whether (sum - k) exists.

We need its FREQUENCY.

For example:

    freq[sum - k] = 3

means there are 3 different previous prefix sums,
and therefore 3 different valid subarrays ending
at the current index.

-------------------------------------------------------

Time Complexity  : O(n) average

Space Complexity : O(n)




class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0; int sum=0;
        unordered_map<int,int>freq;

        freq[0]=1;
        for(int i=0 ; i<nums.size(); i++){
            sum+=nums[i];
            int required= sum-k;
            int count= freq[required];
            res+=count;

            freq[sum]++;
        }
        return res;
    }
};
