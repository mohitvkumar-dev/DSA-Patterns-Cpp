Problem    : Aggressive Cows
Platform   : GeeksforGeeks
Pattern    : Binary Search on Answer
Difficulty : Medium

-------------------------------------------------------
Question kya keh raha hai?
-------------------------------------------------------

Hame kuch stalls diye gaye hain aur har stall ki
position di hui hai.

Example:

arr = [1, 2, 4, 8, 9]

Hame k cows ko different stalls mein place karna hai.

Condition:

Do cows ke beech ka MINIMUM distance jitna possible
ho utna MAXIMIZE karna hai.

Example:

arr = [1, 2, 4, 8, 9]
k = 3

Agar cows ko:

Cow 1 -> 1
Cow 2 -> 4
Cow 3 -> 8

par place karein:

Distance:

4 - 1 = 3
8 - 4 = 4

Minimum distance:

min(3, 4) = 3

Hame aisa placement find karna hai jisme ye
minimum distance maximum possible ho.

Is example mein answer:

3


-------------------------------------------------------
Intuition
-------------------------------------------------------

Directly cows ko alag-alag stalls par place karke
maximum minimum distance find karna difficult hai.

Isliye hum directly cows ko optimize nahi karenge.

Hum ANSWER ko guess karenge.

Yahan answer kya hai?

Minimum distance between two cows.

To ek possible distance ko:

guess

maan lenge.

Example:

guess = 4

Ab question ban jayega:

"Kya hum k cows ko aise place kar sakte hain ki
har do placed cows ke beech distance kam se kam
4 ho?"

Agar YES:

4 possible answer hai.

Lekin ho sakta hai 4 se bhi bada distance possible ho.

Agar NO:

4 bahut bada distance hai.

Hame distance kam karna padega.


-------------------------------------------------------
Important Observation
-------------------------------------------------------

Possible answer actually distance hai.

Agar stalls:

1 2 4 8 9

hain, to minimum distance:

1 se start ho sakta hai.

Maximum possible distance:

last stall - first stall

= 9 - 1
= 8

Therefore answer search space:

1 ---------------- 8
↑                   ↑
low                high


Yahan hum array ke andar Binary Search nahi kar
rahe.

Hum POSSIBLE ANSWERS ke range mein Binary Search
kar rahe hain.


-------------------------------------------------------
Why Binary Search?
-------------------------------------------------------

Kisi guessed distance ko check karne par do cases
aayenge:

1. Distance FEASIBLE hai.
2. Distance FEASIBLE nahi hai.

Aur inka pattern MONOTONIC hota hai.

Example:

Distance:

1  2  3  4  5  6  7  8

Feasible:

Y  Y  Y  Y  X  X  X  X

Y = k cows place ho sakti hain
X = k cows place nahi ho sakti

Agar koi distance feasible hai, to usse chhota
distance bhi feasible hoga.

Agar koi distance feasible nahi hai, to usse bada
distance bhi feasible nahi hoga.

Therefore:

Feasible -> RIGHT jao
Not feasible -> LEFT jao

Hame maximum feasible distance find karna hai.

Isliye Binary Search on Answer use karenge.


-------------------------------------------------------
Intuition of Binary Search
-------------------------------------------------------

Har iteration mein:

guess = low + (high - low) / 2

nikalenge.

Ye guess ek possible minimum distance hoga.

Ab check karenge:

"Kya guess distance maintain karke k cows
place ho sakti hain?"

Ye check karne ke liye:

fun()

function use karenge.


-------------------------------------------------------
fun() Function ka kaam
-------------------------------------------------------

fun() ka main kaam hai:

Given minimum distance = guess

check karo ki maximum kitni cows place
ki ja sakti hain.

Agar k cows place ho gayi:

guess FEASIBLE hai.

Agar k cows place nahi hui:

guess FEASIBLE nahi hai.


-------------------------------------------------------
fun() mein kya karenge?
-------------------------------------------------------

Sabse pehle stalls ko sort karenge:

sort(arr.begin(), arr.end());

Example:

Original:

8 1 9 4 2

Sorted:

1 2 4 8 9

Sorting isliye important hai kyunki hum stalls ko
left to right traverse karke greedily cows place
karna chahte hain.


-------------------------------------------------------
First Cow
-------------------------------------------------------

Sabse pehle first stall par cow place kar denge.

Example:

1 2 4 8 9
↑
Cow

Isliye:

cow = 1
pos = arr[0]

Yahan:

pos

last placed cow ki position ko represent karega.


-------------------------------------------------------
Baaki Stalls Traverse Karna
-------------------------------------------------------

Ab har next stall ke liye:

dis = arr[i] - pos

calculate karenge.

Ye batayega:

Current stall aur last placed cow ke beech
kitna distance hai.


-------------------------------------------------------
Case 1 — dis < guess
-------------------------------------------------------

Agar:

dis < guess

to current stall par cow place nahi kar sakte.

Example:

guess = 4

Last cow:

1

Current stall:

2

Distance:

2 - 1 = 1

1 < 4

To yahan cow place nahi kar sakte.

Isliye:

continue;


Kyunki hame minimum distance guess maintain
karna hai.


-------------------------------------------------------
Case 2 — dis >= guess
-------------------------------------------------------

Agar:

dis >= guess

to current stall par cow place kar sakte hain.

Example:

guess = 3

Last cow:

1

Current stall:

4

Distance:

4 - 1 = 3

3 >= 3

Therefore cow place kar sakte hain.

So:

cow++

pos = arr[i]


pos ko update karenge kyunki ab next cow ka
distance isi newly placed cow se calculate hoga.


-------------------------------------------------------
Feasibility kaise decide hogi?
-------------------------------------------------------

Poore stalls traverse karne ke baad:

Agar:

cow >= k

to required k cows place ho gayi.

Therefore:

guess FEASIBLE hai.

return true;


Agar:

cow < k

to required cows place nahi ho paayi.

Therefore:

guess FEASIBLE nahi hai.

return false;


-------------------------------------------------------
Binary Search Search Space
-------------------------------------------------------

Possible minimum distance:

low = 1

Maximum possible minimum distance:

high = arr[n-1] - arr[0]

Example:

arr = [1, 2, 4, 8, 9]

low = 1
high = 8


-------------------------------------------------------
Case 1 — guess FEASIBLE hai
-------------------------------------------------------

Agar:

fun(...) == true

matlab guess distance maintain karke
k cows place ho sakti hain.

Example:

guess = 3

3 distance par cows place ho gayi.

Lekin hame:

MAXIMUM minimum distance

chahiye.

Ho sakta hai 3 se bada distance bhi possible ho.

Therefore current answer store karenge:

res = guess

Aur RIGHT side search karenge:

low = guess + 1


Meaning:

Current distance possible hai,
ab aur bada distance try karo.


-------------------------------------------------------
Case 2 — guess FEASIBLE nahi hai
-------------------------------------------------------

Agar:

fun(...) == false

matlab guess distance bahut bada hai.

Itne distance par k cows place nahi ho pa rahi.

Therefore distance decrease karna padega.

So:

high = guess - 1


Meaning:

Current guess aur usse bade distances reject
kar do.


-------------------------------------------------------
Why res?
-------------------------------------------------------

Hame MAXIMUM valid distance chahiye.

Example:

Distance:

1  2  3  4  5  6  7

Valid:

Y  Y  Y  Y  X  X  X
         ↑
   maximum valid


Jab bhi feasible distance mile:

res = guess

kar denge.

Phir right side mein aur bada valid distance
search karenge.

Therefore:

res = guess
low = guess + 1


Finally res maximum feasible distance dega.


-------------------------------------------------------
Complete Flow
-------------------------------------------------------

1. Stalls ko sort karo.

2. Search space define karo:

   low = 1
   high = arr[n-1] - arr[0]

3. guess calculate karo:

   guess = low + (high - low) / 2

4. fun() se check karo:

   Kya guess minimum distance maintain karke
   k cows place ho sakti hain?

5. Agar FEASIBLE:

   res = guess
   low = guess + 1

   Meaning:
   current answer valid hai,
   aur larger distance try karo.

6. Agar NOT FEASIBLE:

   high = guess - 1

   Meaning:
   distance bahut bada hai,
   smaller distance try karo.

7. Search khatam hone ke baad:

   return res

-------------------------------------------------------
Why Greedy Check Works?
-------------------------------------------------------

fun() mein hum cow ko possible earliest stall
par place kar rahe hain.

Example:

guess = 3

Stalls:

1 2 4 8 9

First cow:

1

Next cow ko earliest possible stall:

4

Next cow:

8

Agar hum kisi cow ko unnecessarily aur right
side mein place kar denge, to future cows ke liye
available space kam ho jayega.

Isliye earliest possible valid stall par cow
place karna best hai for checking feasibility.

Ye GREEDY approach hai.


-------------------------------------------------------
Why Sorting?
-------------------------------------------------------

Sorting ke bina stalls random order mein ho sakte
hain.

Example:

8 1 9 2 4

Distance maintain karna aur left-to-right
greedy placement difficult ho jayega.

Sorting ke baad:

1 2 4 8 9

Ab hum sequentially check kar sakte hain:

dis = arr[i] - pos

Therefore feasibility check O(n) mein ho jata hai.


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. arr ko sort karo.

2. low = 1 set karo.

3. high = arr[n-1] - arr[0] set karo.

4. res = -1 set karo.

5. Jab tak:

   low <= high

   a. guess calculate karo.

   b. guess distance par fun() call karo.

   c. Agar feasible hai:

      res = guess
      low = guess + 1

   d. Otherwise:

      high = guess - 1

6. res return karo.


-------------------------------------------------------
Complexity
-------------------------------------------------------

Let:

n = number of stalls

D = arr[n-1] - arr[0]


Sorting:

O(n log n)


Har guess ke liye fun():

O(n)


Possible distances par Binary Search:

O(log D)


Therefore total:

O(n log n + n log D)


Space Complexity:

O(1)

(assuming in-place sorting and ignoring
sorting implementation stack details)


-------------------------------------------------------
Core Pattern
-------------------------------------------------------

Ye problem normal Binary Search nahi hai.

Hum array ke index par Binary Search nahi
kar rahe.

Hum ANSWER SPACE par Binary Search kar rahe hain.


Answer:

Minimum distance


Search space:

1 ... arr[n-1] - arr[0]


Har guess:

"Kya ye minimum distance possible hai?"


YES:

-> current answer valid hai
-> maximum chahiye
-> RIGHT jao

res = guess
low = guess + 1


NO:

-> distance bahut bada hai
-> LEFT jao

high = guess - 1


-------------------------------------------------------
Revision Trick
-------------------------------------------------------

Binary Search on Answer:

GUESS = possible minimum distance


Then:


FEASIBLE:

-> answer store
-> larger answer try

res = guess
low = guess + 1


NOT FEASIBLE:

-> answer too large
-> smaller answer try

high = guess - 1


One line:

> YES -> store + RIGHT
> NO  -> LEFT


-------------------------------------------------------
One-Line Intuition
-------------------------------------------------------

Minimum distance ko answer maan kar Binary Search
karo.

Har guessed distance ke liye greedy check karo
ki us distance ko maintain karke k cows place
ho sakti hain.

Agar possible hai:

-> larger distance try karo.

Agar possible nahi hai:

-> smaller distance try karo.


-------------------------------------------------------


  class Solution {
  public:
  
  bool fun(vector<int>&arr , int n,  int guess , int k){
      int cow =1;
      int pos = arr[0];
      
      for(int i=1 ; i< n ; i++){
         int dis = arr[i]-pos;
         if(dis <guess){
             continue;
         }
         
         cow++;
         pos=arr[i];
      }
      
      if(cow>=k){
          return true;
      }else{
          return false;
      }
      
  }
  
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n= arr.size();
        int low=1;
        int high= arr[n-1]-arr[0];
        int res=-1;
        
        while(low<=high){
            int guess= low+(high-low)/2;
            
            if(fun(arr , n , guess, k)){
                res=guess;
                
                low= guess+1;
            }
            else{
                high= guess-1;
            }
        }
        
        return res;
        
    }
};
