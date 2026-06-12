#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int>& nums){
    int maxLen=0;
    int ps=0;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        ps+=nums[i];
        if (ps==0)
        {
            maxLen=max(maxLen, i+1);
        }
        if (mp.find(ps)!=mp.end())
        {
            maxLen=max(maxLen, i-mp[ps]);
        }
        else{
            mp[ps]=i;
        }
        
    }
    return maxLen;
}

int main() {
    int size, k;
    cin>>size>>k;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }

    int d=maxLen(nums);
    cout << d << endl;
    return 0;
}