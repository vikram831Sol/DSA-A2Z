#include <bits/stdc++.h>
using namespace std;


//brute force approach O(n^2) and O(n);
// vector<int> leaders(vector<int>& nums) {
//     vector<int> result;
//      for (int i = 0; i < nums.size(); i++)
//      {
//         int faulty=0;
//         for (int j = i+1; j < nums.size(); j++)
//         {
//             if (nums[i]<=nums[j])
//             {
//                 faulty=1;
//                 break;
//             }
            
//         }
//         if(!(faulty)){
//             result.push_back(nums[i]);
//         }
//      }
//       return result;
//     }
//optimal approach O(n) and O(n);
void reverse(vector<int>& result, int left, int right){
    while (left<right)
    {
        swap(result[left], result[right]);
        left++;
        right--;
    }
    
}

vector<int> leaders(vector<int>& nums){
    vector<int> result;
    int j=nums.size()-2;
    int greatest_yet=nums[j+1];
    result.push_back(nums[j+1]);
    while (j>=0)
    {
        if (nums[j]>greatest_yet)
        {
            result.push_back(nums[j]);
            greatest_yet=nums[j];j--;
        }
        else{j--;}
        
    }
    reverse(result, 0, result.size()-1);
    return result;
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

    vector<int> result=leaders(nums);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
    
    return 0;
}