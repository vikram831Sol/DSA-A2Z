#include <bits/stdc++.h>
using namespace std;

int funC(vector<int>& nums, int low, int high){
    int left=low;
    int right=high;
    while(left<right)/*while(left<=right) is wrong why*/{
        while(nums[left]<=nums[low] && left<high){left++;}
        while(nums[right]>nums[low]/*why not nums[right]>=nums[low]*/ && right>low){right--;}
        if(left<right){swap(nums[left], nums[right]);}
    }
    swap(nums[low], nums[right]);
    return right;
}

void quicksort(vector<int>& nums, int low, int high){
    if(low>=high){return;}
    int f=funC(nums, low, high);
    quicksort(nums, low, f-1);
    quicksort(nums, f+1, high);
}

int main()
{
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    
    quicksort(nums, 0, size-1);
    for (auto it : nums) {
        cout << it << " ";
    };
    cout << "\n";
    return 0;
}