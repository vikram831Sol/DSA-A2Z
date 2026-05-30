#include <bits/stdc++.h>
using namespace std;

//brute force O(n^3)
// bool linearSearch(vector<int>&nums, int target){
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i]==target)
//         {
//             return true;
//         }
        
//     }
//     return false;
// }

// int longestConsecutive(vector<int>& nums){
//     int cnt=1;
//     int max_cnt=1;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         cnt=1;
//         int x=nums[i];
//         while(linearSearch(nums, x+1)==true){//contributes total of n operations
//             x+=1;//for each of while search it updates so n^2 and 
//              //while runs for each outer for loop i so n^3
//             cnt+=1;
//         }
//         max_cnt=max(max_cnt, cnt);
//     }
//     return max_cnt;
// }

//better approach
// int longestConsecutive(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//      int i=0;
//      int count=1;
//      int max_count=1;
//      while (i<nums.size()-1)
//      {
//         if (nums[i+1]==nums[i]+1)
//         {
//             i++;count++;if(count>max_count){max_count=count;}
//         }
//         else
//         {
//             count=1;i++;
//         }
        
//      }
//         return max_count;
//     }

//Optimal approach
int longestConsecutive(vector<int>& nums){
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }//o(n)
    int cnt=1;
    int max_cnt=1;
    for (auto it:st)
    {
        
        if (st.find(it-1)==st.end())//previous elemet not found so new starting for checking of 
        //sequence
        {
            cnt=1;
            int x=it;
            while (st.find(x+1)!=st.end())//it will give total of o(1) for one i at average and
            //total of n for whole while that is n+n=2n, for nested for loops it was
            //n for one i that is total of n^2
            {
                x=x+1;cnt++;
            }
            
        }
        
        max_cnt=max(max_cnt, cnt);
        
    }
    return max_cnt;
    
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
    int r=longestConsecutive(nums);
    cout << r << "\n";
    return 0;
}