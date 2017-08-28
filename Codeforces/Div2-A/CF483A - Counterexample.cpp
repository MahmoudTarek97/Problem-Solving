/***********************************************/
/**                                           **/
/**   CF483A - Counterexample.cpp             **/
/**   Credits to Mahmoud Tarek Samir          **/
/**   Ma7moud.tarek97@gmail.com               **/
/**                                           **/
/***********************************************/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;


int main()
{
    ll l,r;
    bool found=false;
    scanf("%lld %lld",&l,&r);
    if(l-r+1<3)
    {
        for(ll i=l; i<r-1; i++)     //l-r <= 50
        {
            if(__gcd(i,i+1)==1)
            {
                if(__gcd(i+1,i+2)==1)
                {
                    if(__gcd(i,i+2)!=1)
                    {
                        printf("%lld %lld %lld\n",i,i+1,i+2);
                        found=true;
                        break;
                    }
                }
            }
        }
    }
    if(!found)
        cout << -1 << endl;
    return 0;
}
