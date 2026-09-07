
Problem    : Ransom Note
Platform   : LeetCode
Problem No.: 383
Pattern    : HashMap
Difficulty : Easy

-------------------------------------------------------
Question


Hume check karna hai ki ransomNote ko magazine ke
characters se banaya ja sakta hai ya nahi.

RansomNote mein jo character jitni baar required hai,
magazine mein woh character kam se kam utni baar
available hona chahiye.

Agar ransomNote ki har character ki required frequency
magazine mein available frequency se less than or equal
hai, toh true return karenge.

Agar kisi bhi character ki required frequency magazine
mein available frequency se zyada hai, toh false return
kar denge.


-------------------------------------------------------
Intuition


Simple thinking:

RansomNote ko banane ke liye hume uske characters ki
requirement pata honi chahiye.

Isliye ransomNote ke har character ki frequency count
kar lenge.

Similarly, magazine mein kaun sa character kitni baar
available hai, uski bhi frequency count kar lenge.

Example:

ransomNote = "aaab"
magazine   = "aabbc"

RansomNote ki requirement:

a -> 3
b -> 1

Magazine mein available:

a -> 2
b -> 2

Ab 'a' ke liye:

required = 3
available = 2

available < required

Isliye ransomNote nahi ban sakta.

Answer = false


-------------------------------------------------------
Approach


Iske liye hum 2 unordered_map banayenge:

1. need
   -> ransomNote ke characters ki frequency store karega.

2. have
   -> magazine ke characters ki frequency store karega.


Step 1:
Pehle ransomNote ko traverse karenge aur har character
ki frequency need map mein store karenge.

    need[ransomNote[i]]++;


Step 2:
Phir magazine ko traverse karenge aur har character ki
frequency have map mein store karenge.

    have[magazine[i]]++;


Step 3:
Ab ek boolean function fun(have, need) call karenge.

Is function mein hume ransomNote ki requirements check
karni hain, isliye need map par loop chalayenge.


Step 4:
Har character ke liye:

    fneed = ransomNote mein required frequency
    fhave = magazine mein available frequency


Step 5:
Check karenge:

    if(fhave < fneed)

Agar magazine mein required frequency se kam characters
available hain, toh ransomNote nahi ban sakta.

Isliye:

    return false;


Step 6:
Agar need map ke saare characters successfully check
ho gaye aur kisi bhi character ki frequency kam nahi
mili, toh:

    return true;

-------------------------------------------------------
Why Need Map par Loop?


Hume ye check karna hai ki ransomNote ki har
requirement magazine fulfill kar pa raha hai ya nahi.

Isliye loop ransomNote ke frequency map (need) par
chalana natural hai.

Har required character ke liye magazine ki available
frequency check karenge.


-------------------------------------------------------
Key Idea


RansomNote ki har character ki frequency,
Magazine mein kam nahi honi chahiye.

    Need <= Have  -> true
    Need > Have   -> false

Agar ek bhi character ke liye:

    have < need

hua, toh immediately false.


-------------------------------------------------------
Algorithm


1. need aur have naam ke 2 HashMaps banao.

2. ransomNote traverse karo:
       need[ransomNote[i]]++

3. magazine traverse karo:
       have[magazine[i]]++

4. need map par loop chalao.

5. Har character ke liye:
       fneed = need[ch]
       fhave = have[ch]

6. Agar:
       fhave < fneed

   toh return false.

7. Agar poora loop complete ho gaya:
       return true.


-------------------------------------------------------
Complexity


Let:

n = length of ransomNote
m = length of magazine

Time Complexity:
O(n + m)

Reason:
Dono strings ko frequency count karne ke liye
ek-ek baar traverse kar rahe hain aur need map ko
check bhi kar rahe hain.

Space Complexity:
O(k)

where k = number of distinct characters stored
in the HashMaps.


-------------------------------------------------------
Revision Trick


"NEED vs HAVE"

RansomNote  -> NEED
Magazine    -> HAVE

Har NEED ko check karo:

    Kya HAVE enough hai?

Yes -> continue
No  -> false

Sab requirements fulfill ho gayi
        ↓
      true


-------------------------------------------------------
Pattern Connection
-------------------------------------------------------

Ye HashMap ka basic Frequency Counting pattern hai.

Jab question mein characters/items ki frequency compare
karni ho, toh HashMap ka thought aana chahiye.

Core Pattern:

    Count -> Store -> Compare

-------------------------------------------------------




class Solution {
public:

   bool fun(unordered_map<char,int>have,unordered_map<char,int>need){
      for(auto i: need){
        char ch= i.first;
        int  fneed=i.second;
        int  fhave=have[ch];

        if(fhave < fneed){
            return false;
        }

        
      }
      return true;
    }


    bool canConstruct(string ransomNote, string magazine) {
        
    unordered_map<char,int>need;
    unordered_map<char,int>have;

    for(int i=0 ; i<ransomNote.size(); i++){
        need[ransomNote[i]]++;
    }

    for(int i=0 ; i<magazine.size(); i++){
        have[magazine[i]]++;
    }

    return fun(have,need);

    }

};
