
Problem    : Remove Nodes From Linked List
Platform   : LeetCode
Problem No.: 2487
Pattern    : Monotonic Stack + Linked List
Difficulty : Medium

Intuition :

Hame linked list se un nodes ko remove karna hai jinke
RIGHT side mein koi greater value wala node present hai.

Example:

    5 → 2 → 13 → 3 → 8

2 ke right mein 13 hai:

    2 < 13

Therefore 2 remove hoga.

5 ke right mein bhi 13 hai:

    5 < 13

Therefore 5 bhi remove hoga.

Final:

    13 → 8

-------------------------------------------------------

Main Idea

Linked list ko LEFT → RIGHT traverse karenge.

Stack mein un nodes ki values store karenge jo abhi
tak remove nahi hui hain.

Jab current node ki value stack ke top se greater
hogi:

    curr->val > st.top()

to stack ka top wala node remove karna padega.

Kyunki current node uske RIGHT side mein hai aur
greater hai.

Ek current node multiple previous smaller nodes ko
remove kar sakta hai.

Example:

    3 → 2 → 1 → 5

5 aate hi:

    1 < 5 → remove
    2 < 5 → remove
    3 < 5 → remove

Isliye yahan WHILE loop use karenge.

-------------------------------------------------------

Approach

1. Ek stack banao:

       stack<int> st;

   Stack mein node ki values store karenge.

2. Linked list ko curr pointer se LEFT → RIGHT
   traverse karo.

3. Agar stack empty hai:

       st.push(curr->val);

4. Otherwise check karo:

       while(!st.empty() &&
             st.top() < curr->val)

   Jab tak stack ka top current value se smaller hai,
   top ko pop karte raho.

5. Current value ko stack mein push karo:

       st.push(curr->val);

6. Puri linked list traverse hone ke baad stack mein
   wahi values bachengi jinke RIGHT side mein koi
   greater value nahi hai.

-------------------------------------------------------

Why While Loop?

Sirf ek previous node remove karna enough nahi hai.

Example:

    1 → 2 → 3 → 4

Jab 4 aayega:

    3 < 4 → remove
    2 < 4 → remove
    1 < 4 → remove

Ek current element multiple previous smaller
elements ko remove kar sakta hai.

Therefore:

       while()

use karenge, sirf if nahi.


-------------------------------------------------------

Result Construction

Puri linked list traverse karne ke baad stack mein
required values bachengi.

Lekin stack LIFO follow karta hai.

Example:

    stack = [13,8]

Top se values nikalne par:

    8
    13

milengi.

Ye reverse order hai.

Isliye pehle vector mein values store karenge:

       vector<int> res;

       while(!st.empty())
       {
           res.push_back(st.top());
           st.pop();
       }

Ab:

    res = [8,13]

Isko reverse karenge:

       reverse(res.begin(), res.end());

Now:

    res = [13,8]

-------------------------------------------------------

Linked List Dobara Banana

Ab res vector mein final values correct order mein hain.

Ek new linked list create karenge.

Example:

    res = [13,8]

To:

    13 → 8

banayenge.

Finally:

       return head;

-------------------------------------------------------

Important Observation

Stack mein hum actual linked-list nodes nahi,
sirf VALUES store kar rahe hain.

Therefore final answer ke liye new linked list
create karni padegi.

Process:

    Linked List
         ↓
    Stack of values
         ↓
    Vector
         ↓
    Reverse
         ↓
    New Linked List

-------------------------------------------------------

Why This Works?

Stack mein sirf wahi elements survive karte hain
jo current right-side greater element se remove
nahi hue.

Agar koi current value previous smaller values ko
remove karti hai, to un values ko stack se pop kar
dete hain.

Isliye end mein stack mein exactly wahi values
bachti hain jinke right side mein koi greater value
nahi hai.

-------------------------------------------------------

Algorithm

1. Empty stack banao.
2. curr = head se linked list traverse karo.
3. Jab tak stack empty nahi hai aur:

       st.top() < curr->val

   tab tak pop karo.
4. Current value ko stack mein push karo.
5. Linked list traversal complete karo.
6. Stack se values vector mein nikalo.
7. Vector ko reverse karo.
8. Vector ki values se new linked list banao.
9. New head return karo.

-------------------------------------------------------

Time Complexity

Linked list ka har element stack mein maximum
ek baar push aur maximum ek baar pop hota hai.

Therefore:

    Time = O(n)

Vector se linked list banana bhi:

    O(n)

Overall:

    O(n)

-------------------------------------------------------

Space Complexity

Stack:

    O(n)

Vector:

    O(n)

New linked list:

    O(n)

Therefore:

    Space = O(n)

-------------------------------------------------------

Revision Trick

"Left → Right traverse karo → current bada ho to
previous smaller elements pop karo → current push
karo → stack se vector banao → reverse karo →
new linked list return karo."

-------------------------------------------------------

Pattern Connection

Ye bhi Next Greater Element pattern ka linked-list
version hai.

Normal NGE:

    current ke RIGHT mein greater element find karo.

LC 2487:

    jinke RIGHT mein greater element hai,
    un nodes ko remove karo.

Main pattern:

    Monotonic Stack

-------------------------------------------------------


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<int>st;
        vector<int>res;
        ListNode* curr= head;

        for(ListNode* curr = head ; curr != NULL ; curr = curr->next){
            if(st.empty()){
               st.push(curr->val);
               continue; 
            }

            while(!st.empty()&& st.top()<curr->val){
                st.pop();
                continue;
            }

            st.push(curr->val);
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();

        }

        reverse(res.begin(), res.end());
   

        // vector ko linkedlist  me convert krna

         ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int i = 0;

        while(i < res.size()) {
            temp->next = new ListNode(res[i]);
            temp = temp->next;
            i++;
        }

        return dummy->next;
    }
};
