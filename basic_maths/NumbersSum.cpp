#include <bits/stdc++.h>
using namespace std;


int NnumbersSum(int N){
    if(N==0)return 0;
			return N+NnumbersSum(N-1);
		}

int main()
{
    int n;
    cin>>n;
    int s=NnumbersSum(n);
    cout << s << "\n";
    return 0;
}