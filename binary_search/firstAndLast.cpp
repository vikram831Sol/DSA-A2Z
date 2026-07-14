/*
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given
target value. If the target is not found in the array, return [-1, -1].

Example 1
Input: nums = [5, 7, 7, 8, 8, 10], target = 8
Output: [3, 4]
Explanation:The target is 8,
and it appears in the array at indices 3 and 4, so the output is [3,4]

Example 2
Input: nums = [5, 7, 7, 8, 8, 10], target = 6
Output: [-1, -1]
Expalantion: The target is 6, which is not present in the array. 
Therefore, the output is [-1, -1].
*/

#include <bits/stdc++.h>
using namespace std;

//optimal approach
int searchPositionEnd(vector<int> &nums, int target){
    int end=-1;
    int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(nums[mid]==target){
                end=mid;
                low=mid+1;
            }
            else if (nums[mid]<target)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return end;
}
int searchPositionStart(vector<int> &nums, int target){
    int start=-1;
    int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(nums[mid]==target){
                start=mid;
                high=mid-1;
            }
            else if (nums[mid]<target)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return start;
}

vector<int> searchRange(vector<int> &nums, int target) {
        int start=searchPositionStart(nums, target);
        int end=searchPositionEnd(nums, target);
        return {start, end};
    }//minor mistake earlier ha ha

int main()
{
    int size, target;
    cin>>size>>target;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    vector<int> ans=searchRange(nums, target);
    for (auto it:ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}