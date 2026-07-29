
Problem    : Remove Nth Node From End of List
Platform   : LeetCode
Problem No.: 19
Pattern    : Fixed Gap Two Pointers
Difficulty : Medium

Approach 1 (Brute Force)

Intuition :
- Since we cannot traverse a linked list from the end,
  first calculate the total length of the linked list.
- If the total length is L, then the node to be removed
  from the end is at position (L - n) from the beginning.
- Traverse again until the previous node of the target
  node and remove it.

Approach :
- Traverse the linked list and count the total nodes.
- Calculate:
      position = length - n
- Traverse again to reach the previous node of the
  target node.
- Delete the target node by changing pointers.
- Return the updated head.

Time Complexity  : O(n) + O(n)
                 = O(n)

Space Complexity : O(1)

-------------------------------------------------------

Approach 2 (Optimal - Fixed Gap Two Pointers)

Intuition :
- Instead of traversing twice, maintain a fixed gap
  of n nodes between two pointers.
- Create a dummy node before the head so that deleting
  the head node is handled exactly like deleting any
  other node.
- Move the fast pointer n+1 steps ahead (or n steps,
  depending on the implementation).
- Then move both pointers one step at a time.
- When the fast pointer reaches the end,
  the slow pointer automatically reaches the node
  just before the node to be deleted.

Approach :
- Create a dummy node pointing to head.
- Initialize:
      slow = dummy
      fast = dummy
- Move fast pointer ahead to create a gap of n+1 nodes.
- Move both pointers one step at a time until
  fast reaches nullptr.
- Now slow points to the previous node of the
  node to be removed.
- Delete the target node:
      slow->next = slow->next->next;
- Return:
      dummy->next

Why Dummy Node?
- A dummy node provides a valid previous node even
  for the head.
- This avoids handling head deletion as a separate
  special case.
- Every deletion follows the same logic.

Why does this work?
- The gap between fast and slow always remains n nodes.
- Therefore, when fast reaches the end,
  slow reaches the previous node of the target node.
- This allows deletion in a single traversal.

Time Complexity  : O(n)

Space Complexity : O(1)




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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* dummy = new ListNode(0);
       dummy->next=head;

       ListNode* slow= dummy;
       ListNode* fast= dummy;

       for(int i=0 ; i<=n ; i++){
        fast=fast->next;
       }

       while(fast!=NULL){
        slow= slow->next;
        fast= fast->next;
       }

       slow->next= slow->next->next;
       return dummy->next;

    }
};
