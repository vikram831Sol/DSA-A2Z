#include <bits/stdc++.h>
using namespace std;

//Brute force approach
//store first k elements in the temp array
//shift last n-k elements to left and place first k elements at last

void rotateArrayM2(vector<int>& nums, int k){
    k=k%nums.size();
    vector<int> temp;
    for (int i = 0; i < k; i++)
    {
        temp.push_back(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        nums[i-k]=nums[i];
    }
    for (int i = nums.size()-k; i < nums.size(); i++)
    {
        nums[i]=temp[i-(nums.size()-k)];
    }
}


//optimal approach
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
    
    rotateArrayM2(nums, n);
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] <<" ";
    }
    cout << "\n";
    return 0;
}