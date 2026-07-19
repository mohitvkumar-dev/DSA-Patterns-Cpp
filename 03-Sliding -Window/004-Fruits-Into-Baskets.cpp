
Problem    : Fruits Into Baskets
Platform   : LeetCode
Problem No.: 904
Pattern    : Sliding Window (Variable Size)
Difficulty : Medium

Approach :
- Use the Variable Size Sliding Window technique.
- Maintain a window using two pointers:
    • low  -> Starting index of the current window.
    • high -> Ending index of the current window.
- Use an unordered_map<int, int> to store the frequency
  of fruit types present inside the current window.
- Expand the window by moving high forward and include
  the current fruit in the frequency map.
- If the number of distinct fruit types (freq.size())
  becomes greater than 2:
    • Shrink the window by moving low forward.
    • Decrease the frequency of the outgoing fruit.
    • If its frequency becomes 0, erase it from the map.
    • Continue shrinking until only two distinct fruit
      types remain.
- Whenever the current window contains at most two
  distinct fruit types:
    • Calculate the current window length.
    • Update the maximum answer.
- Repeat the process until the entire array is traversed.

Time Complexity  : O(n)

Space Complexity : O(1)



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int low=0;
        int high=0;
        int res=0;
        unordered_map<int,int>f;

        for(int high=0;high<n; high++ ){
            f[fruits[high]]++;

            while(f.size()>2){
                f[fruits[low]]--;

                if(f[fruits[low]]==0){
                    f.erase(fruits[low]);
                }
                low++;
            }

              int len =high-low+1;
              res= max(res,len);
        }

        return res;
      
    }
};
