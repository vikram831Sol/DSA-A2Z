/*
Given an integer array nums, sorted in ascending order 
(may contain duplicate values) and a target value k. Now the
array is rotated at some pivot point unknown to you. Return True if k
is present and otherwise, return False.
*/

#include <bits/stdc++.h>
using namespace std;
bool searchInARotatedSortedArrayII(vector<int> &nums, int k)  {
      int low=0;
      int high=nums.size()-1;
      /*
      When does ambiguity actually happen?
    Ambiguity means:
    "From the available information, I cannot tell whether the pivot
    is on the left or the right."
    For that to happen, the boundary values must all look identical
      */
      while(low<=high){
        int mid=low+((high-low))/2;
        if(nums[mid]==k){return true;}
        if (nums[low]==nums[mid]&&nums[mid]==nums[high])//for ambigous case
        {
            low++;
            high--;//while loop low<=high protects them
            continue;//to avoid going to next if loop and start the fresh next loop
        }
        if (nums[low]<=nums[mid])
        {
            if (nums[low]<=k && k<nums[mid])
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(nums[mid]<k&&k<=nums[high]){
                low=mid+1;
            }
            else{high=mid-1;}
        } 
      }
      return false;
    }
int main()
{
    int size, k;
    cin>>size>>k;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }

    bool ans=searchInARotatedSortedArrayII(nums, k);

    cout << ans;
    
    return 0;
}