
Problem    : Check Overlapping Intervals
Platform   : GeeksForGeeks
Pattern    : Sorting + Interval Overlap
Difficulty : Easy / Medium

Intuition :

Hume intervals diye gaye hain aur check karna hai ki
kya kisi bhi do intervals ke beech overlap hai.

Sabse pehle intervals ko unke starting point ke according
sort karenge.

Sorting ke baad intervals left-to-right order mein aa jayenge.

Example:

[1,3] [4,6] [2,5]

Sort karne ke baad:

[1,3] [2,5] [4,6]

Ab adjacent intervals ko compare karke easily check kar
sakte hain ki overlap hai ya nahi.

-------------------------------------------------------

Approach

1. Intervals ko starting point ke according sort karo.

2. Pehle interval ko current interval maan lo:

     s1 = intervals[0][0]
     e1 = intervals[0][1]

   Yahan:

     s1 = current interval ka start
     e1 = current interval ka end

3. Ab i = 1 se remaining intervals traverse karo.

   Current interval:

     s2 = intervals[i][0]
     e2 = intervals[i][1]

-------------------------------------------------------

Overlap Check

Sorted order ki wajah se:

     s1 <= s2

hoga.

Ab agar:

     e1 >= s2

to current interval aur next interval overlap karte hain.

Is case mein:

     return true;

kyunki hume sirf ye check karna hai ki
koi bhi overlapping pair exist karta hai ya nahi.

-------------------------------------------------------

Non-Overlapping Case

Agar:

     e1 < s2

to dono intervals overlap nahi karte.

Ab next interval ko current interval bana denge:

     s1 = s2;
     e1 = max(e1, e2);

Actually sorted non-overlapping case mein:

     e1 < s2

hone ki wajah se current interval ko directly:

     s1 = s2;
     e1 = e2;

bhi update kiya ja sakta hai.

-------------------------------------------------------

Why Sorting is Necessary?

Agar intervals sorted nahi hain, to hume ye guarantee
nahi milegi ki current interval ke baad aane wala
interval actually next relevant interval hai.

Sorting ke baad:

     intervals[i][0] <= intervals[i+1][0]

Isliye sirf consecutive intervals ko compare karke
overlap detect kar sakte hain.

-------------------------------------------------------

Algorithm

1. Intervals ko start point ke according sort karo.
2. First interval ko current interval banao.
3. i = 1 se remaining intervals traverse karo.
4. Current interval [s1,e1] aur next interval
   [s2,e2] nikalo.
5. Agar:

       e1 >= s2

   to overlap exist karta hai:

       return true;

6. Agar overlap nahi hai, to next interval ko
   current interval bana do.
7. Loop complete hone ke baad:

       return false;

-------------------------------------------------------

Time Complexity

Sorting:

     O(n log n)

Traversal:

     O(n)

Overall:

     O(n log n)

-------------------------------------------------------

Space Complexity

Auxiliary space:

     O(1)

Agar sorting ki internal implementation space ko
consider na karein.




  class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        int n= intervals.size();
        
        int s1= intervals[0][0];
        int e1= intervals[0][1];
        
        for(int i=1 ; i<n ;i++){
            int s2= intervals[i][0];
            int e2= intervals[i][1];
            
            if(e1>=s2){
                return true;
            }
            s1= s1;
            e1= max(e1,e2);
        }
        
        return false;
        
    }
};
