#include <bits/stdc++.h>
using namespace std;


//brute force approach
// int majorityElement(vector<int>& nums){
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int count=0;
//         for (int j = 0; j < nums.size(); j++)
//         {
//             if (nums[i]==nums[j])
//             {
//                 count++;
//             }
//         }
//         if(count>nums.size()/2){
//             return nums[i];
//         }
//     }
//     return -1;
// }


//TC--->O(2n) and SC--->O(n);
// int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             mp[nums[i]]++;
            
//         }
//         return -1;
//         int maxi=INT_MIN;
//         int maxi_number=-1;
//         for (auto it=mp.begin(); it != mp.end(); it++)
//         {
//             if (maxi<it->second)
//             {
//                 maxi=it->second;
//                 maxi_number=it->first;
//             }
            
//         }
//         return maxi_number;
//     }

//TC--->O(n) and SC--->O(n);
//after seeing editorial-->better approach
// int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             mp[nums[i]]++;
//             if(mp[nums[i]]>nums.size()/2){return nums[i];}
//         }
//         return -1;
        
//     }

//OPTIMAL approach T.C=O(n) and S.C=O(1)
//do not increment count twice for both if case only one if case will have count icnrease
//Boyer-Moore majority Algorithm
//this algorithm can return value even without any majority element existing
//this algo is based on cancellation for example if we form pairs of
//numbers such that in a pair no two numbers are same then at the last majority element 
//remains, so as per algo if majority doesn't exist it will return some random value
int majorityElement(vector<int>& nums){
    int count=0; int element;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count==0)
        {
            element=nums[i];
        }
        if(nums[i]==element){
            count++;
        }
        else{count--;}   
    }
    int freq=0;
    for(int num:nums){
        if (num==element)
        {
            freq++;
        }
    }
    
    return (freq>nums.size()/2)?element:-1;
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
    int d=majorityElement(nums);
    cout << d << "\n";  
    return 0;
}