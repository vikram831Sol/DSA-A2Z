#include <bits/stdc++.h>
using namespace std;


int factorial(int N){
    if(N==0)return 1;
			return N*factorial(N-1);
		}

int main()
{
    int n;
    cin>>n;
    if(n<0){cout << "invalid number" << "\n";}
    else{
    int s=factorial(n);
    cout << s << "\n";
}
    return 0;
}