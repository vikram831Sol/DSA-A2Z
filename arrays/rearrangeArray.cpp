#include <bits/stdc++.h>
using namespace std;
//O(n) and O(2n);
// vector<int> rearrangeArray(vector<int>& nums){
//     vector<int> pos;
//     vector<int> neg;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(nums[i]>0){
//             pos.push_back(nums[i]);
//         }
//         else{neg.push_back(nums[i]);}
//     }

//         int i=0;
//         int j=0;
//         while (i<nums.size())
//         {
//             nums[i]=pos[j];
//             nums[i+1]=neg[j];i++;i++;j++;

//         } 

    
//     return nums;
// }

vector<int> rearrangeArray(vector<int>& nums){
    int posIndex=0;
    int negIndex=1;
    vector<int> result(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i]>0)
        {
            result[posIndex]=nums[i]; 
            posIndex+=2;  
        }
        else{
            result[negIndex]=nums[i];
            negIndex+=2;
        }
        
    }
    return result;
}//this second method is optimal method right and the commented and this method are almost the same
//and first one has just space complexity of 2n rest both are same

int main()
{
    int size;
    cin>>size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }

    vector<int> result=rearrangeArray(nums);

    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}