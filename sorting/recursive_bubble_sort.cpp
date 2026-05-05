#include <bits/stdc++.h>
using namespace std;


void bubbleSort(vector<int>& nums, int n){
    if(n<=1)return;
    for (int i = 0; i <=n-1; i++)
    {
        if(nums[i]>nums[i+1]){
            swap(nums[i], nums[i+1]);
        }
    }
    bubbleSort(nums, n-1);
}


int main()
{
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    
    bubbleSort(nums, size-1);
    for (auto it : nums) {
        cout << it << " ";
    };
    cout << "\n";
    return 0;
}