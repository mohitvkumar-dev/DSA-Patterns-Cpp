
Problem    : Remove All Adjacent Duplicates In String
Platform   : LeetCode
Problem No.: 1047
Pattern    : Stack
Difficulty : Easy

Intuition :

Hume string se repeatedly adjacent duplicate characters
remove karne hain.

Example:

abbaca

Step 1:
abbaca
 ↑↑
 bb duplicate → remove

Remaining:
aaca

Step 2:
aaca
 ↑↑
 aa duplicate → remove

Remaining:
ca

Answer:
ca

-------------------------------------------------------

Main Observation

String ko left-to-right traverse karenge.

Current character ko previous remaining character ke saath
compare karna hai.

Lekin removal ke baad naye adjacent duplicates ban sakte hain.

Example:

abbaca

bb remove hone ke baad:

aaca

Ab naye "aa" duplicate ban gaye.

Isliye hume previous remaining characters ko efficiently
track karna hoga.

Yahan Stack perfect fit hai.

Stack mein woh characters rahenge jo abhi tak final string
ka part ho sakte hain.

-------------------------------------------------------

Approach

1. Ek stack banao.

2. String ko left-to-right traverse karo.

3. Har current character ke liye stack ke top se compare karo.

4. Agar stack empty hai:

   current character ko push karo.

5. Agar:

   stack.top() == current character

   to dono adjacent duplicate hain.

   Isliye stack se top ko pop karo aur current character
   ko push mat karo.

6. Agar top aur current character different hain:

   current character ko stack mein push karo.

7. Traversal complete hone ke baad stack mein final
   remaining characters honge.

8. Stack LIFO hota hai, isliye pop karne par characters
   reverse order mein milenge.

   Isliye result ko reverse karna padega.

-------------------------------------------------------

Why Stack?

Hume hamesha current character ko immediately previous
remaining character ke saath compare karna hai.

Stack ka top exactly wahi character represent karta hai.

Example:

String:
abbaca

Process:

'a'

Stack:
[a]

'b'

Stack:
[a,b]

'b'

Top = b
Current = b

Duplicate → pop

Stack:
[a]

'a'

Top = a
Current = a

Duplicate → pop

Stack:
[]

'c'

Stack:
[c]

'a'

Stack:
[c,a]

Final:
ca

-------------------------------------------------------

  
Important Point

Jab duplicate milta hai:

stack.pop();

Current character ko push nahi karte.

Kyunki duplicate pair ke dono characters remove ho rahe hain.

------------------------------------------------------

  
Algorithm

1. Stack banao.

2. String ko left-to-right traverse karo.

3. Agar stack empty hai:
   
   push(current)

4. Else agar:
   
   stack.top() == current

   → pop()

5. Otherwise:
   
   push(current)

6. Stack ke characters ko result mein pop karke add karo.

7. Result ko reverse karo.

8. Result return karo.

-------------------------------------------------------

Time Complexity

Har character maximum ek baar push aur ek baar pop
hota hai.

Therefore:

Time:
O(n)

-------------------------------------------------------

Space Complexity

Worst case mein koi duplicate remove nahi hoga.

Example:

abcdef

Stack mein saare n characters aa jayenge.

Therefore:

Space:
O(n)

-------------------------------------------------------

  
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string res;
        int n= s.size();

        for(int i=0 ; i<n; i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }

            if(st.top()==s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        
            while(!st.empty()){
                res.push_back(st.top());
                st.pop();

            }

            reverse(res.begin(),res.end());
        
        return res;
    }
};




-------------------------------------------------------

Pattern Recognition

Agar question mein:

- Adjacent duplicates remove karne hain
- Removal ke baad naye adjacent duplicates ban sakte hain
- Previous remaining character ke saath repeatedly
  comparison karna hai

to Stack pattern ke baare mein sochna chahiye.

-------------------------------------------------------

Problem-Solving Lesson

Is question mein main trick "duplicate remove karna"
nahi hai.

Main observation ye hai:

"Removal ke baad naye duplicates ban sakte hain."

Isliye normal string manipulation se repeatedly
remove karne ke bajay Stack use karna efficient hai.

Stack ka top = previous remaining character.

