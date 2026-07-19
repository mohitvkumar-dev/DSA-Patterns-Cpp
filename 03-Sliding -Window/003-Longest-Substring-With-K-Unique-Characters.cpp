
Problem    : Longest Substring with Exactly K Unique Characters
Platform   : GeeksforGeeks
Pattern    : Sliding Window (Variable Size)
Difficulty : Medium

Approach :
- Use the Variable Size Sliding Window technique.
- Maintain a window using two pointers:
    • low  -> Starting index of the current window.
    • high -> Ending index of the current window.
- Use an unordered_map<char, int> to store the frequency
  of characters present inside the current window.
- Expand the window by moving high forward and include
  the current character in the frequency map.
- If the number of unique characters (freq.size()) becomes
  greater than k:
    • Shrink the window by moving low forward.
    • Decrease the frequency of the outgoing character.
    • If its frequency becomes 0, erase it from the map.
    • Continue shrinking until freq.size() becomes equal to k.
- Whenever freq.size() == k:
    • Calculate the current window length.
    • Update the maximum length if the current window is larger.
- Repeat the process until the entire string is traversed.

Time Complexity  : O(n)
Space Complexity : O(k)




  class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n= s.size();
        int res=INT_MIN;
        int low=0; 
        int high=0;
        unordered_map<char,int>f;
        
        for(int high=0; high<n; high++){
            f[s[high]]++;
            
            while(f.size()>k){
                f[s[low]]--;
                if(f[s[low]]==0){
                    f.erase(s[low]);
                }
                low++;
            }
            if(f.size()==k){
                int len= high-low+1;
                res= max(res,len);
            }
           
        }
        
         
            if(res==INT_MIN){
                return -1;
            }
            
        return res;
        
 }
}; 
