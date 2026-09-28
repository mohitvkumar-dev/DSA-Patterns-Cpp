
Problem    : Kth Largest Element in an Array
Platform   : LeetCode
Problem No.: 215
Pattern    : Heap / Top K Elements
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hame ek array diya gaya hai.

Hame array ka Kth largest element find karna hai.

Example:

nums = [3, 2, 1, 5, 6, 4]

Agar:

k = 2

Descending order:

6  5  4  3  2  1

2nd largest element = 5


-------------------------------------------------------
Intuition
-------------------------------------------------------

Hame Kth largest element chahiye.

Directly poore array ko sort bhi kar sakte hain,
lekin sorting mein:

O(n log n)

time lagega.

Hum soch sakte hain ki hame poore array ki zarurat nahi hai.

Hame sirf K largest elements maintain karne hain.

Example:

nums = [3, 2, 1, 5, 6, 4]

k = 2

Hame 2 largest elements maintain karne hain:

6, 5

In dono mein sabse chhota element:

5

Ye hi 2nd largest element hai.

Therefore:

K largest elements maintain karo
        ↓
Unme smallest element chahiye
        ↓
Use Min Heap


-------------------------------------------------------
Approach
-------------------------------------------------------

Step 1 — Min Heap banao
-------------------------------------------------------

Hame K largest elements maintain karne hain.

Un K elements mein jo smallest hoga,
wahi current Kth largest hoga.

Isliye Min Heap use karenge.

Min Heap mein:

heap.top()

smallest element deta hai.


-------------------------------------------------------
Step 2 — First K elements insert karo
-------------------------------------------------------

Array ke first K elements ko Min Heap mein
push kar do.

Example:

nums = [3, 2, 1, 5, 6, 4]

k = 2

First K elements:

3, 2

Min Heap:

    2
   /
  3

heap.top() = 2

Abhi tak ke 2 largest elements:

3, 2

mein smallest = 2.


-------------------------------------------------------
Step 3 — Remaining elements traverse karo
-------------------------------------------------------

Ab index K se lekar end tak array traverse karenge.

Har element ko:

heap.top()

se compare karenge.


-------------------------------------------------------
Case 1 — nums[i] <= heap.top()
-------------------------------------------------------

Agar:

nums[i] <= heap.top()

to current element existing K largest
elements mein enter nahi kar sakta.

Kyunki heap mein already K elements hain
aur current element unmein se smallest se
bhi chhota/equal hai.

Therefore:

Ignore the element.


-------------------------------------------------------
Case 2 — nums[i] > heap.top()
-------------------------------------------------------

Agar:

nums[i] > heap.top()

to current element existing K largest
elements mein aa sakta hai.

Lekin heap mein already K elements hain.

Isliye:

1. heap.top() ko remove karo.
2. Current element ko push karo.

Therefore:

pop()
push(nums[i])


-------------------------------------------------------
Why Min Heap Works?
-------------------------------------------------------

Hame K largest elements maintain karne hain.

Un K elements mein hame smallest element chahiye.

Min Heap hamesha smallest element ko
top par rakhta hai.

Therefore:

K largest elements
        ↓
Min Heap
        ↓
Smallest among K
        ↓
Kth largest


-------------------------------------------------------
Key Intuition
-------------------------------------------------------

Agar heap mein K largest elements hain:

        K largest elements
                ↓
       smallest among them
                ↓
          Kth largest

Isliye:

Kth Largest → Min Heap


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. Ek Min Heap create karo.

2. Array ke first K elements ko heap mein
   push karo.

3. K se n-1 tak remaining elements traverse karo.

4. Agar:

   nums[i] > heap.top()

   to:

   pop()
   push(nums[i])

5. Agar:

   nums[i] <= heap.top()

   to element ko ignore karo.

6. Finally:

   return heap.top()


-------------------------------------------------------
C++ Code
-------------------------------------------------------

  
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++) {

            if(nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};



-------------------------------------------------------
Complexity
-------------------------------------------------------

Heap mein maximum K elements rahenge.

Har element ke liye:

Comparison → O(1)

Agar replacement hua:

pop() + push() → O(log k)


Therefore:

Time Complexity:

O(n log k)


Space Complexity:

O(k)


-------------------------------------------------------
Core Intuition
-------------------------------------------------------

> K largest elements ko Min Heap mein maintain karo.
> Agar koi naya element heap ke minimum element
> se bada hai, to minimum element ko remove karke
> naye element ko insert karo. End mein heap ka top
> Kth largest element hoga.


-------------------------------------------------------
Key Pattern
-------------------------------------------------------

Kth Largest Element

        ↓

Maintain K largest elements

        ↓

Need smallest among them

        ↓

MIN HEAP

        ↓

heap.top() = Kth largest


-------------------------------------------------------
One-Line Intuition
-------------------------------------------------------

> K largest elements maintain karne ke liye Min Heap
> use karo; heap ka smallest element hi Kth largest
> element hota hai.

-------------------------------------------------------

```
