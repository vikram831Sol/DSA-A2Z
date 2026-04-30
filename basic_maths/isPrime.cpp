#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if (n<=1){return false;}
    for (int i = 2; i*i <=n; i++)
    {
        if(n%i==0){
            return false;
        }
    }
    return true;  
}

//sieve method for getting array of prime numbers till number n
// vector<bool> sieve(int n) {
//     vector<bool> isPrime(n + 1, true);

//     isPrime[0] = isPrime[1] = false;

//     for (int i = 2; i * i <= n; i++) {
//         if (isPrime[i]) {
//             for (int j = i * i; j <= n; j += i) {
//                 isPrime[j] = false;
//             }
//         }
//     }

//     return isPrime;
// }

int main()
{
    int n;
    cin>>n;
    int c;
    c=isPrime(n);
    cout << c << "\n";
    return 0;
}