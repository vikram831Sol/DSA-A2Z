/*
You are given a sorted array of integers arr and
an integer target. Your task is to determine how many times target appears in arr.
Return the count of occurrences of target in the array.

Example 1
Input: arr = [0, 0, 1, 1, 1, 2, 3], target = 1
Output: 3
Explanation: The number 1 appears 3 times in the array.

Example 2
Input: arr = [5, 5, 5, 5, 5, 5], target = 5
Output: 6
Explanation: All elements in the array are 5, so the target appears 6 times.
*/

#include <bits/stdc++.h>
using namespace std;

int searchStart(vector<int>& arr, int target){
    int low=0;
    int high=arr.size()-1;
    int start=-1;
    while (low<=high)
    {
        int mid=low+((high-low)/2);
        if (arr[mid]==target)
        {
            start=mid;;
            high=mid-1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
    }
    return start;
}


int searchEnd(vector<int>& arr, int target){
    int low=0;
    int high=arr.size()-1;
    int end=-1;
    while (low<=high)
    {
        int mid=low+((high-low)/2);
        if (arr[mid]==target)
        {
            end=mid;
            low=mid+1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
    }
    return end;
}


int countOccurrences(vector<int>& arr, int target) {
        int start=searchStart(arr, target);
        int end=searchEnd(arr, target);
        if (start==-1&&end==-1){return 0;}
        return (end-start+1); 
    }

int main()
{
    int size, target;
    cin>>size>>target;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    int ans=countOccurrences(arr, target);
    cout << ans << endl;
    return 0;
}