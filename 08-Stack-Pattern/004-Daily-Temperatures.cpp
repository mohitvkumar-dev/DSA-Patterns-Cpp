
Problem    : Daily Temperatures
Platform   : LeetCode
Problem No.: 739
Pattern    : Monotonic Stack / Next Greater Element
Difficulty : Medium

Intuition :

Hume har day ke liye find karna hai ki future mein
kitne days baad temperature current temperature se
greater hoga.

Example:

temperatures = [73,74,75,71,69,72]

73 → 74  → 1 day
74 → 75  → 1 day
75 → no greater → 0
71 → 72  → 2 days
69 → 72  → 1 day
72 → no greater → 0

Answer:

[1,1,0,2,1,0]

Ye basically Next Greater Element problem hai.

Difference ye hai ki:

NGE:
→ next greater temperature ki value chahiye.

Daily Temperatures:
→ next greater temperature kitne days baad milega.

Isliye stack mein temperature ki value ke instead
INDEX store karna useful hai.

Agar current index i hai aur next greater temperature
index j par hai:

    days = j - i

-------------------------------------------------------

Why Monotonic Stack?

Brute Force mein har temperature ke liye uske right
side mein greater temperature search karenge.

Worst case mein:

    O(n²)

time lag sakta hai.

Lekin hume har element ko baar-baar check karne ki
zarurat nahi hai.

Stack mein sirf useful future temperatures ke indices
rakhenge.

Isliye Monotonic Stack use karenge.

-------------------------------------------------------

Approach

1. Result array ko initially 0 se initialize karo:

       vector<int> res(n, 0);

   Agar kisi temperature ke baad greater temperature
   nahi milta, answer 0 hi rahega.

2. Ek empty stack banao:

       stack<int> st;

   Stack mein temperature ki values nahi,
   unke INDICES store karenge.

3. Right se left traverse karo:

       for(int i = n-1; i >= 0; i--)

   Kyunki current temperature ke liye hume
   future temperatures ki information chahiye.

-------------------------------------------------------

Step 1 — Smaller / Equal Temperature Remove Karo

Condition:

       while(!st.empty() &&
             temperatures[st.top()] <= temperatures[i])

           st.pop();

Agar stack ke top par temperature current temperature
se chhota ya equal hai, to woh current temperature ka
greater temperature nahi ho sakta.

Isliye us index ko stack se remove kar denge.

Example:

Current:

    75

Stack top:

    74

74 <= 75

Therefore 74 current ka answer nahi ho sakta.

Pop.

-------------------------------------------------------

Step 2 — Next Greater Temperature Find Karo

Agar pop karne ke baad stack empty nahi hai:

       res[i] = st.top() - i;

Yahan:

    i         = current day ka index
    st.top()  = next greater temperature ka index

Therefore:

    days = next greater index - current index

Example:

    index:        2   3   4   5
    temperature: 75  71  69  72

For 69:

    current index = 4
    next greater index = 5

Therefore:

    res[4] = 5 - 4
           = 1

-------------------------------------------------------

Step 3 — Current Index Push Karo

Finally:

       st.push(i);

Current temperature ko stack mein push karenge.

Kyunki ye current temperature future mein left side
ke kisi temperature ka next greater ho sakta hai.


-------------------------------------------------------

Why Index Store Karna Zaroori Hai?

Agar stack mein sirf temperature values store karte:

    [74,75,72...]

to hume ye nahi pata chalta ki greater temperature
kitne index par mila.

Question mein hume value nahi, DAYS ka difference
chahiye.

Isliye:

    stack<int> st;

mein indices store karenge.

Then:

    st.top() - i

directly number of days de deta hai.

-------------------------------------------------------

Why Right to Left?

Current element ko apne RIGHT side ka next greater
element chahiye.

Isliye right side ki information pehle available
honi chahiye.

Example:

    [73,74,75]

75 ka koi future day nahi hai.

Phir 74 ke liye 75 available hai.

Phir 73 ke liye 74 available hai.

Therefore:

    Right → Left

-------------------------------------------------------
  

Algorithm

1. Result array ko 0 se initialize karo.
2. Empty stack banao.
3. Right se left traverse karo.
4. Jab tak stack empty nahi hai aur top temperature
   current se <= hai, pop karo.
5. Agar stack empty nahi hai:
       res[i] = st.top() - i
6. Current index ko stack mein push karo.
7. Result return karo.

-------------------------------------------------------

Time Complexity

Har index stack mein maximum ek baar push hota hai
aur maximum ek baar pop hota hai.

Therefore:

    Time = O(n)

-------------------------------------------------------

Space Complexity

Stack mein maximum n indices ho sakte hain:

    Space = O(n)

Result array bhi O(n) hai.

-------------------------------------------------------


Pattern Recognition

Agar question mein aaye:

    "next greater element"
    "next warmer day"
    "future mein greater value"
    "kitne steps/days baad greater milega"

to Monotonic Stack ke baare mein socho.

-------------------------------------------------------


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int>st;
        vector<int> res(n,0);
        st.push(n-1);
        for(int i= n-1; i>=0 ; i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }

            if(!st.empty()){
               res[i]= st.top()-i;
            }

            st.push(i);
        }
        return res;

        
    }
};
