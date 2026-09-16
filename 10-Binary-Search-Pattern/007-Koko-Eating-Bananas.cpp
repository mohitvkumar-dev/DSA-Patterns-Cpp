
Problem    : Koko Eating Bananas
Platform   : LeetCode
Problem No.: 875
Pattern    : Binary Search on Answer
Difficulty : Medium

-------------------------------------------------------
Question kya keh raha hai?
-------------------------------------------------------

Koko ke paas banana ke kuch piles hain.

Example:

piles = [3, 6, 7, 11]

Koko ek fixed speed k bananas/hour se bananas
khati hai.

Har hour mein woh sirf ek pile se maximum k
bananas kha sakti hai.

Agar kisi pile mein k se kam bananas bache hain,
to woh poora pile usi hour mein kha legi.

Hame MINIMUM eating speed k find karni hai jisse
Koko maximum h hours ke andar saare bananas
kha sake.


-------------------------------------------------------
Important Observation
-------------------------------------------------------

Hame banana ka answer directly array mein
search nahi karna.

Hame actually EATING SPEED k search karni hai.

Possible speeds:

1, 2, 3, 4, 5, ...., max(piles)


Example:

piles = [3, 6, 7, 11]

minimum possible speed = 1
maximum required speed = 11


To search space:

[1 -------------------- 11]
 ↑                         ↑
low                       high


-------------------------------------------------------
Why Binary Search?
-------------------------------------------------------

Agar kisi speed k par Koko ko h se zyada
hours lag rahe hain:

hours > h

to iska matlab speed bahut slow hai.

Hame speed increase karni padegi.

Therefore:

low = guess + 1


Agar kisi speed k par:

hours <= h

to Koko allowed time ke andar kha sakti hai.

Matlab ye speed VALID answer hai.

Lekin hame MINIMUM speed chahiye.

Isliye isse bhi chhoti speed try karenge:

res = guess;
high = guess - 1;


Important relationship:

speed ↑ -> eating hours ↓

speed ↓ -> eating hours ↑


Ye MONOTONIC behavior hai.

Isi wajah se Binary Search on Answer
laga sakte hain.


-------------------------------------------------------
Intuition
-------------------------------------------------------

Har iteration mein ek possible eating speed ko
GUESS maanenge.

guess = low + (high - low) / 2


Ab check karenge ki guess speed par saare
bananas kitne hours mein khatam honge.

Iske liye fun() function use karenge.


-------------------------------------------------------
fun() ka kaam
-------------------------------------------------------

fun() ka main kaam hai:

Given eating speed = guess

calculate karo ki total kitne hours lagenge.


Har pile ke liye:

piles[i] / guess

hours lagenge.

Lekin agar perfectly divide nahi hua:

piles[i] % guess != 0

to ek extra hour lagega.

Isliye:

hour += piles[i] / guess;

if (piles[i] % guess != 0) {
    hour++;
}


Ye basically:

ceil(piles[i] / guess)

calculate kar raha hai.


-------------------------------------------------------
Example
-------------------------------------------------------

piles = [3, 6, 7, 11]
guess = 4


3:

3 / 4 = 0
remainder hai

=> 1 hour


6:

6 / 4 = 1
remainder hai

=> 2 hours


7:

7 / 4 = 1
remainder hai

=> 2 hours


11:

11 / 4 = 2
remainder hai

=> 3 hours


Total:

1 + 2 + 2 + 3 = 8 hours


Therefore:

hour = 8


-------------------------------------------------------
Binary Search kaise derive hua?
-------------------------------------------------------

Sabse pehle maximum pile find karenge.

M = max(piles)


Example:

piles = [3, 6, 7, 11]

M = 11


Maximum required speed max(piles) se zyada
kabhi nahi hogi.

Agar:

k = 11

to har pile maximum 1 hour mein khatam
ho sakta hai.

Isliye:

low = 1
high = M


Ab answer speed ke range mein Binary Search
kar sakte hain.


-------------------------------------------------------
Case 1 — hours > h
-------------------------------------------------------

Suppose:

allowed hours = 8
calculated hours = 10


Matlab current speed bahut slow hai.

Koko allowed time ke andar bananas nahi
kha pa rahi.

Hame speed increase karni padegi.

Therefore:

low = guess + 1


Left side ki saari smaller speeds bhi
invalid hongi.


-------------------------------------------------------
Case 2 — hours <= h
-------------------------------------------------------

Suppose:

allowed hours = 8
calculated hours = 7


Matlab current speed VALID hai.

Koko allowed hours ke andar saare bananas
kha sakti hai.

Lekin hame MINIMUM speed chahiye.

Ho sakta hai isse chhoti speed bhi valid ho.

Isliye:

res = guess;

Aur smaller speed check karenge:

high = guess - 1;


-------------------------------------------------------
Why res?
-------------------------------------------------------

Hame MINIMUM VALID SPEED find karni hai.

Example:

speed:

3  4  5  6  7  8

valid:

X  X  X  Y  Y  Y
         ↑
   minimum valid


Jab bhi valid speed mile:

res = guess;


Phir left side search karenge:

high = guess - 1;


Finally:

res

minimum valid speed dega.

-------------------------------------------------------
Complete Flow
-------------------------------------------------------

1. Maximum pile find karo:

M = max(piles)


2. Search space define karo:

low = 1
high = M


3. guess nikalo:

guess = low + (high - low) / 2


4. guess speed par total hours calculate karo.


5. Agar:

hours > h

to speed insufficient hai:

low = guess + 1


6. Otherwise:

hours <= h

to speed valid hai:

res = guess

Aur smaller speed check karo:

high = guess - 1


7. Search khatam hone ke baad:

return res


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. Piles mein se maximum value M find karo.
2. low = 1 aur high = M rakho.
3. res = -1 rakho.
4. Jab tak low <= high:
   
   a. guess calculate karo.
   
   b. guess speed par total hours calculate karo.
   
   c. Agar hours > h:
      low = guess + 1
   
   d. Otherwise:
      res = guess
      high = guess - 1

5. res return karo.


-------------------------------------------------------
Why Does It Work?
-------------------------------------------------------

Possible speeds ka pattern dekho:

1  2  3  4  5  6  7  ... 11

X  X  X  Y  Y  Y  Y  ... Y

X = hours > h
    Invalid speed

Y = hours <= h
    Valid speed


Ek point ke baad saari speeds VALID ho jaati hain.

Hame isi FIRST/MINIMUM valid speed ko find
karna hai.

Therefore:

Binary Search on Answer.


-------------------------------------------------------
Core Pattern
-------------------------------------------------------

Is problem mein hum array ke andar answer
search nahi kar rahe.

Hum POSSIBLE ANSWER VALUES ke range mein
Binary Search kar rahe hain.

Possible Answer:

Eating Speed k

1  2  3  4  5  6  7 ... max(piles)
            ↑
          guess


Har guess par check:

"Kya is speed par Koko h hours ke andar
saare bananas kha sakti hai?"


NO:

hours > h
    -> speed badhao
    -> low = guess + 1


YES:

hours <= h
    -> answer store karo
    -> smaller speed check karo
    -> res = guess
    -> high = guess - 1


-------------------------------------------------------
One-Line Intuition
-------------------------------------------------------

Eating speed ko answer maan kar Binary Search karo.

Har speed par calculate karo ki total kitne
hours lagenge.

Agar hours zyada hain:

-> speed badhao.

Agar allowed hours ke andar hai:

-> answer store karo
-> minimum ke liye left jao.


-------------------------------------------------------
Revision Trick
-------------------------------------------------------

Binary Search on Answer:

GUESS = possible answer


Invalid:

hours > h
    -> RIGHT
    -> low = guess + 1


Valid:

hours <= h
    -> STORE
    -> LEFT
    -> res = guess
    -> high = guess - 1


Remember:

NO -> speed increase

YES -> answer store + smaller speed check


-------------------------------------------------------
Complexity
-------------------------------------------------------

Let:

n = piles.size()

M = max(piles)


Har guess speed par poore piles traverse
karne padte hain:

O(n)


Possible speeds par Binary Search:

O(log M)


Therefore:

Time Complexity = O(n log M)

Space Complexity = O(1)


-------------------------------------------------------
Pattern Connection
-------------------------------------------------------

LC 875 Binary Search on Answer ka classic
example hai.

Yahan answer array ka index nahi hai.

Answer khud ek VALUE hai:

Eating Speed = k


Is pattern ko future mein un problems mein
use kar sakte hain jahan:

- possible answer ka range diya ho
- kisi guess answer ko check kar sakte ho
- validity monotonic ho
- minimum/maximum valid answer find karna ho


-------------------------------------------------------




  class Solution {
public:
    long long fun(vector<int>& piles, int h, int guess) {
        long long hour = 0;

        for(int i = 0; i < piles.size(); i++) {
            hour += piles[i] / guess;

            if(piles[i] % guess != 0) {
                hour++;
            }
        }

        return hour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int M = INT_MIN;

        for(int i = 0; i < piles.size(); i++) {
            M = max(M, piles[i]);
        }

        int low = 1;
        int high = M;
        int res = -1;

        while(low <= high) {

            int guess = low + (high - low) / 2;

            long long hour = fun(piles, h, guess);

            if(hour > h) {
                // Speed kam hai
                low = guess + 1;
            }
            else {
                // Speed sufficient hai
                res = guess;

                // Aur kam speed try karo
                high = guess - 1;
            }
        }

        return res;
    }
};
