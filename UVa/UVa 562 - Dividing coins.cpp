#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;
int n;
int coins[101];
int sum;
int memo[101][50000];

//Dynamic Programming - Top-down Approach
int min_diff(int idx,int taken)
{
    if(idx>=n && memo[idx][taken]==-1)
        memo[idx][taken]= (int) fabs(taken-(sum-taken));

    if(memo[idx][taken]==-1)
        memo[idx][taken] = min(min_diff(idx+1,taken+coins[idx]),min_diff(idx+1,taken));
    return memo[idx][taken];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(memo, -1, sizeof(memo));
        cin >> n;
        sum=0;
        for(int i=0; i<n; i++)
        {
            cin >> coins[i];
            sum+=coins[i];
        }
        cout << min_diff(0,0) << endl;

    }
    return 0;
}