
Problem    : Next Greater Element I
Platform   : LeetCode
Problem No.: 496
Pattern    : Monotonic Stack / Next Greater Element
Difficulty : Easy

Intuition :

Hume nums1 ke har element ka Next Greater Element
nums2 mein find karna hai.

Next Greater Element ka matlab:

Kisi element x ke right side mein jo pehla element
x se greater ho, wahi uska NGE hai.

Example:

nums2 = [1,3,4,2]

    1 → 3
    3 → 4
    4 → -1
    2 → -1

Agar nums1 = [4,1,2]

Answer:

    [ -1,3,-1 ]

-------------------------------------------------------

1. Brute Force Approach

Brute force mein nums1 ke har element ko nums2 mein
search karenge.

Equal element milne ke baad uske right side ko
traverse karenge aur pehla greater element find karenge.

Agar greater element mil gaya:

    res[i] = greater element

Agar nahi mila:

    res[i] = -1

Problem ye hai ki nums2 ko baar-baar traverse
karna pad sakta hai.

Therefore worst case:

    O(n²)

Time Complexity.

-------------------------------------------------------

2. Optimized Approach — Monotonic Stack

Brute force mein same Next Greater Element ko
baar-baar calculate kar rahe hain.

Is repeated work ko avoid karne ke liye hum pehle
nums2 ke HAR element ka NGE calculate kar lenge.

Phir:

    element → NGE

ko hashmap mein store kar denge.

Example:

    nums2 = [1,3,4,2]

Map:

    1 → 3
    3 → 4
    4 → -1
    2 → -1

Ab nums1 ke kisi bhi element ka answer chahiye,
to map se O(1) average time mein mil jayega.

NGE calculate karne ke liye Monotonic Stack use
karoge.

-------------------------------------------------------

Why Right to Left?

Kisi element ka NGE uske RIGHT side mein hota hai.

Isliye right side ki information pehle available
honi chahiye.

Therefore nums2 ko:

    Right → Left

traverse karenge.

-------------------------------------------------------

Stack mein Kya Store Karenge?

Stack mein elements ki values store karenge:

    stack<int> st;

Stack mein sirf useful NGE candidates rahenge.

-------------------------------------------------------

Step 1 — Smaller / Equal Elements Pop Karo

Har current element nums2[i] ke liye:

    while(!st.empty() && st.top() <= nums2[i])
        st.pop();

Kyun?

Agar:

    st.top() <= nums2[i]

to stack ka top current element ka NGE nahi
ho sakta.

Because NGE ko current element se GREATER hona
zaroori hai.

Isliye usse pop kar denge.

-------------------------------------------------------

Step 2 — NGE Find Karo

Pop karne ke baad:

Case 1:

    st.empty()

Matlab current element ke right side mein koi
greater element available nahi hai.

Therefore:

    mp[nums2[i]] = -1;

Case 2:

Stack empty nahi hai.

To:

    st.top() > nums2[i]

Aur stack ka top hi current element ka nearest
greater candidate hai.

Therefore:

    mp[nums2[i]] = st.top();

-------------------------------------------------------

Step 3 — Current Element Push Karo

NGE find karne ke baad:

    st.push(nums2[i]);

Current element future mein left side ke kisi
element ka NGE ho sakta hai. 

  
-------------------------------------------------------

nums1 Se Answer Kaise Nikale?

Ab nums1 ko traverse karenge.

Har element x ke liye:

    res[i] = mp[x];

Example:

nums1:

    [4,1,2]

Map se:

    4 → -1
    1 → 3
    2 → -1

Therefore:

    res = [-1,3,-1]

-------------------------------------------------------

Why Monotonic Stack Works?

Stack mein hum un elements ko hi rakhte hain jo
future/current NGE ke useful candidates ho sakte hain.

Agar koi element current se chhota ya equal hai,
to current element ke liye wo useless hai.

Isliye:

    smaller/equal → pop

Aur pop karne ke baad stack ka top:

    nearest greater element

ban jata hai.

-------------------------------------------------------

Algorithm

1. Empty stack aur hashmap banao.
2. nums2 ko right se left traverse karo.
3. Stack ke smaller/equal elements ko pop karo.
4. Agar stack empty hai:
       map[current] = -1
5. Otherwise:
       map[current] = st.top()
6. Current element ko stack mein push karo.
7. nums1 traverse karo.
8. Har element ka answer hashmap se nikalo.
9. Result return karo.

-------------------------------------------------------

Time Complexity

nums2 traversal:

    O(n)

nums1 traversal:

    O(m)

Har element stack mein maximum ek baar push
aur maximum ek baar pop hota hai.

Therefore overall:

    O(n + m)

Where:

    n = nums2.size()
    m = nums1.size()

-------------------------------------------------------

Space Complexity

Stack:

    O(n)

HashMap:

    O(n)

Result:

    O(m)

Overall:

    O(n + m)

-------------------------------------------------------




class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m= nums2.size();
        int n= nums1.size();
        stack<int>st;
        unordered_map<int,int>mp;

        for(int j=m-1; j>=0 ; j--){
            while(!st.empty() && st.top()<=nums2[j]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[j]]=-1;
            }else{
                mp[nums2[j]]=st.top();
            }
            st.push(nums2[j]);
        }

        vector<int>res(n);
        for(int i=0 ; i<n ; i++){
            res[i]=mp[nums1[i]];
        }
        return res ;
    }
};


