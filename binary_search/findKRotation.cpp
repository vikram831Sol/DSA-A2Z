/*find number of times sorted array is rotated*/
#include <bits/stdc++.h>
using namespace std;
int findKRotation(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    int mini = INT_MAX;
    int mini_ind = 0;
    while (low <= high) {
        //checking if part low to high is already sorted or not 
        if (nums[low] <= nums[high]) {
            if (nums[low] < mini) {
                mini = nums[low];
                mini_ind = low;
            }
            break;
        }
        int mid = low + ((high - low) / 2);
        if (nums[low] <= nums[mid])  // if left side is sorted take the min
        // arr[low]temporarily for now and later then sort out the search space to unsorted part
        // that is right side.
        {
            if (mini >= nums[low]) {
                mini = nums[low];
                mini_ind = low;
            } else {
                mini_ind = mini_ind;
            }
            low = mid + 1;
        }
        // if right side is sorted take the min arr[mid]for now and do the searching in
        // unsorted part that is left side.
        else {
            if (mini >= nums[mid]) {
                mini = nums[mid];
                mini_ind = mid;
            } else {
                mini_ind = mini_ind;
            }
            high = mid - 1;
        }
    }

    return mini_ind;
}
int main() { 
    int size;
    cin>>size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    int ans=findKRotation(arr);
    cout << ans << endl;
    
    return 0; }