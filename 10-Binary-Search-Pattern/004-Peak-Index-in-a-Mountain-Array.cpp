
Problem    : Peak Index in a Mountain Array
Platform   : LeetCode
Problem No.: 852
Pattern    : Binary Search
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hame ek Mountain Array diya hai.

Mountain Array mein:

- Starting mein elements increasing hote hain.
- Ek point par maximum element (peak) aata hai.
- Uske baad elements decreasing hote hain.

Hame peak element ka INDEX find karna hai.

Question mein O(log n) diya hai, isliye Binary Search
use karenge.


-------------------------------------------------------
Intuition
-------------------------------------------------------

Hame poore array ko traverse karke peak find nahi
karni hai.

Binary Search mein hum middle position ko GUESS
maanenge.

guess = low + (high - low) / 2

Ab hum guess ko uske next element se compare karenge:

arr[guess] < arr[guess + 1]

Is comparison se hame pata chalega ki hum increasing
side par hain ya decreasing side par.


-------------------------------------------------------
Case 1: arr[guess] < arr[guess + 1]
-------------------------------------------------------

Agar:

arr[guess] < arr[guess + 1]

to iska matlab hai ki array abhi increase ho raha hai.

Example:

1  3  5  7  9  6  4
      ↑  ↑
    guess next

Height increase ho rahi hai.

Isliye peak definitely RIGHT side mein hogi.

So:

low = guess + 1

guess peak nahi ho sakta, isliye usse reject kar
denge.


-------------------------------------------------------
Case 2: arr[guess] > arr[guess + 1]
-------------------------------------------------------

Agar:

arr[guess] > arr[guess + 1]

to iska matlab hai ki decrease start ho chuka hai.

Example:

1  3  5  9  7  4  2
         ↑  ↑
       guess next

Is case mein guess peak ho sakta hai.

Isliye guess ko:

res = guess

mein store karenge.

Ab kyuki current guess ek possible peak hai,
hum usko future search space se remove kar sakte hain.

Isliye:

high = guess - 1

Yahan hum guess ko discard kar rahe hain kyuki
uska index already res mein store ho chuka hai.


-------------------------------------------------------
Main Idea
-------------------------------------------------------

Hum do cheezein maintain kar rahe hain:

1. Search space:
   low aur high

2. Best peak candidate:
   res


Increasing side:

arr[guess] < arr[guess + 1]

    -> peak right mein hai
    -> low = guess + 1


Decreasing side:

arr[guess] > arr[guess + 1]

    -> guess possible peak hai
    -> res = guess
    -> high = guess - 1


-------------------------------------------------------
Approach
-------------------------------------------------------

Initially:

low = 0
high = n - 1
res = -1


Jab tak:

low <= high

tab tak:

1. guess calculate karo:

guess = low + (high - low) / 2


2. Agar:

arr[guess] < arr[guess + 1]

to peak right side mein hai:

low = guess + 1


3. Otherwise:

arr[guess] > arr[guess + 1]

to guess possible peak hai.

Isliye:

res = guess

Aur guess ko process karne ke baad left side
search karenge:

high = guess - 1


4. Finally:

return res


-------------------------------------------------------
Why Does It Work?
-------------------------------------------------------

Agar:

arr[guess] < arr[guess + 1]

to hum increasing side par hain.

Mountain array ki property ke according peak
guess ke RIGHT mein hogi.

Isliye:

low = guess + 1


Agar:

arr[guess] > arr[guess + 1]

to hum decreasing side par hain.

Iska matlab guess ek possible peak hai.

Isliye:

res = guess

kar ke current guess ko search space se remove
kar sakte hain:

high = guess - 1


Har iteration mein search space reduce hota hai,
isliye Binary Search efficiently peak find karta hai.


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. low = 0
2. high = n - 1
3. res = -1
4. Jab tak low <= high:
   a. guess calculate karo.
   b. Agar arr[guess] < arr[guess + 1]:
      low = guess + 1
   c. Otherwise:
      res = guess
      high = guess - 1
5. res return karo.


-------------------------------------------------------
Complexity
-------------------------------------------------------

Time Complexity  : O(log n)

Har iteration mein search space approximately
half ho jaata hai.


Space Complexity : O(1)

Sirf low, high, guess aur res variables use ho
rahe hain.


-------------------------------------------------------
Core Idea
-------------------------------------------------------

INCREASING:

arr[guess] < arr[guess + 1]

        ↓

Peak RIGHT mein

        ↓

low = guess + 1


DECREASING:

arr[guess] > arr[guess + 1]

        ↓

guess possible PEAK

        ↓

res = guess

        ↓

high = guess - 1

-------------------------------------------------------



class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n= arr.size();
        int low=0;
        int high=n-1;
        int res=-1;


        while(low<=high){
            int guess= low+(high-low)/2;
            if(arr[guess]<arr[guess+1]){
                
                low= guess+1;
            }
            else{
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
};
