#include <bits/stdc++.h>
using namespace std;

//brute force approach
// vector<int> divisors(int n){
//     vector<int> sol;
//     for (int i = 1; i <=n; i++)
//     {
//         if(n%i==0){
//             sol.push_back(i);
//         }
//     }
//     return sol;
// }

//better approach
vector<int> divisors(int n) {
    vector<int> sol;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sol.push_back(i);
            if (i != n / i) sol.push_back(n / i);
        }
    }
    sort(sol.begin(), sol.end());
    return sol;
}

int main() {
    int n;
    cin >> n;
    vector<int> c;
    c = divisors(n);
    for (auto it : c) {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}