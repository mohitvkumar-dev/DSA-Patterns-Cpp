
Problem    : Top K Frequent Elements
Platform   : LeetCode
Problem No.: 347
Pattern    : Heap / Top K Elements
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hame ek integer array nums diya gaya hai.

Hame array ke K most frequent elements return karne hain.

Example:

nums = [1,1,1,2,2,3]

k = 2

Frequency:

1 → 3
2 → 2
3 → 1

2 most frequent elements:

1, 2

Therefore:

Answer = [1,2]


-------------------------------------------------------
Approach 1 — Max Heap
-------------------------------------------------------

Intuition
-------------------------------------------------------

Sabse pehle har element ki frequency count karenge.

Example:

1 → 3
2 → 2
3 → 1

Ab hame K most frequent elements chahiye.

Agar hum frequency ke basis par ek Max Heap
banate hain, to sabse zyada frequency wala
element heap ke top par rahega.

Therefore:

Frequency Map
      ↓
Max Heap
      ↓
Highest frequency first
      ↓
Top K elements


-------------------------------------------------------
Step 1 — Frequency Count
-------------------------------------------------------

unordered_map ka use karke har element ki
frequency count karenge.

Example:

nums = [1,1,1,2,2,3]

Frequency Map:

1 → 3
2 → 2
3 → 1


-------------------------------------------------------
Step 2 — Max Heap
-------------------------------------------------------

Pair mein:

first  = frequency
second = element

Store karenge.

Max Heap:

(3,1)
(2,2)
(1,3)

Heap ka top:

(3,1)

Therefore, highest frequency wala element
top par hoga.


-------------------------------------------------------
Step 3 — K Elements Extract
-------------------------------------------------------

K times:

1. heap.top() ka element answer mein add karo.
2. heap.pop() karo.

Example:

K = 2

First pop:

(3,1)

Answer:

1

Second pop:

(2,2)

Answer:

1, 2


-------------------------------------------------------
Approach 1 Complexity
-------------------------------------------------------

Let unique elements = m.

Frequency counting:

O(n)

All unique elements ko Max Heap mein insert:

O(m log m)

K elements pop:

O(k log m)

Therefore:

Time Complexity:

O(n + m log m)

Since m <= n:

O(n log n)


Space Complexity:

O(n)


-------------------------------------------------------
Approach 2 — Min Heap of Size K
-------------------------------------------------------

Intuition
-------------------------------------------------------

Max Heap mein hum saare unique elements ko
heap mein maintain kar rahe the.

Lekin hame sirf K most frequent elements
chahiye.

Isliye hum ek Min Heap maintain karenge
jiska size maximum K hoga.

Min Heap mein sabse kam frequency wala
element top par rahega.

Agar heap mein K se zyada elements ho gaye,
to sabse kam frequency wale element ko remove
kar denge.

Therefore:

K most frequent elements maintain karo
             ↓
      Min Heap of size K
             ↓
Smallest frequency remove karo
             ↓
Heap mein Top K elements bachenge


-------------------------------------------------------
Step 1 — Frequency Count
-------------------------------------------------------

Pehle frequency map banayenge.

Example:

nums = [1,1,1,2,2,3]

Frequency:

1 → 3
2 → 2
3 → 1


-------------------------------------------------------
Step 2 — Min Heap
-------------------------------------------------------

Pair:

{frequency, element}

use karenge.

Min Heap:

(1,3)
(2,2)
(3,1)

Min Heap ka top:

(1,3)

Yani minimum frequency wala element.


-------------------------------------------------------
Step 3 — Heap Size Maintain K
-------------------------------------------------------

Har frequency-element pair ko heap mein
push karenge.

Agar:

pq.size() > k

to:

pq.pop()

kar denge.

Kyunki Min Heap ka top minimum frequency
wala element hai.

Isliye minimum frequency ko remove karne par
sirf K most frequent elements heap mein
bachenge.


-------------------------------------------------------
Why Min Heap Works?
-------------------------------------------------------

Hame K largest frequencies maintain karni hain.

Isliye hame smallest frequency wale
element ko easily identify karna hai.

Min Heap mein:

heap.top()

sabse chhoti frequency deta hai.

Agar heap size K se bada ho:

smallest frequency remove karo.

Therefore:

All frequencies
      ↓
Min Heap
      ↓
Remove minimum
      ↓
K largest frequencies remain
      ↓
Top K Frequent Elements


-------------------------------------------------------
Key Intuition
-------------------------------------------------------

Agar heap mein K elements hain:

        K elements
             ↓
   minimum frequency
             ↓
        heap.top()

Agar koi naya element aata hai jiska
frequency heap.top() se zyada hai:

        New frequency
             ↓
    Existing minimum se bada
             ↓
     Remove minimum
             ↓
      Insert new element

Isliye heap mein hamesha K most frequent
elements maintain ho sakte hain.


-------------------------------------------------------
Algorithm — Min Heap
-------------------------------------------------------

1. Ek frequency map banao.

2. Har element ki frequency count karo.

3. Ek Min Heap create karo:

   {frequency, element}

4. Frequency map traverse karo.

5. Har pair ko heap mein push karo.

6. Agar:

   pq.size() > k

   to:

   pq.pop()

7. Finally heap mein bache hue K elements
   answer mein add karo.

8. Answer return karo.


-------------------------------------------------------
C++ Code — Min Heap
-------------------------------------------------------

class Solution {
public:

    struct cmp {
        bool operator()(pair<int,int>& a,
                        pair<int,int>& b) {
            return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int> f;

        for(int i = 0; i < n; i++) {
            f[nums[i]]++;
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            cmp
        > pq;

        for(auto i : f) {

            int ele = i.first;
            int freq = i.second;

            pair<int,int> curr = {freq, ele};

            if(pq.size() < k) {
                pq.push(curr);
                continue;
            }

            if(curr.first < pq.top().first)
                continue;

            pq.pop();
            pq.push(curr);
        }

        vector<int> res;

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};


-------------------------------------------------------
Complexity — Min Heap
-------------------------------------------------------

Frequency counting:

O(n)

Let unique elements = m.

Har unique element ko heap mein process:

O(log k)

Therefore:

Time Complexity:

O(n + m log k)

Since m <= n:

O(n log k)


Space Complexity:

Frequency Map → O(n)

Heap → O(k)

Therefore:

O(n)


-------------------------------------------------------
Core Intuition
-------------------------------------------------------

> Pehle har element ki frequency count karo.
> Phir K most frequent elements maintain karne
> ke liye Min Heap of size K use karo. Agar heap
> ka size K se bada ho jaye, to minimum frequency
> wale element ko remove karo. End mein heap mein
> K most frequent elements bachenge.


-------------------------------------------------------
Key Pattern
-------------------------------------------------------

Top K Frequent Elements

          ↓

Frequency Count

          ↓

Maintain K most frequent

          ↓

MIN HEAP of size K

          ↓

Remove minimum frequency

          ↓

Top K elements remain


-------------------------------------------------------
Comparison of Both Approaches
-------------------------------------------------------

Approach 1:

Max Heap

All unique elements heap mein

Time:

O(n log n)

Space:

O(n)


Approach 2:

Min Heap of Size K

Sirf K elements maintain

Time:

O(n log k)

Space:

O(n)


-------------------------------------------------------
One-Line Intuition
-------------------------------------------------------

> K most frequent elements chahiye, isliye
> frequency count karo aur Min Heap of size K
> maintain karo; heap mein sabse kam frequency
> wale ko remove karte raho, taaki end mein
> sirf K most frequent elements bachenge.

-------------------------------------------------------

```
