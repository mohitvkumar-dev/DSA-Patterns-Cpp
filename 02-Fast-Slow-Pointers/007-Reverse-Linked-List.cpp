
Problem    : Reverse Linked List
Platform   : LeetCode
Problem No.: 206
Pattern    : In-Place Reversal of Linked List
Difficulty : Easy

Intuition :
- Reversing a linked list does not require moving the
  nodes. We only need to reverse the direction of each
  node's next pointer.
- Before changing the current node's next pointer,
  store the address of the next node. Otherwise,
  the remaining linked list would be lost.
- By repeating this process for every node, the entire
  linked list gets reversed in-place.

Approach :
- Initialize:
      prev = nullptr
      curr = head
- While curr != nullptr:
    1. Store the next node:
           nextNode = curr->next
    2. Reverse the current link:
           curr->next = prev
    3. Move prev forward:
           prev = curr
    4. Move curr forward:
           curr = nextNode
- When the loop ends,
  prev points to the new head of the reversed list.
- Return prev.

Why does this work?
- The next node is saved before reversing the link,
  so the remaining linked list is never lost.
- Each iteration reverses exactly one pointer.
- After processing all nodes, every link points in
  the opposite direction.
- The last processed node becomes the new head,
  which is stored in prev.

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
