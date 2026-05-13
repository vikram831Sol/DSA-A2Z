#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums){
    int xor1=0;
        for (int i = 0; i < nums.size(); i++)
        {                 
            xor1^=nums[i];
        }
        return xor1;
    }

int main()
{
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int d = singleNumber(nums);
    cout << d << "\n";
    return 0;
}