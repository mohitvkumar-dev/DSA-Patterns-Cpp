
Problem    : Allocate Minimum Pages
Platform   : GeeksforGeeks
Pattern    : Binary Search on Answer
Difficulty : Medium

-------------------------------------------------------
Question kya keh raha hai?
-------------------------------------------------------

Hame n books di gayi hain aur har book mein kuch
pages hain.

Example:

arr = [12, 34, 67, 90]

Hame books ko k students mein allocate karna hai.

Conditions:

1. Har student ko CONTIGUOUS books milengi.
2. Har book exactly ek student ko milegi.
3. Hame aisa allocation karna hai ki kisi bhi
   student ko milne wale pages ka maximum value
   MINIMUM possible ho.

Example:

arr = [12, 34, 67, 90]
k = 2


Ek possible allocation:

Student 1:

12 + 34 + 67 = 113 pages

Student 2:

90 pages


Maximum pages assigned to one student:

max(113, 90) = 113


Hame aisa allocation find karna hai jisme ye
maximum pages MINIMUM possible ho.


-------------------------------------------------------
Intuition
-------------------------------------------------------

Directly books ko different students mein allocate
karke minimum answer find karna difficult hai.

Isliye hum directly allocation try nahi karenge.

Hum ANSWER ko guess karenge.

Yahan answer kya hai?

Maximum pages that any one student can get.


Maan lo:

guess = 113


Ab question ban jayega:

"Kya saari books ko k students mein is tarah
allocate kar sakte hain ki kisi bhi student ko
113 se zyada pages na mile?"


Agar YES:

113 possible answer hai.

Lekin ho sakta hai isse chhoti page limit bhi
possible ho.


Agar NO:

113 bahut chhota hai.

Hame page limit increase karni padegi.


-------------------------------------------------------
Important Observation
-------------------------------------------------------

Hame maximum pages per student ko minimize karna hai.

Possible answer ki range kya hogi?


Minimum possible answer:

MAXIMUM SINGLE BOOK


Example:

arr = [12, 34, 67, 90]

Sabse badi book:

90


Kisi student ko 90 pages wali book milni hi hai.

Isliye maximum pages per student 90 se kam
nahi ho sakte.


Therefore:

low = max(arr)


-------------------------------------------------------
Maximum Possible Answer
-------------------------------------------------------

Agar saari books ek hi student ko de dein:

12 + 34 + 67 + 90
= 203


Therefore maximum possible answer:

sum(arr)


So:

low = max(arr)
high = sum(arr)


Search space:

90 ---------------------- 203
↑                         ↑
low                       high


Hum ARRAY KE INDEX par Binary Search nahi kar rahe.

Hum POSSIBLE ANSWERS ke range mein Binary Search
kar rahe hain.


-------------------------------------------------------
Why Binary Search?
-------------------------------------------------------

Har guessed page limit ke liye hum check kar sakte
hain ki books ko students mein allocate karna
possible hai ya nahi.


Is feasibility ka MONOTONIC pattern hota hai.


Example:

Maximum pages allowed:

90  100  110  120  130  140  150
 X    X    X    Y    Y    Y    Y
             ↑
       minimum feasible


Agar 120 pages per student allowed hain aur
allocation possible hai, to 130, 140, 150 bhi
possible honge.


Aur agar 120 possible nahi hai, to usse chhoti
limits bhi possible nahi hongi.


Therefore:

NOT FEASIBLE -> RIGHT jao

FEASIBLE -> LEFT jao


Hame FIRST/MINIMUM FEASIBLE answer find karna hai.


-------------------------------------------------------
Intuition of Binary Search
-------------------------------------------------------

Har iteration mein:

guess = low + (high - low) / 2


nikalenge.

Ye guess ek possible maximum page limit hoga.


Ab check karenge:

"Kya guess maximum pages per student rakhkar
books ko k students mein allocate kar sakte hain?"


Is check ke liye:

fun()

function use karenge.


-------------------------------------------------------
Feasibility Function — fun()
-------------------------------------------------------

fun() ka main kaam hai:

Given maximum allowed pages = guess


check karo ki books ko CONTIGUOUS order mein
allocate karke kitne students required honge.


Initially:

stu = 1
pages = 0


Matlab first student ko books dena start karenge.


-------------------------------------------------------
Books ko Allocate Kaise Karenge?
-------------------------------------------------------

Array ko left to right traverse karenge.


Har book ke liye:

pages + arr[i]


check karenge.


-------------------------------------------------------
Case 1 — Current book same student ko de sakte hain
-------------------------------------------------------

Agar:

pages + arr[i] <= guess


to current book current student ko de sakte hain.


Therefore:

pages += arr[i]


Example:

guess = 100

Current student ke paas:

pages = 34


Next book:

67


34 + 67 = 101


101 > 100


To ye book current student ko nahi de sakte.


Lekin agar:

34 + 60 = 94


hota, to same student ko de sakte the.


-------------------------------------------------------
Case 2 — Current book dene par limit cross ho jayegi
-------------------------------------------------------

Agar:

pages + arr[i] > guess


to current student ko ye book nahi de sakte.


New student start karenge:


stu++

pages = arr[i]


Matlab current book new student ki first book
ban jayegi.


-------------------------------------------------------
Example of Allocation
-------------------------------------------------------

arr = [12, 34, 67, 90]

guess = 113


Initially:

stu = 1
pages = 0


Book 12:

0 + 12 <= 113

Student 1:

pages = 12


Book 34:

12 + 34 = 46 <= 113

Student 1:

pages = 46


Book 67:

46 + 67 = 113 <= 113

Student 1:

pages = 113


Book 90:

113 + 90 > 113


New student:

stu = 2
pages = 90


Total students required:

2


Agar:

k = 2


to guess = 113 FEASIBLE hai.


-------------------------------------------------------
Feasibility kaise decide hogi?
-------------------------------------------------------

Books traverse karte waqt agar:

stu > k


ho gaya, to required students allowed
students se zyada ho gaye.


Therefore:

guess FEASIBLE nahi hai.


return false


Agar complete array traverse karne ke baad:

stu <= k


hai, to allocation possible hai.


Therefore:

guess FEASIBLE hai.


return true


-------------------------------------------------------
Important Point — Contiguous Books
-------------------------------------------------------

Books ko arbitrary order mein distribute nahi
kar sakte.


Example:

arr = [12, 34, 67, 90]


Valid allocation:

Student 1:

12 34


Student 2:

67 90


Ye CONTIGUOUS hai.


Lekin:

Student 1:

12 67


Student 2:

34 90


valid nahi hai.


Isliye hum books ko array ke given order mein
left to right allocate karte hain.


-------------------------------------------------------
Binary Search Logic
-------------------------------------------------------

Ab har guess ke liye fun() call karenge.


-------------------------------------------------------
Case 1 — guess FEASIBLE hai
-------------------------------------------------------

Agar:

fun(...) == true


matlab guess maximum page limit rakhkar
books allocate ho sakti hain.


Lekin hame:

MINIMUM possible maximum pages


chahiye.


Ho sakta hai isse bhi chhoti page limit possible ho.


Therefore:

res = guess

Aur LEFT side search karenge:

high = guess - 1


Meaning:

Current answer valid hai,
ab smaller answer try karo.


-------------------------------------------------------
Case 2 — guess FEASIBLE nahi hai
-------------------------------------------------------

Agar:

fun(...) == false


matlab guess page limit bahut chhoti hai.


Itni page limit mein books ko k students
mein allocate nahi kar pa rahe.


Therefore page limit increase karni padegi.


So:

low = guess + 1


Meaning:

Current guess aur usse smaller limits reject
kar do.


-------------------------------------------------------
Why res?
-------------------------------------------------------

Hame MINIMUM FEASIBLE page limit chahiye.


Example:

Maximum pages:

90  100  110  120  130  140
 X    X    X    Y    Y    Y
             ↑
       minimum feasible


Jab bhi feasible answer mile:

res = guess


kar denge.


Phir aur chhota feasible answer find karne ke
liye:

high = guess - 1


Finally:

res

minimum feasible maximum page limit dega.


-------------------------------------------------------
Complete Flow
-------------------------------------------------------

1. Agar:

   number of books < number of students

   to allocation possible nahi hai.

   return -1


2. Maximum single book find karo.


3. Total pages calculate karo.


4. Search space:

   low = max(arr)
   high = sum(arr)


5. guess calculate karo:

   guess = low + (high - low) / 2


6. fun() se check karo:

   Kya guess maximum pages per student rakhkar
   books ko k students mein allocate kar sakte hain?


7. Agar FEASIBLE:

   res = guess
   high = guess - 1

   Meaning:
   smaller page limit try karo.


8. Agar NOT FEASIBLE:

   low = guess + 1

   Meaning:
   page limit increase karo.


9. Search khatam hone ke baad:

   return res

-------------------------------------------------------
Why Greedy Allocation Works?
-------------------------------------------------------

fun() mein hum current student ko maximum possible
contiguous books de rahe hain jab tak page limit
cross nahi hoti.


Example:

guess = 113


Student 1:

12 + 34 + 67 = 113


Ab 90 add nahi kar sakte.


To next student start karenge.


Ye greedy approach minimum number of students
required find karne ke liye use hoti hai.


Agar greedy allocation mein bhi k se zyada
students lag rahe hain, to guess limit ke andar
k students mein allocation possible nahi hoga.


-------------------------------------------------------
Why Sorting Nahi Karni?
-------------------------------------------------------

Yahan sorting nahi karenge.


Kyunki books ko CONTIGUOUS order mein allocate
karna hai.


Agar array ko sort kar diya to original book order
change ho jayega aur contiguous allocation ki
condition break ho sakti hai.


Therefore:

Sorting ki zarurat nahi hai.


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. Agar n < k:

   return -1


2. Maximum book pages find karo.


3. Total pages find karo.


4. low = maximum book pages


5. high = total pages


6. res = -1


7. Jab tak:

   low <= high


   a. guess calculate karo.


   b. guess maximum page limit par
      required students calculate/check karo.


   c. Agar feasible:

      res = guess
      high = guess - 1


   d. Otherwise:

      low = guess + 1


8. res return karo.


-------------------------------------------------------
Complexity
-------------------------------------------------------

Let:

n = number of books

S = total number of pages


Har guess par poore books traverse karne padte hain:

O(n)


Possible answer range:

max(arr) ... sum(arr)


Binary Search:

O(log S)


Therefore:


Time Complexity:

O(n log S)


Space Complexity:

O(1)


Sorting nahi hai, isliye O(n log n) sorting
complexity add nahi hogi.


-------------------------------------------------------
Core Pattern
-------------------------------------------------------

Ye normal Binary Search nahi hai.


Hum array ke index par Binary Search nahi
kar rahe.


Hum ANSWER SPACE par Binary Search kar rahe hain.


Answer:

Maximum pages assigned to one student


Search space:

max(arr) ... sum(arr)


Har guess:

"Kya ye maximum page limit valid hai?"


NO:

students > k

-> limit badhao
-> RIGHT

low = guess + 1


YES:

students <= k

-> answer store karo
-> smaller limit try karo
-> LEFT

res = guess
high = guess - 1


-------------------------------------------------------
Revision Trick
-------------------------------------------------------

Binary Search on Answer:


GUESS = maximum pages allowed per student


Then:


NOT FEASIBLE:

students > k

-> RIGHT
-> page limit increase

low = guess + 1


FEASIBLE:

students <= k

-> STORE
-> LEFT
-> smaller page limit check

res = guess
high = guess - 1


One line:

> NO -> limit increase
> YES -> answer store + smaller limit check


-------------------------------------------------------
One-Line Intuition
-------------------------------------------------------

Maximum pages per student ko answer maan kar
Binary Search karo.

Har guessed limit ke liye greedily check karo
ki books ko contiguous order mein k students
mein allocate kiya ja sakta hai ya nahi.

Agar possible hai:

-> answer store karo
-> smaller limit try karo.

Agar possible nahi hai:

-> limit increase karo.


-------------------------------------------------------
Pattern Connection
-------------------------------------------------------

LC 875 — Koko Eating Bananas:

Minimum valid answer

YES -> LEFT
NO  -> RIGHT


GFG — Aggressive Cows:

Maximum valid answer

YES -> RIGHT
NO  -> LEFT


GFG — Allocate Minimum Pages:

Minimum valid answer

YES -> LEFT
NO  -> RIGHT


Common Pattern:

BINARY SEARCH ON ANSWER

------------------------------------------------------------

class Solution {
public:

    bool fun(vector<int>& arr, int n, long long guess, int k) {

        int stu = 1;
        long long pages = 0;

        for(int i = 0; i < n; i++) {

            if(pages + arr[i] <= guess) {
                pages += arr[i];
            }
            else {
                stu++;
                pages = arr[i];

                if(stu > k) {
                    return false;
                }
            }
        }

        return true;
    }

    int findPages(vector<int> &arr, int k) {

        int n = arr.size();

        if(n < k) {
            return -1;
        }

        long long low = 0;
        long long high = 0;

        for(int i = 0; i < n; i++) {

            low = max(low, (long long)arr[i]);

            high += arr[i];
        }

        long long res = -1;

        while(low <= high) {

            long long guess = low + (high - low) / 2;

            if(fun(arr, n, guess, k)) {

                res = guess;
                high = guess - 1;
            }
            else {
                low = guess + 1;
            }
        }

        return (int)res;  //res jo long long type ka hai, usko int mein convert karke return karo.
    }
};



// (long long)arr[i] → int ko long long mein convert karna
