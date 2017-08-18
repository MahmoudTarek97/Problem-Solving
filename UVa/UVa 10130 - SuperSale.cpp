#include <iostream>
#include <stdio.h>

using namespace std;
int w[1001];
int p[1001];
int n;

//Dynamic Programming - Top-down approach
int val(int idx,int remW,int memo[1001][31])
{
    if(remW<=0)
        return 0;
    if(idx>=n)
        return 0;
    if(w[idx]>remW && memo[idx][remW]==0)
        memo[idx][remW]= val(idx+1,remW,memo);
    if(w[idx]<=remW && memo[idx][remW]==0)
        memo[idx][remW]= max(val(idx+1,remW,memo),val(idx+1,remW-w[idx],memo)+p[idx]);
    return memo[idx][remW];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> p[i];
            cin >> w[i];
        }
        int G,ans=0;
        cin >> G;
        int W[G];
        int max_value=-1;
        for(int i=0; i<G; i++)
        {
            cin >> W[i];
            int memo[1001][31]= {};
            ans+=val(0,W[i],memo);
        }
        cout << ans << endl;
    }
    return 0;
}
