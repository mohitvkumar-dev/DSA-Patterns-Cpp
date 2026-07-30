
Problem    : Palindrome Linked List
Platform   : LeetCode
Problem No.: 234
Pattern    : Fast & Slow Pointer + In-Place Reversal of Linked List
Difficulty : Easy

Intuition :
- To check whether a linked list is a palindrome,
  we need to compare the left and right halves.
- In an array, this is easy because we can access
  elements from both ends.
- However, a singly linked list can only be traversed
  in the forward direction.
- Therefore, instead of traversing from the end,
  reverse the second half of the linked list.
- After reversing, both halves can be compared by
  moving forward simultaneously.

Approach :
- Find the middle of the linked list using the
  Slow & Fast Pointer technique.
- Reverse the second half of the linked list
  starting from slow->next.
- Initialize:
      first = head
      second = reversed second half
- Compare the values of both pointers:
      If any value differs,
          return false.
- Move both pointers one step at a time.
- If all nodes of the second half match,
  return true.

Why does this work?
- A singly linked list cannot be traversed
  from the end.
- Reversing the second half brings the right
  half into forward order.
- Now both halves can be compared using
  normal forward traversal.
- If every corresponding node matches,
  the linked list is a palindrome.

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

    ListNode* reverselist(ListNode* head){
        ListNode* prev =NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            ListNode* nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    } 
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }

        ListNode* slow= head;
        ListNode* fast= head;

        while(fast->next !=NULL && fast->next->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* secondHalf = reverselist(slow->next);

        ListNode* firstHalf = head;

        while(secondHalf !=NULL){
            if(firstHalf->val != secondHalf->val)
             return false;

             firstHalf = firstHalf->next;
             secondHalf = secondHalf->next;
        }
        return true;
    }
};
