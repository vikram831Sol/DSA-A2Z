/*
Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals and return an array of the non-overlapping 
intervals that cover all the intervals in the input.
You can return the intervals in any order.

Example 1

Input: intervals = [[1,5],[3,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Intervals [1,5] and [3,6] overlap, so they are merged into [1,6].
*/

#include <bits/stdc++.h>
using namespace std;

/*********Brute force approach O(N^2) and O(N) */

// vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
//     sort(arr.begin(), arr.end());//contri NlogN tc
//     vector<vector<int>> ans;
//     for(int i=0; i<arr.size(); i++){contributes N-1+N-2+...+1=N(N-1)/2=O(N^2) tc
//         int start=arr[i][0];
//         int end=arr[i][1];
//         if(!(ans.empty())&& end<=ans.back()[1]){continue;}
//         for(int j=i+1; j<arr.size(); j++){
//             if(arr[j][0]<=end){
//                 end=max(arr[j][1], end);
//             }
//         }
//         ans.push_back({start, end});
//     }
//     return ans;
//     }

/****Optimal approach O(NlogN) and O(N) */
vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    sort(arr.begin(), arr.end());//contributes NlogN tc
    vector<vector<int>> ans;
    for(int i=0; i<arr.size(); i++){//contributes N tc over all NlogN + N is equivalent to NlogN
        int start=arr[i][0];
        int end=arr[i][1];
        if(!(ans.empty())&& end<=ans.back()[1]){continue;}
        if(!(ans.empty())&& (start<=ans.back()[1])){
            ans.back()[1]=max(end, ans.back()[1]);;
        }
        else{
        ans.push_back({start, end});
        }
    }
    return ans;
    }

int main()
{
    int size;
    cin>>size;
    vector<vector<int>> arr(size, vector<int> (2));
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cin>>arr[i][j];
        }
        
    }
    
    vector<vector<int>> ans=mergeOverlap(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        
        cout << ans[i][0] << " " << ans[i][1];
        
        cout << endl;
    }
    return 0;
}