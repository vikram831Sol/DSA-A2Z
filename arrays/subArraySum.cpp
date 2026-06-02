#include <bits/stdc++.h>
using namespace std;

//    int cnt=0;
//      for (int i = 0; i < nums.size(); i++)
//      {
//          int sum=0;
//         for(int j=i; j<nums.size(); j++){
//             for (int k = i; k <=j; k++)
//             {
//                 sum+=nums[k];
//             }
//             if (sum==k)
//             {
//                 cnt+=1;
//             }
//         }
//      }
//      return cnt;
//     }


// int subarraySum(vector<int> &nums, int k){
//      int cnt=0;
//      for (int i = 0; i < nums.size(); i++)
//      {
//          int sum=0;
//         for(int j=i; j<nums.size(); j++){
//             sum+=nums[j];
//             if (sum==k)
//             {
//                 cnt++;
//             }
//         }
//      }
//      return cnt;
//     }
//  

int subarraySum(vector<int>& nums, int k){
    vector<int> prefixSum(nums.size());
    int cnt=0;
    prefixSum[0]=nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if(prefixSum[i]==k){cnt++;}
        int val=prefixSum[i]-k;
        if (mp.find(val)!=mp.end())
        {
            cnt+=mp[val];//adding frequency of whatever val is found
        }
        if (mp.find(prefixSum[i])==mp.end())
        {
            mp[prefixSum[i]]=0;
        }
        mp[prefixSum[i]]++;
        
    }
    
    return cnt;
}

int main()
{
    int size;
    int k;
    cin>>k;
    cin>>size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    int r=subarraySum(nums, k);
    cout << r << "\n";
    
    return 0;
}