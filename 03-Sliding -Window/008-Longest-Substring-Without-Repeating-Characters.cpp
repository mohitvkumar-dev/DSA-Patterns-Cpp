
Problem    : Longest Substring Without Repeating Characters
Platform   : LeetCode
Problem No.: 3
Pattern    : Sliding Window (Variable Size)
Difficulty : Medium

Intuition :
- We need to find the longest substring in which every
  character appears only once.
- Maintain a variable-size sliding window.
- Expand the window by including new characters.
- If a duplicate character appears, shrink the window
  until the duplicate is removed.
- Every valid window is a candidate answer.

Approach :
- Use the Variable Size Sliding Window (Hire & Fire)
  technique.
- Maintain a window using two pointers:
    • low  -> Starting index of the current window.
    • high -> Ending index of the current window.
- Use an unordered_map<char, int> to store the
  frequency of characters inside the current window.
- Expand the window by moving high forward and include
  the current character:
      freq[s[high]]++;
- If the current character becomes a duplicate
  (freq[s[high]] > 1):
    • Shrink the window by moving low forward.
    • Decrease the frequency of the outgoing character.
    • Continue shrinking until the duplicate character
      is removed.
- Once the window becomes valid again:
    • Calculate the current window length:
          windowLength = high - low + 1
    • Update the maximum window length.
- Repeat until the entire string is traversed.
- Return the maximum length.

Time Complexity  : O(n)

Space Complexity : O(k)
(k = Number of unique characters in the current window)




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.size();
        int maxlen=0;
        int low=0;
        int high=0;
      
        unordered_map<char,int>f;
        for(int high=0; high<n ; high++){
            f[s[high]]++;
            while(f[s[high]]>1){
                f[s[low]]--;
                low++;
            }

            int len=high-low+1;

          maxlen= max(maxlen,len);
            
        }
        return maxlen;

    }
};
