#include <bits/stdc++.h>
using namespace std;

// int missingNumber(vector<int>& nums) {
//      for (int i = 0; i < nums.size()+1; i++)
//      {
//         int flag=0;
//         for (int j = 0; j < nums.size(); j++)
//         {
//             if(i==nums[j]){
//                 flag=1;break;
//             }
//         }
//         if(!(flag)){
//             return i;
//         }
//      }
//      return -1;
//     }

// int missingNumber(vector<int>& nums){
//     vector<int> temp(nums.size()+1);
//     for (int i = 0; i < nums.size(); i++)
//     {
//         temp[nums[i]]++;
//     }
//     for (int i = 0; i < nums.size()+1; i++)
//     {
//         if((temp[i]==0)){return i;}
//     }
//     return -1;
    
// }

// int missingNumber(vector<int>&nums){
//     int n=nums.size();
//     long long int sum0toN=(n*(n+1))/2;
//     long long int sum=0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         sum+=nums[i];
//     }
//     return sum0toN-sum;
// }

//xor approach T.C=O(n), SC=O(1);
int missingNumber(vector<int>& nums){
    int xor1=0, xor2=nums[0];
    for (int i = 1; i <=nums.size(); i++)
    {
        xor1^=i;
    }
    for (int i = 1; i < nums.size(); i++)
    {
        xor2^=nums[i];
    }
    return xor1^xor2;
}

int main()
{
    int size;
    cin>>size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    
    long long int d=missingNumber(nums);
    cout << d << "\n";

    return 0;
}