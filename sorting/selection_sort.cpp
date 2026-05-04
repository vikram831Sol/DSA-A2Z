#include <bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
    {
        int min=i;
        for(int j=i; j<nums.size(); j++){
            if(nums[j]<nums[min]){
                min=j;
            }
        }
        swap(nums[i], nums[min]);
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
    d=selectionSort(nums);
    for(auto it:d){cout << it << " ";};
    cout << "\n";
    return 0;
}