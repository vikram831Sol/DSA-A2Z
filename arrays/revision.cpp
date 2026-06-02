#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k){
    vector<int> prefixSum(nums.size());
    prefixSum[0]=nums[0];
    int count=0;
    unordered_map<int, int> mp;
    for (int i = 1; i < nums.size(); i++)
    {
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (prefixSum[i]==k)
        {
            count++;
        }
        int val=prefixSum[i]-k;
        if (mp.find(val)!=mp.end())
        {
            count+=mp[val];
        }
        mp[prefixSum[i]]++;
        
    }
    return count;
}
int main()
{
    int size, k;
    cin>>k>>size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    int d=subarraySum(nums, k);
    cout << d << '\n';
    return 0;
}