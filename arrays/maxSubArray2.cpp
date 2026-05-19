#include <bits/stdc++.h>
using namespace std;

// void maxSubArray2(vector<int>& nums){
//     int maxi=INT_MIN;
//     int ansStart=0;
//     int ansEnd=0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = i; j < nums.size(); j++)
//         {
//             int sum=0;
//             for (int k = i; k <=j; k++)
//             {
//                 sum+=nums[k];
//             }
//             if (sum>maxi)
//             {
//                 maxi=sum;
//                 ansStart=i;
//                 ansEnd=j;
//             }

//         }

//     }
//     for (int i = ansStart; i <=ansEnd; i++)
//     {
//         cout << nums[i] << " ";
//     }
//     cout << "\n";
//     cout << "The maximum sum is: " << maxi;

// }

// void maxSubArray2(vector<int>& nums){
//     int maxi=INT_MIN;
//     int ansStart=0;
//     int ansEnd=0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int sum=0;
//         for (int j = i; j < nums.size(); j++)
//         {
//             sum+=nums[j];
//             if (maxi<sum)
//             {
//                 maxi=sum;
//                 ansStart=i;
//                 ansEnd=j;
//             }

//         }

//     }
//     for (int i = ansStart; i <=ansEnd; i++)
//     {
//         cout << nums[i] << " ";
//     }
//     cout << "\n";
//     cout << "The maximum sum is: "<< maxi<< "\n";

// }

void maxSubArray2(vector<int>& nums) {
    int sum = 0;
    int maxi = INT_MIN;
    //wrong
    // int ansStart=0;
    // int ansEnd=0;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     sum+=nums[i];
    //     if (sum>maxi)
    //     {
    //         maxi=sum;
    //         ansEnd=i;
    //     }
    //     if (sum<0)
    //     {
    //         sum=0;
    //         if(nums[i+1]>=0){
    //         ansStart=i+1;}
    //         else{
    //             ansStart=i;
    //             ansEnd=i;
    //         }
    //     }

    // }
    int ansStart = 0;
    int ansEnd = 0;//ansEnd=-1;
    int start = 0;//ansStart=-1;when you have to return these two pointers instead of void
    for (int i = 0; i < nums.size(); i++) {
        sum +=nums[i];
        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0) {
            sum = 0;
            start=i+1;//here sum<0 that means sub array till here is useless check after this
            //so start=i+1;
        }
    }

    for (int i = ansStart; i <= ansEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
    cout << "The maximum sum is: " << maxi << "\n";
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }
    maxSubArray2(nums);
    return 0;
}