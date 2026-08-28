
Problem    : Meeting Rooms
Platform   : LeetCode /252
Pattern    : Sorting + Greedy / Interval Checking
Difficulty : Easy

Intuition :

Question mein pucha hai ki kya person sari meetings
attend kar sakta hai ya nahi.

Ye tabhi possible hoga jab kisi bhi do meetings
ka time overlap na kare.

Isliye meetings ko start time ke according sort
kar denge.

Sorting ke baad meetings chronological order mein
aa jayengi aur hume sirf consecutive meetings
compare karni hongi.

-------------------------------------------------------

Approach

1. Meetings ko starting time ke according sort karo.

2. Pehli meeting ko current meeting maan lo:

   s1 = intervals[0][0]
   e1 = intervals[0][1]

3. Ab i = 1 se n-1 tak remaining meetings traverse karo.

   Current meeting:

   s2 = intervals[i][0]
   e2 = intervals[i][1]

-------------------------------------------------------

Overlap Check

Agar:

    e1 > s2

to previous meeting ka end time current meeting
ke start time se bada hai.

Example:

    [1,5]
       [3,7]

    e1 = 5
    s2 = 3

    5 > 3 → overlap

Person dono meetings attend nahi kar sakta.

Isliye:

    return false;

-------------------------------------------------------

Important Case

Agar:

    e1 == s2

Example:

    [1,5]
       [5,7]

To pehli meeting exactly 5 par end ho rahi hai
aur dusri meeting 5 par start ho rahi hai.

Isliye dono meetings attend ki ja sakti hain.

Therefore condition:

    e1 > s2

use karenge, na ki:

    e1 >= s2

-------------------------------------------------------

Non-Overlapping Case

Agar:

    e1 <= s2

to meetings overlap nahi kar rahi hain.

Current meeting ko next comparison ke liye
previous/current meeting bana do:

    s1 = s2;
    e1 = e2;

Phir next meeting check karo.

-------------------------------------------------------

Why Sorting is Necessary?

Agar meetings sorted nahi hain, to hume ye guarantee
nahi hogi ki hum previous chronological meeting
ke saath current meeting compare kar rahe hain.

Start time ke according sorting ke baad:

    start[i] <= start[i+1]

Isliye sirf consecutive meetings compare karna
sufficient hai.

-------------------------------------------------------

Algorithm

1. Meetings ko start time ke according sort karo.
2. First meeting ko current meeting banao.
3. i = 1 se n-1 tak traverse karo.
4. Current meeting ka start aur end nikalo.
5. Agar:

       e1 > s2

   → overlap hai → false return karo.
6. Otherwise current meeting ko update karo:

       s1 = s2;
       e1 = e2;

7. Agar pura loop complete ho gaya,
   → koi overlap nahi mila → true return karo.

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

Extra space:

    O(1)

Sorting ki implementation-dependent extra space
ko ignore karke.

-------------------------------------------------------


  class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
         sort(arr.begin(),arr.end());
         
         int s1= arr[0][0];
         int e1= arr[0][1];
         
         for(int i=1 ; i<arr.size() ; i++){
             int s2= arr[i][0];
             int e2= arr[i][1]; 
             
             if(e1>s2){
                
                 return false;
             }
              s1=s2;
              e1=e2;
            
         }
        return true;
         
    }
};
