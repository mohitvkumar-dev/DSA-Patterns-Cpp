
Problem    : Next Greater Element II
Platform   : LeetCode
Problem No.: 503
Pattern    : Monotonic Stack + Circular Array
Difficulty : Medium

Intuition :

Hume har element ke liye uske right side ka
FIRST GREATER ELEMENT find karna hai.

Example:

nums = [1,2,1]

1 ka next greater = 2
2 ka next greater = -1
1 ka next greater = 2

Answer:
[2,-1,2]

Normally Next Greater Element problem mein hum
right se left traverse karke Monotonic Stack use
kar sakte hain.

Lekin yahan array circular hai.

Matlab last element ke baad hum dobara first
element par aa sakte hain.

-------------------------------------------------------

Normal Array vs Circular Array

Normal:

[1,2,1]
       ↓
       END

Circular:

[1,2,1]
 ↑     |
 └─────┘

Last element ke baad first element dobara available hai.

Example:

nums = [1,2,1]

Last 1 ke right side circularly:

1 → 1 → 2

Isliye last 1 ka next greater:

2

-------------------------------------------------------

Main Problem

Circular array ki wajah se last elements ke liye
beginning ke elements bhi consider karne padenge.

Actual array ko duplicate karne ke bajay hum
virtually array ko 2 times traverse karenge.

Conceptually:

[1,2,1 | 1,2,1]

Actual array duplicate nahi karenge.

Instead:

idx = i % n

use karke circular indexing simulate karenge.

-------------------------------------------------------

Monotonic Stack Intuition

Stack mein hum useful greater-element candidates
rakhenge.

Har current element nums[idx] ke liye:

Agar:

stack.top() <= nums[idx]

to stack ka top current element ka next greater
nahi ho sakta.

Isliye:

stack.pop();

Ye process tab tak chalega jab tak:

stack.empty()

ya

stack.top() > nums[idx]

na ho jaye.

Agar stack empty nahi hai:

stack.top()

current element ka next greater candidate hoga.

-------------------------------------------------------

Why Smaller or Equal Elements Pop?

Suppose:

Current = 5

Stack top = 3

3 <= 5

To 3 future mein 5 ka next greater nahi ho
sakta.

Isliye 3 ko remove kar sakte hain.

Agar:

Stack top = 8

8 > 5

to 8 current 5 ka greater element ho sakta hai.

Therefore 8 ko stack mein retain karenge.

-------------------------------------------------------

Circular Array Ko 2 Times Traverse Kyun?

Example:

nums = [1,2,1]

Agar sirf ek baar right-to-left traverse kiya,
to last 1 ke liye beginning ka 2 available nahi
hoga.

Isliye virtually:

[1,2,1,1,2,1]

consider karenge.

Lekin actual array duplicate nahi karenge.

Use:

idx = i % n

Example n = 3:

i:
5 4 3 2 1 0

idx = i % n:

2 1 0 2 1 0

Matlab circular order automatically simulate ho gaya.

-------------------------------------------------------

Approach

1. Result array banao:

   vector<int> res(n,-1);

   Initially sab answers -1 hain.

2. Empty stack banao:

   stack<int> st;

3. Array ko virtually 2 times right-to-left
   traverse karo:

   for(int i = 2*n-1; i >= 0; i--)

4. Circular index nikalo:

   int idx = i % n;

5. Stack se saare smaller/equal elements remove karo:

   while(!st.empty() &&
         st.top() <= nums[idx])

       st.pop();

6. Agar current iteration original array ke
   first traversal mein hai aur stack empty nahi hai:

   res[idx] = st.top();

7. Current element ko stack mein push karo:

   st.push(nums[idx]);

8. Finally res return karo.

-------------------------------------------------------

Important Point :— i < n

Hum 2*n iterations kar rahe hain.

Lekin result mein har original element ka answer
sirf ek baar store karna hai.

Isliye:

if(i < n && !st.empty())

    res[idx] = st.top();

First half mein hum actual answers calculate
kar rahe hain.

Second half mainly stack ko circular elements se
prepare karne ka kaam karta hai.

-------------------------------------------------------

Why Push Current Element?

Current element ko stack mein isliye push karte hain
taaki ye next elements ke liye greater-element
candidate ban sake.

Example:

[1,2]

1 process karne ke baad:

stack = [1]

Jab 2 process hoga:

1 <= 2

1 pop ho jayega.

2 future elements ke liye stack mein rahega.

-------------------------------------------------------

Why Stack Contains Useful Candidates?

Hum stack se un elements ko continuously remove kar
dete hain jo kisi future element ke liye useful nahi
ho sakte.

Isliye stack mein sirf relevant candidates bachte hain.

Ye property Monotonic Stack pattern ka core hai.

-------------------------------------------------------

Algorithm

1. n = nums.size()
2. res ko -1 se initialize karo.
3. Empty stack banao.
4. i = 2*n-1 se 0 tak traverse karo.
5. idx = i % n nikalo.
6. Stack ke saare elements <= nums[idx] pop karo.
7. Agar i < n aur stack empty nahi hai:
   
   res[idx] = st.top();

8. nums[idx] ko stack mein push karo.
9. res return karo.

-------------------------------------------------------



  
  class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>res(n,-1);
        st.push(nums[n-1]);

        for(int i= 2*n-2 ; i>=0 ; i--){
            int idx= i%n;
            while(!st.empty() && st.top()<=nums[idx]){
                st.pop();
            }

            if(i<n && !st.empty()){
                res[idx]= st.top();
            }
            st.push(nums[idx]);
        }
        return res;
    }
};




--------------------------------

Why This Works?

Har element ke liye stack ke top par woh nearest
greater candidate available hota hai jo current
element se bada hai.

Smaller/equal elements ko pop karne se irrelevant
candidates remove ho jate hain.

Array ko virtually 2 times traverse karne se
circular nature bhi handle ho jata hai.

Therefore:

Circular Array
      +
Monotonic Stack
      ↓
Next Greater Element

-------------------------------------------------------

Time Complexity

Hum total:

2n

iterations karte hain.

Har element maximum ek baar push aur maximum ek
baar pop hota hai.

Therefore:

Time:
O(n)

-------------------------------------------------------

Space Complexity

Stack mein maximum n elements ho sakte hain.

Result array bhi n elements ka hai.

Auxiliary Stack:
O(n)

Result:
O(n)

Overall:
O(n)

-------------------------------------------------------

Revision Trick

"Array ko virtually 2 times traverse karo →
i % n se circular index nikalo →
smaller/equal elements pop karo →
stack top = next greater →
current element push karo."

-------------------------------------------------------

Pattern Recognition

Agar question mein:

- Next Greater Element
- Next Smaller Element
- Previous Greater/Smaller
- Nearest greater/smaller
- First greater element

jaisi requirement ho, to Monotonic Stack ke baare
mein sochna chahiye.

Agar array circular bhi ho, to:

"2*n traversal + i % n"

ka idea yaad rakho.

-------------------------------------------------------

Problem-Solving Lesson

Is question mein do main observations hain:

1. Next Greater Element
   → Monotonic Stack

2. Circular Array
   → Array ko virtually 2 times traverse karo
     using i % n

Dono ideas combine karke problem solve hoti hai.

