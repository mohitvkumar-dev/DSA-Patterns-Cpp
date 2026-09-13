
Problem    : Count Shadow Pairs
Platform   : LeetCode
Problem No.: 4054
Pattern    : Miscellaneous
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hume array mein aise pairs `(i, j)` count karne hain
jinke liye:

    1. i < j

    2. nums[i] < nums[j]

    3. i aur j ke beech koi k aisa nahi hona chahiye
       jiske liye:

       nums[k] < nums[i]


-------------------------------------------------------
Simple Meaning
-------------------------------------------------------

`i` ke baad aur `j` se pehle koi element
`nums[i]` se chhota nahi hona chahiye.

Agar `nums[i] < nums[j]` hai aur beech mein
koi smaller element nahi mila, toh `(i,j)`
ek valid Shadow Pair hai.


-------------------------------------------------------
Approach 1 — Brute Force O(n^3)
-------------------------------------------------------

Har possible `(i,j)` pair check karenge.

Step 1:

    i ko 0 se n-1 tak traverse karenge.


Step 2:

    Har fixed `i` ke liye `j` ko i+1 se
    n-1 tak traverse karenge.


Step 3:

    Sabse pehle check karenge:

        nums[i] < nums[j]

    Agar ye condition false hai, toh pair valid
    nahi ho sakta.


Step 4:

    Agar `nums[i] < nums[j]` hai, toh `i` aur `j`
    ke beech har `k` ko check karenge.

    Agar kisi `k` ke liye:

        nums[k] < nums[i]

    mil gaya, toh pair invalid hai.


Step 5:

    Agar koi smaller `k` nahi mila, toh pair
    valid hai aur answer increase karenge.


Time Complexity:

    O(n^3)

Kyunki:

    i -> O(n)
    j -> O(n)
    k -> O(n)


-------------------------------------------------------
Approach 2 — Optimized O(n^2)
-------------------------------------------------------

Observation:

Fixed `i` ke liye hum `j` ko left to right
move kar rahe hain.

Suppose:

    nums[i] = 5

Aur future mein hume:

    nums[j] > 5

chahiye.

Ab agar kisi point par:

    nums[j] < 5

mil gaya, toh ye current `j` khud ek
smaller element hai.


Example:

    i        j
    ↓        ↓
    5 ... 3 ... 8

Yahan `3 < 5`.

Ab `8` ke saath pair `(i, 8)` valid nahi hoga,
kyunki `3` already `i` aur `8` ke beech mein
hai aur:

    3 < 5


Therefore, ek baar:

    nums[j] < nums[i]

mil gaya, toh iske baad koi future `j`
valid nahi ho sakta.

Isliye:

    if(nums[j] < nums[i])
        break;


Is single observation ki wajah se `k` wala
separate loop completely remove ho jata hai.


-------------------------------------------------------
Optimized Approach — Step by Step
-------------------------------------------------------

Step 1:

    `i` ko 0 se n-1 tak traverse karo.


Step 2:

    Har fixed `i` ke liye `j = i+1` se
    right side traverse karo.


Step 3:

    Agar:

        nums[j] < nums[i]

    toh immediately break karo.

    Kyunki current `j` hi future pairs ke
    beech mein smaller element ban jayega.


Step 4:

    Agar:

        nums[i] < nums[j]

    hai, toh `(i,j)` valid Shadow Pair hai.

    Answer increase karo.


Step 5:

    Isi process ko har `i` ke liye repeat karo.


-------------------------------------------------------
Why Does Break Work?
-------------------------------------------------------

Ye optimized approach ka main observation hai.

Fixed `i` ke liye:

    nums[i] = 5

Suppose right side:

    7, 6, 3, 8, 9

Check:

    5 < 7
    -> valid pair (i, 7)

    5 < 6
    -> valid pair (i, 6)

Ab:

    3 < 5

mil gaya.

`3` ek smaller element hai.

Ab uske baad:

    8
    9

chahe `5` se bade hain, lekin unke beech
`3` already present hai.

Therefore:

    (i,8) -> invalid
    (i,9) -> invalid

Isliye yahin:

    break

kar sakte hain.


-------------------------------------------------------
Dry Run
-------------------------------------------------------

Example:

    nums = [5, 7, 6, 3, 8]

Fix:

    i = 0
    nums[i] = 5


j = 1:

    nums[j] = 7

    5 < 7
    -> valid

    count = 1


j = 2:

    nums[j] = 6

    5 < 6
    -> valid

    count = 2


j = 3:

    nums[j] = 3

    3 < 5

    Smaller element mil gaya.

    break


j = 4 wala 8 check hi nahi karenge,
because 3 already 5 se smaller hai.


For i = 0:

    valid pairs = (0,1), (0,2)


-------------------------------------------------------
Key Observation
-------------------------------------------------------

Brute force mein hum har `(i,j)` ke liye
separately `k` check kar rahe the.

Optimized approach mein:

    Current j itself becomes k

when:

    nums[j] < nums[i]

Therefore:

    smaller found -> break


Isse third loop remove ho jata hai.


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. `count = 0` initialize karo.

2. `i = 0` se `n-1` tak loop chalao.

3. Har `i` ke liye:

       j = i + 1

   se loop chalao.

4. Agar:

       nums[j] < nums[i]

   toh:

       break


5. Agar:

       nums[i] < nums[j]

   toh:

       count++


6. Finally `count` return karo.


-------------------------------------------------------
Complexity
-------------------------------------------------------

Approach 1 — Brute Force:

    Time  : O(n^3)
    Space : O(1)


Approach 2 — Optimized:

    Time  : O(n^2)
    Space : O(1)


Optimization ka main benefit:

    O(n^3) -> O(n^2)

because separate `k` loop remove ho gaya.


-------------------------------------------------------
Revision Trick
-------------------------------------------------------

Fixed `i` rakho.

Right mein `j` move karo.

    nums[i] < nums[j]
        ↓
      count

    nums[j] < nums[i]
        ↓
      break


One-line intuition:

"Smaller mil gaya toh aage sab invalid."


-------------------------------------------------------
Pattern Connection
-------------------------------------------------------

Ye problem observation-based optimization ka example
hai.

Brute force mein:

    i -> j -> k

teen loops the.

Observation:

    j itself can become the required smaller k.

Therefore:

    i -> j

sirf do loops sufficient hain.


-------------------------------------------------------




  long long count = 0;

for(int i = 0; i < n; i++) {

    for(int j = i + 1; j < n; j++) {

        if(nums[i] < nums[j]) {

            bool valid = true;

            for(int k = i + 1; k < j; k++) {

                if(nums[k] < nums[i]) {
                    valid = false;
                    break;
                }
            }

            if(valid)
                count++;
        }
    }
}



-----------------------


long long count = 0;

for(int i = 0; i < n; i++) {

    for(int j = i + 1; j < n; j++) {

        if(nums[j] < nums[i])
            break;

        if(nums[i] < nums[j])
            count++;
    }
}
  
