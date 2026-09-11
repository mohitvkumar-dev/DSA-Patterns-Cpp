
Problem    : Rotate List
Platform   : LeetCode
Problem No.: 61
Pattern    : In-Place Reversal of Linked List
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hume given linked list ko `k` places to the right
rotate karna hai.

Example:

    1 -> 2 -> 3 -> 4 -> 5 -> NULL

    k = 2

After rotation:

    4 -> 5 -> 1 -> 2 -> 3 -> NULL


-------------------------------------------------------
Intuition
-------------------------------------------------------

Suppose:

    1 -> 2 -> 3 -> 4 -> 5 -> NULL

and:

    k = 2

Agar carefully observe karein, toh last `k` nodes:

    4 -> 5

front mein aa jayenge.

Aur remaining `n-k` nodes:

    1 -> 2 -> 3

unke baad aa jayenge.

Therefore:

    4 -> 5 -> 1 -> 2 -> 3


Is rotation ko achieve karne ke liye 3 important
pointer operations hain:

1. Last node ko new head se connect karna.
2. `(n-k)`th node ko new last node banana.
3. `(n-k)`th node ke baad link ko NULL karna.


Example:

    1 -> 2 -> 3 -> 4 -> 5 -> NULL

Here:

    n = 5
    k = 2
    n-k = 3

So:

    3 -> NULL

karna hai.

Aur:

    5 -> 4

karna hai.

Then:

    4 -> 5 -> 1 -> 2 -> 3 -> NULL


-------------------------------------------------------
Approach
-------------------------------------------------------

Step 1: Empty List Handle Karna
-------------------------------------------------------

Agar:

    head == NULL

hai, toh list mein kuch nahi hai.

Isliye:

    return NULL


-------------------------------------------------------
Step 2: Length aur Last Node Find Karna
-------------------------------------------------------

Puri linked list ko traverse karenge.

Is traversal ke during:

    n = total number of nodes

count karenge aur last node ko bhi identify
kar lenge.

Last node woh hoga jiska:

    current->next == NULL

hai.

Example:

    1 -> 2 -> 3 -> 4 -> 5 -> NULL

Yahan:

    n = 5
    last = 5


-------------------------------------------------------
Step 3: k ko Reduce Karna
-------------------------------------------------------

`k` `n` se bada ho sakta hai.

Example:

    n = 5
    k = 7

7 rotations same hain as:

    7 % 5 = 2

Because every `n` rotations ke baad linked list
apni original position par aa jaati hai.

Therefore:

    k = k % n


Agar:

    k == 0

hai, toh list already same rahegi.

Isliye:

    return head


-------------------------------------------------------
Step 4: (n-k)th Node Find Karna
-------------------------------------------------------

Ab hume woh node find karni hai jo new list ka
last node banegi.

Ye node hai:

    (n-k)th node


Example:

    1 -> 2 -> 3 -> 4 -> 5

    n = 5
    k = 2

    n-k = 3

So:

    current = 3


`current->next` new head hoga.

Therefore:

    newHead = current->next

Yahan:

    newHead = 4


-------------------------------------------------------
Step 5: List Break Karna
-------------------------------------------------------

`(n-k)`th node new list ka last node hona chahiye.

Isliye:

    current->next = NULL


Ab:

    1 -> 2 -> 3 -> NULL

aur:

    4 -> 5 -> NULL


-------------------------------------------------------
Step 6: Old Last Node ko New Head se Connect Karna
-------------------------------------------------------

Old last node `5` ko new head `4` se connect
karna hai.

Therefore:

    last->next = newHead


Ab:

    4 -> 5 -> 1 -> 2 -> 3 -> NULL


Final rotated list complete ho gayi.


-------------------------------------------------------
Why k % n?
-------------------------------------------------------

Agar list mein `n` nodes hain, toh `n` rotations
ke baad list exactly original position par aa
jaati hai.

Example:

    n = 5

    k = 5
    k = 10
    k = 15

Sab cases mein final list same hogi.

Isliye unnecessary rotations ko remove karne ke liye:

    k = k % n


-------------------------------------------------------
Important Pointer Roles
-------------------------------------------------------

current:

    `(n-k)`th node ko find karne ke liye.

last:

    Original linked list ka last node.

newHead:

    Rotated list ka new head.

head:

    Original list ka head.


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. Agar `head == NULL`:
       return NULL

2. Linked list traverse karke:
       n = length
       last = last node

3. Calculate:
       k = k % n

4. Agar:
       k == 0
   toh:
       return head

5. `(n-k)`th node find karo.

6. Uska next save karo:
       newHead = current->next

7. List break karo:
       current->next = NULL

8. Old last node ko new head se connect karo:
       last->next = newHead

9. `newHead` return karo.


-------------------------------------------------------
Key Idea
-------------------------------------------------------

Last `k` nodes ko front mein shift karna hai.

    Original:

    [ first n-k nodes ] [ last k nodes ]

    Rotation:

    [ last k nodes ] [ first n-k nodes ]


Bas:

    (n-k)th node ke baad list break karo

aur:

    old last -> new head

connect kar do.


-------------------------------------------------------
Revision Trick
-------------------------------------------------------

"Count → Cut → Connect"

    1. Length count karo
    2. k = k % n
    3. (n-k)th node find karo
    4. Uske baad list cut karo
    5. Old last ko new head se connect karo


Most important:

    newHead = current->next
    current->next = NULL
    last->next = newHead


-------------------------------------------------------
Complexity
-------------------------------------------------------

Time Complexity:
O(n)

Pehle length aur last node find karne ke liye
traverse karte hain.

Phir `(n-k)`th node find karne ke liye ek aur
traversal karte hain.

Total:

    O(n) + O(n) = O(n)


Space Complexity:
O(1)

Sirf pointers use kar rahe hain.

Koi extra array, stack ya linked list use nahi
kar rahe.


-------------------------------------------------------
Pattern Connection
-------------------------------------------------------

Ye In-Place Linked List pattern mein pointer
rearrangement ka problem hai.

Ismein nodes ko physically move nahi karte.

Sirf existing `next` pointers ko change karke:

    Last k nodes
        ↓
    Front par connect

karte hain.


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
    ListNode* rotateRight(ListNode* head, int k) {
          if(head==NULL){
            return NULL;
          }
          
        // finding n & last 
        ListNode* last= head;
        int n=1;

        while(last->next!=NULL){
            n++;
            last= last->next;
        }

        k=k%n;

        if(k==0){
            return head;
        }
     // finding (n-k)th node
        ListNode* t= head;
        int count=1;

        while(t!=NULL){
            if(count==(n-k)){
                break;
            }
            count++;
            t= t->next;
        }

        // 3 step updatation 

        last->next=head;
        ListNode* res= t->next;
        t->next= NULL;

        return res;

    }
};
