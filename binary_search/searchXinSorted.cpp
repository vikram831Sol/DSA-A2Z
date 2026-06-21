#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target){
     for (int i = 0; i < nums.size(); i++)
     {
        if (nums[i]==target)
        {
            return i;
        }
        
     }
     return -1;
    }

int main()
{
    int size, target;
    cin>>size>>target;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    int ans=search(nums, target);
    cout << ans << endl;
    return 0;
}