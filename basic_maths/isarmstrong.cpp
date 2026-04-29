#include <bits/stdc++.h>
using namespace std;

bool armstrong(int n) {
    int temp = n;
    int k;
    int size = 0;
    int sum = 0;
    do {
        size++;
        temp = temp / 10;
    } while (temp);
    temp = n;
    do {
        k = temp % 10;
        int p = 1;
        for (int i = 1; i <= size; i++) {
            p = p * k;
        }

        sum = sum + p;
        temp = temp / 10;
    } while (temp);

    return sum == n;
}

int main() {
    int n;
    cin >> n;
    int c;
    c = armstrong(n);
    cout << c << "\n";
    return 0;
}