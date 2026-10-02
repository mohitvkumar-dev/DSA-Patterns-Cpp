
Problem    : Top K Frequent Words
Platform   : LeetCode
Problem No.: 692
Pattern    : Heap / Top K Elements
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hame strings ka ek array words diya gaya hai.

Hame K most frequent words return karne hain.

Agar do words ki frequency same ho, to
lexicographically smaller word pehle aayega.

Example:

words = ["i","love","leetcode","i","love","coding"]

k = 2

Frequency:

i       → 2
love    → 2
leetcode → 1
coding   → 1

Same frequency hone par:

"i" < "love"

Therefore:

Answer = ["i","love"]


-------------------------------------------------------
Intuition
-------------------------------------------------------

Sabse pehle har word ki frequency count karenge.

Example:

i    → 2
love → 2
coding → 1

Hame sirf K most frequent words chahiye.

Isliye hum K size ka Min Heap maintain karenge.

Lekin yahan ek extra condition hai:

Agar frequency same ho, to
lexicographically larger word ko remove karna hai.

Therefore:

Higher frequency
        ↓
Better word

Same frequency:
Lexicographically smaller
        ↓
Better word


-------------------------------------------------------
Approach — Min Heap of Size K
-------------------------------------------------------

Hame K best words maintain karne hain.

Min Heap mein hamesha K elements mein se
worst element top par rakhenge.

Worst element:

1. Jiski frequency sabse kam ho.

2. Agar frequency same ho, to jo word
   lexicographically larger ho.


-------------------------------------------------------
Step 1 — Frequency Count
-------------------------------------------------------

unordered_map<string,int> ka use karke
har word ki frequency count karenge.

Example:

words = ["i","love","leetcode","i","love","coding"]

Frequency:

i        → 2
love     → 2
leetcode → 1
coding   → 1


-------------------------------------------------------
Step 2 — Pair Create Karo
-------------------------------------------------------

Har word ke liye:

pair<int,string>

use karenge.

first  = frequency
second = word

Example:

(2,"i")
(2,"love")
(1,"leetcode")
(1,"coding")


-------------------------------------------------------
Step 3 — Custom Comparator
-------------------------------------------------------

Normal Min Heap mein smallest pair top par aata hai.

Lekin hame apne according
"Worst" element top par chahiye.

Rules:

Lower frequency → worse

Same frequency:
Lexicographically larger word → worse


Comparator:

if frequency same hai:

a.second < b.second

return karenge.

Aur frequency ke liye:

a.first > b.first


-------------------------------------------------------
Step 4 — First K Elements
-------------------------------------------------------

Agar:

pq.size() < k

to current pair ko directly heap mein
push karenge.


-------------------------------------------------------
Step 5 — Heap Size K Maintain Karo
-------------------------------------------------------

Agar heap already K elements contain karta hai,
to current word ko heap ke top se compare karenge.

Agar current word worse hai:

Ignore.


Agar current word better hai:

1. Heap ka worst element pop karo.
2. Current word push karo.


-------------------------------------------------------
Comparison
-------------------------------------------------------

Current frequency < top frequency

        ↓

Current word worse

        ↓

Ignore


-------------------------------------------------------

Current frequency > top frequency

        ↓

Current word better

        ↓

Pop top
Push current


-------------------------------------------------------

Same frequency:

Current word > top word

        ↓

Current word lexicographically larger

        ↓

Current word worse

        ↓

Ignore


-------------------------------------------------------

Same frequency:

Current word < top word

        ↓

Current word lexicographically smaller

        ↓

Current word better

        ↓

Pop top
Push current


-------------------------------------------------------
Example
-------------------------------------------------------

words = ["i","love","leetcode","i","love","coding"]

k = 2


Frequency:

i        → 2
love     → 2
leetcode → 1
coding   → 1


-------------------------------------------------------

Insert:

(2,"i")

Heap:

(2,"i")


-------------------------------------------------------

Insert:

(2,"love")

Heap:

(2,"love")
(2,"i")

Because frequency same hai aur
"love" lexicographically larger hai,
"love" worse candidate hai.

Therefore:

heap.top() = (2,"love")


-------------------------------------------------------

Next:

(1,"leetcode")

Frequency:

1 < 2

Therefore:

"leetcode" worse hai.

Ignore.


-------------------------------------------------------

Next:

(1,"coding")

Frequency:

1 < 2

Therefore:

"coding" worse hai.

Ignore.


-------------------------------------------------------

Final Heap:

(2,"love")
(2,"i")


Heap mein K best elements hain.


-------------------------------------------------------
Step 6 — Result
-------------------------------------------------------

Heap se elements pop karne par
worst-to-best order milega.

Isliye result ko reverse karenge.

Example:

Heap pop order:

love
i

Reverse:

i
love

Therefore:

Answer = ["i","love"]


-------------------------------------------------------
Why Min Heap Works?
-------------------------------------------------------

Hame K best elements maintain karne hain.

Isliye hame un K elements mein se
worst element ko easily identify karna hai.

Min Heap ke top par hum:

Lowest frequency
OR
Same frequency mein lexicographically larger word

rakhte hain.

Therefore:

K elements
      ↓
Worst element at top
      ↓
New better element aaye
      ↓
Pop worst
      ↓
Push new element


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. Frequency map banao.

2. Har word ki frequency count karo.

3. Ek Min Heap create karo:

   pair<frequency, word>

4. Custom comparator use karo.

5. Frequency map traverse karo.

6. Agar:

   pq.size() < k

   to current pair push karo.

7. Otherwise current pair ko
   heap.top() se compare karo.

8. Agar current pair better hai:

   pop()
   push(current)

9. Agar current pair worse hai:

   ignore karo.

10. Heap se elements result mein add karo.

11. Result ko reverse karo.

12. Answer return karo.


-------------------------------------------------------
C++ Code
-------------------------------------------------------

class Solution {
public:

    struct cmp {
        bool operator()(pair<int,string>& a,
                        pair<int,string>& b) {

            if(a.first == b.first)
                return a.second < b.second;

            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        int n = words.size();

        unordered_map<string,int> f;

        for(int i = 0; i < n; i++) {
            f[words[i]]++;
        }

        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            cmp
        > pq;

        for(auto i : f) {

            string ele = i.first;
            int freq = i.second;

            pair<int,string> curr = {freq, ele};

            if(pq.size() < k) {
                pq.push(curr);
                continue;
            }

            if(curr.first < pq.top().first)
                continue;

            if(curr.first == pq.top().first &&
               curr.second > pq.top().second)
                continue;

            pq.pop();
            pq.push(curr);
        }

        vector<string> res;

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};


-------------------------------------------------------
Complexity
-------------------------------------------------------

Frequency counting:

O(n)


Let unique words = m.

Har unique word ko Min Heap mein process:

O(log k)


Therefore:

Time Complexity:

O(n + m log k)


Since:

m <= n

Worst case:

O(n log k)


Space Complexity:

Frequency Map → O(n)

Heap → O(k)

Result → O(k)

Therefore:

O(n)


-------------------------------------------------------
Core Intuition
-------------------------------------------------------

> Pehle har word ki frequency count karo.
> Phir K best words maintain karne ke liye
> Min Heap of size K use karo. Heap ke top par
> worst word rakho — yani lowest frequency wala,
> aur same frequency par lexicographically larger
> word. Jab koi better word aaye to worst word ko
> remove karke naye word ko insert karo.


-------------------------------------------------------
Key Pattern
-------------------------------------------------------

Top K Frequent Words

          ↓

Frequency Count

          ↓

Min Heap of Size K

          ↓

Worst element at top

          ↓

Lower frequency remove

          ↓

Same frequency:
Lexicographically larger remove

          ↓

K best words remain


-------------------------------------------------------
One-Line Intuition
-------------------------------------------------------

> K best words maintain karne ke liye size K ka
> Min Heap rakho, jisme worst word top par ho;
> better word aane par worst ko remove karke
> current word insert karo.

-------------------------------------------------------

```
