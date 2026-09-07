
Problem    : First Unique Character in a String
Platform   : LeetCode
Problem No.: 387
Pattern    : HashMap
Difficulty : Easy

-------------------------------------------------------
Question

Hume string mein pehla aisa character find karna hai
jo sirf ek baar occur hua ho.

Agar koi unique character nahi hai, toh -1 return
karna hai.

Example:

s = "leetcode"

Frequency:
l -> 1
e -> 3
t -> 1
c -> 1
o -> 1
d -> 1

String ko left to right dekhenge:

l -> frequency 1
Isliye l first unique character hai.

Answer = 0


-------------------------------------------------------
Intuition


Hume "first unique character" chahiye.

Sirf frequency count karne se kaam nahi chalega,
kyunki hume ye bhi maintain karna hai ki string mein
kaunsa character pehle aaya tha.

Isliye:

1. Pehle har character ki frequency count karenge.
2. Phir string ko left to right dobara traverse karenge.
3. Jis character ki frequency 1 milegi, wahi
   first unique character hoga.

Frequency store karne ke liye unordered_map use karenge.

unordered_map<char, int> freq;


-------------------------------------------------------
Approach


Hum 2 passes mein string traverse karenge.

Step 1:
Ek unordered_map<char, int> banayenge.

Step 2:
String ko first time traverse karke har character
ki frequency store karenge:

freq[s[i]]++;


Step 3:
Ab string ko second time left to right traverse karenge.

Har character ki frequency check karenge:

if(freq[s[i]] == 1)

Agar frequency 1 hai, toh ye unique character hai.

Kyuki hum string ko left to right traverse kar rahe hain,
isliye jo pehla character frequency 1 wala milega,
wahi first unique character hoga.

Uska index i return kar denge.


Step 4:
Agar poori string traverse karne ke baad bhi koi
unique character nahi mila, toh -1 return karenge.


-------------------------------------------------------
Why 2 Passes?


Pehle pass mein hume sirf ye pata karna hai ki har
character kitni baar aaya hai.

Example:

s = "loveleetcode"

Pehle pass ke baad:

l -> 2
o -> 2
v -> 1
e -> 4
t -> 1
c -> 1
d -> 1

Ab hume first unique character chahiye.

Isliye second pass mein original string ka order
maintain karte hue check karenge:

l -> 2 -> unique nahi
o -> 2 -> unique nahi
v -> 1 -> unique

Isliye answer = 2.


-------------------------------------------------------

Key Idea


Frequency count karne ke liye HashMap use karenge.

Lekin first unique character find karne ke liye
second traversal string ke original order mein
karna zaroori hai.

Yahi "first" unique character guarantee karta hai.


-------------------------------------------------------
Algorithm


1. unordered_map<char, int> freq banao.
2. String ko traverse karke frequency count karo.
3. String ko dobara left to right traverse karo.
4. Agar freq[s[i]] == 1 hai:
      return i
5. Agar koi unique character nahi mila:
      return -1


-------------------------------------------------------
Complexity


Time Complexity:
O(n)

Reason:
String ko maximum 2 baar traverse kar rahe hain.

O(n) + O(n) = O(n)


Space Complexity:
O(k)

where k = number of distinct characters.

HashMap mein sirf distinct characters store honge.

---------------------------------------------

Pattern Connection


Ye HashMap / Frequency Counting ka basic pattern hai.

Jab question mein aaye:

- frequency count karo
- duplicate find karo
- unique character find karo
- occurrence count karo

Toh HashMap / Frequency Array ka thought aana chahiye.

-------------------------------------------------------



class Solution {
public:
    int firstUniqChar(string s) {
        int n= s.size();

        unordered_map<char,int>f;

        for(int i=0 ; i<n ; i++){
            f[s[i]]++;
        }
        for(int i=0 ; i<n ; i++){
            if(f[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};
