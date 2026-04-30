#include <bits/stdc++.h>
using namespace std;

void reverse(int i, int arr[], int n){
    if(i>=n/2)return;
    swap(arr[i], arr[n-1-i]);
    return reverse(i+1, arr, n);
}

//two pointer approach
// void reverse(int left, int arr[], int right){
//     if(left>=right)return;
//     swap(arr[left], arr[right]);
//     return reverse(left+1, arr, right-1);
// }

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i < n; i++){cin>>arr[i];}
    reverse(0, arr, n-1);
    for(auto it:arr){cout << it << " ";};
    cout << "\n";
    return 0;
}