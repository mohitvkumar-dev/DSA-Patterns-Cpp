
Problem    : Swap Nodes in Pairs
Platform   : LeetCode
Problem No.: 24
Pattern    : In-Place Reversal of Linked List
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hume linked list ke adjacent nodes ko pair-wise swap
karna hai.

Example:

    1 -> 2 -> 3 -> 4 -> 5

Adjacent pairs:

    (1, 2)
    (3, 4)
    (5)

Har complete pair ko swap karna hai.

After swapping:

    2 -> 1 -> 4 -> 3 -> 5


-------------------------------------------------------
Intuition
-------------------------------------------------------

Do adjacent nodes ko swap karna aur un dono nodes ko
reverse karna equivalent hai.

Example:

    1 -> 2

Swap:

    2 -> 1

Ye exactly 2 nodes ko reverse karne ke same hai.

Isliye hum linked list ko 2-2 nodes ke groups mein
process karenge.

Har complete pair ko reverse karenge aur reverse hone
ke baad previous pair ko current pair se connect karenge.

Agar last mein ek single node bach jata hai, toh usko
bina reverse kiye list ke end mein connect kar denge.


-------------------------------------------------------
Approach
-------------------------------------------------------

Hum `left` ko current pair ke first node par rakhenge.

Initially:

    left = head

Aur previous reversed pair ke last node ko track
karne ke liye:

    prevleft = NULL

Pehli reversed pair ka head store karne ke liye:

    res = NULL


-------------------------------------------------------
Step 1: Pair ka second node find karna
-------------------------------------------------------

`right` ko `left` se ek step aage move karenge.

    right = left->next

Agar `right` exist karta hai, iska matlab complete
pair available hai.

Example:

    1 -> 2 -> 3

    left  = 1
    right = 2


-------------------------------------------------------
Step 2: Next pair ka address save karna
-------------------------------------------------------

Reversal se pehle `right->next` ko save karenge:

    nextleft = right->next

Ye zaroori hai kyunki current pair reverse hone
ke baad hume next pair par move karna hai.

Example:

    1 -> 2 -> 3

    nextleft = 3


-------------------------------------------------------
Step 3: Current pair reverse karna
-------------------------------------------------------

Ab current pair ke 2 nodes ko reverse karenge:

    reverse(left, 2)

Example:

    1 -> 2

becomes:

    2 -> 1


-------------------------------------------------------
Step 4: Reversal ke baad pointers
-------------------------------------------------------

Reversal ke baad:

    right
       ↓
    current pair ka first node

Aur:

    left
       ↓
    current pair ka last node


Example:

Before:

    1 -> 2

After:

    2 -> 1
    ↑    ↑
  right left


-------------------------------------------------------
Step 5: Previous pair ko current pair se connect
-------------------------------------------------------

Agar previous pair exist karta hai, toh previous
pair ke last node ko current reversed pair ke head
se connect karenge:

    prevleft->next = right


Example:

Previous pair:

    2 -> 1

Current reversed pair:

    4 -> 3

Connection:

    1 -> 4


-------------------------------------------------------
Step 6: First pair ka head store karna
-------------------------------------------------------

Pehli pair reverse hone ke baad `right` new head
hoga.

Isliye agar ye first pair hai:

    res = right

Example:

    1 -> 2

After reversal:

    2 -> 1

So:

    res = 2


-------------------------------------------------------
Step 7: Previous pair update karna
-------------------------------------------------------

Current reversed pair ka last node `left` hai.

Isliye:

    prevleft = left

Ab ye next pair ko connect karne ke kaam aayega.


-------------------------------------------------------
Step 8: Next pair par move karna
-------------------------------------------------------

Saved pointer `nextleft` ki help se next pair par
move karenge:

    left = nextleft


-------------------------------------------------------
Step 9: Single Node Case
-------------------------------------------------------

Agar `right` nahi milta, iska matlab last mein sirf
ek node bacha hai.

Example:

    1 -> 2 -> 3

First pair:

    1 -> 2

reverse:

    2 -> 1

Ab:

    3

single node bacha.

Is node ko reverse nahi karna hai.

Previous pair ke last node se connect karenge:

    prevleft->next = left

Then loop break kar denge.


-------------------------------------------------------
Dry Run
-------------------------------------------------------

Linked List:

    1 -> 2 -> 3 -> 4 -> 5


FIRST PAIR
----------

left = 1
right = 2

nextleft = 3

Reverse:

    1 -> 2

becomes:

    2 -> 1

Since first pair hai:

    res = 2

Update:

    prevleft = 1
    left = 3


Current list:

    2 -> 1    3 -> 4 -> 5


SECOND PAIR
-----------

left = 3
right = 4

nextleft = 5

Reverse:

    3 -> 4

becomes:

    4 -> 3

Previous pair ko current pair se connect:

    prevleft->next = right

    1 -> 4


Update:

    prevleft = 3
    left = 5


Current list:

    2 -> 1 -> 4 -> 3    5


LAST SINGLE NODE
----------------

left = 5

right = left->next

right = NULL

Matlab complete pair nahi hai.

Isliye `5` ko reverse nahi karenge.

Previous pair ke last node `3` se connect:

    3 -> 5


Final Linked List:

    2 -> 1 -> 4 -> 3 -> 5


-------------------------------------------------------
Why Do We Save nextleft?
-------------------------------------------------------

Current pair reverse karne ke baad original links
change ho jaate hain.

Example:

    1 -> 2 -> 3

Agar `right->next` ko pehle save nahi kiya, toh
pair reverse hone ke baad next pair ka starting
node lose ho sakta hai.

Isliye:

    nextleft = right->next

reversal se pehle karna zaroori hai.


-------------------------------------------------------
Important Pointer Roles
-------------------------------------------------------

left:

    Current pair ka first node.

right:

    Current pair ka second node aur reversal ke baad
    current pair ka first node.

nextleft:

    Next pair ka first node.

prevleft:

    Previous reversed pair ka last node.

res:

    Puri final list ka head.


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. `left = head`
2. `prevleft = NULL`
3. `res = NULL`

4. Jab tak `left != NULL`:

   a. `right = left->next`

   b. Agar `right == NULL`:
         Last single node hai.
         Previous pair se connect karo.
         Break.

   c. `nextleft = right->next`

   d. Current 2 nodes ko reverse karo:
         `reverse(left, 2)`

   e. Agar previous pair exist karta hai:
         `prevleft->next = right`

   f. Agar first pair hai:
         `res = right`

   g. `prevleft = left`

   h. `left = nextleft`

5. `res` return karo.


-------------------------------------------------------
Key Idea
-------------------------------------------------------

"Pair banao → Pair reverse karo → Connect karo"

    (1,2) -> reverse -> (2,1)
    (3,4) -> reverse -> (4,3)

Then connect:

    2 -> 1 -> 4 -> 3 -> 5


-------------------------------------------------------
Revision Trick
-------------------------------------------------------

3 main cheezein yaad rakho:

    1. Pair ka second node find karo
    2. 2 nodes reverse karo
    3. Previous pair se connect karo

Important pointers:

    right->next = nextleft

    prevleft->next = right

Aur first pair ke liye:

    res = right


-------------------------------------------------------
Complexity
-------------------------------------------------------

Time Complexity:
O(n)

Har node ko maximum ek baar process kar rahe hain.


Space Complexity:
O(1)

Sirf pointers use kar rahe hain.
Koi extra data structure nahi use kar rahe.


-------------------------------------------------------
Pattern Connection
-------------------------------------------------------

Ye In-Place Linked List Reversal pattern ka
extension hai.

LC 206:
    Puri linked list reverse

LC 92:
    Given range reverse

LC 24:
    Har 2 nodes ka group reverse

Core idea same hai:

    Existing nodes ke links ko change karke
    in-place reversal perform karna.


-------------------------------------------------------





  class Solution {
public:

    // head se start karke 'times' nodes ko reverse karega
    void reverse(ListNode* head, int times) {

        // Current node ko head se start karenge
        ListNode* curr = head;

        // Initially previous node NULL hai
        ListNode* prev = NULL;

        // Sirf 'times' nodes reverse karne hain
        while(times--) {

            // Next node ko save kar rahe hain
            // kyunki curr->next ko change karne wale hain
            ListNode* nex = curr->next;

            // Current node ka direction reverse kar rahe hain
            curr->next = prev;

            // Previous ko current par move kar do
            prev = curr;

            // Current ko next node par move kar do
            curr = nex;
        }
    }


    ListNode* swapPairs(ListNode* head) {

        // Empty list hai to kuch swap nahi karna
        if(head == NULL)
            return NULL;


        // Current pair ka first node
        ListNode* left = head;

        // Current pair ka second node
        ListNode* right;

        // Final answer ka head store karega
        ListNode* res = NULL;

        // Previous reversed pair ke last node ko track karega
        ListNode* prevleft = NULL;

        // Ek time par 2 nodes process karne hain
        int size = 2;


        // Jab tak pairs milte rahenge
        while(true) {

            // right ko current pair ke first node se start karo
            right = left;


            // right ko ek step aage move karo
            // taaki pair ka second node mil sake
            for(int i = 0; i < size - 1; i++) {

                // Agar right NULL ho gaya,
                // to complete pair available nahi hai
                if(right == NULL)
                    break;

                right = right->next;
            }


            // Agar right exist karta hai,
            // matlab complete pair mil gaya
            if(right) {

                // Reversal se pehle next pair ka first node save kar lo
                ListNode* nextleft = right->next;


                // Current 2 nodes ko reverse karo
                //
                // Example:
                // 1 -> 2
                //
                // becomes:
                // 2 -> 1
                reverse(left, size);


                // Agar previous pair already reverse ho chuka hai,
                // to usko current pair ke head se connect karo
                if(prevleft)
                    prevleft->next = right;


                // Reverse ke baad left current pair ka last node hai
                // ise next iteration ke liye previous node maanenge
                prevleft = left;


                // Sirf first pair ke baad result ka head set hoga
                if(res == NULL)
                    res = right;


                // Next pair ke first node par move karo
                left = nextleft;
            }


            // Complete pair nahi mila
            else {

                // Agar previous pair exist karta hai,
                // to bache hue single node ko usse connect karo
                if(prevleft)
                    prevleft->next = left;


                // Agar list me starting se hi single node tha
                // to wahi result hoga
                if(res == NULL)
                    res = left;


                // Processing complete
                break;
            }
        }


        // Swapped linked list ka head return karo
        return res;
    }
};
  
