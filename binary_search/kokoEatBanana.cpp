/*
A monkey is given n piles of bananas, 
where the 'ith' pile has nums[i] bananas. 
An integer h represents the total time in hours to eat all the bananas.

Each hour, the monkey chooses a non-empty pile of bananas 
and eats k bananas. If the pile contains fewer than k bananas, 
the monkey eats all the bananas in that pile and does not consume 
any more bananas in that hour.

Determine the minimum number of bananas the monkey must eat per 
hour to finish all the bananas within h hours.

Example 1
Input: n = 4, nums = [7, 15, 6, 3], h = 8
Output: 5
Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 
1 hour to eat the piles 
accordingly. So, he will take 8 hours to complete all the piles.  

Example 2
Input: n = 5, nums = [25, 12, 8, 14, 19], h = 5
Output: 25
Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 
hour to eat the piles accordingly. So, he will take 5 hours to 
complete all the piles.
*/

#include <bits/stdc++.h>
using namespace std;

//brute force approach tc=O(m+2n) and space is O(1);
int findMax(vector<int> nums){
    int max=nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (max<nums[i])
        {
            max=nums[i];
        }
        
    }
    return max;
}

int totalTimeFinder(int s, vector<int> nums){
    int time=0;
    for (int i = 0; i < nums.size(); i++)
    {
        time+=(nums[i]+s-1)/s;
    }
    return time;
}

// int minimumRateToEatBananas(vector<int> nums, int h) {
//         int maxBananaInPile=findMax(nums);//this is maximum possible speed to eat banana
//         //to find minimum we will start from 1 and check speed for each iteration
//         for (int i = 1; i <=maxBananaInPile; i++)
//         {
//             int totalTime=0;
//             totalTime+=totalTimeFinder(i, nums);
//             if (totalTime<=h)
//             {
//                 return i;
//             }
            
//         }
//         return -1;
//     }

int minimumRateToEatBananas(vector<int> nums, int h){
    int low=1;
    int high=findMax(nums);
    int mini=INT_MAX;
    while (low<=high)
    {
        int mid=low+((high-low)/2);
        int totalTime=0;
        totalTime=totalTimeFinder(mid, nums);
        if (totalTime<=h)
        {
            mini=min(mini, mid);
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    return mini;
}

int main()
{
    int size, h;
    cin>>size>>h;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }

    int ans=minimumRateToEatBananas(nums, h);
    cout << ans << endl;
    
    return 0;
}