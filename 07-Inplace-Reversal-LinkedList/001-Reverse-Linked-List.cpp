
Problem    : Reverse Linked List
Platform   : LeetCode
Problem No.: 206
Pattern    : In-Place Reversal of Linked List
Difficulty : Easy

-------------------------------------------------------
Question
-------------------------------------------------------

Hume given singly linked list ko reverse karna hai.

Example:

    1 -> 2 -> 3 -> 4 -> 5 -> NULL

Reverse karne ke baad:

    5 -> 4 -> 3 -> 2 -> 1 -> NULL


-------------------------------------------------------
Intuition
-------------------------------------------------------

Linked list ko reverse karte waqt har node ka `next`
pointer opposite direction mein point karna chahiye.

Example:

    1 -> 2 -> 3 -> NULL

Reverse:

    1 <- 2 <- 3

Is process mein agar hum directly `curr->next` ko
change kar denge, toh original next node ka reference
lose ho jayega.

Isliye pehle original next node ko save karna zaroori hai.

Iske liye hum 3 pointers use karenge:

    prev
    curr
    next


-------------------------------------------------------
Approach
-------------------------------------------------------

Initially:

    curr = head
    prev = NULL

Loop tab tak chalega jab tak:

    curr != NULL


Har iteration mein 4 steps perform karenge:


Step 1:
Sabse pehle current node ka next node save karenge.

    next = curr->next

Ye isliye zaroori hai kyunki next step mein
`curr->next` ko change karne wale hain.


Step 2:
Current node ka link reverse karenge.

    curr->next = prev

Ab current node previous node ki taraf point karega.


Step 3:
`prev` ko current node par move karenge.

    prev = curr

Ab current node reversed list ka previous part ban gaya.


Step 4:
`curr` ko saved next node par move karenge.

    curr = next

Ab hum original linked list ke next node par aa gaye.


Ye process tab tak repeat karenge jab tak:

    curr == NULL


-------------------------------------------------------
Why Do We Save next First?
-------------------------------------------------------

Ye sabse important point hai.

Agar hum pehle:

    curr->next = prev

kar denge aur `next` save nahi kiya, toh original
next node ka address lose ho jayega.

Example:

    1 -> 2 -> 3

Agar `1->next = NULL` kar diya bina `2` ko save kiye,
toh hum `2` tak pahunch hi nahi paayenge.

Isliye order hamesha:

    Save next
        ↓
    Reverse link
        ↓
    Move prev
        ↓
    Move curr


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. `prev = NULL` initialize karo.
2. `curr = head` initialize karo.
3. Jab tak `curr != NULL`:
   
   a. `next = curr->next`
   
   b. `curr->next = prev`
   
   c. `prev = curr`
   
   d. `curr = next`

4. `prev` ko return karo.


-------------------------------------------------------
Key Idea
-------------------------------------------------------

Har iteration mein ek node ka link reverse karna hai.

    next save karo
        ↓
    link reverse karo
        ↓
    prev aage karo
        ↓
    curr aage karo


Loop ke end mein:

    curr = NULL
    prev = New Head


-------------------------------------------------------
Complexity
-------------------------------------------------------

Time Complexity:
O(n)

Har node ko exactly ek baar process karte hain.


Space Complexity:
O(1)

Sirf 3 pointers use kar rahe hain:

    prev
    curr
    next

Koi extra array, stack ya linked list create nahi
kar rahe hain.


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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;

        while(curr!=NULL){
            ListNode* nextNode=curr->next;// save curr next
            curr->next=prev; //reverse 
            prev=curr; // move prev
            curr=nextNode; // move curr

        }
        return prev;
    }
};
