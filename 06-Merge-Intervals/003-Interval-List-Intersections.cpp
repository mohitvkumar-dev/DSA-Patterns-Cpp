
Problem    : Interval List Intersections
Platform   : LeetCode
Problem No.: 986
Pattern    : Two Pointers + Merge Intervals
Difficulty : Medium

Intuition :

Hume do sorted, non-overlapping interval lists di gayi hain.

Hume dono lists ke intervals ka intersection find karna hai.

Is problem ko "Merge Two Sorted Arrays" ki tarah soch sakte hain.

Dono lists already sorted hain, isliye:

    i → first list ko traverse karega
    j → second list ko traverse karega

Har step par current intervals:

    [s1, e1]
    [s2, e2]

Intersection tabhi possible hoga jab dono intervals
ek dusre ke saath overlap kar rahe hon.

Isliye problem ko 3 parts mein divide kar sakte hain:

1. Check karo intersection possible hai ya nahi.
2. Agar intersection hai, to intersection range find karo.
3. Decide karo ki i ya j mein se kisko update karna hai.

-------------------------------------------------------

Approach

1. Do pointers initialize karo:

     i = 0;
     j = 0;

   i → first list
   j → second list

2. Jab tak dono lists khatam nahi hoti:

     while(i < A.size() && j < B.size())

   tab tak traverse karo.

3. Current intervals ke start aur end nikalo:

     s1 = A[i][0]
     e1 = A[i][1]

     s2 = B[j][0]
     e2 = B[j][1]

------------------------

Part 1 — Sorted Case Check

Dono lists sorted hain, lekin current intervals mein
kisi ka start pehle aa sakta hai.

Case 1:

     s1 <= s2

Matlab first interval ka start pehle hai.

Ab check karenge:

     e1 >= s2

Agar ye true hai, to:

     [s1, e1]
          [s2, e2]

overlap karte hain.

Case 2:

     s1 > s2

Matlab second interval ka start pehle hai.

Ab check karenge:

     e2 >= s1

Agar ye true hai, to intervals overlap karte hain.

-------------------------------------------------

Part 2 — Intersection Find Karna

Agar intervals overlap karte hain, to intersection ka:

Start:

     s = max(s1, s2)

End:

     e = min(e1, e2)

Therefore:

     [max(s1,s2), min(e1,e2)]

result mein add karenge:

     res.push_back({max(s1,s2), min(e1,e2)});

Example:

     [1,5]
       [3,7]

Intersection:

     start = max(1,3) = 3
     end   = min(5,7) = 5

Therefore:

     [3,5]

-------------------------------------------------------

Part 3 — Pointer Update

Intersection find karne ke baad decide karna hai ki
kaunsa interval completely finish ho gaya.

Agar:

     e1 <= e2

to first list ka current interval pehle finish ho raha hai.

Isliye:

     i++;

Otherwise:

     j++;

Matlab:

     if(e1 <= e2)
         i++;
     else
         j++;

Reason:

Jo interval pehle end ho gaya, uske saath future mein
koi aur intersection possible nahi hai.

-------------------------------------------------------

Why Do We Move the Smaller End?

Example:

     A = [1,5]
     B = [3,7]

Intersection:

     [3,5]

A ka end = 5
B ka end = 7

A pehle finish ho gaya.

Isliye A ko move karna padega:

     i++

B ko wahi rakhenge, kyunki B ka remaining portion
future interval ke saath intersect kar sakta hai.

-------------------------------------------------------

Why Two Pointers Work?

Dono lists sorted hain.

Har comparison mein jo interval pehle finish hota hai,
uska future mein kisi later interval ke saath intersection
possible nahi hota.

Isliye us pointer ko safely aage badha sakte hain.

Isi wajah se har interval ko maximum ek baar process karna
padta hai.

-------------------------------------------------------

Algorithm

1. i = 0 aur j = 0 initialize karo.
2. Jab tak i aur j dono valid hain, loop chalao.
3. Current intervals [s1,e1] aur [s2,e2] nikalo.
4. Check karo ki intervals overlap karte hain ya nahi.
5. Agar overlap hai:
      start = max(s1,s2)
      end   = min(e1,e2)
   aur intersection result mein add karo.
6. Jiska end chhota/equal hai, us pointer ko increment karo.
7. Loop ke end mein result return karo.

-------------------------------------------------------

Time Complexity

Agar:

m = first list ka size
n = second list ka size

Har interval ko maximum ek baar process karte hain.

Time:

     O(m + n)

-------------------------------------------------------

Space Complexity

Result ko store karne ke liye:

     O(m + n)

Auxiliary pointer space:

     O(1)

-------------------------------------------------------


  class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        vector<vector<int>>res;
        int i = 0 ;
        int j= 0;

        while(i<firstList.size() && j <secondList.size()){
            int s1 = firstList[i][0];
            int e1 = firstList[i][1];

            int s2 = secondList[j][0];
            int e2 = secondList[j][1];

            if(s1<=s2){

                if(e1>=s2){
                    int s= max(s1, s2);
                    int e= min(e1, e2);
                    res.push_back({s,e});
                }
            }
            else{
                if(e2>=s1){
                    int s= max(s1, s2);
                    int e= min(e1, e2);
                    res.push_back({s,e});
                }
            }

            if(e1<=e2){
                i++;
            }else{
                j++;
            }
        }
        
        return res;
    }
};
