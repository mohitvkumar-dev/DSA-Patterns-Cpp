
Problem    : Maximum Number of Balloons
Platform   : LeetCode
Problem No.: 1189
Pattern    : HashMap
Difficulty : Easy

-------------------------------------------------------
Question


Hume given text se maximum number of "balloon" words
banane hain.

Ek "balloon" banane ke liye:

    b -> 1
    a -> 1
    l -> 2
    o -> 2
    n -> 1

characters required hain.

Hume maximum number of complete "balloon" words return
karne hain.


-------------------------------------------------------
Intuition


Ek "balloon" banane ke liye har character ki ek fixed
requirement hai.

Agar kisi character ki frequency bahut zyada hai,
toh usse koi problem nahi hai.

Lekin agar kisi required character ki frequency kam hai,
toh wahi character maximum number of balloons ko limit
karega.

Example:

Suppose:

    l -> 6

Lekin ek balloon ke liye:

    l -> 2

required hain.

Toh `l` se:

    6 / 2 = 3

balloons ban sakte hain.

Similarly, har required character ke liye calculate
karna padega ki us character se maximum kitne balloons
ban sakte hain.

In sabhi values mein jo minimum hoga, wahi answer hoga.


-------------------------------------------------------
Approach


Iske liye hum 2 unordered_map banayenge:

1. have
   -> given text ke har character ki frequency store
      karega.

2. need
   -> "balloon" ke har character ki required frequency
      store karega.


Step 1:
Given text ko traverse karke har character ki frequency
`have` map mein store karenge.

    have[text[i]]++;


Step 2:
`need` map mein "balloon" ki required frequencies store
kar lenge:

    b -> 1
    a -> 1
    l -> 2
    o -> 2
    n -> 1


Step 3:
`res = INT_MAX` se initialize karenge.

Kyunki hume har character se banne wale balloons ki
quantity ka minimum find karna hai.


Step 4:
Ab `need` map par loop chalayenge.

Har character ke liye:

    fneed = required frequency
    fhave = available frequency


Step 5:
Calculate karenge:

    times = fhave / fneed

Ye batata hai ki current character ki available
frequency se maximum kitne balloons ban sakte hain.


Step 6:
Har character ke liye minimum lenge:

    res = min(res, times)


Step 7:
Finally `res` return kar denge.




-------------------------------------------------------
Why Minimum?


Har character ek limiting resource ki tarah kaam karta
hai.

Agar:

    b -> 5 balloons
    a -> 4 balloons
    l -> 2 balloons
    o -> 3 balloons
    n -> 6 balloons

banane mein capable hain, toh hum maximum sirf 2
complete "balloon" words bana sakte hain.

Kyunki `l` ke paas sirf 2 balloons ke liye enough
characters hain.

Isliye:

    answer = minimum(times)


-------------------------------------------------------
Key Idea


Har required character ke liye:

    available frequency / required frequency

nikalenge.

Phir in sabhi values ka minimum answer hoga.

    times = fhave / fneed

    answer = min(answer, times)


-------------------------------------------------------
Algorithm


1. `have` map banao.
2. `text` ke har character ki frequency count karo.
3. `need` map mein "balloon" ki required frequencies
   store karo.
4. `res = INT_MAX` se initialize karo.
5. `need` map par loop chalao.
6. Har character ke liye:
       fhave = have[ch]
       fneed = need[ch]
       times = fhave / fneed
7. `res = min(res, times)` karo.
8. `res` return karo.


-------------------------------------------------------
Complexity


Time Complexity:
O(n)

where n = length of text.

Reason:
Text ko ek baar traverse karte hain aur required
characters ki count bahut limited hai.


Space Complexity:
O(1)

Reason:
Character set limited hai, isliye HashMaps mein
constant number of characters store honge.



-------------------------------------------------------
Pattern Connection


Ye HashMap ka Frequency Counting + Minimum Limiting
Resource pattern hai.

Core idea:

    Count frequencies
          ↓
    Compare with requirement
          ↓
    Calculate possible quantity
          ↓
    Take minimum


-------------------------------------------------------




class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>have;

        for(int i=0; i<text.size() ; i++){
            have[text[i]]++;
        }

        unordered_map<char,int>need;

        need['b']=1;
        need['a']=1;
        need['l']=2;
        need['o']=2;
        need['n']=1;

        int res= INT_MAX;

        for(auto i : need){
            char ch = i.first;
            int fneed= i.second;
            int fhave= have[ch];
            int times= fhave/fneed;

            res = min(res,times);
        }

        return res;
        
    }
};
