
Problem    : Linked List Cycle
Platform   : LeetCode
Problem No.: 141
Pattern    : Fast & Slow Pointers (Floyd's Cycle Detection)
Difficulty : Easy

Intuition :
- We need to determine whether a linked list contains
  a cycle.
- If a cycle exists, some node will be visited again.
- Instead of storing visited nodes using extra space,
  use two pointers moving at different speeds.
- If the two pointers ever meet, a cycle exists.
- If the fast pointer reaches the end of the list,
  no cycle is present.

Approach :
- Use Floyd's Cycle Detection Algorithm.
- Initialize two pointers:
    • slow = head
    • fast = head
- Move:
    • slow by one step.
    • fast by two steps.
- Continue while both fast and fast->next exist.
- If slow == fast at any point:
    • A cycle is present.
    • Return true.
- If the loop ends because fast or fast->next becomes
  nullptr:
    • The list has no cycle.
    • Return false.

Why does this work?
- In a linear linked list, the fast pointer eventually
  reaches nullptr.
- In a cyclic linked list, the fast pointer never reaches
  the end.
- Since the fast pointer moves one node faster than the
  slow pointer in every iteration (relative speed = 1),
  it will eventually catch the slow pointer inside the
  cycle.

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
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                return true;
            }
            
        }
        return false;
    }
};
  
