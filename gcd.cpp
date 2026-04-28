#include <bits/stdc++.h>
using namespace std;

// int gcd(int a, int b){
//     if (b==0)return a;
//     return gcd(b, a%b);
// }

int gcd(int a, int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

int main()
{
    int a, b;
    cin>>a>>b;
    int c;
    c=gcd(a, b);
    cout << c << "\n";
    return 0;
}