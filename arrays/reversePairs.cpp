#include <bits/stdc++.h>
using namespace std;

// brute force approach O(n^2) & O(1)
//  int reversePairs(vector<int>& nums) {
//          int cnt=0;
//          for (int i = 0; i < nums.size(); i++)
//          {
//              for (int j = i+1; j < nums.size(); j++)
//              {
//                  if (nums[i]>(2*nums[j]))
//                  {
//                      cnt++;
//                  }

//             }

//         }
//         return cnt;
//     }

int cnt = 0;

void cntPairs(vector<int>& nums, int low, int mid, int high){
    int right=mid+1;
    for(int i=low; i <= mid; i++)
    {
        while ((right<=high)&&(nums[i]>2*nums[right]))
        {
            right++;
        }
        cnt+=(right-(mid+1));
    }
    
}

void merge(vector<int>& nums, int low, int mid, int high) {
    int left = low, right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high) {
        if (nums[left] > nums[right]) {
            temp.push_back(nums[right]);
            right++;
        } else {
            temp.push_back(nums[left]);
            left++;
        }
    }
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

void mergeSort(vector<int>& nums, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + ((high - low) / 2));
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    cntPairs(nums, low, mid, high);
    merge(nums, low, mid, high);
}

int reversePairs(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return cnt;
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }
    int ans = reversePairs(nums);

    cout << ans << endl;

    return 0;
}