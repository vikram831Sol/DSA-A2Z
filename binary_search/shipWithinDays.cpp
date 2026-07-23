/*
You are given an array weights where weights[i] 
represents the weight of the i-th package on a conveyor belt. 
All the packages must be shipped in the order given from one port 
to another within days days.

Each day, the ship can carry a contiguous sequence of packages, 
as long as the total weight does not exceed its maximum capacity.

Your task is to find the minimum possible capacity of the ship so 
that all packages can be shipped within the given number of days.
*/

#include <bits/stdc++.h>
using namespace std;

int minfinder(vector<int> &nums){
    int mini=nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        mini=max(mini, nums[i]);
    }
    return mini;
}

int maxfinder(vector<int> &nums){
    int maxi=nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        maxi+=nums[i];
    }
    return maxi;
}

int dayfinder(vector<int> &weights, int cap){
    int totaldays=1;//what if i did here totaldays=0;
    int sum=0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (sum+weights[i]>cap)
        {
            sum=weights[i];//what if i did here sum=0;what would above and this sentence will
            //actually mean?
            totaldays++;
        }
        else{
            sum+=weights[i];
        }
        
    }
    return totaldays;
}
//brute force approach O(2n+(maxCap-minCap)*n)
// int shipWithinDays(vector<int>& weights, int days) {
//         int minCap=minfinder(weights);
//         int maxCap=maxfinder(weights);
        
//         for(int i=minCap; i<=maxCap; i++)
//         {
//             int daysRequired=dayfinder(weights, i);
//             if (daysRequired<=days)
//             {
//                 return i;
//             }
            
//         }
//         return -1;
//     }

/*
The critical fix from your original code: 
you must check before adding, not after. Your original 
code added weights[i] first (sum += weights[i]), and only 
checked against cap on the next iteration — by then it's too late, 
the ship's already overloaded in the accounting.
*/

//optimal approach O(2n+n*log(maxCap-minCap)) O(1)
int shipWithinDays(vector<int>& weights, int days) {
        int minCap=minfinder(weights);
        int maxCap=maxfinder(weights);
        int ans=-1;
        while(minCap<=maxCap)
        {
            int mid=minCap+((maxCap-minCap)/2);
            int daysRequired=dayfinder(weights, mid);
            if (daysRequired<=days)
            {
                ans=mid;
                maxCap=mid-1;
            }
            else{
                minCap=mid+1;
            }
            
        }
        return ans;
    }

    /*
    What's actually lost: its weight is never accounted for on any day
The whole point of sum is to answer one question: "
how much weight have I placed onto today's ship so far?"
When a package doesn't fit (sum + weights[i] > cap), 
what should happen is:
Today's ship is done — it carried sum total weight, and 
that's correct and final.
Tomorrow's ship begins, and the very first thing loaded onto 
tomorrow's ship is this leftover package. So tomorrow's sum 
should now equal weights[i] — this package's weight is now "on board" 
tomorrow's ship.
If instead you write sum = 0, you're saying: "tomorrow's ship 
begins, and nothing has been loaded onto it yet — not even the
package that just failed to fit."
But that's false! That package still needs to physically 
go on the ship some day — it hasn't shipped, it hasn't vanished, 
but your sum variable — which is supposed to be tracking "current 
running weight on the current day" — now says 0, as if that package's 
weight doesn't exist anywhere in your bookkeeping.
    */

int main()
{
    int size, days;
    cin>>size>>days;
    vector<int> weights(size); 
    for (int i = 0; i < size; i++)
    {
        cin>>weights[i];
    }
    int ans=shipWithinDays(weights, days);
    cout << ans << endl;
    return 0;
}