#include <bits/stdc++.h>
using namespace std;

//brute force approach O(m*n*(m+n)) O(1)
// void setZeroes(vector<vector<int>>& matrix) {
//     int m=matrix.size();
//     int n=matrix[0].size();
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (matrix[i][j]==0)
//                 {
//                     for (int  k= 0;  (k<m); k++)
//                     {
//                         if (k!=i)
//                         {
//                             matrix[k][j]=-1;
//                         }

//                     }
//                     for (int  k= 0;  (k<n); k++)
//                     {
//                         if (k!=j)
//                         {
//                             matrix[i][k]=-1;
//                         }
//                     }
                    
//                 }
                
//             }
            
//         }
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (matrix[i][j]==-1)
//                 {
//                     matrix[i][j]=0;
//                 }
                
//             }
            
//         }
        
        
//     }


//better approach O(m*n) O(n)
// void setZeroes(vector<vector<int>>& matrix){
//     int m=matrix.size();
//     int n=matrix[0].size();
//     vector<bool> row(m, false);
//     vector<bool> col(n, false);
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (matrix[i][j]==0)
//             {
//                 row[i]=true;
//                 col[j]=true;
//             }
            
//         }
        
//     }
//     for (int i = 0; i < m; i++)
//     {
//         if (row[i]==true)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 matrix[i][j]=0;
//             }
            
//         }
        
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (col[i]==true)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 matrix[j][i]=0;
//             }
//         } 
//     }
// }

//optimal appraoch
void setZeroes(vector<vector<int>>& matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    int col0=1;
    //is it necessary that we use upper most row and left most col to store data and not 
    //right most col and bottom most row
     
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0]==0)
        {
            col0=0;
        }
        
        for (int j = 1; j < n; j++)//why j begin from 1 adn not zero
        {
            if (matrix[i][j]==0)
            {
                matrix[i][0]=0;
                matrix[0][j]=0;
            }
            
        }
        
    }

    for (int i = m-1; i >=0; i--)
    {
        for (int j = n-1; j >= 1; j--)
        {
            if (matrix[i][0]==0 || matrix[0][j]==0)
            {
                matrix[i][j]=0;//why matrix[i][j]=0 and not only one like i, 0 or 0, j
            }
            
        }
        if (col0==0)//in case of first row and first col confusion arises to avoid this
        //as matrix[0][0]=0 but due to whom?row or col to tackle this problem
        {
            matrix[i][0]=0;
        }
        
    }
    
    
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
    setZeroes(matrix);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j]<< " ";
        }
        cout << "\n";
    }
    return 0;
}