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


//optimal approach for time complexity logn is from division and for each merge it is n and for 
//each cnt pairs funciton it is n so O(2nlogn) and space complexity O(n)
//and it is important to tell interviewer that we are distorting the array
int cntPairs(vector<int>& nums, int low, int mid, int high){
    int cnt=0;
    int right=mid+1;
    for(int i=low; i <= mid; i++)
    {
        while ((right<=high)&&(nums[i]>2*nums[right]))
        {
            right++;
        }
        cnt+=(right-(mid+1));
    }
    return cnt;
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

// void mergeSort(vector<int>& nums, int low, int high) {
//     if (low >= high) {
//         return;
//     }
//     int mid = (low + ((high - low) / 2));
//     mergeSort(nums, low, mid);
//     mergeSort(nums, mid + 1, high);
//     cntPairs(nums, low, mid, high);
//     merge(nums, low, mid, high);
// }instead of this we can avoid use of global count and write as 

int mergeSort(vector<int>& nums, int low, int high) {
    int cnt=0;
    if (low >= high) {
        return cnt;
    }
    int mid = (low + ((high - low) / 2));
    cnt+=mergeSort(nums, low, mid);//each block will return its count;//that is before counting
    //for current one count for earlier ones;
    cnt+=mergeSort(nums, mid + 1, high);
    cnt+=cntPairs(nums, low, mid, high);
    merge(nums, low, mid, high);
    return cnt;
}

int reversePairs(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size() - 1);
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