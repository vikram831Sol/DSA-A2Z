#include <bits/stdc++.h>
using namespace std;
//TC---->>O(n) best avg and worst
//SC---->>O(1)
int largestElement(vector<int>& nums) {
        int largest;
        largest=nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if(largest<nums[i]){largest=nums[i];}
        }
        return largest;
    }

int main()
{
    int size;
    cin>>size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    
    int d;
    d=largestElement(nums);
    cout << d << "\n";

    return 0;
}