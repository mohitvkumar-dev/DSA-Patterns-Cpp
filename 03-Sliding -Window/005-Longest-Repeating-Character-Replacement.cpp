
Problem    : Longest Repeating Character Replacement
Platform   : LeetCode
Problem No.: 424
Pattern    : Sliding Window (Variable Size)
Difficulty : Medium

Intuition :
- We are allowed to replace at most k characters.
- The goal is to find the longest substring that can be
  converted into a substring of the same character after
  performing at most k replacements.
- Maintain a variable-size sliding window and keep track
  of the most frequent character inside the current window.

Approach :
- Use the Variable Size Sliding Window technique.
- Maintain a window using two pointers:
    • low  -> Starting index of the current window.
    • high -> Ending index of the current window.
- Use an unordered_map<char, int> to store the frequency
  of characters present inside the current window.
- Expand the window by moving high forward and include
  the current character in the frequency map.
- Maintain a variable maxFreq which stores the maximum
  frequency of any character seen in the current window.
- For every window, calculate:
      windowLength = high - low + 1
      replacements = windowLength - maxFreq
- If replacements > k:
    • The current window becomes invalid.
    • Shrink the window by:
          freq[s[low]]--
          low++
- Do not recalculate maxFreq while shrinking.
  Even if maxFreq becomes stale, the algorithm still
  remains correct and avoids scanning the map repeatedly,
  keeping the overall complexity linear.
- Whenever the window is valid
      (windowLength - maxFreq <= k),
  update the maximum window length.
- Continue until the entire string is traversed.

Time Complexity  : O(n)

Space Complexity : O(1)
(At most 26 uppercase English characters are stored.)



  class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int res=INT_MIN;
        int low=0;
        int high=0;
        int maxf=0;
        
        unordered_map<char,int>f;
        for(int high=0; high<n; high++){
            f[s[high]]++;
            int len= high-low+1;
            maxf= max(maxf,f[s[high]]);
            

            while(len-maxf>k){
                f[s[low]]--;
                low++;
                 len= high-low+1;

            }
            res=max(res,len);
        }

        return res;
    }
};
