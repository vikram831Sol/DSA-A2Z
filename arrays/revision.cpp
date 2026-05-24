#include <bits/stdc++.h>
using namespace std;

/*Brute force

// Class to hold the solution logic
class Solution {
public:
    // Function to remove duplicates from sorted array in-place
    int removeDuplicates(vector<int>& nums) {
        // If array is empty, return 0 directly
        if (nums.empty()) return 0;

        // Pointer for the position of last unique element
        int i = 0;

        // Traverse the array starting from the second element
        for (int j = 1; j < nums.size(); j++) {
            // If current element is different from last unique element
            if (nums[j] != nums[i]) {
                // Move pointer for unique element forward
                i++;
                // Place the new unique element at the next position
                nums[i] = nums[j];
            }
        }

        // i is index of last unique element, count = i + 1
        return i + 1;
    }
};
*/

int removeDuplicates(vector<int>& nums){
    int i=0;
    int j=1;
    while (j<nums.size())
    {
        if (nums[j]!=nums[i])
        {
            nums[i+1]=nums[j];
            i++;
        }
        j++;
    }
    return i+1;
}

int main()
{
    int size;
    cin>>size;
    vector<int> nums(size);
    for (int i = 0; i < nums.size(); i++)
    {
        cin>>nums[i];
    }
    
    int d=removeDuplicates(nums);
    
    cout << d << "\n";
    return 0;
}