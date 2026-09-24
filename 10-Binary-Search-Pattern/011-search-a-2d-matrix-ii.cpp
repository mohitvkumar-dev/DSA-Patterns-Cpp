
Problem    : Search a 2D Matrix II
Platform   : LeetCode
Problem No.: 240
Pattern    : Search in Sorted Matrix
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hame ek m × n matrix di gayi hai.

Matrix ki property:

- Har row ascending order mein sorted hai.
- Har column ascending order mein sorted hai.

Example:

1   4   7   11
2   5   8   12
3   6   9   16
10 13   14  17

Hame check karna hai ki target matrix mein present hai
ya nahi.

Target present hai:

return true

Otherwise:

return false


-------------------------------------------------------
Intuition
-------------------------------------------------------

LC 74 ki tarah yahan normal Binary Search nahi laga
sakte.

LC 74 mein ek important property thi:

Ek row ka last element next row ke first element
se chhota hota tha.

Isliye poori matrix ko logically ek sorted 1D array
maan sakte the.

Lekin LC 240 mein aisi property nahi hai.

Example:

1   4   7   11
2   5   8   12
3   6   9   16
10 13   14  17

Yahan rows sorted hain aur columns bhi sorted hain,
lekin poori matrix ko ek single sorted 1D array ki
tarah treat nahi kar sakte.

Lekin ek useful property hai:

Har row sorted hai.
Har column sorted hai.

Isi property ka use karke hum ek corner se search
kar sakte hain.


-------------------------------------------------------
Why Top-Right Corner?
-------------------------------------------------------

Hum top-right corner se start karenge.

Example:

1   4   7   11
2   5   8   12
3   6   9   16
10 13   14  17
                ↑
              start

Start:

row = 0
col = n - 1


Top-right element ke paas do directions hain:

LEFT
DOWN


Dono directions mein sorted property ka use karke
ek complete portion eliminate kar sakte hain.


-------------------------------------------------------
Approach
-------------------------------------------------------

Initially:

row = 0
col = n - 1


Matlab top-right element se start karenge.

Har step par:

matrix[row][col]

ko target se compare karenge.


-------------------------------------------------------
Case 1 — matrix[row][col] == target
-------------------------------------------------------

Agar:

matrix[row][col] == target

to target mil gaya.

Therefore:

return true;


-------------------------------------------------------
Case 2 — matrix[row][col] < target
-------------------------------------------------------

Agar current element target se chhota hai:

matrix[row][col] < target


Current row ko dekho.

Hum top-right corner par hain.

Current row ke left wale saare elements current
element se chhote ya equal honge because row sorted hai.

Example:

1   4   7   11
            ↑
          current

Agar target:

15

hai aur current:

11

hai.

To 11 ke left:

1 4 7

ye aur bhi chhote honge.

Isliye current row mein target nahi ho sakta.

Therefore:

row++

Neeche move karenge.


Core idea:

matrix[row][col] < target
        ↓
left ke elements bhi smaller
        ↓
current row reject
        ↓
row++


-------------------------------------------------------
Case 3 — matrix[row][col] > target
-------------------------------------------------------

Agar:

matrix[row][col] > target


Current column ko dekho.

Column sorted ascending hai.

Isliye current element ke neeche wale elements
aur bade ya equal honge.

Example:

1   4   7   11
2   5   8   12
3   6   9   16
        ↑
      column

Agar current element:

11

hai aur target:

8

hai.

To 11 ke neeche:

12
16
17

ye sab aur bade hain.

Isliye current column mein target nahi ho sakta.

Therefore:

col--


Left move karenge.


Core idea:

matrix[row][col] > target
        ↓
neeche ke elements bhi larger
        ↓
current column reject
        ↓
col--


-------------------------------------------------------
Key Observation
-------------------------------------------------------

Top-right corner par:

Agar current element target se chhota hai:

    row++

Kyunki left side ke elements aur chhote honge.


Agar current element target se bada hai:

    col--

Kyunki neeche ke elements aur bade honge.


Agar equal hai:

    return true


Therefore:

matrix[row][col] < target
        ↓
      row++


matrix[row][col] > target
        ↓
      col--


matrix[row][col] == target
        ↓
      true


-------------------------------------------------------
Complete Flow
-------------------------------------------------------

1. Matrix ka top-right element choose karo.

2. Initialize:

   row = 0
   col = n - 1

3. Jab tak:

   row < m && col >= 0

4. Current element:

   matrix[row][col]

   ko target se compare karo.

5. Agar equal:

   return true

6. Agar current element target se chhota:

   row++

7. Agar current element target se bada:

   col--

8. Agar boundary cross ho gayi:

   return false


-------------------------------------------------------
Why This Approach Works?
-------------------------------------------------------

Top-right corner se start karne par current element
target ke comparison ke according ek complete row
portion ya column portion ko eliminate kar sakta hai.

If:

current < target

to current row ke left ke elements bhi smaller hain.

Isliye left side eliminate karke neeche move karte hain.


If:

current > target

to current column ke neeche ke elements bhi larger hain.

Isliye neeche ka portion eliminate karke left move
karte hain.


Har step mein search space reduce hota hai.


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. m = matrix.size()
2. n = matrix[0].size()

3. row = 0
4. col = n - 1

5. Jab tak:

   row < m && col >= 0

   a. current = matrix[row][col]

   b. Agar current == target:
      return true

   c. Agar current < target:
      row++

   d. Otherwise:
      col--

6. return false


-------------------------------------------------------
Complexity
-------------------------------------------------------

Har step mein:

- ya to row increase hoti hai
- ya col decrease hota hai

Maximum:

m rows
+
n columns

traverse ho sakte hain.

Therefore:

Time Complexity:

O(m + n)


Space Complexity:

O(1)


-------------------------------------------------------
Core Intuition
-------------------------------------------------------

> LC 74 ki tarah poori matrix ko 1D sorted array
> nahi maan sakte, kyunki yahan rows aur columns
> sorted hain but row-to-row complete ordering
> nahi hai. Isliye top-right corner se start karke
> current element ko target se compare karte hain.
> Chhota ho to neeche jaate hain, bada ho to left
> jaate hain.


-------------------------------------------------------




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        int m= matrix[0].size();

        int row= n-1;
        int col= 0;

        while(row>=0 && col<m){
            if(matrix[row][col]==target){
                return true;
            }

            if(matrix[row][col]>target){
                row--;
            }else{
                col++;
            }
        }
        return false;
    }
};
