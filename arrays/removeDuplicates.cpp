#include <bits/stdc++.h>
using namespace std;

//two pointer algo
//write the approaches and time complexity
// int removeDuplicates(vector<int>& nums) {
//         int i=1;int k=1; int j=0;
//         for (; i < nums.size(); i++)
//         {
//             if(nums[i]!=nums[j]){
//                 nums[j+1]=nums[i]; j++;k++;
//             }
//         }
//             return k;   
//     }
//perfect two pointer approach
int removeDuplicates(vector<int>& nums){
    int i=1; int j=0;
    for(; i<nums.size(); i++){
        if(nums[i]!=nums[j]){
            nums[j+1]=nums[i];
            j++;
        }
    }
    
    return j+=1;
}

//brute force approach
// int removeDuplicates(vector<int>& nums){
//     int j=0;
//     for(int i=0; i<nums.size();i++){
//         int fault=1;int w=0;
//         while(w<=j){
//             if(nums[w]==nums[i]){
//                 fault=0; break;
//             }
//             w++;
//         }
//         if(fault){j++; nums[j]=nums[i];}
//     }
//     j+=1;
//     return j;
// }

int main()
{
    int size;
    cin>>size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    
    int d=removeDuplicates(nums);

    cout << d << "\n";
    return 0;
}