#include <bits/stdc++.h>
using namespace std;


//TC->O(n^2) best average
//TC->O(n) best case with optimization
vector<int> bubbleSort(vector<int>& nums) {
        for (int i = nums.size()-1; i>0; i--)
        {
            //bool swapped=false;optimization(skip checking if already sorted)
            for (int j = 0; j < i; j++)
            {
                if (nums[j]>nums[j+1])
                {
                    swap(nums[j], nums[j+1]);
                    //swapped=true;
                }
                
            }
            //if(!swapped)break;
        }
        return nums;
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
    vector<int> d;
    d=bubbleSort(nums);
    for(auto it:d){cout << it << " ";};
    cout << "\n";
    return 0;
}