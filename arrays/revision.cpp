#include <bits/stdc++.h>
using namespace std;

void spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int m = matrix.size();
    int n = matrix[0].size();
    int left = 0, right = n - 1;
    int top = 0, bottom = m - 1;
    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom) {//equals to condition because one row may still be left for equals to
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right) {//condition to check whether still unvisited column exists or not
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
}

int main() { return 0; }