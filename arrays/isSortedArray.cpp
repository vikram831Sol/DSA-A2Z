#include <bits/stdc++.h>
using namespace std;
//mistake made was that i kept i<nums.size() and not i<nums.size()-1; as i+1 will exceed the range
bool isSorted(vector<int>& nums){
			int flag=1;
            for (int i = 0; i < nums.size()-1; i++)
            {
                if(nums[i]>nums[i+1]){
                    return false;
                }
                
            }
            return true;
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
    
    int d=isSorted(nums);

    cout << d << "\n";
    return 0;
}