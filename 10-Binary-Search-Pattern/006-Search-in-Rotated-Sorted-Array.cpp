
Problem    : Search in Rotated Sorted Array
Platform   : LeetCode
Problem No.: 33
Pattern    : Binary Search
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hame ek sorted array diya hai jo rotate hua hai.

Hame target ka index find karna hai.

Agar target array mein present hai to uska index
return karna hai.

Agar target present nahi hai to:

return -1;


Question mein:

Time Complexity = O(log n)

diya hai, isliye Binary Search use karenge.


-------------------------------------------------------
Approach 1 — Minimum Find Karke 2 Binary Search
-------------------------------------------------------

Rotated sorted array ko dhyan se dekhen:

5 6 7 | 1 2 3 4
Part 1 | Part 2

Rotation ke baad array do parts mein divide ho
jata hai aur dono parts individually sorted hote hain.

Agar pehle minimum element find kar lein:

5 6 7 | 1 2 3 4
        ↑
      minimum

to hame dono sorted parts mil jayenge.

Phir target kis part mein ho sakta hai ye determine
karke us part par Binary Search laga sakte hain.

Lekin is approach mein multiple searches/passes
ho sakte hain.

Isliye hum single Binary Search mein target find
karne ki koshish karenge.


-------------------------------------------------------
Approach 2 — Single Pass Rotated Binary Search
-------------------------------------------------------

Har iteration mein ek index GUESS lenge:

guess = low + (high - low) / 2

Sabse pehle target check karenge:

if (nums[guess] == target)

to target mil gaya.

Therefore:

return guess;


Agar target nahi mila, to hame decide karna hai ki
target left mein hai ya right mein.

Iske liye pehle identify karenge ki guess kis
sorted part mein hai.


-------------------------------------------------------
Part Identify Karna
-------------------------------------------------------

nums[last] ko reference ke roop mein use karenge.

Example:

5 6 7 | 1 2 3 4
Part 1 | Part 2

nums[last] = 4


Part 1 ki values:

5 6 7

Ye nums[last] se GREATER hain.


Part 2 ki values:

1 2 3 4

Ye nums[last] se SMALLER OR EQUAL hain.


Therefore:

nums[guess] > nums[last]

-> guess Part 1 mein hai.


nums[guess] <= nums[last]

-> guess Part 2 mein hai.


-------------------------------------------------------
Case 1 — Guess Part 1 Mein Hai
-------------------------------------------------------

Part 1:

5 6 7

Example:

5 6 7 | 1 2 3 4
  ↑
guess


Part 1 sorted hai.

Agar:

nums[guess] < target

to target guess ke RIGHT mein ho sakta hai.

Lekin target Part 2 mein bhi ho sakta hai.

Isliye Part 1 ke leftmost element ko reference
karenge:

nums[0]


Agar:

nums[guess] < target

aur target Part 1 ke range mein nahi hai,
to Part 2 mein hoga.

Code mein:

if (nums[guess] < target)
    low = guess + 1;

Otherwise:

if (nums[0] > target)
    low = guess + 1;
else
    high = guess - 1;


Meaning:

target < nums[0]

-> target Part 2 mein hai
-> right side search karo

Otherwise:

target >= nums[0]

-> target Part 1 mein ho sakta hai
-> left side search karo.


-------------------------------------------------------
Case 2 — Guess Part 2 Mein Hai
-------------------------------------------------------

Part 2:

1 2 3 4

Example:

5 6 7 | 1 2 3 4
          ↑
        guess


Part 2 bhi sorted hai.

Agar:

nums[guess] > target

to target guess ke LEFT mein hoga:

high = guess - 1


Agar:

nums[guess] < target

to target guess ke RIGHT mein ho sakta hai.

Lekin target Part 1 mein bhi ho sakta hai.

Isliye nums[last] ko reference karenge.

Agar:

nums[last] < target

to target Part 1 mein hai.

Isliye:

high = guess - 1


Otherwise:

target Part 2 mein ho sakta hai.

Isliye:

low = guess + 1


-------------------------------------------------------
Complete Logic
-------------------------------------------------------

Har iteration:

1. guess calculate karo.

2. Agar:

nums[guess] == target

to:

return guess


3. Check karo guess kis part mein hai:

nums[guess] > nums[n-1]

-> Part 1 (badi values wala part)


Otherwise:

-> Part 2 (chhoti values wala part)


4. Sorted part aur target ke range ko compare karke
   low/high update karo.


-------------------------------------------------------
Code Logic
-------------------------------------------------------

Part 1:

if (nums[guess] > nums[n-1]) {

    if (nums[guess] < target) {

        low = guess + 1;

    } else {

        if (nums[0] > target) {

            low = guess + 1;

        } else {

            high = guess - 1;

        }
    }
}


Part 2:

if (nums[guess] > target) {

    high = guess - 1;

} else {

    if (nums[n-1] < target) {

        high = guess - 1;

    } else {

        low = guess + 1;

    }
}



-------------------------------------------------------
Why Does It Work?
-------------------------------------------------------

Rotated sorted array ko do sorted parts ki tarah
dekh sakte hain.

Example:

5 6 7 | 1 2 3 4


Har iteration mein hum:

1. Guess find karte hain.

2. Identify karte hain ki guess kis part mein hai.

3. Kyuki woh part sorted hai, hum target ki
   position/range determine kar sakte hain.

4. Jo half possible nahi hai usse reject kar dete hain.

Isliye har iteration mein search space reduce hota hai.


-------------------------------------------------------
Core Intuition
-------------------------------------------------------

Rotated array ko unsorted array mat samjho.

Har iteration mein kam se kam ek sorted part
available hota hai.

Process:

Guess
  ↓
Part identify karo
  ↓
Sorted range dekho
  ↓
Target range mein hai?
  ↓
YES → us side search
NO  → doosri side search


-------------------------------------------------------
Revision Trick
-------------------------------------------------------

First:

nums[guess] == target
    -> return guess


Then:

nums[guess] > nums[last]

    -> Part 1
    -> badi values wala part


Otherwise:

    -> Part 2
    -> chhoti values wala part


Part 1 mein:

target ka comparison nums[0] ke range se


Part 2 mein:

target ka comparison nums[last] ke range se


Main rule:

> Sorted half identify karo,
> phir target us sorted half ke range mein hai
> ya nahi check karo.


-------------------------------------------------------
Time Complexity
-------------------------------------------------------

Time Complexity:

O(log n)

Har iteration mein search space approximately
half hota jaata hai.


Space Complexity:

O(1)

Sirf low, high aur guess jaise variables use
kiye ja rahe hain.


-------------------------------------------------------
Important Point
-------------------------------------------------------

Is problem mein:

1. Pehle minimum find karke 2 Binary Search
   kar sakte hain.

2. Lekin optimized approach mein ek hi Binary
   Search ke andar sorted part identify karke
   target search kar sakte hain.

Tumhara code second approach use karta hai.


-------------------------------------------------------


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int low= 0;
        int high= n-1;

        while(low<=high){
            int guess = low +(high-low)/2;

            if(nums[guess]==target){
                return guess;
            }

            // decide guess is from which part

            // part1 ---- badi values

            if(nums[guess]>nums[n-1]){
               if(nums[guess]<target){
                 low = guess+1;
               }else{
                  if(nums[0]>target){
                    low= guess+1;
                  }else{
                    high=guess-1;
                  }
               }
               continue;
            }

            // part2 ----- chhoti values

            if(nums[guess]>target){
                high= guess-1;
            }else{
                if(nums[n-1]<target){
                    high= guess-1;
                }else{
                    low = guess+1;
                }
            }
        }
        return -1;
    }
};
