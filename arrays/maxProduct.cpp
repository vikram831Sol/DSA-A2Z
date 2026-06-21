#include <bits/stdc++.h>
using namespace std;

// int maxProduct(vector<int>& nums) {
//      int maxproduct=INT_MIN;
//      for (int i = 0; i < nums.size(); i++)
//      {
//          int product=1;
//         for (int j = i; j < nums.size(); j++)
//         {
//             product*=nums[j];
//             maxproduct=max(product, maxproduct);
//         }

//      }
//         return maxproduct;
//     }

int maxProduct(vector<int>& nums) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int prod1 = 1;
    int prod2 = 1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            prod1 = 1;
            max1=max(0, max1);
        } else {
            prod1 *= nums[i];
            max1=max(max1, prod1);
        }
    }
    for (int i = nums.size()-1; i > -1; i--) {
        if (nums[i] == 0) {
            prod2 = 1;
            max2=max(0, max2);
        } else {
            prod2 *= nums[i];
            max2=max(max2, prod2);
        }
    }
    return max(max1, max2);
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int ans = maxProduct(nums);

    cout << ans << endl;

    return 0;
}