
Problem    : Find First and Last Position of Element
             in Sorted Array
Platform   : LeetCode
Problem No.: 34
Pattern    : Binary Search
Difficulty : Medium

-------------------------------------------------------
Question
-------------------------------------------------------

Hame target ki first occurrence aur last occurrence
find karni hai.

Normal binary search mein target milte hi return kar
dete hain, lekin yahan target milne ke baad bhi search
continue karni hai.


-------------------------------------------------------
First Occurrence
-------------------------------------------------------

guess ko middle element ki tarah use karenge.

Agar:

nums[guess] < target

to target right side mein hoga.

Isliye:

low = guess + 1


Agar:

nums[guess] > target

to target left side mein hoga.

Isliye:

high = guess - 1


Agar:

nums[guess] == target

to target mil gaya.

Isliye:

res = guess

mein store kar lenge.

Lekin ho sakta hai target isse pehle bhi present ho.

Isliye left side check karenge:

high = guess - 1


Finally res first occurrence dega.


-------------------------------------------------------
Last Occurrence
-------------------------------------------------------

Last occurrence ke liye comparison same rahega.

Agar:

nums[guess] < target

to:

low = guess + 1


Agar:

nums[guess] > target

to:

high = guess - 1


Agar:

nums[guess] == target

to:

res = guess

mein store karenge.

Lekin ho sakta hai target iske baad bhi present ho.

Isliye right side check karenge:

low = guess + 1


Finally res last occurrence dega.


-------------------------------------------------------
Main Function
-------------------------------------------------------

Dono binary searches ko call karenge:

return {first(nums, target), last(nums, target)};


first() -> first occurrence find karega.

last() -> last occurrence find karega.


-------------------------------------------------------
Core Idea
-------------------------------------------------------

First occurrence:

target mile
    -> answer store karo
    -> LEFT jao

high = guess - 1


Last occurrence:

target mile
    -> answer store karo
    -> RIGHT jao

low = guess + 1


Is tarah ek binary search se first occurrence aur
doosri binary search se last occurrence efficiently
find karte hain.


-------------------------------------------------------
Important Difference
-------------------------------------------------------

Normal Binary Search:

target mil gaya
    -> immediately return


First Occurrence:

target mila
    -> res = guess
    -> left search karo


Last Occurrence:

target mila
    -> res = guess
    -> right search karo


-------------------------------------------------------
Time Complexity
-------------------------------------------------------

First occurrence -> O(log n)

Last occurrence  -> O(log n)

Total:

O(log n) + O(log n)
= O(log n)


Extra Space:

O(1)

(Result array ko chhodkar)


-----------------------------------------------------



class Solution {
public:
int first(vector<int>& nums, int target){
int low=0 ;
int high=nums.size()-1;
int res=-1;
while(low<=high){
    int guess= low+(high-low)/2;
    if(nums[guess]<target){
        low=guess+1;
    }else if(nums[guess]>target){
        high=guess-1;
    }else{
        res=guess;
        high=guess-1;
    }

}
return res;
}

int last(vector<int>& nums, int target){
int low=0 ;
int high=nums.size()-1;
int res=-1;
while(low<=high){
    int guess= low+(high-low)/2;
    if(nums[guess]<target){
        low=guess+1;
    }else if(nums[guess]>target){
        high=guess-1;
    }else{
        res=guess;
        low=guess+1;
    }

}
return res;
}
 
    vector<int> searchRange(vector<int>& nums, int target) {
        return{first(nums,target),last(nums,target)};
    }
};
