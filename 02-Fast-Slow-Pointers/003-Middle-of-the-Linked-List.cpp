
Problem    : Middle of the Linked List
Platform   : LeetCode
Problem No.: 876
Pattern    : Fast & Slow Pointers
Difficulty : Easy

Approach 1 (Brute Force)

Intuition :
- Traverse the linked list once to calculate the total
  number of nodes.
- The middle node will be present at index:
      length / 2
- Traverse the list again and move the pointer
  length / 2 steps from the head.
- The current node will be the required middle node.
- If the linked list contains an even number of nodes,
  length / 2 automatically points to the second middle
  node, which matches the problem requirement.

Approach :
- Initialize count = 0.
- Traverse the linked list and count the total nodes.
- Calculate:
      middle = count / 2
- Move the pointer back to the head.
- Traverse middle steps.
- Return the current node.

Time Complexity  : O(n) + O(n/2)
                 = O(n)

Space Complexity : O(1)

-------------------------------------------------------

Approach 2 (Optimal - Fast & Slow Pointer)

Intuition :
- Instead of traversing the linked list twice,
  use two pointers moving at different speeds.
- Slow pointer moves one step at a time.
- Fast pointer moves two steps at a time.
- Since the fast pointer moves twice as fast,
  when it reaches the end of the linked list,
  the slow pointer automatically reaches the
  middle node.
- If the linked list contains an even number
  of nodes, the slow pointer stops at the
  second middle node, satisfying the problem
  requirement.

Approach :
- Initialize:
      slow = head
      fast = head
- While:
      fast != nullptr
      &&
      fast->next != nullptr
- Move:
      slow = slow->next
      fast = fast->next->next
- When the loop terminates,
  slow points to the middle node.
- Return slow.

Why does this work?
- Slow pointer moves 1 step per iteration.
- Fast pointer moves 2 steps per iteration.
- Therefore, when fast completes the traversal,
  slow has covered exactly half the distance.
- Hence, slow points to the middle node.

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast= head;

        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
};
