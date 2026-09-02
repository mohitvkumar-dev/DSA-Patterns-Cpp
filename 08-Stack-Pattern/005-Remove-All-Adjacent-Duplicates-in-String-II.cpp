
Problem    : Remove All Adjacent Duplicates in String II
Platform   : LeetCode
Problem No.: 1209
Pattern    : Stack / Character Frequency
Difficulty : Medium

Intuition :

Ye LeetCode 1047 — Remove All Adjacent Duplicates
in String ka extended version hai.

1047 mein k = 2 fixed tha.

Matlab:

    aa → remove
    bb → remove

Lekin 1209 mein k given hai.

Isliye hume sirf character store karna enough nahi hai.
Hume ye bhi pata hona chahiye ki current character
kitni consecutive baar aa chuka hai.

Therefore stack mein:

    {character, count}

ka pair store karenge.

Example:

    k = 3

    aaa

To stack mein:

    (a,1)
    (a,2)

Aur third 'a' aate hi:

    (a,3)

complete ho jayega aur poora group remove kar denge.

-------------------------------------------------------

Approach

1. Ek stack banao jisme pair store hoga:

       stack<pair<char,int>> st;

   Yahan:

       first  → character
       second → us character ka consecutive count

2. String ko left-to-right traverse karo.

3. Har character ch = s[i] ke liye teen cases
   handle karenge.

-------------------------------------------------------

Case 1 — Stack Empty

Agar:

       st.empty()

hai, to current character ek naya group start karega.

Isliye:

       st.push({ch,1});

Example:

    s = "a"

    stack:
    (a,1)

-------------------------------------------------------

Case 2 — Top Character Different

Agar:

       st.top().first != ch

to current character previous group ka part nahi hai.

Ye ek naya consecutive group start karega.

Therefore:

       st.push({ch,1});

Example:

    stack:
    (a,2)

    current = b

    stack:
    (a,2)
    (b,1)

-------------------------------------------------------

Case 3 — Top Character Same

Agar:

       st.top().first == ch

to current character same consecutive group ka part hai.

Ab us group ka count check karenge.

-------------------------------------------------------

Case 3A — Count k se Chhota Hai

Agar:

       st.top().second < k-1

to current character add karne ke baad bhi
k occurrences complete nahi hongi.

Isliye top pair ko update karenge:

       int count = st.top().second;
       st.pop();
       st.push({ch,count+1});

Example:

    k = 3

    stack:
    (a,1)

    current = a

    count = 1 < 2

    update:

    (a,2)

-------------------------------------------------------

Case 3B — Count k-1 Hai

Agar:

       st.top().second == k-1

to current character add karne par total k
consecutive characters complete ho jayenge.

Example:

    k = 3

    stack:
    (a,2)

    current = a

    total = 3

Ab poora group remove karna hai:

       st.pop();

Current character ko push nahi karenge, kyunki
current character bhi remove hone wale group ka
part hai.

Example:

    (a,2) + a

    aaa → remove

    stack:
    empty

-------------------------------------------------------

Important Point

Count ko update karte waqt:

    current character ko alag se push nahi karna hai.

Agar same character milta hai, to existing pair ka
count increase hoga.

Aur jab count k ho jaye:

    poora pair pop hoga.

-------------------------------------------------------

Why Stack Works?

Stack mein adjacent character groups maintain hote hain.

Suppose:

    s = "deeed"

    k = 3

Process:

    d → (d,1)

    e → (e,1)

    e → (e,2)

    e → k complete
         (e,2) pop

Ab stack mein:

    (d,1)

Current ke baad:

    d → (d,2)

Final:

    dd

Isse ye bhi handle ho jata hai ki kisi group ko remove
karne ke baad naye adjacent duplicates ban sakte hain.

-------------------------------------------------------

Example

s = "deeedbbcccbdaa"
k = 3

Important part:

    eee → remove
    bbb → remove
    ccc → remove

Agar removal ke baad same characters adjacent
ban jaate hain, stack automatically unke groups
ko combine/update karta hai.

-------------------------------------------------------

Result Construction

String process hone ke baad stack mein remaining
characters aur unke counts stored honge.

Ab stack se pairs nikalenge:

       while(!st.empty())

Har pair ke character ko uske count ke according
result mein add karenge.

Example:

    stack:

    (a,2)
    (b,1)

Stack LIFO hota hai.

Pop order:

    b
    a

Lekin original string order:

    aa
    b

tha.

Isliye result reverse order mein banega.

Therefore end mein:

       reverse(res.begin(), res.end());

karke original order restore karenge.

-------------------------------------------------------

Algorithm

1. Empty stack banao.
2. String ko left-to-right traverse karo.
3. Agar stack empty hai:
       (ch,1) push karo.
4. Agar top character current se different hai:
       (ch,1) push karo.
5. Agar top character same hai:
       count check karo.
6. Agar count < k-1:
       count increase karo.
7. Agar count == k-1:
       pair ko pop karo.
8. String traversal complete hone ke baad stack
   se remaining characters construct karo.
9. Result ko reverse karo.
10. Result return karo.

-------------------------------------------------------

Time Complexity

Har character stack mein maximum ek baar push aur
maximum ek baar pop hota hai.

Therefore:

    Time = O(n)

Result construction bhi O(n) hai.

Overall:

    O(n)

-------------------------------------------------------

Space Complexity

Stack mein maximum n characters ke groups ho sakte hain.

Therefore:

    Space = O(n)

Result ke liye bhi O(n) space use hota hai.

-------------------------------------------------------

Revision Trick

"Character + count stack mein rakho →
same character aaye to count badhao →
count k hote hi poora group pop karo →
end mein stack se result banao aur reverse karo."

-------------------------------------------------------

Pattern Connection

LC 1047:
    Stack of characters
    k = 2 fixed

LC 1209:
    Stack of {character, count}
    k variable

Main upgrade:

    Duplicate removal + frequency tracking

-------------------------------------------------------



class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>>st;

        for(int i=0 ; i<n ; i++){
            char ch =s[i];
            if(st.empty()){
              st.push({ch,1});
              continue;
            }
            if(st.top().first!=ch){
                st.push({ch,1});
                continue;
            }

            if(st.top().second < k-1){
                pair<char,int>p= st.top();
                st.pop();
                st.push({p.first, p.second+1});
                continue;
            }

            st.pop();
        }

        string res="";
        while(!st.empty()){
             pair<char,int>p= st.top();
             st.pop();

             while(p.second--){
                res.push_back(p.first);
             }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
