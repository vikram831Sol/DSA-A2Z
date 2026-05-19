#include <bits/stdc++.h>
using namespace std;
//brute force O(n^3) and O(1)
// int maxSubArray(vector<int>& nums) {
//     int maxi=INT_MIN;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i; j < nums.size(); j++)
//         {
//                 int sum=0;
//                 for (int k = i; k <=j; k++)
//                 {
//                     sum=sum+nums[k];
//                 }
//                 maxi=max(sum, maxi);
//             }
            
//         }
//         return maxi;
//     }

//better approach O(n^2) and O(1)
// int maxSubArray(vector<int>& nums){
//     int maxi=INT_MIN;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int sum=0;
//         for (int j = i; j < nums.size(); j++)
//         {
//             sum+=nums[j];
//             maxi=max(sum, maxi);
//         }
        
//     }
//     return maxi;
// }

//optimal approach Kadane's algorithm or sum
//till sum is positive it is still usefull but as soon as it gets negative
//it will get useless as negative sum with next positive value will decrease it only
//so reset it

int maxSubArray(vector<int>& nums){
    int maxi=INT_MIN;
    int sum=0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum+=nums[i];
        maxi=max(maxi, sum);
        if (sum<0)
        {
            sum=0;
        }
        
    }
    return maxi;
}


int main()
{
    int size;
    cin>>size;
    vector<int> nums(size);
    for (int i = 0; i < nums.size(); i++)
    {
        cin>>nums[i];
    }
    int d=maxSubArray(nums);
    cout << d << "\n";
    return 0;
}