
Problem    : Kth Smallest Element in a Sorted Matrix 
Platform   : LeetCode 
Problem No.: 378 
Pattern    : Binary Search on Answer 
Difficulty : Medium 
 
------------------------------------------------------- 
Question 
------------------------------------------------------- 
 
Hame ek n × n matrix di gayi hai. 
 
Matrix ki property: 
 
- Har row ascending order mein sorted hai. 
- Har column ascending order mein sorted hai. 
 
Hame matrix ka Kth smallest element find karna hai. 
 
Example: 
 
1   5   9 
10  11  13 
12  13  15 
 
Agar: 
 
k = 8 
 
Sorted order: 
 
1  5  9  10  11  12  13  13  15 
 
8th smallest element = 13 
 
 
------------------------------------------------------- 
Intuition 
------------------------------------------------------- 
 
Hame directly Kth smallest element ko search nahi 
karna hai. 
 
Hum ANSWER ki value range par Binary Search karenge. 
 
Matrix mein: 
 
Smallest element = matrix[0][0] 
 
Largest element = matrix[n-1][n-1] 
 
Therefore possible answer ka range: 
 
[smallest element ---------------- largest element] 
 
 
Har iteration mein ek possible answer ko GUESS 
maanenge: 
 
guess = low + (high - low) / 2 
 
 
Ab check karenge ki matrix mein GUESS se 
less than or equal kitne elements hain. 
 
Agar count < k hai: 
 
Kth smallest element guess se bada hoga. 
 
Agar count >= k hai: 
 
Kth smallest element guess ya guess se chhota 
ho sakta hai. 
 
 
------------------------------------------------------- 
Approach 
------------------------------------------------------- 
 
Step 1 — Binary Search on Answer 
 
Initially: 
 
low = matrix[0][0] 
 
high = matrix[n-1][n-1] 
 
 
Har iteration mein: 
 
guess = low + (high - low) / 2 
 
 
Ab guess ke liye count find karenge. 
 
 
------------------------------------------------------- 
Step 2 — Count elements <= guess 
------------------------------------------------------- 
 
Har element ko traverse karna inefficient hoga. 
 
Matrix ki rows aur columns sorted hain, isliye 
BOTTOM-LEFT corner se staircase search karenge. 
 
Example: 
 
1   5   9 
10  11  13 
12  13  15 
↑ 
start 
 
 
Initially: 
 
r = n - 1 
c = 0 
 
 
------------------------------------------------------- 
Case 1 — matrix[r][c] <= guess 
------------------------------------------------------- 
 
Agar: 
 
matrix[r][c] <= guess 
 
to current column mein r + 1 elements bhi 
guess se less than or equal honge. 
 
Kyunki column sorted hai. 
 
Therefore: 
 
count += r + 1 
c++ 
 
 
Right move karenge. 
 
 
------------------------------------------------------- 
Case 2 — matrix[r][c] > guess 
------------------------------------------------------- 
 
Agar: 
 
matrix[r][c] > guess 
 
to current element ke neeche ke elements bhi 
guess se bade honge. 
 
Isliye neeche search karne ka koi fayda nahi. 
 
Upar move karenge: 
 
r-- 
 
 
------------------------------------------------------- 
Step 3 — Binary Search Decision 
------------------------------------------------------- 
 
Ab count mil gaya: 
 
Matrix mein guess se less than or equal 
kitne elements hain. 
 
 
------------------------------------------------------- 
Case 1 — count < k 
------------------------------------------------------- 
 
Agar: 
 
count < k 
 
to guess tak k elements available nahi hain. 
 
Matlab Kth smallest element guess se BADA hoga. 
 
Therefore: 
 
low = guess + 1 
 
 
Right side mein search karenge. 
 
 
------------------------------------------------------- 
Case 2 — count >= k 
------------------------------------------------------- 
 
Agar: 
 
count >= k 
 
to Kth smallest element guess ya usse chhota 
ho sakta hai. 
 
Isliye current guess ko possible answer 
maanenge: 
 
res = guess 
 
 
Aur minimum valid answer find karne ke liye 
left side mein search karenge: 
 
high = guess - 1 
 
 
Finally res mein smallest valid guess store rahega. 
 
 
------------------------------------------------------- 
Key Intuition 
------------------------------------------------------- 
 
count < k 
 
    ↓ 
 
Kth smallest > guess 
 
    ↓ 
 
low = guess + 1 
 
 
count >= k 
 
    ↓ 
 
Kth smallest <= guess 
 
    ↓ 
 
guess possible answer 
 
    ↓ 
 
res = guess 
 
high = guess - 1 
 
 
------------------------------------------------------- 
Why Binary Search Works? 
------------------------------------------------------- 
 
Guess badhne par matrix mein guess se less than 
or equal elements ki count kabhi decrease nahi hoti. 
 
Small guess: 
 
fewer elements <= guess 
 
 
Large guess: 
 
more elements <= guess 
 
 
Therefore monotonic pattern: 
 
count < k | count >= k 
 
   X X X  |  Y Y Y 
            ↑ 
      minimum valid guess 
 
 
Hame isi MINIMUM VALID VALUE ko find karna hai. 
 
Isliye Binary Search on Answer use kar sakte hain. 
 
 
------------------------------------------------------- 
Complete Flow 
------------------------------------------------------- 
 
1. low = matrix[0][0] 
 
2. high = matrix[n-1][n-1] 
 
3. guess calculate karo. 
 
4. Bottom-left corner se count karo: 
 
   Kitne elements <= guess hain? 
 
5. Agar: 
 
   count < k 
 
   to: 
 
   low = guess + 1 
 
6. Otherwise: 
 
   res = guess 
   high = guess - 1 
 
7. Loop khatam hone ke baad: 
 
   return res 
 
 
------------------------------------------------------- 
Why Bottom-Left? 
------------------------------------------------------- 
 
Bottom-left se start karne par dono directions 
useful hain. 
 
Agar: 
 
matrix[r][c] <= guess 
 
to: 
 
right move 
 
Kyunki current column ke upar ke elements bhi 
valid hain. 
 
 
Agar: 
 
matrix[r][c] > guess 
 
to: 
 
up move 
 
Kyunki current column ke neeche ke elements 
bhi guess se bade honge. 
 
 
Har step mein ek row ya column eliminate hota hai. 
 
Isliye count efficiently find ho jata hai. 
 
 
------------------------------------------------------- 
Algorithm 
------------------------------------------------------- 
 
1. low = matrix[0][0] set karo. 
2. high = matrix[n-1][n-1] set karo. 
3. res = -1 set karo. 
4. Jab tak low <= high: 
   
   a. guess calculate karo. 
   
   b. Bottom-left se count karo ki 
      kitne elements <= guess hain. 
   
   c. Agar count < k: 
      low = guess + 1 
   
   d. Otherwise: 
      res = guess 
      high = guess - 1 
 
5. res return karo. 
 
 
------------------------------------------------------- 
Complexity 
------------------------------------------------------- 
 
Har guess par bottom-left staircase traversal: 
 
O(n) 
 
 
Possible values par Binary Search: 
 
O(log(maxElement - minElement)) 
 
 
Therefore: 
 
Time Complexity: 
 
O(n × log(maxElement - minElement)) 
 
 
Space Complexity: 
 
O(1) 
 
 
------------------------------------------------------- 
Core Intuition 
------------------------------------------------------- 
 
> Matrix ki value range par Binary Search karo. 
> Har guess ke liye bottom-left se efficiently 
> count karo ki kitne elements guess se less than 
> or equal hain. Agar count k se kam hai to answer 
> right mein hai, aur agar count k ya usse zyada 
> hai to current guess possible answer hai aur 
> minimum valid answer ke liye left mein search karo. 
 
 
------------------------------------------------------- 



class Solution {
public:

    int fun(vector<vector<int>>&matrix ,int n, int m , int guess ){
        int r= n-1 ;
        int c=0;
        int count =0;
        while(r>=0 && c<m){
            if(matrix[r][c]<= guess){
                 count += r +1;
                c++;
            }else{
                r--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        int m=matrix[0].size();
        int res=-1;
        int low= matrix[0][0];
        int high= matrix[n-1][m-1];

        while(low<=high){
            int guess = low+(high-low)/2;
            int ans=fun(matrix , n , m , guess);

            if(ans<k){
                
                low= guess+1;
                
            }else{
                res = guess;
                high= guess-1;
            }
        }
        return res;
    }
};
