#include <bits/stdc++.h>
using namespace std;
//brute force TC-->O(n) SC-->O(1)
// void sortZeroOneTwo(vector<int>& nums) {
//         int count_zero=0; int count_one=0; int count_two=0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (nums[i]==0)
//             {
//                 count_zero++;
//             }
//             else if (nums[i]==1)
//             {
//                 count_one++;
//             }
//             else if (nums[i]==2)
//             {
//                 count_two++;
//             }
            
//         }
//         for (int i = 0; i < count_zero; i++)
//         {
//             nums[i]=0;
//         }
//         for (int i = count_zero; i < count_zero+count_one; i++)
//         {
//             nums[i]=1;
//         }
//         for (int i = count_one+count_zero; i < count_one+count_zero+count_two; i++)
//         {
//             nums[i]=2;
//         }   
//
//     }

//Dutch National Flag algorithm
void sortZeroOneTwo(vector<int>& nums){
    int low=0, high=nums.size()-1;
    int mid=0;
    while (mid<=high)
    {
        if (nums[mid]==0)
        {
            swap(nums[low], nums[mid]);low++;mid++;
        }
        else if (nums[mid]==1)
        {
            mid++;
        }
        else if (nums[mid]==2)
        {
            swap(nums[mid], nums[high]); high--;
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