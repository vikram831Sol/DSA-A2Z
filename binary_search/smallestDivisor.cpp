/*
Given an array of integers nums and an integer threshold,
 we will choose a positive integer divisor,
 divide all the array by it, and sum the division's result.
 Find the smallest divisor such that the result mentioned above
  is less than or equal to threshold.

Each result of the division is rounded to the nearest integer
greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.
*/
#include <bits/stdc++.h>
using namespace std;

int largestNum(vector<int>& nums) {
    int maxi = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        maxi = max(maxi, nums[i]);
    }
    return maxi;
}

int summation(vector<int>& nums, int num) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += (nums[i] + num - 1) / num;  // ceil division;
    }
    return sum;
}

// int smallestDivisor(vector<int> &nums, int limit) {//we have to find the smallest positive
// divisor
//     //this does not mean we need to find from the array it can be outside the array too.
//        int largest=largestNum(nums);
//        int ans=-1;
//        for (int i = 1; i <=largest; i++)
//        {
//             int sum=summation(nums, i);
//             if(sum<=limit){
//                 return i;
//             }
//        }
//        return ans;
//     }

// optimal approach O(N*log(largestNumber)+N) O(1)
int smallestDivisor(vector<int>& nums, int limit) {
    int high = largestNum(nums);
    int low = 1;
    int ans = -1;
    while (low <= high) {
        int mid = low + ((high - low) / 2);
        int sum = summation(nums, mid);
        if (sum <= limit) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int size, limit;
    cin >> size >> limit;
    vector<int> nums(size);
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }
    int solution = smallestDivisor(nums, limit);
    cout << solution << endl;
    return 0;
}