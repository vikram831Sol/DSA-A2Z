#include <bits/stdc++.h>
using namespace std;

void swapping(vector<int>& nums, int left, int right){
    while(left<right){
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

void rotateArrayByOne(vector<int>& nums){
    
    swapping(nums, 0, nums.size()-1);
    swapping(nums, 0, nums.size()-1-1);
    swapping(nums, nums.size()-1, nums.size()-1);
}

int main()
{
    int size;
    cin>>size;
    int n;
    cin>>n;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    
    rotateArrayByOne(nums);
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] <<" ";
    }
    cout << "\n";
    return 0;
}