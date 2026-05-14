#include <bits/stdc++.h>
using namespace std;

//brute force approach
// vector<int> twoSum(vector<int>& nums, int target) {
//     for (int i = 0; i < nums.size()-1; i++)
//     {
//         for (int j = i+1; j < nums.size(); j++)
//         {
//             if ((nums[i]+nums[j])==target)
//             {
//                 return {i, j};
//             }
            
//         }
        
//     }
    
//     }

//Better Approach
// vector<int> twoSum(vector<int>& nums, int target) {
//     unordered_map<int, int> mp;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         mp[nums[i]]=i;
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (mp.find(target-nums[i])!=mp.end()&&mp[target-nums[i]]!=i)
//         {
//             return {i, mp[target-nums[i]]};
//         }
        
//     }
//     return {-1, -1};
//     }

//Optimal approach
vector<int> twoSum(vector<int>& nums, int target){
    vector<pair<int, int>> temp;
    for (int i = 0; i < nums.size(); i++)
    {
        temp.push_back({nums[i], i});
    }
    
    sort(temp.begin(), temp.end());
    int left=0, right=nums.size()-1;
    while (left<right)
    {
        int sum=temp[left].first+temp[right].first;
        if (sum==target)
        {
            return {temp[left].second, temp[right].second};
        }
        else if (sum>target)
        {
            right--;
        }
        else if (sum<target)
        {
            left++;
        }
    }
    return {-1, -1};
}

// unordered_map find() summary

//unordered_map<int, int> mp;

// search for key
//auto it = mp.find(key);

// if key exists
//if (it != mp.end()) {

    // access key
    //it->first;

    // access value
    //it->second;
//}

// if key does NOT exist
//if (it == mp.end()) {
    // key not found
//}


/*
IMPORTANT:

mp.find(key)
- only searches
- does NOT create new key

mp[key]
- accesses value
- creates key automatically if absent
*/

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

    vector<int> d = twoSum(nums, k);
    cout << d[0] << " " << d[1] << "\n";
    return 0;
}

