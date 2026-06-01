#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    vector<bool> row(m, false);
    vector<bool> col(n, false);
    for (int i = 0; i < m; i++)
    {
        for(int j=0; j<n; j++){
            if (matrix[i][j]==0)
            {
                row[i]=true;
                col[j]=true;
            }
            
        }
    }

    for (int i = 0; i < m; i++)
    {
        if(row[i]==true){
        for(int j=0; j<n; j++){
            matrix[i][j]=0;
        }}
    }
    for (int i = 0; i < n; i++)
    {
        if(col[i]==true){
        for(int j=0; j<m; j++){
            matrix[j][i]=0;
        }}
    }
    
    
}

void setZero(vector<vector<int>>& matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    int col0=1;
    for (int i = 0; i < m; i++)
    {
        if(matrix[i][0]==0){col0=0;}
        
        for (int j = 1; j < n; j++)
        {
            if(matrix[i][j]==0){//do not forget writting this condition
            matrix[i][0]=0;//stores position of rows which contain zero in column zeroth
            matrix[0][j]=0;//stores position of column containing zero in zeroth row
            }
        }
        
    }
    //start filling rows and columns with zeros which contains atleast on zero from bottom right
    for (int i = m-1; i >=0; i--)
    {
        for(int j= n-1; j>=1; j--){
            if (matrix[i][0]==0 || matrix[0][j]==0)
            {
                matrix[i][j]=0;
            }
            
        }
        if (col0==0)
        {
            matrix[i][0]=0;
        }
        
    }
    

}

int main() { 
    int m, n;
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
        
    }
    setZero(matrix);
    for(int i=0; i<m; i++){
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j]<< " ";
        }
        cout << "\n";
    }
    
    return 0; }