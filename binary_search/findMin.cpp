/*
Given an integer array nums of size N, sorted in ascending order with distinct values,
 and then rotated an unknown number of times (between 1 and N), find the minimum element
in the array.
Example 1
Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]
Output: 0
Explanation: Here, the element 0 is the minimum element in the array.

Example 2
Input : nums = [3, 4, 5, 1, 2]
Output: 1
Explanation:Here, the element 1 is the minimum element in the array.
*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)  {
      int low=0;
      int high=arr.size()-1;
      int mini=INT_MAX;
      int mini_ind=0;
      while (low<=high)
      {
        int mid=low+((high-low)/2);
        if (arr[low]<=arr[mid])//if left side is sorted take the min
        //arr[low]temporarily for now and later then sort out the search space to unsorted part
        //that is right side.
        {
            mini=min(mini, arr[low]);
            (mini>=arr[low])?mini_ind=low:mini_ind=mini_ind;
            low=mid+1;
        }
        //if right side is sorted take the min arr[mid]for now and do the searching in
        //unsorted part that is left side.
        else{
            mini=min(mini, arr[mid]);
            (mini>=arr[mid])?mini_ind=mid:mini_ind=mini_ind;
            high=mid-1;
        }
      }
      
      return mini;
    }

int main()
{
    int size;
    cin>>size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    int ans=findMin(arr);
    cout << ans << endl;
    
    return 0;
}