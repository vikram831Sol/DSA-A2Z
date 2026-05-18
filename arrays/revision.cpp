#include <bits/stdc++.h>
using namespace std;

void sortZeroOneTwo(vector<int>& nums){
    int low=0, mid=0, high=nums.size()-1;
    while (mid<=high)//
    {
        if (nums[mid]==0)
        {
            swap(nums[mid], nums[low]);mid++;low++;
        }
        else if (nums[mid]==1)
        {
            mid++;
        }
        else if (nums[mid]==2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
        
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
    sortZeroOneTwo(nums);
    for (int i = 0; i < size; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout << "\n";
    return 0;
}