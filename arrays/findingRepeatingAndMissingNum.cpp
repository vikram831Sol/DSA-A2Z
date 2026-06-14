#include <bits/stdc++.h>
using namespace std;

//brute force approach O(N^2) and O(1)
// vector<int> findMissingRepeatingNumbers(vector<int> nums){
//     vector<int> ans;
//     for (int i = 1; i <=nums.size(); i++)
//     {
//         int count=0;
//         for (int j = 0; j < nums.size(); j++)
//         {
//             if(i==nums[j]){count++;}
//         }
//         if (count==2)
//         {
//             ans.push_back(i);
//         }
//         else if(count==0){
//             ans.push_back(i);
//         }
//     }
//     return ans;
// }

/*better approach O(n) and O(n)*/
// vector<int> findMissingRepeatingNumbers(vector<int> nums) {
//     vector<int> hasharr(nums.size()+1, 0);
//     vector<int> ans;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         hasharr[nums[i]]++;
//     }
//     for (int i = 1; i <nums.size()+1; i++)
//     {
//         if (hasharr[i]==2)
//         {
//             ans.push_back(i);
//         }
//         else if(hasharr[i]==0){
//             ans.push_back(i);
//         }
        
//     }
    
//     return ans;
//     }

//optimal solution 1
//O(N) and O(1)
vector<int> findMissingRepeatingNumbers(vector<int> nums){
    vector<int> ans;
    long long A;
    long long B;
    long long X;
    long long Y;
    long long Z;
    long long S=0;
    long long S2=0;
    long long Sn;
    long long Sn2;
    Sn=(nums.size()*(nums.size()+1))/2;
    Sn2=((nums.size())*(nums.size()+1)*((2*nums.size())+1))/6;
    for (int i = 0; i < nums.size(); i++)
    {
        S+=(long long)nums[i];
        S2+=(long long)nums[i]*(long long)nums[i];
    }
    X=S-Sn;
    Z=S2-Sn2;
    Y=Z/X;
    A=(X+Y)/2;
    B=Y-A;
    return {(int)A, (int)B};
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
    
    vector<int> ans=findMissingRepeatingNumbers(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    

    return 0;
}