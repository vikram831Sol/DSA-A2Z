/*Given an array nums sorted in non-decreasing order.
Every number in the array except one appears twice. Find the single number in the array.
*/

#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    if (low == high) {
        return nums[low];
    }
    if (nums[low] != nums[low + 1]) {
        return nums[low];
    }
    if (nums[high - 1] != nums[high]) {
        return nums[high];
    }//we will do this three checks outside the loop because for low and high checks
    //high!=high-1 in sub array even though in whole array that high value has a proper pair
    while (low <= high) {
        int mid = low + ((high - low) / 2);
        // left side do not contains the number
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }

        if (mid % 2 == 0) {
            // left side do not contains the singel number
            if (nums[mid + 1] == nums[mid]) {
                low = mid + 1;
            }
            // right side do not contains the single number
            else {
                high = mid - 1;
            }
        } else {
            if (nums[mid - 1] == nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    int ans = singleNonDuplicate(nums);
    cout << ans << endl;
    return 0;
}