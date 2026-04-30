#include <bits/stdc++.h>
using namespace std;


//time complexity>>>>O(2^n)
int fib(int n) {
    if(n<=1)return n;
        return fib(n-1)+fib(n-2);
    }

int main()
{
    int n;
    cin>>n;
    int result=fib(n);
    cout << result << "\n";
    return 0;
}