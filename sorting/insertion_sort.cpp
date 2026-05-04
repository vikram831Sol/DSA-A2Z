#include <bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        int j = i;
        while (j >= 0 && nums[j+1]<nums[j]) {
            swap(nums[j+1], nums[j]);
                j--;
            
        }
    }
    return nums;
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    vector<int> d;
    d = insertionSort(nums);
    for (auto it : d) {
        cout << it << " ";
    };
    cout << "\n";
    return 0;
}
// //this worked
// for (int i = 0; i < nums.size() - 1; i++) {
//     int j = i;
//     while (j >= 0) {
//         if (nums[j + 1] < nums[j]) {
//             swap(nums[j + 1], nums[j]);
//             j--;
//         } else {
//             j--;
//         }
//     }
// }
// return nums;
// }
// //this didn't
// vector<int> insertionSort(vector<int>& nums) {
//     for (int i = 0; i < nums.size() - 1; i++) {
//         int j = i;
//         while (j >= 0) {
//             if (nums[j + 1] < nums[j]) {//if this is true then only j decrement other wise it 
//                 //stops but while is true for j>=0 so it will run infintely
//                 swap(nums[j + 1], nums[j]);
//                 j--;
//             }
//         }
//     }
//     return nums;
//}
//this worked too
// vector<int> insertionSort(vector<int>& nums) {
//     for (int i = 0; i < nums.size() - 1; i++) {
//         int j = i;
//         while (j >= 0 && nums[j+1]<nums[j]) {
//             swap(nums[j+1], nums[j]);
//                 j--;
            
//         }
//     }
//     return nums;
// }