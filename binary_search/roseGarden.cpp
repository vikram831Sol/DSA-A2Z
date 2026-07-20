/*
Given n roses and an array nums where nums[i]
denotes that the 'ith' rose will bloom on the
nums[i]th day, only adjacent bloomed roses can
be picked to make a bouquet. Exactly k adjacent
bloomed roses are required to make a single bouquet.
Find the minimum number of days required to make at
least m bouquets, each containing k roses. Return -1 if it is not possible.
*/

#include <bits/stdc++.h>
using namespace std;

int minFinder(vector<int>& bloomDay) {
    int mini = bloomDay[0];
    for (int i = 1; i < bloomDay.size(); i++) {
        mini = min(mini, bloomDay[i]);
    }
    return mini;
}

int maxFinder(vector<int>& bloomDay) {
    int maxi = bloomDay[0];
    for (int i = 1; i < bloomDay.size(); i++) {
        maxi = max(maxi, bloomDay[i]);
    }
    return maxi;
}


//brute force approachf O() O()
// int roseGarden(int n, vector<int> nums, int k, int m) {
//   if ((long long)m*k>n)
//   {
//     return -1;//if required are greater than available
//   }
//     int minDays = minFinder(nums);
//     int maxDays = maxFinder(nums);
//     for (int i = minDays; i <= maxDays; i++) {
//       int bouquet = 0;
//         int consecutive = 0;
//         for (int j = 0; j < nums.size(); j++) {
//             if (nums[j] <= i) {
//                 consecutive++;
//                 if (consecutive == k) {
//                     bouquet++;
//                     if (bouquet==m)
//                     {
//                       return i;
//                     }
                    
//                     consecutive = 0;
//                 }
//             } else {
//                 consecutive = 0;
//             }
//         }
//     }
//     return -1;
// }

int countBouquet(int day, int m, int k, vector<int>& bloomDay){
  int bouquet=0;
  int consecutive=0;
  for (int i = 0; i < bloomDay.size(); i++)
  {
    if (bloomDay[i]<=day)
    {
      consecutive++;
      if (consecutive==k)
      {
        bouquet++;
        if(bouquet==m){return bouquet;}
        consecutive=0;
      }
      
    }
    else{consecutive=0;}
  }
  return bouquet;
}

int minDays(vector<int>& bloomDay, int m, int k){
  if((long long)m*k>bloomDay.size()){return -1;}
  int miniDays = minFinder(bloomDay);
  int maxDays = maxFinder(bloomDay);
  int ans=-1;
  while (miniDays<=maxDays)
  {
    int mid=miniDays+((maxDays-miniDays)/2);
    if (countBouquet(mid, m, k, bloomDay)==m)
    {
      ans=mid;
      maxDays=mid-1;//as we just don't have to find any mid but the smallest mid
    }
    else{miniDays=mid+1;}
    // else{maxDays=mid-1;}//bouquet can never return more then m bouquet
  }
  return ans;
}

int main() { 
  int n, m, k;
  cin>>n>>m>>k;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin>>nums[i];
  }
  int ans=minDays(nums, k, m);
  cout << ans << endl;
  return 0; }