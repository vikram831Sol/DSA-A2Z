#include <bits/stdc++.h>
using namespace std;

// int maxLen(vector<int>& arr) {
//     int maxSize=0;
//     int flag=0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         int sum=0;
//         int size=0;
//         for(int j=i; j<arr.size(); j++){
//                 sum+=arr[j];
//                 size++;                
//                 if(sum==0){
//                 if (maxSize<size)
//                 {
//                     maxSize=size;
//                     flag=1;
//                 }
//             }
                
//             }
//         }
//         return maxSize;
//     }

int maxLen(vector<int>& arr){
    int sum=0;
    int size=0;
    int maxSize=0;
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        sum+=arr[i];
        if (sum==0)
        {
            size=i+1;
            maxSize=max(maxSize, size);
        }
        else if(mp.find(sum)!=mp.end()){
            size=i-mp[sum];
            maxSize=max(maxSize, size);
        }
        else{
            mp[sum]=i;
        }
        

    }
    return maxSize;
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
    
    int d=maxLen(arr);

    cout << d << "\n";

    return 0;
}