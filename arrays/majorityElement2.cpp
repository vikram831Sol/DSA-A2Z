#include <bits/stdc++.h>
using namespace std;

// time complexity is O(n) and O(n)
//  vector<int> majorityElementTwo(vector<int>& nums) {
//          unordered_map<int, int> mp;
//          vector<int> result;
//          for (int i = 0; i < nums.size(); i++)
//          {
//              mp[nums[i]]++;
//          }
//          for (auto i = mp.begin(); i != mp.end(); i++)
//          {
//              if (i->second>nums.size()/3)
//              {
//                  result.push_back(i->first);
//              }

//         }
//         sort(result.begin(), result.end());
//         return result;
//     }

vector<int> majorityElementTwo(vector<int>& nums) {
    vector<int> result;
    int cnt1 = 0, ele1 = INT_MIN;
    int cnt2 = 0, ele2 = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if (cnt1 == 0 && nums[i] != ele2) {
            cnt1 = 1;
            ele1 = nums[i];
        } else if (cnt2 == 0 && nums[i] != ele1) {
            cnt2 = 1;
            ele2 = nums[i];
        } else if (nums[i] == ele1) {
            cnt1++;
        } else if (nums[i] == ele2) {
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
            // We have found three distinct elements:
            // (ele1, ele2, nums[i]).
            // Remove one occurrence of each (cancel them out).
            // A true majority element (> n/3) cannot be completely
            // eliminated by repeated cancellations, so potential
            // majority candidates will survive.
            cnt1--;
            cnt2--;
        }
    }
    // few doubts in this method will this ensure that ele1 and ele2 variables will be assigned
    // with some values and how to know that and in else condition why we are reducing both cnts
    cnt1 = 0;
    cnt2 = 0;
    int mini = (nums.size() / 3) + 1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == ele1) {
            cnt1 += 1;
        } else if (nums[i] == ele2) {
            cnt2 += 1;
        }
    }
    if (cnt1 >= mini) {
        result.push_back(ele1);
    }
    if (cnt2 >= mini && ele1 != ele2) {
        result.push_back(ele2);
    }

    return result;
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    vector<int> res = majorityElementTwo(nums);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}