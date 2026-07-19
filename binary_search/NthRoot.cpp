#include <bits/stdc++.h>
using namespace std;
int NthRoot(int N, int M) {
       int low=1;
       int high=M;
       while (low<=high)
       {
        int mid=low+((high-low)/2);
        long long expo=1;
        for (int i = 1; i <=N; i++)
        {
            if (expo>M/mid)
            {
                //we want to check whether expo*mid>M before multiplying we do so
                //by expo>M/mid by dividing mid on both sides
                //if it is then we mark expo greater than M for later use
                expo=M+1;
                break;
            }   
            expo*=mid;
        }
        if (expo==M)
        {
            return mid;
        }
        else if (expo<M)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
        
       }
       return -1;
    }
int main()
{
    int N, M;
    cin>>N>>M;
    int ans=NthRoot(N, M);
    cout << ans << endl;
    return 0;
}