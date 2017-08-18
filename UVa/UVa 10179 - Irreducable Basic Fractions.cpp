#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <bitset>
using namespace std;
typedef long long int ll;
bitset<1000010> is_prime;
vector<ll> primes;

// O(n * log (log (n)))
void sieve(ll n)
{
    is_prime.set();                                      // set all bits to 1
    is_prime[0] = 0;
    is_prime[1] = 0;                                     // except index 0 and 1
    for (ll i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            // cross out multiples of i starting from i * i!
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = 0;
            primes.push_back(i);
        }
    }

}

//O(sqrt(n)/ln(sqrt(n)))
ll phi(ll n)
{
    ll i=0;
    ll pf=primes[i];
    ll ans=n;
    while(pf * pf <=n)
    {
        if(n%pf==0)
            ans-=ans/pf;
        while(n%pf==0)
        {
            n=n/pf;
        }
        i++;
        pf=primes[i];
    }
    if(n!=1)    ans-=ans/n;
    return ans;
}

int main()
{
    sieve(1000000);       //O(nlog(log(n)))
    ll n;
    scanf("%lld",&n);
    while(n!=0)
    {
        cout << phi(n) << endl;
        scanf("%lld",&n);
    }
    return 0;
}
