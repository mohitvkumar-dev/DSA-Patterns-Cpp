
Problem    : Binary Search
Platform   : LeetCode
Problem No.: 704
Pattern    : Binary Search
Difficulty : Easy

-------------------------------------------------------
Question
-------------------------------------------------------

Humein ek sorted array nums diya gaya hai aur ek target
value di gayi hai.

Humein target ka index return karna hai.

Agar target array mein present nahi hai to -1 return
karna hai.

Example:

nums = [-1,0,3,5,9,12]
target = 9

Answer = 4


-------------------------------------------------------
Intuition
-------------------------------------------------------

Binary Search ka basic idea hai ki hum target ko directly
search karne ke bajay mid ko ek guess ki tarah use karte hain.

Hum mid ko isliye choose karte hain kyuki har iteration
mein hum search space ko almost half kar dete hain.

Is wajah se target bahut kam iterations mein mil sakta hai.


-------------------------------------------------------
Approach
-------------------------------------------------------

1. low aur high

Hum low aur high isliye lete hain kyuki ye hamara
current search/guess space batate hain.

low  -> search space ka starting index
high -> search space ka ending index

Initially:

low = 0
high = n - 1


2. While Loop

Hum tab tak search karenge jab tak search space mein
koi element available hai:

while (low <= high)

low <= high isliye kyuki jab low == high ho tab bhi
ek element check karna baaki ho sakta hai.


3. Mid Find Karna

Search space ke beech ka element choose karenge:

mid = low + (high - low) / 2

mid hamara current guess hai ki shayad target yahin ho.


4. Target mil gaya

Agar:

nums[mid] == target

to target mil gaya.

Isliye:

return mid;


5. nums[mid] < target

Agar:

nums[mid] < target

to target mid ke right side mein hoga, kyuki array
sorted hai.

mid ke left wale elements aur bhi chhote honge,
isliye unhe check karne ki zarurat nahi hai.

Isliye:

low = mid + 1

Hum left half ko reject kar dete hain.


6. nums[mid] > target

Agar:

nums[mid] > target

to target mid ke left side mein hoga.

mid ke right wale elements aur bhi bade honge,
isliye unhe check karne ki zarurat nahi hai.

Isliye:

high = mid - 1

Hum right half ko reject kar dete hain.


7. Repeat

Har iteration mein:

Guess -> Compare -> Ek half reject -> Search space half

Ye process tab tak chalega jab tak:

- target mil jaye
- ya search space completely khatam ho jaye.


-------------------------------------------------------
Why Does It Work?
-------------------------------------------------------

Array sorted hai.

Isliye agar nums[mid] < target hai, to mid ke
left mein target ho hi nahi sakta.

Similarly, agar nums[mid] > target hai, to mid ke
right mein target ho hi nahi sakta.

Isliye har comparison ke baad ek complete half ko
safely reject kar sakte hain.


-------------------------------------------------------
Algorithm
-------------------------------------------------------

1. low = 0 set karo.
2. high = n - 1 set karo.
3. Jab tak low <= high:
   a. mid calculate karo.
   b. Agar nums[mid] == target:
      return mid.
   c. Agar nums[mid] < target:
      low = mid + 1.
   d. Agar nums[mid] > target:
      high = mid - 1.
4. Agar loop khatam ho jaye:
   return -1.


-------------------------------------------------------
Complexity
-------------------------------------------------------

Time Complexity  : O(log n)

Har iteration mein search space approximately half
ho jaata hai.

Space Complexity : O(1)

Hum sirf low, high aur mid jaise variables use kar rahe hain.


-------------------------------------------------------
Core Idea
-------------------------------------------------------

Binary Search mein mid ek guess hota hai.

Comparison ke basis par hum decide karte hain ki
left half reject karna hai ya right half.

Is tarah:

Guess -> Compare -> Half Reject -> Repeat

Har iteration mein search space half hota jaata hai.


-------------------------------------------------------
Important Condition
-------------------------------------------------------

Binary Search ke liye array ka SORTED hona zaroori hai.

Agar array sorted nahi hai to:

nums[mid] < target

ke basis par ye decide nahi kar sakte ki target
left mein hai ya right mein.


-------------------------------------------------------



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int low= 0;
        int high= n -1;

        while  (low<=high){
            int mid = low+ (high-low)/2;

            if(nums[mid]==target){
               return mid;
            }
           
            else if(nums[mid]<target){
                low = mid+1;
            }else{
                high= mid-1;
            }

        }
        return -1;
    }
};
