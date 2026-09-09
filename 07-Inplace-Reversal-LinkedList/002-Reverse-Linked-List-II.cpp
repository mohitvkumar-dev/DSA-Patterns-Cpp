
Problem    : Reverse Linked List II
Platform   : LeetCode
Problem No.: 92
Pattern    : In-Place Reversal of Linked List
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hume given linked list mein sirf `left` se `right`
position tak ke nodes ko reverse karna hai.

Puri linked list ko reverse nahi karna hai.

Example:

    1 -> 2 -> 3 -> 4 -> 5

    left = 2
    right = 4

Reversed portion:

    2 -> 3 -> 4

becomes:

    4 -> 3 -> 2

Final list:

    1 -> 4 -> 3 -> 2 -> 5


-------------------------------------------------------
Intuition
-------------------------------------------------------

Hume puri linked list ko reverse nahi karna hai,
sirf `left` se `right` tak ke portion ko reverse
karna hai.

Isliye pehle `t` pointer se `left` position tak
jayenge aur `before` pointer mein left se just
pehle wale node ko store kar lenge.

Ab `left` se `right` tak ke nodes ko normal
linked list reversal ki tarah reverse karenge.

Reversal ke baad reversed portion ko linked list
ke dono sides se properly connect karna hoga.


-------------------------------------------------------
Approach
-------------------------------------------------------

Step 1:
`t` ko `head` par aur `before` ko `NULL` par
initialize karenge.

    t = head
    before = NULL


Step 2:
`t` ko traverse karenge jab tak woh `left`
position par na pahunch jaye.

Har step par `before` ko previous node par
update karenge.

Iske baad:

    t = left position wala node
    before = left se just pehle wala node


Step 3:
Ab `left` se `right` tak ke nodes ko reverse
karna hai.

Iske liye `curr`, `prev` aur `nex` pointers
use karenge.

Reversal normal linked list reversal ki tarah
hogi.

Hum exactly:

    right - left + 1

nodes ko reverse karenge.


Step 4:
Reversal complete hone ke baad:

    prev
        ↓
    reversed portion ka first node

    curr
        ↓
    right ke baad wala node


Example:

    1 -> 2 -> 3 -> 4 -> 5

left = 2
right = 4

Reversal ke baad:

    1 -> 4 -> 3 -> 2    5
        ↑           ↑
       prev        curr


Step 5:
Original `left` node reversal ke baad reversed
portion ka last node ban chuka hai.

Isliye `t` ab bhi original left node ko point
kar raha hai.

Usko remaining list se connect karenge:

    t->next = curr


So:

    2 -> 5


Step 6:
Agar `left != 1` hai, toh `before` left portion
ka last node hai.

Usko reversed portion ke first node se connect
karna hoga:

    before->next = prev


So:

    1 -> 4 -> 3 -> 2 -> 5


Step 7:
Agar `left == 1` hai, toh reversed portion ka
first node hi new head hoga.

Isliye:

    return prev


Agar `left != 1` hai, toh original `head` return
kar denge.


-------------------------------------------------------
Dry Run
-------------------------------------------------------

Linked List:

    1 -> 2 -> 3 -> 4 -> 5

    left = 2
    right = 4


Initially:

    t = 1
    before = NULL


`left` position tak traverse:

    before = 1
    t = 2


Ab:

    before -> 1
    t      -> 2


Reverse `2 -> 3 -> 4`:

Before:

    1 -> 2 -> 3 -> 4 -> 5


After reversal:

    1    4 -> 3 -> 2    5
         ↑           ↑
        prev        curr


`t` original `left` node yani `2` par hai.

Connect right side:

    t->next = curr

So:

    2 -> 5


Connect left side:

    before->next = prev

So final:

    1 -> 4 -> 3 -> 2 -> 5


-------------------------------------------------------
Important Case: left == 1
-------------------------------------------------------

Example:

    1 -> 2 -> 3 -> 4 -> 5

    left = 1
    right = 3


Yahan `left` se pehle koi node nahi hai.

Isliye:

    before = NULL


Reversal ke baad:

    3 -> 2 -> 1 -> 4 -> 5


Yahan `prev` hi new head hai.

Therefore:

    return prev


-------------------------------------------------------
Why Do We Need before?
-------------------------------------------------------

`before` left portion aur reversed portion ko
connect karne ke liye use hota hai.

Example:

    1 -> 2 -> 3 -> 4 -> 5
         ↑
        left

Reversal ke baad:

    1    4 -> 3 -> 2    5

Hume:

    1 -> 4

karna hai.

Isliye:

    before->next = prev


-------------------------------------------------------
Why Do We Need t?
-------------------------------------------------------

`t` original `left` node ko point karta hai.

Reversal ke baad original `left` node reversed
portion ka last node ban jata hai.

Example:

    2 -> 3 -> 4

reverse:

    4 -> 3 -> 2

Ab `2` ko `right` ke baad wale node se connect
karna hai:

    2 -> 5

Isliye:

    t->next = curr


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. `t = head` aur `before = NULL` initialize karo.

2. `t` ko `left` position tak traverse karo.

3. `left` se `right` tak ke nodes ko reverse karo
   using `prev`, `curr` and `nex`.

4. Reversal ke baad:
   
   `t->next = curr`

5. Agar `before != NULL`:
   
   `before->next = prev`

6. Agar `left == 1`:
   
   `return prev`

7. Otherwise:
   
   `return head`


-------------------------------------------------------
Key Idea
-------------------------------------------------------

Sirf required portion ko reverse karna hai.

    Left Part
       ↓
    Reversed Part
       ↓
    Right Part

Pehle portion reverse karo,
phir dono sides ko reconnect karo.


Important pointers:

    before
       ↓
    left se pehle wala node

    t
       ↓
    original left node

    prev
       ↓
    reversed portion ka new head

    curr
       ↓
    right ke baad wala node


-------------------------------------------------------
Revision Trick
-------------------------------------------------------

"Reach → Reverse → Connect"

    1. Left tak reach karo
    2. Left to Right reverse karo
    3. Left side connect karo
    4. Right side connect karo

Important:

    before->next = prev
    t->next = curr


-------------------------------------------------------
Complexity
-------------------------------------------------------

Time Complexity:
O(n)

Linked list ko maximum ek baar traverse kar rahe hain.


Space Complexity:
O(1)

Sirf pointers use kar rahe hain.
Koi extra data structure nahi use kar rahe.


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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL){
            return NULL;
        }

        if(left==right){
            return head;
        }

        ListNode* t= head;
        ListNode* before= NULL;

        int pos=1;

        while(t!=NULL){
            if(pos<left){
                before=t;
                t=t->next;
                pos++;
                continue;
            }

            ListNode* curr =t ;
            ListNode* prev= NULL;

            int time= right-left+1;

            while(time--){
                ListNode* nex= curr->next;
                curr->next= prev;
                prev=curr;
                curr = nex;
            }
            t->next= curr;
            if(before){
                before->next= prev;
                return head;
            }
            return prev;
        }
           return head;
    }
};
