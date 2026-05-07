#include <bits/stdc++.h>
using namespace std;

//two pointer algo
//write the approaches and time complexity
int removeDuplicates(vector<int>& nums) {
        int i=1;int k=1; int j=0;
        for (; i < nums.size(); i++)
        {
            if(nums[i]!=nums[j]){
                nums[j+1]=nums[i]; j++;k++;
            }
        }
            return k;   
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
    
    int d=removeDuplicates(nums);

    cout << d << "\n";
    return 0;
}