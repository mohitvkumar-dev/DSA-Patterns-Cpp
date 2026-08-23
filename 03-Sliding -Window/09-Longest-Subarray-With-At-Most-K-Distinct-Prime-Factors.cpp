
Problem    : Longest Subarray with At Most K Distinct
             Prime Factors
Platform   : LeetCode
Problem No.: 4032
Pattern    : Variable Size Sliding Window +
             Prime Factorization
Difficulty : Medium

Intuition :
- We need to find the longest contiguous subarray whose
  total number of distinct prime factors is at most k.
- Each number can contribute multiple distinct prime
  factors.

Example:

    6  -> {2, 3}
    10 -> {2, 5}
    12 -> {2, 3}

For:

    [6, 10, 12]

The set of distinct prime factors is:

    {2, 3, 5}

So the window contains 3 distinct prime factors.

- This is similar to the standard problem:
  "Longest Subarray with At Most K Distinct Elements".

- The difference is that each array element contributes
  multiple distinct prime factors instead of just one
  element/value.

- Therefore, use a Variable Size Sliding Window and
  maintain the frequency of every prime factor inside
  the current window.

-------------------------------------------------------

Prime Factorization :

- For every number x, find its distinct prime factors.
- Try divisors from 2 up to sqrt(x).
- If p divides x:
    • Add p once to the factor list.
    • Remove all occurrences of p using:

          while (x % p == 0)
              x /= p;

- After the loop, if x > 1, then x itself is a
  remaining prime factor.

Examples:

    12 = 2 × 2 × 3
       -> {2, 3}

    72 = 2 × 2 × 2 × 3 × 3
       -> {2, 3}

-------------------------------------------------------

Approach :

1. Find and store the distinct prime factors of every
   array element.

      allFactors[i] = distinct prime factors of nums[i]

2. Maintain a sliding window using:

      left = 0
      right = 0

3. Maintain:

      freq[prime] = frequency of that prime factor
                     inside the current window.

      distinctPrimes = number of distinct prime factors
                       currently present in the window.

4. Expand the window using the right pointer.

   For every prime factor of nums[right]:

      If freq[prime] == 0:
          distinctPrimes++;

      freq[prime]++;

5. If:

      distinctPrimes > k

   the window becomes invalid.

   Shrink it from the left.

   For every prime factor of nums[left]:

      freq[prime]--;

      If freq[prime] == 0:
          distinctPrimes--;

   Then:

      left++;

   Continue until:

      distinctPrimes <= k

6. Now the window is valid.

      length = right - left + 1

   Update:

      ans = max(ans, length)

7. Continue until the entire array is processed.

8. Return ans.

-------------------------------------------------------

Why does this work?

- The window is valid exactly when it contains at
  most k distinct prime factors.
- freq keeps track of how many elements in the current
  window contain each prime factor.
- When a prime's frequency becomes zero, that prime is
  completely removed from the window.
- Therefore distinctPrimes always represents the exact
  number of distinct prime factors in the current window.
- Whenever the window becomes invalid, moving left
  removes prime factors until the window becomes valid
  again.
- Since we maximize the length of every valid window,
  the final answer is the longest valid subarray.

-------------------------------------------------------

Time Complexity:

Prime factors nikaalne ke liye:  O(n × √M)
  
Kyuki har number ke liye worst case mein √nums[i] tak divisors check karte hain.
  
Sliding window mein:  O(n × log M)
  
Ek number ke distinct prime factors maximum roughly O(log M) hote hain, aur har number ek baar add aur ek baar remove hota hai.
So total: O(n × √M)

Prime factorization wala part dominating hai.
  
Space Complexity: 

allFactors = O(n × log M)
freq = O(number of distinct primes)

Overall: O(n × log M)

------------------------------------


  class Solution {
public:
    vector<int> getPrimeFactors(int x) {
        vector<int> factors;

        // for loop se factor check kar rahe hain
        for (int p = 2; 1LL * p * p <= x; p++) {
            if (x % p == 0) {
                factors.push_back(p);

                // same prime ki saari copies remove kar do
                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        // jo last prime factor bacha ho
        if (x > 1) {
            factors.push_back(x);
        }

        return factors;
    }

    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        // Har element ke distinct prime factors store karenge
        vector<vector<int>> allFactors(n);

        for (int i = 0; i < n; i++) {
            allFactors[i] = getPrimeFactors(nums[i]);
        }

        unordered_map<int, int> freq;

        int left = 0;
        int distinctPrimes = 0;
        int ans = 0;

        // right pointer ke liye for loop
        for (int right = 0; right < n; right++) {

            // nums[right] ke factors window mein add karo
            for (int i = 0; i < allFactors[right].size(); i++) {
                int prime = allFactors[right][i];

                if (freq[prime] == 0) {
                    distinctPrimes++;
                }

                freq[prime]++;
            }

            // invalid window ko left se shrink karo
            while (distinctPrimes > k) {

                // nums[left] ke factors remove karo
                for (int i = 0; i < allFactors[left].size(); i++) {
                    int prime = allFactors[left][i];

                    freq[prime]--;

                    if (freq[prime] == 0) {
                        distinctPrimes--;
                    }
                }

                left++;
            }

            // current valid window ka length
            int length = right - left + 1;

            if (length > ans) {
                ans = length;
            }
        }

        return ans;
    }
};
