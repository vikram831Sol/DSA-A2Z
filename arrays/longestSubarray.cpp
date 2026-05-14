#include <bits/stdc++.h>
using namespace std;

// int longestSubarray(vector<int> &nums, int k){
//         int i=0;int j;int max=0;
//         while (i<nums.size()-1)
//         {
//             j=i+1;
//             int sum=nums[i];
//             while (sum<k&&j<nums.size())
//             {
//                 sum+=nums[j];j++;
//             }
//             if(max<j-i&&sum==k){max=j-i;}
//             i++;
//             }
    
//         return max;
//     }

int longestSubarray(vector<int>&nums, int k){
    int right=0; int left=0; int maxlength=0; int sum=0;
    while(right<nums.size()){
        sum+=nums[right];
        while (sum>k&&left<=right)
        {
            sum-=nums[left];left++;
        }
        if (maxlength<right-left+1&&sum==k)
        {
            maxlength=right-left+1;
        }
        right++;
    }
    return maxlength;
}

int main()
{
    int k;
    cin>>k;
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int d = longestSubarray(nums, k);
    cout << d << "\n";
    return 0;
}