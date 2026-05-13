#include <bits/stdc++.h>
using namespace std;
//T.C--->O(n) and SC--->O(1);
int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxim = 0, temp = 0;
    if (nums[0] == 1) {
        maxim = 1;
        temp = 1;
    }
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == 1) {
            temp++;
            if (temp > maxim) {
                maxim = temp;
            }
        } else if (nums[i] == 0) {
            if (temp > maxim) {
                maxim = temp;
            }
            temp = 0;
        }
    }
    return maxim;
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int d = findMaxConsecutiveOnes(nums);
    cout << d << "\n";
    return 0;
}