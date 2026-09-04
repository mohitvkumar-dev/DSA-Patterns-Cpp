
Problem    : Simplify Path
Platform   : LeetCode
Problem No.: 71
Pattern    : Stack
Difficulty : Medium

Question :

Hume ek Unix-style path diya gaya hai aur hume uska
canonical/simplified path return karna hai.

Path mein:

    "/"   → directories ko separate karta hai
    "."   → current directory, ignore karna hai
    ".."  → parent directory mein jaana hai
    "//"  → extra slash, ignore karna hai

Example:

    /a/./b/../../c/

Simplify karne ke baad:

    /c

-------------------------------------------------------

Intuition :

Path ko LEFT → RIGHT traverse karenge aur "/" ke
beech ke complete directory components ko ek-ek karke
process karenge.

Main problem ".." ko handle karna hai.

Example:

    /a/b/c/..

Yahan ".." ka matlab hai parent directory mein jaana.

Matlab:

    c ko remove karna hai.

Agar stack mein:

    [a,b,c]

hai, to:

    ".." → c ko pop karo

Result:

    [a,b]

Isliye STACK use karenge.

Stack ki LIFO property:

    Last In → First Out

last added directory ko remove karne ke liye
exactly suitable hai.

-------------------------------------------------------

Approach :

1. Ek stack aur result string banao:

       stack<string> st;
       string res;

   Stack mein valid directory names store karenge.

-------------------------------------------------------

2. Path ko LEFT → RIGHT traverse karo:

       for(int i = 0; i < path.size(); i++)

   Har iteration mein path ke current character ko
   check karenge.

-------------------------------------------------------

3. Agar current character "/" hai:

       if(path[i] == '/')
           continue;

   "/" sirf directories ko separate karta hai.

   Isliye isko stack mein store nahi karna hai.

   Multiple "/" bhi automatically ignore ho jayenge.

   Example:

       /a//b///

   Extra "/" ko ignore karne ke baad:

       a
       b

   components milenge.

-------------------------------------------------------

4. Complete directory/component find karo:

       string temp;

       while(i < path.size() && path[i] != '/')
       {
           temp = temp + path[i];
           ++i;
       }

   Yahan "/" ke beech ke saare characters ko
   temp mein collect karenge.

Example:

    path = /home/user/

    "home" → temp = "home"

    "user" → temp = "user"

Important:

    while loop ke andar i++ hone ki wajah se
    ek complete component milne ke baad i "/" par
    aa jata hai.

-------------------------------------------------------

5. Ab temp ke according 3 main cases handle karenge.

-------------------------------------------------------

Case 1 — "." :

       if(temp == ".")
       {
           continue;
       }

"." ka meaning current directory hai.

Isliye current position par hi rehna hai.

Koi change nahi karna.

Example:

    /a/./b

Process:

    a → push
    . → ignore
    b → push

Stack:

    [a,b]

-------------------------------------------------------

Case 2 — ".." :

       else if(temp == "..")
       {
           if(!st.empty())
           {
               st.pop();
           }
       }

".. " ka meaning parent directory mein jaana hai.

Isliye last valid directory ko remove karenge.

Example:

    /a/b/c/..

Stack:

    [a,b,c]

"..":

    pop()

Stack:

    [a,b]

Agar stack empty hai:

    /../a

to root se upar nahi ja sakte.

Isliye:

    if(!st.empty())

lagaya hai.

-------------------------------------------------------

Case 3 — Normal Directory :

Agar temp "." ya ".." nahi hai, to ye normal
directory hai.

Example:

    home
    user
    documents

Isliye:

       st.push(temp);

kar denge.

Example:

    /home/user

Process:

    home → push
    user → push

Stack:

    [home,user]

-------------------------------------------------------

Complete Component Processing :

Har component ke liye:

    Normal directory → push
    "."              → ignore
    ".."             → pop
    "/"              → separator, ignore

-------------------------------------------------------

Result Construction :

Ab stack mein simplified directories correct order
mein stored hain.

Example:

    stack = [a,b,c]

Lekin stack LIFO follow karta hai.

Agar hum simply pop karein:

    c
    b
    a

order reverse ho jayega.

Isliye tumhare code mein:

       res = "/" + st.top() + res;

use kiya gaya hai.

Current top ko result ke FRONT mein add karte hain.

-------------------------------------------------------

Example:

Stack:

    [a,b,c]

First pop:

    top = c

    res = "/c" + ""

         = "/c"

-------------------------------------------------------

Second pop:

    top = b

    res = "/b" + "/c"

         = "/b/c"

-------------------------------------------------------

Third pop:

    top = a

    res = "/a" + "/b/c"

         = "/a/b/c"

-------------------------------------------------------

Final:

    res = "/a/b/c"

Isliye reverse() ki zarurat nahi padti.

Tumhare code mein directly:

    "/" + st.top() + res

use karke correct order maintain ho raha hai.

-------------------------------------------------------

Why Add at Front?

Stack se elements reverse order mein milte hain.

Example:

    Original:
    a → b → c

Stack pop:

    c → b → a

Agar end mein add karte:

    /c/b/a

wrong answer aata.

Isliye har popped directory ko result ke
FRONT mein add karte hain:

    c → /c
    b → /b/c
    a → /a/b/c

-------------------------------------------------------

Empty Result Case :

Agar stack mein kuch bhi nahi bacha:

    res = ""

to canonical path root directory hoga:

    /

Isliye:

       if(res.size() == 0)
           return "/";

Example:

    /a/..

Process:

    a → push
    .. → pop

Stack:

    []

Result:

    ""

Therefore answer:

    "/"

-------------------------------------------------------

Why Stack?

Is problem ka main operation hai:

    ".." → last valid directory remove karo

Aur last added directory ko remove karne ke
liye stack ka:

    LIFO

behavior perfect hai.

Example:

    /a/b/c/..

Last added:

    c

Stack:

    [a,b,c]

pop():

    [a,b]

Therefore ".." naturally handle ho jata hai.



-------------------------------------------------------

Algorithm :

1. Empty stack `st` aur result string `res` banao.
2. Path ko left-to-right traverse karo.
3. "/" mile to ignore karo.
4. "/" ke beech ka complete component `temp` mein
   collect karo.
5. Agar `temp == "."` hai → ignore karo.
6. Agar `temp == ".."` hai → stack empty nahi hai
   to top ko pop karo.
7. Otherwise normal directory ko stack mein push karo.
8. Stack ke saare elements ko pop karo aur:

       res = "/" + st.top() + res;

   se result ke front mein add karo.
9. Agar `res` empty hai → "/" return karo.
10. Otherwise `res` return karo.

-------------------------------------------------------

Time Complexity :

Path ki length = n

Har character ko maximum ek baar process karte hain.

Stack operations:

    push → O(1)
    pop  → O(1)

Result construction mein bhi har component ek baar
process hota hai.

Therefore:

    Time Complexity = O(n)

-------------------------------------------------------

Space Complexity :

Worst case mein path ke saare directory components
stack mein store ho sakte hain.

Therefore:

    Space Complexity = O(n)

Result string bhi O(n) space le sakti hai.

-------------------------------------------------------

Revision Trick :

"Slash ignore karo → complete component banao →

normal directory push →

'.' ignore →

'..' par last directory pop →

stack ko front se result mein add karo →

empty ho to '/' return karo."

-----------------------------------------------------


class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string res;
        for(int i=0 ; i<path.size(); i++){
            if(path[i]=='/'){
                continue;
            }

            string temp;
            while(i<path.size() && path[i] !='/'){
                 temp= temp+path[i];
                 ++i;
            }
            if(temp=="."){
                continue;
            }else if(temp==".."){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(temp);
            }
        }

        while(!st.empty()){
            res ="/" + st.top()+res;
            st.pop();
        }

        if(res.size()==0){
            return "/";
        }

        return res;
    }
};
