
Problem    : Insert Interval
Platform   : LeetCode
Problem No.: 57
Pattern    : Sorting + Greedy / Interval Merging
Difficulty : Medium

Intuition :

Hume sorted aur non-overlapping intervals ki list di gayi hai
aur ek newInterval diya gaya hai.

Hume newInterval ko correct position par insert karke
overlapping intervals ko merge karna hai.

Example:

Intervals:

[1,3] [6,9]

New Interval:

[2,5]

Pehle newInterval ko correct sorted position par insert karenge:

[1,3] [2,5] [6,9]

Ab normal Merge Intervals ki tarah overlapping intervals
ko merge karenge:

[1,5] [6,9]

-------------------------------------------------------

Approach

1. Result store karne ke liye 2D vector banao:

     vector<vector<int>> res;

2. Original intervals ko traverse karo aur newInterval ko
   uski correct sorted position par insert karo.

   Jahan:

     intervals[i][0] >= newInterval[0]

   ho, usse pehle newInterval ko res mein add kar do.

3. Agar newInterval ko loop ke andar insert nahi kiya gaya,
   to loop ke baad usse res mein add kar do.

4. Ab res sorted order mein hai.

5. Ab normal Merge Intervals approach use karo.

   Pehle interval ko current interval maan lo:

     s1 = res[0][0]
     e1 = res[0][1]

6. Ab i = 1 se remaining intervals traverse karo.

   Current interval:

     s2 = res[i][0]
     e2 = res[i][1]
  

Overlap Check

Agar:

     e1 >= s2

to current interval aur next interval overlap karte hain.

Example:

     [1,5]
        [3,7]

     e1 = 5
     s2 = 3

     5 >= 3 → overlap

Dono ko merge karenge:

     s1 = s1
     e1 = max(e1, e2)

Example:

     [1,5] + [3,7]

     → [1,7]

Continue karenge kyunki updated interval aage ke
intervals ke saath bhi overlap kar sakta hai.


Non-Overlapping Case

Agar:

     e1 < s2

to current interval aur next interval overlap nahi karte.

Isliye current interval complete ho gaya.

Result mein add karo:

     ans.push_back({s1, e1});

Ab next interval ko new current interval bana do:

     s1 = s2;
     e1 = e2;


Last Interval

Loop ke end mein current interval pending reh sakta hai.

Isliye finally:

     ans.push_back({s1, e1});

Then:

     return ans;

-------------------------------------------------------

Why Insert Before Merging?

New interval existing intervals ke beech overlap kar sakta hai.

Example:

     [1,2] [5,6]

New Interval:

     [2,5]

Agar pehle newInterval ko correct sorted position par
insert kar dein:

     [1,2] [2,5] [5,6]

to normal Merge Intervals approach se easily:

     [1,6]

mil jayega.

Isliye:

     Insert → Sort Order Maintain → Merge


-------------------------------------------------------

Time Complexity

Insertion Traversal:

O(n)

Merge Traversal:

O(n)

Overall:

O(n)

Space Complexity:

O(n)




  class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    vector<vector<int>> res;
    int n= intervals.size();

     bool insert= false; // man lo naya interval insert abhi nhi hua h 

    for(int i=0 ; i<n ; i++){
        int s=intervals[i][0];

        if(insert==false && s >= newInterval[0]){
            res.push_back(newInterval);
            insert= true;
        }

        res.push_back(intervals[i]);
    }

     // newInterval end mein ho ya intervals empty ho
      if (!insert) {
        res.push_back(newInterval);

      }

        vector<vector<int>>ans;

        int s1=res[0][0];
        int e1=res[0][1];

        for(int i=1 ; i <res.size(); i++){
            int s2=res[i][0];
            int e2=res[i][1];

            if(e1>=s2){
               s1 = s1;
               e1 = max(e1, e2);
               continue;
            }

            ans.push_back({s1,e1});

            s1= s2;
            e1 = e2;

            
        }
        ans.push_back({s1,e1});
        return ans;
    }
};
