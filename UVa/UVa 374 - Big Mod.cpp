#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

//O(p) --TLE
int power_mod(int b,int p,int M)
{
    if(b==M)    return 0;
    if(p==0)    return 1%M;
    ll ans=1;
    for(int i=0; i<p; i++)
    {
        ans=(ans*b)%M;
    }
    return ans;
}

// Divide and Conquer
// 10^16 = (10^8)^2
// 10^17 = (10^8)^2 * 10
//O(log(p) base 2)
ll power_mod_opt(int b,int p,int M)
{
    if(b==M)    return 0;
    if(p==0)    return 1%M;
    ll sq=power_mod_opt(b,p/2,M);
    sq = (sq*sq)%M;
    if(p%2==1)     sq=(sq*b)%M;
    return sq;
}

int main()
{
    int b,p,M;    //0 <= b,p <= 2^31 -1 , 1 <= M <= 46340
    while(scanf("%d %d %d",&b,&p,&M)==3)
    {
        cout << power_mod_opt(b,p,M) << endl;
    }
    return 0;
}
