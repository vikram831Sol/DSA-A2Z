/*Given an array arr of integers. 
A peak element is defined as an element greater than both of its neighbors.
Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i].
Find the index(0-based) of a peak element in the array. 
If there are multiple peak numbers, return the index of any peak number.
Note:
As there can be many peak values, "true" is given as output if the returned index is a peak number,
otherwise the returned value of index.*/

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
     int low=0;
     int high=arr.size()-1;
     if(low==high){return low;}
     if(arr[low]>arr[low+1]){return low;}
     else if(arr[high]>arr[high-1]){return high;}
     low++;
     high--;
     while (low<=high)
     {
        int mid=low+((high-low)/2);
        if ((arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]))
        {
            return mid;
        }
        if (arr[mid]<arr[mid+1])
        {
            low=mid+1;
        }
        else{high=mid-1;}  
     }
      return -1;
    }

int main()
{
    int size;
    cin>>size;
    vector<int>arr(size);
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    int ans=findPeakElement(arr);
    cout << ans << endl;
    return 0;
}