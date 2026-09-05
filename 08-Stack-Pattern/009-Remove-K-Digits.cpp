
Problem    : Remove K Digits
Platform   : LeetCode
Problem No.: 402
Pattern    : Monotonic Stack
Difficulty : Medium

Intuition :

Hume k digits remove karke smallest possible number
banana hai.

Number ko LEFT → RIGHT process karenge.

Agar current digit se pehle stack ke top par koi
BADI digit hai, to us badi digit ko remove karna
number ko smaller banayega.

Example:

    1432219

Agar:

    stack.top() = 4
    current     = 3

to:

    4 > 3

Isliye 4 ko remove karna better hai.

Stack:

    [1,4]

Current = 3

4 pop:

    [1]

Phir 3 push:

    [1,3]

-------------------------------------------------------

Main Idea :

Har current digit ke liye check karenge:

    stack.top() > current
    and
    k > 0

Agar dono true hain, to stack ka top remove
kar denge.

Matlab:

    while(!st.empty() &&
          st.top() > curr &&
          k > 0)

        st.pop();
        k--;

Ek current digit multiple previous larger digits
ko remove kar sakti hai.

Example:

    98765

Jab 5 aayega:

    9 > 5 → remove
    8 > 5 → remove
    7 > 5 → remove
    6 > 5 → remove

Isliye WHILE loop use karenge.

-------------------------------------------------------

Why Stack?

Hume last added digit ko remove karna hota hai.

Stack:

    LIFO
    Last In First Out

follow karta hai.

Isliye previous digits mein se latest digit ko
remove karna efficiently possible hai.

Ye problem basically:

    Monotonic Increasing Stack

ka use karti hai.

-------------------------------------------------------

Approach :

1. Ek stack<char> banao:

       stack<char> st;

2. Number ki digits ko LEFT → RIGHT traverse karo.

3. Har iteration mein current digit:

       curr = num[i]

   lo.

4. Jab tak:

       !st.empty()
       k > 0
       st.top() > curr

   hai, tab tak:

       st.pop();
       k--;

5. While loop ke baad current digit ko push karo:

       st.push(curr);

6. Pura number traverse hone ke baad agar:

       k > 0

   hai, to iska matlab abhi bhi digits remove
   karni baaki hain.

   Is case mein stack ke TOP se k digits remove
   karenge.

7. Stack se digits ko result string `res` mein
   convert karo.

8. Stack LIFO hone ke karan result reverse order
   mein milega, isliye:

       reverse(res.begin(), res.end());

9. Result ke starting ke leading zeros remove karo.

10. Agar leading zeros remove karne ke baad
    result empty hai, to:

       return "0";

-------------------------------------------------------

Why Remaining k Digits Top Se Remove?

Example:

    num = 12345
    k = 2

Number increasing order mein hai.

Kisi point par:

    stack.top() > curr

condition true nahi hogi.

Isliye traversal ke baad:

    stack = [1,2,3,4,5]
    k = 2

Ab smallest number banane ke liye largest digits
remove karna better hai:

    5 remove
    4 remove

Remaining:

    123

Therefore:

    answer = 123

-------------------------------------------------------

Leading Zero Case :

Example:

    num = 10200
    k = 1

Current:

    1 → push
    0 → 1 > 0 → 1 remove

Stack:

    [0]

Remaining digits:

    0,2,0,0

Result:

    0200

Leading zero remove karne ke baad:

    200

Answer:

    "200"

-------------------------------------------------------

All Zero Case :

Example:

    num = 000
    k = 2

Digits remove hone ke baad result empty ya
only zeros ho sakta hai.

Leading zeros remove karne ke baad:

    ""

Isliye:

    return "0";

-------------------------------------------------------

Important Observation :

Is question mein sirf:

    "k digits remove karo"

sochna enough nahi hai.

Hume ye decide karna hai:

    "Kaunsi k digits remove karni hain?"

Smallest number banane ke liye:

    left side ki badi digit ko remove karna
    zyada beneficial hota hai.

Therefore:

    st.top() > curr

hone par top ko remove karenge.

-------------------------------------------------------

Algorithm :

1. Empty monotonic stack banao.
2. Number ko left → right traverse karo.
3. Current digit nikalo.
4. Jab tak top > current aur k > 0:
       top pop karo
       k--
5. Current digit push karo.
6. Agar traversal ke baad k > 0:
       stack ke top se k digits remove karo.
7. Stack ko result string mein convert karo.
8. Result reverse karo.
9. Leading zeros remove karo.
10. Agar result empty hai → "0".
11. Otherwise result return karo.

-------------------------------------------------------

Time Complexity :

Har digit maximum ek baar push hoti hai
aur maximum ek baar pop hoti hai.

Therefore:

    Time = O(n)

-------------------------------------------------------

Space Complexity :

Stack mein maximum n digits store ho sakti hain.

Therefore:

    Space = O(n)

-------------------------------------------------------

Revision Trick :

"Left → Right traverse karo →

previous badi digit ko current chhoti digit
aane par pop karo →

k-- →

current push karo →

k bach jaye to top se remove karo →

reverse karo →

leading zeros hatao."

-------------------------------------------------------



class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0 ; i<num.size(); i++){
            char curr= num[i];

            while(!st.empty()&& st.top()>curr&& k>0){
                st.pop();
                k--;
            }

            st.push(curr);

        }

         while(!st.empty() && k>0){
                st.pop();
                k--;
            }

            string res="";

            while(!st.empty()){
                res+=st.top();
                st.pop();
            }
            reverse(res.begin(), res.end());

            //removing leading zero

           int i=0 ; 
           while(i<res.size() && res[i]=='0'){
            i++;
           }

           res = res.substr(i);

           if(res.empty()){
            return "0";
           }
        return res;
    }
};
