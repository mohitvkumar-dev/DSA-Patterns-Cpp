
Problem    : Happy Number
Platform   : LeetCode
Problem No.: 202
Pattern    : Fast & Slow Pointers (Floyd's Cycle Detection)
Difficulty : Easy

Intuition :
- Repeatedly replace the current number with the sum of
  the squares of its digits.
- The sequence can have only two outcomes:
    • It eventually reaches 1 (Happy Number).
    • It enters a cycle (Not a Happy Number).
- Since every number generates exactly one next number,
  the sequence behaves like a Linked List where:
      current number -> nextNumber(current number)
- Therefore, Floyd's Cycle Detection Algorithm can be
  used to detect whether the sequence reaches 1 or falls
  into a cycle.

Approach :
- Create a helper function nextNumber() which returns
  the sum of the squares of the digits of a number.
- Initialize:
      slow = nextNumber(n)
      fast = nextNumber(nextNumber(n))
- Move:
      slow = nextNumber(slow)
      fast = nextNumber(nextNumber(fast))
- Continue until slow == fast.
- If the meeting point is 1:
      Return true.
- Otherwise:
      Return false.

Why does this work?
- Every number has exactly one next state, so the
  sequence behaves like a linked list.
- If the sequence reaches 1, it stays at 1 forever.
- If it never reaches 1, it must eventually repeat a
  previous value, forming a cycle.
- Floyd's Algorithm detects this cycle without using
  extra space.

Time Complexity  : O(log n)

Space Complexity : O(1)





  class Solution {
public:

     int nextNumber(int n){
        int sum=0;;
        while(n>0){
            int digit=n%10;
            sum= sum+digit*digit;
            n=n/10;

        }
        return sum;

        }
    bool isHappy(int n) {
       
     int slow = nextNumber(n);
     int fast=nextNumber(nextNumber(n));
     while(slow!=fast){
            slow = nextNumber(slow);
            fast=nextNumber(nextNumber(fast));
     }
      if(slow==1){
        return true;
      }else{
        return false;
      }
    }
};
