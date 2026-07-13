#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target){
    int low=0;
    int high=nums.size()-1;
    while (low<=high)
    {
        int mid=low+((high-low)/2);
        if (nums[mid]==target)
        {
            return mid;
        }
        else if (nums[mid]<target)
        {
            low=mid+1;
        }
        else{high=mid-1;}
    }
    return low;
}//this particular function always returns target index if found or
//index of smaller larger number than target

vector<int> getFloorAndCeil(vector<int> nums, int x) {
   int reference=searchInsert(nums, x);
   if (reference==nums.size())//in case no ceiling exists
   {
    return {nums[nums.size()-1], -1};
   }
   else if(nums[reference]==x){//in case if target exists it is itself floor and ceil
    return {x, x};
   }
   else if(reference==0){return {-1, nums[reference]};}
   return {nums[reference-1], nums[reference]};
    }

int main()
{
    int size, x;
    cin>>size>>x;
    vector<int> nums(size);
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    vector<int> result=getFloorAndCeil(nums, x);
    for (auto it:result)
    {
        cout << it <<" ";
    }
    cout << endl;
    return 0;
}