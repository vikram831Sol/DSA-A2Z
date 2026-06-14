#include <bits/stdc++.h>
using namespace std;

//brute force O(N^2) & O(1)
// long long int numberOfInversions(vector<int> nums) {
//     int count=0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i+1; j < nums.size(); j++)
//         {
//             if(nums[i]>nums[j]){count++;}
//         }
        
//     }
//         return count;
//     }

//optimal approach merge sort
int cnt=0;
void merge(vector<int>& nums, int low, int mid, int high){
    int left=low;
    int right=mid+1;
    vector<int> temp;
    while (left<=mid && right<=high)
    {
        if (nums[left]<=nums[right])
        {
            temp.push_back(nums[left]);left++;
        }
        else{
            temp.push_back(nums[right]);
            cnt+=mid-left+1;
            right++;
        }
        
    }
    while (left<=mid)
    {
        temp.push_back(nums[left]);left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);right++;
    }
    
    for (int i = low; i <=high; i++)
    {
        nums[i]=temp[i-low];
    }
    
    
}

void mergeSort(vector<int>& nums, int low, int high){
    if(low>=high){return;}
    int mid=(low+((high-low)/2));
    mergeSort(nums, low, mid);
    mergeSort(nums, mid+1, high);
    merge(nums, low, mid, high);
}

long long int numberOfInversions(vector<int> nums) {
    mergeSort(nums, 0, nums.size()-1);
    return cnt;
    }

int main()
{
    int size;
    cin>>size;
    vector<int> nums(size);
    for(int i=0; i<size; i++){
        cin>>nums[i];
    }
    long long int ans=numberOfInversions(nums);
    cout << ans << endl;
    return 0;
}