
Problem    : Reverse Nodes in k-Group
Platform   : LeetCode
Problem No.: 25
Pattern    : In-Place Reversal of Linked List
Difficulty : Hard

-------------------------------------------------------
Question
-------------------------------------------------------

Hume linked list ke nodes ko `k`-k ke groups mein
reverse karna hai.

Har complete group of `k` nodes ko reverse karna hai.

Agar last mein `k` se kam nodes bachte hain, toh unhe
reverse nahi karna hai.


Example:

    1 -> 2 -> 3 -> 4 -> 5

    k = 2

Result:

    2 -> 1 -> 4 -> 3 -> 5


Example:

    1 -> 2 -> 3 -> 4 -> 5

    k = 3

Result:

    3 -> 2 -> 1 -> 4 -> 5


-------------------------------------------------------
Intuition
-------------------------------------------------------

LC 24 mein hum adjacent 2 nodes ko pair-wise reverse
kar rahe the.

LC 25 mein same concept hai, bas:

    LC 24:
        group size = 2

    LC 25:
        group size = k

Isliye hum linked list ko `k`-k nodes ke groups mein
process karenge.

Har complete group ko reverse karenge.

Agar last mein `k` se kam nodes bach gaye, toh unhe
without reversing waise hi rehne denge.


-------------------------------------------------------
Approach
-------------------------------------------------------

Hum `left` ko current group ke first node par rakhenge.

Previous reversed group ke last node ko track karne ke
liye:

    prevleft = NULL

Aur first reversed group ka head store karne ke liye:

    res = NULL


-------------------------------------------------------
Step 1: Current Group ke k Nodes Check Karna
-------------------------------------------------------

Current group mein `k` nodes available hain ya nahi,
ye check karna zaroori hai.

Agar `k` complete nodes nahi milte, toh remaining nodes
ko reverse nahi karna hai.


-------------------------------------------------------
Step 2: Next Group ka Address Save Karna
-------------------------------------------------------

Complete `k` nodes milne ke baad current group ke
baad wale node ka address save karenge:

    nextleft

Ye reversal ke baad next group par move karne ke
liye required hoga.


-------------------------------------------------------
Step 3: Current k Nodes Reverse Karna
-------------------------------------------------------

Ab current group ke exactly `k` nodes ko reverse
karna hai.

Normal linked list reversal ka same logic use hoga:

    next save karo
    curr->next = prev
    prev = curr
    curr = next

Yahan difference sirf itna hai ki reversal
exactly `k` nodes tak karna hai.


-------------------------------------------------------
Step 4: Reversal ke Baad
-------------------------------------------------------

Agar group tha:

    1 -> 2 -> 3

k = 3

After reversal:

    3 -> 2 -> 1

Reversal ke baad:

    right / prev
        ↓
    current group ka first node

Aur original first node:

    left
        ↓
    current group ka last node


-------------------------------------------------------
Step 5: Previous Group ko Connect Karna
-------------------------------------------------------

Agar previous reversed group exist karta hai,
toh previous group ke last node ko current reversed
group ke head se connect karenge:

    prevleft->next = prev


-------------------------------------------------------
Step 6: First Group ka Head Store Karna
-------------------------------------------------------

Agar current group first group hai, toh reversal ke
baad `prev` current group ka new head hoga.

Isliye:

    res = prev


-------------------------------------------------------
Step 7: Previous Pointer Update Karna
-------------------------------------------------------

Current reversed group ka last node original
`left` node hai.

Isliye:

    prevleft = left


-------------------------------------------------------
Step 8: Next Group par Move Karna
-------------------------------------------------------

Saved `nextleft` ki help se next group par move
karna hai:

    left = nextleft


-------------------------------------------------------
Step 9: Last Incomplete Group
-------------------------------------------------------

Agar last mein `k` se kam nodes bache hain, toh
unhe reverse nahi karna hai.

Example:

    1 -> 2 -> 3 -> 4 -> 5

    k = 3

First group:

    1 -> 2 -> 3

reverse:

    3 -> 2 -> 1

Remaining:

    4 -> 5

Sirf 2 nodes hain, jabki k = 3.

Isliye:

    4 -> 5

unchanged rahega.

Final:

    3 -> 2 -> 1 -> 4 -> 5


-------------------------------------------------------
Dry Run
-------------------------------------------------------

Linked List:

    1 -> 2 -> 3 -> 4 -> 5

    k = 2


FIRST GROUP
-----------

Current group:

    1 -> 2

`k = 2` complete nodes available hain.

Reverse:

    1 -> 2

becomes:

    2 -> 1

First group hai:

    res = 2

Current group ka last node:

    prevleft = 1

Next group:

    left = 3


SECOND GROUP
------------

Current group:

    3 -> 4

Reverse:

    3 -> 4

becomes:

    4 -> 3

Previous group se connect:

    1 -> 4

Update:

    prevleft = 3
    left = 5


LAST GROUP
-----------

Remaining:

    5

Sirf 1 node hai.

But:

    k = 2

Complete group nahi hai.

Isliye `5` ko reverse nahi karenge.

Previous group se connect:

    3 -> 5


Final:

    2 -> 1 -> 4 -> 3 -> 5


-------------------------------------------------------
Another Example
-------------------------------------------------------

List:

    1 -> 2 -> 3 -> 4 -> 5

k = 3


First group:

    1 -> 2 -> 3

Reverse:

    3 -> 2 -> 1


Remaining:

    4 -> 5

Only 2 nodes remain.

Since:

    2 < 3

remaining nodes unchanged rahenge.


Final:

    3 -> 2 -> 1 -> 4 -> 5


-------------------------------------------------------
Why Check k Nodes Before Reversal?
-------------------------------------------------------

Question ki condition hai:

Agar last group mein `k` se kam nodes hain,
toh unhe reverse nahi karna hai.

Isliye har group ke reversal se pehle check karna
zaroori hai ki exactly `k` nodes available hain.

Agar `k` complete nahi hua:

    Stop / remaining list unchanged


-------------------------------------------------------
Important Pointer Roles
-------------------------------------------------------

left:

    Current group ka first node.

prevleft:

    Previous reversed group ka last node.

nextleft:

    Next group ka first node.

prev:

    Reversal ke baad current group ka new head.

curr:

    Current group mein reversal ke time move
    karne wala pointer.

res:

    Final linked list ka head.


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. `left = head`
2. `prevleft = NULL`
3. `res = NULL`

4. Jab tak group process karna possible hai:

   a. Check karo ki current group mein `k` nodes hain.

   b. Agar k nodes nahi hain:
         remaining nodes ko unchanged chhodo
         break.

   c. Current group ko exactly `k` nodes tak reverse karo.

   d. Agar previous group exist karta hai:
         `prevleft->next = prev`

   e. Agar first group hai:
         `res = prev`

   f. `prevleft = left`

   g. `left = nextleft`

5. `res` return karo.


-------------------------------------------------------
Key Idea
-------------------------------------------------------

LC 24:

    2 nodes reverse karo.

LC 25:

    k nodes reverse karo.


Core idea:

    Check k nodes
         ↓
    Reverse k nodes
         ↓
    Previous group se connect
         ↓
    Next group par move


-------------------------------------------------------
Revision Trick
-------------------------------------------------------

"Check → Reverse → Connect → Move"

    1. k nodes available hain?
    2. k nodes reverse karo
    3. Previous group se connect karo
    4. Next group par move karo


Most Important:

    Last group < k
        ↓
    Don't reverse


-------------------------------------------------------
Complexity
-------------------------------------------------------

Time Complexity:
O(n)

Har node ko groups ke through maximum ek baar
process kiya jata hai.


Space Complexity:
O(1)

Sirf pointers use kar rahe hain.

Koi extra array, stack ya linked list use nahi
kar rahe.


-------------------------------------------------------
Pattern Connection
-------------------------------------------------------

Ye In-Place Linked List Reversal pattern ka
extension hai.

LC 206:
    Puri linked list reverse

LC 92:
    [left, right] range reverse

LC 24:
    Har 2 nodes reverse

LC 25:
    Har k nodes reverse

Core reversal logic sab mein same hai:

    next save
    link reverse
    pointers move


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

    // 'times' nodes ko reverse karega
    void reverse(ListNode* head, int times) {

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(times--) {

            // Next node save kar rahe hain
            ListNode* nex = curr->next;

            // Link reverse
            curr->next = prev;

            // Pointers move
            prev = curr;
            curr = nex;
        }
    }


    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL)
            return NULL;

        // Current group ka first node
        ListNode* left = head;

        // Current group ka kth node
        ListNode* right;

        // Final answer ka head
        ListNode* res = NULL;

        // Previous reversed group ka last node
        ListNode* prevleft = NULL;

        // Ab 2 ki jagah k nodes reverse honge
        int size = k;


        while(true) {

            // Current group ke first node se start
            right = left;

            // right ko k-1 steps aage le jao
            for(int i = 0; i < size - 1; i++) {

                // Agar kth node nahi mila
                if(right == NULL)
                    break;

                right = right->next;
            }


            // Complete k-sized group mil gaya
            if(right) {

                // Next group ka first node pehle save karo
                ListNode* nextleft = right->next;

                // Current k nodes reverse karo
                reverse(left, size);

                // Previous group ko current group se connect karo
                if(prevleft)
                    prevleft->next = right;

                // Current reversed group ka last node
                // next iteration me previous group ka last node banega
                prevleft = left;

                // First reversed group ka head
                if(res == NULL)
                    res = right;

                // Next group par move
                left = nextleft;
            }


            // Complete k nodes nahi mile
            else {

                // Remaining nodes ko unchanged rakho
                if(prevleft)
                    prevleft->next = left;

                // Agar first group hi incomplete tha
                if(res == NULL)
                    res = left;

                break;
            }
        }

        return res;
    }
};
