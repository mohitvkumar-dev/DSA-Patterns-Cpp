Problem    : Meeting Rooms II
Platform   : LeetCode
Problem No.: 253
Pattern    : Sorting + Two Pointers
Difficulty : Medium

Intuition :

Hume find karna hai ki given meetings ko accommodate karne
ke liye minimum kitne meeting rooms required hain.

Har meeting ke liye ek room chahiye.

Agar ek meeting start ho rahi hai aur koi previous meeting
abhi tak end nahi hui hai, to ek extra room chahiye.

Isliye hum meeting ke start aur end times ko time ke order
mein process karenge.

Meeting start:

     → ek room occupied hoga

Meeting end:

     → ek room free ho jayega

Kisi bhi time par maximum kitne rooms occupied hain,
wahi final answer hoga.

Important:

Agar ek meeting ka end time aur dusri meeting ka start
time same hai, to purani meeting ka room free ho chuka hai.

Example:

Meeting 1: [1,5]
Meeting 2: [5,8]

5 par first meeting end ho rahi hai aur second meeting
start ho rahi hai.

Isliye same room reuse ho sakta hai.

Therefore:

     start[i] < end[j]

hone par hi new room required hoga.

-------------------------------------------------------

Approach

1. Meeting ke start aur end times ko separate arrays mein
   store karo:

     start[]
     end[]

2. Dono arrays ko independently sort karo.

3. Do pointers lo:

     i → start array
     j → end array

4. Do variables maintain karo:

     rooms    → currently occupied rooms
     maxRooms → maximum rooms required at any time

5. Jab tak saare meetings ke start times process nahi ho
   jaate, loop chalao.

-------------------------------------------------------

Case 1 — New Meeting Start Ho Rahi Hai

Agar:

     start[i] < end[j]

to iska matlab next event ek meeting ka start hai aur
abhi koi room free nahi hua.

Isliye new room chahiye:

     rooms++;

Maximum update karo:

     maxRooms = max(maxRooms, rooms);

Phir:

     i++;

-------------------------------------------------------

Case 2 — Meeting End Ho Rahi Hai

Agar:

     start[i] >= end[j]

to iska matlab ek existing meeting pehle ya same time
par end ho gayi hai.

Uska room free ho gaya.

Isliye:

     rooms--;

Phir:

     j++;

Important:

Equal case:

     start[i] == end[j]

mein bhi room free maana jayega.

Isliye condition:

     start[i] < end[j]

rakhenge, na ki:

     start[i] <= end[j]

-------------------------------------------------------

Why Two Pointers Work?

Start aur end arrays sorted hain.

Isliye har moment par hum compare kar sakte hain ki
next event meeting ka start hai ya kisi existing meeting
ka end.

     start[i] < end[j]
             ↓
        New room needed

     start[i] >= end[j]
             ↓
        Room becomes free

Is tarah rooms ki current count maintain kar sakte hain.


-------------------------------------------------------

Why Minimum Rooms = Maximum Concurrent Meetings?

Ek particular time par agar:

     3 meetings simultaneously running hain

to un teeno ko simultaneously alag rooms chahiye.

Isliye minimum required rooms:

     maximum number of simultaneous meetings

hoga.

Hum exactly isi count ko `maxRooms` mein maintain karte hain.

-------------------------------------------------------

Algorithm

1. Start times aur end times ko separate arrays mein rakho.
2. Dono arrays ko sort karo.
3. i = 0 aur j = 0 initialize karo.
4. rooms = 0 aur maxRooms = 0 rakho.
5. Jab tak i < n:
   
   Agar:

       start[i] < end[j]

   to:

       rooms++;
       maxRooms = max(maxRooms, rooms);
       i++;

   Otherwise:

       rooms--;
       j++;

6. maxRooms return karo. // yaha maxRooms hi required minimum rooms hai.

-------------------------------------------------------

Time Complexity

Start array sorting:

     O(n log n)

End array sorting:

     O(n log n)

Two-pointer traversal:

     O(n)

Overall:

     O(n log n)

-------------------------------------------------------

Space Complexity

Extra arrays:

     O(n)

Two pointers aur variables:

     O(1)

Overall auxiliary space:

     O(n)

-------------------------------------------------------



class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n= start.size();
        int room=0;
        int res=0;
        int i=0; int j=0;
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        
        while(i<n && j<n){
            if(start[i]<end[j]){
                room++;
                res= max(res,room);
                i++;
            }else{
                room--;
                j++;
            }
            
        }
        return res;
        
    }
};

