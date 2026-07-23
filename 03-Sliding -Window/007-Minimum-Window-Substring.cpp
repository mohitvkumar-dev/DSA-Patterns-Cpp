
Problem    : Minimum Window Substring
Platform   : LeetCode
Problem No.: 76
Pattern    : Sliding Window (Variable Size)
Difficulty : Hard

Intuition :
- We need to find the minimum substring that contains
  all the characters of string t along with their
  required frequencies.
- Maintain a variable-size sliding window.
- Expand the window until it becomes valid.
- Once the window is valid, shrink it to obtain the
  smallest possible valid window.

Approach :
- Use the Variable Size Sliding Window (Hire & Fire)
  technique.
- Maintain a window using two pointers:
    • low  -> Starting index of the current window.
    • high -> Ending index of the current window.
- Create two frequency arrays:
    • targetFreq[256] -> Stores the frequency of
      characters present in string t.
    • windowFreq[256] -> Stores the frequency of
      characters present in the current window.
- Store the frequency of every character of t in
  targetFreq.
- Expand the window by moving high forward and include
  the current character:
      windowFreq[s[high]]++;
- Check whether the current window is valid.
- The window is valid only if every required character
  satisfies:
      windowFreq[ch] >= targetFreq[ch]
- If the window is invalid:
    • Continue expanding the window.
- If the window becomes valid:
    • Calculate the current window length.
    • Update the minimum window length and starting
      index if a smaller valid window is found.
    • Shrink the window:
          windowFreq[s[low]]--;
          low++;
    • Continue shrinking until the window becomes
      invalid again.
- Repeat the process until the entire string is
  traversed.
- If a valid window is found, return:
      s.substr(startIndex, minLen)
- Otherwise return an empty string.

Time Complexity  : O(256 × n)
                  ≈ O(n)

Space Complexity : O(256)
                  ≈ O(1)




class Solution {
public:

    // Check whether current window satisfies all characters of t
    bool isValid(vector<int>& windowFreq, vector<int>& targetFreq) {

        for (int i = 0; i < 256; i++) {
            if (windowFreq[i] < targetFreq[i]) {
                return false;
            }
        }

        return true;
    }

    string minWindow(string s, string t) {

        // Edge Case
        if (t.size() > s.size()) {
            return "";
        }

        // Frequency arrays
        vector<int> targetFreq(256, 0);
        vector<int> windowFreq(256, 0);

        // Store frequency of characters of t
        for (char ch : t) {
            targetFreq[ch]++;
        }

        int low = 0;
        int minLen = INT_MAX;
        int startIndex = -1;

        // Hire (Expand Window)
        for (int high = 0; high < s.size(); high++) {

            // Include current character in window
            windowFreq[s[high]]++;

            // Fire (Shrink Window)
            while (isValid(windowFreq, targetFreq)) {

                int windowLength = high - low + 1;

                // Update minimum answer
                if (windowLength < minLen) {
                    minLen = windowLength;
                    startIndex = low;
                }

                // Remove left character
                windowFreq[s[low]]--;

                // Shrink window
                low++;
            }
        }

        // No valid window found
        if (startIndex == -1) {
            return "";
        }

        return s.substr(startIndex, minLen);
    }
};
