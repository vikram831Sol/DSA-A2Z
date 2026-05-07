#include <bits/stdc++.h>
using namespace std;

//other approach is to first find the largest and if all are not same then use loop again to 
//find the second largest and if all are same then return -1;

//best case T.C--->O(n), SC--->O(1)
int secondLargestElement(vector<int>& nums) {
        int largest=INT_MIN;
        int second_largest=INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if(largest<nums[i]){
                second_largest=largest;
                largest=nums[i];}
            else if(largest>nums[i] && second_largest<nums[i]){second_largest=nums[i];}
        }
        
        if(second_largest!=INT_MIN){
            return second_largest;
        }
        else{
            return -1;
        }

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
    
    int d=secondLargestElement(nums);

    cout << d << "\n";

    return 0;
}