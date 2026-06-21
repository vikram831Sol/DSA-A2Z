/*

Given an integer array nums. Find the subarray with the largest product, and 
return the product of the elements present in that subarray.

A subarray is a contiguous non-empty sequence of elements within an array.
Example 1
Input: nums = [4, 5, 3, 7, 1, 2]
Output: 840
Explanation:
The largest product is given by the whole array itself

Example 2
Input: nums = [-5, 0, -2]
Output: 0
Explanation:
The largest product is achieved with the following subarrays [0], [-5, 0], [0, -2], [-5, 0, -2].
*/

#include <bits/stdc++.h>
using namespace std;

// int maxProduct(vector<int>& nums) {
//      int maxproduct=INT_MIN;
//      for (int i = 0; i < nums.size(); i++)
//      {
//          int product=1;
//         for (int j = i; j < nums.size(); j++)
//         {
//             product*=nums[j];
//             maxproduct=max(product, maxproduct);
//         }

//      }
//         return maxproduct;
//     }

int maxProduct(vector<int>& nums) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int prod1 = 1;
    int prod2 = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            prod1 = 1;
            max1=max(0, max1);
        } else {
            prod1 *= nums[i];
            max1=max(max1, prod1);
        }
    }
    for (int i = nums.size()-1; i > -1; i--) {
        if (nums[i] == 0) {
            prod2 = 1;
            max2=max(0, max2);
        } else {
            prod2 *= nums[i];
            max2=max(max2, prod2);
        }
    }
    return max(max1, max2);
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int ans = maxProduct(nums);

    cout << ans << endl;

    return 0;
}