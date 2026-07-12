/*
Given a sorted array of nums consisting of distinct integers and a target value, 
return the index if the target is found. If not, return the index where it would 
be if it were inserted in order.
Example 1
Input: nums = [1, 3, 5, 6], target = 5
Output: 2
Explanation: The target value 5 is found at index 2 in the sorted array. 
Hence, the function returns 2.

Example 2
Input: nums = [1, 3, 5, 6], target = 2
Output: 1
Explanation: The target value 2 is not found in the array. 
However, it should be inserted at index 1 to maintain the sorted order of the array.
*/

#include <bits/stdc++.h>
using namespace std;

int search_Insert(vector<int> &nums, int target, int low, int high){
    if (low>=high)
    {
        if (nums[low]>=target)
        {
            return low;
        }
        else{
            return low+1;
        }
        
    }
    int mid=low+((high-low)/2);
    if (nums[mid]==target)
    {
        return mid;
    }
    else if (nums[mid]<target)
    {
        return search_Insert(nums, target, mid+1, high);
    }
    else{
        return search_Insert(nums, target, low, mid-1);
    }
    
}

int searchInsert(vector<int> &nums, int target)  {
        int low=0;
        int high=nums.size()-1;
        return search_Insert(nums, target, low, high);
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
    int ans=searchInsert(nums, target);
    cout << ans << endl;
    return 0;
}