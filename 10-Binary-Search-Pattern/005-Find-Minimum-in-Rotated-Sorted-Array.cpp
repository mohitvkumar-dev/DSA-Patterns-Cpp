
Problem    : Find Minimum in Rotated Sorted Array
Platform   : LeetCode
Problem No.: 153
Pattern    : Binary Search
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hame ek sorted array diya gaya hai jo rotate hua hai.

Hame array ka MINIMUM element return karna hai.

Agar array rotated nahi hai:

1 2 3 4 5
↑
minimum

to first element hi minimum hoga.

Agar array rotated hai:

4 5 6 7 0 1 2
        ↑
      minimum

to minimum rotation ke baad starting wale part ke
baad aa gaya hai.


-------------------------------------------------------
Intuition
-------------------------------------------------------

Original sorted array ko agar rotate kiya jaye, to
array do parts mein divide ho jata hai:

Part 2 | Part 1

Example:

Original:

1 2 3 4 5 6 7

Rotated:

5 6 7 | 1 2 3 4
Part 2 | Part 1


Part 2:
Original array ke last elements.

Part 1:
Original array ke first elements.


-------------------------------------------------------
Important Observation
-------------------------------------------------------

Part 1 ka FIRST element hi minimum hota hai.

Example:

5 6 7 | 1 2 3 4
        ↑
      minimum

Isliye hame actually:

"Part 1 ki first occurrence"

find karni hai.

Ye conceptually First Occurrence Binary Search
jaisa hai.


-------------------------------------------------------
Part 1 aur Part 2 kaise identify karein?
-------------------------------------------------------

Binary Search mein guess index lenge:

guess = low + (high - low) / 2

Ab hame pata karna hai ki guess Part 1 mein hai
ya Part 2 mein.

Iske liye nums[last] ko reference lenge.


Example:

5 6 7 | 1 2 3 4
            ↑
           last

nums[last] = 4


Part 2:

5 6 7

Ye sab nums[last] se GREATER hain.


Part 1:

1 2 3 4

Ye sab nums[last] se SMALLER OR EQUAL hain.


Therefore:

nums[guess] > nums[last]

-> guess Part 2 mein hai.


nums[guess] <= nums[last]

-> guess Part 1 mein hai.


-------------------------------------------------------
Case 1: Guess Part 2 mein hai
-------------------------------------------------------

Agar:

nums[guess] > nums[last]

to guess Part 2 mein hai.

Example:

5 6 7 | 1 2 3 4
  ↑
guess

Minimum Part 1 mein hai.

Aur Part 1 guess ke RIGHT side mein hai.

Isliye:

low = guess + 1


-------------------------------------------------------
Case 2: Guess Part 1 mein hai
-------------------------------------------------------

Agar:

nums[guess] <= nums[last]

to guess Part 1 mein hai.

Example:

5 6 7 | 1 2 3 4
            ↑
          guess

guess minimum ho sakta hai.

Lekin guess Part 1 ki FIRST occurrence hai,
ye guaranteed nahi hai.

Ho sakta hai minimum guess ke LEFT side mein ho.

Isliye:

res = guess

Aur first occurrence find karne ke liye
left side search karenge:

high = guess - 1


-------------------------------------------------------
Complete Approach
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

nums[guess] > nums[last]

to guess Part 2 mein hai.

Minimum right side mein hai.

Therefore:

low = guess + 1


3. Otherwise:

nums[guess] <= nums[last]

guess Part 1 mein hai.

guess possible minimum hai.

Therefore:

res = guess

Aur aur left mein smaller/first element
check karne ke liye:

high = guess - 1


4. Finally:

return nums[res]


-------------------------------------------------------
Why Does It Work?
-------------------------------------------------------

Rotated sorted array ko do parts mein divide kar
sakte hain:

Part 2 | Part 1

Part 2 ke elements:

nums[last] se greater hote hain.

Part 1 ke elements:

nums[last] se smaller ya equal hote hain.


Therefore:

nums[guess] > nums[last]

-> Part 2
-> minimum RIGHT side mein
-> low = guess + 1


nums[guess] <= nums[last]

-> Part 1
-> guess possible minimum
-> res = guess
-> first occurrence ke liye LEFT search
-> high = guess - 1


Is tarah hum Part 1 ki first occurrence find
karte hain.

Aur Part 1 ki first occurrence hi minimum element
hai.


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. low = 0 set karo.
2. high = n - 1 set karo.
3. res = -1 set karo.
4. nums[last] ko reference value ke roop mein use karo.
5. Jab tak low <= high:
   a. guess calculate karo.
   b. Agar nums[guess] > nums[last]:
      low = guess + 1
   c. Otherwise:
      res = guess
      high = guess - 1
6. nums[res] return karo.


-------------------------------------------------------
Complexity
-------------------------------------------------------

Time Complexity:

O(log n)

Har iteration mein search space approximately
half ho jaata hai.


Space Complexity:

O(1)

Sirf low, high, guess aur res variables use
kiye ja rahe hain.


-------------------------------------------------------
Core Idea
-------------------------------------------------------

Rotated Sorted Array:

Part 2 | Part 1
        ↑
      Minimum

nums[last] ko reference bana kar:

nums[guess] > nums[last]
        ↓
    Part 2
        ↓
   RIGHT jao
        ↓
low = guess + 1


nums[guess] <= nums[last]
        ↓
     Part 1
        ↓
Possible minimum
        ↓
res = guess
        ↓
LEFT jao
        ↓
high = guess - 1


-------------------------------------------------------
Revision Trick
-------------------------------------------------------

LC 153 ko yaad rakho:

"Minimum = Part 1 ki FIRST occurrence"


Reference:

nums[last]


Rule:

GREATER THAN last
    -> Part 2
    -> RIGHT


LESS THAN OR EQUAL TO last
    -> Part 1
    -> res store
    -> LEFT


So:

> Part 2 -> Right
> Part 1 -> Store + Left


-------------------------------------------------------
Pattern Connection
-------------------------------------------------------

Ye problem Binary Search ke "First Occurrence"
concept se connected hai.

Normal First Occurrence:

Target mila
    -> res = guess
    -> LEFT


Yahan:

Part 1 mila
    -> res = guess
    -> LEFT


Difference sirf itna hai ki yahan exact target
search nahi kar rahe.

Hum Part 1 ki boundary search kar rahe hain.

Aur us boundary ka first element minimum hai.


-------------------------------------------------------




class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int low= 0;
        int high= n-1;
        int res=-1;

        while(low<=high){
            int guess= low+(high-low)/2;
            if(nums[guess]>nums[n-1]){
                low= guess+1;
            }else{
                res= guess;
                high=guess-1;
            }
        }
        return nums[res];
    }
};
