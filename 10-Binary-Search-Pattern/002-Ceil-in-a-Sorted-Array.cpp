
Problem    : Ceil in a Sorted Array
Platform   : GeeksforGeeks
Pattern    : Binary Search
Difficulty : Easy

-------------------------------------------------------
Question
-------------------------------------------------------

Hame ek sorted array arr aur ek value x di gayi hai.

Hame array ka CEIL find karna hai.

Ceil ka matlab:

Smallest element jo x se greater than or equal ho.

In other words:

arr[i] >= x

aur in sab valid elements mein se sabse chhota
element return karna hai.

Agar koi aisa element present nahi hai to -1 return
karna hai.


Example:

arr = [1, 2, 4, 6, 8, 10]
x = 5

Greater than or equal elements:

6, 8, 10

Smallest = 6

Answer = 6


-------------------------------------------------------
Intuition
-------------------------------------------------------

Array sorted hai, isliye hum Binary Search ka use
kar sakte hain.

Hame smallest element find karna hai jo x se
greater than or equal ho.

Hum mid index ke element ko ek GUESS maanenge:

guess = low + (high - low) / 2

Phir arr[guess] ko x se compare karenge.

Comparison ke basis par decide karenge ki
left jana hai ya right.


-------------------------------------------------------
Approach
-------------------------------------------------------

1. low aur high

Sabse pehle low aur high se apna current
search/guess space define karenge.

low  -> starting index
high -> ending index

Initially:

low = 0
high = n - 1


2. Result

Hame abhi tak koi valid ceil nahi mila hai.

Isliye:

res = -1

rakhenge.

Jab bhi koi valid element milega, usse res mein
store karenge.


3. Guess Find Karna

Search space ke beech ka index nikalenge:

guess = low + (high - low) / 2

Ab arr[guess] hamara current guess hai.


-------------------------------------------------------
Case 1: arr[guess] < x
-------------------------------------------------------

Agar:

arr[guess] < x

to arr[guess] x se chhota hai.

Isliye ye CEIL nahi ho sakta.

Aur kyuki array sorted hai, guess ke left mein
jo elements hain wo bhi arr[guess] se chhote
ya equal honge.

Isliye left side ka koi element bhi x ka ceil
nahi ho sakta.

Hame right side jaana hoga:

low = guess + 1


-------------------------------------------------------
Case 2: arr[guess] >= x
-------------------------------------------------------

Agar:

arr[guess] >= x

to hame ek VALID CEIL mil gaya.

Isliye:

res = arr[guess]

Lekin hame koi bhi valid element nahi chahiye.

Hame SMALLEST greater than or equal element chahiye.

Ho sakta hai guess ke left side mein isse bhi
chhota valid element present ho.

Isliye:

high = guess - 1

Karke left side search karenge.


-------------------------------------------------------
Repeat
-------------------------------------------------------

Ye process tab tak chalega:

while (low <= high)

Har iteration mein:

arr[guess] < x
    -> invalid
    -> right side jao
    -> low = guess + 1

arr[guess] >= x
    -> possible answer
    -> res mein store karo
    -> smaller answer ke liye left side jao
    -> high = guess - 1



-------------------------------------------------------
Why Does It Work?
-------------------------------------------------------

Case 1:

arr[guess] < x

To arr[guess] valid nahi hai.

Sorted array hone ki wajah se guess ke left ke
elements bhi x se chhote honge.

Isliye left half completely reject kar sakte hain.


Case 2:

arr[guess] >= x

To arr[guess] valid ceil hai.

Lekin ho sakta hai left side mein isse chhota
valid element ho.

Isliye current answer ko store karke left side
search karte hain.

Is process se hum eventually smallest valid
element tak pahunch jaate hain.


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. low = 0 set karo.
2. high = n - 1 set karo.
3. res = -1 set karo.
4. Jab tak low <= high:
   a. guess calculate karo.
   b. Agar arr[guess] < x:
      low = guess + 1.
   c. Otherwise:
      res = arr[guess].
      high = guess - 1.
5. res return karo.


-------------------------------------------------------
Complexity
-------------------------------------------------------

Time Complexity  : O(log n)

Har iteration mein search space approximately
half ho jaata hai.

Space Complexity : O(1)

Sirf low, high, guess aur res variables use
kiye ja rahe hain.


-------------------------------------------------------
Core Idea
-------------------------------------------------------

Ceil = Smallest element >= x

Binary Search mein:

arr[guess] < x
        -> answer nahi ho sakta
        -> RIGHT jao

arr[guess] >= x
        -> possible answer
        -> res mein store karo
        -> LEFT jao
        -> aur chhota valid answer dhoondo



-------------------------------------------------------
Pattern Connection
-------------------------------------------------------

Ye Binary Search Pattern mein ek important variation
hai.

Normal Binary Search mein hame exact target milna
hota hai.

Yahan hame exact target nahi, balki:

SMALLEST element >= x

find karna hai.

Is type ke questions mein:

Possible Answer Store + Left Search

ka pattern bahut important hai.


----------------------------------------------


class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n= arr.size();
        int low=0 ;
        int high= n-1;
        int res=-1;
        
        while(low<=high){
             int guess= low+(high-low)/2;
             
             if(arr[guess]<x){
                 low= guess+1;
             }else{
                 res=guess;
                 high=guess-1;
             }
        }
        return res;
    }
};
