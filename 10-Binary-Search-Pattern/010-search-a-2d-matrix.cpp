
Problem    : Search a 2D Matrix
Platform   : LeetCode
Problem No.: 74
Pattern    : Binary Search
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hame ek sorted 2D matrix di gayi hai aur hame check
karna hai ki target element matrix mein present hai
ya nahi.

Matrix ki conditions:

- Har row sorted hai.
- Har row ka first element previous row ke last
  element se bada hai.

Example:

1  3  5  7
10 11 16 20
23 30 34 60

Target = 16

Hame return karna hai:

true

Agar target present nahi hai:

false


-------------------------------------------------------
Approach 1 — Brute Force
-------------------------------------------------------

Matrix ke har element ko traverse karke target se
compare karenge.

2 loops laga kar poori matrix traverse karenge.

Agar:

matrix[i][j] == target

to:

return true;

Agar poori matrix traverse karne ke baad target nahi
mila:

return false;


Time Complexity:

O(m × n)

Space Complexity:

O(1)


-------------------------------------------------------
Approach 2 — Find Row + Binary Search
-------------------------------------------------------

Observation:

Matrix ki har row sorted hai aur next row ka first
element previous row ke last element se bada hai.

Isliye first column bhi sorted hai.

Example:

1
10
23

Target = 16

Hame aisi row find karni hai jiska first element
target se chhota ya equal ho.

Matlab:

last first-column element <= target

wali row find karni hai.


-------------------------------------------------------
Intuition
-------------------------------------------------------

First column par Binary Search laga kar possible row
find kar sakte hain.

Agar:

matrix[mid][0] <= target

to ye row possible hai.

Is row ko store karenge aur right side mein search
karenge, kyunki aur neeche better row mil sakti hai.

Agar:

matrix[mid][0] > target

to target is row aur iske neeche nahi ho sakta.

Isliye left side mein search karenge.


-------------------------------------------------------
Approach
-------------------------------------------------------

1. First column par Binary Search lagao.

2. Agar:

   matrix[mid][0] <= target

   to row store karo aur:

   right = mid + 1;

3. Agar:

   matrix[mid][0] > target

   to:

   left = mid - 1;

4. Possible row milne ke baad us poori row par
   Binary Search lagao.

Time Complexity:

O(log m + log n)

Space Complexity:

O(1)


-------------------------------------------------------
Approach 3 — Single Binary Search ⭐
-------------------------------------------------------

Observation:

Puri matrix ko logically ek 1D sorted array ki tarah
imagine kar sakte hain.

Example:

Matrix:

1  3  5  7
10 11 16 20
23 30 34 60


Logically:

1  3  5  7  10  11  16  20  23  30  34  60

Ye ek completely sorted sequence hai.

Isliye poori matrix par directly Binary Search laga
sakte hain.


-------------------------------------------------------
Intuition
-------------------------------------------------------

Matrix ko actually 1D array mein convert nahi karna hai.

Hum sirf logically matrix ko 1D sorted array maanenge.

Total elements:

m × n

Therefore:

low = 0;
high = m*n - 1;


Example:

3 × 4 matrix

Total elements:

12

Valid 1D indices:

0 to 11


-------------------------------------------------------
Problem
-------------------------------------------------------

Binary Search mein:

mid

ek 1D index hoga.

Lekin matrix mein hame:

row
col

chahiye.

Isliye 1D index ko 2D index mein convert karenge.


-------------------------------------------------------
1D → 2D Mapping
-------------------------------------------------------

Formula:

row = mid / n;

col = mid % n;


Yahan:

n = number of columns


Example:

n = 4

Agar:

mid = 6

Then:

row = 6 / 4
row = 1

col = 6 % 4
col = 2

Therefore:

matrix[1][2]

Value:

16


-------------------------------------------------------
Binary Search Approach
-------------------------------------------------------

Initially:

low = 0;
high = m*n - 1;


Jab tak:

low <= high

tab tak:

mid = low + (high - low) / 2;


Ab 1D index ko 2D index mein convert karenge:

row = mid / n;
col = mid % n;


Then:

matrix[row][col]

ko target se compare karenge.


-------------------------------------------------------
Case 1 — Element == Target
-------------------------------------------------------

Agar:

matrix[row][col] == target

to target mil gaya.

Therefore:

return true;


-------------------------------------------------------
Case 2 — Element < Target
-------------------------------------------------------

Agar:

matrix[row][col] < target

to current element target se chhota hai.

Sorted order ki wajah se target right side mein hoga.

Therefore:

low = mid + 1;


-------------------------------------------------------
Case 3 — Element > Target
-------------------------------------------------------

Agar:

matrix[row][col] > target

to current element target se bada hai.

Target left side mein hoga.

Therefore:

high = mid - 1;


-------------------------------------------------------
Complete Flow
-------------------------------------------------------

1. Rows aur columns find karo.

2. Matrix ko logically 1D sorted array samjho.

3. Search space:

   low = 0;
   high = m*n - 1;

4. mid/guess calculate karo.

5. 1D index ko 2D index mein convert karo:

   row = mid / n;
   col = mid % n;

6. matrix[row][col] ko target se compare karo.

7. Agar equal:

   return true;

8. Agar element < target:

   low = mid + 1;

9. Agar element > target:

   high = mid - 1;

10. Loop khatam ho gaya aur target nahi mila:

    return false;



-------------------------------------------------------
Why Single Binary Search Works?
-------------------------------------------------------

Matrix ka given order actually ek completely sorted
sequence create karta hai.

Example:

1  3  5  7
10 11 16 20
23 30 34 60


Logically:

1  3  5  7  10  11  16  20  23  30  34  60


Isliye hum poori matrix ko ek sorted 1D array ki
tarah treat karke Binary Search laga sakte hain.

Lekin actual matrix ko flatten nahi karna hai.

Sirf:

mid / n
mid % n

ki help se required row aur column calculate
karna hai.


-------------------------------------------------------
Complexity
-------------------------------------------------------

Total elements:

m × n


Binary Search:

O(log(m × n))


Since:

log(m × n) = log m + log n


Time Complexity:

O(log(m × n))


Space Complexity:

O(1)


-------------------------------------------------------
Core Intuition
-------------------------------------------------------

> Puri 2D sorted matrix ko logically ek 1D sorted
> array maan kar Binary Search karo. Mid ko actual
> matrix position mein convert karne ke liye
> row = mid / n aur col = mid % n use karo.



-------------------------------------------------------
One-Line Intuition
-------------------------------------------------------

> Matrix ko flatten kiye bina logically 1D sorted
> array samjho, Binary Search lagao aur mid / n aur
> mid % n se row aur column find karo.


-------------------------------------------------------
Final Complexity
-------------------------------------------------------

Approach 1:

Brute Force

O(m × n)


Approach 2:

Find Row + Binary Search

O(log m + log n)


Approach 3:

Single Binary Search

O(log(m × n))


Space:

O(1)


-------------------------------------------------------


  class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int low = 0 ;
        int high= n*m-1;

        while(low<=high){
            int guess= low+(high-low)/2;
            int row= guess/m;
            int col = guess%m;

            if(matrix[row][col]==target){
                return true;
            }

            if(matrix[row][col]<target){
                low= guess+1;
            }else{
                high= guess-1;
            }
        }
        return false;
    }
};
