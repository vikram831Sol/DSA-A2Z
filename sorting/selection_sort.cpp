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
        
        // int min=INT_MAX;//we cannot do that because when we swap nums[i] and min nums[i]
        //is getting the swapped with min which is a local variable and not from the array itself
        //resulting in distorted output
        // for(int j=i; j<nums.size(); j++){
        //     if(nums[j]<min){
        //         min=nums[j];
        // swap(nums[i], nums[min]);//this line should be outside the nested for loop as 
        //we do swapping after the min is found through whole array from j to n-1;
        //     }
        // }
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