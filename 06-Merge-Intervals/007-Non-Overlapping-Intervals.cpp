Problem    : Non-overlapping Intervals
Platform   : LeetCode
Problem No.: 435
Pattern    : Sorting + Greedy / Interval Scheduling
Difficulty : Medium

Intuition :

Hume minimum number of intervals remove karne hain
taaki remaining intervals non-overlapping ho jayein.

Sabse pehle obvious observation:

Agar do intervals overlap kar rahe hain, to unmein
se kam se kam ek interval remove karna padega.

Isliye:

    overlap → count++

Lekin yahan ek important hidden decision hai:

    Overlap hone par kaunsa interval remove karein?

Sirf overlap count karna enough nahi hai.

Example:

    [1,5]
    [2,10]
    [6,8]

[1,5] aur [2,10] overlap karte hain.

Ek interval remove karna hi padega.

Agar [1,5] remove kiya:

    [2,10]
    [6,8]

Ye bhi overlap karte hain.

Total removals = 2

Agar [2,10] remove kiya:

    [1,5]
    [6,8]

Ab overlap nahi hai.

Total removals = 1

Therefore overlap hone par hume aisa interval retain
karna chahiye jiska end time chhota ho.

-------------------------------------------------------

Greedy Idea

Overlap ke case mein:

    smaller end wala interval retain karo.

Kyun?

Jis interval ka end chhota hota hai, woh jaldi finish
ho jata hai.

Isliye future intervals ke liye zyada space available
rehta hai aur future overlap ki possibility kam hoti hai.

Example:

    [1,5]
    [2,10]

Ends:

    5 < 10

Isliye [1,5] retain karenge aur [2,10] ko remove
maana jayega.

Is decision ko code mein:

    count++;
    e1 = min(e1,e2);

se represent kar sakte hain.

-------------------------------------------------------

Approach

1. Intervals ko start time ke according sort karo.

2. Pehle interval ka end store karo:

       e1 = intervals[0][1]

   Yahan e1 ka matlab hai:

       Abhi tak retain kiye gaye interval ka end.

3. i = 1 se remaining intervals traverse karo.

4. Current interval ka start aur end nikalo:

       s2 = intervals[i][0]
       e2 = intervals[i][1]

-------------------------------------------------------

Case 1 — Overlap

Agar:

       e1 > s2

to current retained interval aur current interval
overlap kar rahe hain.

Isliye ek interval remove karna padega:

       count++;

Ab dono intervals mein se smaller end wala retain karo:

       e1 = min(e1,e2);

Example:

       [1,5]
       [2,10]

       e1 = 5
       e2 = 10

       e1 = min(5,10)
          = 5

Matlab [1,5] ko retain kiya aur [2,10] ko remove
maana.

-------------------------------------------------------

Case 2 — No Overlap

Agar:

       e1 <= s2

to overlap nahi hai.

Current interval safely retain kar sakte hain.

Isliye:

       e1 = e2;

Ab current interval next comparison ke liye
retained interval ban gaya.

-------------------------------------------------------

Why Smaller End?

Ye is problem ka main Greedy Insight hai.

Suppose:

       [1,5]
       [2,10]

Dono overlap kar rahe hain.

Agar [1,5] retain kiya:

       next interval ko 5 ke baad start karna hoga.

Agar [2,10] retain kiya:

       next interval ko 10 ke baad start karna hoga.

Smaller end future ke liye zyada space deta hai.

Therefore:

       overlap → retain smaller end.

-------------------------------------------------------

Important Hidden Decision

Initial thinking:

       overlap → count++

Correct hai, but incomplete hai.

Hume har overlap par do decisions lene hain:

       1. Ek interval remove karo.
       2. Future ke liye better interval retain karo.

Better interval:

       smaller ending time.

Isi second decision ki wajah se
sirf overlap count karne wala solution fail ho sakta hai.

-------------------------------------------------------

Why Sorting?

Start time ke according sorting se intervals
chronological order mein aa jate hain.

Therefore current interval ko previous retained
interval ke saath compare karna sufficient hai.

Without sorting, local greedy decision reliable
nahi hota.

-------------------------------------------------------

Algorithm

1. Intervals ko start time ke according sort karo.
2. First interval ka end `e1` store karo.
3. Remaining intervals traverse karo.
4. Agar:

       e1 > s2

   → overlap.
5. Overlap par:

       count++;
       e1 = min(e1,e2);

6. Agar overlap nahi hai:

       e1 = e2;

7. Finally `count` return karo.

-------------------------------------------------------

Complexity

Sorting:

    O(n log n)

Traversal:

    O(n)

Overall:

    O(n log n)

Space:

    O(1) extra space
    (sorting ki implementation-dependent space ko ignore
     karke)

-------------------------------------------------------

Revision Trick

"Sort by start → overlap mila to count++ →
smaller end wala retain karo → no overlap par
current end update karo."

-------------------------------------------------------

Problem-Solving Lesson

Agar question kahe:

    "Minimum removals so that intervals don't overlap"

to sirf ye mat socho:

    "Overlap kitne hain?"

Ye bhi poochho:

    "Overlap hone par kaunsa interval remove karna
     future ke liye best hoga?"

Yahi hidden Greedy decision hai.

-------------------------------------


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count =0;
        int n=intervals.size();

        sort(intervals.begin(),intervals.end());

        int s1=intervals[0][0];
        int e1=intervals[0][1];

        for(int i=1 ; i<n ; i++){
             int s2= intervals[i][0];
             int e2= intervals[i][1]; 
             
             if(e1>s2){
               count++;
               s1=s1;
               e1= min(e1,e2);
             }else{
                s1= s2;
                e1=e2;
             }
        }
        return count;
       
    }
};
