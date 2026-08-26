
Problem    : Merge Intervals
Platform   : LeetCode
Problem No.: 56
Pattern    : Sorting + Interval Merging
Difficulty : Medium

Intuition :

Hume overlapping intervals ko merge karke non-overlapping
intervals return karne hain.

Example:

[1,3] [2,6] [8,10] [15,18]

[1,3] and [2,6] overlap karte hain:

[1,6]

Final:

[1,6] [8,10] [15,18]

-------------------------------------------------------

Approach

1. Result store karne ke liye 2D vector banao:

      vector<vector<int>> res;

2. Intervals ko starting point ke according sort karo.

   Sorting ke baad intervals ka order aisa hoga ki
   current interval ke baad aane wale intervals ka
   start point chhota nahi hoga.

3. Pehle interval ko current interval maan lo:

      s1 = intervals[0][0]
      e1 = intervals[0][1]

   Yahan:

      s1 = current merged interval ka start
      e1 = current merged interval ka end

4. Ab i = 1 se remaining intervals traverse karo.

   Current interval:

      s2 = intervals[i][0]
      e2 = intervals[i][1]

-------------------------------------------------------

Overlap Check

Agar:

      e1 >= s2

to current interval aur next interval overlap karte hain.

Example:

      [1,5]
         [3,7]

      e1 = 5
      s2 = 3

      5 >= 3  → overlap

Dono ko merge karenge:

      s1 = s1
      e1 = max(e1, e2)

Example:

      [1,5] + [3,7]

      → [1,7]

Continue karenge because updated interval
aage ke intervals ke saath bhi overlap kar sakta hai.

-------------------------------------------------------

Non-Overlapping Case

Agar:

      e1 < s2

to current interval aur next interval overlap
nahi karte.

Example:

      [1,3]    [5,7]

      3 < 5

Isliye current interval complete ho gaya.

Result mein add karo:

      res.push_back({s1, e1});

Ab next interval ko new current interval bana do:

      s1 = s2;
      e1 = e2;

-------------------------------------------------------

Last Interval

Loop ke andar hum current interval ko tabhi result
mein add karte hain jab next interval non-overlapping
milta hai.

Isliye loop ke end mein ek current interval pending
reh sakta hai.

Usko finally add karenge:

      res.push_back({s1, e1});

Then:

      return res;

-------------------------------------------------------

Why Sorting is Necessary?

Agar intervals sorted nahi hain, to hume ye guarantee
nahi milegi ki current interval ke baad aane wala
interval actually next relevant interval hai.

Starting point ke according sorting karne se:

      intervals[i][0] <= intervals[i+1][0]

Isliye hum left-to-right merge kar sakte hain.


-------------------------------------------------------

Time Complexity

Sorting:

O(n log n)

Traversal:

O(n)

Overall:

O(n log n)

Space Complexity:

O(n)

Result vector ke liye O(n) space use hota hai.
Sorting ki implementation-dependent extra space
bhi ho sakti hai.

-------------------------------------------------------


 class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;

        int s1=intervals[0][0];
        int e1=intervals[0][1];

        for(int i=1 ; i<intervals.size() ; i++){
            int s2=intervals[i][0];
            int e2=intervals[i][1];

            if(e1>=s2){  // merge
              s1= s1;
              e1=max(e1,e2);
              continue;
            }
            res.push_back({s1, e1});
             s1=s2;
             e1=e2;

        }
        res.push_back({s1,e1});
        return res;
    }
}; 


