#include <bits/stdc++.h>
using namespace std;

//brute force approach O(n^2) and O(n^2)
// void rotateMatrix(vector<vector<int>>& matrix) {
//      int n=matrix.size();
//      vector<vector<int>> temp(n, vector<int>(n));
//      for (int i = 0; i < n; i++)
//      {
//         for(int j=0; j<n;j++){
//             temp[j][(n-1)-i]=matrix[i][j];
//         }
//      }
//      for (int i = 0; i < n; i++)
//      {
//         for(int j=0;j<n;j++){
//             matrix[i][j]=temp[i][j];
//         }
//      }
        
//     }


//optimal approach get the transpose of the matrix by swapping elements on the both sides of 
//diagonals and then reverse each row
//O(n^2) and O(1)
void reverseRow(vector<int>& nums){
    int high=nums.size()-1;
    int low=0;
    while(low<high){
        swap(nums[low], nums[high]);low++; high--;
    }
}

void rotateMatrix(vector<vector<int>>& matrix){
    int n=matrix.size();
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<n;j++){
            if(i>=j){continue;}
            else{
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    for(int i=0; i<n; i++){
        reverseRow(matrix[i]);
    }
    
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }
    rotateMatrix(matrix);

    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    


    return 0;
}