#include <bits/stdc++.h>
using namespace std;

//brute force O(2^r) very bad exponential and O(r) space
// int pascalTriangleI(int r, int c){
//     if (c==1 || c==r || r==1)return 1;
//     return pascalTriangleI(r-1, c-1)+pascalTriangleI(r-1, c);
    
// }


//O(c) and O(1) Optimal approach
long long pascalTriangleI(int r, int c){
    // r=r-1;
    // c=c-1;
    long long ans=1;
    // for (int i = r; i >=r-c+1; i--)
    // {
    //     ans*=i;
    // }
    // for (int i = 1; i <=c; i++)
    // {
    //     ans/=i;
    // }
    //or
    c=min(c, r-c);//for minimum iterations;
    for (int i = 1; i <=c; i++)
    {
        ans*=(r-i+1);
        ans/=i;
    }
    
    
    return ans;
}
//for generating the pascals triangle for O(n^3) and O(n^2)
// vector<vector<int>> generate(int numRows){
//     vector<vector<int>> result(numRows);
//     for (int i = 0; i < numRows; i++)
//     {
//         for (int j = 0; j <=i; j++)
//         {
//             result[i].push_back(pascalTriangleI(i, j));
//         }
        
//     }
//     return result;
// }

//for generating pascals triangle using O(n^2) and O(n^2)
vector<vector<int>> generate(int numRows){
    vector<vector<int>> result(numRows);
    result[0].push_back(1);
    for (int i = 1; i < numRows; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            if (j==0 || j==i)
            {
                result[i].push_back(1);
            }
            else{
            result[i].push_back(result[i-1][j-1]+result[i-1][j]);//using 
            //already generated previsous row to geneate the new row
            }
            
        }
        
    }
    return result;
}

int main()
{
    int numRows;
    cin>>numRows;
    vector<vector<int>> result=generate(numRows);
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}