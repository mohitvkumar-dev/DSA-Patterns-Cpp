
Problem    : Linked List Cycle II
Platform   : LeetCode
Problem No.: 142
Pattern    : Fast & Slow Pointers (Floyd's Cycle Detection)
Difficulty : Medium

Intuition :
- We need to find the starting node of the cycle in a
  linked list.
- Instead of using extra space (unordered_set), use
  Floyd's Cycle Detection Algorithm.
- First detect whether a cycle exists.
- If a cycle is found, use the meeting point to locate
  the starting node of the cycle.

Mathematical Proof :

Let,

L1 = Distance from Head to the start of the cycle.
L2 = Distance from the start of the cycle to the
     meeting point.
C  = Length of the cycle.
n  = Number of extra rotations made by the fast pointer.

Slow Pointer Distance :

L1 + L2

Fast Pointer Distance :

L1 + nC + L2

Since the fast pointer moves twice as fast as the slow
pointer,

L1 + nC + L2 = 2(L1 + L2)

Simplifying,

L1 = nC - L2

L1 = (n - 1)C + (C - L2)

Since completing full cycles ((n-1)C) does not change
the position inside the cycle,

Effective Distance,

L1 = C - L2

This means,

Distance from Head to Cycle Start
=
Distance from Meeting Point to Cycle Start

Therefore,

If one pointer starts from Head and the other starts
from the Meeting Point, moving both one step at a
time will make them meet exactly at the starting node
of the cycle.

Approach :
- Initialize two pointers:
    • slow = head
    • fast = head
- Move:
    • slow by one step.
    • fast by two steps.
- If slow and fast never meet:
    • No cycle exists.
    • Return nullptr.
- If they meet:
    • Move slow back to head.
    • Keep fast at the meeting point.
- Move both pointers one step at a time.
- The node where they meet again is the starting node
  of the cycle.
- Return that node.

Time Complexity  : O(n)

Space Complexity : O(1)





  /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow= head;
        ListNode* fast= head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                slow=head;

                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};  
