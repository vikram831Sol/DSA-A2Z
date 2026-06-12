#include <bits/stdc++.h>
using namespace std;

//brute force approach O(n^2) O(1)
// int subarraysWithXorK(vector<int> &nums, int k) {
//         int count=0;
//         for (int i = 0; i <nums.size(); i++)
//         {
//             int xoR=0;
//             for(int j=i; j<nums.size();j++){
//                 xoR^=nums[j];
//                 if(xoR==k){count++;}
//             }
//         }
//         return count;
//     }

//optimal approach O(n) and O(n);
int subarraysWithXorK(vector<int> &nums, int k){
    int count=0;
    int xoR=0;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        xoR^=nums[i];
        if(xoR==k){count++;}
        int y=xoR^k;
        if (mp.find(y)!=mp.end())
        {
            count+=mp[y];
        }
        mp[xoR]++;
    }
    return count;
}

int main()
{
    int size, k;
    cin>>size>>k;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    int ans=subarraysWithXorK(nums, k);
    cout << ans << endl; 
    return 0;
}