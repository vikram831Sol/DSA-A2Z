/*
Given two integer arrays nums1 and nums2. Both arrays are sorted in non-decreasing order.
Merge both the arrays into a single array sorted in non-decreasing order.
The final sorted array should be stored inside the array nums1 and it should be done in-place.
nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest
are 0s.
nums2 has a length of n.
*/

#include <bits/stdc++.h>
using namespace std;

// void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//     for (int i = 0; i < n; i++)
//     {
//         nums1.push_back(0);
//     }
//     for (int i = m; i < m+n; i++)
//     {
//         nums1[i]=nums2[i-m];
//     }
//     sort(nums1.begin(), nums1.end());
//     }

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = 0; i < n; i++) {
        nums1.push_back(0);
    }
    if (n > 0) {//that is if nums2 is not empty
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i > -1 && j > -1) {
            if (nums1[i] > nums2[j]) {
                swap(nums1[k], nums1[i]);
                k--;
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        while (j > -1) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
}

int main() {
    int size1, size2;
    cin >> size1 >> size2;
    vector<int> nums1(size1), nums2(size2);
    for (int i = 0; i < size1; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < size2; i++) {
        cin >> nums2[i];
    }

    merge(nums1, size1, nums2, size2);

    for (int i = 0; i < size1 + size2; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}