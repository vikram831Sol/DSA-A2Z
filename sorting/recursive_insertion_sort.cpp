#include <bits/stdc++.h>
using namespace std;

//n is number of elements and not the index
void insertionsort(vector<int>& nums, int n) {
        if(n<=1)return;
        insertionsort(nums, n-1);
        int last=nums[n-1];
        int j=n-2;
        while(j>=0&&nums[j]>last){
            nums[j+1]=nums[j];j--;
        }
        nums[j+1]=last;
    }

int main()
{
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    
    insertionsort(nums, size);
    for (auto it : nums) {
        cout << it << " ";
    };
    cout << "\n";
    return 0;
}