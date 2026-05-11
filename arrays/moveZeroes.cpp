#include <bits/stdc++.h>
using namespace std;
// approach number one: Brute force Time Complexity--->O(n^2) &&& Space complexity--->O(1)
//  void moveZeroes(vector<int>& nums) {
//      int count=0; int i=0;
//      while(i<nums.size()-count){
//          if(nums[i]!=0){i++;}
//          else{for(int j=i; j<nums.size()-1; j++){
//              nums[j]=nums[j+1];
//          }count++;}
//      }

//         for(int i=nums.size()-count; i<nums.size(); i++){
//             nums[i]=0;
//         }
//     }
// Brute force Time complexity--->O(n^2) and Space complexity is---->O(1)
// void moveZeroes(vector<int>& nums){
//     int count=0; int i=0;
//     while(i<nums.size()){
//         if(nums[i]==0){nums.erase(nums.begin()+i); count++;}
//         else{i++;}
//     }
//     for(int i=0; i<count; i++){
//         nums.push_back(0);
//     }
// }//TC--->O(n) and SC--->O(1);//right??




// Two pointer method--->
/*
CORE IDEA OF THE ALGORITHM

j = number of non-zero elements already placed correctly.

So:

1> If all previous elements are non-zero:
   
   number of non-zeroes before i = i

   therefore:
   
   j == i

   Example:
   [1,2,3]

   Here swap(nums[i], nums[j])
   becomes self-swap like:
   
   swap(nums[1], nums[1])

   which changes nothing.


2> If some zeroes existed before i:

   then:

   number of non-zeroes before i < i

   therefore:

   j < i

   Meaning:
   - some gaps/zeroes exist before i
   - first j positions already contain correctly placed non-zeroes
   - so nums[j] must be a zero/gap position

   Therefore swapping is safe.


IMPORTANT INVARIANT:

Indices before j:
-> already contain correctly placed non-zeroes

Indices from j to i:
-> may contain zeroes/gaps


Hence:
- j never points to a wrong finalized non-zero
- if j < i, nums[j] must be zero
- otherwise j == i


ALGORITHM:
*/

void moveZeroes(vector<int>& nums) {

    int j = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(nums[i] != 0) {

            swap(nums[i], nums[j]);

            j++;
        }
    }
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    moveZeroes(nums);
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
    return 0;
}