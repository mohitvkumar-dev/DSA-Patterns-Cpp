
Problem    : Valid Parentheses
Platform   : LeetCode
Problem No.: 20
Pattern    : Stack
Difficulty : Easy

Intuition :

Hume brackets ki string di gayi hai aur check karna hai
ki woh valid parentheses sequence hai ya nahi.

Valid hone ke liye:

1. Har opening bracket ka corresponding closing bracket
   hona chahiye.

2. Closing bracket correct order mein aana chahiye.

Example:

({[]})

Opening order:

(
{
[

Closing order:

]
}
)

Matlab jo opening bracket sabse last mein aaya,
use sabse pehle close hona chahiye.

Ye exactly Stack ki LIFO property hai:

Last In → First Out

Isliye Stack use karenge.

-------------------------------------------------------

Main Observation

Jab bhi opening bracket mile:

(
{
[

use Stack mein push kar denge.

Jab closing bracket mile:

)
}
]

toh usse Stack ke top opening bracket ke saath match
karna hoga.

Example:

({[]})

Stack:

(
( {
( { [

Ab ']' aaya.

Top = '['

'[' ka correct closing = ']'

Match → pop

Stack:

( {

Ab '}' aaya.

Top = '{'

Match → pop

Stack:

(

Ab ')' aaya.

Top = '('

Match → pop

Stack:

empty

String valid hai.

-------------------------------------------------------

Approach

1. Ek Stack banao.

2. String ko left-to-right traverse karo.

3. Agar current character opening bracket hai:

   '(' , '{' , '['

   to Stack mein push karo.

4. Agar current character closing bracket hai:

   ')' , '}' , ']'

   to sabse pehle check karo ki Stack empty hai ya nahi.

5. Agar Stack empty hai:

   Closing bracket ke liye koi opening bracket available
   nahi hai.

   Example:

   )

   Isliye:

   return false;

6. Agar Stack empty nahi hai, to Stack ke top ko current
   closing bracket ke corresponding opening bracket se
   compare karo.

   ')' → '('
   '}' → '{'
   ']' → '['

7. Agar matching nahi hai:

   Example:

   (]

   Top = '('
   Current = ']'

   Match nahi hua.

   return false;

8. Agar matching hai:

   Opening bracket ka pair complete ho gaya.

   Isliye:

   stack.pop();

9. Loop complete hone ke baad Stack check karo.

10. Agar Stack empty hai:

    Sabhi opening brackets properly close ho gaye.

    return true;

11. Agar Stack empty nahi hai:

    Kuch opening brackets unmatched reh gaye.

    Example:

    (((

    return false;

-------------------------------------------------------

Why Stack?

Important question:

"Closing bracket ko kis opening bracket ke saath match
karna hai?"

Answer:

Sabse recent unmatched opening bracket ke saath.

Example:

({[]})

Opening brackets:

(
{
[

Ab ')' nahi aa sakta.

Pehle '[' close hoga,
phir '{',
phir '('.

Ye:

Last In → First Out

hai.

Isi reason ki wajah se Stack natural data structure hai.

-------------------------------------------------------

Case 1 — Opening Bracket

Agar:

current == '(' || current == '{' || current == '['

to:

stack.push(current);

Kyunki iska closing bracket future mein aayega.

-------------------------------------------------------

Case 2 — Closing Bracket

Example:

current = ']'

Sabse pehle:

if(stack.empty())

to false.

Kyunki matching opening bracket available hi nahi hai.

Agar stack empty nahi hai:

stack.top() ko check karenge.

Agar:

stack.top() == '['

to:

stack.pop();

Otherwise:

return false;

-------------------------------------------------------

Important Edge Cases

Case 1:

String:

")"

Stack empty hai aur closing bracket aa gaya.

→ false

-------------------------------------------------------

Case 2:

String:

"((("

Loop complete hone ke baad:

Stack = (( (

Stack empty nahi hai.

→ false

-------------------------------------------------------

Case 3:

String:

"(]"

Top = '('

Current = ']'

Mismatch.

→ false

-------------------------------------------------------

Case 4:

String:

"()[]{}"

Har pair correctly match hota hai.

End mein:

Stack = empty

→ true

-------------------------------------------------------

Why Final Stack Check is Necessary?

Sirf loop ke andar mismatches check karna enough nahi hai.

Example:

"((("

Isme koi closing bracket aaya hi nahi.

Isliye loop ke andar koi mismatch nahi mila.

Lekin brackets valid bhi nahi hain.

Loop ke baad:

Stack != empty

Matlab unmatched opening brackets remaining hain.

Therefore:

return stack.empty();

-------------------------------------------------------

Algorithm

1. Stack banao.
2. String ko left-to-right traverse karo.
3. Opening bracket → push.
4. Closing bracket:
   - Stack empty → false.
   - Top matching nahi → false.
   - Match → pop.
5. Loop ke baad:
   - Stack empty → true.
   - Otherwise → false.

-------------------------------------------------------

Time Complexity

Har character ko maximum ek baar push aur ek baar pop
kiya ja sakta hai.

Therefore:

Time:
O(n)

-------------------------------------------------------

Space Complexity

Worst case mein saare characters opening brackets ho
sakte hain.

Example:

"((((((("

Therefore:

Space:
O(n)

-------------------------------------------------------

Pattern Recognition

Agar question mein:

- Brackets / parentheses hain
- Opening aur closing ka matching hai
- Latest unmatched opening bracket ko pehle close
  karna hai
- Nested structure hai

to Stack pattern ke baare mein sochna chahiye.

-------------------------------------------------------

Problem-Solving Lesson

Is question mein Stack ka use sirf brackets store karne
ke liye nahi hai.

Stack hume automatically ye guarantee deta hai ki:

"Latest unmatched opening bracket ko hi pehle check
kiya jayega."

Yahi LIFO property is problem ki core observation hai.

-------------------------------------------------------


  class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='('|| s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                continue;
            }

            // closing

            if(st.empty()){
                return false;
            }

            else if(s[i]==')' && st.top()=='('){
                st.pop();
            }

            else if(s[i]=='}' && st.top()=='{'){
                st.pop();
            }

            else if(s[i]==']' && st.top()=='['){
                st.pop();
            }else{
                return false;
            }
        }
        if(!st.empty()){
            return false;
        }

        return true;
    }
};
