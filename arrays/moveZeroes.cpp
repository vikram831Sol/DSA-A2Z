#include <bits/stdc++.h>
using namespace std;
//approach number one: Brute force Time Complexity--->O(n^2) &&& Space complexity--->O(1)
// void moveZeroes(vector<int>& nums) {
//     int count=0;
//         for(int i=0; i<nums.size()-1; i++){
//             if(nums[i]==0){
//                 count++;
//                 for(int j=i; j<nums.size()-1; j++){
//                     nums[j]=nums[j+1];
//                 }
//             }
//         }
//         for(int i=nums.size()-count; i<nums.size(); i++){
//             nums[i]=0;
//         }
//     }
//Best case Time complexity--->O(n) and Space complexity is---->O(1)
void moveZeroes(vector<int>& nums){
    int count=0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==0){
            nums.erase(nums.begin()+i);count++;
        }
    }
    for(int i=0; i<count; i++){
        nums.push_back(0);
    }
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
    moveZeroes(nums);
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] <<" ";
    }
    cout << "\n";
    return 0;
}