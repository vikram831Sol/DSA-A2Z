#include <bits/stdc++.h>
using namespace std;
// brute force approach O(n!xn) and O(n!xn) n! for producing n! permutations and into n for n recursion stack
// void generate(vector<int>& nums, int index, vector<vector<int>>& permu){
//     if (index==nums.size())
//     {
//         permu.push_back(nums);
//         return;
//     }
//     for (int i = index; i < nums.size(); i++)
//     {
//         swap(nums[index], nums[i]);
//         generate(nums, i+1, permu);
//         swap(nums[index], nums[i]);
//     }
    
// }

// vector<int> nextPermutation(vector<int>& nums) {
//         vector<vector<int>> permu;
//         generate(nums, 0, permu);
//         sort(permu.begin(), permu.end());
//         for (int i = 0; i < permu.size(); i++)
//         {
//             if (permu[i]==nums)
//             {
//                 if(i==permu.size()-1){
//                     return permu[0];
//                 }
//                 else{
//                     return permu[i+1];
//                 }
//             }
            
//         }
        
//     }

//optimal approach O(3n) and O(1)
void reverse(vector<int>& nums, int left, int high){
    while (left<high)
    {
        swap(nums[left], nums[high]);
        left++; high--;
    }
}

void nextPermutation(vector<int>& nums){
    int bPoint=-1;
    int k=nums.size()-1;
    int l=nums.size()-1;
    while (k>0)
    {
        if (nums[k]>nums[k-1])
        {
            bPoint=k-1;break;
        }
        else{k--;}
    }
    if (bPoint==-1)
    {
        reverse(nums, 0, nums.size()-1);
    }
    else{
        while(l>bPoint){
            if (nums[l]>nums[bPoint])
            {
                swap(nums[l], nums[bPoint]);
                break;
            }
            else{l--;}
        }
        reverse(nums, bPoint+1, nums.size()-1);
    }
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
    nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
    
    return 0;
}

/*
GOAL:
Find the next lexicographically greater permutation.

Example:
1 2 3
↓
1 3 2

because 132 is the next greater arrangement after 123.


--------------------------------------------------
CORE IDEA
--------------------------------------------------

We want:

    "The smallest possible number
     that is greater than current number."

NOT just any bigger permutation.


--------------------------------------------------
STEP 1 — FIND BREAKPOINT
--------------------------------------------------

Example:

1 2 5 4 3

From right side:

5 4 3

is decreasing.

This means:

    This suffix is already the largest arrangement possible.

So no larger permutation can be formed
using only this suffix.

The first place from right where increase is possible is:

2 < 5

So:

breakpoint = 2


Why RIGHTMOST breakpoint?

Because we want the SMALLEST increase possible.

Changing digits further left creates much larger jumps.


--------------------------------------------------
STEP 2 — FIND NEXT GREATER ELEMENT
--------------------------------------------------

Current array:

1 2 5 4 3

Need:

    smallest element greater than 2

From suffix:

5 4 3

smallest greater element is:

3

Swap:

1 3 5 4 2

Now the number became larger.


--------------------------------------------------
STEP 3 — MAKE SUFFIX MINIMUM
--------------------------------------------------

Current suffix:

5 4 2

This is still the largest ordering.

To get the NEXT permutation,
we must make suffix as small as possible.

Smallest arrangement:

2 4 5

Final answer:

1 3 2 4 5


--------------------------------------------------
WHY REVERSE WORKS
--------------------------------------------------

Original suffix was decreasing:

5 4 3

A decreasing array reversed becomes ascending.

Ascending order gives the minimum arrangement.

So instead of sorting,
we can simply reverse the suffix.


--------------------------------------------------
FINAL ALGORITHM
--------------------------------------------------

1. Traverse from right.
2. Find first index where:

       nums[i] < nums[i+1]

   This is breakpoint.

3. Find smallest element greater than nums[i]
   from right side.

4. Swap them.

5. Reverse the suffix after breakpoint.


--------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------

O(n)

because:
- one traversal for breakpoint
- one traversal for swap element
- one reverse


--------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------

O(1)

because everything is done in-place.
*/