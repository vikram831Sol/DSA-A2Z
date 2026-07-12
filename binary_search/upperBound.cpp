/*
Given a sorted array of nums and an integer x, write a program to find the upper bound of x.
The upper bound of x is defined as the smallest index i such that nums[i] > x.
If no such index is found, return the size of the array.

Example 1
Input : n= 4, nums = [1,2,2,3], x = 2
Output:3
Explanation:
Index 3 is the smallest index such that arr[3] > x.

Example 2
Input : n = 5, nums = [3,5,8,15,19], x = 9
Output: 3
Explanation:
Index 3 is the smallest index such that arr[3] > x.
*/


#include <bits/stdc++.h>
using namespace std;

//iterative approach and better approach as constant space complexity
// int upperBound(vector<int> &nums, int x){
//         int low=0;
//         int high=nums.size()-1;
//         int ans=nums.size();
//         while (low<=high)
//         {
//             int mid=low+((high-low)/2);
//             if (nums[mid]<=x)
//             {
//                 low=mid+1;
//             }
//             else{
//                 ans=mid;
//                 high=mid-1;
//             }
//         }
//         return ans;
//     }

//recursive approach O(logn) and O(logn) from recursive stack space
int upperBoundRec(vector<int>& nums, int x, int low, int high){
    //this is stopping condition and will only be triggered if low>high without finding
    //a valid solution then we return total size of array
    if (low>high)
    {
        return nums.size();
    }
    int mid=low+((high-low)/2);
    if (nums[mid]>x)
    {
        int leftAns=upperBoundRec(nums, x, low, mid-1);
        if (leftAns!=nums.size())
        //if leftAns==nums.size() which comes from first if that means we didn't find and 
        //valid leftAns
        {
            return leftAns;
        }
        return mid;
    }
    else
    {
        return upperBoundRec(nums, x, mid+1, high);
    }
}

int upperBound(vector<int>& nums, int x){
    return upperBoundRec(nums, x, 0, nums.size()-1);
}

int main()
{
    int size, x;
    cin>>size>>x;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    int ans=upperBound(nums, x);
    cout << ans << endl;
    
    return 0;
}