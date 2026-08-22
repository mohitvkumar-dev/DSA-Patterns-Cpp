
Problem    : Contiguous Array
Platform   : LeetCode
Problem No.: 525
Pattern    : Prefix Difference + HashMap
Difficulty : Medium

  ----------------------------

Intuition :
- We need to find the longest contiguous subarray
  containing an equal number of 0s and 1s.
- Maintain a running difference:

      diff = count(0) - count(1)

- A subarray is valid if it contains equal numbers
  of 0s and 1s, which means its difference is 0.

Green-Red Intuition :
- Consider the array up to the current index as:

      [ Red Prefix ][ Green Valid Subarray ]

- The Green part contains equal 0s and 1s, so:

      greenDiff = 0

- Therefore:

      currentDiff = redDiff + greenDiff
                  = redDiff

- So, if the same diff appeared at an earlier index,
  the portion between that earlier index and the
  current index has difference 0.

      currentDiff - oldDiff = 0

- Hence, that portion contains equal numbers of 0s
  and 1s and is a valid subarray.

-------------------------------------------------------

HashMap :

Store:

      freq[diff] = first index where this diff occurred

- If the same diff appears again at index i:

      length = i - freq[diff]

- We want the longest subarray, so we must store
  the FIRST occurrence of every diff.
- The earlier the stored index, the larger the
  possible subarray length.

Important :
- If diff already exists in the map, do NOT update
  its index.
- Only store the first occurrence.

-------------------------------------------------------

Special Case :

If:

      diff == 0

then the entire prefix from index 0 to i is valid
because the number of 0s and 1s is equal.

Therefore:

      length = i + 1

      answer = max(answer, i + 1)

-------------------------------------------------------

Why does this work?
- Equal prefix differences mean their difference
  is zero.
- A difference of zero means equal numbers of 0s
  and 1s in the subarray between those prefixes.
- Storing the first occurrence gives the maximum
  possible length for every repeated diff.

-------------------------------------------------------

Time Complexity  : O(n) average

Space Complexity : O(n)




class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res=0 ;
        int zero=0;
        int one =0;
        unordered_map<int,int>f;
        int n= nums.size();

        for(int i=0; i<n ; i++){
            if(nums[i]==0){
                zero++;
            }else{
                one++;
            }

            int diff= zero - one;
            
            // start se i tak valid subarray mil gya h to 

            if(diff==0){
                res= max(res,i+1);
                continue;
            }

            // diff first time mila : to sabse phle wala index store kro 

            if(f.find(diff)==f.end()){ // eska mtlab h hashmap me h h wo diff
               f[diff]=i;
            }

            // same diff phle mil chuka h

            else{
                int idx = f[diff];
                int len = i - idx;

                res = max(res , len);
            }
        }
        return res;
    }
};
