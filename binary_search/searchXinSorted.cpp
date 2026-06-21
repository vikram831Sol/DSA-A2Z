/*
Given a sorted array of integers nums with 0-based indexing, 
find the index of a specified target integer. If the target is found in the array, 
return its index. If the target is not found, return -1.

Example 1
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: The target integer 9 exists in nums and its index is 4

Example 2
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: The target integer 2 does not exist in nums so return -1
*/


#include <bits/stdc++.h>
using namespace std;

//iterative approach
// int search(vector<int> &nums, int target){
//     int low=0;
//     int high=nums.size()-1;
//     while (low<=high)
//     {
//         int mid=(low+high)/2;
//         if (nums[mid]==target)
//         {
//             return mid;
//         }
//         else if(nums[mid]<target)
//         {
//             low=mid+1;
//         }
//         else{high=mid-1;}
//     }
    
//     return -1;
//     }

//recursive approach O(logn) and O(1)
int bin_search(vector<int> &nums, int target, int low, int high){
    if (low>high)
    {
        return -1;
    }
    int mid=(low+(high-low)/2);
    if (nums[mid]==target)
    {
        return mid;
    }
    else if(nums[mid]<target)
    {
        return bin_search(nums, target, mid+1, high);
    }
    else{
        return bin_search(nums, target, low, mid-1);
    }
}

int search(vector<int> &nums, int target){
    return bin_search(nums, target, 0, nums.size()-1);
}

int main()
{
    int size, target;
    cin>>size>>target;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    int ans=search(nums, target);
    cout << ans << endl;
    return 0;
}