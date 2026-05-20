#include <bits/stdc++.h>
using namespace std;
//brute forc O(n^2) and O(1);
// int stockBuySell(vector<int> arr, int n){
//         int maxi=INT_MIN;
//         for(int i=0; i<arr.size()-1; i++){
//             int diff=0;
//             for(int j=i+1; j<arr.size();j++){
//                 diff=arr[j]-arr[i];
//                 maxi=max(diff, maxi);
//             }
//         }

//         return (maxi>0)?maxi:0;
//     }
//optimal approach O(n) and O(1);
int stockBuySell(vector<int> arr, int n){
        int mini=arr[0];
        int profit=0;
        int max_profit=0;
        for (int i = 1; i < arr.size(); i++)
        {
            profit=arr[i]-mini;
            mini=min(mini, arr[i]);
            max_profit=max(max_profit, profit);
        }
        return max_profit;
    }

int main()
{
    int size;
    cin>>size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
    int d=stockBuySell(arr, size);

    cout << d << "\n";

    return 0;
}