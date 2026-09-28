
Problem    : Kth Smallest Element
Platform   : GeeksforGeeks
Problem No.: -
Pattern    : Heap
Difficulty : Medium
 
------------------------------------------------------- 
Question
------------------------------------------------------- 
 
Hame ek array diya gaya hai aur hame uska Kth smallest
element find karna hai.
 
Example:
 
arr = [7, 10, 4, 3, 20, 15]
k = 3
 
Hame 3rd smallest element find karna hai.
 
Sorted order:
 
3  4  7  10  15  20
 
Therefore:
 
3rd smallest = 7
 
 
------------------------------------------------------- 
Approach 1 — Sorting
------------------------------------------------------- 
 
Sabse simple approach hai array ko sort kar do.
 
Example:
 
arr = [7, 10, 4, 3, 20, 15]
 
After sorting:
 
3  4  7  10  15  20
 
Kth smallest element ka index:
 
k - 1
 
Therefore:
 
return arr[k - 1]
 
 
Time Complexity:
 
O(n log n)
 
 
Space Complexity:
 
O(1)
 
Agar hame sirf Kth smallest element chahiye,
to poore array ko sort karna necessary nahi hai.
 
Isliye Heap approach use kar sakte hain.
 
 
------------------------------------------------------- 
Approach 2 — Max Heap
------------------------------------------------------- 
 
Intuition
------------------------------------------------------- 
 
Hame Kth smallest element find karna hai.
 
Hum array ke exactly K smallest elements ko
maintain kar sakte hain.
 
Agar hamare paas K smallest elements hain,
to un K elements mein jo sabse bada element hoga,
wahi Kth smallest element hoga.
 
Example:
 
K = 3
 
Agar K smallest elements hain:
 
3  4  7
 
To inmein largest:
 
7
 
hai.
 
Therefore:
 
7 = 3rd smallest
 
 
------------------------------------------------------- 
Why Max Heap?
------------------------------------------------------- 
 
Hame K smallest elements maintain karne hain.
 
In K elements mein se hame sabse bada element
quickly chahiye.
 
Max Heap ka top hamesha largest element hota hai.
 
Therefore:
 
Max Heap
 
use karenge.
 
 
Important Invariant:
 
> Max Heap mein hamesha ab tak ke K smallest
> elements maintain honge.
 
Aur:
 
heap.top()
 
un K elements mein sabse bada element hoga.
 
Therefore:
 
heap.top() = Kth smallest element
 
 
------------------------------------------------------- 
Approach
------------------------------------------------------- 
 
Step 1:
 
Ek Max Heap create karo:
 
priority_queue<int> pq;
 
 
Step 2:
 
Array ke first K elements ko heap mein
insert karo.
 
 
Example:
 
arr = [7, 10, 4, 3, 20, 15]
k = 3
 
First 3 elements:
 
7  10  4
 
Max Heap:
 
       10
      /  \
     7    4
 
heap.top() = 10
 
Abhi heap mein K elements hain.
 
 
------------------------------------------------------- 
Remaining Elements
------------------------------------------------------- 
 
Ab K ke baad ke elements ko traverse karenge.
 
Har element ko:
 
arr[i]
 
heap.top()
 
se compare karenge.
 
 
------------------------------------------------------- 
Case 1 — Current element > heap.top()
------------------------------------------------------- 
 
Agar:
 
arr[i] > heap.top()
 
to current element heap ke maximum element
se bhi bada hai.
 
Example:
 
heap elements:
 
3  4  7
 
heap.top() = 7
 
Current element:
 
20
 
Since:
 
20 > 7
 
20 K smallest elements ka part nahi ho sakta.
 
Therefore:
 
Ignore the element.
 
 
------------------------------------------------------- 
Case 2 — Current element < heap.top()
------------------------------------------------------- 
 
Agar:
 
arr[i] < heap.top()
 
to current element K smallest elements mein
aa sakta hai.
 
Lekin heap mein already K elements hain.
 
Isliye heap ke sabse bade element ko remove
karna padega.
 
Therefore:
 
pop()
 
Then current element insert karenge:
 
push(arr[i])
 
 
Example:
 
Heap:
 
3  4  7
 
Current:
 
2
 
Since:
 
2 < 7
 
7 ko remove karenge:
 
pop()
 
Aur 2 insert karenge:
 
push(2)
 
 
New K smallest elements:
 
2  3  4
 
Ab:
 
heap.top() = 4
 
 
------------------------------------------------------- 
Complete Flow
------------------------------------------------------- 
 
1. Max Heap create karo.
 
2. First K elements ko heap mein insert karo.
 
3. K ke baad remaining elements traverse karo.
 
4. Har element ke liye:
 
   Agar:
 
   arr[i] < heap.top()
 
   to:
 
   pop()
   push(arr[i])
 
5. Agar:
 
   arr[i] > heap.top()
 
   to element ignore karo.
 
6. Finally:
 
   heap.top()
 
   return karo.
 
 

------------------------------------------------------- 
Why Does This Work?
------------------------------------------------------- 
 
Hum heap mein hamesha K smallest elements
maintain kar rahe hain.
 
Jab bhi koi smaller element milta hai,
to heap ka largest element remove kar dete hain.
 
Isliye heap mein unnecessary bada element
nahi rahta.
 
Finally heap mein:
 
K smallest elements
 
rahte hain.
 
Aur inmein sabse bada element:
 
Kth smallest
 
hota hai.
 
 
------------------------------------------------------- 
Algorithm
------------------------------------------------------- 
 
1. Max Heap create karo.
 
2. First K elements heap mein push karo.
 
3. i = K se array ke end tak traverse karo.
 
4. Agar:
 
   arr[i] < pq.top()
 
   to:
 
   pq.pop()
   pq.push(arr[i])
 
5. Otherwise current element ignore karo.
 
6. Finally:
 
   return pq.top()
 
 
------------------------------------------------------- 
Complexity
------------------------------------------------------- 
 
Let:
 
n = array size
k = required smallest element
 
First K elements ko heap mein insert karna:
 
O(k log k)
 
 
Remaining:
 
(n - k)
 
elements traverse honge.
 
Har element par heap operation maximum:
 
O(log k)
 
 
Therefore:
 
Time Complexity:
 
O(n log k)
 
 
Space Complexity:
 
O(k)
 
 
------------------------------------------------------- 
Core Intuition
------------------------------------------------------- 
 
> Kth smallest element find karne ke liye
> K smallest elements ko Max Heap mein maintain karo.
> Jab koi current element heap ke top se chhota ho,
> to top ko remove karke current element insert karo.
> Finally heap ka top hi Kth smallest element hoga.
 
 
------------------------------------------------------- 
Key Pattern
------------------------------------------------------- 
 
Kth Smallest
      ↓
Maintain K smallest elements
      ↓
Max Heap
      ↓
heap.top() = largest among K smallest
      ↓
Kth Smallest
 
 
------------------------------------------------------- 
One-Line Intuition
------------------------------------------------------- 
 
> K smallest elements ko Max Heap mein maintain karo;
> unmein jo largest element hoga, wahi Kth smallest
> element hoga.
 
 
------------------------------------------------------- 



  class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>pq;
        int i;
        
        for(int i=0 ; i<k ; i++){
            pq.push(arr[i]);
        }
        
        for(int i = k ; i< arr.size() ; i++){
            if(arr[i]>= pq.top()){
                continue;
            }
            
            pq.pop();
            pq.push(arr[i]);
        }
        
        return pq.top();
    }
};
