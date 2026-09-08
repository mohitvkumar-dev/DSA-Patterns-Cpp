
Problem    : Longest Palindrome
Platform   : LeetCode
Problem No.: 409
Pattern    : HashMap
Difficulty : Easy

-------------------------------------------------------
Question
-------------------------------------------------------

Given string ke characters ko use karke maximum length
ka palindrome banana hai.

Hume maximum possible palindrome ki length return karni hai.

Har character ko jitni baar use karenge, palindrome mein
uska arrangement symmetric hona chahiye.


-------------------------------------------------------
Intuition
-------------------------------------------------------

Palindrome mein characters pair mein use hote hain.

Agar kisi character ki frequency even hai, toh uske
saare characters ko palindrome mein use kar sakte hain.

Example:

    c = 4

Toh:

    c c ... c c

ke form mein 4 characters use kiye ja sakte hain.


Agar frequency odd hai, toh usmein se:

    frequency - 1

characters ko pairs mein use kar sakte hain.

Example:

    a = 5

Toh 4 characters pair mein use kar sakte hain aur
1 character bach jayega.


Agar koi bhi odd-frequency character available hai,
toh unmein se kisi ek character ko palindrome ke
middle mein use kar sakte hain.

Isliye longest palindrome ke liye:

    Maximum possible pairs use karo
            +
    Agar koi odd character hai toh 1 middle character


-------------------------------------------------------
Approach
-------------------------------------------------------

Step 1:
`unordered_map<char,int>` banayenge aur string ke
saare characters ki frequency store karenge.


Step 2:
Ek boolean variable:

    odd = false

rakhenge.

Ye batayega ki string mein koi odd-frequency character
available hai ya nahi.


Step 3:
`res = 0` se initialize karenge.


Step 4:
Map par loop chalayenge aur har character ki frequency
`val` mein lenge.

Agar `val` even hai:

    res += val

Kyuki even frequency ke saare characters pairs mein
use kiye ja sakte hain.


Agar `val` odd hai:

    odd = true

Is case mein us frequency ka ek character middle ke
liye bach sakta hai aur baaki characters pairs mein
use ho sakte hain.


Step 5:
Agar `odd == false` hai, iska matlab saari frequencies
even hain.

Toh koi character middle mein rakhne ki zarurat nahi hai
aur saare characters use ho sakte hain.

Isliye:

    return res


Step 6:
Agar `odd == true` hai, toh kam se kam ek odd-frequency
character available hai.

Odd frequency wale character se:

    val - 1

characters pairs mein use karenge.

Even frequency wale characters ko completely use karenge.


Step 7:
Ek odd character ko palindrome ke middle mein rakh
sakte hain.

Isliye:

    return res + 1


-------------------------------------------------------
Example
-------------------------------------------------------

s = "abccccdd"

Frequency:

    a -> 1
    b -> 1
    c -> 4
    d -> 2


Odd frequencies:

    a -> 1
    b -> 1

Even frequencies:

    c -> 4
    d -> 2


Pairs se:

    a -> 0
    b -> 0
    c -> 4
    d -> 2

So:

    res = 6


Ab odd character available hai.

`a` ya `b` mein se kisi ek ko middle mein rakh sakte hain.

Therefore:

    answer = res + 1
           = 6 + 1
           = 7


-------------------------------------------------------
Why Only One Odd Character in Middle?
-------------------------------------------------------

Palindrome ka middle position sirf ek hota hai.

Isliye multiple odd-frequency characters ko middle
mein individually use nahi kar sakte.

Example:

    a = 1
    b = 1
    c = 1

Hum ek hi character ko middle mein rakh sakte hain.

Baaki odd frequencies mein se:

    frequency - 1

characters ko pairs mein use karenge.


-------------------------------------------------------
Key Idea
-------------------------------------------------------

Palindrome mein:

    Even frequency
        -> poori frequency use kar sakte hain

    Odd frequency
        -> frequency - 1 use kar sakte hain
        -> 1 extra odd character middle mein


Final:

    Maximum Pairs + 1 middle character (if odd exists)


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. HashMap mein characters ki frequency count karo.
2. `odd = false` aur `res = 0` initialize karo.
3. Map par loop chalao.
4. Agar frequency even hai:
       res += frequency
5. Agar frequency odd hai:
       odd = true
       res += frequency - 1
6. Agar `odd == true`:
       res += 1
7. `res` return karo.


-------------------------------------------------------
Complexity
-------------------------------------------------------

Time Complexity:
O(n)

String ko frequency count karne ke liye ek baar traverse
karte hain aur map mein limited number of characters hote
hain.


Space Complexity:
O(1)

Character set limited hai, isliye HashMap mein maximum
constant number of characters store honge.


-------------------------------------------------------
Revision Trick
-------------------------------------------------------

"PAIR + ONE"

Even frequency:

    Full frequency use karo.

Odd frequency:

    frequency - 1 use karo.

Agar koi odd mila:

    +1 middle ke liye.


Short Formula:

    answer = all possible pairs + 1(if odd exists)


-------------------------------------------------------
Pattern Connection
-------------------------------------------------------

Ye HashMap ka Frequency Counting pattern hai.

Core idea:

    Count frequencies
          ↓
    Identify even/odd
          ↓
    Maximum pairs use karo
          ↓
    One odd character middle mein


-------------------------------------------------------


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;

        for(int i=0 ; i<s.size(); i++){
            f[s[i]]++;
        }

        bool odd = false;
        int res=0; 

        for(auto i : f){
            int val = i.second;
            if(val%2==0){
                res+=val;
            }else{
                odd=true;
            }
        }

        if(odd==false){
            return res;
        }

        for(auto i : f){
            int val = i.second;
            if(val%2==1){
                res+=val-1;
            }
        }

        return res+1;
    }
};
  
