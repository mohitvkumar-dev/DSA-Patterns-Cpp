
Problem    : Intersection of Two Linked Lists
Platform   : LeetCode
Problem No.: 160
Pattern    : Two Pointers / Pointer Switching
Difficulty : Easy

Approach 1 (Brute Force)

Intuition :
- For every node of List A, traverse List B and check
  whether the exact same node exists in List B.
- Intersection means both lists share the same node
  address, not just the same value.

Approach :
- Traverse List A using pointer pA.
- For every node in List A:
    • Traverse List B using pointer pB.
    • If pA == pB, return pA.
- If no common node is found, return nullptr.

Time Complexity  : O(m * n)

Space Complexity : O(1)

-------------------------------------------------------

Approach 2 (Optimal - Pointer Switching)

Intuition :
- The two linked lists may have different lengths.
- Therefore, pointers starting from their respective
  heads may not reach the intersection at the same time.
- To compensate for this length difference, switch
  the pointers to the opposite list after reaching
  the end.

Let:

A = X + C
B = Y + C

where:

X = Unique part of List A
Y = Unique part of List B
C = Common part

Before meeting at the intersection:

pA travels = X + C + Y
pB travels = Y + C + X

Both distances are equal.

Therefore, after switching lists, the length difference
is automatically compensated and both pointers reach
the intersection node at the same time.

Approach :
- Initialize:
      pA = headA
      pB = headB

- While pA != pB:
    • If pA becomes nullptr:
          pA = headB
      Otherwise:
          pA = pA->next

    • If pB becomes nullptr:
          pB = headA
      Otherwise:
          pB = pB->next

- Eventually:
    • If an intersection exists, pA and pB meet at
      the intersection node.
    • If no intersection exists, both become nullptr.

- Return pA.

Why does this work?
- Each pointer traverses both lists once.
- Therefore, both pointers cover the same total
  distance regardless of the initial length difference.
- Pointer switching automatically cancels the unequal
  portions of the two lists.

Important :
- Compare node addresses:
      pA == pB
  NOT node values:
      pA->val == pB->val
- Two different nodes can contain the same value but
  that does not mean the lists intersect.

Time Complexity  : O(m + n)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode* PA=headA;
         ListNode* PB=headB;

         while(PA!=PB){
            if(PA==NULL){
                PA=headB;
            }else{
                PA=PA->next;
            }

            if(PB==NULL){
                PB=headA;
            }else{
                PB=PB->next;
            }
         }
         return PA;
    }
};
