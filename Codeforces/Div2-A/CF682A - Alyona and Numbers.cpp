/***********************************************/
/**                                           **/
/**   CF682A - Alyona and Numbers.cpp         **/
/**   Credits to Mahmoud Tarek Samir          **/
/**   Ma7moud.tarek97@gmail.com               **/
/**                                           **/
/***********************************************/

#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,m,count=0;
    cin >> n >> m;
    for(ll i=1; i<=n; i++) //  n <= 1,000,000
    {
        if(m>=5-(i%5))
            count+=(m-(5-(i%5)))/5 + 1;
    }
    cout << count << endl;
    return 0;
}
