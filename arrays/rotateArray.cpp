#include <bits/stdc++.h>
using namespace std;

void swapping(vector<int>& nums, int left, int right){
    while(left<right){
        swap(nums[left], nums[right]);
        left++;
        right--;
    }
}

void rotateArray(vector<int>& nums, int n){
    int k=n%nums.size();
    swapping(nums, 0, nums.size()-1);
    swapping(nums, 0, nums.size()-k-1);
    swapping(nums, nums.size()-k, nums.size()-1);
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
    
    rotateArray(nums, n);
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] <<" ";
    }
    cout << "\n";
    return 0;
}