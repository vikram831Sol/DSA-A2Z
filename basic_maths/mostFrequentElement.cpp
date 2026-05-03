#include <bits/stdc++.h>
using namespace std;

// unordered_map<int, int> helper(vector<int> &nums){
//     unordered_map<int, int> mp;
//     for (auto &it:nums){
//         mp[it]++;
//     }
//     return mp;
// }

// int mostFrequentElement(vector<int>& nums) {
//         unordered_map<int, int> d=helper(nums);
//         vector<int> v;
//         int max=INT_MIN;
//         for (auto it=d.begin(); it!=d.end(); it++)
//         {
//             if(it->second>max){
//                 max=it->second;
//             }
//         }
//         for (auto it=d.begin(); it!=d.end(); it++)
//         {
//             if(it->second==max){
//                 v.push_back(it->first);
//             }
//         }
//         sort(v.begin(), v.end());
//         return v[0];
        
        
//     }


//optimal:-update frequency → immediately check if it’s the best so far
int mostFrequentElement(vector<int>& nums) {
    unordered_map<int,int> mp;

    int maxFreq = 0;
    int ans = INT_MAX;  // to pick smallest in case of tie

    for (int x : nums) {
        mp[x]++;

        if (mp[x] > maxFreq || (mp[x] == maxFreq && x < ans)) {
            maxFreq = mp[x];
            ans = x;
        }
    }

    return ans;
}

int main()
{
    int size;
    cin>>size;
    vector<int> nums(size);
    for (auto &it:nums)
    {
        cin>>it;
    }
    int result;
    result=mostFrequentElement(nums);
    cout << result << "\n";
    return 0;
}