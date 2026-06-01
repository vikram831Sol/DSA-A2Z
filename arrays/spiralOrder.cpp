#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
        int m=matrix.size();
        int n=matrix[0].size();
        int top=0;
        int left=0;
        int right=n-1;
        int bottom=m-1;
        while(left<=right && top<=bottom)//why this oil?
        {
            for(int i=left; i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <=bottom; i++)
            {
                result.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){//whyt this condtion separately insde the loop and why not for above
                //two for loops this condition was not use??
                //ans because while loop is ensuring for them
                //equals to condition because one row may still be left for equals to
            for (int i = right; i >=left; i--)
            {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){//whyt this condtion separately insde the loop:-because top can go beyond
            //bottome in even operation
            //condition to check whether still unvisited column exists or not
            for (int i = bottom; i>=top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++; 
        }
        }
        return result;
    }

int main()
{
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
    
    vector<int> ans(m*n);
    ans=spiralOrder(matrix);
    for (int i = 0; i < m*n; i++)
    {
    
            cout << ans[i]<<" ";
        
        
    }
    return 0;
}