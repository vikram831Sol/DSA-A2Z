/*
Given a positive integer n. Find and return its square root. \
If n is not a perfect square, then return the floor value of sqrt(n).
*/

#include <bits/stdc++.h>
using namespace std;

// int floorSqrt(int n)  {
//     int ans=-1;
//     if (n<0)
//     {
//         return -1;
//     }
//      for (int i = 0; i*i <=n; i++)
//      {
//       ans=i;  
//      }
//     return ans; 
//     }


//Optimal approach
// FLOOR SQUARE ROOT (Binary Search on Answer)

// Goal:
// Find the largest integer x such that x² <= n.

// Key Observation:
// 1. If mid² <= n:
//    - mid is a valid answer.
//    - Store it in ans.
//    - Search on the RIGHT to find a larger valid answer.
//      ans = mid;
//      low = mid + 1;

// 2. If mid² > n:
//    - mid and all elements to its right are invalid.
//    - Search on the LEFT.
//      high = mid - 1;

// Binary Search Pattern:
// Condition: mid² <= n
//
// True  -> Store answer + Move Right
// False -> Move Left
//
// This is the "Last True" binary search pattern.

// Example (n = 28):
// Number : 1  2  3  4  5  6  7
// Valid? : T  T  T  T  T  F  F
//                     ^
//                Last True = 5

// Overflow Note:
// Instead of:
//     mid * mid <= n
// use:
//     mid <= n / mid
// or:
//     1LL * mid * mid <= n
// to avoid integer overflow.
int floorSqrt(int n){
    int low=1;
    int high=n;
    int ans=0;
    if (n<2)
    {
        return n;
    }
    while (low<=high)
    {
        int mid=low+((high-low)/2);
        if (mid<=(n/mid))//if(mid*mid<=n)//to avoid overflow
        {
            ans=mid;
            low=mid+1;
        }
        else{high=mid-1;}
        
    }
    return ans;
}//how this solution works i don't understand the if part inside while

int main()
{
    int n;
    cin>>n;
    int ans=floorSqrt(n);
    cout << ans << endl;
    return 0;
}