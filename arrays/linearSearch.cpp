#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){
                return i;
            }
        }
        return -1;
    }

int main()
{
    int size;
    cin>>size;
    int target;
    cin>>target;

    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }

    int d=linearSearch(nums, target);

    cout << d <<"\n";
    return 0;
}