#include <bits/stdc++.h>
using namespace std;
//Hashing made from sratch
// vector<vector<int>> countFrequencies(vector<int>& nums) {
//         vector<vector<pair<int, int>>> table(10);
//         vector<vector<int>> result;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int index=(nums[i]%10+10)%10;//for handling both negative and positive integers
//             bool found=false;
//             //updating frequency if number already found earlier inside the table array
//             for(auto &p:table[index])
//             {
//                 if(p.first==nums[i]){
//                     p.second++;
//                     found=true;
//                     break;
//                 }
//             }
//             //updating the new element found in new array
//             if(!found){
//                 table[index].push_back({nums[i], 1});
//             }
//         }
//         for(auto &p:table){
//             for(auto &it:p){
//                 result.push_back({it.first, it.second});
//             }
//         }
//         sort(result.begin(), result.end());
//         return result;

//     }

vector<vector<int>> countFreq(vector<int> & nums){
    vector<vector<int>> result;
    unordered_map<int, int> mp;
    for (auto &it:nums)
    {
        mp[it]++;
    }
    for (auto &it:mp)
    {
        result.push_back({it.first, it.second});
    }
    return result;
}

int main()
{
    int size;
    cin>>size;
    vector<int> nums(size);
    for (int i=0; i<size; i++){
        cin>>nums[i];
    }
    vector<vector<int>> d;
    d=countFreq(nums);
    for (auto it:d){
        cout << it[0] << " " << it[1];
        cout << "\n";
    }

    return 0;
}